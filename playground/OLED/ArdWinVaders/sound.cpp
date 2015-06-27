#include "sound.h"

/*
 *   constructor
 */
Sound::Sound(uint8_t speaker_pin) {
  this->speaker_pin = speaker_pin;
}

void Sound::init() {
  noTone(speaker_pin);
}

void Sound::fire() {
  noTone(speaker_pin);
  play(NOTE_C3, 300);
}

void Sound::play(unsigned int note, unsigned long duration) {
  tone(speaker_pin, note, duration);
}