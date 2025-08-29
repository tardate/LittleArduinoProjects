/*

  BetterWithBacon
  This sketch prints message with the time.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/BetterWithBacon

 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 7, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.print("It's better with");
  lcd.setCursor(0, 1); lcd.print("bacon!");
}

void loop() {
  lcd.setCursor(8, 1); // set the cursor to column 8, line 1 (second row)
  lcd.print(millis()/1000);  // print the number of seconds since reset:
}
