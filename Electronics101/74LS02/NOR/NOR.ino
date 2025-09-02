/*

  NOR7402
  Testing the 74LS02 Quad 2-input NOR gate with an Arduino

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/NOR7402

 */

#include <FlexiTimer2.h>

#define INPUT_A1 8
#define INPUT_B1 9
#define STEP_DELAY 240

const int y1_read_pin = A0;
volatile int ab = 0;

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)

  pinMode(INPUT_A1, OUTPUT);
  pinMode(INPUT_B1, OUTPUT);
  pinMode(y1_read_pin, INPUT);

  FlexiTimer2::set(10, sample);
  FlexiTimer2::start();
}

void loop() {
  for (ab=0; ab<4; ab++) {
    digitalWrite(INPUT_A1, ab & 1);
    digitalWrite(INPUT_B1, ab & 2);
    delay(STEP_DELAY);
  }
}

void sample() {
  String result = "";
  int a1_value = map((ab & 1),0,1,0,1023);
  int b1_value = map((ab & 2),0,2,0,1023);
  int y1_value = analogRead(y1_read_pin);
  Serial.println(result + a1_value + "," + b1_value + "," + y1_value);
}
