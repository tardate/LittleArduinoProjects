/*

  BasicAND
  Use an Arduino to demonstrate the most basic transistor AND gate, and plot the results with Processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BasicAND

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int i1_pin = 8;                   // input 1 pin to drive
const int i2_pin = 9;                   // input 2 pin to drive

const int read_i1_pin = A0;             // the pin we'll read ouput values from
const int read_i2_pin = A1;             // the pin we'll read ouput values from
const int read_output_pin = A2;         // the pin we'll read ouput values from

void setup() {
  Serial.begin(9600);                   // initialize serial communications at 9600 bps

  pinMode(i1_pin, OUTPUT);              // enable the input pins
  pinMode(i2_pin, OUTPUT);              // enable the input pins
  pinMode(read_i1_pin, INPUT);          // enable analog read
  pinMode(read_i2_pin, INPUT);          // enable analog read
  pinMode(read_output_pin, INPUT);      // enable analog read

  FlexiTimer2::set(50, sample);         // sample every 10ms
  FlexiTimer2::start();

}

void loop() {

  // 0 0
  digitalWrite(i1_pin, LOW);
  digitalWrite(i2_pin, LOW);
  delay(1000);
  // 0 1
  digitalWrite(i2_pin, LOW);
  digitalWrite(i1_pin, HIGH);
  delay(1000);
  // 1 0
  digitalWrite(i1_pin, LOW);
  digitalWrite(i2_pin, HIGH);
  delay(1000);
  // 1 1
  digitalWrite(i1_pin, HIGH);
  digitalWrite(i2_pin, HIGH);
  delay(1000);

}

// temp sampling storage
int i1_value = 0;
int i2_value = 0;
int output_value = 0;
String result = "";

void sample() {
  // read the current value and send to the serial port
  i1_value = analogRead(read_i1_pin);
  i2_value = analogRead(read_i2_pin);
  output_value = analogRead(read_output_pin);
  Serial.println(result + i1_value + "," + i2_value + "," + output_value);
}
