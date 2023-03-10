#include "flame.h"

void Flame::setup(int pin, int mix, int delay) {
  _pin = pin;
  _mix = mix;
  _update_delay = delay;
  // randomise the first update to prevent multiple flames being in sync
  _next_update  = millis() + random(_update_delay);
}

void Flame::flicker() {
  if (millis() >= _next_update) {
    _next_update += _update_delay;
    _brightness = random(0, 255);
    _brightness = (_mix * _brightness + (100 - _mix) * _old_brightness) / 100;
    _old_brightness = _brightness;
    analogWrite(_pin, _brightness);
  }
}
