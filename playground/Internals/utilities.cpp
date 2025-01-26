#include "utilities.h"


void hr(void) {
  Serial.println(F("--------------------------------"));
}


void showHex(const byte b, const boolean newline, const boolean show0x, const boolean trailing_space) {
  if (show0x)
    Serial.print(F("0x"));
  // try to avoid using sprintf
  char buf [4];
  buf [0] = ((b >> 4) & 0x0F) | '0';
  buf [1] = (b & 0x0F) | '0';
  if(trailing_space) buf[2] = ' ';
  else buf [2] = 0;
  buf [3] = 0;
  if (buf [0] > '9')
    buf [0] += 7;
  if (buf [1] > '9')
    buf [1] += 7;
  Serial.print(buf);
  if (newline) Serial.println();
}


void showYesNo(const boolean b, const boolean newline) {
  if (b)
    Serial.print(F("Yes"));
  else
    Serial.print(F("No"));
  if (newline)
    Serial.println();
}


void showHex4(const unsigned int value, const boolean newline) {
  Serial.print(F("0x"));
  if (value < 0x1000) { Serial.print(F("0")); };
  if (value < 0x0100) { Serial.print(F("0")); };
  if (value < 0x0010) { Serial.print(F("0")); };
  Serial.print(value, HEX);
  if (newline) Serial.println();
};
