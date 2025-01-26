#include "ring_counter.h"


RingCounter::RingCounter(int clock_pin, int enable_pin, int reset_pin) {
  this->clock_pin = clock_pin;
  this->enable_pin = enable_pin;
  this->reset_pin = reset_pin;
  this->pulse_width = 1;
}

void RingCounter::init() {
  pinMode(clock_pin, OUTPUT);
  pinMode(reset_pin, OUTPUT);
  pinMode(enable_pin, OUTPUT);
  enable();
  reset();
}


void RingCounter::pulse() {
  digitalWrite(clock_pin, HIGH);
  delay(pulse_width);
  digitalWrite(clock_pin, LOW);
}

void RingCounter::reset() {
  digitalWrite(reset_pin, HIGH);
  delay(pulse_width);
  digitalWrite(reset_pin, LOW);
}

void RingCounter::enable() {
  digitalWrite(enable_pin, LOW);
}

void RingCounter::disable() {
  digitalWrite(enable_pin, HIGH);
}