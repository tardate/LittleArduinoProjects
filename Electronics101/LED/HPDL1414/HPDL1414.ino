/*

  LED/HPDL1414
  Test driving a retro HPDL-1414 4-digit GaAsP display with an Arduino

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/LED/HPDL1414

 */

#include <HPDL1414.h>

const int MICRO_DELAY = 5;
const int MINOR_DELAY = 100;
const int MAJOR_DELAY = 1000;

const byte dataPins[7] = {2, 3, 4, 5, 6, 7, 8}; // Segment data pins: D0 - D6
const byte addrPins[2] = {A1, A2}; // Segment address pins: A0, A1
const byte wrenPins[] = {A0}; // Write Enable pins (left to right)

HPDL1414 hpdl(dataPins, addrPins, wrenPins, sizeof(wrenPins));


/*
 * Command: one-time setup
 */
void setup() {
  hpdl.begin();
  hpdl.printOverflow(true);
  hpdl.clear();
}


/*
 * Command: main loop
 */
void loop() {
  showDiags();
  showCharset();
  showCounter();
}


void showDiags() {
  for (uint8_t segment = 0; segment < hpdl.segments(); ++segment) {
    hpdl.print("SEG" + String(segment));
  }
  delay(MAJOR_DELAY);
  hpdl.clear();
}


void showCharset() {
  for (uint16_t c = 0x20; c <= 0x5F; ++c) {
    hpdl.write(c);
    delay(MINOR_DELAY);
  }
  delay(MAJOR_DELAY);
  hpdl.clear();
}


void showCounter() {
  for (uint16_t n = 0; n <= 1234; ++n) {
    hpdl.write(0b0110000 + n / 1000);
    hpdl.write(0b0110000 + (n - n / 1000 * 1000) / 100);
    hpdl.write(0b0110000 + (n - n / 100 * 100) / 10);
    hpdl.write(0b0110000 + (n - n / 10 * 10));
    delay(MICRO_DELAY);
  }
  delay(MAJOR_DELAY);
  delay(10000);
  hpdl.clear();
}
