/*

  UsingServo8Bit
  NB: this doesn't work properly

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kinetics/ServoMotors/ATTinyServo

 */

#include <Servo8Bit.h>

static const int SERVO_PIN = 4; // PB4, pin 3 on the DIP8 ATTiny85
Servo8Bit myServo;  //create a servo object.

void setup() {
    myServo.attach(SERVO_PIN);

    myServo.write(0);   //rotate to the 0 degree position
    delay(2000);        //wait 2 seconds

    myServo.write(180); //rotate to the 180 degree position
    delay(2000);        //wait 2 seconds

    myServo.write(90);  //rotate to the center (90 degree) position
    delay(2000);        //wait 2 seconds
}

void loop() {
  for(int pos = 0; pos < 180; pos++)  // goes from 0 degrees to 180 degrees
  {                                   // in steps of 1 degree
      myServo.write(pos);             // tell servo to go to position in variable 'pos'
      delay(15);                      // waits 15ms for the servo to reach the position
  }

  for(int pos = 180; pos > 1; pos--)  // goes from 180 degrees to 0 degrees
  {
      myServo.write(pos);             // tell servo to go to position in variable 'pos'
      delay(15);                      // waits 15ms for the servo to reach the position
  }
}
