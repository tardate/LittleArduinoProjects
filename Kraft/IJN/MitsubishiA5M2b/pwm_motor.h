#pragma once

#include <Arduino.h>

class PwmMotor
{
  public:
    void setup(int motor_pin, int control_pin, int delay = 100);
    void update();

  private:
    int _motor_pin;
    int _control_pin;
    int _update_delay;
    unsigned long _next_update;
};
