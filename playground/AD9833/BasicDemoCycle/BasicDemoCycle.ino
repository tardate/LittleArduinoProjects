/*

  AD9833/BasicDemoCycle
  Run a basic waveform demo with an AD9833 module

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/AD9833/BasicDemoCycle

 */

#include <FlexiTimer2.h>            // use timer for sampling to get even time base for data
#define SAMPLING_FREQUENCY 5        // milliseconds
#define PROBE_PIN          A0

#include <SPI.h>                    // use hardware SPI

// AD9833 Control Register helpers
#define CR_B28_COMBINED      0x2000
#define CR_FSELECT_0         0x0000
#define CR_PSELECT_0         0x0000
#define CR_RESET             0x0100
#define CR_SLEEP1            0x0080
#define CR_SLEEP12           0x0040
#define CR_OPBITEN           0x0020
#define CR_DIV2              0x0008
#define CR_MODE_D1_TRIANGLE  0x0002
#define CR_MODE_D1_SINE      0x0000

// Mnemonics for wave forms
#define SINE                 (CR_B28_COMBINED | CR_MODE_D1_SINE)
#define SQUARE               (CR_B28_COMBINED | CR_OPBITEN)
#define FAST_SQUARE          (SQUARE | CR_DIV2)
#define TRIANGLE             (CR_B28_COMBINED | CR_MODE_D1_TRIANGLE)

#define FREQ0                0x4000
#define PHASE0               0xC000
#define REF_FREQ             25000000.0
#define SPI_CLOCK_SPEED      12000000

// Mnemonics for demo control
#define STEP_DELAY           800
#define ENABLE_DEMO_SEQUENCE // if defined, runs the multi-wave demo cycle,
                             // else runs a fixed sine wave at max frequency


void setup() {

  // initialize serial communications and setup sampling interrupt routine
  Serial.begin(115200);
  FlexiTimer2::set(SAMPLING_FREQUENCY, sample);
  FlexiTimer2::start();

  // initialise SPI
  SPI.begin();

  #ifndef ENABLE_DEMO_SEQUENCE
  setWave(SINE, 1000000);  // just run a fixed 1 MHz sine
  #endif
}


void loop() {
  #ifdef ENABLE_DEMO_SEQUENCE
  for(long frequency = 1; frequency < 11; frequency++) {
    setWave(SINE, frequency);
    delay(STEP_DELAY);
    setWave(SQUARE, frequency);
    delay(STEP_DELAY);
    setWave(TRIANGLE, frequency);
    delay(STEP_DELAY);
    setWave(FAST_SQUARE, frequency);
    delay(STEP_DELAY);
    setWaveOff();
    delay(STEP_DELAY);
  }
  #endif
}


/*
  Command: set the waveform and frequency (Hz)
 */
void setWave(int waveform, long frequency) {
  long freq_data = frequency * pow(2, 28) / REF_FREQ;
  int freq_MSB = (int)(freq_data >> 14) | FREQ0;
  int freq_LSB = (int)(freq_data & 0x3FFF) | FREQ0;

  SPI.beginTransaction(SPISettings(SPI_CLOCK_SPEED, MSBFIRST, SPI_MODE2));
  digitalWrite(SS, LOW);

  SPI.transfer16(CR_B28_COMBINED | CR_FSELECT_0 | CR_PSELECT_0 | CR_RESET);
  SPI.transfer16(freq_LSB);
  SPI.transfer16(freq_MSB);
  SPI.transfer16(PHASE0);
  SPI.transfer16(waveform);

  digitalWrite(SS, HIGH);
  SPI.endTransaction();
}


/*
  Command: turn off the waveform output
 */
void setWaveOff() {
  SPI.beginTransaction(SPISettings(SPI_CLOCK_SPEED, MSBFIRST, SPI_MODE2));
  digitalWrite(SS, LOW);

  SPI.transfer16(CR_RESET | CR_SLEEP1 | CR_SLEEP12);

  digitalWrite(SS, HIGH);
  SPI.endTransaction();
}


/*
  Command: read the current values and send to the serial port.
  This sends raw values (0-1023) because that is what PlotNValues processing script expects.
 */
void sample() {
  Serial.println(analogRead(PROBE_PIN));
}
