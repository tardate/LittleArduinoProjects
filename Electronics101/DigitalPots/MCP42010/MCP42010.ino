/*

  DigitalPots/MCP42010
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/DigitalPots/MCP42010

 */

#include <SPI.h>

SPISettings digipotSettings(2000000, MSBFIRST, SPI_MODE0);

// Standard hardware SPI pins are used used for clock and data, but slave select can be any free pin
#define DIGIPOT_SS_PIN (9)

#define CMD_WRITE (0b00010000)
#define CMD_P0    (0b01)
#define CMD_P1    (0b10)
#define POT_LIMIT (0xFF)


void setup() {
  SPI.begin();
  pinMode(DIGIPOT_SS_PIN, OUTPUT);
}

void loop() {
  int data;
  for(data = 0; data <= POT_LIMIT; data++) {
    setPot(CMD_WRITE | CMD_P0, data);
    setPot(CMD_WRITE | CMD_P1, POT_LIMIT - data);
  }
  for(data = POT_LIMIT; data > 0; --data) {
    setPot(CMD_WRITE | CMD_P0, data);
    setPot(CMD_WRITE | CMD_P1, POT_LIMIT - data);
  }
}

// Command: send +command+ and +data+ bytes to the pot
void setPot(byte command, byte data) {
  SPI.beginTransaction(digipotSettings);
  digitalWrite(DIGIPOT_SS_PIN, LOW);
  SPI.transfer(command);
  SPI.transfer(data);
  digitalWrite(DIGIPOT_SS_PIN, HIGH);
  SPI.endTransaction();
}
