/*

  Internals

  Dump to serial any and all internal details of the Arduino baord we can muster

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/Internals

 */

#include "quirks.h"

extern int __bss_end;
extern void *__brkval;

void setup() {
  Serial.begin(115200);
  dumpAll();
}

void loop() {
}

void dumpAll() {
  Serial.println("\n\nA Rundown of the Board Internals");
  hr();

  cpuDetails();
  memoryDetails();
  eepromDetails();
  hr();

  pinDetails();
  hr();
}

void hr() {
  Serial.println("--------------------------------");
}


/*
  cpuDetails
 */
void cpuDetails() {
  Serial.print("Clock speed: ");
  Serial.print(clockCyclesPerMicrosecond());
  Serial.println(" MHz");
}


/*
  memoryDetails
 */
void memoryDetails() {
  Serial.print("Free memory: ");
  Serial.print(memoryFree());
  Serial.println(" bytes");
}

/*
  Return the amount of free RAM
 */
int memoryFree()
{
  int freeValue;

  if((int)__brkval == 0)
     freeValue = ((int)&freeValue) - ((int)&__bss_end);
  else
    freeValue = ((int)&freeValue) - ((int)__brkval);

  return freeValue;
}

/*
 Dump EEPROM details
 see http://forum.arduino.cc/index.php?topic=120346.0
 */
void eepromDetails() {
  Serial.print("EEPROM memory: ");
#ifdef E2END
  Serial.print(E2END);
  Serial.println(" bytes");
#else
  Serial.println(" not available");
#endif
}

/*
  pinDetails
 */
void pinDetails() {

  Serial.print("Number of digital pins: ");
  Serial.println(NUM_DIGITAL_PINS);
  for(int p = 0; p < NUM_DIGITAL_PINS; p++) {
    Serial.print(p);
    Serial.print(":");
    if(digitalPinToInterrupt(p) != NOT_AN_INTERRUPT) {
      Serial.print(" (interrupt:");
      Serial.print(digitalPinToInterrupt(p));
      Serial.print(")");
    }
    if(p == LED_BUILTIN) Serial.print(" (internal LED)");
    if(digitalPinHasPWM(p)) Serial.print(" (PWM)");
    Serial.println();

  }
  Serial.print("Number of analog inputs: ");
  Serial.println(NUM_ANALOG_INPUTS);
  for(int p = 0; p < NUM_ANALOG_INPUTS; p++) {
    Serial.print("A");
    Serial.print(p);
    Serial.print(":");
    Serial.print(" (pin:");
    Serial.print(analogInputToDigitalPin(p));
    Serial.print(")");
    Serial.println();
  }

}
