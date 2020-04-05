/*

  ButtonTester
  Diagnostic sketch. Used to verify the foot switches and LEDs are working correctly.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/ESP8266/YouTubeFootSwitch

 */

// #define ENABLE_SERIAL_DEBUG

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <ArduinoJson.h>

#include "settings.h"

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
  LedMode::off,
  LedMode::off,
  LedMode::off
};

// true if button state has changed since last status call
bool status_changed = false;

// main web page content
char index_page[] = "<!doctype html>\
<html lang=\"en\">\
<head>\
<meta charset=\"utf-8\">\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\
<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">\
<style>\
.switch .card-body { min-height: 180px; }\
.switch .card-body.state-0 { background-color: red; }\
.switch .card-body.state-1 { background-color: green; }\
.switch .card-body.state-2 { background-color: blue; }\
.switch .card-body.state-3 { background-color: gray; }\
</style>\
</head>\
<body>\
<div class=\"container-fluid mt-3\">\
<div class=\"row\">\
<div class=\"col-3\">\
<div class=\"card\">\
<img src=\"https://leap.tardate.com/electronics101/inputdevices/footswitch/assets/FootSwitch_build.jpg\" class=\"card-img-top\">\
<div class=\"card-body\">\
<h5 class=\"card-title\">YouTubeFootSwitch Button Tester</h5>\
<p class=\"card-text\">Compiled on " __DATE__ " at " __TIME__ "</p>\
<p class=\"card-text\">Uptime: <span id=\"uptime\" class=\"badge badge-success\">00:00:00</span></p>\
</div>\
</div>\
</div>\
<div class=\"col-9\">\
<div class=\"container-fluid\">\
<div class=\"row\">\
<div class=\"col-3\">\
<div class=\"card switch\" id=\"sw0\">\
<div class=\"card-header\">SW0</div>\
<div class=\"card-body\"></div>\
</div>\
</div>\
<div class=\"col-3\">\
<div class=\"card switch\" id=\"sw1\">\
<div class=\"card-header\">SW1</div>\
<div class=\"card-body\"></div>\
</div>\
</div>\
<div class=\"col-3\">\
<div class=\"card switch\" id=\"sw2\">\
<div class=\"card-header\">SW2</div>\
<div class=\"card-body\"></div>\
</div>\
</div>\
<div class=\"col-3\">\
<div class=\"card switch\" id=\"sw3\">\
<div class=\"card-header\">SW3</div>\
<div class=\"card-body\"></div>\
</div>\
</div>\
</div>\
</div>\
</div>\
</div>\
</div>\
<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js\"></script>\
<script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js\"></script>\
<script type=\"text/javascript\">\
$( document ).ready(function() {\
function update(data) {\
$('#uptime').html( new Date(data.uptime).toISOString().substr(11, 8) );\
if ( data.changed ) {\
$('#sw0 .card-body').attr(\"class\", \"card-body state-\" + data.sw0);\
$('#sw1 .card-body').attr(\"class\", \"card-body state-\" + data.sw1);\
$('#sw2 .card-body').attr(\"class\", \"card-body state-\" + data.sw2);\
$('#sw3 .card-body').attr(\"class\", \"card-body state-\" + data.sw3);\
}\
};\
var sampler = function() {\
$.ajax({\
url: '/status.json',\
success: function( data ) {\
update(data);\
setTimeout(sampler, 10);\
}\
});\
};\
sampler();\
});\
</script>\
</body>\
</html>";


/*
 * Command: server the main page
 */
void handleRoot() {
  server.send(200, "text/html", index_page);
}


/*
 * Command: server the current status
 */
void handleStatus() {
  char buffer[200];
  StaticJsonDocument<200> status;

  status["uptime"] = millis();
  status["sw0"] = (uint8_t)led_mode[0];
  status["sw1"] = (uint8_t)led_mode[1];
  status["sw2"] = (uint8_t)led_mode[2];
  status["sw3"] = (uint8_t)led_mode[3];
  status["changed"] = status_changed;

  serializeJson(status, buffer);
  server.send(200, "application/json", buffer);

  status_changed = false;
}


/*
 * Command: simple 404
 */
void handleNotFound() {
  String message = "File Not Found\n\n";
  server.send ( 404, "text/plain", message );
}


/*
 * Command: startup wifi and webserver
 */
void wifiStartup() {
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print ( "." );
  }

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.println ( "" );
  Serial.print ( "Connected to " );
  Serial.println ( ssid );
  Serial.print ( "IP address: " );
  Serial.println ( WiFi.localIP() );
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
  Serial.println ( "HTTP server started" );
  #endif
}


/*
 * Command: recalculates the correct register data
 */
void updateRegisterData() {
  register_data = 0xFFFF;
  for(int led = 0; led < 4; ++led) {
    if (led_mode[led] != LedMode::off) {
      register_data &= ~bit(led_offset[led] + (uint8_t)led_mode[led]);
    }
  }
  status_changed = true;
}


/*
 * Command: push the led_values to the shift registers
 */
void pushLedSettings() {
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, register_data >> 8);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, register_data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}


/*
 * Command: cycle the color for the specified led
 */
void stepLedMode(int led) {
  switch (led_mode[led]) {
  case LedMode::off:
    led_mode[led] = LedMode::red;
    break;
  case LedMode::red:
    led_mode[led] = LedMode::green;
    break;
  case LedMode::green:
    led_mode[led] = LedMode::blue;
    break;
  case LedMode::blue:
    led_mode[led] = LedMode::off;
    break;
  }
}


/*
 * Command: handle button presses, with some simple software debouncing
 */
bool switchPressed() {
  static unsigned long debounce_until = DEBOUNCE_DELAY;
  bool result = false;

  if ( millis() > debounce_until ) {
    if(digitalRead(SW0_PIN)) {
      stepLedMode(0);
      result = true;
    }
    if(digitalRead(SW1_PIN)) {
      stepLedMode(1);
      result = true;
    }
    if(digitalRead(SW2_PIN)) {
      stepLedMode(2);
      result = true;
    }
    if(digitalRead(SW3_PIN)) {
      stepLedMode(3);
      result = true;
    }
    if (result) {
      debounce_until = millis() + DEBOUNCE_DELAY;
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
  pushLedSettings();

  wifiStartup();
}


/*
 * Command: main loop
 */
void loop() {
  server.handleClient();
  if (switchPressed()) {
    updateRegisterData();
    pushLedSettings();
  }
}
