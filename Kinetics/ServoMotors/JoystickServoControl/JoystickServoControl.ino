/*
  JoystickServoControl
  Control two servos with a joystick.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Kinetics/ServoMotors/JoystickServoControl

 */

#include <Servo.h>

static const int SERVO_LEFT_PIN    = 10;
static const int SERVO_RIGHT_PIN   = 9;
static const int CONTROL_LEFT_PIN  = 0;
static const int CONTROL_RIGHT_PIN = 1;

// delay in milliseconds between each servo command
static const int STEP_DELAY = 10;

// custom min/max pulse width settings that best suit my servos
// the pulse width, in microseconds, corresponding to the minimum (0 degree) angle on the servo (defaults to 544)
static const int IDEAL_MIN_PW = 600;
// the pulse width, in microseconds, corresponding to the maximum (180 degree) angle on the servo (defaults to 2400)
static const int IDEAL_MAX_PW = 2320;

Servo servo_left;
Servo servo_right;


void setup() {
  servo_left.attach(SERVO_LEFT_PIN, IDEAL_MIN_PW, IDEAL_MAX_PW);
  servo_right.attach(SERVO_RIGHT_PIN, IDEAL_MIN_PW, IDEAL_MAX_PW);
}


void loop() {
  int left_reading = analogRead(CONTROL_LEFT_PIN);
  int right_reading = analogRead(CONTROL_RIGHT_PIN);

  servo_left.write( map(left_reading, 0, 1023, 0, 180) );
  servo_right.write( map(right_reading, 0, 1023, 0, 180) );

  delay(STEP_DELAY);
}
