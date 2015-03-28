/*
  Girabot

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Girabot

 */

// undefine any of the following enable flags to remove the function from the build
// #define ENABLE_MOTORS
#define ENABLE_SPEAKER

#define SPEAKER_PIN 6

#include "melody.h"

#include <Servo.h>

#define SERVO_PIN 9

#define STEP_DELAY 500
#define WALK_LR_OFFSET 30
#define WALK_LEFT 90 - WALK_LR_OFFSET
#define WALK_RIGHT 90 + WALK_LR_OFFSET

Servo myservo;

void centerServo() {
  myservo.write(90);
}

void walkFullStep() {
  myservo.write(WALK_LEFT);
  delay(STEP_DELAY);
  myservo.write(WALK_RIGHT);
  delay(STEP_DELAY);
}

void walkAhead() {
  for( int i=0; i<10; i++) {
    walkFullStep();
  }
}



void setup() {

  #ifdef ENABLE_MOTORS
  myservo.attach(SERVO_PIN);
  centerServo();
  #endif

}

void loop() {
  delay(1000);

  #ifdef ENABLE_MOTORS
  walkAhead();
  #endif

  #ifdef ENABLE_SPEAKER
  playMelody();
  #endif
}

