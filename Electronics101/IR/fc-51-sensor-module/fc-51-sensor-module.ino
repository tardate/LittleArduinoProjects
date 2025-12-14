/*

  FC-51 IR Obstacle Avoidance Sensor Module Demo

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/IR/fc-51-sensor-module

 */

const int LED_PIN = 13;
const int DETECTOR_PIN = 2;
const int DELAY = 100;
volatile bool detector_flag = HIGH;
bool detector_state = LOW;

/*
 * On detector trigger, set flag
 */
void detectorInterrupt() {
  detector_flag = HIGH;
}

/*
 * Return the current detector state. HIGH - obstacle detected, LOW - no obstacle
 * Reads new value if a change has been detected
 */
bool getDetectorState() {
  if (detector_flag) {
    detector_state = !digitalRead(DETECTOR_PIN);
    detector_flag = LOW;
  }
  return detector_state;
}

/*
 * Command: one-time setup
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(DETECTOR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(DETECTOR_PIN), detectorInterrupt, CHANGE);
}


/*
 * Command: main loop
 */
void loop() {
  digitalWrite(LED_PIN, getDetectorState());
  delay(DELAY);
}
