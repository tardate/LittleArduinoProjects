/*

  MonostablePulseExtender
  test the behaviour of a 74LS122 monostable with external timing configuration and plot the results

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/MonostablePulseExtender

 */

#include <FlexiTimer2.h> // use timer for sampling to get even time base for data

#define SIGNAL_PIN 7
#define SIGNAL_MIN_DURATION 60
#define SIGNAL_MIN_DELAY 1500
const int QREAD_PIN = A0;

volatile int signal_state = 0;

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)

  pinMode(SIGNAL_PIN, OUTPUT);
  digitalWrite(SIGNAL_PIN, LOW);

  FlexiTimer2::set(30, sample);
  FlexiTimer2::start();

}

void loop() {
  signal(1);
  signal(2);
  signal(1);
  signal(4);
}

void signal(int factor) {
  signal_state = 1;
  digitalWrite(SIGNAL_PIN, HIGH);
  delay(SIGNAL_MIN_DURATION * factor);
  digitalWrite(SIGNAL_PIN, LOW);
  signal_state = 0;
  delay(SIGNAL_MIN_DELAY * factor);
}

void sample() {
  int trigger_value = map(signal_state,0,1,0,1023);
  int qread_value = analogRead(QREAD_PIN);
  String result = "";
  Serial.println(result + trigger_value + "," + qread_value);
}
