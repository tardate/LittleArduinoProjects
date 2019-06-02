#include <Arduino.h>
#include "melody.h"

// melody definitions
// BPM followed by series of note definitions.
// Note definition as set values: pitch, duration, staccato.
// Durations indicated as 4 = quarter note, 8 = eighth note, etc

int happy_beep[] = {
  220, // bpm
  // notes: pitch, duration, staccato
  NOTE_A4,  8, 1,
  NOTE_CS5, 8, 1,
  NOTE_E5,  8, 1,
  NOTE_A6,  8, 1
};

int sad_beep[] = {
  95, // bpm
  // notes: pitch, duration, staccato
  NOTE_D4,  8, 0,
  NOTE_G3,  4, 0
};

int happy_tune[] = {
  220, // bpm
  // notes: pitch, duration, staccato
  NOTE_CS5, 8, 1,
  NOTE_GS5, 8, 1,
  NOTE_F6,  8, 1,
  NOTE_GS6, 4, 1,
  NOTE_F6,  8, 1,
  NOTE_GS6, 4, 0
};

int sad_tune[] = {
  95, // bpm
  // notes: pitch, duration, staccato
  NOTE_CS4, 16, 0,
  NOTE_D4,  8,  1,
  NOTE_C4,  16, 0,
  NOTE_CS4, 8,  1,
  NOTE_B3,  16, 0,
  NOTE_C4,  8,  1,
  NOTE_AS3, 16, 0,
  NOTE_B3,  4,  0
};


void playMelody(uint8_t speaker_pin, Melodies melody) {
  int * current_melody;
  int noteCount;

  switch (melody) {
  case Melodies::HappyBeep:
    current_melody = happy_beep;
    noteCount = sizeof(happy_beep) / sizeof(int) - 1;
    break;;
  case Melodies::SadBeep:
    current_melody = sad_beep;
    noteCount = sizeof(sad_beep) / sizeof(int) - 1;
    break;;
  case Melodies::HappyTune:
    current_melody = happy_tune;
    noteCount = sizeof(happy_tune) / sizeof(int) - 1;
    break;;
  case Melodies::SadTune:
    current_melody = sad_tune;
    noteCount = sizeof(sad_tune) / sizeof(int) - 1;
    break;;
  default:
    return;
  };

  int bpm = current_melody[0];

  // iterate over the notes in the melody:
  for (int noteIndex = 0; noteIndex < noteCount; noteIndex += 3) {
    int pitch = current_melody[noteIndex + 1];
    int duration = current_melody[noteIndex + 2];
    int staccato = current_melody[noteIndex + 3];

    // calculate the note duration based on BPM
    int noteDuration = 60000 * 4.0 / bpm / duration;
    tone(speaker_pin, pitch, noteDuration);

    if (staccato) {
      delay(noteDuration / 2);
      noTone(speaker_pin);
      delay(noteDuration / 2);
    } else {
      delay(noteDuration);
      noTone(speaker_pin);
    }
  }
}
