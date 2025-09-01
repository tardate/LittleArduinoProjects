/*

  DigitalPots/MCP4017
  Demonstrate control of an MCP4017 digital potentiometer.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/DigitalPots/MCP4017

 */

#include <Wire.h>
const byte ADDRESS = 0b0101111;
const byte FULL_SCALE = 0x7F;

void setup() {
  Wire.begin();
}

void loop() {
  static byte value = 0;

  setPot(value);
  delayMicroseconds(2);

  value++;
  if (value > FULL_SCALE) value = 0;
}

void setPot(byte value) {
  Wire.beginTransmission(ADDRESS);
  Wire.write(value);  // yes, it is that simple - no command code required
  Wire.endTransmission();
}
