#include "KeyController.h"


bool KeyController::keyPressed() {
  return current_value[0] != 0;
}

bool KeyController::bothKeysPressed() {
  return current_value[0] == (BUTTON1_MASK | BUTTON2_MASK);
}

bool KeyController::decrementKeyPressed() {
  return current_value[0] & BUTTON1_MASK;
}

bool KeyController::incrementKeyPressed() {
  return current_value[0] & BUTTON2_MASK;
}

void KeyController::debounceDelay() {
  delay(DEBOUNCE_DELAY);
}