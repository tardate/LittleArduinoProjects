/*

  Popcorn

  How to make a piezo buzzer even more annoying? Make it play popcorn!

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/Popcorn

 */

#include "pitches.h"

#define SIGNAL_PIN 6  // pin that the piezo is connected to

#define BPM 145       // beats per minute for the playboack

// notes in the melody:
int melody[] = {
  NOTE_C4,
  NOTE_AS3,
  NOTE_C4,
  NOTE_G3,
  NOTE_DS3,
  NOTE_G3,
  NOTE_C3,
  NOTE_C4,
  NOTE_AS3,
  NOTE_C4,
  NOTE_G3,
  NOTE_DS3,
  NOTE_G3,
  NOTE_C3,

  NOTE_C4,
  NOTE_D4,
  NOTE_DS4,
  NOTE_D4,
  NOTE_DS4,
  NOTE_C4,
  NOTE_D4,
  NOTE_C4,
  NOTE_D4,
  NOTE_AS3,
  NOTE_C4,
  NOTE_AS3,
  NOTE_C4,
  NOTE_GS3,
  NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8,
  8,
  8,
  8,
  8,
  8,
  4,
  8,
  8,
  8,
  8,
  8,
  8,
  4,

  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  4

};

const int noteCount = sizeof(melody) / sizeof(int);

void setup() {
  delay(1000);
}

void loop() {
  playMelody();
}

void playMelody() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < noteCount; thisNote++) {

    // calculate the note duration based on BPM
    int noteDuration = 60000 * 4.0 / BPM / noteDurations[thisNote];
    tone(SIGNAL_PIN, melody[thisNote], noteDuration);

    // play with staccato ~ half beat
    delay(noteDuration / 2);
    noTone(SIGNAL_PIN);
    delay(noteDuration / 2);

  }
}
