#include "saved_settings.h"
#include <EEPROM.h>

SavedSettings::SavedSettings(void) {
  this->calibration_factor_address = 0;
  this->calibration_factor = 0;
  this->calibration_factor_cached = false;
}


int32_t SavedSettings::get_calibration_factor(void) {
  if(!calibration_factor_cached) {
    calibration_factor = readlong(calibration_factor_address);
    calibration_factor_cached = true;
  }
  return calibration_factor;
}


void SavedSettings::set_calibration_factor(int32_t calibration_factor) {
  this->calibration_factor = calibration_factor;
  writelong(calibration_factor_address, calibration_factor);
}


// Command: writes (32 bit) long value to EEPROM address
void SavedSettings::writelong(int address, long value) {
  byte four = (value & 0xFF);
  byte three = ((value>>8) & 0xFF);
  byte two = ((value>>16) & 0xFF);
  byte one = ((value>>24) & 0xFF);

  EEPROM.write(address, four);
  EEPROM.write(address +1, three);
  EEPROM.write(address +2, two);
  EEPROM.write(address +3, one);
}


// Returns: (32 bit) long value from EEPROM address
long SavedSettings::readlong(long address) {
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);
  return (four)+(three << 8)+(two << 16)+(one << 24);
}


