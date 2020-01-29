#pragma once

#include <Arduino.h>

#if defined(__AVR_ATtiny85__)
  #include <TinyWireM.h>
  #define Wire TinyWireM
#else
  #include <Wire.h>
#endif

enum InaRegister : uint8_t {
  Configuration    = 0x00,
  ShuntVoltage     = 0x01,
  BusVoltage       = 0x02,
  Power            = 0x03,
  Current          = 0x04,
  Calibration      = 0x05,
  MaskEnable       = 0x06,
  AlertLimit       = 0x07,
  ManID            = 0xFE,
  DieID            = 0xFF
};


/**
 * A simplified INA226 interface using the Wire library
 */
class Ina226Driver {
  public:

    /**
     * Command: init for specified I²C address
     */
    void begin(uint8_t address);

    /**
     * Command: set calibration for particular shunt and current combination
     */
    void calibrate(float shunt_resistance, float max_current);

    /**
     * Returns: the latest bus voltage (in volts)
     */
    float readBusVoltage(void);
    /**
     * Returns: the latest shunt voltage (in millivolts)
     */
    float readShuntVoltage(void);

    /**
     * Returns: the latest bus/shunt current (in amps)
     */
    float readCurrent(void);

    /**
     * Returns: the latest bus power (in watts)
     */
    float readPower(void);

  private:
    uint8_t address;

    float shunt_resistance;
    uint16_t calibration_value;

    float current_LSB;
    float power_LSB;

    int16_t readRegister16(InaRegister reg);
    void writeRegister16(InaRegister reg, uint16_t value);
};
