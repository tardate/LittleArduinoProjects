#include "KeyController.h"

void KeyController::readKeys() {
  tm1638_driver->readKeys(current_value);
}

bool KeyController::rollKeyPressed() {
  readKeys();
  return current_value[0] & BUTTON1_MASK;
}

bool KeyController::bothDiceEnabled() {
  return current_value[0] & BUTTON2_MASK;
}

void KeyController::debounceDelay() {
  delay(DEBOUNCE_DELAY);
}
