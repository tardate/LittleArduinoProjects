/*

  ElectretTrigger
  Triggers a tone sequence when mic input above predetermined threshold

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ElectretTrigger

 */

#include "pitches.h"
#include "melody.h"

const int preamp_pin = A1;             // the pin we'll read preamp output value from

#define TRIGGER_THRESHOLD 512

void setup() {
  pinMode(preamp_pin, INPUT);          // enable preamp read
}

void loop() {
  if(sample() > TRIGGER_THRESHOLD) {
    playMelody();
  }
  delay(1);
}

int sample() {
  return analogRead(preamp_pin);
}

void playMelody() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < noteCount; thisNote++) {

    // calculate the note duration based on BPM
    int noteDuration = 60000 * 4.0 / BPM / noteDurations[thisNote];
    tone(melody_pin, melody[thisNote], noteDuration);

    // play with staccato ~ half beat
    delay(noteDuration / 2);
    noTone(melody_pin);
    delay(noteDuration / 2);

  }
}
