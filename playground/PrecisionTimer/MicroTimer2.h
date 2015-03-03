#pragma once

#include <Arduino.h>

class MicroTimer2 {
  public:
    MicroTimer2();

    /*
     * Command: enables the timer.
     * This configures Timer2 and will prevent other Timer2-based features from working.
     * Invoked implicitly with a call to micros().
     */
    void enable();
    /*
     * Command: disables the timer.
     * This resets Timer2 configuration so it may be used by other features.
     */
    void disable();

    /*
     * Returns: current count in microseconds, with a precision of 0.5µs.
     */
    float micros();

    /*
     * Command: disables the timer
     * This resets Timer2 configuration so it may be used by other features.
     */
    void reset();

    /*
     * Command: increments overflow count.
     * Used by the overflow interrupt service routine.
     */
    void increment_overflow_count();

  private:

    volatile unsigned long _overflow_count;
    unsigned long _total_count;
    bool _started;

    byte _initial_tccr2a;
    byte _initial_tccr2b;
    byte _paused_SREG;

    /*
     * Command: stops interrupts
     */
    void pause();
    /*
     * Command: re-enables interrupts
     */
    void resume();

    /*
     * Returns: current raw count of 0.5µs increments.
     */
    unsigned long get_count();

    void reset_overflow_flag();
    void enable_overflow_interrupt();
    void disable_overflow_interrupt();

};

extern MicroTimer2 microTimer2; // gobal singleton for this class
