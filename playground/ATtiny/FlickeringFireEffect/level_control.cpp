#include "level_control.h"

void LevelControl::setup(int pin, int delay) {
  _pin = pin;
  pinMode(_pin, INPUT);
  _update_delay = delay;
  _next_update = millis() + _update_delay;
}

int LevelControl::level(int scale) {
  read();
  return map(_level, 0, 1023, 0, scale);
}

void LevelControl::read() {
  if (millis() >= _next_update) {
    _next_update += _update_delay;

    _level = analogRead(_pin);
  }
}
