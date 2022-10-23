/*

  Displays/Lcd3Digit/Simple
  The Simple (Unoptimised) Approach

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/Displays/Lcd3Digit/Simple

 */

// #define ENABLE_SERIAL_DEBUG
#include <FlexiTimer2.h>

const int COM1_PIN =  8;
const int COM2_PIN =  9;
const int COM3_PIN =  10;
const int COM4_PIN =  11;
const int SEG1_PIN =  14;
const int SEG2_PIN =  15;
const int SEG3_PIN =  16;
const int SEG4_PIN =  17;
const int SEG5_PIN =  18;
const int SEG6_PIN =  19;


const byte segmentEncoding[10] = {
  // two bits for each com line for each digit
  // {7,6}(com4{1,0}), {5,4}(com3{1,0}), {3,2}(com2{1,0}), {1,0}(com1{1,0}) -
  0b11011110,
  0b00010100,
  0b01111010,
  0b01110110,
  0b10110100,
  0b11100110,
  0b11101110,
  0b01010100,
  0b11111110,
  0b11110100
};

static byte comSegmentSteps[8] = {
  // defines the segment pins PORTC at each step
  0, 0, 0, 0, 0, 0, 0, 0
};

static byte currentNumber = 0;

volatile boolean timer_tick_triggered = false;

void flagTimerTickTriggered() {
  timer_tick_triggered = true;
}

/*
 * Command: calculates and sets the comSegmentSteps for the given number
 */

