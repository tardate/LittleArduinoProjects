/*

  QuadLatch
  Use an Arduino to demonstrate a basic 74LS75 Quad Latch driver circuit

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/QuadLatch

 */

#include <FlexiTimer2.h>                // use timer for sampling to get even time base for data

const int latch_pin = 2;                // latch enable pin for D1-D4
const int d1_pin = 6;                   // D1 input pin
const int d2_pin = 5;                   // D2 input pin
const int d3_pin = 4;                   // D3 input pin
const int d4_pin = 3;                   // D4 input pin

const int read_q1_pin = A0;             // the pin we'll read Q1 from
const int read_q2_pin = A1;             // the pin we'll read Q2 from
const int read_q3_pin = A2;             // the pin we'll read Q3 from
const int read_q4_pin = A3;             // the pin we'll read Q4 from

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)

  pinMode(latch_pin, OUTPUT);           // enable the output pins
  digitalWrite(latch_pin, LOW);         // start with enable LOW

  pinMode(d1_pin, OUTPUT);              // enable the output pins
  pinMode(d2_pin, OUTPUT);              // enable the output pins
  pinMode(d3_pin, OUTPUT);              // enable the output pins
  pinMode(d4_pin, OUTPUT);              // enable the output pins
  pinMode(read_q1_pin, INPUT);          // enable analog read
  pinMode(read_q2_pin, INPUT);          // enable analog read
  pinMode(read_q3_pin, INPUT);          // enable analog read
  pinMode(read_q4_pin, INPUT);          // enable analog read

  FlexiTimer2::set(50, sample);         // sample every 50ms
  FlexiTimer2::start();

}

byte data = 1;                          // data out accumulator

/*
 * each loop latches a new data value to D1-4
 */
void loop() {

  allPinsLow();
  if (data & B00001) digitalWrite(d1_pin, HIGH);
  if (data & B00010) digitalWrite(d2_pin, HIGH);
  if (data & B00100) digitalWrite(d3_pin, HIGH);
  if (data & B01000) digitalWrite(d4_pin, HIGH);

  digitalWrite(latch_pin, HIGH);
  digitalWrite(latch_pin, LOW);
  delay(800);

  // cycle to next data value. Our range is 1-16.
  data++;
  if (data>16) data = 1;

}

/*
 * set all the pins low
 */
void allPinsLow() {
  digitalWrite(d1_pin, LOW);
  digitalWrite(d2_pin, LOW);
  digitalWrite(d3_pin, LOW);
  digitalWrite(d4_pin, LOW);
}

// temp sampling storage
int q1_value = 0;
int q2_value = 0;
int q3_value = 0;
int q4_value = 0;
String result = "";

/*
 * asynchronously, read Q1-4 and send to serial port
 */
void sample() {
  // read the current value and send to the serial port
  q1_value = analogRead(read_q1_pin);
  q2_value = analogRead(read_q2_pin);
  q3_value = analogRead(read_q3_pin);
  q4_value = analogRead(read_q4_pin);
  Serial.println(result + q1_value + "," + q2_value + "," + q3_value + "," + q4_value);
}
