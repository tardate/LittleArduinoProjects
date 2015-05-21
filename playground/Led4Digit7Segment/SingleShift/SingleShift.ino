/*

  Simple4Digit7SegmentDisplay
  Drive a 4-Digit 7-Segment display with a 74HC595 shift register and 4 NPN BJTs.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/Simple4Digit7SegmentDisplay

 */

#define ST_CP_LATCH_PIN 4
#define SH_CP_CLOCK_PIN 5
#define DS_DATA_PIN 3
#define DIGIT_BASE_PIN 6
#define DIGITS 4

#define LCD_CLR 0b00000000
#define LCD_DP  0b10000000
#define LCD_0   0b00111111
#define LCD_1   0b00000110
#define LCD_2   0b01011011
#define LCD_3   0b01001111
#define LCD_4   0b01100110
#define LCD_5   0b01101101
#define LCD_6   0b01111101
#define LCD_7   0b00000111
#define LCD_8   0b01111111
#define LCD_9   0b01101111

void setup() {
  pinMode(ST_CP_LATCH_PIN, OUTPUT);
  pinMode(SH_CP_CLOCK_PIN, OUTPUT);
  pinMode(DS_DATA_PIN, OUTPUT);
  for(int p=0; p<DIGITS; p++) {
    pinMode(DIGIT_BASE_PIN + p, OUTPUT);
  }
}

void loop() {
  for(int p=0; p<DIGITS; p++) {
    enableDigit(p);
    registerWrite(LCD_0);
    delay(200);
    registerWrite(LCD_1);
    delay(200);
    registerWrite(LCD_2);
    delay(200);
    registerWrite(LCD_3);
    delay(200);
    registerWrite(LCD_4);
    delay(200);
    registerWrite(LCD_5);
    delay(200);
    registerWrite(LCD_6);
    delay(200);
    registerWrite(LCD_7);
    delay(200);
    registerWrite(LCD_8);
    delay(200);
    registerWrite(LCD_9);
    delay(200);
    registerWrite(LCD_CLR);
    delay(200);
  }
}

// Command: send +data+ to the 74HC595 shift register
void registerWrite(byte data) {
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}

void enableDigit(byte digit) {
  for(int p=0; p<DIGITS; p++) {
    digitalWrite(DIGIT_BASE_PIN + p, digit == p);
  }
}
