#ifndef __INC_LED_STRIP_EFFECTS_H
#define __INC_LED_STRIP_EFFECTS_H

#include "FastLED.h"

// library interface description
class LedStripEffects {
  public:
    // constructors:
    LedStripEffects(CRGB *leds, int number_of_leds);

    // chaser effect
    void chaser(CRGB::HTMLColorCode color, int ms_per_step);

    // cylon effect
    void cylon(CRGB::HTMLColorCode color);

    // fade by scaling color and brightness
    void fast_fade_and_scale();

  private:

    CRGB *leds;
    int number_of_leds;

};

#endif
