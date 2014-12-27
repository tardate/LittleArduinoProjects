/*

  BetterWithBacon

  This sketch prints message with the time.

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  The circuit:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * 10K resistor:
  * ends to +5V and ground
  * wiper to LCD VO pin (pin 3)

  Based on example code in the public domain: http://www.arduino.cc/en/Tutorial/LiquidCrystal

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/BetterWithBacon

 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.print("It's better with");
  lcd.setCursor(0, 1); lcd.print("bacon!");
}

void loop() {
  lcd.setCursor(8, 1); // set the cursor to column 8, line 1 (second row)
  lcd.print(millis()/1000);  // print the number of seconds since reset:
}
