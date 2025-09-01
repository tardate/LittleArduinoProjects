/*

  Popcorn

  How to make a piezo buzzer even more annoying? Make it play popcorn!

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/Popcorn

 */

#include "pitches.h"

#define SIGNAL_PIN 6  // pin that the piezo is connected to

// melody definition
// BPM followed by series of note definitions.
// Note definition as paired values: pitch, duration.
// Durations indicated as 4 = quarter note, 8 = eighth note, etc
int melody[] = {
  // beats per minute
  145,
  // note definitions as values: pitch, duration.
  NOTE_C4,  8,
  NOTE_AS3, 8,
  NOTE_C4,  8,
  NOTE_G3,  8,
  NOTE_DS3, 8,
  NOTE_G3,  8,
  NOTE_C3,  4,
  NOTE_C4,  8,
  NOTE_AS3, 8,
  NOTE_C4,  8,
  NOTE_G3,  8,
  NOTE_DS3, 8,
  NOTE_G3,  8,
  NOTE_C3,  4,

  NOTE_C4,  8,
  NOTE_D4,  8,
  NOTE_DS4, 8,
  NOTE_D4,  8,
  NOTE_DS4, 8,
  NOTE_C4,  8,
  NOTE_D4,  8,
  NOTE_C4,  8,
  NOTE_D4,  8,
  NOTE_AS3, 8,
  NOTE_C4,  8,
  NOTE_AS3, 8,
  NOTE_C4,  8,
  NOTE_GS3, 8,
  NOTE_C4,  4
};

void setup() {
  delay(1000);
}

void loop() {
  playMelody();
}

void playMelody() {
  int noteCount = sizeof(melody) / sizeof(int) - 1;
  int bpm = melody[0];

  // iterate over the notes of the melody:
  for (int noteIndex = 0; noteIndex < noteCount; noteIndex+=2) {

    // calculate the note duration based on BPM
    int noteDuration = 60000 * 4.0 / bpm / melody[noteIndex + 2];
    tone(SIGNAL_PIN, melody[noteIndex+1], noteDuration);

    // play with staccato ~ half beat
    delay(noteDuration / 2);
    noTone(SIGNAL_PIN);
    delay(noteDuration / 2);

  }
}
