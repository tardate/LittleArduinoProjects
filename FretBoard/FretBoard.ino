/*

  Retrieve continuous integration server status from the net and visualise status with a
  ws2811-based programmable LED array.

 */

#include <SPI.h>
#include <Ethernet.h>
#include <TextFinder.h>
#include <FastLED.h>

#include "settings.h"

EthernetClient client;
TextFinder finder( client );

const int max_line_part_length = 100;    // max length for an element in the build status response

CRGB leds[MAX_PROJECTS];                 // array of LEDs

byte builds[MAX_PROJECTS];               // array of build status values.

// build status values are recorded as follows:
// xx00 - undefined/off
// xx01 - 1 sleeping or checking mods
// xx10 - 2 building
// 00xx - undefined/off
// 01xx - 4 fail
// 10xx - 8 success
// i.e.:
// 5 = failed/sleeping
// 6 = failed/building
// 9 = success/sleeping or checking mods
// 10 = success/building
// < 5 = undefined
// < 8 = failed

void setup() {

#ifdef SERIAL_DEBUG
  Serial.begin(9600);
#endif

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
#ifdef SERIAL_DEBUG
    Serial.println("Failed to configure Ethernet using DHCP");
#endif
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }

  // give the Ethernet shield a second to initialize:
#ifdef SERIAL_DEBUG
  Serial.println("firing up the Ethernet...");
#endif
  delay(1000);

  // you might need to change this based on your LED strip
  FastLED.addLeds<WS2811, LED_DATA_PIN, RGB>(leds, MAX_PROJECTS);

  FastLED.clear();
  FastLED.setBrightness(32);
}

void loop()
{

  getBuildStatus();

  ledEffects();

  delay(BUILD_STATUS_POLL_INTERVAL);
}

void ledEffects() {
  for(int iLed = 0; iLed < MAX_PROJECTS; iLed++) {
    switch(builds[iLed]) {
    case 5 : // failed/sleeping
      leds[iLed] = CRGB::Red;
      break;
    case 6 : // failed/building
      leds[iLed] = CRGB::OrangeRed;
      break;
    case 9 : // success/sleeping or checking mods
      leds[iLed] = CRGB::Green;
      break;
    case 10 : //success/building
       leds[iLed] = CRGB::PaleGreen;
       break;
    default: // undefined
      leds[iLed] = CRGB::Black;
    }

  }
  // show and pause for a bit
  FastLED.show();
}

void getBuildStatus() {
  char name[max_line_part_length];
  char build_activity_name[max_line_part_length];
  char build_status_name[max_line_part_length];
  byte build_id = 0;
  byte build_status;

  String debug = "name:";

  if(sendRequest()) {
    if(finder.find("\r\n\r\n")) {

      while(finder.getString(",", name, max_line_part_length) > 0) {
        if(finder.getString(",", build_activity_name, max_line_part_length) > 0) {
          if(finder.getString("\n", build_status_name, max_line_part_length) > 0) {

            if(build_id < MAX_PROJECTS) {

              switch(build_status_name[0]) {
                case 'S': // Success
                  build_status = 8;
                  break;
                case 'F': // Failure
                  build_status = 4;
                  break;
                default:
                  build_status = 0;
              }
              switch(build_activity_name[0]) {
                case 'B': // Building
                  build_status = build_status ^ 2;
                  break;
                case 'S': // Sleeping
                  build_status = build_status ^ 1;
                  break;
                case 'C': // CheckingModifications
                  build_status = build_status ^ 1;
                  break;
              }
              builds[build_id] = build_status;
#ifdef SERIAL_DEBUG
              Serial.println(debug + name + " activity:" + build_activity_name + " status:" + build_status_name + " build_id:" + build_id + " builds[]:" + builds[build_id]);
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

    client.stop();
    client.flush();

  }
}

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

