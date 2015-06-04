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
#define DISPLAY_PAGE_HEIGHT SSD1306_PAGE_HEIGHT

#define FIREBASE_WIDTH 5
#define FIREBASE_GUN_X_OFFSET 2
#define FIREBASE_GUN_Y_OFFSET 5
#define FIREBASE_INITAL_X DISPLAY_WIDTH / 2 - 2
#define FIREBASE_MAX_X DISPLAY_WIDTH - FIREBASE_WIDTH

#define ALIEN_WIDTH 5
#define ALIEN_MARGIN 5
#define ALIEN_MARGIN_LEFT 3
#define ALIEN_MARGIN_RIGHT 2
#define ALIEN_SPACING (ALIEN_WIDTH + ALIEN_MARGIN)

class BufferedDisplay {
  public:
    BufferedDisplay(OledDriver *displayDriver);

    void init();
    void redraw();
    void setSegmentCursor(int position);
    int  setSegmentCursor(int x, int y);
    void setSegmentByPageOffset(int page, int offset);

    void writeSegment(byte data);
    void writeString(char *characters);

    void moveFireBase(int new_left_x);
    void moveFireBase(int new_left_x, int delta);

    void moveMissile(int x, int new_y);
    void moveMissile(int x, int old_y, int new_y);

    void insertAlienAtCursor();
    void insertNoAlienAtCursor();

  private:
    byte firebase_sprite[FIREBASE_WIDTH] = {
      0b10000000,
      0b11000000,
      0b11111000,
      0b11000000,
      0b10000000
    };

    byte alien_sprite[ALIEN_WIDTH] = {
      0b00011101,
      0b00001010,
      0b00001110,
      0b00001010,
      0b00011101
    };

    int buffer_size;
    byte *buffer;
    int segment_cursor;

    OledDriver *display;


    void xorSegment(byte data);
    void writeCharacter(char character);

};

#endif