void setComSegmentSteps(byte number) {

  byte d2 = number / 100;
  byte d1 = (number - number / 100 * 100) / 10;
  byte d0 = (number - number / 10 * 10);


  byte d2Encoding = segmentEncoding[d2];
  byte d1Encoding = segmentEncoding[d1];
  byte d0Encoding = segmentEncoding[d0];

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.println("# setComSegmentSteps");
  Serial.print("number: "); Serial.println(number);
  Serial.print("d2: "); Serial.print(d2); Serial.print(" d2Encoding: "); Serial.println(d2Encoding, BIN);
  Serial.print("d1: "); Serial.print(d1); Serial.print(" d1Encoding: "); Serial.println(d1Encoding, BIN);
  Serial.print("d0: "); Serial.print(d0); Serial.print(" d0Encoding: "); Serial.println(d0Encoding, BIN);
  #endif

  for (int step = 0; step < 8; ++step) {
    byte value = step % 2 == 0 ? 0xFF : 0;

    switch(step) {
    case 0: // COM1 normally high phase
      if(d0Encoding & _BV(1)) value &= ~_BV(1); // if pin 2 should be asserted, flip output low
      if(d1Encoding & _BV(1)) value &= ~_BV(3); // if pin 4 should be asserted, flip output low
      if(d2Encoding & _BV(1)) value &= ~_BV(5); // if pin 6 should be asserted, flip output low
      break;
    case 1: // COM1 normally low phase
      if(d0Encoding & _BV(1)) value |= _BV(1); // if pin 2 should be asserted, flip output high
      if(d1Encoding & _BV(1)) value |= _BV(3); // if pin 4 should be asserted, flip output high
      if(d2Encoding & _BV(1)) value |= _BV(5); // if pin 6 should be asserted, flip output high
      break;
    case 2: // COM2 normally high phase
      if(d0Encoding & _BV(2)) value &= ~_BV(0); // if pin 1 should be asserted, flip output low
      if(d0Encoding & _BV(3)) value &= ~_BV(1); // if pin 2 should be asserted, flip output low
      if(d1Encoding & _BV(2)) value &= ~_BV(2); // if pin 3 should be asserted, flip output low
      if(d1Encoding & _BV(3)) value &= ~_BV(3); // if pin 4 should be asserted, flip output low
      if(d2Encoding & _BV(2)) value &= ~_BV(4); // if pin 5 should be asserted, flip output low
      if(d2Encoding & _BV(3)) value &= ~_BV(5); // if pin 6 should be asserted, flip output low
      break;
    case 3: // COM2 normally low phase
      if(d0Encoding & _BV(2)) value |= _BV(0); // if pin 1 should be asserted, flip output high
      if(d0Encoding & _BV(3)) value |= _BV(1); // if pin 2 should be asserted, flip output high
      if(d1Encoding & _BV(2)) value |= _BV(2); // if pin 3 should be asserted, flip output high
      if(d1Encoding & _BV(3)) value |= _BV(3); // if pin 4 should be asserted, flip output high
      if(d2Encoding & _BV(2)) value |= _BV(4); // if pin 5 should be asserted, flip output high
      if(d2Encoding & _BV(3)) value |= _BV(5); // if pin 6 should be asserted, flip output high
      break;
    case 4: // COM3 normally high phase
      if(d0Encoding & _BV(4)) value &= ~_BV(0); // if pin 1 should be asserted, flip output low
      if(d0Encoding & _BV(5)) value &= ~_BV(1); // if pin 2 should be asserted, flip output low
      if(d1Encoding & _BV(4)) value &= ~_BV(2); // if pin 3 should be asserted, flip output low
      if(d1Encoding & _BV(5)) value &= ~_BV(3); // if pin 4 should be asserted, flip output low
      if(d2Encoding & _BV(4)) value &= ~_BV(4); // if pin 5 should be asserted, flip output low
      if(d2Encoding & _BV(5)) value &= ~_BV(5); // if pin 6 should be asserted, flip output low
      break;
    case 5: // COM3 normally low phase
      if(d0Encoding & _BV(4)) value |= _BV(0); // if pin 1 should be asserted, flip output high
      if(d0Encoding & _BV(5)) value |= _BV(1); // if pin 2 should be asserted, flip output high
      if(d1Encoding & _BV(4)) value |= _BV(2); // if pin 3 should be asserted, flip output high
      if(d1Encoding & _BV(5)) value |= _BV(3); // if pin 4 should be asserted, flip output high
      if(d2Encoding & _BV(4)) value |= _BV(4); // if pin 5 should be asserted, flip output high
      if(d2Encoding & _BV(5)) value |= _BV(5); // if pin 6 should be asserted, flip output high
      break;
    case 6: // COM4 normally high phase
      if(d0Encoding & _BV(6)) value &= ~_BV(0); // if pin 1 should be asserted, flip output low
      if(d0Encoding & _BV(7)) value &= ~_BV(1); // if pin 2 should be asserted, flip output low
      if(d1Encoding & _BV(6)) value &= ~_BV(2); // if pin 3 should be asserted, flip output low
      if(d1Encoding & _BV(7)) value &= ~_BV(3); // if pin 4 should be asserted, flip output low
      if(d2Encoding & _BV(6)) value &= ~_BV(4); // if pin 5 should be asserted, flip output low
      if(d2Encoding & _BV(7)) value &= ~_BV(5); // if pin 6 should be asserted, flip output low
      break;
    case 7: // COM4 normally low phase
      if(d0Encoding & _BV(6)) value |= _BV(0); // if pin 1 should be asserted, flip output high
      if(d0Encoding & _BV(7)) value |= _BV(1); // if pin 2 should be asserted, flip output high
      if(d1Encoding & _BV(6)) value |= _BV(2); // if pin 3 should be asserted, flip output high
      if(d1Encoding & _BV(7)) value |= _BV(3); // if pin 4 should be asserted, flip output high
      if(d2Encoding & _BV(6)) value |= _BV(4); // if pin 5 should be asserted, flip output high
      if(d2Encoding & _BV(7)) value |= _BV(5); // if pin 6 should be asserted, flip output high
      break;
    }
    comSegmentSteps[step] = value;
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.print("step: "); Serial.print(step); Serial.print("value: "); Serial.println(comSegmentSteps[step], BIN);
    #endif
  }
}

/*
 * Command: set COM port state for given step
 */
