/*
  ATtiny/At8MHz

  Toggles LEDs connected to GPIO pin 0 and 1 roughly once every 4 seconds
  - load this on an ATtiny with default 8MHz internal clock with /8 prescaler and LEDs will toggle every 4 seconds
  - reset fuses for 8MHz internal clock with no prescaler and LEDs will toggle every half a second

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ATtiny/At8MHz
 */

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop() {
  for(byte led=0; led < 2; led++) {
    digitalWrite(led, HIGH);
    digitalWrite(!led, LOW);
    delay(4000);
  }
}
