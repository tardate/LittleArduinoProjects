/*

  TransistorTester
  Tests NPN and PNP transistors with LCD output.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/TransistorTester

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
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  setWaiting();
}

void loop() {
  testForNPN() || testForPNP() || setFailedResult();
  delay(1000);
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
    return false;
  } else {
    setResult(1,bemV);
    return true;
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

  bemV = (ebaseReading - emitterReading) / 1023.0 * VREF_MV;
  Serial.print("B_READ_PIN:"); Serial.println(ebaseReading);
  Serial.print("E_READ_PIN:"); Serial.println(emitterReading);
  Serial.print("bemV:"); Serial.println(bemV);

  bcmV = (cbaseReading - collectorReading) / 1023.0 * VREF_MV;
  Serial.print("B_READ_PIN:"); Serial.println(cbaseReading);
  Serial.print("C_READ_PIN:"); Serial.println(collectorReading);
  Serial.print("bcmV:"); Serial.println(bcmV);
  Serial.println("**\n");

  if(ebaseReading<100) {
    return false;
  } else {
    setResult(2,bemV);
    return true;
  }

}

void setWaiting() {
  lcd.clear();
  lcd.print("Insert a BJT..");
}

void setResult(int bjt_type, int vf) {
  lcd.clear();
  switch(bjt_type) {
  case 1: // NPN
    lcd.print("NPN Vf=");
    break;
  case 2:
    lcd.print("PNP Vf=");
    break; // NPN
  default: // unidentified
    lcd.print("** no/bad BJT **");
    lcd.setCursor(0, 1);
    lcd.print("Insert to test..");
    return;
  }
  lcd.print(vf);
  lcd.print("mV");
  lcd.setCursor(0, 1);
  lcd.print("Test another..");
}

boolean setFailedResult() {
  setResult(0,0);
  return true;
}
