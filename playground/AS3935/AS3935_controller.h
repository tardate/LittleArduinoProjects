#pragma once

#include <Arduino.h>
#include <Wire.h>

class AS3935Controller {
  public:
    AS3935Controller(int address, int interrupt_pin);

    /*
     * Command: initialise the device
     */
    void begin();

    /*
     * Command: reset the device
     */
    void reset();

    /*
     * Command: read all registers to internal cache
     */
    void readAllRegisters();

    /*
     * Return: register accessors
     */
    uint8_t getGainBoost();
    uint8_t getPowerDown();
    uint8_t getNoiseFloor();
    uint8_t getWatchdogThreshold();
    uint8_t getMinimumLightningStrikes();
    uint8_t getSpikeRejection();
    uint8_t getFrequencyDivisionRatio();
    uint8_t getMaskDisturber();
    uint8_t getDisplayLCO();
    uint8_t getDisplaySRCO();
    uint8_t getDisplayTRCO();
    uint8_t getTuningCap();

    uint8_t getStrikeType();
    uint8_t getStrikeDistance();
    uint32_t getStrikeEnergy();

    bool isLightningInterrupt();

    uint8_t getRegister(int address);

  private:
    int address;
    int interrupt_pin;
    int register_data[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    /*
     * Command: write a single byte to the specified register
     * followed by stop condition
     */
    void writeRegister(uint8_t reg, uint8_t data);

    /*
     * Command: read a single byte from the specified register on the device
     */
    uint8_t readRegister(uint8_t reg);

};
