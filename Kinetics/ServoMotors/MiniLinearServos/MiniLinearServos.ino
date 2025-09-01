/*

  ServoMotors/MiniLinearServos
  Testing some mini/micro linear servo motors with an ATtiny85

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Kinetics/ServoMotors/MiniLinearServos

 */

#include <SoftwareServo.h>

static const int SERVO_PIN = 4; // PB4, pin 3 on the DIP8 ATTiny85
static const int SERVO_UPDATE_DELAY = 10;

SoftwareServo myServo;


void setup() {
  myServo.attach(SERVO_PIN);
  myServo.setMinimumPulse(832);

}

void loop() {
  int start_angle = 0;
  int end_angle = 180;

  for(int pos = start_angle; pos <= end_angle; pos += 1) {
    stepTo(pos);
  }
  delay(3000);
  for(int pos = end_angle; pos >= start_angle; pos -= 1) {
    stepTo(pos);
  }
  delay(3000);

}

void stepTo(int pos) {
  myServo.write(pos);
  delay(SERVO_UPDATE_DELAY);
  SoftwareServo::refresh();
}
