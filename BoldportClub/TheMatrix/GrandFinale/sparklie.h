#pragma once

#include <LRAS1130.h>


/// @brief particle actor
/// Each sparlie represents a single animation element
///
class Sparklie {
public:
  Sparklie();

  /// @brief Command: recalculates the sparkles next position if it is alive, else might regenerate if with_regeneration is true.
  /// Returns whether the sparkle is alive at the end.
  ///
  bool recalculate(bool with_regeneration, uint8_t custom_height, uint8_t custom_velocity);

  /// @brief Command: clears the sparkle display on the given page
  ///
  void clear(lr::AS1130Picture24x5& page);

  /// @brief Command: draws the sparkle display on the given page and driver
  ///
  void draw(lr::AS1130Picture24x5& page, lr::AS1130& driver);

private:
  uint8_t max_height;        // pre-calculated peak height
  uint8_t max_displacement;  // pre-calculated final displacement
  uint8_t x;                 // current position (0-23) aka "height"
  uint8_t y;                 // current position (0-4) aka "displacement"
  uint16_t ttl;              // the time to live after the sparklie has "returned to earth"
  int8_t ticks_per_step;     // how many animation ticks between movement
  int8_t tick_counter;       // current step tick counter
  bool alive;                // if sparklie is alive
  bool up;                   // if sparklie is currently moving up

  /// @brief Returns: true if it is time for the sparkle to regenerate
  ///
  bool shouldRegenerate();

  /// @brief Command: a sparkle is born - sets some randomised defaults
  ///
  void initialiseSettings(uint8_t custom_height, uint8_t custom_velocity);

};
