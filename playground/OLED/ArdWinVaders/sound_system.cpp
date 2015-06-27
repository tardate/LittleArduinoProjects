#include "sound_system.h"
#include <avr/pgmspace.h>

#define TICKS_PER_BEAT_MAX 2
#define BEAT_DURATION 120

#define FIRE_NOTE NOTE_C4
#define FIRE_DURATION (BEAT_DURATION * 2)

#define MELODY_SIZE 120
#define MELODY_LIMIT (MELODY_SIZE - 2)
const unsigned int melody[MELODY_SIZE] PROGMEM = {
  // 10
  NOTE_E3,NOTE_2,
  NOTE_E3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_2,

  NOTE_D3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_2,

  NOTE_D3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_1,

  // 10
  NOTE_E3,NOTE_2,
  NOTE_E3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_2,

  NOTE_D3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_2,

  NOTE_D3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_1,

  // 10
  NOTE_B3,NOTE_2,
  NOTE_B3,NOTE_4d,
  NOTE_B3,NOTE_8,
  NOTE_B3,NOTE_2,

  NOTE_A3,NOTE_4d,
  NOTE_C3,NOTE_8,
  NOTE_B3,NOTE_2,

  NOTE_A3,NOTE_4d,
  NOTE_C3,NOTE_8,
  NOTE_B3,NOTE_1,

  // 10
  NOTE_E3,NOTE_2,
  NOTE_E3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_2,

  NOTE_D3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_2,

  NOTE_D3,NOTE_4d,
  NOTE_F3,NOTE_8,
  NOTE_E3,NOTE_2,

  // 10
  NOTE_D3,NOTE_8,
  NOTE_E3,NOTE_8,
  NOTE_F3,NOTE_8,
  NOTE_G4,NOTE_1,
  NOTE_D4,NOTE_2,

  NOTE_D3,NOTE_8,
  NOTE_E3,NOTE_8,
  NOTE_F3,NOTE_8,
  NOTE_G4,NOTE_1,
  NOTE_D4,NOTE_2,

  // 10
  NOTE_G4,NOTE_2,
  NOTE_D4,NOTE_8,
  NOTE_B3,NOTE_8,
  NOTE_C4,NOTE_8,
  NOTE_D4,NOTE_2,

  NOTE_G4,NOTE_2,
  NOTE_D4,NOTE_8,
  NOTE_B4,NOTE_8,
  NOTE_C4,NOTE_8,
  NOTE_D4,NOTE_4d,

};


/*
 *   constructor
 */
SoundSystem::SoundSystem(uint8_t speaker_pin) {
  this->speaker_pin = speaker_pin;
}

void SoundSystem::init() {
  noTone(speaker_pin);
  ticks_per_beat = TICKS_PER_BEAT_MAX;
  tick_counter = 0;
  note_counter = 0;
  note_index = 0;
}

void SoundSystem::next() {
  if(tick_counter>0) tick_counter--;
  else {
    tick_counter = ticks_per_beat;
    if(note_counter>0) {
      // still playing last note
      note_counter--;
    } else {
      // play next note
      note_counter = pgm_read_word(&melody[note_index+1]);
      play(pgm_read_word(&melody[note_index]), note_counter * BEAT_DURATION);
      note_index++;
      note_index++;
      if(note_index>MELODY_LIMIT) {
        if(--ticks_per_beat==0) ticks_per_beat = TICKS_PER_BEAT_MAX;
        note_index=0;
      }
    }
  }
}

void SoundSystem::fire() {
  noTone(speaker_pin);
  play(FIRE_NOTE, FIRE_DURATION);
}

void SoundSystem::play(unsigned int note, unsigned long duration) {
  tone(speaker_pin, note, duration);
}