/*

  Hardware-specific SPI OLED driver
  * only supports SPI
  * currently assumes 128*64 monochrome

*/

#ifndef OledDriver_h
#define OledDriver_h

#include <Arduino.h>
#include "font.h"

//** dimensional settings
#define SSD1306_PIXEL_WIDTH             128
#define SSD1306_PIXEL_HEIGHT            64
#define SSD1306_PAGE_COUNT              8
#define SSD1306_PAGE_HEIGHT             (SSD1306_PIXEL_HEIGHT / SSD1306_PAGE_COUNT)
#define SSD1306_SEGMENT_COUNT           (SSD1306_PIXEL_WIDTH * SSD1306_PAGE_HEIGHT)


class OledDriver {
  public:
    OledDriver(int mosi_pin, int clk_pin, int dc_pin, int cs_pin);

    void init();
    void clear();
    int segmentCount();
    void setSegmentCursor(int segment, int page);
    void setTextCursor(int column, int page);
    void writeCharacter(char character);
    void writeString(char *characters);
    void writeCommand(byte cmd);
    void writeCommand(byte cmd, byte data);
    void writeData(byte cmd);
    void writeBuffer(byte *buffer, int len);

  private:
    // SPI pins:
    int mosi_pin;
    int clk_pin;
    int dc_pin;
    int cs_pin;

    byte dc_status;

    void setDcStatus(byte cmd);
    void spiSend(byte cmd);

};

#endif
