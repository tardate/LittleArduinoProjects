/*

  R2RDAC
  Test a 16-bit R2R digital to analog converter with shift register interface

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/R2RDAC

 */

#define LATCH_PIN 6
#define CLOCK_PIN 7
#define DATA_PIN  5

#define PATTERN_REPEATS 2
#define STEP_DELAY  3

#include "dac.h"
#include "wavetables.h"

DAC dac(DATA_PIN, LATCH_PIN, CLOCK_PIN);

void setup() {
  dac.write16(0x0);
}

void loop() {
  triangleWave(PATTERN_REPEATS);
  sawtoothWave(PATTERN_REPEATS);
  sineWave(PATTERN_REPEATS);
  humpWave(PATTERN_REPEATS);
}

void triangleWave(int cycles) {
  for(int c=0; c<cycles; c++) {
    for(int p=0; p< TRIANGLE_WAVE_SIZE; p++) {
      dac.write16(pgm_read_word(&TRIANGLE_WAVE_TABLE[p]));
      delay(STEP_DELAY);
    }
  }
}

void sawtoothWave(int cycles) {
  for(int c=0; c<cycles; c++) {
    for(int p=0; p< SAWTOOTH_WAVE_SIZE; p++) {
      dac.write16(pgm_read_word(&SAWTOOTH_WAVE_TABLE[p]));
      delay(STEP_DELAY);
    }
  }
}

void sineWave(int cycles) {
  for(int c=0; c<cycles; c++) {
    for(int p=0; p< SINE_WAVE_SIZE; p++) {
      dac.write16(pgm_read_word(&SINE_WAVE_TABLE[p]));
      delay(STEP_DELAY);
    }
  }
}

void humpWave(int cycles) {
  for(int c=0; c<cycles; c++) {
    for(int p=0; p< HUMP_WAVE_SIZE; p++) {
      dac.write16(pgm_read_word(&HUMP_WAVE_TABLE[p]));
      delay(STEP_DELAY);
    }
  }
}
