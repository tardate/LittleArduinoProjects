/*

  UsingSoftwareServo
  NB: this doesn't work properly

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kinetics/ServoMotors/ATTinyServo

 */

#include <SoftwareServo.h>

static const int SERVO_PIN = 4; // PB4, pin 3 on the DIP8 ATTiny85
static const int SERVO_UPDATE_DELAY = 10;

SoftwareServo myservo;  // creates name “my servo” as object to control a servo


void setup() {
  myservo.attach(SERVO_PIN);
}


void loop() {
  int start_angle = 0;
  int end_angle = 180;

  for(int pos = start_angle; pos <= end_angle; pos += 1)  {
    stepTo(pos);
  }
  for(int pos = end_angle; pos>=start_angle; pos-=1) {
    stepTo(pos);
  }
}

void stepTo(int pos) {
  myservo.write(pos);
  delay(SERVO_UPDATE_DELAY);
  SoftwareServo::refresh();
}
