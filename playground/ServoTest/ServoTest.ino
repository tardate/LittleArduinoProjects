/*
  ServoTest
  Test the positioning accuracy of a servo motor.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ServoTest

 */

#include <Servo.h>

#define SERVO_PIN 9
#define STEP_DELAY 1000

Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
  centerServo();
}

void loop() {
  stepAroundCompass();
}

void centerServo() {
  myservo.write(90);
  delay(STEP_DELAY * 4);
}

void stepAroundCompass() {
  for(int step=0; step < 5; step++) {
    myservo.write(step * 45);
    delay(STEP_DELAY);
  }
  delay(STEP_DELAY * 3);
}
