/*

  SingleShift
  Drive a 4-Digit 7-Segment display with a 74HC595 shift register and 4 NPN BJTs.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/Led4Digit7Segment/SingleShift

 */

// use timer for scheduling the display update
#include <FlexiTimer2.h>

// define pins for the shift register control
#define ST_CP_LATCH_PIN 4
#define SH_CP_CLOCK_PIN 5
#define DS_DATA_PIN 3

// define pins for the BJT control
#define DIGIT_BASE_PIN 6
#define DIGITS 4

// define the bitmasks for characters 0-9
byte LCD_DIGIT_MASK[] = {
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111
};

volatile int number_for_display = 0;   // the number we'll display on the LED unit
volatile byte current_digit = 0;       // 0-3 left to right

void setup() {
  Serial.begin(9600); 
  pinMode(ST_CP_LATCH_PIN, OUTPUT);
  pinMode(SH_CP_CLOCK_PIN, OUTPUT);
  pinMode(DS_DATA_PIN, OUTPUT);
  for(int p=0; p<DIGITS; p++) {
    pinMode(DIGIT_BASE_PIN + p, OUTPUT);
  }

  FlexiTimer2::set(5, redrawLedDisplay); // update an LED character every 5ms
  FlexiTimer2::start();
}

void loop() {
  // increment a number every little while
  delay(100);
  if(number_for_display<9999) number_for_display += 1;
  else number_for_display = 0;
}


void redrawLedDisplay() {
  // stop glowing the current digit and move to the next
  digitalWrite(DIGIT_BASE_PIN + current_digit, LOW);
  current_digit++;
  if(current_digit>3) current_digit = 0;

  // do some gymnastics to figure out which number to display for this digit
  int digit_scale = 1;
  for(byte s=3; s>current_digit; s--) digit_scale = digit_scale * 10;
  byte digit_value = (number_for_display / digit_scale) % 10;

  // push the digit to the LED display
  pushSegmentRegister(LCD_DIGIT_MASK[digit_value]);
  digitalWrite(DIGIT_BASE_PIN + current_digit, HIGH);
}

// Command: send +data+ byte to the 74HC595 shift register
void pushSegmentRegister(byte data) {
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}
