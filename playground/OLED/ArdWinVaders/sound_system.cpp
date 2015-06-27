#include "sound_system.h"

/*
 *   constructor
 */
SoundSystem::SoundSystem(uint8_t speaker_pin) {
  this->speaker_pin = speaker_pin;
}

void SoundSystem::init() {
  noTone(speaker_pin);
}

void SoundSystem::fire() {
  noTone(speaker_pin);
  play(NOTE_C3, 300);
}

void SoundSystem::play(unsigned int note, unsigned long duration) {
  tone(speaker_pin, note, duration);
}