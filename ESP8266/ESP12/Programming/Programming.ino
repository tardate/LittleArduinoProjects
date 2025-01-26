/*

  ESP12/Programming
  The basics of programming an ESP-12 with the ESP8266 core for Arduino

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/ESP8266/ESP12/Programming

 */

const int PINS[] = {
  2,
  4,
  5,
  12,
  14,
  16
};

const int PIN_COUNT = 6;

const int BUTTON_PIN = 13;

const int DEBOUNCE_DELAY = 150;

int current_pin_index = 0;

/*
 * Command: one-time setup
 */
void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  for(int pin = 0 ; pin < PIN_COUNT; ++pin) {
    pinMode(PINS[pin], OUTPUT);
    digitalWrite(PINS[pin], LOW);
  }
  digitalWrite(PINS[current_pin_index], HIGH);
}


/*
 * Command: main loop
 */
void loop() {
  if(digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(PINS[current_pin_index], LOW);
    ++current_pin_index;
    if (current_pin_index == PIN_COUNT) {
      current_pin_index = 0;
    }
    digitalWrite(PINS[current_pin_index], HIGH);
    delay(DEBOUNCE_DELAY);
  }
}
