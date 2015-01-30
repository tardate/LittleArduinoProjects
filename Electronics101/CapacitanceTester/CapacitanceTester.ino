/*

  CapacitanceTester
  Capacitor tester with LCD output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/CapacitanceTester

 */

#include <LiquidCrystal.h>

#define r1      4660    // actual resistance of R1, in ohms
#define vref_mv 4930    // actual reference voltage of the board, in mV

#define vtrigger_mv      vref_mv * 63.2 / 100.0
#define vtrigger_level   vtrigger_mv / vref_mv * 1023

const int read_charge_pin = A0;
const int charge_pin = 2;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 7, 9, 10, 11, 12);

void setup() {
  pinMode(read_charge_pin, INPUT);          // enable Vout read
  pinMode(charge_pin, OUTPUT);          // enable the charge/discharge pin

  lcd.begin(16, 2); // set up the LCD's number of columns and rows
}

void loop() {
  dischargeCompletely();
  measureCapacitance();
  delay(5000);
}

void dischargeCompletely() {
  setDischarging();
  while(analogRead(read_charge_pin) > 0) {}
  setDischarged();
}

void measureCapacitance() {
  unsigned long startTime;
  unsigned long elapsedTime;
  float capacitance;
  char capStr[10];

  digitalWrite(charge_pin, HIGH);
  startTime = millis();
  while(analogRead(read_charge_pin) < vtrigger_level) {}
  elapsedTime = millis() - startTime;
  digitalWrite(charge_pin, LOW);

  lcd.clear();
  lcd.print("test complete:");
  lcd.setCursor(0, 1);

  capacitance = ((float)elapsedTime / r1) * 1000.0; //mF
  if(capacitance>1) { //mF
    dtostrf(capacitance, 4, 3, capStr);
    lcd.print(capStr);
    lcd.print("uF");
  } else {
    dtostrf(capacitance * 1000, 4, 3, capStr);
    lcd.print(capStr);
    lcd.print("nF");
  }


}

void setDischarging() {
  digitalWrite(charge_pin, LOW);
  lcd.clear();
  lcd.print("discharging...");
}

void setDischarged() {
  lcd.clear();
  lcd.print("discharged.");
}

void setTesting() {
  lcd.clear();
  lcd.print("testing...");
}
