/*

  SimplestInverter
  Uses an Arduino to drive the simplest 1-transistor inverter circuit and measure the output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/SimplestInverter

 */

const int i1_pin = 8;                   // input pin
const int cycle_length = 200;           // how often to step the input values
int step_counter = 0;                   // keep track of the charging duty cycle
int i1_value = 0;
const int max_value = 1023;

const int result_pin = A0;              // the pin we'll read our result values from
int result_value = 0;

void setup() {
  Serial.begin(9600);                   // initialize serial communications at 9600 bps
  pinMode(i1_pin, OUTPUT);              // enable the input pins
  pinMode(result_pin, INPUT);           // enable the result_pin

  digitalWrite(i1_pin, LOW);            // start things off low
  i1_value = 0;
}

void loop() {

  // flip to hi
  if(step_counter == cycle_length / 2) {
    digitalWrite(i1_pin, HIGH);
    i1_value = max_value;
  }

  // reset
  if(step_counter == cycle_length) {
    digitalWrite(i1_pin, LOW);
    step_counter = 0;
    i1_value = 0;
  } else {
    step_counter += 1;
  }

  // read the current value and send to the serial port
  String result = "";
  result_value = analogRead(result_pin);
  Serial.println(result + i1_value + "," + result_value);

  // wait a tic before going around again
  delay(1);
}
