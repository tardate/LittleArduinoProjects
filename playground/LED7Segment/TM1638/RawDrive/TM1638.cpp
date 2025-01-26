#include "TM1638.h"

TM1638Driver::TM1638Driver(int clk_pin, int data_pin, int cs_pin) {
  this->clk_pin = clk_pin;
  this->data_pin = data_pin;
  this->cs_pin = cs_pin;
}

void TM1638Driver::begin() {
  pinMode(cs_pin, OUTPUT);
  pinMode(clk_pin, OUTPUT);
  setDataOutbound();
  deselect();
}

void TM1638Driver::setDataInbound() {
  pinMode(data_pin, INPUT);
}

void TM1638Driver::setDataOutbound() {
  pinMode(data_pin, OUTPUT);
}

inline void TM1638Driver::select() {
  digitalWrite(cs_pin, LOW);
}

inline void TM1638Driver::deselect() {
  digitalWrite(cs_pin, HIGH);
}

uint8_t TM1638Driver::trace(String message, uint8_t value) {
  Serial.print(message);
  Serial.print(": ");
  Serial.println(value, BIN);
  return value;
}

uint8_t TM1638Driver::readData() {
  return shiftIn(data_pin, clk_pin, LSBFIRST);
}

void TM1638Driver::writeData(uint8_t data) {
  shiftOut(data_pin, clk_pin, LSBFIRST, data);
}

void TM1638Driver::sendData(uint8_t data) {
  select();
  writeData(data);
  deselect();
}

void TM1638Driver::setDataCommand(uint8_t command) {
  sendData(trace(
    "setDataCommand",
    TM1638_data_command | (TM1638_data_command_mask & command)
  ));
}

void TM1638Driver::writeDataFixedAddress(uint8_t address, uint8_t data) {
  select();
  writeData(trace(
    "writeDataFixedAddress address",
    TM1638_address_command | (TM1638_address_command_mask & address)
  ));
  writeData(trace(
    "writeDataFixedAddress data",
    data
  ));
  deselect();
}

void TM1638Driver::setDisplayControl(bool enabled, uint8_t level) {
  if (enabled) {
    sendData(trace(
      "setDisplayControl on",
      TM1638_display_command | TM1638_display_command_on | (TM1638_display_command_mask & level)
    ));
  } else {
    sendData(trace(
      "setDisplayControl off",
      TM1638_display_command
    ));
  }
}

void TM1638Driver::clearAll() {
  setDataCommand(
    TM1638_data_command_write |
    TM1638_data_command_incr_address |
    TM1638_data_command_normal
  );
  select();
  writeData(trace("clear from address", TM1638_address_command));
  for(int i=0; i< 16; ++i) {
    writeData(0);
  }
  deselect();
  setDisplayControl(false, 0);
}

void TM1638Driver::displayNumber(uint16_t counter) {
  setDataCommand(
    TM1638_data_command_write |
    TM1638_data_command_fixed_address |
    TM1638_data_command_normal
  );
  writeDataFixedAddress(0, NUMBERS[counter % 10]);
  writeDataFixedAddress(2, NUMBERS[(counter / 10) % 10]);
  setDisplayControl(true, 0b11);
}

void TM1638Driver::readKeys(uint8_t k[]) {
  select();
  writeData(TM1638_data_command | TM1638_data_command_read | TM1638_data_command_normal);


  setDataInbound();
  for (int i=0; i<4; ++i) {
    k[i] = trace(
      "read", readData()
    );
  }
  setDataOutbound();
  deselect();
}
