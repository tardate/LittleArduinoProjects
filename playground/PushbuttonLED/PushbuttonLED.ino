/*
 Reads a digital input on pin 2, and toggle LED 
 
 This example code is in the public domain.
 */

int pushButton = 2;   // digital pin 2 has a pushbutton attached to it
int buttonStatus = 0; // track button status
int led = 11;         // pin for LED
int ledStatus = 0;    // track status. 0==off, 1==on

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:
  pinMode(pushButton, INPUT); // pushbutton's pin an input
  pinMode(led, OUTPUT);       // led pin an output
}

// the loop routine runs over and over again forever:
void loop() {
  int buttonState = digitalRead(pushButton); // read the input pin
  
  if(buttonState!=buttonStatus) {
    // status has changed
    buttonStatus = buttonState;
    if(buttonStatus==1) toggleLed();
  }
  
  log(buttonState);
  delay(10);        // delay in between reads for stability
}

void toggleLed() {
  if(ledStatus==0) {
    digitalWrite(led, HIGH);
    ledStatus=1;
  } else {
    digitalWrite(led, LOW);
    ledStatus=0;
  }
}

void log(int buttonState) {
  Serial.print("ledStatus: ");
  Serial.print(ledStatus);
  Serial.print(", buttonStatus: ");
  Serial.print(buttonStatus);
  Serial.print(", buttonState: ");
  Serial.println(buttonState);
}



