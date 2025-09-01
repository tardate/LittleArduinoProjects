/*

  FastAnalogRead
  How to increase the Arduino ADC analog sampling rate.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/FastAnalogRead

 */

const int ANALOG_IN_PIN = A0;             //pin the receiver is connected to
const int NUMBER_OF_READINGS = 100;

int results[NUMBER_OF_READINGS];

/*
 * Command: report ADC settings to serial port
 */
void showCurrentAdcSettings() {
  Serial.print("ADMUX = 0b");
  Serial.print(ADMUX, BIN);
  Serial.print(", ADCSRA = 0b");
  Serial.print(ADCSRA, BIN);
  Serial.print(", ADCSRB = 0b");
  Serial.println(ADCSRB, BIN);
}


/*
 * Command: report ADC result to serial port
 */
void showAdcResult() {
  int minValue = results[0];
  int maxValue = results[0];

  for (int i = 1 ; i < NUMBER_OF_READINGS; ++i) {
    if (results[i] > maxValue) maxValue = results[i];
    if (results[i] < minValue) minValue = results[i];
  }

  Serial.print("Read = ");
  Serial.print(results[0]);
  Serial.print(", min = ");
  Serial.print(minValue);
  Serial.print(", max = ");
  Serial.println(maxValue);
}

/*
 * Command: set the ADC prescalar
 * Takes advantage of the fact that ADPS2, ADPS1, ADPS0 are the lowest 3 bits of the register.
 *
 */
void setAdcPrescaler(uint8_t divisor) {
  uint8_t exponent;
  switch (divisor) {
  case 128: exponent = 0b111; break;
  case 64: exponent = 0b110; break;
  case 32: exponent = 0b101; break;
  case 16: exponent = 0b100; break;
  case 8: exponent = 0b011; break;
  case 4: exponent = 0b010; break;
  case 2: exponent = 0b001; break;
  default: exponent = 0;
  }
  ADCSRA = (ADCSRA & 0b11111000) | exponent;
}


void makeReadings() {
  unsigned long start_time;
  unsigned long duration;

  start_time = micros();
  for(int i = 0; i < NUMBER_OF_READINGS; i++) {
      results[i] = analogRead(ANALOG_IN_PIN);
  }
  duration = micros() - start_time;
  Serial.print("Duration = ");
  Serial.print(duration);
  Serial.println("us");
  showAdcResult();
}


void compareAdcPerformance() {
  Serial.print(NUMBER_OF_READINGS);
  Serial.println(" readings with analogRead and standard prescaler = 128:");
  setAdcPrescaler(128);
  showCurrentAdcSettings();
  makeReadings();

  Serial.print(NUMBER_OF_READINGS);
  Serial.println(" readings with analogRead and prescaler = 16:");
  setAdcPrescaler(16);
  showCurrentAdcSettings();
  makeReadings();
}


void setup() {
  Serial.begin(115200);

  Serial.println("FastAnalogRead");
  Serial.print("Initial ADC Settings: ");
  showCurrentAdcSettings();
}


void loop() {
  compareAdcPerformance();
  delay(5000);
}
