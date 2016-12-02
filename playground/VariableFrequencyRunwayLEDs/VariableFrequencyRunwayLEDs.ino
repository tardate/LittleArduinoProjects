/*

  VariableFrequencyRunwayLEDs
  A PWM-controlled variable frequency LED "runway lights" effect using the LM331 and CD4011

  This sketch demonstrates frequency control using a single PWM output.
  The LED clock frequencies mentioned below are those achieved on a breadboard build
  with oscilloscope attached .. YMMV

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/VariableFrequencyRunwayLEDs

 */

const int DRIVER_PIN = 10;
const int STEP_DELAY = 5000;

void setup() {
  pinMode(DRIVER_PIN, OUTPUT);
}

void loop() {
  analogWrite(DRIVER_PIN,   5); // about 2Hz
  delay(STEP_DELAY);

  analogWrite(DRIVER_PIN,  25); // about 4Hz
  delay(STEP_DELAY);

  analogWrite(DRIVER_PIN, 155); // about 6Hz
  delay(STEP_DELAY);

  analogWrite(DRIVER_PIN, 255); // about 8Hz
  delay(STEP_DELAY);
}
