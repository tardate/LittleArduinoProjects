/*

  Demo a range of effects for an LED strip - chaser, cylon, fades

  based on original code from the FastLED project at http://fastled.io/

*/

#include "FastLED.h"
#include "LedStripEffects.h"

#define NUM_LEDS 12  // How many leds in your strip?
#define DATA_PIN 6   // signal pin pin

CRGB leds[NUM_LEDS];

LedStripEffects led_strip(leds,NUM_LEDS);

void setup() {
  delay(2000); // sanity check delay

  // you might need to change this based on your LED strip
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

  FastLED.clear();
  FastLED.setBrightness(32);
}

void loop() {
  led_strip.clear();
  led_strip.chaser(CRGB::Red, 100);
  led_strip.chaser(CRGB::Green, 100);
  led_strip.chaser(CRGB::Blue, 100);
  led_strip.cylon(CRGB::Tomato, 30);
  led_strip.cylon(CRGB::Lime, 30);
  led_strip.cylon(CRGB::PowderBlue, 30);
  led_strip.fast_fade_and_scale();
}
