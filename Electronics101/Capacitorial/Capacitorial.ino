/*

  Capacitorial
  Uses an Arduino to drive an RC circuit and measure the capcitive discharge.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/Capacitorial

 */

const int charge_pin = 8;               // the pin we'll drive our charging from
const int charge_time = 10;             // how long to charge the capacitor each time
const int charge_frequency = 200;       // frequency of the charging cycle
int charge_counter = 0;                 // keep track of the charging duty cycle

const int signal_pin = A0;              // the pin we'll read our charge values from

void setup() {
  Serial.begin(115200);                 // initialize serial communications (to match that used by PlotNValues.pde)
  pinMode(charge_pin, OUTPUT);          // enable the charge_pin
  pinMode(signal_pin, INPUT);           // enable the signal_pin

  digitalWrite(charge_pin, HIGH);       // start things off in charging mode
}

void loop() {

  // what to do at the end of the charging duty cycle - stop charging
  if(charge_counter == charge_time) {
    digitalWrite(charge_pin, LOW);
  }

  // what to do at the end of the charge cycle - reset
  if(charge_counter == charge_frequency) {
    digitalWrite(charge_pin, HIGH);
    charge_counter = 0;
  } else {
    charge_counter += 1;
  }

  // read the current value and send to the serial port
  Serial.println(analogRead(signal_pin));

  // wait a tic before going around again
  delay(1);
}
