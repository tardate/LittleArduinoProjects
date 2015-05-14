/*
  TinyBlink
  
  Toggles LEDs connected to pin 0 and 1
  
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
