/*

  Manages buffered display
  * largly hardware-agnostic
  * owns the screen buffer
  * delegate screen updates to the OledDriver
  * can write text to the buffer
  * TODO: be smart about trakcing what's changed?
  * own sprites?
  * accept sprite move/draw updates?

*/

#ifndef BufferedDisplay_h
#define BufferedDisplay_h

#include "oled_driver.h"

#define DISPLAY_WIDTH SSD1306_PIXEL_WIDTH
#define DISPLAY_HEIGHT SSD1306_PIXEL_HEIGHT
#define DISPLAY_PAGE_COUNT SSD1306_PAGE_COUNT
#define DISPLAY_PAGE_HEIGHT SSD1306_PAGE_HEIGHT

#define FIREBASE_WIDTH 9
#define FIREBASE_GUN_X_OFFSET 4
#define FIREBASE_GUN_Y_OFFSET 5
#define FIREBASE_INITAL_X (DISPLAY_WIDTH / 2 - 4)
#define FIREBASE_MAX_X (DISPLAY_WIDTH - FIREBASE_WIDTH)
#define FIREBASE_ROW_OFFSET DISPLAY_WIDTH * (DISPLAY_PAGE_COUNT - 1)

#define ALIEN_WIDTH 9
#define ALIEN_GUN_X_OFFSET 4
#define ALIEN_GUN_Y_OFFSET 5

class BufferedDisplay {
  public:
    BufferedDisplay(OledDriver *displayDriver);

    void init();
    void reset();
    void redraw();
    void setSegmentCursor(int position);
    int  setSegmentCursor(int x, int y);
    int  setSegmentByPageOffset(int page, int offset);

    int  getPage(int y);

    void writeString(char *characters);

    void moveFireBase(int new_left_x);

    int  moveMissile(int x, int new_y);

    bool insertAlienAtCursor(int segmentLimit);
    void insertNoAlienAtCursor(int segmentLimit);

  private:
    byte firebase_sprite[FIREBASE_WIDTH] = {
      0b00000000,
      0b00000000,
      0b10000000,
      0b11000000,
      0b11111000,
      0b11000000,
      0b10000000,
      0b00000000,
      0b00000000
    };

    byte alien_sprite[ALIEN_WIDTH] = {
      0b00000000,
      0b00000000,
      0b00111010,
      0b00010100,
      0b00011100,
      0b00010100,
      0b00111010,
      0b00000000,
      0b00000000
    };

    int buffer_size;
    byte *buffer;
    int segment_cursor;

    OledDriver *display;

    void writeSegment(byte data);
    void writeSegment(byte data, int segmentLimit);
    int  xorSegment(byte data);
    void writeCharacter(char character);

};

#endif
