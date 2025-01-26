/*

  based on original code from the FastLED project at http://fastled.io/

  Use this sketch to determine the RGB ordering of your chipset

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/LEDArrayDemos/RGBCalibrate

*/

#include <FastLED.h>

#define NUM_LEDS 12  // How many leds in your strip?
#define DATA_PIN 6   // signal pin pin

CRGB leds[NUM_LEDS]; // Define the array of leds

void setup() {
  delay(2000);                                              // sanity check delay
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);   // you might need to change this based on your LED strip
}

void loop() {
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Blue;
  FastLED.show();
  delay(1000);
}
