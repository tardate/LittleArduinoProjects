/*

  SolenoidControl
  Controlling a mini solenoid with an Arduino

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/SolenoidControl

 */

#define SOLENOID_PIN 6
#define ON_TIME 500
#define OFF_DELAY 2000

void setup() {
  pinMode(SOLENOID_PIN, OUTPUT);
}

void loop() {
  digitalWrite(SOLENOID_PIN, HIGH);
  delay(ON_TIME);
  digitalWrite(SOLENOID_PIN, LOW);
  delay(OFF_DELAY);
}
