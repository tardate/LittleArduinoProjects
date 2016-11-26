/*
  TinyBlink

  Toggles LEDs connected to GPIO pin 0 and 1

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/TinyBlink
 */

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop() {
  for(byte led=0; led < 2; led++) {
    digitalWrite(led, HIGH);
    digitalWrite(!led, LOW);
    delay(400);
  }
}
