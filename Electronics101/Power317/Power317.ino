/*

  Power317
  Use an Arduino to read LM317 Vout and plot the results with Processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/Power317

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data


const int read_vout_pin = A0;           // the pin we'll read Vout values from

const int vref_mv = 4930;               // this is the actual value of the Arduino "5V" in millivolts.
                                        // the Uno I'm using sends about 4.93V when powered by USB
                                        // measure the 5V pin with a multimeter to check the specific board

void setup() {
  Serial.begin(9600);                   // initialize serial communications at 9600 bps

  pinMode(read_vout_pin, INPUT);        // enable Vout read

  FlexiTimer2::set(50, sample);         // sample every 50ms
  FlexiTimer2::start();
}

void loop() {
}

// temp sampling values
int vout_value = 0;
float vout = 0.0;
String result = "";

// read the current value and send to the serial port
void sample() {
  vout_value = analogRead(read_vout_pin);
  vout = map(vout_value, 0, 1023, 0, vref_mv) * 2.0;

  // sending vout_value (0-1023) because that is what PlotNValues expects.
  Serial.println(result + vout_value);
  // To send the actual voltage, do this instead:
  // Serial.println(result + vout);
}
