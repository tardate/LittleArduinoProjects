#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <TinyGPS++.h>

const int WELCOME_DELAY = 1000;

class DisplayController {
  public:
    DisplayController(Adafruit_PCD8544 *display_driver, TinyGPSPlus *gps);

    /*
     * Command: initialise the display
     */
    void begin();
    /*
     * Command: clear/reset display and cursor
     */
    void reset();
    /*
     * Command: show/refresh display
     */
    void refresh();
    /*
     * Command: display welcome message
     */
    void welcome(char *libraryVersion);
    /*
     * Command: display GPS data
     */
    void update();

  private:
    Adafruit_PCD8544 *display;
    TinyGPSPlus *gps;
};
