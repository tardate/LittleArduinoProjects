/*

  Demo a range of effects for an LED strip

  based on original code from the FastLED project at http://fastled.io/

  Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
  and then how to turn a single pixel white and then off, moving down the line of pixels.

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
  led_strip.chaser(CRGB::Red, 100);
  led_strip.chaser(CRGB::Green, 100);
  led_strip.chaser(CRGB::Blue, 100);
  led_strip.cylon(CRGB::Tomato);
  led_strip.cylon(CRGB::Lime);
  led_strip.cylon(CRGB::PowderBlue);
  led_strip.fast_fade_and_scale();
}
