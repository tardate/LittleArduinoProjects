/*

  YouTubeControl
  Control the playback and looping of a YouTube vide with your feet.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/ESP8266/YouTubeFootSwitch

 */


// #define ENABLE_SERIAL_DEBUG

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
#include "settings.h"
#include "index_page.h"

// mDNS - will advertsise this server as (server_host_name).local
char server_host_name[] = "yt-foot-controller";

// TCP server at port 80 will respond to HTTP requests
ESP8266WebServer server(80);

// software debounce fudge factor
const int DEBOUNCE_DELAY = 250;

// pins for the shift register control
const int DS_DATA_PIN = 2;
const int ST_CP_LATCH_PIN = 4;
const int SH_CP_CLOCK_PIN = 5;

// switch inputs (active high)
const int SW0_PIN = 13;
const int SW1_PIN = 12;
const int SW2_PIN = 14;
const int SW3_PIN = 16;

/* register_data maps the 16 bits
 bit | LED# | color (active low)
  0  |      |
  1  |      |
  2  | 3    | red
  3  | 3    | green
  4  | 3    | blue
  5  | 2    | red
  6  | 2    | green
  7  | 2    | blue
  8  |      |
  9  |      |
 10  | 1    | red
 11  | 1    | green
 12  | 1    | blue
 13  | 0    | red
 14  | 0    | green
 15  | 0    | blue
*/
uint16_t register_data = 0xFFFF;

// number of bits into register_data that the individual leds are found:
uint16_t led_offset[] = {13, 10, 5, 2};

// track LED states with mnemonics
enum class LedMode : uint8_t {
    red = 0,
    green = 1,
    blue = 2,
    off = 3
};

// current states for the 4 LEDs
LedMode led_mode[] = {
  LedMode::off,
  LedMode::red,
  LedMode::off,
  LedMode::off
};

// true if button state has changed since last status call
bool status_changed = false;

// current playing state (true = playing, false = stopped)
bool play_state = false;

// indicates first mark has been made
bool mark_one = false;

// indicates second mark has been made i.e. now looping
bool mark_two = false;

// keepalive counter for temporary indicators
int flash_countdown = 0;
const int FLASH_COUNT = 10;

// supported events encoded with mnemonics
enum class VideoEvent : uint8_t {
  nop = 0,
  play = 1,
  stop = 2,
  skip_back = 3,
  skip_fwd = 4,
  mark = 5,
  loop = 6,
  loop_reset = 7
};

// indicates a single (most recent) action to take (missed actions are silently dropped)
VideoEvent current_event = VideoEvent::nop;


/*
 * Command: server the main page. This causes a state reset.
 */
void handleRoot() {
  server.send(200, "text/html", index_page);
  resetFootSwitchState();
}


/*
 * Command: server the current status
 */
void handleStatus() {
  char buffer[200];
  StaticJsonDocument<200> status;

  status["uptime"] = millis();
  status["changed"] = status_changed;
  status["event"] = (uint8_t)current_event;
  status["play"] = play_state;
  status["loop"] = mark_two;

  serializeJson(status, buffer);
  server.send(200, "application/json", buffer);

  // reset event and changed status
  status_changed = false;
  current_event = VideoEvent::nop;

  // clear temporary indicators
  if (flash_countdown > 0) {
    --flash_countdown;
  } else {
    led_mode[0] = LedMode::off;
    led_mode[2] = LedMode::off;
    pushLedSettings();
  }
}


/*
 * Command: simple 404
 */
void handleNotFound() {
  String message = "File Not Found\n\n";
  server.send ( 404, "text/plain", message );
}


/*
 * Command: reset state to startup condition
 */
void resetFootSwitchState() {
  status_changed = false;
  play_state = false;
  mark_one = false;
  mark_two = false;
  current_event = VideoEvent::nop;
  led_mode[0] = LedMode::off;
  led_mode[1] = LedMode::red;
  led_mode[2] = LedMode::off;
  led_mode[3] = LedMode::off;
}


/*
 * Command: startup wifi and webserver
 */
void wifiStartup() {
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.print( "." );
    #endif
  }

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.println( "" );
  Serial.print( "Connected to " );
  Serial.println( ssid );
  Serial.print( "IP address: " );
  Serial.println( WiFi.localIP() );
  #endif

  if (MDNS.begin(server_host_name)) {
    MDNS.addService("http", "tcp", 80);
  }

  // Start TCP (HTTP) server
  server.on("/", handleRoot);
  server.on("/status.json", handleStatus);
  server.onNotFound (handleNotFound);
  server.begin();

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.println( "HTTP server started" );
  #endif
}


/*
 * Command: recalculates the correct LED register data
 */
void updateRegisterData() {
  register_data = 0xFFFF;
  for(int led = 0; led < 4; ++led) {
    if (led_mode[led] != LedMode::off) {
      register_data &= ~bit(led_offset[led] + (uint8_t)led_mode[led]);
    }
  }

}


/*
 * Command: push the led_values to the shift registers
 */
void pushLedSettings() {
  updateRegisterData();
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, register_data >> 8);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, register_data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}


/*
 * Command: set stopped playing mode (also turns off looping)
 */
void setStopped() {
  mark_one = false;
  mark_two = false;
  play_state = false;
  led_mode[1] = LedMode::red;
  led_mode[3] = LedMode::off;
  current_event = VideoEvent::stop;
}


/*
 * Command: handle button presses, with some simple software debouncing
 */
bool switchPressed() {
  static unsigned long debounce_until = DEBOUNCE_DELAY;
  bool result = false;

  if ( millis() > debounce_until && current_event == VideoEvent::nop ) {
    if(digitalRead(SW0_PIN)) {
      led_mode[0] = LedMode::green;
      current_event = VideoEvent::skip_back;
      flash_countdown = FLASH_COUNT;
      result = true;
    } else if(digitalRead(SW1_PIN)) {
      if (play_state) {
        setStopped();
      } else {
        play_state = true;
        led_mode[1] = LedMode::green;
        current_event = VideoEvent::play;
      }
      result = true;
    } else if(digitalRead(SW2_PIN)) {
      led_mode[2] = LedMode::green;
      current_event = VideoEvent::skip_fwd;
      flash_countdown = FLASH_COUNT;
      result = true;
    } else if(digitalRead(SW3_PIN)) {
      if (mark_two) {
        setStopped();
        current_event = VideoEvent::loop_reset;
      } else if (mark_one) {
        mark_two = true;
        led_mode[3] = LedMode::blue;
        current_event = VideoEvent::loop;
      } else {
        mark_one = true;
        led_mode[3] = LedMode::green;
        current_event = VideoEvent::mark;
      }
      result = true;
    }
    if (result) {
      debounce_until = millis() + DEBOUNCE_DELAY;
      status_changed = true;
    }
  }
  return result;
}


/*
 * Command: one-time setup
 */
void setup() {
  #ifdef ENABLE_SERIAL_DEBUG
  Serial.begin ( 115200 );
  #endif

  pinMode(DS_DATA_PIN, OUTPUT);
  pinMode(ST_CP_LATCH_PIN, OUTPUT);
  pinMode(SH_CP_CLOCK_PIN, OUTPUT);
  pinMode(SW0_PIN, INPUT);
  pinMode(SW1_PIN, INPUT);
  pinMode(SW2_PIN, INPUT);
  pinMode(SW3_PIN, INPUT);

  resetFootSwitchState();
  pushLedSettings();
  wifiStartup();
}


/*
 * Command: main loop
 */
void loop() {
  if (switchPressed()) {
    pushLedSettings();
  }
  server.handleClient();
}
