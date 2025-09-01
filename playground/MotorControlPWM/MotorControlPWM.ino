/*
  MotorControlPWM
  Tests PWM speed control of a DC motor.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/MotorControlPWM

 */

#define MOTOR_PIN 3
#define DURATION_AT_SPEED 1000

void setup() {
  Serial.begin(115200);
  // NB: You do not need to call pinMode() before calling analogWrite()
}

void loop() {
  rampUpTest(64);
}

void rampUpTest(int from_minimum) {
  for(int speed = from_minimum; speed < 256; speed +=16 ) {
    Serial.print("Pulse: ");
    Serial.println(speed);
    motorOn(speed);
  }
  motorOff();
}

void motorOff() {
  motorOn(0);
}

void motorOn(int value) {
  analogWrite(MOTOR_PIN, value);
  delay(DURATION_AT_SPEED);
}
