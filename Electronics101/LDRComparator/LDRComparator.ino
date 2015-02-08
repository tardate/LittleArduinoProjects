/*

  LDRComparator
  Low-light Detector - monitor an LDR/Wheatstone Bridge with comparator output evaluation

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/LDRComparator

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int ldr_trigger_pin = 7;          // input pin to read output of comparator
const int vldr_read_pin = A0;           // input pin to read the voltage at the base of the LDR

void setup() {
  Serial.begin(9600);

  // enable the input pins
  pinMode(ldr_trigger_pin, INPUT);
  pinMode(vldr_read_pin, INPUT);

  FlexiTimer2::set(15, sample);         // sample every 10ms
  FlexiTimer2::start();

}

void loop() {
 // nop
}

// temp sampling storage
//boolean ldr_trigger = false;
int ldr_value = 0;
int vldr_value = 0;
String result = "";

// read the current values
void sample() {
  ldr_value = map(digitalRead(ldr_trigger_pin),0,1,0,1023);
  vldr_value = analogRead(vldr_read_pin);
  Serial.println(result + vldr_value + "," + ldr_value);
}
