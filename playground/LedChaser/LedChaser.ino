/*
  LED Chaser
  Blinks a simple array of LEDs connected directly to GPIO pins

  This example code is in the public domain.
 */

//
int myLeds[] = {2,3,4,5,6,7,8,9,10,11,12,13};
int pinCount = 12;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  for (int i = 0; i < pinCount; i++){
    pinMode(myLeds[i], OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i = 0; i < pinCount; i++){
    digitalWrite(myLeds[i], HIGH);
    delay(50);
    digitalWrite(myLeds[i], LOW);
  }
}
