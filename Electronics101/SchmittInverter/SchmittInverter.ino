/*

  SchmittInverter
  Uses an Arduino to drive and monitor a 74LS14 Schmitt Trigger inverter circuit and pipe the data to processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/SchmittInverter

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int i1_pin = 8;                   // input pin to drive
const int read_input_pin = A0;          // the pin we'll read input values from
const int read_output_pin = A1;         // the pin we'll read ouput values from

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)
  pinMode(i1_pin, OUTPUT);              // enable the input pins
  pinMode(read_input_pin, INPUT);       // enable the input_pin
  pinMode(read_output_pin, INPUT);      // enable the output_pin

  FlexiTimer2::set(10, sample);         // sample every 10ms
  FlexiTimer2::start();
}

void loop() {
  digitalWrite(i1_pin, HIGH);
  delay(500);
  digitalWrite(i1_pin, LOW);
  delay(500);
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
