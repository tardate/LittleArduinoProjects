#include "oled_driver.h"


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

#define SSD1306_SET_COM_SCAN            0b11000000 // 0xC0
#define SSD1306_SET_COM_SCAN_DEFAULT    SSD1306_SET_COM_SCAN | 0b0000
#define SSD1306_SET_COM_SCAN_REVERSE    SSD1306_SET_COM_SCAN | 0b1000

#define SSD1306_SET_DISPLAY_OFFSET      0b11010011 // 0xD3
#define SSD1306_DISPLAY_OFFSET_DEFAULT  0b00000000

#define SSD1306_SET_COM_PINS            0b11011010 // 0xDA
#define SSD1306_COM_PINS_DEFAULT        0b00010010

//** timing and driving

#define SSD1306_SET_CLOCK_FREQUENCY     0b11010101 // 0xD5
#define SSD1306_CLOCK_FREQUENCY_DEFAULT 0b10000000

#define SSD1306_SET_PRECHARGE           0b11011001 // 0xD9
#define SSD1306_PRECHARGE_DEFAULT       0b00100010

#define SSD1306_SET_VCOMH_DESELECT      0b11011011 // 0xDB
#define SSD1306_VCOMH_DESELECT_DEFAULT  0b00100000

#define SSD1306_SET_CHARGE_PUMP         0b10001101 // 0x8D
#define SSD1306_CHARGE_PUMP_ENABLE      0b00010100


/*
 *   constructor
 */

OledDriver::OledDriver(int mosi_pin, int clk_pin, int dc_pin, int cs_pin) {
  this->mosi_pin = mosi_pin;
  this->clk_pin = clk_pin;
  this->dc_pin = dc_pin;
  this->cs_pin = cs_pin;

  #ifdef USE_OPTIMISED_SPI
  cs_port      = portOutputRegister(digitalPinToPort(cs_pin));
  cs_pinmask   = digitalPinToBitMask(cs_pin);
  dc_port      = portOutputRegister(digitalPinToPort(dc_pin));
  dc_pinmask   = digitalPinToBitMask(dc_pin);
  clk_port     = portOutputRegister(digitalPinToPort(clk_pin));
  clk_pinmask  = digitalPinToBitMask(clk_pin);
  mosi_port    = portOutputRegister(digitalPinToPort(mosi_pin));
  mosi_pinmask = digitalPinToBitMask(mosi_pin);
  #endif
}

void OledDriver::init() {
  pinMode(mosi_pin, OUTPUT);
  pinMode(clk_pin, OUTPUT);
  pinMode(dc_pin, OUTPUT);
  pinMode(cs_pin, OUTPUT);
  setDcStatus(LOW);

  writeCommand(SSD1306_DISPLAY_SLEEP);

  writeCommand(SSD1306_SET_CLOCK_FREQUENCY, SSD1306_CLOCK_FREQUENCY_DEFAULT);

  writeCommand(SSD1306_SET_MULTIPLEX_RATIO, SSD1306_MULTIPLEX_RATIO_DEFAULT);

  writeCommand(SSD1306_SET_DISPLAY_OFFSET, SSD1306_DISPLAY_OFFSET_DEFAULT);

  writeCommand(SSD1306_SET_START_LINE | SSD1306_START_LINE_DEFAULT);

  writeCommand(SSD1306_ADDRESSING, SSD1306_ADDRESSING_HORIZONTAL);

  // setting seg and com scan reverse means our x,y origin is top left of the screen
  writeCommand(SSD1306_SET_SEG_SCAN_REVERSE);
  writeCommand(SSD1306_SET_COM_SCAN_REVERSE);

  writeCommand(SSD1306_SET_COM_PINS, SSD1306_COM_PINS_DEFAULT);

  writeCommand(SSD1306_SET_CONTRAST, SSD1306_CONTRAST_DEFAULT);

  writeCommand(SSD1306_SET_PRECHARGE, SSD1306_PRECHARGE_DEFAULT);

  writeCommand(SSD1306_SET_VCOMH_DESELECT, SSD1306_VCOMH_DESELECT_DEFAULT);

  writeCommand(SSD1306_DISPLAY_RESET);

  writeCommand(SSD1306_SET_CHARGE_PUMP, SSD1306_CHARGE_PUMP_ENABLE);
  writeCommand(SSD1306_DISPLAY_NORMAL);
  writeCommand(SSD1306_DISPLAY_ON);
}

int OledDriver::segmentCount() {
  return SSD1306_SEGMENT_COUNT;
}

//inline
void OledDriver::setDcStatus(byte state) {
  if(dc_status==state) return;
  dc_status=state;

  #ifdef USE_OPTIMISED_SPI
  if(dc_status) *dc_port |= dc_pinmask;
  else *dc_port &= ~dc_pinmask;
  #else
  digitalWrite(dc_pin, dc_status);
  #endif
}

#ifdef USE_OPTIMISED_SPI
inline void OledDriver::spiShiftOut(byte data) {
  for(byte bit = 0x80; bit; bit >>= 1) {
    *clk_port &= ~clk_pinmask;
    if(data & bit) *mosi_port |=  mosi_pinmask;
    else *mosi_port &= ~mosi_pinmask;
    *clk_port |=  clk_pinmask;
  }
}
#endif

void OledDriver::spiSend(byte data) {
  #ifdef USE_OPTIMISED_SPI
  *cs_port &= ~cs_pinmask;
  spiShiftOut(data);
  *cs_port |= cs_pinmask;
  #else
  digitalWrite(cs_pin, LOW);
  shiftOut(mosi_pin, clk_pin, MSBFIRST, data);
  digitalWrite(cs_pin, HIGH);
  #endif
}

void OledDriver::writeCommand(byte cmd) {
  setDcStatus(LOW);
  spiSend(cmd);
}

void OledDriver::writeCommand(byte cmd, byte data) {
  setDcStatus(LOW);
  spiSend(cmd);
  spiSend(data);
}

void OledDriver::writeData(byte data) {
  setDcStatus(HIGH);
  spiSend(data);
}

void OledDriver::clear() {
  setSegmentCursor(0,0);
  for(int i=0; i<SSD1306_SEGMENT_COUNT; i++) writeData(0x00);
  setSegmentCursor(0,0);
}

void OledDriver::setSegmentCursor(int segment, int page) {
  writeCommand(SSD1306_SET_COLUMN);
  writeCommand(segment);
  writeCommand(SSD1306_PIXEL_WIDTH - 1);
  writeCommand(SSD1306_SET_PAGE);
  writeCommand(page);
  writeCommand(SSD1306_PAGE_HEIGHT - 1);
}

void OledDriver::setTextCursor(int column, int page) {
  setSegmentCursor(column * FONT_WIDTH, page);
}


void OledDriver::writeBuffer(byte *buffer, int len) {
  for(int i=0; i<len; i++) writeData(buffer[i]);
}

void OledDriver::writeCharacter(char character) {
  for(int i=0; i<FONT_WIDTH; i++) writeData(FONT[character - 0x20][i]);
}

void OledDriver::writeString(char *characters) {
  while(*characters) writeCharacter(*characters++);
}
