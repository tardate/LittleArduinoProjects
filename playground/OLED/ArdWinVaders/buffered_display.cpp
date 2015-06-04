#include "buffered_display.h"
#include <stdlib.h>

#define FIREBASE_ROW_OFFSET SSD1306_PIXEL_WIDTH * (SSD1306_PAGE_COUNT - 1)

/*
 *   constructor
 */

BufferedDisplay::BufferedDisplay(OledDriver *displayDriver) {
  display = displayDriver;
  buffer_size = display->segmentCount();
  buffer = (byte*)malloc( buffer_size );
  for(int i=0; i<buffer_size; i++) buffer[i] = 0x00;
  segment_cursor = 0;
}

void BufferedDisplay::init() {
  display->init();
  display->clear();
}

void BufferedDisplay::redraw() {
  display->setSegmentCursor(0,0);
  display->writeBuffer(buffer, buffer_size);
}

void BufferedDisplay::setSegmentCursor(int position) {
  segment_cursor = position;
}

int BufferedDisplay::setSegmentCursor(int x, int y) {
  div_t result = div (y, DISPLAY_PAGE_HEIGHT);
  segment_cursor = result.quot * DISPLAY_WIDTH + x;
  return result.rem;
}

void BufferedDisplay::setSegmentByPageOffset(int page, int offset) {
  segment_cursor = page * DISPLAY_WIDTH + offset;
}

void BufferedDisplay::writeSegment(byte data) {
  buffer[segment_cursor++] = data;
}

void BufferedDisplay::xorSegment(byte data) {
  buffer[segment_cursor++] ^= data;
}

void BufferedDisplay::writeCharacter(char character) {
  for(int i=0; i<FONT_WIDTH; i++) writeSegment(FONT[character - 0x20][i]);
}

void BufferedDisplay::writeString(char *characters) {
  while(*characters) writeCharacter(*characters++);
}

void BufferedDisplay::moveFireBase(int new_left_x) {
  moveFireBase(new_left_x, 0);
}

void BufferedDisplay::moveFireBase(int new_left_x, int delta) {
  int i;
  if(delta>0) {
    segment_cursor = FIREBASE_ROW_OFFSET + new_left_x - delta;
    for(i=0; i<delta; i++) writeSegment(0x00);
  } else {
    segment_cursor = FIREBASE_ROW_OFFSET + new_left_x;
  }
  for(i=0; i<FIREBASE_WIDTH; i++) writeSegment(firebase_sprite[i]);
  if(delta<0) {
    for(i=delta; i<0; i++) writeSegment(0x00);
  }
}

void BufferedDisplay::moveMissile(int x, int new_y) {
  int y_offset = setSegmentCursor(x, new_y);
  xorSegment(1 << y_offset);
}

void BufferedDisplay::moveMissile(int x, int old_y, int new_y) {
  moveMissile(x, old_y);
  moveMissile(x, new_y);
}

void BufferedDisplay::insertAlienAtCursor() {
  int i;
  for(i=0; i<ALIEN_MARGIN_LEFT; i++) writeSegment(0x00);
  for(i=0; i<ALIEN_WIDTH; i++) writeSegment(alien_sprite[i]);
  for(i=0; i<ALIEN_MARGIN_RIGHT; i++) writeSegment(0x00);
}

void BufferedDisplay::insertNoAlienAtCursor() {
  for(int i=0; i<ALIEN_SPACING; i++) writeSegment(0x00);
}


