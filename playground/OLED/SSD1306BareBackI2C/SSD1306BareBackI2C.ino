/*

  OLED/SSD1306BareBackI2C
  Test driving a monochrome 128x32 OLED Display with an Arduino and the raw command set over I²C

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/OLED/SSD1306BareBackI2C

 */

#include <Wire.h>

const byte DEVICE_ADDRESS               = 0b00111100;
const byte SSD1306_I2C_CMD              = 0b00000000;
const byte SSD1306_I2C_DATA             = 0b01000000;

//** dimensional settings

#define SSD1306_PIXEL_WIDTH             128
#define SSD1306_PIXEL_HEIGHT            32
#define SSD1306_PAGE_HEIGHT             8
#define SSD1306_PAGE_COUNT              SSD1306_PIXEL_HEIGHT / SSD1306_PAGE_HEIGHT
#define SSD1306_SEGMENT_COUNT           SSD1306_PIXEL_WIDTH * SSD1306_PAGE_COUNT

//** a simple font for testing
#include "font.h"
#define SSD1306_FONT_WIDTH              5
#define SSD1306_FONT_ROWS               SSD1306_PAGE_COUNT

//** fundamental commands

#define SSD1306_SET_CONTRAST            0b10000001 // 0x81
#define SSD1306_CONTRAST_DEFAULT        0b01111111

#define SSD1306_DISPLAY                 0b10100100
#define SSD1306_DISPLAY_RESET           SSD1306_DISPLAY
#define SSD1306_DISPLAY_ALLON           SSD1306_DISPLAY | 0b01
#define SSD1306_DISPLAY_NORMAL          SSD1306_DISPLAY | 0b10
#define SSD1306_DISPLAY_INVERSE         SSD1306_DISPLAY | 0b11
#define SSD1306_DISPLAY_SLEEP           SSD1306_DISPLAY | 0b1110
#define SSD1306_DISPLAY_ON              SSD1306_DISPLAY | 0b1111

//** addressing

#define SSD1306_ADDRESSING              0b00100000 // 0x20
#define SSD1306_ADDRESSING_HORIZONTAL   0b00
#define SSD1306_ADDRESSING_VERTICAL     0b01
#define SSD1306_ADDRESSING_PAGE         0b10

#define SSD1306_SET_COLUMN              0b00100001 // 0x21

#define SSD1306_SET_PAGE                0b00100010 // 0x22

//** hardware configuration

#define SSD1306_SET_START_LINE          0b01000000 // 0x40
#define SSD1306_START_LINE_DEFAULT      0b00000000

#define SSD1306_SET_SEG_SCAN            0b10100000 // 0xA0
#define SSD1306_SET_SEG_SCAN_DEFAULT    SSD1306_SET_SEG_SCAN | 0b00
#define SSD1306_SET_SEG_SCAN_REVERSE    SSD1306_SET_SEG_SCAN | 0b01

#define SSD1306_SET_MULTIPLEX_RATIO     0b10101000 // 0xA8
#define SSD1306_MULTIPLEX_RATIO_DEFAULT 0b00111111
#define SSD1306_MULTIPLEX_RATIO_31      0b00011111

#define SSD1306_SET_COM_SCAN            0b11000000 // 0xC0
#define SSD1306_SET_COM_SCAN_DEFAULT    SSD1306_SET_COM_SCAN | 0b0000
#define SSD1306_SET_COM_SCAN_REVERSE    SSD1306_SET_COM_SCAN | 0b1000

#define SSD1306_SET_DISPLAY_OFFSET      0b11010011 // 0xD3
#define SSD1306_DISPLAY_OFFSET_DEFAULT  0b00000000

#define SSD1306_SET_COM_PINS            0b11011010 // 0xDA
#define SSD1306_COM_PINS_DEFAULT        0b00010010
#define SSD1306_COM_PINS_SEQUENTIAL     0b00000010

