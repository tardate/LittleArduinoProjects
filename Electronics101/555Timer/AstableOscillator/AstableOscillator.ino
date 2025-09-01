/*

  AstableOscillator
  Uses an Arduino to monitor a classic a-stable 555 circuit and pipe the data to processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/555Timer/AstableOscillator

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int result_pin = A0;              // the pin we'll read our result values from
int result_value = 0;

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)
  pinMode(result_pin, INPUT);           // enable the result_pin

  FlexiTimer2::set(5, sample);          // sample every 5ms
  FlexiTimer2::start();
}

void loop() {
}

void sample() {
  // read the current value and send to the serial port
  result_value = analogRead(result_pin);
  Serial.println(result_value);
}
