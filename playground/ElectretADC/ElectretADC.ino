/*

  ElectretADC
  Use an Arduino to monitor the raw and amplified electret mic signal

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ElectretADC

 */

// use timer for sampling to get even time base for data
#include <FlexiTimer2.h>

// the pin we'll read values from
const int read_v1_pin = A0;
const int read_v2_pin = A1;

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)

  pinMode(read_v1_pin, INPUT);          // enable voltage read
  pinMode(read_v2_pin, INPUT);          // enable voltage read

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

// read the current value and send to the serial port
void sample() {
  v1_value = analogRead(read_v1_pin);
  v2_value = analogRead(read_v2_pin);

  // sending vout_value (0-1023) because that is what PlotNValues expects.
  Serial.println(result + v1_value + "," + v2_value);

}
