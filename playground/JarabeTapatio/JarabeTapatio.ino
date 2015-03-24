/*

  Jarabe Tapatío

  Play The Mexican Hat Dance on a piezo buzzer!

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/JarabeTapatio

 */

#include "pitches.h"

#define SIGNAL_PIN 6  // pin that the piezo is connected to

#define BPM 165       // beats per minute for the playboack

// notes in the melody:
int melody[] = {
  NOTE_A5,
  NOTE_GS5,

  NOTE_A5,
  NOTE_FS5,
  NOTE_CS5,
  NOTE_D5,
  NOTE_D5,
  NOTE_CS5,

  NOTE_D5,
  NOTE_A4,
  NOTE_REST,
  NOTE_FS4,
  NOTE_G4,

  NOTE_A4,
  NOTE_B4,
  NOTE_CS5,
  NOTE_D5,
  NOTE_E5,
  NOTE_FS5,
  
  NOTE_G5,
  NOTE_E5,
  NOTE_REST,
  NOTE_G5,
  NOTE_FS5,

  NOTE_G5,
  NOTE_E5,
  NOTE_DS5,
  NOTE_E5,
  NOTE_CS5,
  NOTE_B4,
  
  NOTE_CS5,
  NOTE_A4,
  NOTE_REST,
  NOTE_A5,
  NOTE_GS5,

  NOTE_A5,
  NOTE_B5,
  NOTE_A5,
  NOTE_G5,
  NOTE_FS5,
  NOTE_E5,

  NOTE_D5,
  NOTE_REST
  
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8,
  8,

  8,
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

  2,
  2

};

const int noteCount = sizeof(melody) / sizeof(int);

void setup() {
  delay(1000);
}

void loop() {
  playMelody();
  delay(1000);  // wait before repeating
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
