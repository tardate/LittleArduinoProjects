/*

  MultiSlaveSPI
  Control multiple devices with SPI - in this case:
  (1) ledController: a 74HC595 shift register driving a 7-segment LED
  (2) counter: a CD4017 counter module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/MultiSlaveSPI

 */

#include <SPI.h>

SPISettings ledControllerSettings(2000000, MSBFIRST, SPI_MODE0);
SPISettings counterSettings(2000000, LSBFIRST, SPI_MODE0);

// Standard SPI pins are used used for clock and data, but slave select can be any free pin
#define COUNTER_SS_PIN 3
#define LED_CONTROLLER_SS_PIN 4

#define STEP_DELAY 1000


void setup() {
  SPI.begin();
  pinMode(LED_CONTROLLER_SS_PIN, OUTPUT);
  pinMode(COUNTER_SS_PIN, OUTPUT);
  clearLedController();
}


void loop() {
  for(int d=0; d<10; d++) {
    pulseCounterModule();
    writeLedController(d);
    delay(STEP_DELAY);
  }
  clearLedController();
  delay(STEP_DELAY);
}


/*
  Counter Module support
 */

// Command: pulse the counter module using SPI
// the counter module doesn't really support SPI,
// but this results in a "backwards count"
void pulseCounterModule() {
  SPI.beginTransaction(counterSettings);
  digitalWrite(COUNTER_SS_PIN, LOW);
  // toggling the select actually causes 1 pulse to be detected by the counter
  // so now send another 8 pulses, effectively resulting in count by -1
  SPI.transfer(0b01010101);
  SPI.transfer(0b01010101);
  digitalWrite(COUNTER_SS_PIN, HIGH);
  SPI.endTransaction();
}

/*
  LED Controller support
 */

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

// Command: send +data+ byte to the 74HC595 shift register using SPI
void pushLedControllerData(byte data) {
  SPI.beginTransaction(ledControllerSettings);
  digitalWrite(LED_CONTROLLER_SS_PIN, LOW);
  SPI.transfer(data);
  digitalWrite(LED_CONTROLLER_SS_PIN, HIGH);
  SPI.endTransaction();
}

void writeLedController(byte digit) {
  boolean withDP = digit % 2 == 0;
  if(withDP) pushLedControllerData(LED_DIGIT_MASK[digit] | LED_DP_MASK);
  else pushLedControllerData(LED_DIGIT_MASK[digit]);
}

void clearLedController() {
  pushLedControllerData(LED_CLEAR_MASK);
}

