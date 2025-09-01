/*

  LED7Segment/DirectDrive

  Based on Arduino 7 segment display example software
  http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
  License: http://www.opensource.org/licenses/mit-license.php (Go crazy)

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/LED7Segment/DirectDrive

 */


// Define the LED digit patters, from 0 - 9
// Note that these patterns are for common cathode displays
// For common anode displays, change the 1's to 0's and 0's to 1's
// 1 = LED on, 0 = LED off, in this order:
//                    Arduino pin: 2,3,4,5,6,7,8
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                               };

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  clearDot();
  Serial.begin(115200);
}

void writeDot(byte dot) {
  digitalWrite(9, dot);
}

void clearDot() {
  writeDot(0);
}

void blinkDot(byte times) {
  for (byte count = 1; count <= times * 2; count++) {
    writeDot(count % 2);
    delay(1000);
  }
}


// set display to `digit` [0..9]
void sevenSegWrite(byte digit) {
  Serial.print("digit:");
  Serial.println(digit);
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void loop() {
  // countdown 9,8,7..0
  for (byte count = 10; count > 0; count--) {
    sevenSegWrite(count - 1);
    delay(1000);
  }
  blinkDot(4);
}
