/*

  CapacitanceTester
  Capacitor tester with LCD output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/CapacitanceTester

 */

#include <LiquidCrystal.h>

#define rt1     21600   // actual resistance of RT1, in ohms. 22k is decent choice for caps 10nF - 330uF, 4.7k is better for caps > 330uF
#define vref_mv 4930    // actual reference voltage of the board, in mV

#define vtrigger_mv      vref_mv * 63.2 / 100.0        // precalculate the 63.2% voltage
#define vtrigger_level   vtrigger_mv / vref_mv * 1023  // scale vtrigger_mv to the expected analog reading

const int read_charge_pin = A0;
const int charge_pin = 2;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 7, 9, 10, 11, 12);

void setup() {
  pinMode(read_charge_pin, INPUT);      // enable charge voltage reading
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
  delay(300); // extra shake
  setDischarged();
}

void measureCapacitance() {
  unsigned long startTime;
  unsigned long elapsedTime;
  float capacitance;
  char capStr[10];

  setTesting();

  digitalWrite(charge_pin, HIGH);
  startTime = micros();
  while(analogRead(read_charge_pin) < vtrigger_level) {}
  elapsedTime = micros() - startTime;
  digitalWrite(charge_pin, LOW);

  lcd.clear();
  lcd.print("test complete:");
  lcd.setCursor(0, 1);

  capacitance = ((float)elapsedTime / rt1); // uF
  if(capacitance>1) { //uF
    dtostrf(capacitance, 4, 3, capStr);
    lcd.print(capStr);
    lcd.print("uF");
  } else { // scale to nF
    dtostrf(capacitance * 1000.0, 4, 3, capStr);
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
