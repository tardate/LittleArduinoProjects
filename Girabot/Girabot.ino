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
#include <Servo.h>
#include "audio_subsystem.h"
#include "mic_subsystem.h"
#include "motor_subsystem.h"
#include "ldr_subsystem.h"

#ifdef ENABLE_SERIAL_DEBUG
String result = "";
#endif

// main routines
void setup() {

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.begin(9600);
  #endif

  setupAudioSystem();
  setupMicSystem();
  setupLdrSystem();
  setupMotorSystem();

}

void loop() {

  sampleMicState();

  #ifdef ENABLE_SERIAL_DEBUG
  if (mic_state) Serial.println("MIC ALERT! MIC ALERT! MIC ALERT! ");
  Serial.print(result + "mic_state: " +  mic_state + ", mic_reading: " + mic_reading + "/" + mic_reading_min + "-" + mic_reading_max);
  #endif

  if (mic_state) {
    dance();
  }
  clearMicState();

  sampleLdrState();

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.println(result + ", ldr_state: " + ldr_state + ", walkCounter: " + walkCounter + "/" + pauseCounter);
  #endif

  switch (ldr_state) {
    case 1:
      beepRight();
      walkRight();
      break;
    case 2:
      beepLeft();
      walkLeft();
      break;
    case 3:
      beepStopWalking();
      stopWalking();
      break;
    default:
      walkAhead();
  }
  clearLdrState();

}

void dance() {
  playMelody();
}

