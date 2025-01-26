#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "Syn6288.h"
#include <stdio.h>
#include <arduino.h>

uint8_t head[5] =  {0xfd, 0x00, 0x00, 0x01, 0x00};
uint16_t boud[5] = {0xfd, 0x00, 0x03, 0x31, 0x00};

void Syn6288::play(uint8_t *text, uint8_t text_length, uint8_t music) {
  pi=0;
  delay(100);
  head[2] = text_length + 3;
  switch(music) {
    case 0: head[4]=0x01;break;
    case 1: head[4]=0x09;break;
    case 2: head[4]=0x11;break;
    case 3: head[4]=0x19;break;
    case 4: head[4]=0x21;break;
    case 5: head[4]=0x29;break;
    case 6: head[4]=0x31;break;
    case 7: head[4]=0x39;break;
    case 8: head[4]=0x41;break;
    case 9: head[4]=0x49;break;
    case 10: head[4]=0x51;break;
    case 11: head[4]=0x59;break;
    case 12: head[4]=0x61;break;
    case 13: head[4]=0x69;break;
    case 14: head[4]=0x71;break;
    case 15: head[4]=0x79;break;
  }
  for(int i=0;i<5;i++) {
    pi^=head[i];
    Serial.write(head[i]);
    delay(2);
  }
  for(int j=0;j<text_length;j++) {
    pi^=text[j];
    Serial.write(text[j]);
    delay(2);
  }
  Serial.write(pi);
  delay(300 * text_length);
}

void Syn6288::setBaud(uint16_t boudr) {
	uint8_t p;
  p=0;
  switch(boudr) {
    case 9600:
      boud[4]=0x00;
      break;
    case 19200:
      boud[4]=0x01;
      break;
  }
  for(int z=0;z<HEADLEN;z++) {
    p^=boud[z];
    Serial.write(boud[z]);
    delay(2);
  }
  Serial.write(p);
  p=0;
  for(int z=0;z<HEADLEN;z++) {
    p^=boud[z];
    Serial.write(boud[z]);
    delay(2);
  }
  Serial.write(p);
  delay(200);
}
