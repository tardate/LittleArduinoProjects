/*

  PiezoPolarityTester

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/Ultrasonics/PiezoPolarityTester

 */

#define SERIAL_DEBUG

const int SENSOR_PIN = A0;
const int NON_INVERTED_LED_PIN = 3;
const int INVERTED_LED_PIN = 2;

const int SAMPLES_PER_READING = 32; // this gives a sampling rate of 300Hz
const int READINGS_PER_RESULT = 5; // use last 5 readings to determine polarity

const uint16_t INVERTED_THRESHOLD = 5; // non-inverted will typically be pegged at 0
const uint16_t NON_INVERTED_THRESHOLD = 300; // inverted variance will typically be in the 20-30 range

// use mnemonics for polarity states
enum class Polarity : uint8_t {
  noSignal = 0,
  inverted = 1,
  nonInverted = 2
};

/*
 * Command: one-time setup
 */
void setup() {
  pinMode(NON_INVERTED_LED_PIN, OUTPUT);
  pinMode(INVERTED_LED_PIN, OUTPUT);

  // set ADC prescaler to 128 division factor, 9.6kHz sampling rate
  ADCSRA |= bit(ADPS2) | bit(ADPS1) | bit(ADPS0);

  #ifdef SERIAL_DEBUG
  Serial.begin(115200);
  #endif
}

/*
 * Returns the average of multiple analog readings from the sensor pin
 */
int sampleValue() {
  int sum = 0;
  for (int i = 0; i < SAMPLES_PER_READING; ++i){
    sum += analogRead(SENSOR_PIN);
  }
  return sum / SAMPLES_PER_READING;
}

/*
 * Returns the polarity judged based on a series of readings
 */
Polarity checkPolarity() {
  int lastValue = sampleValue();
  uint16_t sumOfVariances = 0;
  for (int i = 1; i < READINGS_PER_RESULT; ++i){
    int currentValue = sampleValue();
    int delta = currentValue - lastValue;
    int deltaSq = delta * delta;
    if (sumOfVariances > UINT16_MAX - deltaSq) {
      sumOfVariances = UINT16_MAX;
    } else {
      sumOfVariances += deltaSq;
    }
    lastValue = currentValue;
  }
  int variance = sumOfVariances / READINGS_PER_RESULT;

  Polarity result = Polarity::noSignal;
  if (variance < INVERTED_THRESHOLD) {
    result = Polarity::inverted;
  } else if (variance < NON_INVERTED_THRESHOLD) {
    result = Polarity::nonInverted;
  }
  #ifdef SERIAL_DEBUG
  Serial.print(variance);
  Serial.print(" -> ");
  Serial.println((uint8_t)result);
  #endif
  return result;
}

/*
 * Command: set LED states based on polarity
 */
void indicatePolarity(Polarity polarity) {
  switch (polarity) {
    case Polarity::noSignal:
      digitalWrite(NON_INVERTED_LED_PIN, LOW);
      digitalWrite(INVERTED_LED_PIN, LOW);
      break;
    case Polarity::inverted:
      digitalWrite(NON_INVERTED_LED_PIN, LOW);
      digitalWrite(INVERTED_LED_PIN, HIGH);
      break;
    case Polarity::nonInverted:
      digitalWrite(NON_INVERTED_LED_PIN, HIGH);
      digitalWrite(INVERTED_LED_PIN, LOW);
      break;
  }
}

/*
 * Command: main loop
 */
void loop() {
  indicatePolarity(checkPolarity());
}
