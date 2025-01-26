#include "buffered_display.h"
#include <stdlib.h>

/*
 *   constructor
 */

BufferedDisplay::BufferedDisplay(OledDriver *displayDriver) {
  display = displayDriver;
  buffer_size = display->segmentCount();
  buffer = (byte*)malloc( buffer_size );
}

void BufferedDisplay::init() {
  display->init();
  reset();
}

void BufferedDisplay::reset() {
  for(int i=0; i<buffer_size; i++) buffer[i] = 0x00;
  segment_cursor = 0;
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

int BufferedDisplay::setSegmentByPageOffset(int page, int offset) {
  segment_cursor = page * DISPLAY_WIDTH + offset;
  return (page + 1) * DISPLAY_WIDTH - 1;
}

int BufferedDisplay::getPage(int y) {
  div_t result = div (y, DISPLAY_PAGE_HEIGHT);
  return result.quot;
}

void BufferedDisplay::writeSegment(byte data) {
  buffer[segment_cursor++] = data;
}

void BufferedDisplay::writeSegment(byte data, int segmentLimit) {
  if(segment_cursor>segmentLimit) return;
  buffer[segment_cursor++] = data;
}

int BufferedDisplay::xorSegment(byte data) {
  int collision = buffer[segment_cursor] & data;
  buffer[segment_cursor++] ^= data;
  return collision;
}

void BufferedDisplay::writeCharacter(char character) {
  for(int i=0; i<FONT_WIDTH; i++) writeSegment(FONT[character - 0x20][i]);
}

void BufferedDisplay::writeString(char *characters) {
  while(*characters) writeCharacter(*characters++);
}

void BufferedDisplay::moveFireBase(int new_left_x) {
  setSegmentCursor(FIREBASE_ROW_OFFSET + new_left_x);
  for(int i=0; i<FIREBASE_WIDTH; i++) writeSegment(firebase_sprite[i]);
}

int BufferedDisplay::moveMissile(int x, int new_y) {
  int y_offset = setSegmentCursor(x, new_y);
  return xorSegment(1 << y_offset);
}

bool BufferedDisplay::insertAlienAtCursor(int segmentLimit) {
  for(int i=0; i<ALIEN_WIDTH; i++) writeSegment(alien_sprite[i], segmentLimit);
  return (segment_cursor < segmentLimit);
}

void BufferedDisplay::insertNoAlienAtCursor(int segmentLimit) {
  for(int i=0; i<ALIEN_WIDTH; i++) writeSegment(0x00, segmentLimit);
}


