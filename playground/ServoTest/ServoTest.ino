/*
  ServoTest
  Test the positioning accuracy of a servo motor.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ServoTest

 */

#include <Servo.h>

#define SERVO_PIN 9
#define STEP_DELAY 1000

// custom min/max pulse width settings that best suit my servos
// NB: default vaules are min pulse width=544, max pulse width=2400
#define IDEAL_MIN_PW 600
#define IDEAL_MAX_PW 2320

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN,IDEAL_MIN_PW,IDEAL_MAX_PW);
  printInstructions();
}

void loop() {
  char ch;
  int pos;
  int new_min;
  int new_max;

  while (Serial.available() > 0) {
    ch = Serial.read();
    switch(ch) {
    case 'c':
      Serial.println("Centering servo..");
      centerServo();
      break;
    case 'l':
      Serial.println("Servo left (180)..");
      myservo.write(180);
      break;
    case 'r':
      Serial.println("Servo right (0)..");
      myservo.write(0);
      break;
    case 'a':
      new_min = Serial.parseInt();
      new_max = Serial.parseInt();
      Serial.print("Reattaching server with min pulse width = ");
      Serial.print(new_min);
      Serial.print(" and max pulse width = ");
      Serial.println(new_max);
      myservo.detach();
      myservo.attach(SERVO_PIN, new_min, new_max);
      break;
    case 'p':
      pos = Serial.parseInt();
      Serial.print("positioning servo to ");
      Serial.println(pos);
      myservo.write(pos);
      break;
    case '1':
      stepAroundCompass();
      break;
    case '2':
      continuousStepAroundCompass();
      break;
    case '?':
      printInstructions();
      break;
    }
  }
}

void centerServo() {
  myservo.write(90);
  delay(STEP_DELAY * 4);
}

void stepAroundCompass() {
  for(int step=0; step < 5; step++) {
    myservo.write(step * 45);
    delay(STEP_DELAY);
  }
  delay(STEP_DELAY * 3);
}

void continuousStepAroundCompass() {
  while(true) stepAroundCompass();
}


void printInstructions() {

  Serial.println("\n\nServoTest commands:");
  Serial.println("c : center servo");
  Serial.println("l : servo left");
  Serial.println("r : servo right");
  Serial.println("p<int> : move servo to <int> degrees");
  Serial.println("a <int> <int> : reattach servo with min/max pulse width");
  Serial.println("1 : behaviour 1 - step around compass");
  Serial.println("2 : behaviour 2 - continuous step sequence");

  Serial.print("\nmin pulse width:");
  Serial.println(MIN_PULSE_WIDTH);
  Serial.print("max pulse width:");
  Serial.println(MAX_PULSE_WIDTH);
  Serial.print("default pulse width:");
  Serial.println(DEFAULT_PULSE_WIDTH);
  Serial.print("refresh interval:");
  Serial.println(REFRESH_INTERVAL);
  Serial.print("Servo library version interval:");
  Serial.println(Servo_VERSION);

  Serial.print("current read degrees:");
  Serial.println(myservo.read());
  Serial.print("current read microseconds:");
  Serial.println(myservo.readMicroseconds());
  Serial.println("\nEnter a command: ");
}
