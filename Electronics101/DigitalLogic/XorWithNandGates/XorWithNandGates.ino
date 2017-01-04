/*

  DigitalLogic/XorWithNandGates
  Construct an XOR gate with only an 74LS132 quad NAND gate, and demonstrate it's behaviour with an Arduino and Processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/DigitalLogic/XorWithNandGates

 */

// use FlexiTimer2 for sampling to get even time base for data
#include <FlexiTimer2.h>

// control pins
const int A_pin = 5;
const int B_pin = 6;

// data sampling pins
const int A_in_pin = A0;
const int B_in_pin = A1;
const int OUT_pin = A2;

const int STEP_DELAY = 500;

void setup() {
  // initialize serial communications (to match that used by PlotNValues.pde)
  Serial.begin(115200);

  // set pin modes
  pinMode(A_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);
  pinMode(A_in_pin, INPUT);
  pinMode(B_in_pin, INPUT);
  pinMode(OUT_pin, INPUT);

  // set the timer callback frequency in ms and function
  FlexiTimer2::set(10, sample);
  FlexiTimer2::start();
}

void loop() {
  for (int ab=0; ab<4; ab++) {
    digitalWrite(A_pin, ab & 1);
    digitalWrite(B_pin, ab & 2);
    delay(STEP_DELAY);
  }
}


String result = "";
int A_in_value = 0;
int B_in_value = 0;
int OUT_value = 0;

void sample() {
  // read the current value and send to the serial port
  A_in_value = analogRead(A_in_pin);
  B_in_value = analogRead(B_in_pin);
  OUT_value = analogRead(OUT_pin);
  Serial.println(result + A_in_value + "," + B_in_value + "," + OUT_value);
}
