/*

  LM324Oscillator
  Use an Arduino to monitor the behaviour of an LM324 OpAmp oscillator

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/LM324Oscillator

 */

// use timer for sampling to get even time base for data
#include <FlexiTimer2.h>

const int read_v1_pin = A0;             // the pin we'll read Vout values from
const int read_v2_pin = A1;             // the pin we'll read Vout values from

void setup() {
  Serial.begin(9600);                   // initialize serial communications at 9600 bps

  pinMode(read_v1_pin, INPUT);          // enable read pin
  pinMode(read_v2_pin, INPUT);          // enable read pin

  FlexiTimer2::set(10, sample);         // set sampling procedure on timer interrupt
  FlexiTimer2::start();
}

void loop() {
  // do nothing
}

// temporary sampling storage
int v1_value = 0;
int v2_value = 0;
String result = "";

// read the current value and send to the serial port
void sample() {
  v1_value = analogRead(read_v1_pin);
  v2_value = analogRead(read_v2_pin);

  // sending raw value (0-1023) because that is what PlotNValues expects.
  Serial.println(result + v1_value + "," + v2_value );
}
