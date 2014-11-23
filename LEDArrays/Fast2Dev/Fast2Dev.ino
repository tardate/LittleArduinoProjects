// based on original code from the FastLED project at http://fastled.io/

#include "FastLED.h"

#define NUM_LEDS 12  // How many leds in your strip?
#define DATA_PIN 6   // signal pin pin

CRGB leds[NUM_LEDS]; // Define the array of leds

void setup() {
  delay(2000);                                              // sanity check delay
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);   // you might need to change this based on your LED strip
  LEDS.setBrightness(64);
}

void loop() {
  for(int i = 0; i < 3; i++) {
    for(int iLed = 0; iLed < NUM_LEDS; iLed++) {
      memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));

      switch(i) {
        // You can access the rgb values by field r, g, b
        case 0: leds[iLed].r = 128; break;

        // or by indexing into the led (r==0, g==1, b==2)
        case 1: leds[iLed][i] = 128; break;

        // or by setting the rgb values for the pixel all at once
        case 2: leds[iLed] = CRGB(0, 0, 128); break;
      }

      // and now, show your led array!
      LEDS.show();
      delay(10);
    }

    // fade up
    for(int x = 0; x < 128; x++) {
      // The showColor method sets all the leds in the strip to the same color
      LEDS.showColor(CRGB(x, 0, 0));
      delay(10);
    }

    // fade down
    for(int x = 128; x >= 0; x--) {
      LEDS.showColor(CRGB(x, 0, 0));
      delay(10);
    }

    // let's fade up by scaling the brightness
    for(int scale = 0; scale < 128; scale++) {
      LEDS.showColor(CRGB(0, 128, 0), scale);
      delay(10);
    }

    // let's fade down by scaling the brightness
    for(int scale = 128; scale > 0; scale--) {
      LEDS.showColor(CRGB(0, 128, 0), scale);
      delay(10);
    }
  }
}
