#include "display_controller.h"

DisplayController::DisplayController(Adafruit_PCD8544 *display_driver, TinyGPSPlus *gps) {
  this->display = display_driver;
  this->gps = gps;
}

void DisplayController::begin() {
  display->begin();
  display->setContrast(50);
  display->clearDisplay();
  display->setTextSize(1);
  display->setTextColor(BLACK);
}

void DisplayController::reset() {
  display->clearDisplay();
  display->setCursor(0,0);
}

void DisplayController::refresh() {
  display->display();
}

void DisplayController::welcome(char *libraryVersion) {
  reset();
  display->println(F("GPS Basics"));
  display->println(F("TinyGPS++ Ver"));
  display->println(libraryVersion);
  refresh();
  delay(WELCOME_DELAY);
}

void DisplayController::update() {
  if(gps->location.isValid()) {
    reset();
    display->print(F("LAT: "));
    display->println(gps->location.lat());
    display->print(F("LNG: "));
    display->println(gps->location.lng());
    if(gps->altitude.isValid()) {
      display->print(F("ALT: "));
      display->print(gps->altitude.meters());
      display->println(F("m"));
    }
    if (gps->date.isValid()) {
      char sz[32];
      sprintf(sz, "%02d-%02d-%02d", gps->date.year(), gps->date.month(), gps->date.day());
      display->println(sz);
    }
    if (gps->time.isValid()) {
      char sz[32];
      sprintf(sz, "%02d:%02d:%02d", gps->time.hour(), gps->time.minute(), gps->time.second());
      display->print(sz);
      display->println(F(" UTC"));
    }
    if(gps->satellites.isValid()) {
      display->print(F("SAT: "));
      display->println(gps->satellites.value());
    }
    refresh();
  }
}
