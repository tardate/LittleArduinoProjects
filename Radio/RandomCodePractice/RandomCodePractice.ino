/*

  RandomCodePractice
  A revised and enhanced version of "Random_charset_Oscillator.ino" by Glen Popiel, KW5GP

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Radio/RandomcharsetPractice

  Original copyright:

  Author Glen Popiel, KW5GP

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

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Morse.h"

const int LCD_COLUMNS = 16; // set width of LCD
const int LCD_ADDRESS = 0x3F; // I2C LCD Address
const int LCD_ROWS = 2; // Number of lines on LCD

const int BEEP_PIN = 11; // Pin for CW tone
const int SPEED_PIN = A0; // Pin for speed pot
const int CHAR_SELECT_PIN = A1; // Pin for char mode selector

const int MIN_WPM = 5; // minimum speed in WPM
const int MAX_WPM = 35; // maximum speed in WPM

const int HISTORY_ROW = 0; // which row of the LCD to display the character history
const int STATUS_ROW = 1; // which row of the LCD to display the status (speed, current char, morse representation)
const bool SCROLL_LEFT_TO_RIGHT = false; // sets the direction of the history scrolling

char charset[41];  // The array to hold the CW Alphabet 0-9,-./A-Z

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

int cw_speed_wpm = 15;  // initial CW Speed
Morse morse(BEEP_PIN, cw_speed_wpm, 1);

/*
 * Command: initialises the global charset array with all the characters
 * that will be used in code generation (0-9 , . / ? A-Z)
 */
void initCharset() {
  for (int x = 0 ; x<14 ; x++) {
    // 0-9,-./
    charset[x] = char(44 + x);
  }

  for (int x = 14 ; x<40 ; x++) {
    // A-Z
    charset[x] = char(51+x);
  }

  charset[40] = char(63);  // add ? character
}

/*
 * Command: one-time setup
 */
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.home();  // Set the cursor to line 0, column 0

  initCharset();

  // Seed the Random Number Generator
  randomSeed(analogRead(3));

  delay(250);
}

/*
 * Command: read the current state of the speed selector
 * and adjust the Morse speed accordingly
 */
void updateSpeed() {
  cw_speed_wpm = map(analogRead(SPEED_PIN), 0, 1023, MIN_WPM, MAX_WPM);
  morse.setSpeed(cw_speed_wpm);
  lcd.setCursor(10, STATUS_ROW);
  if (cw_speed_wpm < 10) {
    lcd.print(F(" "));
  }
  lcd.print(cw_speed_wpm);
  lcd.print(F(" WPM"));
}

/*
 * Returns: a random character, selected on the basis of the
 * current state of the charater select switch
 */
char pickCharacter() {
  int charMode = analogRead(CHAR_SELECT_PIN);
  int index;

  if (charMode < 300) {
    // pick numbers only
    index = 4 + char(random(10));
  } else if (charMode > 600) {
    // pick alpha only
    index = 14 + char(random(26));
  } else {
    // pick any
    index = char(random(41));
  }

  return charset[index];
}

/*
 * Command: main loop
 */
void loop() {
  static String history = "";  // holds LCD scrolling text
  static char morse_code[8];   // holds the dit-dah representation of the current character

  updateSpeed();

  char c = pickCharacter();

  // display the history
  if (SCROLL_LEFT_TO_RIGHT) {
    if (history.length() >15) history = history.substring(1, 16);
    history = history + String(c);
  } else {
    if (history.length() >15) history = history.substring(0, 15);
    history = String(c) + history;
  }
  lcd.setCursor(0, HISTORY_ROW);
  lcd.print(history);

  // display the status line and play the morse code
  morse.getCode(c, morse_code, sizeof(morse_code));
  lcd.setCursor(0, STATUS_ROW);
  lcd.print(c);
  lcd.setCursor(2, STATUS_ROW);
  lcd.print(morse_code);
  morse.send(c);
}
