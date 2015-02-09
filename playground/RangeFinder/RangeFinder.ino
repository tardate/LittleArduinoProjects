/*

  RangeFinder
  Measure distance with HC-SR04 and print to LCD output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/RangeFinder

 */

#include <LiquidCrystal.h>

const int trigger_pin = 4;
const int echo_pin = 3;

LiquidCrystal lcd(6, 7, 9, 10, 11, 12); // set pins for LCD

//
// Define the distance in mm per microsecond
// Test distance = (high level time×velocity of sound (340M/S) / 2,
// Theoretically:
//       340.29 m / s = 0.34029 mm/us
// Divided by two (for the round trip) = 0.170145
//
// #define MM_PER_MICROSEC 0.170145
//
// In practice, the calibrated constant for my test scenario works out to around 0.186:
//
#define MM_PER_MICROSEC  0.186

void setup() {
  pinMode(trigger_pin, OUTPUT);         // enable HC-SR04 trigger pin
  pinMode(echo_pin, INPUT);             // enable HC-SR04 echo pin

  lcd.begin(16, 2);                     // setup the LCD's number of columns and rows
}

void loop() {
  takeRangeMeasurement();
  delay(1000);
}

void takeRangeMeasurement() {
  long range = 0;
  setMeasuring();
  range = rangeTime() * MM_PER_MICROSEC;
  lcd.setCursor(0, 1);
  lcd.print(range);
  lcd.print(" mm");
}

// Command: trigger range measurement, returns high level time un microseconds
long rangeTime() {
  // send trigger signal
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  // read echo response
  return pulseIn(echo_pin,HIGH);
}

void setMeasuring() {
  lcd.clear();
  lcd.print("measuring...");
}

