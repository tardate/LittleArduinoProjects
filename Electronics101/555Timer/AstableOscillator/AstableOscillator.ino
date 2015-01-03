/*

  Astable
  Uses an Arduino to monitor a classic a-stable 555 circuit and pipe the data to processing

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/555Timer/Astable

 */

const int result_pin = A0;              // the pin we'll read our result values from
int result_value = 0;

void setup() {
  Serial.begin(9600);                   // initialize serial communications at 9600 bps
  pinMode(result_pin, INPUT);           // enable the result_pin

}

void loop() {

  // read the current value and send to the serial port
  result_value = analogRead(result_pin);
  Serial.println(result_value);

  // wait a tic before going around again
  delay(1);

}
