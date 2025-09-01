/*
  Blink
  Turns on an LED on and off repeatedly

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/Blink
 */

#define LED_PIN 13  // pin 13 has an LED connected on most Arduino boards

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(200);
}
