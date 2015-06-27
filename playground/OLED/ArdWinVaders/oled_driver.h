/*

  Hardware-specific SPI OLED driver
  * only supports SPI
  * currently assumes 128*64 monochrome

*/

#ifndef OledDriver_h
#define OledDriver_h

#define USE_OPTIMISED_SPI

#include <Arduino.h>
#include "font.h"

//** dimensional settings
#define SSD1306_PIXEL_WIDTH             128
#define SSD1306_PIXEL_HEIGHT            64
#define SSD1306_PAGE_COUNT              8
#define SSD1306_PAGE_HEIGHT             (SSD1306_PIXEL_HEIGHT / SSD1306_PAGE_COUNT)
#define SSD1306_SEGMENT_COUNT           (SSD1306_PIXEL_WIDTH * SSD1306_PAGE_HEIGHT)

#ifdef USE_OPTIMISED_SPI
// fast SPI supporting types
typedef volatile uint8_t PortReg;
typedef uint8_t PortMask;
#endif

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
    void writeData(byte data);
    void writeBuffer(byte *buffer, int len);

  private:
    // SPI pins:
    int mosi_pin;
    int clk_pin;
    int dc_pin;
    int cs_pin;

    #ifdef USE_OPTIMISED_SPI
    PortReg *mosi_port, *clk_port, *cs_port, *dc_port;
    PortMask mosi_pinmask, clk_pinmask, cs_pinmask, dc_pinmask;
    void spiShiftOut(byte data);
    #endif

    byte dc_status;

    void setDcStatus(byte state);
    void spiSend(byte data);

};

#endif
