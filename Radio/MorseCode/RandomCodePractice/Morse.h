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

#pragma once

#include "Arduino.h"

class Morse
{
  public:
    Morse(byte pin, byte speed, byte beep);
    void sendmsg(char *str);
    void send(char c);
    void getCode(char c, char *buffer, byte buffer_len);
    void setSpeed(byte speed);
  private:
    byte _speed;  // Speed in WPM
    byte _pin;    // Pin to beep or toggle
    byte _beep;   // 1 == beep to speaker, 0 == toggle pin high and low
    int _dashlen; // Length of dash
    int _dotlen;  // Length of dot

    void dash();
    void dit();
    void bdash();
    void bdit();
};
