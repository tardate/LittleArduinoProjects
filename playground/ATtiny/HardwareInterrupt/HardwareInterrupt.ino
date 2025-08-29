/*

  HardwareInterrupt
  Test hardware interrupts with an ATtiny85 processor on a breadboard

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/ATtiny/HardwareInterrupt

 */

#define INTERRUPT 0 // digital pin 2 / ATtiny pin 7
#define LED_PIN 4

void setup() {
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(INTERRUPT, wakeyWakey, RISING);
}

volatile boolean perform_flag = false;

void loop() {
  if(perform_flag) perform();
}

void wakeyWakey() {
  perform_flag = true;
}

void perform() {
  for(int i=0; i<24; i++) flashLed();
  perform_flag = false;
}

void flashLed() {
  static boolean output = HIGH;
  digitalWrite(LED_PIN, output);
  delay(200);
  output = !output;
}
