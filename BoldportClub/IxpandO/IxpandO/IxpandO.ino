/*

  IxpandO
  Demo with LEDs connected to bank B (GPB) and DIP switches connected to bank A (GPA)

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub/IxpandO

 */

#include <Wire.h>

const uint8_t DEVICE_ADDRESS = 0x20;
const uint8_t DEVICE_INTA_PIN = 2;

const uint8_t IOCON     = 0x0A;

const uint8_t IODIRA    = 0x00;
const uint8_t IODIRB    = 0x01;
const uint8_t IPOLA     = 0x02;
const uint8_t IPOLB     = 0x03;
const uint8_t GPINTENA  = 0x04;
const uint8_t GPINTENB  = 0x05;
const uint8_t DEFVALA   = 0x06;
const uint8_t DEFVALB   = 0x07;
const uint8_t INTCONA   = 0x08;
const uint8_t INTCONB   = 0x09;

const uint8_t GPPUA     = 0x0C;
const uint8_t GPPUB     = 0x0D;
const uint8_t INTFA     = 0x0E;
const uint8_t INTFB     = 0x0F;
const uint8_t INTCAPA   = 0x10;
const uint8_t INTCAPB   = 0x11;
const uint8_t GPIOA     = 0x12;
const uint8_t GPIOB     = 0x13;
const uint8_t OLATA     = 0x14;
const uint8_t OLATB     = 0x15;

volatile boolean inta_flag = true;

void setup() {
  Wire.begin();
  initIxpandO();
  enableIntA();
}

void loop() {
  static uint8_t switch_state = 0;

  if (inta_flag) {
    inta_flag = false;
    switch_state = readRegister(GPIOA);
  }

  switch (switch_state) {
  case 0:
    demoPingPong();
    break;
  default:
    writeRegister(GPIOB, switch_state);
  }
}

/*
 * Command: run 1 cycle of demo pattern
 */
void demoPingPong() {
  for(int i=0; i<8; ++i) {
    writeRegister(GPIOB, 1 << i);
    delay(20);
  }
  for(int i=6; i>0; --i) {
    writeRegister(GPIOB, 1 << i);
    delay(20);
  }
}

/*
 * Command: initialise IxpandO for default LED + switch config
 */
void initIxpandO() {
  writeRegister(IOCON,  0x0);    // default config: seauential addressing, separate INT
  writeRegister(IODIRA, 0xFF);   // set all GPA to input
  writeRegister(IODIRB, 0x0);    // set all GPB to output
  writeRegister(IPOLA, 0x0);     // GPA register bit will reflect the same logic state of the input pin.
  writeRegister(IPOLB, 0x0);     // GPB register bit will reflect the same logic state of the input pin.
  writeRegister(GPPUA, 0xFF);    // enable pull-ups for GPA
  writeRegister(GPPUB, 0x0);     // disable pull-ups for GPB

  writeRegister(INTCONA, 0xFF);  // compare GPA to DEFVAL
  writeRegister(DEFVALA, 0xFF);  // set GPA default compare value to 1 (normally pulled high)
  writeRegister(GPINTENA, 0xFF); // set GPA interrupt on change
}

/*
 * Command: write a single byte to the specified register
 * followed by stop condition
 */
void writeRegister(uint8_t reg, uint8_t data) {
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission(true);
}

/*
 * Command: read a single byte from the specified register
 */
uint8_t readRegister(uint8_t reg) {
  Wire.requestFrom(DEVICE_ADDRESS, 1, reg, 1, true);
  return Wire.read();
}

/*
 * Command: enable hardware interrupt from MCP23017 INTA
 */
void enableIntA() {
  pinMode(DEVICE_INTA_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(DEVICE_INTA_PIN), handleIntA, CHANGE);
}

/*
 * Command: INTA interrupt handler
 */
void handleIntA() {
  inta_flag = true;
}
