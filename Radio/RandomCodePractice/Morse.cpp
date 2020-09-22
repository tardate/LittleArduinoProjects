//
// Arduino Morse Library
// Written by Erik Linder SM0RVV and Mark VandeWettering K6HX
// Contact: sm0rvv at google mail
//
// Released 2011 under GPLv3
//
// Version 0.2 - Erik Linder SM0RVV and Mark VandeWettering K6HX
// Version 0.2+1 - Corrected Morse Code errors , Glen Popiel KW5GP
// Version 0.2+2 - Restructure class members and added setSpeed method, Paul Gallagher
//
// Usage:
//         Morse <handle>(<outputpin>, <speed>);
//         <handle>.sendmsg (*str);
//         <handle>.send (*char);
//         <handle>.setSpeed (byte);

#include "Morse.h"

const byte _morsetab[] = { // Those with value 1 has no morsecode - code is decimal - but converted to reverse binary to send
  117, //ASCII 33 !
  82,  //ASCII 34 "
  1,   //ASCII 35 #
  200, //ASCII 36 $
  1,   //ASCII 37 %
  34,  //ASCII 38 &
  94,  //ASCII 39 '
  45,  //ASCII 40 (
  109, //ASCII 41 )
  1,   //ASCII 42 *
  42,  //ASCII 43 +
  115, //ASCII 44 ,
  97,  //ASCII 45 -
  106, //ASCII 46 .
  41,  //ASCII 47 /
  63,  //ASCII 48 0
  62,  //ASCII 49 1
  60,  //ASCII 50 2
  56,  //ASCII 51 3
  48,  //ASCII 52 4
  32,  //ASCII 53 5
  33,  //ASCII 54 6
  35,  //ASCII 55 7
  39,  //ASCII 56 8
  47,  //ASCII 57 9
  71,  //ASCII 58 :
  85,  //ASCII 59 ;
  1,   //ASCII 60 <
  49,  //ASCII 61 =
  1,   //ASCII 62 >
  76,  //ASCII 63 ?
  86,  //ASCII 64 @
  6,   //ASCII 65 A
  17,  //ASCII 66 B
  21,  //ASCII 67 C
  9,   //ASCII 68 D
  2,   //ASCII 69 E
  20,  //ASCII 70 F
  11,  //ASCII 71 G
  16,  //ASCII 72 H
  4,   //ASCII 73 I
  30,  //ASCII 74 J
  13,  //ASCII 75 K
  18,  //ASCII 76 L
  7,   //ASCII 77 M
  5,   //ASCII 78 N
  15,  //ASCII 79 O
  22,  //ASCII 80 P
  27,  //ASCII 81 Q
  10,  //ASCII 82 R
  8,   //ASCII 83 S
  3,   //ASCII 84 T
  12,  //ASCII 85 U
  24,  //ASCII 86 V
  14,  //ASCII 87 W
  25,  //ASCII 88 X
  29,  //ASCII 89 Y
  19,  //ASCII 90 Z
  1,   //ASCII 91 [
  64,  //ASCII 92 backslash
  1,   //ASCII 93 ]
  1,   //ASCII 94 ^
  108, //ASCII 95 _
  94,  //ASCII 96 `
  6,   //ASCII 97 a
  17,  //ASCII 98 b
  21,  //ASCII 99 c
  9,   //ASCII 100 d
  2,   //ASCII 101 e
  20,  //ASCII 102 f
  11,  //ASCII 103 g
  16,  //ASCII 104 h
  4,   //ASCII 105 i
  30,  //ASCII 106 j
  13,  //ASCII 107 k
  18,  //ASCII 108 l
  7,   //ASCII 109 m
  5,   //ASCII 110 n
  15,  //ASCII 111 o
  22,  //ASCII 112 p
  27,  //ASCII 113 q
  10,  //ASCII 114 r
  8,   //ASCII 115 s
  3,   //ASCII 116 t
  12,  //ASCII 117 u
  24,  //ASCII 118 v
  14,  //ASCII 119 w
  25,  //ASCII 120 x
  29,  //ASCII 121 y
  19,  //ASCII 122 z
  1,   //ASCII 123 left brace
  1,   //ASCII 124 vertical bar
  1,   //ASCII 125 right brace
  1,   //ASCII 126 tilde
};

byte getMorseValue(char c) {
  byte _i = ((byte) c) - 33;
  return _morsetab[_i];
}


Morse::Morse(byte pin, byte speed, byte beep)
{
  // Save values for later use
  _pin = pin;
  _beep = beep;

  setSpeed(speed);

  // Set the pin to output mode
  pinMode(_pin, OUTPUT);
}

// Returns the morse code for the given charater as a dit-dah string representation
// buffer provider must be pre-allocated and long enough for the code.
void Morse::getCode(char c, char *buffer, byte buffer_len)
{
  // fill buffer with blanks
  for (int i = 0; i < buffer_len - 1; ++i) buffer[i] = ' ';
  buffer[buffer_len - 1] = '\0';

  if (c == ' ') return;

  // Do a table lookup to get morse data
  byte _p = getMorseValue(c);
  byte code_index = 0;

  // Main algoritm for each morse sign
  while (_p != 1) {
    if (_p & 1) {
      buffer[code_index] = '_';
      // dash();
    } else {
      buffer[code_index] = '.';
      // dit();
    }
    if (code_index < buffer_len - 2) ++code_index;
    _p = _p / 2;
  }
}

// Updates the current speed in WPM
void Morse::setSpeed(byte speed)
{
  _speed = speed;

  // Calculate the length of dash and dot
  _dotlen = (1200/_speed);
  _dashlen =  (3*_dotlen);
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(_dashlen);
  digitalWrite(_pin, LOW);
  delay(_dotlen);
}

void Morse::dit()
{
  digitalWrite(_pin, HIGH);
  delay(_dotlen);
  digitalWrite(_pin, LOW);
  delay(_dotlen);
}

void Morse::bdash()
{
  analogWrite(_pin, 128);
  delay(_dashlen);
  analogWrite(_pin, 0);
  delay(_dotlen);
}

void Morse::bdit()
{
  analogWrite(_pin, 128);
  delay(_dotlen);
  analogWrite(_pin, 0);
  delay(_dotlen);
}

void Morse::send(char c)
{
  // Send space
  if (c == ' ') {
    delay(7*_dotlen) ;
    return ;
  }

  // Do a table lookup to get morse data
  byte _p = getMorseValue(c);

  // Main algoritm for each morse sign
  while (_p != 1) {
    if (_p & 1)
      switch (_beep) {
        case 0:
          dash();
          break;
        case 1:
          bdash();
          break;
        default:
          break;
      }
    else
      switch (_beep) {
        case 0:
          dit();
          break;
        case 1:
          bdit();
          break;
        default:
          break;
      }
    _p = _p / 2;
  }
  // Letterspace
  delay(2*_dotlen);
}

void Morse::sendmsg(char *str)
{
  while (*str) {
    send(*str++);
  }
}


