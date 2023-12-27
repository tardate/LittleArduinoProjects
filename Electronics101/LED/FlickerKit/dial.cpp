#include "dial.h"

void Dial::setup(int control_pin, int delay, int scale) {
  _control_pin = control_pin;
  pinMode(_control_pin, INPUT);

  _update_delay = delay;
  _next_update  = millis() + _update_delay;

  _scale = scale;

  read();
}

void Dial::update() {
  if (millis() >= _next_update) {
    _next_update += _update_delay;
    read();
  }
}

void Dial::read() {
  level = map(analogRead(_control_pin), 0, 1023, 0, _scale);
}
