/*
  tin_counter

  A project by [novaprimexex](https://github.com/novaprimexex) to count tins as they roll by and detect tins without paper labels.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/tin_counter

  HC-SR04 Ping distance sensor]
  VCC to arduino 5v GND to arduino GND
  Echo to Arduino pin 13 Trig to Arduino pin 12
  Red POS to Arduino pin 11
  Green POS to Arduino pin 10
  560 ohm resistor to both LED NEG and GRD power rail
*/

#define trigPin 13
#define echoPin 12
#define green 11
#define red 10
int count = 0;
int withoutLabel;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(withoutLabel, OUTPUT);
  pinMode(9, OUTPUT);
  beep(50);
  beep(50);
  delay(1000);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 12) {  // This is where the count happens
    count = count +1;
    Serial.println(count);
    delay (500);
  }
  if(count%4==0) {
    digitalWrite(green, HIGH);
    delay (500);
    digitalWrite(green, LOW);
  }
  int contact = analogRead(A0); //reading the voltage on pin A0, to know wether a can is in contact or not
  Serial.println(contact); //prints the value of the contact on the serial monitor(on screen)\

  delay(100);
  if(contact == 0){
    digitalWrite(red,HIGH);//red led on
    delay (500); //delay for half a second
    digitalWrite(red,  LOW); //turn off led
    beep (200);
  }
}


void beep(unsigned char delayms){
  analogWrite(9, 50);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms
}

