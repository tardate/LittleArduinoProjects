/*

  ClassicNokia
  Just a quick transcription of the classic Nokia 3310 ringtone for Arduino.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ClassicNokia

 */

#include "pitches.h"

// pin that the sound output is connected to
const int SOUND_PIN = 6;

// melody definition
// BPM followed by series of note definitions.
// Note definition as paired values: pitch, duration.
// Durations indicated as 4 = quarter note, 8 = eighth note, etc
int melody[] = {
  // beats per minute
  185,
  // note definitions as values: pitch, duration.
  NOTE_E6  , 8,
  NOTE_D6  , 8,
  NOTE_FS5 , 4,
  NOTE_GS5 , 4,

  NOTE_CS6 , 8,
  NOTE_B5  , 8,
  NOTE_D5  , 4,
  NOTE_E5  , 4,

  NOTE_B5  , 8,
  NOTE_A5  , 8,
  NOTE_CS5 , 4,
  NOTE_E5  , 4,

  NOTE_A5  , 2,
  NOTE_REST, 2
};

void setup() {
  // nothing to do!
}

void loop() {
  delay(1000);  // wait before playing/repeating
  playMelody();
}


void playMelody() {
  int noteCount = sizeof(melody) / sizeof(int) - 1;
  int bpm = melody[0];

  // iterate over the notes of the melody:
  for (int noteIndex = 0; noteIndex < noteCount; noteIndex+=2) {

    // calculate the note duration based on BPM
    int noteDuration = 60000 * 4.0 / bpm / melody[noteIndex + 2];
    tone(SOUND_PIN, melody[noteIndex+1], noteDuration);

    // play with staccato ~ half beat
    delay(noteDuration);
    noTone(SOUND_PIN);
    // delay(noteDuration / 2);

  }
}
