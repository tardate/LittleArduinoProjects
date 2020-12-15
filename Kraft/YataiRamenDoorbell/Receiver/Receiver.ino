/*

  YataiRamenDoorbell
  Receiver

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kraft/YataiRamenDoorbell

 */

#include <RH_ASK.h>
#include <SPI.h>
#include <SD.h>
#include "TMRpcm.h"

const int PLAY_PIN = 2; // normally closed (grounded)
const int LED_EN_PIN = 5;
const int AUDIO_EN_PIN = 6; // active low
const int AUDIO_OUT_PIN = 9;

const int RX_PIN = 3;
const int TX_PIN = 4;

const int RH_BPS = 2000;

#define SAMPLE_NAME ("/SAMPLE.WAV")

TMRpcm audio_player;

RH_ASK driver(RH_BPS, RX_PIN, TX_PIN);

boolean lights_on = false;
unsigned long lights_on_at = 0;
const unsigned long lights_on_duration = 60000;

void setup() {
  pinMode(PLAY_PIN, INPUT_PULLUP);
  pinMode(LED_EN_PIN, OUTPUT);
  pinMode(AUDIO_EN_PIN, OUTPUT);
  digitalWrite(AUDIO_EN_PIN, HIGH);
  driver.init();

  SD.begin();
  audio_player.speakerPin = AUDIO_OUT_PIN;
  audio_player.setVolume(5);
  audio_player.quality(0);
}

void loop() {
  if (bellPressed() || digitalRead(PLAY_PIN)) {
    lightsOn();
    playAudio();
  } else {
    checkLights();
  }
}

boolean bellPressed() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    buf[buflen] = 0; // because the driver doesn't know it is meant to be a string

    if ( strcmp((char *) buf, "b") == 0 ) {
      return true;
    }
  }
  return false;
}

void playAudio() {
  digitalWrite(AUDIO_EN_PIN, LOW);
  audio_player.play(SAMPLE_NAME);
  while (audio_player.isPlaying()) {};
  digitalWrite(AUDIO_EN_PIN, HIGH);
  driver.init(); // reclaim Timer1 for RF driver
}

void lightsOn() {
  digitalWrite(LED_EN_PIN, HIGH);
  lights_on = true;
  lights_on_at = millis();
}

void checkLights() {
  if (lights_on) {
    if (millis() - lights_on_at >= lights_on_duration) {
      digitalWrite(LED_EN_PIN, LOW);
      lights_on = false;
    }
  }
}
