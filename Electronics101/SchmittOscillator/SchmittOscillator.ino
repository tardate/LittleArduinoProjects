/*

  SchmittOscillator
  Uses an Arduino to monitor a 74LS14 Schmitt Trigger oscillator circuit and pipe the data to processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/SchmittOscillator

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int read_input_pin = A0;          // the pin we'll read input values from
const int read_output_pin = A1;         // the pin we'll read ouput values from

void setup() {
  Serial.begin(9600);                   // initialize serial communications at 9600 bps
  pinMode(read_input_pin, INPUT);       // enable the input_pin
  pinMode(read_output_pin, INPUT);      // enable the output_pin

  FlexiTimer2::set(10, sample);         // sample every 10ms
  FlexiTimer2::start();
}

void loop() {
  // NOP
}

// temp sampling storage
int input_value = 0;
int output_value = 0;
String result = "";

void sample() {
  // read the current value and send to the serial port
  input_value = analogRead(read_input_pin);
  output_value = analogRead(read_output_pin);
  Serial.println(result + input_value + "," + output_value);
}
