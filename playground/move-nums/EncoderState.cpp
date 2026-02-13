#include "EncoderState.h"

EncoderState::EncoderState(int8_t min_position, int8_t max_position) {
  this->min_position = min_position;
  this->max_position = max_position;
  reset();
}

void EncoderState::reset(void) {
  this->position = min_position;
  clear();
}

bool EncoderState::process(unsigned char direction) {
  bool result = false;
  if (direction == DIR_CW) {
    result = change(1);
  }
  else if (direction == DIR_CCW) {
    result = change(-1);
  }
  return result;
}

bool EncoderState::inc(void) {
  return change(1);
}

bool EncoderState::dec(void) {
  return change(-1);
}

inline bool EncoderState::change(int8_t amount) {
  int8_t new_position = position + amount;
  if (new_position >= min_position && new_position <= max_position) {
    this->position = new_position;
    this->has_changed = true;
  } else {
    this->has_changed = false;
  }
  return this->has_changed;
}

void EncoderState::clear(void) {
  this->has_changed = false;
}
