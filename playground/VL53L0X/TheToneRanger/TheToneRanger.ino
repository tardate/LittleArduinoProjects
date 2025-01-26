/*

  VL53L0X/TheToneRanger
  A simple modification of the basic VL53L0X example to add audio indication of range.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/VL53L0X/TheToneRanger

 */

#include <Adafruit_VL53L0X.h>

const int TONE_PIN = 8;
const int STEP_DELAY = 100;
const int PEAK_FREQUENCY = 1500;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(9600);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Robojax Test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power
  Serial.println(F("VL53L0X API Simple Ranging example"));
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
    tone(TONE_PIN, PEAK_FREQUENCY - 2 * measure.RangeMilliMeter, STEP_DELAY);
  } else {
    Serial.println(" out of range ");
  }

  delay(STEP_DELAY);
}
