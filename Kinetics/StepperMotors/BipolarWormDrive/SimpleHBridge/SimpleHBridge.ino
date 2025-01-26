/*

  StepperMotors/BipolarCDTrayDrive/SimpleHBridge
  Testing some linear/worm-drive stepper motors salvaged from a DVD drive unit, using a bespoke H-bridge circuit and Arduino .. or pushbuttons!

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/StepperMotors/BipolarCDTrayDrive/SimpleHBridge

 */

#include <Stepper.h>

const int SPEED_RPM            = 300;
const int STEPS_PER_REVOLUTION = 20;
const int PIN_A = 8;
const int PIN_B = 9;
const int PIN_C = 10;
const int PIN_D = 11;

const int REVOLUTIONS_EACH_DIRACTION = 4;
const int DELAY_PER_ACTION_MS = 500;

Stepper myStepper(STEPS_PER_REVOLUTION, PIN_A, PIN_B, PIN_C, PIN_D);

void setup() {
  myStepper.setSpeed(SPEED_RPM);
}

void loop() {
  for (int i=0; i<REVOLUTIONS_EACH_DIRACTION; ++i) {
    myStepper.step(STEPS_PER_REVOLUTION);
    delay(DELAY_PER_ACTION_MS);
  }
  for (int i=0; i<REVOLUTIONS_EACH_DIRACTION; ++i) {
    myStepper.step(-STEPS_PER_REVOLUTION);
    delay(DELAY_PER_ACTION_MS);
  }
}
