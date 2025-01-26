/*

  NonInverting324
  Use an Arduino to monitor the behaviour of an LM324 OpAmp in non-inverting DC gain mode

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/NonInverting324

 */

// use timer for sampling to get even time base for data
#include <FlexiTimer2.h>

// When SAMPLE_RAW_VALUE defined, sketch sends raw analog values.
// Comment this out and the sketch will send correclty scaled Vout readings
//#define SAMPLE_RAW_VALUE

// the pin we'll read Vout values from
const int read_v1_pin = A0;
const int read_v2_pin = A1;

// this is the actual value of the Arduino "5V" in millivolts.
// The Uno I'm using sends about 4.93V when powered by USB.
// Measure the 5V pin with a multimeter to check the value for the specific board used
const int vref_mv = 4930;


void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)

  pinMode(read_v1_pin, INPUT);          // enable Vout read
  pinMode(read_v2_pin, INPUT);          // enable Vout read

  FlexiTimer2::set(25, sample);         // set sampling procedure on timer interrupt
  FlexiTimer2::start();
}


void loop() {
  // do nothing
}

// temporary sampling storage
int v1_value = 0;
int v2_value = 0;
String result = "";

#ifndef SAMPLE_RAW_VALUE
  float v1 = 0.0;
  float v2 = 0.0;
#endif

// read the current value and send to the serial port
void sample() {
  v1_value = analogRead(read_v1_pin);
  v2_value = analogRead(read_v2_pin);

#ifdef SAMPLE_RAW_VALUE
  // sending vout_value (0-1023) because that is what PlotNValues expects.
  Serial.println(result + v1_value + "," + v2_value);
#else
  // To send the actual voltage, scaled by 2 to account for voltage divider
  v1 = map(v1_value, 0, 1023, 0, vref_mv) * 2.0;
  v2 = map(v2_value, 0, 1023, 0, vref_mv) * 2.0;
  Serial.println(result + v1 + "," + v2);
#endif

}
