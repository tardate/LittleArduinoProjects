/*

  DigitalInputWithAnalogPins
  Demonstrate how analog pins can also be used as a digital GPIO

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/DigitalInputWithAnalogPins

 */

#define BUTTON_PIN (A5)
#define STEP_DELAY (400)

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  for(int analog_pin=A0; analog_pin<A5; analog_pin++) {
    pinMode(analog_pin, OUTPUT);
  }
}

void loop() {

  if (digitalRead(BUTTON_PIN)) {

    // cycle output on A0..A4 using mnemonic analog pin names
    for(int analog_pin=A0; analog_pin<A5; analog_pin++) {
      digitalWrite(analog_pin, HIGH);
      delay(STEP_DELAY);
      digitalWrite(analog_pin, LOW);
    }

  } else {

    // cycle output on A4..A0 using pin numbers
    for(int analog_pin=18; analog_pin>=14; analog_pin--) {
      digitalWrite(analog_pin, HIGH);
      delay(STEP_DELAY);
      digitalWrite(analog_pin, LOW);
    }

  }

}
