#pragma once

#include <Arduino.h>
#include <SPI.h>


/// @brief The movie end frame
///
class EepromController {
public:

  /// @brief The movie end frame
  ///
  enum Mode : uint8_t {
    ReadMode,
    WriteMode
  };

  EepromController();

  /// @brief Command: initialise resources (SPI, ports)
  ///
  void begin();

  /// @brief Returns the data at the specified address in the EEPROM.
  /// Will set read mode if required.
  ///
  uint8_t read(uint16_t address);

  /// @brief Command: write the data to the specified address in the EEPROM.
  /// Will set write mode if required.
  ///
  void write(uint8_t data, uint16_t address);

  /// @brief Command: setup the port expander and data ports for read.
  /// This will reset the address
  ///
  void setReadMode();

  /// @brief Command: setup the port expander and data ports for write.
  /// This will reset the address
  ///
  void setWriteMode();

private:

  SPISettings* spi_settings;

  Mode current_mode;

  int first_data_pin;      // expect I/O connected to 8 GPIO pins starting from this one (default: 2)
  int pe_ss_pin;           // slave-select pin for the port expander (default: 10)
  uint8_t pe_address;      // address of the port expander (default: 0)
  uint8_t pe_control_byte; // precalculated slave control byte

  uint8_t GPIOA_value;
  uint8_t GPIOB_value;

  /// @brief Command: writes the GPIO A and B registers to the port expander
  ///
  void setPeGpio();

  /// @brief Command: write a single byte to the specified port expander register
  ///
  void setPeRegister(uint8_t reg, uint8_t data);

  /// @brief Command: write two bytes to specified register
  /// Uses sequential write and transfer16 alternate SPI method.
  ///
  void setPeRegister(uint8_t reg, uint8_t first, uint8_t last);


};