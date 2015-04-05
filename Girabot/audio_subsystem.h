#ifndef AudioSubsystem_h
#define AudioSubsystem_h

#ifdef ENABLE_AUDIO_SUBSYSTEM

#include "pitches.h"
#define SHORT_NOTE_LENGTH 70

// melody definition
// BPM followed by series of note definitions.
// Note definition as paired values: pitch, duration.
// Durations indicated as 4 = quarter note, 8 = eighth note, etc
int melody[] = {
  // beats per minute
  172,
  // note definitions as values: pitch, duration.
  NOTE_A5  , 8,
  NOTE_GS5 , 8,

  NOTE_A5  , 8,
  NOTE_FS5 , 8,
  NOTE_F5  , 8,
  NOTE_FS5 , 8,
  NOTE_D5  , 8,
  NOTE_CS5 , 8,

  NOTE_D5  , 8,
  NOTE_A4  , 4,
  NOTE_REST, 8,
  NOTE_FS4 , 8,
  NOTE_G4  , 8,

  NOTE_A4  , 8,
  NOTE_B4  , 8,
  NOTE_CS5 , 8,
  NOTE_D5  , 8,
  NOTE_E5  , 8,
  NOTE_FS5 , 8,

  NOTE_G5  , 8,
  NOTE_E5  , 4,
  NOTE_REST, 8,
  NOTE_G5  , 8,
  NOTE_FS5 , 8,

  NOTE_G5  , 8,
  NOTE_E5  , 8,
  NOTE_DS5 , 8,
  NOTE_E5  , 8,
  NOTE_CS5 , 8,
  NOTE_B4  , 8,

  NOTE_CS5 , 8,
  NOTE_A4  , 4,
  NOTE_REST, 8,
  NOTE_A5  , 8,
  NOTE_GS5 , 8,

  NOTE_A5  , 8,
  NOTE_B5  , 8,
  NOTE_A5  , 8,
  NOTE_G5  , 8,
  NOTE_FS5 , 8,
  NOTE_E5  , 8,

  NOTE_D5  , 2,
  NOTE_REST, 2

};

void setupAudioSystem() {
  pinMode(AUDIO_OUT_PIN, OUTPUT);
}

void playMelody() {
  int noteCount = sizeof(melody) / sizeof(int) - 1;
  int bpm = melody[0];

  // iterate over the notes of the melody:
  for (int noteIndex = 0; noteIndex < noteCount; noteIndex+=2) {

    // calculate the note duration based on BPM
    int noteDuration = 60000 * 4.0 / bpm / melody[noteIndex + 2];
    tone(AUDIO_OUT_PIN, melody[noteIndex+1], noteDuration);

    // play with staccato ~ half beat
    delay(noteDuration / 2);
    noTone(AUDIO_OUT_PIN);
    delay(noteDuration / 2);

  }
}

void beepLeft() {
  tone(AUDIO_OUT_PIN, NOTE_A5);
  delay(SHORT_NOTE_LENGTH);
  tone(AUDIO_OUT_PIN, NOTE_A4);
  delay(SHORT_NOTE_LENGTH);
  noTone(AUDIO_OUT_PIN);
}

void beepRight() {
  tone(AUDIO_OUT_PIN, NOTE_C4);
  delay(SHORT_NOTE_LENGTH);
  tone(AUDIO_OUT_PIN, NOTE_C5);
  delay(SHORT_NOTE_LENGTH);
  noTone(AUDIO_OUT_PIN);
}

void beepStopWalking() {
  for(int note = NOTE_A3 ; note > NOTE_A2; note -= 10) {
    tone(AUDIO_OUT_PIN, note);
    delay(20);
  }
  noTone(AUDIO_OUT_PIN);
}

#else
// NOP functions for when audio disabled

void setupAudioSystem() { }

void playMelody() { }

void beepLeft() { }

void beepRight() { }

void beepStopWalking() { }

#endif

#endif
