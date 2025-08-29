/*

  FretBoard

  Retrieve continuous integration server status from the net and visualise status with a
  ws2811-based programmable LED array.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/FretBoard

 */

#include <SPI.h>
#include <Ethernet.h>
#include <TextFinder.h>
#include <FastLED.h>
#include <FlexiTimer2.h>

#include "settings.h"

EthernetClient client;
TextFinder finder( client );

CRGB leds[MAX_PROJECTS];                       // array of LEDs

byte build_status[MAX_PROJECTS];               // array of build status values.
/*
  build status values are recorded as follows:
  xx00 - undefined/off
  xx01 - 1 sleeping, checking mods or unknown
  xx10 - 2 building
  00xx - undefined/off
  01xx - 4 fail
  10xx - 8 success
  i.e.:
  5 = failed/sleeping
  6 = failed/building
  9 = success/sleeping or checking mods
  10 = success/building
  < 5 = undefined
  < 8 = failed
*/

volatile byte total_projects = 0;              // actual number of active projects

volatile byte status_updating = 0;             // set to total_projects after build status update

volatile boolean led_toggle = true;
volatile signed int led_scale = 0;
volatile signed int led_scale_factor = 1;

void setup() {

#ifdef SERIAL_DEBUG
  Serial.begin(115200);
#endif

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
#ifdef SERIAL_DEBUG
    Serial.println("Failed to configure Ethernet using DHCP");
#endif
    // try to configure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }

  // give the Ethernet shield a second to initialize:
#ifdef SERIAL_DEBUG
  Serial.println("firing up the Ethernet...");
#endif
  delay(1000);

  // you might need to change this based on your LED strip
  FastLED.addLeds<WS2811, LED_DATA_PIN, RGB>(leds, MAX_PROJECTS);

  for(int iLed = 0; iLed < MAX_PROJECTS; iLed++) {
    leds[iLed] = CRGB::Black;
  }

  FastLED.clear(true);
  FastLED.setBrightness(32);

  FlexiTimer2::set(10, redrawLedEffects);
  FlexiTimer2::start();
}


/*
  loop()
  runs the main loop to update build status every BUILD_STATUS_POLL_INTERVAL milliseconds or so
 */
void loop()
{
  getBuildStatus();
  delay(BUILD_STATUS_POLL_INTERVAL);
}


/*
  redrawLedEffects()
  invoked by timer to update LED display
 */
void redrawLedEffects() {

  if(status_updating > 0) {
    // cycles a blue LED around all the active projects after an update received
    status_updating--;
    for(int iLed = 0; iLed < MAX_PROJECTS; iLed++) {
      if(iLed==status_updating) {
        leds[iLed] = CRGB::Blue;
      } else {
        leds[iLed] = CRGB::Black;
      }
    }
    FastLED.show(128);

  } else {
    for(int iLed = 0; iLed < MAX_PROJECTS; iLed++) {
      // map the build status to LED color
      switch(build_status[iLed]) {
      case 5 : // failed/sleeping
        leds[iLed] = CRGB::Red;
        break;
      case 6 : // failed/building
        leds[iLed] = led_toggle ? CRGB::OrangeRed : CRGB::Black;
        break;
      case 9 : // success/sleeping or checking mods
        leds[iLed] = CRGB::Green;
        break;
      case 10 : //success/building
        leds[iLed] = led_toggle ? CRGB::PaleGreen : CRGB::Black;
        break;
      default: // undefined
        leds[iLed] = CRGB::Black;
      }
    }
    FastLED.show(led_scale);

    led_toggle = !led_toggle;
    led_scale += led_scale_factor;
    if(led_scale>=128) led_scale_factor = -1;
    if(led_scale<=0) led_scale_factor = 1;

  }

}


/*
  getBuildStatus
  sends web request for build status and parses the result.
 */
void getBuildStatus() {
  char name[MAX_STATUS_PART_LENGTH];
  char build_activity_name[MAX_STATUS_PART_LENGTH];
  char build_status_name[MAX_STATUS_PART_LENGTH];
  byte build_id = 0;
  byte status;

#ifdef SERIAL_DEBUG
  String debug = "name:";
#endif

  if(sendRequest()) {
    if(finder.find("\r\n\r\n")) {

      while(finder.getString(",", name, MAX_STATUS_PART_LENGTH) > 0) {
        if(finder.getString(",", build_activity_name, MAX_STATUS_PART_LENGTH) > 0) {
          if(finder.getString("\n", build_status_name, MAX_STATUS_PART_LENGTH) > 0) {

            if(build_id < MAX_PROJECTS) {

              // parse the build status value
              switch(build_status_name[0]) {
                case 'S': // Success
                  status = 8;
                  break;
                case 'F': // Failure
                  status = 4;
                  break;
                default:
                  status = 0;
              }

              // parse the build activity value
              switch(build_activity_name[0]) {
                case 'B': // Building
                  status = status ^ 2;
                  break;
                case 'S': // Sleeping
                case 'C': // CheckingModifications
                case 'U': // Unknown
                  status = status ^ 1;
                  break;
              }

              build_status[build_id] = status;

#ifdef SERIAL_DEBUG
              Serial.println(debug + name + " activity:" + build_activity_name + " status:" + build_status_name + " build_id:" + build_id + " build_status[]:" + build_status[build_id]);
#endif

            } else {
#ifdef SERIAL_DEBUG
              Serial.println(debug + name + " activity:" + build_activity_name + " status:" + build_status_name + " -- ignore because build_id " + build_id + " exceeds limits");
#endif
            }
            build_id += 1;
          }
        }
      }
    }

    // update the total project count
    total_projects = build_id;

    client.stop();
    client.flush();

    status_updating = MAX_PROJECTS;

  }
}

/*
  sendRequest
  sends the HTTP request for build status
 */
boolean sendRequest() {
  if (client.connect(hostname, 80)) {
#ifdef SERIAL_DEBUG
    Serial.println("connected");
#endif
    // Make a HTTP request:
    client.print("GET ");
    client.print(request_path);
    client.println(" HTTP/1.0");
    client.print("Host: ");
    client.println(hostname);
    client.println("Connection: close");
    client.println();
    return true;
  }
  else {
#ifdef SERIAL_DEBUG
    Serial.println("connection failed");
#endif
    return false;
  }
}
