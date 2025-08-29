/*

  StepperMotors/28BYJ48/StepperLibraryDrive
  This program demonstrates using the standard Stepper library
  to drive a unipolar 28YBT-48 stepper motor.

  The standard Stepper library requires re-mapping of the control pins in 1-3-2-4 sequence as follows:

  Step C0 C1 C2 C3  <= as driven by the Stepper library
     1  1  0  1  0
     2  0  1  1  0
     3  0  1  0  1
     4  1  0  0  1
  Pin: I1 I3 I2 I4  <= remapped to the 28YBT-48/X113647 inputs

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Kinetics/StepperMotors/28BYJ48/StepperLibraryDrive

 */

#include <Stepper.h>

static const int STEPS_PER_REVOLUTION     = 32 * 64;
static const int PIN_IN1_BLUE             = 8;
static const int PIN_IN2_PINK             = 9;
static const int PIN_IN3_YELLOW           = 10;
static const int PIN_IN4_ORANGE           = 11;

// initialize the stepper library
Stepper myStepper(STEPS_PER_REVOLUTION, PIN_IN1_BLUE, PIN_IN3_YELLOW, PIN_IN2_PINK, PIN_IN4_ORANGE);

void setup() {
  myStepper.setSpeed(6.5);                // in rpm
}

void loop() {
  myStepper.step(STEPS_PER_REVOLUTION);   // clockwise
  delay(100);
  myStepper.step(-STEPS_PER_REVOLUTION);  // counter-clockwise
  delay(1000);
}
