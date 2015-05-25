/*

  TransistorTester
  Capacitor tester with LCD output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/TransistorTester

 */

#include <LiquidCrystal.h>

#define VREF_MV 4930    // actual reference voltage of the board, in mV

#define E_PIN 3
#define B_PIN 4
#define C_PIN 5
#define E_READ_PIN A0
#define B_READ_PIN A1
#define C_READ_PIN A2

#define SETTLE_DELAY 50

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 7, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  //lcd.begin(16, 2); // set up the LCD's number of columns and rows
}

void loop() {
  testForNPN();
  testForPNP();
  delay(5000);
}

/*
  Run test to see if we have an NPN BJT present
 */
boolean testForNPN() {
  int ebaseReading;
  int cbaseReading;
  int emitterReading;
  int collectorReading;
  int bemV;
  int bcmV;

  Serial.println("testForNPN");
  // power the Base
  pinMode(B_PIN,OUTPUT);
  digitalWrite(B_PIN, HIGH);

  // test B->E
  pinMode(E_PIN,OUTPUT);
  digitalWrite(E_PIN, LOW);
  delay(SETTLE_DELAY);
  ebaseReading = analogRead(B_READ_PIN);
  emitterReading = analogRead(E_READ_PIN);
  pinMode(E_PIN,INPUT);

  // test B->C
  pinMode(C_PIN,OUTPUT);
  digitalWrite(C_PIN, LOW);
  delay(SETTLE_DELAY);
  cbaseReading = analogRead(B_READ_PIN);
  collectorReading = analogRead(C_READ_PIN);
  pinMode(C_PIN,INPUT);

  // reset base
  digitalWrite(B_PIN, LOW);
  pinMode(B_PIN,INPUT);

  bemV = (ebaseReading - emitterReading) / 1023.0 * VREF_MV;
  Serial.print("B_READ_PIN:"); Serial.println(ebaseReading);
  Serial.print("E_READ_PIN:"); Serial.println(emitterReading);
  Serial.print("bemV:"); Serial.println(bemV);

  bcmV = (cbaseReading - collectorReading) / 1023.0 * VREF_MV;
  Serial.print("B_READ_PIN:"); Serial.println(cbaseReading);
  Serial.print("C_READ_PIN:"); Serial.println(collectorReading);
  Serial.print("bcmV:"); Serial.println(bcmV);
  Serial.println("**\n");

  if(ebaseReading>1000) {
    Serial.println("** NPN not found **\n");
    return false;
  } else {
    Serial.println("** NPN found **");
    Serial.print("Vf forward voltage: ");
    Serial.print(bemV);
    Serial.println("mV\n");
    return false;
  }

}


/*
  Run test to see if we have an PNP BJT present
 */
boolean testForPNP() {
  int ebaseReading;
  int cbaseReading;
  int emitterReading;
  int collectorReading;
  int bemV;
  int bcmV;

  Serial.println("testForPNP");
  pinMode(B_PIN,OUTPUT);
  digitalWrite(B_PIN, LOW);

  // test E->B
  pinMode(E_PIN,OUTPUT);
  digitalWrite(E_PIN, HIGH);
  delay(SETTLE_DELAY);
  ebaseReading = analogRead(B_READ_PIN);
  emitterReading = analogRead(E_READ_PIN);
  pinMode(E_PIN,INPUT);

  // test C->B
  pinMode(C_PIN,OUTPUT);
  digitalWrite(C_PIN, HIGH);
  delay(SETTLE_DELAY);
  cbaseReading = analogRead(B_READ_PIN);
  collectorReading = analogRead(C_READ_PIN);
  pinMode(C_PIN,INPUT);

  // reset base
  pinMode(B_PIN,INPUT);

  bemV = (emitterReading - ebaseReading) / 1023.0 * VREF_MV;
  Serial.print("B_READ_PIN:"); Serial.println(ebaseReading);
  Serial.print("E_READ_PIN:"); Serial.println(emitterReading);
  Serial.print("bemV:"); Serial.println(bemV);

  bcmV = (collectorReading - cbaseReading) / 1023.0 * VREF_MV;
  Serial.print("B_READ_PIN:"); Serial.println(cbaseReading);
  Serial.print("C_READ_PIN:"); Serial.println(collectorReading);
  Serial.print("bcmV:"); Serial.println(bcmV);
  Serial.println("**\n");

  if(ebaseReading<100) {
    Serial.println("** PNP not found **\n");
    return false;
  } else {
    Serial.println("** PNP found **");
    Serial.print("Vf forward voltage: ");
    Serial.print(bemV);
    Serial.println("mV\n");
    return false;
  }

}
