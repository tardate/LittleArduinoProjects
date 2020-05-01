/*

  STM32F103C8T6/48pinDevBoard
  Simplest example possible: programming a 48 pin ARM Cortex-M3 STM32F103C8T6 board with the Arduino IDE

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/STM32/STM32F103C8T6/48pinDevBoard

 */

const int LED_PIN=PC13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  static boolean output = HIGH;

  digitalWrite(LED_PIN, output);

  if (output) {
    delay(400);
  } else {
    delay(600);
  }

  output = !output;
}
