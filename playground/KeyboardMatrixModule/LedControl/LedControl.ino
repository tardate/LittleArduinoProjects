/*

  KeyboardMatrixModule/LedControl
  Demo controlling the LEDs on a simple pushbutton/LED matrix module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/KeyboardMatrixModule/LedControl

 */

const int START_PIN=2;
const int LED_COUNT=8;
const int DELAY=500;

void setup() {
  // set the pins as output HIGH (off) by default
  for(int pin = START_PIN; pin < START_PIN + LED_COUNT; ++pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void loop() {
  for(int pin = START_PIN; pin < START_PIN + LED_COUNT; ++pin) {
    digitalWrite(pin, LOW);
    delay(DELAY);
    digitalWrite(pin, HIGH);
  }
}
