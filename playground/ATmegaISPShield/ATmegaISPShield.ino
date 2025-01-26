/*
  ATmegaISPShield Test
  A variant of the standard Blink program to test a chip on the ISP Shield.
  After uploading the ArduinoISP sketch to the host Arduino,
  send this sketch via the Arduino using the "Upload using Programmer" option.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ATmegaISPShield
 */

#define ON_DURATION  200
#define OFF_DURATION ON_DURATION

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  flashOnPin(11);
  flashOnPin(12);
  flashOnPin(13);
}

void flashOnPin(int pin) {
  digitalWrite(pin, HIGH);
  delay(ON_DURATION);
  digitalWrite(pin, LOW);
  delay(OFF_DURATION);
}
