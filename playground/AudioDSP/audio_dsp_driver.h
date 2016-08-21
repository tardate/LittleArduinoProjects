#ifndef AudioDspDriver_h
#define AudioDspDriver_h

#include <Arduino.h>

#define DEFAULT_LED_PIN (13)
#define DEFAULT_FOOTSWITCH (12)
#define DEFAULT_TOGGLE (2)
#define DEFAULT_PUSHBUTTON_1 (A5)
#define DEFAULT_PUSHBUTTON_2 (A4)
#define DEFAULT_PWM_FREQ (0x00FF) // pwm frequency - 31.3KHz
#define DEFAULT_PWM_MODE (0) // Fast (1) or Phase Correct (0)
#define DEFAULT_PWM_QTY (2)


class AudioDspDriver {

  public:

    AudioDspDriver();

    /*
     * Initialise controls and ports.
     */
    void init();

    /*
     * Initialise ADC.
     */
    void init_adc();

    /*
     * Initialise PWM.
     */
    void init_pwm();

    /*
     * Reset all settings to defaults.
     */
    void reset();

    /*
     * Scan and update all controls.
     */
    void process_controls();

    /*
     * Turn on the LED if the effect is ON.
     */
    void process_footswitch();

    /*
     * Pushbuttons control the volume up/down
     */
    void process_pushbuttons();

    /*
     * Read ADC value. Sets and returns `current_input`.
     */
    int read();

    /*
     * Write `current_output` value
     */
    void write();

    /*
     * Read/Write input to output with standard transform.
     * Sets `current_input` and `current_output` as a by-product.
     */
    void pump();

    /*
     * Apply volume filter to `current_output`
     */
    void apply_volume();

    volatile int volume;
    volatile int current_input;
    volatile int current_output;

  private:

    int led_pin;
    int footswitch_pin;
    int toggle_pin;
    int pb1_pin;
    int pb2_pin;
    int pwm_freq;
    int pwm_mode;
    int pwm_qty;

};


#endif
