/*

  UsingTextFinder

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/UsingTextFinder

 */

#include <TextFinder.h>

TextFinder finder(Serial);


/*
 * Command: one-time setup
 */
void setup() {
  Serial.begin(115200);
}


/*
 * Command: main loop
 */
void loop() {
  readIntegers();
}


/*
 * Command: read a list of integers
 */
void readIntegers() {
  const int NUMBER_OF_FIELDS = 3; // how many comma separated fields we expect
  int values[NUMBER_OF_FIELDS];   // array holding values for all the fields

  int fieldIndex = 0;

  Serial.print(F("Enter 3 comma-separated numbers. Waiting..."));

  while(fieldIndex < NUMBER_OF_FIELDS) {
    values[fieldIndex++] = finder.getValue();
  }

  Serial.println(F("\nAll fields received:"));
  for (fieldIndex=0; fieldIndex < NUMBER_OF_FIELDS; fieldIndex++) {
    Serial.println(values[fieldIndex]);
  }
}
