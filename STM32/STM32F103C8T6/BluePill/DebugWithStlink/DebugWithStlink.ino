/*

  STM32F103C8T6/BluePill/DebugWithStlink
  A simple sketch for testing gdb and stlink debugging techniques.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/STM32/STM32F103C8T6/BluePill/DebugWithStlink

 */

const int LED_PIN = PC13;
const int BASE_FREQ = 100;
int global_counter = 1;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  static boolean output = LOW;
  output = !output;

  if (global_counter > 10) {
    global_counter = 1;
  } else {
    ++global_counter;
  }

  digitalWrite(LED_PIN, output);
  if (output) {
    delay(BASE_FREQ * global_counter);
  } else {
    delay(BASE_FREQ * global_counter);
  }
}
