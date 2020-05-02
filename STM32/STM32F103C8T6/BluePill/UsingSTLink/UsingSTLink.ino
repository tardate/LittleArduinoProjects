/*

  BluePill/UsingSTLink
  Simplest example possible: Programming an ARM Cortex-M3 STM32F103C8T6 Blue Pill with an ST Link v2 programmer and the Arduino IDE

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/STM32/STM32F103C8T6/BluePill/UsingSTLink

 */

const int LED_PIN = PC13;
const int BASE_FREQ = 100;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  static boolean output = HIGH;

  digitalWrite(LED_PIN, output);

  if (output) {
    delay(BASE_FREQ);
  } else {
    delay(BASE_FREQ * 3);
  }

  output = !output;
}
