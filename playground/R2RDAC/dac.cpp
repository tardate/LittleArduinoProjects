#include "dac.h"


DAC::DAC(int data_pin, int latch_pin, int clock_pin) {
  this->data_pin = data_pin;
  this->latch_pin = latch_pin;
  this->clock_pin = clock_pin;
  init();
}

void DAC::init() {
  pinMode(data_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
}

// Command: sends a 16-bit value to the shift register chain, LSB first
// NB: this could be significantly optimised by using direct port access
void DAC::write16(unsigned int data) {
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, data);
  shiftOut(data_pin, clock_pin, LSBFIRST, data >> 8);
  digitalWrite(latch_pin, HIGH);
}
