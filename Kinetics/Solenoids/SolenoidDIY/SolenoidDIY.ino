/*

  SolenoidDIY
  Test a DIY solenoid

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Kinetics/Solenoids/SolenoidDIY

 */

#define CONTROL_PIN 6
#define SOLENOID_ON_DURATION 150

const int sequence[] = {
  1000,
  1000,
  500,
  500,
};

void setup() {
  pinMode(CONTROL_PIN, OUTPUT);
}

void loop() {
  runSequence();
}

void runSequence() {
  for(int step=0; step < sizeof(sequence) / sizeof(int); step++) {
    digitalWrite(CONTROL_PIN, HIGH);
    delay(SOLENOID_ON_DURATION);
    digitalWrite(CONTROL_PIN, LOW);
    delay(sequence[step]);
  }
}
