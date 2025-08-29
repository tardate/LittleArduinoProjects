/*

  TheMatrix/Firecracker
  A firecracker simulacrum running on the BoldportClub Matrix.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/BoldportClub/TheMatrix/Firecracker

 */

#include <Wire.h>
#include <LRAS1130.h>
#include "sparklie.h"


using namespace lr;
AS1130 ledDriver;

AS1130Picture24x5 pages[2]; // two pages for the current and next frame
uint8_t current_page = 0;   // index to the current page

static const uint16_t NOMINAL_RUNTIME = 1200;
static const uint8_t SPARKLIE_COUNT = 55;
Sparklie sparklies[SPARKLIE_COUNT];

static const uint8_t TEMP_PIN = A0;
static const uint16_t VREF_MV = 1100; // 1.1V when analogReference(INTERNAL)


void setup() {
  analogReference(INTERNAL);

  // Initialize the Wire library.
  Wire.begin();

  // Initialize the serial port.
  Serial.begin(115200);

  // Give the matrix some time to boot
  delay(100);

  // Check if the matrix is addressable.
  if (!ledDriver.isChipConnected()) {
    Serial.println(F("Communication problem with The Matrix."));
    Serial.flush();
    return;
  }

  // Set-up everything.
  ledDriver.setRamConfiguration(AS1130::RamConfiguration1);
  ledDriver.setOnOffFrameAllOff(0);
  ledDriver.setOnOffFrameAllOff(1);
  ledDriver.setBlinkAndPwmSetAll(0);
  ledDriver.setCurrentSource(AS1130::Current30mA);
  ledDriver.setScanLimit(AS1130::ScanLimitFull);
  ledDriver.startPicture(0);

  // Enable the chip
  ledDriver.startChip();
  delay(100);
}


/// @brief Command: main loop; explode when lit!
///
void loop() {
  if(fuseLit()) explode();
}


/// @brief Returns: true if temperature detected above 35°C
///
bool fuseLit() {
  int current_temperature = map(analogRead(TEMP_PIN), 0, 1023, 0, VREF_MV);
  return current_temperature > 350;
}


/// @brief Command: run the animation sequence
///
void explode() {
  uint16_t runtime = NOMINAL_RUNTIME;
  uint8_t live_sparklies;
  do {
    if(runtime>0) --runtime;
    live_sparklies = processStep(runtime > NOMINAL_RUNTIME / 2);
  } while(runtime>0 || live_sparklies>0);
}


/// @brief  Command: handle one step in the animation
///
uint8_t processStep(bool with_regeneration) {
  uint8_t live_sparklies = 0;
  uint8_t target_page = !current_page;
  for(uint8_t s=0; s<SPARKLIE_COUNT; ++s) {
    sparklies[s].clear(pages[current_page]);
    if(sparklies[s].recalculate(with_regeneration)) live_sparklies++;
    sparklies[s].draw(pages[target_page], ledDriver);
  }
  flipPage();
  return live_sparklies;
}


/// @brief Command: switch display pages.
/// current_page is switched, and the new page displayed
///
void flipPage() {
  current_page = !current_page;
  ledDriver.setOnOffFrame(0, pages[current_page]);
}
