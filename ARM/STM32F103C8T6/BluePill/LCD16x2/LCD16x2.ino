/*
 * Program to test 16*2 Alaphanumeric LCD with STM32 (Blue Pill) 
 *
 * The circuit:
 * LCD RS pin to digital pin PB11
 * LCD Enable pin to digital pin PB10
 * LCD D4 pin to digital pin PB0
 * LCD D5 pin to digital pin PB1
 * LCD D6 pin to digital pin PC13
 * LCD D7 pin to digital pin PC14
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/

#include <LiquidCrystal.h> // include the LCD library

const int rs = PB11, en = PB10, d4 = PB0, d5 = PB1, d6 = PC13, d7 = PC14;     //mention the pin names to with LCD is connected to 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    //Initialize the LCD

void setup() {
  lcd.begin(16, 2);                   //We are using a 16*2 LCD
  lcd.setCursor(0, 0);                //At first row first column 
  lcd.print("Interfacing LCD");       //Print this
  lcd.setCursor(0, 1);                //At secound row first column 
  lcd.print("-Starting up");        //Print this
  
  delay(2000);    //wait for two seconds 
  lcd.clear();    //Clear the screen
}

void loop() {
  lcd.setCursor(0, 0); //At first row first column 
  lcd.print("STM32 -Blue Pill"); //Print this

  lcd.setCursor(0, 1); //At secound row first column 
  lcd.print(millis() / 1000); //Print the value of secounds
}