//** timing and driving

#define SSD1306_SET_CLOCK_FREQUENCY     0b11010101 // 0xD5
#define SSD1306_CLOCK_FREQUENCY_DEFAULT 0b10000000

#define SSD1306_SET_PRECHARGE           0b11011001 // 0xD9
#define SSD1306_PRECHARGE_DEFAULT       0b00100010

#define SSD1306_SET_VCOMH_DESELECT      0b11011011 // 0xDB
#define SSD1306_VCOMH_DESELECT_DEFAULT  0b00100000

#define SSD1306_SET_CHARGE_PUMP         0b10001101 // 0x8D
#define SSD1306_CHARGE_PUMP_ENABLE      0b00010100


void writeRegister(uint8_t reg, uint8_t data) {
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission(true);
}

void OledWriteCmd(byte cmd) {
  writeRegister(SSD1306_I2C_CMD, cmd);
}

void OledWriteData(byte cmd) {
  writeRegister(SSD1306_I2C_DATA, cmd);
}

void OledClear() {
  OledXY(0, 0);
  for(int i = 0; i < SSD1306_SEGMENT_COUNT; ++i) {
    OledWriteData(0x00);
  }
  OledXY(0, 0);
}

void OledXY(int x, int y) {
  OledWriteCmd(SSD1306_SET_COLUMN);
  OledWriteCmd(x * SSD1306_FONT_WIDTH);
  OledWriteCmd(SSD1306_PIXEL_WIDTH - 1);
  OledWriteCmd(SSD1306_SET_PAGE);
  OledWriteCmd(y);
  OledWriteCmd(SSD1306_PAGE_COUNT - 1);
}

void OledWriteCharacter(char character) {
  for(int i=0; i<5; ++i) {
    OledWriteData(ASCII[character - 0x20][i]);
  }
  OledWriteData(0x00);
}

void OledWriteString(char *characters) {
  while(*characters) {
    OledWriteCharacter(*characters++);
  }
}

void setup() {
  Wire.begin();
  OledWriteCmd(SSD1306_DISPLAY_SLEEP);
  OledWriteCmd(SSD1306_ADDRESSING);
  OledWriteCmd(SSD1306_ADDRESSING_HORIZONTAL);
  // setting seg and com scan reverse means our x,y origin is top left of the screen
  OledWriteCmd(SSD1306_SET_COM_SCAN_REVERSE);
  OledWriteCmd(SSD1306_SET_SEG_SCAN_REVERSE);
  OledWriteCmd(SSD1306_SET_MULTIPLEX_RATIO);
  OledWriteCmd(SSD1306_MULTIPLEX_RATIO_31);
  OledWriteCmd(SSD1306_SET_COM_PINS);
  OledWriteCmd(SSD1306_COM_PINS_SEQUENTIAL);
  OledWriteCmd(SSD1306_SET_CHARGE_PUMP);
  OledWriteCmd(SSD1306_CHARGE_PUMP_ENABLE);
  OledWriteCmd(SSD1306_DISPLAY_NORMAL);
  OledWriteCmd(SSD1306_DISPLAY_ON);
}

void loop() {
  demoHatching();
  demoPositionedText();
  demoInversedText();
}

void demoHatching() {
  OledClear();
  delay(400);
  for(int i = 0; i < SSD1306_SEGMENT_COUNT / 2; i++) {
    OledWriteData(0xAA);
    OledWriteData(0x55);
  }
  delay(600);
}

void demoPositionedText() {
  OledClear();
  for(int i = 0; i < SSD1306_FONT_ROWS; ++i) {
    OledXY(i, i);
    OledWriteString("Demo!");
  }
  delay(1000);
}

void demoInversedText() {
  OledClear();
  OledWriteCmd(SSD1306_DISPLAY_INVERSE);
  demoPositionedText();
  OledWriteCmd(SSD1306_DISPLAY_NORMAL);
}
