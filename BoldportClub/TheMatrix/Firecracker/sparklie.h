#pragma once

#include <LRAS1130.h>

class Sparklie {
public:
  Sparklie();

  /*
    Command: recalculates the sparkles next position if it is alive, else might regenerate if with_regeneration is true.
    Returns whether the sparkle is aliver at the end.
   */
  bool recalculate(bool with_regeneration);
  /*
    Command: clears the sparkle display on the given page
   */
  void clear(lr::AS1130Picture24x5& page);
  /*
    Command: draws the sparkle display on the given page and driver
   */
  void draw(lr::AS1130Picture24x5& page, lr::AS1130& driver);

private:
  uint8_t max_height;
  uint8_t max_displacement;
  uint8_t x;
  uint8_t y;
  uint16_t ttl;
  int8_t ticks_per_step;
  int8_t tick_counter;
  bool alive;
  bool up;

  /*
    Returns: true if it is time for the sparkle to regenerate
   */
  bool shouldRegenerate();

  /*
   Command: a sparkle is born - sets some randomised defaults
  */
  void initialiseSettings();

};
