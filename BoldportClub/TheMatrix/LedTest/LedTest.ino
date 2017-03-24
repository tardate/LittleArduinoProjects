/*

  TheMatrix/LedTest
  This example tests all connected LEDs.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/BoldportClub/TheMatrix/LedTest

 */

#include <Wire.h>
#include "LRAS1130.h"

/// @example LedTest.ino
/// This example tests all connected LEDs.

using namespace lr;
AS1130 ledDriver;


void setup() {
  // Initialize the Wire library.
  Wire.begin();

  // Initialize the serial port.
  Serial.begin(9600);

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

  // Check for dead LEDs
  Serial.println(F("Run the LED test"));
  ledDriver.runManualTest();

  // Display the status of all leds.
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


void loop() {
}