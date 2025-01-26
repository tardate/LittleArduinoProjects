#pragma once

#include <Arduino.h>

void hr(void);

void showHex(const byte b, const boolean newline = false, const boolean show0x = true, const boolean trailing_space = true);
void showHex(const byte b, const boolean newline, const boolean show0x, const boolean trailing_space);
void showHex4(const unsigned int value, const boolean newline = false);
void showHex4(const unsigned int value, const boolean newline);

void showYesNo(const boolean b, const boolean newline = false);
void showYesNo(const boolean b, const boolean newline);
