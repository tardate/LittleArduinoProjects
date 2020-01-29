#include "ina226_driver.h"


void Ina226Driver::begin(uint8_t address) {
  Wire.begin();
  this->address = address;
}


void Ina226Driver::calibrate(float shunt_resistance, float max_current) {
  this->shunt_resistance = shunt_resistance;

  float minimum_lsb = max_current / 32768;
  current_LSB = ceil(minimum_lsb * 10000000000) / 10000000000;
  power_LSB = current_LSB * 25;
  calibration_value = (uint16_t)((512) / (current_LSB * 100000 * shunt_resistance));

  #ifdef HAVE_HWSERIAL0
    Serial.print("Manufacturer ID : "); Serial.println(readRegister16(InaRegister::ManID), HEX);
    Serial.print("Die ID          : "); Serial.println(readRegister16(InaRegister::DieID), HEX);
    Serial.print("Calibrating for shunt resistance of ");
      Serial.print(shunt_resistance, 3);
      Serial.print("Ω and maximum current of ");
      Serial.print(max_current, 3);
      Serial.println("A");
    Serial.print("  * current_LSB : "); Serial.print(current_LSB * 1000.0, 6); Serial.println("mA");
    Serial.print("  * power_LSB   : "); Serial.print(power_LSB * 1000.0, 6); Serial.println("mW");
    Serial.print("  * CAL         : "); Serial.println(calibration_value);
  #endif

  writeRegister16(InaRegister::Calibration, calibration_value);
}


float Ina226Driver::readBusVoltage(void) {
  int16_t voltage = readRegister16(InaRegister::BusVoltage);
  return (voltage * 0.00125);
}


float Ina226Driver::readShuntVoltage(void) {
  float voltage = readRegister16(InaRegister::ShuntVoltage);
  return (voltage * 0.0025);
}


float Ina226Driver::readCurrent(void) {
  return (readRegister16(InaRegister::Current) * current_LSB);

}


float Ina226Driver::readPower(void) {
  return (readRegister16(InaRegister::Power) * power_LSB);
}


int16_t Ina226Driver::readRegister16(InaRegister reg) {
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.requestFrom(address, (uint8_t)2);
  uint8_t hi = Wire.read();
  uint8_t lo = Wire.read();

  return hi << 8 | lo;
}


void Ina226Driver::writeRegister16(InaRegister reg, uint16_t value) {
  uint8_t lo = (uint8_t)value;
  uint8_t hi = value >>= 8;

  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(hi);
  Wire.write(lo);
  Wire.endTransmission();
}
