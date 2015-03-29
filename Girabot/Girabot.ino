/*
  Girabot

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Girabot

 */

// undefine any of the following flags to remove the function from the build
#define ENABLE_MOTOR_SUBSYSTEM
#define ENABLE_AUDIO_SUBSYSTEM
#define ENABLE_LDR_SUBSYSTEM
#define ENABLE_MIC_SUBSYSTEM
// #define ENABLE_SERIAL_DEBUG

// pin settings
#define MOTOR_CONTROL_PIN 11
#define AUDIO_OUT_PIN 6
#define LDR_ENABLE_PIN 9
#define LDR2OUT_PIN 8
#define LDR1OUT_PIN 7
const int MIC_AMP_OUT_PIN = A0;

// includes
#include <FlexiTimer2.h>
#include <Servo.h>
#include "audio_subsystem.h"
#include "mic_subsystem.h"
#include "motor_subsystem.h"
#include "ldr_subsystem.h"


// main routines
void setup() {

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.begin(9600);
  #endif

  setupAudioSystem();
  setupMicSystem();
  setupLdrSystem();
  setupMotorSystem();

  FlexiTimer2::set(25, sampleSensors);
  FlexiTimer2::start();

}

void loop() {
  sampleLdrState();

  #ifdef ENABLE_SERIAL_DEBUG
  String result = "";
  Serial.println(result + mic_state + ", " + mic_reading + ", " + ldr_state);
  #endif

  if (mic_state) {
    dance();
    clearMicState();

  } else {

    switch (ldr_state) {
      case 1:
        walkRight();
        break;
      case 2:
        walkLeft();
        break;
      case 3:
        // stop walking
        break;
      default:
        walkAhead();
    }
    clearLdrState();

  }

}

void sampleSensors() {

  sampleMicState();

}

void dance() {
  playMelody();
}
