/*

  Audio/SimpleSamplePlayer
  Playing short audio samples on an Arduino using some PWM tricks from the PCM library.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/Audio/SimpleSamplePlayer

 */

#include <PCM.h>

/* include one (and only one) sample definition */
// #include "sample_arduino_duemilanove.h"
// #include "sample_pop.h"
#include "sample_phone.h"


/* playback control variables */
const int DEBOUNCE_MILLISECONDS = 1000;
const int PLAY_BUTTON_PIN       = 2;
volatile bool playback_flag     = false;

/*
 * Command: play button interrupt handler
 */
void flagPlaybackInterrupt() {
  playback_flag = true;
}

/*
 * Command: enable hardware interrupt from play button
 */
void enablePlaybackInterrupt() {
  pinMode(PLAY_BUTTON_PIN, INPUT_PULLUP);
  delay(200);
  attachInterrupt(digitalPinToInterrupt(PLAY_BUTTON_PIN), flagPlaybackInterrupt, FALLING);
}


/*
 * Command: play the sample
 */
void play_sample() {
  startPlayback(sample, sizeof(sample));
  delay(DEBOUNCE_MILLISECONDS);
}


void setup() {
  enablePlaybackInterrupt();
}

void loop() {
  if (playback_flag) {
    play_sample();
    playback_flag = false;
  }
}
