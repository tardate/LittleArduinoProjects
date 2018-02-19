#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "AS3935_controller.h"

const int WELCOME_DELAY = 1000;
const int PAGE_DELAY = 3000;

// define SERIAL_DEBUG to enable debug info to be sent to serial port
#define SERIAL_DEBUG

class DisplayController {
  public:
    DisplayController(Adafruit_PCD8544 *display_driver, AS3935Controller *as3935_controller);

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
    void welcome();
    /*
     * Command: display AS3935 config
     */
    void showConfig();
    /*
     * Command: display lightening strike info
     */
    void lightningWarning();
    /*
     * Command: display welcome message
     */
    void waiting();

  private:
    Adafruit_PCD8544 *display;
    AS3935Controller *as3935;

    void readAllRegisters();
};
