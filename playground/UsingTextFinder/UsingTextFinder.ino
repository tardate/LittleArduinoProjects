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
  Serial.println(F("\n\n*** TextFinder Demo ***"));

  readInteger();
  readIntegers();
  readFloat();
  readString();
}


/*
 * Command: read an integer
 */
void readInteger() {
  int value;

  Serial.println();
  Serial.println(F("Enter an integer ->"));
  value = finder.getValue();

  Serial.print(F("\nReceived: "));
  Serial.println(value);
}


/*
 * Command: read a list of integers
 */
void readIntegers() {
  const int NUMBER_OF_FIELDS = 3;
  int values[NUMBER_OF_FIELDS];

  int fieldIndex = 0;

  Serial.println();
  Serial.println(F("Enter 3 comma-separated numbers ->"));

  while(fieldIndex < NUMBER_OF_FIELDS) {
    values[fieldIndex++] = finder.getValue();
  }

  Serial.println(F("\nReceived:"));
  for (fieldIndex=0; fieldIndex < NUMBER_OF_FIELDS; fieldIndex++) {
    Serial.println(values[fieldIndex]);
  }
}


/*
 * Command: read a float
 */
void readFloat() {
  float value;

  Serial.println();
  Serial.println(F("Enter a floating point number ->"));
  value = finder.getFloat();

  Serial.print(F("\nReceived: "));
  Serial.println(value);
}


/*
 * Command: read a string
 */
void readString() {
  const int STRING_LENGTH = 31;
  char value[STRING_LENGTH];

  Serial.println();
  Serial.println(F("Enter a string ->"));
  finder.getString("\n", value, STRING_LENGTH);

  Serial.print(F("\nReceived: "));
  Serial.println(value);
}
