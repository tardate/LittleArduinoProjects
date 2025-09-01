/*

  VoltageSelfMeasurement
  Self-measurement of an Arduino's supply voltage (Vcc).

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/VoltageSelfMeasurement

 */

// Modify VBG_REF if the measured internal voltage reference is not exactly 1.1V
// static const uint32_t VBG_REF = 1100L * 1024; // mV * ADC resolution; standard 1.1V reference
static const uint32_t VBG_REF = 1063L * 1024; // for the Arduino I'm testing

void setup() {
  Serial.begin(115200);
  sendInternalRefToAREF();
}

void loop() {
  Serial.println(readVcc(), DEC);
  delay(1000);
}

/*
 * Run Vcc with respect to Vbg through the ADC
 * and derive actual Vcc assuming we know exactly what Vbg should be.
 */
uint16_t readVcc() {
  uint16_t result;

  ADMUX =
    _BV(REFS0) |                       // select AVcc with external capacitor at AREF pin (AVcc == Vcc)
    _BV(MUX3) | _BV(MUX2) | _BV(MUX1); // select 1.1V Vbg input channel

  delay(2);                            // wait a little for ADC inputs to settle
  ADCSRA |= _BV(ADSC);                 // start Single Conversion mode
  while (bit_is_set(ADCSRA, ADSC));    // wait until conversion is done

  result = ADCL;                       // Read low byte of result then high byte.
  result |= ADCH<<8;                   // When ADCL is read, the ADC Data Register is not updated until ADCH is read.

  result = VBG_REF / result;           // Convert back to mV
  return result;
}

/*
 * Configure the ADC to send the 1.1V internal reference to the AREF pin
 * for a few seconds so it can be measured
 */
void sendInternalRefToAREF() {
  ADMUX = _BV(REFS1) | _BV(REFS0);
  Serial.println(F("10 seconds to measure the actual 1.1V voltage reference in the AREF pin.."));
  delay(10000);
  Serial.println(F("If that was not exactly 1.1V, modify VBG_REF accordingly."));
}
