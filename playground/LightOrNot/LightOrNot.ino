/*
 Reads a photocell/light-dependent resistor and adjusts the 
 blink rate of an LED accordingly
 Based on http://arduino.cc/en/Tutorial/AnalogInput

 */

int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 2;       // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  Serial.begin(9600);       // enable serial comms for recording readings
}

void loop() {
  // read the value from the sensor and log the reading to serial
  sensorValue = analogRead(sensorPin);  
  Serial.println(sensorValue);  
  
  // blink the LED ata rate proportional to the sensor reading
  digitalWrite(ledPin, HIGH);  
  delay(sensorValue);          
  digitalWrite(ledPin, LOW);   
  delay(sensorValue);                  
}
