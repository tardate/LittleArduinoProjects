/*

  EEPROM/AT28C16/PEProgrammer
  Programming an AT28C16 EEPROM with an Arduino and MCP23S17 16-bit port expander.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/EEPROM/AT28C16/PEProgrammer

 */

#include "eeprom_controller.h"

EepromController controller;

/*
 * Command: setup SPI, ports and interrupts.
 */
void setup() {
  Serial.begin(115200);
  controller.begin();
  printBanner();
}

/*
 * Command: main loop
 */
void loop() {

  char cmd;
  int p1;
  int p2;
  int p3;

  if((cmd = Serial.read()) >= '!') {
    switch(cmd) {
    case 'r':
      p1 = Serial.parseInt();
      p2 = Serial.parseInt();
      echoParams(cmd, p1, p2);
      if(p2 < p1) p2 = p1;
      readRange(p1, p2);
      break;
    case 'w':
      p1 = Serial.parseInt();
      p2 = Serial.parseInt();
      echoParams(cmd, p1, p2);
      writeRange(p1, p2);
      readRange(p2, p2);
      break;
    case 'f':
      p1 = Serial.parseInt();
      p2 = Serial.parseInt();
      p3 = Serial.parseInt();
      echoParams(cmd, p1, p2, p3);
      writeRange(p1, p2, p3);
      readRange(p2, p3);
      break;
    default:
      Serial.print(F("Unrecognised command: "));
      Serial.println(cmd);
    }
    while (Serial.available() > 0) Serial.read();
    printBanner();
  }

}

void printBanner() {
  Serial.println(F("\n# Commands:"));
  Serial.println(F("#    r X Y : read and echo data from start (X) to end (Y) address inclusive"));
  Serial.println(F("#    w V X : write value (V) to address (X)"));
  Serial.println(F("#    f V X Y : fill value (V) from  start addresses (X) to end address (Y)"));
  Serial.println(F("# Note: enter all values in decimal"));
  Serial.print(F("> "));
}

void echoParams(char cmd, int p1, int p2) {
  char buffer[20];
  sprintf(buffer, "%c %u %u", cmd, p1, p2);
  Serial.println(buffer);
}

void echoParams(char cmd, int p1, int p2, int p3) {
  char buffer[20];
  sprintf(buffer, "%c %u %u %u", cmd, p1, p2, p3);
  Serial.println(buffer);
}

void readRange(uint16_t start_address, uint16_t end_address) {
  for(uint16_t address=start_address; address <= end_address; ++address) {
    uint8_t data = controller.read(address);
    char buffer[80];
    sprintf(buffer, "0x%03x %04u:  %02x %03u", address, address, data, data);
    Serial.println(buffer);
  }
}

void writeRange(uint8_t data, uint16_t start_address, uint16_t end_address) {
  for(uint16_t address=start_address; address <= end_address; ++address) controller.write(data, address);
}

void writeRange(uint8_t data, uint16_t address) {
  writeRange(data, address, address);
}
