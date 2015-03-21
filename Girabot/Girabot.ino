/*
  Girabot

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Girabot

 */

#include <Servo.h>

#define SERVO_PIN 9


#define STEP_DELAY 500
#define WALK_LR_OFFSET 30
#define WALK_LEFT 90 - WALK_LR_OFFSET
#define WALK_RIGHT 90 + WALK_LR_OFFSET


Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
  centerServo();
}

void loop() {
  delay(1000);

  for( int i=0; i<10; i++) {
    walk();
  }
}

void centerServo() {
  myservo.write(90);
}

void walk() {

  myservo.write(WALK_LEFT);
  delay(STEP_DELAY);
  myservo.write(WALK_RIGHT);
  delay(STEP_DELAY);
}
