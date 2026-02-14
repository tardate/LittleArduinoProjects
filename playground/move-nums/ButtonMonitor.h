#pragma once

#include <Arduino.h>

class ButtonMonitor {
  public:
    ButtonMonitor(int button_pin, unsigned long debounce_delay=250 /* ms */);

    /*
      Command: start the button monitor. Will setup the pin mode
    */
    void begin(void);

    /*
      Command: update the button state. Should be called frequently in loop()
      Returns: true if the button state has changed since last update and is pressed
    */
    bool update(void);

    /*
      Query: is the button currently pressed?
    */
    bool isPressed(void);

  private:
    int button_pin;
    unsigned long debounce_delay;
    bool button_state;
    unsigned long last_debounce_time;
};
