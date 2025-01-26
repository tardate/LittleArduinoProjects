#ifndef LTC2400_ADC_h
#define LTC2400_ADC_h

#include <Arduino.h>


class LTC2400_ADC {
  public:
    LTC2400_ADC(int cs_pin, int sample_size);

    // Command: initialise for ADC (usually in setup)
    void begin();

    // Command: requests and reads a single sample from the ADC
    void read(void);

    // Returns: reads a full set of samples from the ADC and returns the latest average
    int32_t read_average(int delay_per_sample);

    // Returns: latest average value sampled from the ADC
    int32_t current_average(void);

    int32_t latest_sample;
    int32_t raw_reading;

  private:
    int cs_pin;
    int sample_size;
    int current_sample;
    int32_t *samples;


    void clear_samples(void);
};


#endif
