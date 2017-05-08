// #include <Arduino.h>
#include "eeprom_controller.h"

/*
 * private defines for default config
 */
#define  DEFAULT_FIRST_DATA_PIN (2)
#define  DEFAULT_SS_PIN         (10)
#define  DEFAULT_PE_ADDRESS     (0)


#define  IOCON     (0x0A)
#define  IODIRA    (0x00)
#define  IODIRB    (0x01)
#define  GPIOA     (0x12)
#define  GPIOB     (0x13)

#define  WE_BIT (3)
#define  OE_BIT (4)
#define  CE_BIT (5)



EepromController::EepromController() {
  this->current_mode = ReadMode;
  this->first_data_pin = DEFAULT_FIRST_DATA_PIN;
  this->pe_ss_pin = DEFAULT_SS_PIN;
  this->pe_address = DEFAULT_PE_ADDRESS;
  this->pe_control_byte = 0b1000000 | (pe_address << 1);
  this->spi_settings = new SPISettings(16000000, MSBFIRST, SPI_MODE0);
  this->GPIOA_value = 0;
  this->GPIOB_value = 0;
}


void EepromController::begin() {
  pinMode(pe_ss_pin, OUTPUT);
  digitalWrite(pe_ss_pin, HIGH);

  SPI.begin();
  SPI.beginTransaction(*spi_settings);

  setPeRegister(IOCON,  0b00001000); // enable hardware address pins; bank=0 addressing
  setPeRegister(IODIRA, 0b00000000); // set GPA output ports
  setPeRegister(IODIRB, 0b11000000); // set GPB output ports except GPB6,GPB7 (unused)

}


void EepromController::setReadMode() {
  this->current_mode = ReadMode;
  this->GPIOA_value = 0; // clear A0-7
  this->GPIOB_value = _BV(WE_BIT); // set WE; clear CE/OE and A8-10
  setPeGpio();

  for(int pindex=0; pindex < 8; ++pindex) {
    pinMode(first_data_pin + pindex, INPUT);
  }

}


void EepromController::setWriteMode() {
  this->current_mode = WriteMode;
  this->GPIOA_value = 0;                         // clear A0-7
  this->GPIOB_value = _BV(WE_BIT) | _BV(OE_BIT); // set WE/OE; clear CE and A8-10
  setPeGpio();

  for(int pindex=0; pindex < 8; ++pindex) {
    pinMode(first_data_pin + pindex, OUTPUT);
  }
}


uint8_t EepromController::read(uint16_t address) {
  if(current_mode==WriteMode) setReadMode();
  this->GPIOA_value = (uint8_t)address; // low byte
  this->GPIOB_value |= ((address >> 8) & 0b00000111); // 3 bits of high byte
  setPeGpio();
  uint8_t input = 0;
  for(int pindex=0; pindex < 8; ++pindex) {
    input |= digitalRead(first_data_pin + pindex) << pindex;
  }
  return input;
}

void EepromController::write(uint8_t data, uint16_t address) {
  if(current_mode==ReadMode) setWriteMode();
  this->GPIOA_value = (uint8_t)address;               // low address byte A0-7
  this->GPIOB_value |= ((address >> 8) & 0b00000111); // 3 bits of high address byte A8-10
  setPeGpio();

  for(int pindex=0; pindex < 8; ++pindex) {
    digitalWrite(first_data_pin + pindex, (data >> pindex) & 1);
  }
  setPeRegister(GPIOB, GPIOB_value & ~(_BV(WE_BIT))); // clear WE - latches address
  delayMicroseconds(1);
  setPeRegister(GPIOB, GPIOB_value);                  // set WE - latches data
  delay(1); // byte write time is 200 μs maximum but wait a 1ms to be sure
}


void EepromController::setPeGpio() {
  // with IOCON.BANK = 0, GPIOA address is immediately followed by GPIOB
  setPeRegister(GPIOA, GPIOA_value, GPIOB_value);
}


void EepromController::setPeRegister(uint8_t reg, uint8_t data) {
  digitalWrite(pe_ss_pin, LOW);
  SPI.transfer(pe_control_byte);
  SPI.transfer(reg);
  SPI.transfer(data);
  digitalWrite(pe_ss_pin, HIGH);
}


void EepromController::setPeRegister(uint8_t reg, uint8_t first, uint8_t last) {
  digitalWrite(pe_ss_pin, LOW);
  SPI.transfer16((uint16_t)pe_control_byte << 8 | reg);
  SPI.transfer16((uint16_t)first << 8 | last);
  digitalWrite(pe_ss_pin, HIGH);
}
