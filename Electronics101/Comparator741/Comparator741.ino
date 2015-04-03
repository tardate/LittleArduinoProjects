/*

  Comparator741
  Uses an Arduino to test LM741 comparator behaviour and plot the results with processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/Comparator741

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

#define INVERTED_INPUT_PIN 10
const int READ_INVERTED_PIN = A0;
const int READ_OUTPUT_PIN = A1;

int inverted_value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(INVERTED_INPUT_PIN, OUTPUT);

  FlexiTimer2::set(10, sample);
  FlexiTimer2::start();
}

void loop() {
  for(inverted_value=0; inverted_value <=255; inverted_value += 10) {
    analogWrite(INVERTED_INPUT_PIN, inverted_value);
    delay(100);
  }
  for(inverted_value=255; inverted_value >=0; inverted_value -= 10) {
    analogWrite(INVERTED_INPUT_PIN, inverted_value);
    delay(100);
  }
}

// sample values and pipe to processing
void sample() {
  String result = "";
  Serial.println(result + inverted_value + "," + analogRead(READ_INVERTED_PIN) + "," + analogRead(READ_OUTPUT_PIN));
}
