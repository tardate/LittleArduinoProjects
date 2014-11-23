/*

  based on original code from the FastLED project at http://fastled.io/

  Sweep across the LEDs back and forth

*/

#include "FastLED.h"

#define NUM_LEDS 12  // How many leds in your strip?
#define DATA_PIN 6   // signal pin pin

CRGB leds[NUM_LEDS]; // Define the array of leds

void setup() {
  delay(2000);                                              // sanity check delay
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);   // you might need to change this based on your LED strip
}

void loop() {

  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red
    leds[i] = CRGB::Red;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
    delay(30);
  }

  // Now go in the other direction.
  for(int i = NUM_LEDS-1; i >= 0; i--) {
    // Set the i'th led to red
    leds[i] = CRGB::Red;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
    delay(30);
  }

}
