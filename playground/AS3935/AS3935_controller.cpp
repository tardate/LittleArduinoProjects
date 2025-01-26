#include "AS3935_controller.h"

AS3935Controller::AS3935Controller(int address, int interrupt_pin) {
  this->address = address;
  this->interrupt_pin = interrupt_pin;
}

void AS3935Controller::begin() {
  Wire.begin();
  reset();
}

void AS3935Controller::reset() {
  writeRegister(0x3c, 0x96);
  delay(2);
}

uint8_t AS3935Controller::getGainBoost() {
  return (register_data[0] & 0b111110) >> 1;
}

uint8_t AS3935Controller::getPowerDown() {
  return register_data[0] & 0b01;
}

uint8_t AS3935Controller::getNoiseFloor() {
  return (register_data[1] & 0b1110000) >> 4;
}

uint8_t AS3935Controller::getWatchdogThreshold() {
  return register_data[1] & 0b1111;
}

uint8_t AS3935Controller::getMinimumLightningStrikes() {
  return (register_data[2] & 0b110000) >> 4;
}

uint8_t AS3935Controller::getSpikeRejection() {
  return register_data[2] & 0b1111;
}

uint8_t AS3935Controller::getFrequencyDivisionRatio() {
  return (register_data[3] & 0b11000000) >> 6;
}

uint8_t AS3935Controller::getMaskDisturber() {
  return (register_data[3] & 0b100000) >> 5;
}

uint8_t AS3935Controller::getDisplayLCO() {
  return (register_data[8] & 0b10000000) >> 7;
}

uint8_t AS3935Controller::getDisplaySRCO() {
  return (register_data[8] & 0b1000000) >> 6;
}

uint8_t AS3935Controller::getDisplayTRCO() {
  return (register_data[8] & 0b100000) >> 5;
}

uint8_t AS3935Controller::getTuningCap() {
  return register_data[8] & 0b1111;
}

uint8_t AS3935Controller::getStrikeType() {
  return register_data[3] & 0b1111;
}

uint8_t AS3935Controller::getStrikeDistance() {
  return register_data[7] & 0b111111;
}

uint32_t AS3935Controller::getStrikeEnergy() {
  uint32_t energy = (register_data[6] & 0b11111) << 16;
  energy = energy | (register_data[5] << 8);
  energy = energy | register_data[4];
  return energy;
}

bool AS3935Controller::isLightningInterrupt() {
  return getStrikeType() == 0b1000;
}


void AS3935Controller::writeRegister(uint8_t reg, uint8_t data) {
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission(true);
}

uint8_t AS3935Controller::readRegister(uint8_t reg) {
  Wire.requestFrom(address, 1, reg, 1, true);
  return Wire.read();
}

void AS3935Controller::readAllRegisters() {
  Wire.requestFrom(address, 9);
  for(uint8_t reg=0; reg<9; ++reg) {
    this->register_data[reg] = Wire.read();
    // this->register_data[reg] = readRegister(reg);
  }
  this->register_data[9] = readRegister(0x3A);
  this->register_data[10] = readRegister(0x3B);
}

uint8_t AS3935Controller::getRegister(int address) {
  uint8_t result;
  switch (address) {
  case 0x3A:
    result = register_data[9];
    break;
  case 0x3B:
    result = register_data[10];
    break;
  default:
    result = register_data[address];
  }
  return result;
}
