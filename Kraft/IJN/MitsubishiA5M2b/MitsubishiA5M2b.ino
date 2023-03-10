/*

  IJN/MitsubishiA5M2b
  Building the Wingsey Kits A5M2b in-flight for the 2023 Model Offiers Mess birthday bash raising money and awareness for the Models for Heroes charity

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kraft/IJN/MitsubishiA5M2b

 */

#include "flame.h"
#include "pwm_motor.h"

Flame flame1;
Flame flame2;
PwmMotor motor;

const int FLAME1_PIN = 1; // ATtiny85 DIP8: PB1, pin 6
const int FLAME2_PIN = 4; // ATtiny85 DIP8: PB4, pin 3
const int PWM_OUT_PIN = 0; // ATtiny85 DIP8: PB0, pin 5
const int PWM_LEVEL_PIN = A1; // ATtiny85 DIP8: pin 7

/*
 * Command: one-time setup
 */
void setup() {
  motor.setup(PWM_OUT_PIN, PWM_LEVEL_PIN);
  flame1.setup(FLAME1_PIN, 50, 30);
  flame2.setup(FLAME2_PIN, 30, 30);
}

/*
 * Command: main loop
 */
void loop() {
  motor.update();
  flame1.flicker();
  flame2.flicker();
}
