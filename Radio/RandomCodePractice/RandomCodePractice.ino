// Author Glen Popiel, KW5GP
/*

 This program is free software: you can redistribute it and/or modify
 it under the terms of the version 3 GNU General Public License as
 published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */

// Uses Morse Library - Author Erik Linder - errors corrected by Glen Popiel KW5GP

#include <Morse.h>   // Use the Morse Library
#include <Wire.h>    //I2C Library
#include <LiquidCrystal_I2C.h>  // Liquid Crystal I2C Library

const int lcd_end = 16; // set width of LCD
const int lcd_address = 0x27; // I2C LCD Address
const int lcd_lines = 2; // Number of lines on LCD
const int beep_pin = 11; // Pin for CW tone
const String spd = "Speed = ";
String text;  // Variable to hold LCD scrolling text
char c;  // The CW character to send
char Code[41];  // The array to hold the CW Alphabet 0-9,-./A-Z
int key_speed;  // CW Speed
int index; // variable to select CW character to send

LiquidCrystal_I2C lcd(lcd_address,lcd_end,lcd_lines);  // set the LCD I2C address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();  // initialize the LCD
  lcd.backlight();  // Turn on the LCD backlight
  lcd.home();  // Set the cursor to line 0, column 0

  // populate the array containing the characters to use (0-9 , . / ? A-Z)
  for (int x = 0 ; x<14 ; x++)  // 0-9,-.
  {
    Code[x] = char(44 + x);
  }


  for (int x = 14 ; x<40 ; x++)  // A-Z
  {
    Code[x] = char(51+x);
  }

  Code[40] = char(63);  // add ? character

  // randomize
  randomSeed(analogRead(1)); // Seed the Random Number Generator

  delay(3000);
  text = "";

}  // End Setup Loop

void loop()
{

 key_speed = map(analogRead(0),0,1023,5,35);  // Read the potentiometer to determine code speed
 Morse morse(beep_pin, key_speed, 1);  // Set the Code Library to Beep on Pin 11 at the selected Key Speed

 index = char(random(41));  // Randomly pick a character from the character array
 c = Code[index];  // Assign the value of the selected character to c

 lcd.setCursor(3,1);  // Display the CW Speed on Line 1
 lcd.print(spd);
 lcd.print(key_speed);
 lcd.print(" ");

  //  Assign the text to display on line 0.
  if (text.length() >15)  // When length = 15, trim and add to new character so display appears to scroll left
  {
    text = text.substring(1,16);  // Drop the First Character
  }

  text = text + String(char(toupper(c)));

  lcd.setCursor(0,0);  // Set the cursor to 0,0
  lcd.print(text);  // Display the CW text
  morse.send(c);  // Send the character in CW

}  // End Main Loop







