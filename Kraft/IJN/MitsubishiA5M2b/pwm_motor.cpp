#include "pwm_motor.h"

void PwmMotor::setup(int motor_pin, int control_pin, int delay) {
  _motor_pin = motor_pin;
  _control_pin = control_pin;
  pinMode(_motor_pin, OUTPUT);
  pinMode(_control_pin, INPUT);

  _update_delay = delay;
  _next_update  = millis() + _update_delay;
}

void PwmMotor::update() {
  if (millis() >= _next_update) {
    _next_update += _update_delay;
    analogWrite(_motor_pin, map(analogRead(_control_pin), 0, 1023, 0, 255));
  }
}
