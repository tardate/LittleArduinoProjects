/*
  JoystickServoControl
  Control two servos with a joystick.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/JoystickServoControl

 */

#include <Servo.h>

#define SERVO_LEFT_PIN 10
#define SERVO_RIGHT_PIN 9

#define CONTROL_LEFT_PIN 0
#define CONTROL_RIGHT_PIN 1

// delay in milliseconds between each servo command
#define STEP_DELAY 10

// custom min/max pulse width settings that best suit my servos
// NB: default vaules are min pulse width=544, max pulse width=2400
#define IDEAL_MIN_PW 600
#define IDEAL_MAX_PW 2320


Servo servo_left;
Servo servo_right;

void setup() {
  servo_left.attach(SERVO_LEFT_PIN,IDEAL_MIN_PW,IDEAL_MAX_PW);
  servo_right.attach(SERVO_RIGHT_PIN,IDEAL_MIN_PW,IDEAL_MAX_PW);
}


void loop() {
  int left_reading = analogRead(CONTROL_LEFT_PIN);
  int right_reading = analogRead(CONTROL_RIGHT_PIN);

  servo_left.write( map(left_reading, 0, 1023, 0, 180) );
  servo_right.write( map(right_reading, 0, 1023, 0, 180) );

  delay(STEP_DELAY);

}


