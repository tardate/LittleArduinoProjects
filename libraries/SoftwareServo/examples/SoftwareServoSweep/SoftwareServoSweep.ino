/*
 * SoftwareServoSweep
 * Sweeps a servo between the start_angle and end_angle using the SoftwareServo library.
 * Can be used to program a servo to sweep using an ATtiny microcontroller.
 * Adapted from the Servo Sweep example for the Servo.h library
 */
#include <SoftwareServo.h>

SoftwareServo myservo;  // creates name “my servo” as object to control a servo 
int pos = 0;            // variable to store the servo position 
int start_angle = 0;  
int end_angle = 180;
int servo_pin = 0;      // pin servo is attached to
int delay_time = 10; 

void setup() 
{ 
  myservo.attach(servo_pin);
} 


void loop() 
{
    for(int i=0; i<5; i++){
        for(pos = start_angle; pos <= end_angle; pos += 1)        // goes from 0 degrees to 180 degrees 
        {                                         // in steps of 1 degree 
          myservo.write(pos);                     // tell servo to go to position in variable 'pos' 
          delay(delay_time);                      
          SoftwareServo::refresh();               // required by SoftwareServo Library to sweep correctly
        }           
        delay (delay_time);                       // required by SoftwareServo Library to sweep correctly
        for(pos = end_angle; pos>=start_angle; pos-=1)  
        {                                
          myservo.write(pos);                     // tell servo to go to position in variable 'pos' 
          delay(delay_time);                      
          SoftwareServo::refresh();               // required by SoftwareServo Library to sweep correctly
        }
        delay(delay_time);                        // required by SoftwareServo Library to sweep correctly 
  }      
}  
