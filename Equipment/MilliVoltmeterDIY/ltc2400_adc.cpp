#include <SPI.h>
#include "ltc2400_adc.h"


LTC2400_ADC::LTC2400_ADC(int cs_pin, int sample_size) {
  this->cs_pin = cs_pin;
  this->sample_size = sample_size;
  this->current_sample = 0;
  this->samples = new int32_t[sample_size];
  clear_samples();
}

void LTC2400_ADC::begin() {
  pinMode(cs_pin, OUTPUT);
  digitalWrite(cs_pin, HIGH);

  // Mode 0 (MOSI read on rising edge (CPLI=0) and SCK idle low (CPOL=0))
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  SPI.begin();
}


void LTC2400_ADC::read(void) {
  digitalWrite(cs_pin, LOW);

  while ((PINB & (1 << 4))) { }               // wait till pin 12 goes low, indicating end of conversion

  int32_t reading = 0;
  for (int i = 0; i < 4; i++) {
    reading <<= 8;
    reading |= SPI.transfer(0xFF);
  }
  reading >>= 4;                              // Discard 4 sub-LSB bits on the right

  if(reading & 0x02000000) {                  // positive:
    reading &=   0x01FFFFFF;                  // discard flag bits, keep EXR
  } else {                                    // negative:
    reading |=   0xFF000000;                  // convert to pure 2's complement
  }

  digitalWrite(cs_pin, HIGH);

  samples[current_sample++] = reading;
  if (current_sample == sample_size) current_sample = 0;
}


int32_t LTC2400_ADC::current_average(void) {
  int32_t sum = 0;
  for (int i = 0; i < sample_size; i++) sum += samples[i];
  return sum / sample_size;
}


void LTC2400_ADC::clear_samples(void) {
  for (int i = 0; i < sample_size; i++) samples[i] = 0;
}
