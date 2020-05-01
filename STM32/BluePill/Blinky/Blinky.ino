/*

  Blinky
  Simplest example possible: programming an ARM Cortex-M3 STM32F103C8T6 Blue Pill board with the Arduino IDE

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/STM32/BluePill/Blinky

 */

const int LED_PIN=PC13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  static boolean output = HIGH;

  digitalWrite(LED_PIN, output);
  delay(500);

  output = !output;
}
