/*

  TriangleWaveGen
  Uses an Arduino to monitor a 555 timer/RC integrator triangle wave generator

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/555Timer/TriangleWaveGen

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int v1_pin = A0;                  // data sampling pins
const int v2_pin = A1;                  // data sampling pins

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)
  pinMode(v1_pin, INPUT);               // enable the sampling pins
  pinMode(v2_pin, INPUT);               // enable the sampling pins

  FlexiTimer2::set(10, sample);          // set the timer callback frequency in ms and function
  FlexiTimer2::start();
}

void loop() {
}


String result = "";
int v1_value = 0;
int v2_value = 0;

void sample() {
  // read the current value and send to the serial port
  v1_value = analogRead(v1_pin);
  v2_value = analogRead(v2_pin);
  Serial.println(result + v1_value + "," + v2_value);
}
