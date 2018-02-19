#include "display_controller.h"

DisplayController::DisplayController(Adafruit_PCD8544 *display_driver, AS3935Controller *as3935_controller) {
  this->display = display_driver;
  this->as3935 = as3935_controller;
}

void DisplayController::begin() {
  display->begin();
  display->setContrast(50);
  display->clearDisplay();
  display->setTextSize(1);
  display->setTextColor(BLACK);
  #ifdef SERIAL_DEBUG
    Serial.begin(115200);
  #endif
}

void DisplayController::reset() {
  display->clearDisplay();
  display->setCursor(0,0);
}

void DisplayController::refresh() {
  display->display();
}

void DisplayController::welcome() {
  #ifdef SERIAL_DEBUG
    Serial.println("AS3935 Demo");
  #endif
  reset();
  display->println("AS3935 Demo");
  refresh();
  delay(WELCOME_DELAY);
}

void DisplayController::waiting() {
  #ifdef SERIAL_DEBUG
    Serial.println("Listening for lightning...");
  #endif
  reset();
  display->println("Listening for lightning...");
  refresh();
}


void DisplayController::readAllRegisters() {
  as3935->readAllRegisters();
  #ifdef SERIAL_DEBUG
    Serial.println("** readAllRegisters:");
    Serial.print("AFE_GB:");
    Serial.println(as3935->getGainBoost(), BIN);
    Serial.print("PWD:");
    Serial.println(as3935->getPowerDown(), BIN);
    Serial.print("NF_LEV:");
    Serial.println(as3935->getNoiseFloor(), BIN);
    Serial.print("WDTH:");
    Serial.println(as3935->getWatchdogThreshold(), BIN);
    Serial.print("MIN_LIGH:");
    Serial.println(as3935->getMinimumLightningStrikes(), BIN);
    Serial.print("SREJ:");
    Serial.println(as3935->getSpikeRejection(), BIN);
    Serial.print("LCO_FDIV:");
    Serial.println(as3935->getFrequencyDivisionRatio(), BIN);
    Serial.print("MASK_DIST:");
    Serial.println(as3935->getMaskDisturber(), BIN);
    Serial.print("DISP_LCO:");
    Serial.println(as3935->getDisplayLCO(), BIN);
    Serial.print("DISP_SRCO:");
    Serial.println(as3935->getDisplaySRCO(), BIN);
    Serial.print("DISP_TRCO:");
    Serial.println(as3935->getDisplayTRCO(), BIN);
    Serial.print("TUN_CAP:");
    Serial.println(as3935->getTuningCap(), BIN);
    Serial.println("Raw Registers:");
    for(uint8_t reg=0; reg<9; ++reg) {
      Serial.print("0x");
      Serial.print(reg, HEX);
      Serial.print("  : ");
      Serial.println(as3935->getRegister(reg), BIN);
    }
    Serial.print("0x3A : ");
    Serial.println(as3935->getRegister(0x3A), BIN);
    Serial.print("0x3B : ");
    Serial.println(as3935->getRegister(0x3B), BIN);
  #endif
}

void DisplayController::showConfig() {
  readAllRegisters();
  reset();
  display->print("AFE_GB:");
  display->println(as3935->getGainBoost(), BIN);
  display->print("PWD:");
  display->println(as3935->getPowerDown(), BIN);
  display->print("NF_LEV:");
  display->println(as3935->getNoiseFloor(), BIN);
  display->print("WDTH:");
  display->println(as3935->getWatchdogThreshold(), BIN);
  display->print("MIN_LIGH:");
  display->println(as3935->getMinimumLightningStrikes(), BIN);
  refresh();
  delay(PAGE_DELAY);
  reset();
  display->print("SREJ:");
  display->println(as3935->getSpikeRejection(), BIN);
  display->print("LCO_FDIV:");
  display->println(as3935->getFrequencyDivisionRatio(), BIN);
  display->print("MASK_DIST:");
  display->println(as3935->getMaskDisturber(), BIN);
  refresh();
  delay(PAGE_DELAY);
  reset();
  display->print("DISP_LCO:");
  display->println(as3935->getDisplayLCO(), BIN);
  display->print("DISP_SRCO:");
  display->println(as3935->getDisplaySRCO(), BIN);
  display->print("DISP_TRCO:");
  display->println(as3935->getDisplayTRCO(), BIN);
  display->print("TUN_CAP:");
  display->println(as3935->getTuningCap(), BIN);
  refresh();
  delay(PAGE_DELAY);
}

void DisplayController::lightningWarning() {
  readAllRegisters();
  #ifdef SERIAL_DEBUG
    Serial.print("Strike! ");
    Serial.println(millis(), HEX);
    Serial.print("Dist:");
    Serial.print(as3935->getStrikeDistance(), DEC);
    Serial.println("km");
    Serial.print("Type: ");
    Serial.println(as3935->getStrikeType(), BIN);
    Serial.print("Energy: ");
    Serial.println(as3935->getStrikeEnergy(), HEX);
  #endif
  if(as3935->isLightningInterrupt()) {
    // only display actual lightning interrupts on the LCD
    reset();
    display->print("Strike! ");
    display->println(millis(), HEX);
    display->print("Dist:");
    display->print(as3935->getStrikeDistance(), DEC);
    display->println("km");
    display->println("Type: Lightning");
    display->print("Energy: ");
    display->println(as3935->getStrikeEnergy(), HEX);
    refresh();
  }
}
