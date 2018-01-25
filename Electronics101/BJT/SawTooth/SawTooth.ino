/*

  SawTooth
  Testing a simple BJT saw-tooth oscillator

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BJT/SawTooth

 */

#include <FlexiTimer2.h>       // use timer for sampling to get even time base for data

#define TRACE_COUNT   1        // 1,2,..6 - the number of values to sample from analog inputs A0,1,..5 respectively
#define INPUT1_PIN   A0        // the first analog input.

#define SAMPLING_FREQUENCY 10  // milliseconds

void setup() {
  Serial.begin(115200);                           // initialize serial communications (to match that used by PlotNValues.pde)
  FlexiTimer2::set(SAMPLING_FREQUENCY, sample);   // set sampling procedure on timer interrupt
  FlexiTimer2::start();
}

void loop() {
  // do nothing
}

/*
  Command: read the current values and send to the serial port.
  This sends raw values (0-1023) because that is what PlotNValues processing script expects.
 */
void sample() {
  String result = "";
  for(int i=0; i < TRACE_COUNT; i++) {
    if(i>0) result += ",";
    result += analogRead(INPUT1_PIN + i);
  }
  Serial.println(result);
}
