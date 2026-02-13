#include "ButtonMonitor.h"

ButtonMonitor::ButtonMonitor(int button_pin, unsigned long debounce_delay) {
  this->button_pin = button_pin;
  this->debounce_delay = debounce_delay;
  this->button_state = HIGH;
  this->last_debounce_time = 0;
}

void ButtonMonitor::begin(void) {
  pinMode(button_pin, INPUT);
  digitalWrite(button_pin, HIGH); // enable pull-up resistor
}

bool ButtonMonitor::update(void) {
  if ((millis() - last_debounce_time) <= debounce_delay) return false;

  bool reading = digitalRead(button_pin);

  if (reading != button_state) {
    button_state = reading;
    last_debounce_time = millis();
    return isPressed();
  } else {
    return false;
  }
}

bool ButtonMonitor::isPressed(void) {
  return (button_state == LOW);
}
