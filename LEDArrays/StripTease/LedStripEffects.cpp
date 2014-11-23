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
 *  This is based on FirstLight from the FastLED library
 */
void LedStripEffects::chaser(CRGB::HTMLColorCode color, int ms_per_step)
{
  for(int iLed = 0; iLed < this->number_of_leds; iLed++) {
    // set the color of the next led in sequence
    this->leds[iLed] = color;
    // show and pause for a bit
    FastLED.show();
    delay(ms_per_step);
    // clear the led
    leds[iLed] = CRGB::Black;
  }

}

