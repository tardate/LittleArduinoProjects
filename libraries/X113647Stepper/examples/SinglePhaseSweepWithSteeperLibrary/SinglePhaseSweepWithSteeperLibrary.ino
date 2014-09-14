/*
  This program demonstrates using the standard Stepper library
  to drives a 2-Phase 5-Wire stepper motor (28YBT-48) using 4 wires
  via an ULN2003/X113647 driver board.

  The standard Stepper library does not drive the pins in the sequence
  required by the X113647 board, but we can get it to work
  by re-mapping the pins as follows:

  Step C0 C1 C2 C3  <= as driven by the Stepper library
     1  1  0  1  0
     2  0  1  1  0
     3  0  1  0  1
     4  1  0  0  1
  Pin: I4 I2 I1 I3  <= remapped to the X113647 inputs

  Re-ordering this by input pin, we can see we get a full step sequence:

  Pin: I1 I2 I3 I4
     1  1  0  0  1
     2  1  1  0  0
     3  0  1  1  0
     4  0  0  1  1
  Step C2 C1 C3 C0    <= as driven by the Stepper library

  So, if pins are connected to the board thus:

     Pin     Board   Param
      8   --  I1  --  C2
      9   --  I2  --  C1
      10  --  I3  --  C3
      11  --  I4  --  C0

  We should initialise the library like this:

    Stepper myStepper(stepsPerRevolution, 11, 9, 8, 10);

  The motor should revolve one revolution in one direction, then
  one revolution in the other direction.

 */

#include <Stepper.h>

// change this to fit the number of steps per revolution for your motor
const int stepsPerRevolution = 64 * 32;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 11, 9, 8, 10);

void setup() {
  // set the speed in rpm:
  myStepper.setSpeed(1);
}

void loop() {
  // step one revolution  in one direction:
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

