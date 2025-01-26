#pragma once

#include <Arduino.h>

class Dial
{
  public:
    void setup(int control_pin, int delay = 100, int scale = 1023);
    void update();
    int level;

  private:
    int _scale;
    int _control_pin;
    int _update_delay;
    unsigned long _next_update;
    void read();
};
