/*

  SwitchNPN
  Uses an Arduino to drive a simple NPN switch and measure the output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/SwitchNPN

 */

// use timer for sampling to get even time base for data
#include <FlexiTimer2.h>

const int data_pin = 7;

// When SAMPLE_RAW_VALUE defined, sketch sends raw analog values.
// Comment this out and the sketch will send correclty scaled Vout readings
#define SAMPLE_RAW_VALUE

// the pin we'll read Vout values from
const int read_vout_pin = A0;

// this is the actual value of the Arduino "5V" in millivolts.
// The Uno I'm using sends about 4.93V when powered by USB.
// Measure the 5V pin with a multimeter to check the value for the specific board used
const int vref_mv = 4930;


void setup() {
  Serial.begin(9600);                   // initialize serial communications at 9600 bps

  pinMode(data_pin, OUTPUT);            // enable the data pin
  pinMode(read_vout_pin, INPUT);        // enable Vout read

  FlexiTimer2::set(50, sample);         // sample every 50ms
  FlexiTimer2::start();
}


void loop() {
  // flip the switch every second
  digitalWrite(data_pin, HIGH);
  delay(1000);
  digitalWrite(data_pin, LOW);
  delay(1000);
}


// temporary sampling storage
int vout_value = 0;
float vout = 0.0;
String result = "";

// read the current value and send to the serial port
void sample() {
  vout_value = analogRead(read_vout_pin);

#ifdef SAMPLE_RAW_VALUE
  // sending vout_value (0-1023) because that is what PlotNValues expects.
  Serial.println(result + vout_value);
#else
  // To send the actual voltage, scaled to actual max voltage vref_mv
  vout = map(vout_value, 0, 1023, 0, vref_mv);
  Serial.println(result + vout);
#endif

}
