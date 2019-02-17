/*

  ADC/LTC2400
  Simple LTC2400 utility for logger readings to serial

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/ADC/LTC2400

 */

#include <SPI.h>
#include "ltc2400_adc.h"


const int NUMBER_OF_SAMPLES = 10;
const int DELAY_PER_SAMPLE = 1;
const int ADC_CS_PIN = 10;
const int DELAY_PER_READING = 2000;


LTC2400_ADC adc(ADC_CS_PIN, NUMBER_OF_SAMPLES);

float adc_reference_voltage = 2.5; // default for LT1019-2.5; updated on startup
int32_t calibration_factor = 0;


/*
 * Command: perform calibration:
 * - ask for entry of the VREF voltage and for VREF to be connected to VIN
 * - read the current average input value, now assumed to correspond to VREF on VIN
 */
void calibrate() {
  float value = 0;
  int shift_multiplier = 10;
  int fractional_divisor = 1;
  bool accumulating = true;

  Serial.print("Connect VIN to VREF and enter the reference voltage (in volts): ");

  while (accumulating) {

    if (Serial.available()) {
      char ch = Serial.read();
      if (ch >= '0' && ch <= '9') {
        value = (value * shift_multiplier) + (ch - '0') * 1.0 / fractional_divisor;
        if (shift_multiplier == 1) {
          fractional_divisor *= 10;
        }
      } else if (ch == '.') {
        shift_multiplier = 1;
        fractional_divisor = 10;
      } else {
        accumulating = false;
      }
    }

  }

  adc_reference_voltage = value;

  Serial.println();
  Serial.print("Calibrating for VREF = ");
  Serial.println(adc_reference_voltage, DEC);

  calibration_factor = adc.read_average(DELAY_PER_SAMPLE);

  Serial.print("Calibration complete. ADC Calibration Factor = 0x");
  Serial.print(calibration_factor, HEX);
  Serial.println();

}


/*
 * setup: init serial and aDC and perform calibration
 */
void setup() {
  Serial.begin(115200);
  Serial.println("LTC2400 Diags");

  adc.begin();

  calibrate();
}


/*
 * loop: read ADC and log details to serial
 */
void loop() {
  adc.read();

  Serial.print("ADC Raw: 0x");
  Serial.print(adc.raw_reading, HEX);
  Serial.print(",  Current sample: 0x");
  Serial.print(adc.latest_sample, HEX);
  Serial.print(" = ");
  Serial.print(
    adc_reference_voltage * adc.latest_sample / calibration_factor,
    DEC
  );
  Serial.print("V");

  Serial.print(",  Average sample: 0x");
  Serial.print(adc.current_average(), HEX);
  Serial.print(" = ");
  Serial.print(
    adc_reference_voltage * adc.current_average() / calibration_factor,
    DEC
  );
  Serial.println("V");

  delay(DELAY_PER_READING);
}