void setComState(byte step) {
  switch(step) {
  case 0: // COM1 normally high phase
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.println("COM1_PIN: HIGH ");
    #endif
    pinMode(COM4_PIN, INPUT);
    pinMode(COM1_PIN, OUTPUT);
    digitalWrite(COM1_PIN, HIGH);
    break;
  case 1: // COM1 normally low phase
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.println("COM1_PIN: LOW ");
    #endif
    digitalWrite(COM1_PIN, LOW);
    break;
  case 2: // COM2 normally high phase
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.println("COM2_PIN: HIGH ");
    #endif
    pinMode(COM1_PIN, INPUT);
    pinMode(COM2_PIN, OUTPUT);
    digitalWrite(COM2_PIN, HIGH);
    break;
  case 3: // COM2 normally low phase
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.println("COM2_PIN: LOW ");
    #endif
    digitalWrite(COM2_PIN, LOW);
    break;
  case 4: // COM3 normally high phase
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.println("COM3_PIN: HIGH ");
    #endif
    pinMode(COM2_PIN, INPUT);
    pinMode(COM3_PIN, OUTPUT);
    digitalWrite(COM3_PIN, HIGH);
    break;
  case 5: // COM3 normally low phase
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.println("COM3_PIN: LOW ");
    #endif
    digitalWrite(COM3_PIN, LOW);
    break;
  case 6: // COM4 normally high phase
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.println("COM4_PIN: HIGH ");
    #endif
    pinMode(COM3_PIN, INPUT);
    pinMode(COM4_PIN, OUTPUT);
    digitalWrite(COM4_PIN, HIGH);
    break;
  case 7: // COM4 normally low phase
    #ifdef ENABLE_SERIAL_DEBUG
    Serial.println("COM4_PIN: LOW ");
    #endif
    digitalWrite(COM4_PIN, LOW);
    break;
  }
}

/*
 * Command: set COM port state for given step
 */
void updateSegments(byte step) {
  byte value = comSegmentSteps[step];
  #ifdef ENABLE_SERIAL_DEBUG
  Serial.print("updateSegments step: "); Serial.print(step); Serial.print(" value: "); Serial.println(value, BIN);
  Serial.print("           SEG1_PIN: "); Serial.println(value & _BV(0), BIN);
  Serial.print("           SEG2_PIN: "); Serial.println(value & _BV(1), BIN);
  Serial.print("           SEG3_PIN: "); Serial.println(value & _BV(2), BIN);
  Serial.print("           SEG4_PIN: "); Serial.println(value & _BV(3), BIN);
  Serial.print("           SEG5_PIN: "); Serial.println(value & _BV(4), BIN);
  Serial.print("           SEG6_PIN: "); Serial.println(value & _BV(5), BIN);
  #endif
  digitalWrite(SEG1_PIN, value & _BV(0));
  digitalWrite(SEG2_PIN, value & _BV(1));
  digitalWrite(SEG3_PIN, value & _BV(2));
  digitalWrite(SEG4_PIN, value & _BV(3));
  digitalWrite(SEG5_PIN, value & _BV(4));
  digitalWrite(SEG6_PIN, value & _BV(5));
}

/*
 * Command: run a single full duty cycle
 */
void runFullCycle() {
  for (int comStep = 0; comStep < 8; ++comStep) {
    setComState(comStep);
    updateSegments(comStep);
    delay(3);
  }
}

/*
 * Command: one-time setup
 */
void setup() {
  #ifdef ENABLE_SERIAL_DEBUG
  Serial.begin(115200);
  #endif

  pinMode(COM1_PIN, INPUT);
  pinMode(COM2_PIN, INPUT);
  pinMode(COM3_PIN, INPUT);
  pinMode(COM4_PIN, INPUT);
  pinMode(SEG1_PIN, OUTPUT);
  pinMode(SEG2_PIN, OUTPUT);
  pinMode(SEG3_PIN, OUTPUT);
  pinMode(SEG4_PIN, OUTPUT);
  pinMode(SEG5_PIN, OUTPUT);
  pinMode(SEG6_PIN, OUTPUT);

  setComSegmentSteps(currentNumber);

  FlexiTimer2::set(1000, 1.0/1000, flagTimerTickTriggered); // call every 1000 1ms "ticks"
  FlexiTimer2::start();
}


/*
 * Command: main loop
 */
void loop() {
  if (timer_tick_triggered) {
    currentNumber++;
    if(currentNumber>999) currentNumber = 0;
    setComSegmentSteps(currentNumber);
    timer_tick_triggered = false;
  }
  runFullCycle();
}
