/*

  LedTemperatureDisplay
  Measure ambient temperature and display with a 4-digit 7-segment LED unit

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LedTemperatureDisplay

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

// define pin for temperature reading
#define READ_TEMPERATURE_PIN A0

// actual reference voltage of the board, in mV (as measured)
//#define VREF_MV 4930    // 5V  when analogReference(DEFAULT)
#define VREF_MV 1060  // 1.1V when analogReference(INTERNAL)

void setup() {
  analogReference(INTERNAL);

  pinMode(ST_CP_LATCH_PIN, OUTPUT);
  pinMode(SH_CP_CLOCK_PIN, OUTPUT);
  pinMode(DS_DATA_PIN, OUTPUT);
  for(int p=0; p<DIGITS; p++) {
    pinMode(DIGIT_BASE_PIN + p, OUTPUT);
  }

  FlexiTimer2::set(1, redrawLedDisplay); // update an LED character every 5ms
  FlexiTimer2::start();
}

void loop() {

  int current_temperature = map(analogRead(READ_TEMPERATURE_PIN),0,1023,0,VREF_MV);
  pushToLedDisplay(current_temperature, false, 1);

  // wait a bit before taking a new reading
  delay(1500);
}


// define the bitmasks for characters 0-9
byte LED_DIGIT_MASK[] = {
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
// define the bitmasks for clear and decimal point
#define LED_CLEAR_MASK 0b00000000
#define LED_DP_MASK    0b10000000

volatile byte display_values[] = {0,0,0,0}; // current display values for each digit
volatile byte current_digit = 0;            // 0-3 left to right

// Command: submit +value+ for display.
// If +leading_zeros+ is true, display leading zeros, else blank.
// If +scale+ >= 0, place decimal point at 10^-scale
void pushToLedDisplay(int value, boolean leading_zeros, int scale) {
  if(!leading_zeros && value<1000) {
    display_values[0] = LED_CLEAR_MASK;
  } else {
    display_values[0] = LED_DIGIT_MASK[value/1000 % 10];
  }
  if(!leading_zeros && value<100) {
    display_values[1] = LED_CLEAR_MASK;
  } else {
    display_values[1] = LED_DIGIT_MASK[value/100 % 10];
  }
  if(!leading_zeros && value<10) {
    display_values[2] = LED_CLEAR_MASK;
  } else {
    display_values[2] = LED_DIGIT_MASK[value/10 % 10];
  }
  display_values[3] = LED_DIGIT_MASK[value % 10];
  if(scale >= 0) display_values[3-scale] = display_values[3-scale] ^ LED_DP_MASK;
}
// Command: submit +value+ for display, no leading zeroes or decimal point
void pushToLedDisplay(int value) {
  pushToLedDisplay(value, false, -1);
}

// Command: update the LED display
void redrawLedDisplay() {
  // stop glowing the current digit and move to the next
  digitalWrite(DIGIT_BASE_PIN + current_digit, LOW);
  if(current_digit++ > 3) current_digit = 0;
  // push the digit to the LED display
  pushSegmentRegister(display_values[current_digit]);
  digitalWrite(DIGIT_BASE_PIN + current_digit, HIGH);
}

// Command: send +data+ byte to the 74HC595 shift register
void pushSegmentRegister(byte data) {
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}
