/*

  SpeechSynthesis/SYN6288Module
  Investigating the SYN6288 Chinese text to speech module with simple Arduino demonstration.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Audio/SpeechSynthesis/SYN6288Module

 */

#include "Syn6288.h"

Syn6288 syn;

// GBK encoded test
uint8_t text1[]={0xCF,0xA3,0xCD,0xFB,0xB4,0xF3,0xBC,0xD2,0xD0,0xC4,0xCF,0xEB,0xCA,0xC2,0xB3,0xC9,0xBD,0xA1,0xBD,0xA1,0xBF,0xB5,0xBF,0xB5}; //希望大家心想事成健健康康
uint8_t text2[]={0x6C,0x65,0x61,0x70,0x2E,0x74,0x61,0x72,0x64,0x61,0x74,0x65,0x2E,0x63,0x6F,0x6D}; //leap.tardate.com
uint8_t text3[]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39}; //0,1,2,3,4,5,6,7,8,9


/*
 * Command: one-time setup
 */
void setup() {
  Serial.begin(9600);
  syn.setBaud(19200);
  Serial.begin(19200);
}


/*
 * Command: main loop
 */
void loop() {
  syn.play(text1, sizeof(text1), 1);
  syn.play(text2, sizeof(text2), 2); delay(1800); // english seems to take longer
  syn.play(text3, sizeof(text3), 3);
}
