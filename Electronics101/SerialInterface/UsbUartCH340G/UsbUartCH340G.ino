/*
  UsbUartCH340G
  A blink sketch that also sends a burst of data over the serial port.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/SerialInterface/UsbUartCH340G
 */

#define LED_PIN 13

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  for(int i=0; i< 50; ++i) {
    Serial.println("high......");
    delay(10);
  }
  digitalWrite(LED_PIN, LOW);
  delay(200);
}
