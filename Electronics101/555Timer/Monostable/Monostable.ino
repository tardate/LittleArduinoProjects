/*

  Monostable
  Uses an Arduino to drive a monostable 555 circuit and pipe the output to processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/555Timer/Monostable

*/

const int trigger_pin = 2;              // trigger pin
const int cycle_length = 200;           // how long per cycle
const int trigger_at = 180;             // when to trigger
int step_counter = 0;                   // keep track of the cycle

const int max_value = 1023;             // the value of trigger "high"
int trigger_value = max_value;          // keep track of the trigger value

const int result_pin = A0;              // the pin we'll read our result values from
int result_value = 0;

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)
  pinMode(result_pin, INPUT);           // enable the result_pin

  pinMode(trigger_pin, OUTPUT);         // enable the trigger pin
  digitalWrite(trigger_pin, HIGH);      // start things off high
}

void loop() {

  // flip the trigger (pull low)
  if(step_counter == trigger_at) {
    digitalWrite(trigger_pin, LOW);
    trigger_value = 0;
  }

  // reset
  if(step_counter == cycle_length) {
    digitalWrite(trigger_pin, HIGH);
    step_counter = 0;
    trigger_value = max_value;
  } else {
    step_counter += 1;
  }

  // read the current values and send to the serial port
  String result = "";
  result_value = analogRead(result_pin);
  Serial.println(result + trigger_value + "," + result_value);

  // wait a tic before going around again
  delay(1);
}
