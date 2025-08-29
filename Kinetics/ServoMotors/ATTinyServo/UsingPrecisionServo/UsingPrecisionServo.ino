/*

  UsingPrecisionServo
  NB: this only works correctly if ATtiny set to use 1MHz internal clock (not 8Mhz)

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Kinetics/ServoMotors/ATTinyServo

 */

#include <ServoManager.h>

static const int SERVO_PIN = 4; // PB4, pin 3 on the DIP8 ATTiny85

PrecisionServo* servo;

void setup() {
  ServoManager::setup(1);

  servo = ServoManager::createServo(SERVO_PIN);
  servo->setSetting(SERVO_MEDIUM_ENDPOINT);
}

void loop() {
  servo->setTarget(0);
  ServoManager::waitUntilFinished();

  servo->setTarget(180);
  ServoManager::waitUntilFinished();
}
