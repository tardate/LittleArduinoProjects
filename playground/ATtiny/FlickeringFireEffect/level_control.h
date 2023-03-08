#pragma once

#include <Arduino.h>

class LevelControl
{
  public:
    void setup(int pin, int delay = 100);
    int level(int scale = 255);
    void read();

  private:
    int _pin;
    int _level = 0;  // soft start
    int _update_delay;
    unsigned long _next_update;
};
