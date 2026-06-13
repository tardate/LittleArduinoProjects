#include "Die.h"

Die::Die() {
  enabled = true;
  clear();
}

void Die::clear() {
  value = NUMBER_CLEAR;
}

void Die::blank() {
  value = NUMBER_BLANK;
}

void Die::enable() {
  if (enabled) return;

  enabled = true;
  roll();
}

void Die::disable() {
  if (!enabled) return;

  blank();
  enabled = false;
}

void Die::roll() {
  if (!enabled) return;

  value = random(1, 7);
}
