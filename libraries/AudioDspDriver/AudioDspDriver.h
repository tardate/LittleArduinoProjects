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
    int16_t read();

    /*
     * Write `current_output` value
     */
    void write();

    /*
     * Read/Write input to output with standard transform.
     * Sets `current_input` and `current_output` as a by-product.
     */
    void transform();

    /*
     * Read/Write input to output with suppplied transformer function.
     * transformer function takes two parameters: input and pb_level
     *
     *     int transformer(int input, int pb_level)
     *
     * input is 16-bit signed input signal (values from -32768 to +32768, INT16_MIN to INT16_MAX)
     * pb_level is 0-1024 with midpoint 512
     *
     * Sets `current_input` and `current_output` as a by-product.
     */
    void transform(int16_t (*transformer)(int16_t, int));

    volatile int pb_level;
    volatile int16_t current_input;
    volatile int16_t current_output;

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
