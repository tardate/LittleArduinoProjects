/*

  El Jarabe Tapatío

  Play The Mexican Hat Dance on a piezo buzzer!

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/JarabeTapatio

 */

#include "pitches.h"

#define SIGNAL_PIN 6  // pin that the piezo is connected to

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
    tone(SIGNAL_PIN, melody[noteIndex+1], noteDuration);

    // play with staccato ~ half beat
    delay(noteDuration / 2);
    noTone(SIGNAL_PIN);
    delay(noteDuration / 2);

  }
}
