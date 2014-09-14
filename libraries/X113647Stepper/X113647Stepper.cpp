/*
  X113647Stepper.cpp - X113647 Stepper Moter Driver Board library for Arduino
  See X113647Stepper.h for notes

 */


#include "Arduino.h"
#include "X113647Stepper.h"

/*
 *   constructor for defualt single-phase operation
 *   Sets the number of steps per revolution and which pins should control the motor.
 */

X113647Stepper::X113647Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
{

  this->number_of_steps = number_of_steps;
  this->step_mode = 1;

  // Arduino pins for the motor control connection:
  this->motor_pin_1 = motor_pin_1;
  this->motor_pin_2 = motor_pin_2;
  this->motor_pin_3 = motor_pin_3;
  this->motor_pin_4 = motor_pin_4;

  ignition();

}

/*
 *   constructor with step mode specification
 *   Sets the number of steps per revolution, stepping mode and which pins should control the motor.
 */

X113647Stepper::X113647Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4, int step_mode)
{

  this->number_of_steps = number_of_steps;
  this->step_mode = step_mode;

  // Arduino pins for the motor control connection:
  this->motor_pin_1 = motor_pin_1;
  this->motor_pin_2 = motor_pin_2;
  this->motor_pin_3 = motor_pin_3;
  this->motor_pin_4 = motor_pin_4;

  ignition();

}

/*
  Common (private) method to initialise stepper output

*/
void X113647Stepper::ignition()
{
  // common instance variable initialisation
  this->step_number = 0;

  // Encode the the clockwise sequence of control signals:
  switch(this->step_mode) {
  case 1:
    this->steps_per_cycle = 4;
    this->step_codes[0] = B00001;
    this->step_codes[1] = B00010;
    this->step_codes[2] = B00100;
    this->step_codes[3] = B01000;
    break;
  case 2:
    this->steps_per_cycle = 4;
    this->step_codes[0] = B00011;
    this->step_codes[1] = B00110;
    this->step_codes[2] = B01100;
    this->step_codes[3] = B01001;
    break;
  case 3:
    this->steps_per_cycle = 8;
    this->step_codes[0] = B00001;
    this->step_codes[1] = B00011;
    this->step_codes[2] = B00010;
    this->step_codes[3] = B00110;
    this->step_codes[4] = B00100;
    this->step_codes[5] = B01100;
    this->step_codes[6] = B01000;
    this->step_codes[7] = B01001;
    break;
  }
  this->signals_per_step = this->steps_per_cycle / 4;
  this->minimum_delay = this->signals_per_step + 1;

  // setup the pins on the microcontroller:
  pinMode(this->motor_pin_1, OUTPUT);
  pinMode(this->motor_pin_2, OUTPUT);
  pinMode(this->motor_pin_3, OUTPUT);
  pinMode(this->motor_pin_4, OUTPUT);

  // set a default speed 1rpm
  setSpeed(1);
}

/*
  Sets the speed in revs per minute

*/
void X113647Stepper::setSpeed(float whatSpeed)
{
  this->step_delay = 60L * 1000L / this->number_of_steps / whatSpeed / this->signals_per_step;
  if(this->step_delay < this->minimum_delay) this->step_delay = this->minimum_delay;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative,
   the motor moves in the reverse direction.
 */
void X113647Stepper::step(int steps_to_move)
{
  int steps_remaining = abs(steps_to_move) * this->signals_per_step;  // how many steps to take

  // determine direction based on whether steps_to_move is + or -:
  int direction = 1;                    // Direction of rotation: default forward
  if (steps_to_move < 0) direction = 0; // reverse

  long last_step_time = 0;         // time stamp in ms of when the last step was taken

  // decrement the number of steps, moving one step each time:
  while(steps_remaining > 0) {

    // move only if the appropriate delay has passed:
    if (millis() >= last_step_time + this->step_delay) {

      // get the timeStamp of when you stepped:
      last_step_time = millis();

      // increment or decrement the step number,
      // depending on direction:
      if (direction == 1) {
        this->step_number++;
        if (this->step_number == this->number_of_steps) {
          this->step_number = 0;
        }
      }
      else {
        if (this->step_number == 0) {
          this->step_number = this->number_of_steps;
        }
        this->step_number--;
      }
      // decrement the steps remaining:
      steps_remaining--;
      // step the motor to step number 0..7:
      stepMotor(this->step_number % this->steps_per_cycle);
    }
  }
  // clear signals
  digitalWrite(motor_pin_1, LOW);
  digitalWrite(motor_pin_2, LOW);
  digitalWrite(motor_pin_3, LOW);
  digitalWrite(motor_pin_4, LOW);
}

/*
 * Moves the motor forward or backwards.
 */
void X113647Stepper::stepMotor(int thisStep)
{
  digitalWrite(motor_pin_1, bitRead(this->step_codes[thisStep], 0));
  digitalWrite(motor_pin_2, bitRead(this->step_codes[thisStep], 1));
  digitalWrite(motor_pin_3, bitRead(this->step_codes[thisStep], 2));
  digitalWrite(motor_pin_4, bitRead(this->step_codes[thisStep], 3));
}

/*
  version() returns the version of the library:
*/
int X113647Stepper::version(void)
{
  return 1;
}
