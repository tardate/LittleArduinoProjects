#include "DigitDisplay.h"

byte LED_DIGIT_MASK[] = {
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111
};

const byte LED_CLEAR_MASK = 0b00000000;
const byte LED_DP_MASK    = 0b10000000;

DigitDisplay::DigitDisplay(uint8_t mosi_pin, uint8_t sck_pin, uint8_t cs_pin, int8_t initial_value, int8_t min_value=0, int8_t max_value=9) {
  this->mosi_pin = mosi_pin;
  this->sck_pin = sck_pin;
  this->cs_pin = cs_pin;
  this->initial_value = initial_value;
  this->min_value = min_value;
  this->max_value = max_value;
  pinMode(cs_pin, OUTPUT);
  pinMode(mosi_pin, OUTPUT);
  pinMode(sck_pin, OUTPUT);
}

void DigitDisplay::reset(void) {
  this->current_value = initial_value;
  update();
}

void DigitDisplay::update(void) {
  if (valid()) {
    writeDigit(current_value);
  } else {
    clearDigit();
  }
}

void DigitDisplay::inc(void) {
  set(current_value + 1);
}

void DigitDisplay::dec(void) {
  set(current_value - 1);
}

void DigitDisplay::set(int8_t value) {
  this->current_value = value;
}

bool DigitDisplay::valid(void) {
  return (current_value >= min_value && current_value <= max_value);
}

int8_t DigitDisplay::value(void) {
  return current_value;
}

void DigitDisplay::pushLed7SegmentRegister(byte data) {
  digitalWrite(cs_pin, LOW);
  shiftOut(mosi_pin, sck_pin, MSBFIRST, data);
  digitalWrite(cs_pin, HIGH);
}

void DigitDisplay::writeLed7SegmentDigit(byte digit, boolean withDP) {
  if(withDP) pushLed7SegmentRegister(LED_DIGIT_MASK[digit] | LED_DP_MASK);
  else pushLed7SegmentRegister(LED_DIGIT_MASK[digit]);
}

void DigitDisplay::writeDigit(byte digit) {
  pushLed7SegmentRegister(LED_DIGIT_MASK[digit]);
}

void DigitDisplay::clearDigit() {
  pushLed7SegmentRegister(LED_CLEAR_MASK);
}
