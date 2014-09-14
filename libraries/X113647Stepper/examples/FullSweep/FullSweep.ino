
/*
 X113647 Stepper Motor Control - one revolution

 This program drives a 4-Phase 5-Wire stepper motor using 4 wires
 via an X113647 (ULN2003-based) driver board.

 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.

 */

#include <X113647Stepper.h>

const int stepsPerRevolution = 64 * 32;  // change this to fit the number of steps per revolution for your motor

// initialize the stepper library on pins 8 through 11:
X113647Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed in rpm:
  myStepper.setSpeed(1.5);
}

void loop() {
  // step one revolution  in one direction:
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

