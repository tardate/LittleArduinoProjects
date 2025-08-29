/*

  SwitchPJFET
  Switch an independent power source using an Arduino and p-channel JFET

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/SwitchPJFET

 */

#define CONTROL_PIN 6

void setup() {
  pinMode(CONTROL_PIN, OUTPUT);
}

void loop() {
  for(int duration = 1; duration <= 1024; duration = duration * 2 ) {
    digitalWrite(CONTROL_PIN, HIGH);
    delay(duration);
    digitalWrite(CONTROL_PIN, LOW);
    delay(duration);
  }
}
