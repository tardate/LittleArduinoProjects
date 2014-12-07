#include "LedStripEffects.h"


/*
 *   constructor
 */
LedStripEffects::LedStripEffects(CRGB *leds, int number_of_leds)
{
  this->number_of_leds = number_of_leds;
  this->leds = leds;
}

/*
 *  chaser effect - move a single led of specified color along the strip
 *  This is based on the FirstLight sketch from the FastLED library
 */
void LedStripEffects::chaser(CRGB::HTMLColorCode color, int ms_per_step)
{
  for(int i = 0; i < this->number_of_leds; i++) {
    // set the color of the next led in sequence
    leds[i] = color;
    // show and pause for a bit
    FastLED.show();
    delay(ms_per_step);
    // clear the led
    leds[i] = CRGB::Black;
  }

}

/*
 *  cylon effect
 *  This is based on the Cylon sketch from the FastLED library
 */
void LedStripEffects::cylon(CRGB::HTMLColorCode color)
{
  // First slide the led in one direction
  for(int i = 0; i <  this->number_of_leds; i++) {
    // Set the i'th led to red
    leds[i] = color;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
    delay(30);
  }

  // Now go in the other direction.
  for(int i =  this->number_of_leds-1; i >= 0; i--) {
    // Set the i'th led to red
    leds[i] = color;
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
    delay(30);
  }
}

/*
 *  demo fade by scaling color and brightness
 *  This is based on the Fast2Dev sketch from the FastLED library
 */
void LedStripEffects::fast_fade_and_scale()
{
  for(int i = 0; i < 3; i++) {
    for(int iLed = 0; iLed < this->number_of_leds; iLed++) {
      memset(this->leds, 0,  this->number_of_leds * sizeof(struct CRGB));

      switch(i) {
        // You can access the rgb values by field r, g, b
        case 0: this->leds[iLed].r = 128; break;

        // or by indexing into the led (r==0, g==1, b==2)
        case 1: this->leds[iLed][i] = 128; break;

        // or by setting the rgb values for the pixel all at once
        case 2: this->leds[iLed] = CRGB(0, 0, 128); break;
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
