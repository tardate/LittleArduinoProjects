/*

  MicroSD/WavePlayer
  A basic demonstration of playing a sound file (WAV) from an SD card with an Arduino.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Audio/MicroSD/WavePlayer

 */

#include <SPI.h>
#include <SD.h>
#include "TMRpcm.h"

const int PLAY_PIN = 2;
const int AUDIO_PIN = 9;
#define SAMPLE_NAME ("/SAMPLE.WAV")

TMRpcm audio_player;


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(PLAY_PIN, INPUT_PULLUP);

  SD.begin();

  audio_player.speakerPin = AUDIO_PIN;
  audio_player.setVolume(5);
  audio_player.quality(0);
}


/*
 * Command: main loop
 */
void loop() {
  static boolean play = false;

  if (!audio_player.isPlaying()) {
    if (play) {
      audio_player.play(SAMPLE_NAME);
      play = false;
    } else {
      play = !digitalRead(PLAY_PIN);
    }
  }
}
