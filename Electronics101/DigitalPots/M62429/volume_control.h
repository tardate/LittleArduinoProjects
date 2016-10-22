#ifndef VOLUME_CONTROL_h
#define VOLUME_CONTROL_h

#include <Arduino.h>

#define LEFT_CHANNEL  (0b10)
#define RIGHT_CHANNEL (0b11)
#define BOTH_CHANNELS (0b00)
#define MAX_VOLUME    (0b1010111) // 87 = 0dB


class VolumeControl {

  public:
    VolumeControl(uint8_t data_pin, uint8_t clock_pin);

    void begin();

    /*
     * set the attenuation in dB 0 to 83.
     * anything above 83dB is effectively off (infinite attentuation)
     * i.e. db=70 means -70dB attenuation
     */
    void set_db(uint8_t db, uint8_t channel);

    /*
     * set the volume on a scale of 0 to 100.
     */
    void set_level(uint8_t level, uint8_t channel);

  private:
    uint8_t clock_pin;
    uint8_t data_pin;

    void latch_data();

};

#endif
