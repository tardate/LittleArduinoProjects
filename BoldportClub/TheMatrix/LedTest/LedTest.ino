/*

  TheMatrix/LedTest
  This example tests all connected LEDs.

  Based on LedTest.ino from the LRAS1130 library examples.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub/TheMatrix/LedTest

 */

#include <Wire.h>
#include <LRAS1130.h>

using namespace lr;
AS1130 ledDriver;

AS1130Picture24x5 picture;

void setup() {
  // Initialize the Wire library.
  Wire.begin();

  // Initialize the serial port.
  Serial.begin(115200);

  // Wait until the chip is ready.
  delay(100);
  Serial.println(F("Initialize chip"));

  // Check if the chip is addressable.
  if (!ledDriver.isChipConnected()) {
    Serial.println(F("Communication problem with chip."));
    Serial.flush();
    return;
  }

  // Set-up everything.
  ledDriver.setRamConfiguration(AS1130::RamConfiguration1);
  ledDriver.setOnOffFrameAllOn(0);
  ledDriver.setBlinkAndPwmSetAll(0);
  ledDriver.setCurrentSource(AS1130::Current30mA);
  ledDriver.setScanLimit(AS1130::ScanLimitFull);
  ledDriver.startPicture(0);

  // Enable the chip
  ledDriver.startChip();

  runLedTest();
}

void loop() {
  runPixelTest();
}

void runLedTest() {
  Serial.println(F("Testing the status of all LEDs"));
  ledDriver.runManualTest();

  for (uint8_t ledIndex = 0x00; ledIndex < 0xbb; ++ledIndex) {
    Serial.print(F("LED 0x"));
    Serial.print(ledIndex, HEX);
    Serial.print(F(": "));
    switch (ledDriver.getLedStatus(ledIndex)) {
      case AS1130::LedStatusOk:
        Serial.println(F(" OK"));
        break;
      case AS1130::LedStatusOpen:
        Serial.println(F(" open"));
        break;
      case AS1130::LedStatusDisabled:
        Serial.println(F(" disabled"));
        break;
    }
  }
}

void runPixelTest() {
  Serial.println(F("Visual inspection one LED at a time..."));
  for(uint8_t speed=0; speed<5; speed++) {
    for(uint8_t x=0; x<24; x++) {
      for(uint8_t y=0; y<5; y++) {
        picture.setPixel(x, y, true);
        ledDriver.setOnOffFrame(0, picture);
        picture.setPixel(x, y, false);
        delay(50 + 20 * speed);
      }
    }
  }
}
