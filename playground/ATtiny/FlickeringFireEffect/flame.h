#pragma once

#include <Arduino.h>
#include "level_control.h"

class Flame
{
  public:
    void setup(int pin, LevelControl *level_control, int mix = 20, int delay = 100);
    void flicker();

  private:
    int _pin;
    LevelControl *_level_control;
    int _mix; // percentage (0..100) change to mix on each update. Lower values mean slower changes
    int _update_delay;
    unsigned long _next_update;
    int _brightness = 0;  // soft start
    int _old_brightness = 0;
};
