/*

  TheMatrix/KeypadControl
  Use a 20-button keypad to write a scrolling message on the Boldport Matrix

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub/TheMatrix/KeypadControl

 */


#include <Wire.h>
#include <LRAS1130.h>

using namespace lr;
AS1130 ledDriver;

AS1130Picture24x5 picture;
uint8_t x_offset = 0;

const int KEY_POLL_DELAY    = 250;
const uint8_t START_L_PIN   = 2;
const uint8_t L_PINS        = 4;
const uint8_t START_R_PIN   = 6;
const uint8_t R_PINS        = 4;
const uint8_t START_S_PIN   = 10;
const uint8_t S_PINS        = 4;


void setup() {
  Wire.begin();
  setupTheMatrix();
  setupKeys();
}


void loop() {
  scanKeys();
  delay(KEY_POLL_DELAY);
}


void setupTheMatrix() {
    // Wait until the chip is ready.
  delay(100);

  // Check if the chip is addressable.
  if (!ledDriver.isChipConnected()) {
    return;
  }

  // Set-up everything.
  ledDriver.setRamConfiguration(AS1130::RamConfiguration1);
  ledDriver.setOnOffFrameAllOff(0);
  ledDriver.setOnOffFrameAllOff(1);
  ledDriver.setBlinkAndPwmSetAll(0);
  ledDriver.setCurrentSource(AS1130::Current30mA);
  ledDriver.setScanLimit(AS1130::ScanLimitFull);
  ledDriver.setScrollingEnabled(false);
  ledDriver.startPicture(0);

  // Enable the chip
  ledDriver.startChip();
}


void togglePixel(uint8_t relX, uint8_t relY) {
  uint8_t x = x_offset + relX;
  uint8_t y = relY;
  picture.setPixel(x, y, !picture.getPixel(x, y));
  ledDriver.setOnOffFrame(0, picture);
}


void shiftViewport(uint8_t offset) {
  uint8_t new_offset = x_offset + offset;
  if(new_offset >= 0 && new_offset < 24)  {
    x_offset = new_offset;
    togglePixel(0, 4);
    delay(200);
    togglePixel(0, 4);
  }
}


void toggleScrolling() {
  if(ledDriver.isMovieRunning()) {
    ledDriver.setMovieLoopCount(AS1130::MovieLoop1);
    ledDriver.setFrameDelayMs(0);
    ledDriver.setScrollingEnabled(false);
    ledDriver.stopMovie();
    ledDriver.startPicture(0);
  } else {
    ledDriver.setMovieEndFrame(AS1130::MovieEndWithFirstFrame);
    ledDriver.setMovieFrameCount(2);
    ledDriver.setFrameDelayMs(300);
    ledDriver.setScrollingEnabled(true);
    ledDriver.setScrollingDirection(AS1130::ScrollingLeft);
    ledDriver.setMovieLoopCount(AS1130::MovieLoopEndless);
    ledDriver.startMovie(0);
  }
}


void setupKeys() {
  // set the L pins as output LOW by default
  for(uint8_t lpin = START_L_PIN; lpin < START_L_PIN + L_PINS; ++lpin) {
    pinMode(lpin, OUTPUT);
    digitalWrite(lpin, HIGH);
  }
  // set the R pins as input with pullup (normally high)
  for(uint8_t rpin = START_R_PIN; rpin < START_R_PIN + R_PINS; ++rpin) {
    pinMode(rpin, INPUT_PULLUP);
  }
  // set the S pins as input (normally high with external pullup)
  for(uint8_t spin = START_S_PIN; spin < START_S_PIN + S_PINS; ++spin) {
    pinMode(spin, INPUT);
  }
}


void scanKeys() {
  // test for command combinations
  if(!digitalRead(START_S_PIN) && !digitalRead(START_S_PIN + 1)) {
    shiftViewport(-R_PINS);
    return;
  }
  if(!digitalRead(START_S_PIN + 2) && !digitalRead(START_S_PIN + 3)) {
    shiftViewport(R_PINS);
    return;
  }
  if(!digitalRead(START_S_PIN + 1) && !digitalRead(START_S_PIN + 2)) {
    toggleScrolling();
    return;
  }

  // scan the L-R key matrix
  for(uint8_t lpin = START_L_PIN; lpin < START_L_PIN + L_PINS; ++lpin) {
    // pull a set of L keys LOW
    digitalWrite(lpin, LOW);
    for(uint8_t rpin = START_R_PIN; rpin < START_R_PIN + R_PINS; ++rpin) {
      // see if any corresponding R inputs are LOW
      if(!digitalRead(rpin)) togglePixel(rpin - START_R_PIN, lpin - START_L_PIN);
    }
    digitalWrite(lpin, HIGH);
  }
  // S pins just get read normally
  for(uint8_t spin = START_S_PIN; spin < START_S_PIN + S_PINS; ++spin) {
    // see if any corresponding S inputs are LOW
    if(!digitalRead(spin)) togglePixel(spin - START_S_PIN, 4);
  }
}
