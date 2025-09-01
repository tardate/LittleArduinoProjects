/*

  Shifty

  Drive 8 LEDs with 3 pins using a 74HC595 shift register.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/Shifty

 */

const int latchPin = 10; // latch pin (ST_CP)
const int clockPin = 11; // clock pin (SH_CP)
const int dataPin  = 8;  // data pin (DS)

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // a simple loop to light the 8 LEDs in sequence
  for(int bitToSet; bitToSet < 8; bitToSet++) {
    registerWrite(bitToSet, HIGH);
    delay(300);
  }
}

// Command: set +whichBit+ on the shift register to +whichState+
void registerWrite(int whichBit, int whichState) {
  byte bitsToSend = 0;
  digitalWrite(latchPin, LOW);
  bitWrite(bitsToSend, whichBit, whichState);
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);
  digitalWrite(latchPin, HIGH);
}
