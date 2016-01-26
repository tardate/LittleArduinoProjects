/*

  LED7Segment/ShiftDrive
  Test control of a 7-segment display via a shift register.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LED7Segment/ShiftDrive

 */

// define pins for the shift register control
#define ST_CP_LATCH_PIN 4
#define SH_CP_CLOCK_PIN 5
#define DS_DATA_PIN 3

void setup() {
  pinMode(ST_CP_LATCH_PIN, OUTPUT);
  pinMode(SH_CP_CLOCK_PIN, OUTPUT);
  pinMode(DS_DATA_PIN, OUTPUT);
}

#define STEP_DELAY 500

void loop() {
  for(int d=0; d<10; d++) {
    writeDigit(d, d % 2 == 0);
    delay(STEP_DELAY);
  }
  clearDigit();
  delay(STEP_DELAY);
}

// define the bitmasks for characters 0-9
// where bits represent dp,G,F..A from MSB to LSB
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


// Command: send +data+ byte to the 74HC595 shift register
void pushSegmentRegister(byte data) {
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}

void writeDigit(byte digit, boolean withDP) {
  if(withDP) pushSegmentRegister(LED_DIGIT_MASK[digit] | LED_DP_MASK);
  else pushSegmentRegister(LED_DIGIT_MASK[digit]);
}

void writeDigit(byte digit) {
  pushSegmentRegister(LED_DIGIT_MASK[digit]);
}

void clearDigit() {
  pushSegmentRegister(LED_CLEAR_MASK);
}
