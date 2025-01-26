#include "display_72R02.h"
#include <SPI.h>


Display72R02::Display72R02(int data_pin) {
  this->data_pin = data_pin;
}

void Display72R02::init() {
  this->current_digit = 0;
  pinMode(data_pin, OUTPUT);
  clear();
}

void Display72R02::clear() {
  clearStatusIndictors();
  clearDigits();
}

void Display72R02::setStatus(byte status_index) {
  this->status_indicators = 0x1 << status_index;
}

void Display72R02::enableStatus(byte status_index) {
  this->status_indicators |= 0x1 << status_index;
}

void Display72R02::setStatusIndictors(byte status_indicators) {
  this->status_indicators = status_indicators;
}

void Display72R02::clearStatusIndictors() {
  setStatusIndictors(0);
}

void Display72R02::setDigit(byte digit, byte value) {
  this->digits[digit] = segment_mask[value];
}

void Display72R02::clearDigits() {
  for(int i=0; i<DISPLAY_DIGITS; i++) digits[i] = 0;
}

void Display72R02::refresh() {
  pushDisplayUpdate(status_indicators, digits[current_digit], 0xFF ^ 0x1 << (current_digit + 1));
  current_digit++;
  if(current_digit==DISPLAY_DIGITS) current_digit=0;
}

void Display72R02::pushDisplayUpdate(byte status_indicators, byte segment_enable, byte digit_enable) {
  digitalWrite(data_pin, LOW);
  SPI.transfer(digit_enable);
  SPI.transfer(segment_enable);
  SPI.transfer(status_indicators);
  digitalWrite(data_pin, HIGH);
}