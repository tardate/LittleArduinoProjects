/*

  SwitchModePowerSupplies/MC34063/BuckConverter
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/SwitchModePowerSupplies/MC34063/BuckConverter

 */

const int LED_PIN = 13;


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
  static boolean output = HIGH;

  digitalWrite(LED_PIN, output);
  delay(500);

  output = !output;
}

