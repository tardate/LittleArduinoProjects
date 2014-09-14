/*
  X113647Stepper.cpp - X113647 Stepper Moter Driver Board library for Arduino

  Drives a 1-2 phase 5-Wire stepper motor using 4 wires via an X113647 (ULN2003-based) driver board

  See http://www.geeetech.com/wiki/index.php/Stepper_Motor_5V_4-Phase_5-Wire_%26_ULN2003_Driver_Board_for_Arduino
  for a description of the hardware involved.

  The clockwise sequence of control signals for 4 control wires is as follows:

  Step IN1 IN2 IN3 IN4
    0   0   0   0   1
    1   0   0   1   1
    2   0   0   1   0
    3   0   1   1   0
    4   0   1   0   0
    5   1   1   0   0
    6   1   0   0   0
    7   1   0   0   1


  This library is derived from the Arduino Stepper library http://www.arduino.cc/en/Tutorial/Stepper

*/

// ensure this library description is only included once
#ifndef X113647Stepper_h
#define X113647Stepper_h

// library interface description
class X113647Stepper {
  public:
    // constructors:
    X113647Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);
    X113647Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4, int step_mode );

    // speed setter method:
    void setSpeed(float whatSpeed);

    // mover method:
    void step(int number_of_steps);

    int version(void);

  private:
    void ignition();
    void stepMotor(int this_step);

    unsigned long step_delay;    // delay between steps, in ms, based on speed
    int minimum_delay;           // minimum delay between steps
    int number_of_steps;         // total number of steps this motor can take
    int step_mode;               // number of phases being used to drive the motor
    int steps_per_cycle;         // number of steps per revolution (before gearing)
    int signals_per_step;        // number of signals per step. when full step == 1, when half-step == 2
    int step_number;             // which step the motor is on

    // motor pin numbers:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;

    int step_codes[8];

};

#endif

