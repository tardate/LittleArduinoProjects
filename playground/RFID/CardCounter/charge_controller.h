/*

  Implements charging/card control logic, and drives the indicator LEDs.

*/

#pragma once

#include <Arduino.h>

const int DEFAULT_DELAY = 3000;
const int CHARGE_DELAY = 2000;
const int RESET_DELAY = 2000;
const int DEDUCT_DELAY = 200;

class ChargeController {

  public:

    ChargeController(int reset_led_pin, int recharge_led_pin, int deduct_led_pin);

    /**
     * Initializes indictor LEDs
     */
    void begin();

    /**
     * Signals start of personalize/charge action
     */
    void start_charge();

    /**
     * Signals start of reset action
     */
    void start_reset();

    /**
     * Signals start of deduct action
     */
    void start_deduct();

    /**
     * Signals end of action
     */
    void end_state();

  private:

    int reset_led_pin;
    int recharge_led_pin;
    int deduct_led_pin;
    int end_state_delay;

    /**
     * Flash a welcome sequence
     */
    void hello();

    //
    /**
     * Flash a specific pin
     */
    void flash(int pin, int duration);

};
