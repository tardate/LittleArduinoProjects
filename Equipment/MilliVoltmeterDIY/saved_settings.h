#ifndef SAVED_SETTINGS_h
#define SAVED_SETTINGS_h

#include <Arduino.h>


class SavedSettings {
  public:
    SavedSettings(void);

    // Returns: current calibration setting
    int32_t get_calibration_factor(void);

    // Command: set the current calibration setting and save to EEPROM
    void set_calibration_factor(int32_t);

  private:
    int calibration_factor_address;
    int32_t calibration_factor;
    bool calibration_factor_cached;

    // Command: writes (32 bit) long value to EEPROM address
    void writelong(int address, long value);

    // Returns: (32 bit) long value from EEPROM address
    long readlong(long address);
};


#endif
