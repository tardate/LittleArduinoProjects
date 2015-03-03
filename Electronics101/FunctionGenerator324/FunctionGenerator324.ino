/*

  FunctionGenerator324
  Use an Arduino to monitor the behaviour of an LM324 OpAmp waveform generator (square,triangle,sine,cosine)

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/FunctionGenerator324

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int READ_OUT1_PIN = A0;
const int READ_OUT2_PIN = A1;
const int READ_OUT3_PIN = A2;
const int READ_OUT4_PIN = A3;

void setup() {
  Serial.begin(9600);                   // initialize serial communications at 9600 bps

  FlexiTimer2::set(10, sample);         // set sampling procedure on timer interrupt
  FlexiTimer2::start();
}


void loop() {
  // do nothing
}

// read the current value and send to the serial port
// sending raw value (0-1023) because that is what PlotNValues expects.
void sample() {
  String result = "";
  Serial.println(result + analogRead(READ_OUT1_PIN) + "," + analogRead(READ_OUT2_PIN) + "," + analogRead(READ_OUT3_PIN) + "," + analogRead(READ_OUT4_PIN));
}
