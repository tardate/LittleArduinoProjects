/*

  TydiriumStrobe
  Figuring out the navigation light strobe frequency of the Lambda-class shuttle "Tydirium" and
  building a freeform circuit sculpture to demonstrate the effects (running an ATtiny85 on 3V)

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kraft/TydiriumStrobe

 */

const int LED_PIN = 0;

/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

/*
 * Command: main loop
 */
void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(1500);
}
