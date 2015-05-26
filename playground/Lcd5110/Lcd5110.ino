/*

  Lcd5110
  Test driving a Nokia 5110 LCD Display with an Arduino.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/Lcd5110

 */

#define RST 12
#define CE 11
#define DC 10
#define DIN 9
#define CLK 8

#include "font.h"

#define N5110_CMD_FUNCTION_SET        0b00100000
#define N5110_CMD_FS_PD_OFF           0b00000000
#define N5110_CMD_FS_PD_ON            0b00000100
#define N5110_CMD_FS_ADDR_HORIZONTAL  0b00000000
#define N5110_CMD_FS_ADDR_VERTICAL    0b00000010
#define N5110_CMD_FS_INSTR_BASIC      0b00000000
#define N5110_CMD_FS_INSTR_EXTENDED   0b00000001

#define N5110_CMD_EXTENDED_COMMANDS   N5110_CMD_FUNCTION_SET ^ N5110_CMD_FS_PD_OFF ^ N5110_CMD_FS_ADDR_HORIZONTAL ^  N5110_CMD_FS_INSTR_EXTENDED // 0x21
#define N5110_CMD_BASIC_COMMANDS      N5110_CMD_FUNCTION_SET ^ N5110_CMD_FS_PD_OFF ^ N5110_CMD_FS_ADDR_HORIZONTAL ^  N5110_CMD_FS_INSTR_BASIC    // 0x20

// LCD Vop (contrast)
#define N5110_CMD_VOP                 0b10000000
#define N5110_CMD_VOP_MID             N5110_CMD_VOP ^ 0b00111111 // 0xB8

#define N5110_CMD_BIAS_SYSTEM         0b00010000
#define N5110_CMD_BS_1_40             N5110_CMD_BIAS_SYSTEM ^ 0b00000100 // 0x14

#define N5110_CMD_DISPLAY_CONFIG      0b00001000
#define N5110_CMD_DC_BLANK            N5110_CMD_DISPLAY_CONFIG
#define N5110_CMD_DC_NORMAL           N5110_CMD_DISPLAY_CONFIG ^ 0b00000100 // 0x0C
#define N5110_CMD_DC_ALL_ON           N5110_CMD_DISPLAY_CONFIG ^ 0b00000001 // 0x09
#define N5110_CMD_DC_INVERSE          N5110_CMD_DISPLAY_CONFIG ^ 0b00000101 // 0x0D

#define N5110_CMD_TH 0b00000111
#define N5110_CMD_TH_TROPICAL N5110_CMD_TH ^ 0b00000011 // 0x04

void LcdWrite(byte cmd, byte dc) {
  digitalWrite(DC, dc);
  digitalWrite(CE, LOW);
  shiftOut(DIN, CLK, MSBFIRST, cmd); //transmit serial data
  digitalWrite(CE, HIGH);
}

void LcdWriteCmd(byte cmd) {
  LcdWrite(cmd,LOW);
}

void LcdWriteData(byte cmd) {
  LcdWrite(cmd,HIGH);
}

void setup()
{
  pinMode(RST, OUTPUT);
  pinMode(CE, OUTPUT);
  pinMode(DC, OUTPUT);
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(RST, LOW);
  digitalWrite(RST, HIGH);
  LcdWriteCmd(N5110_CMD_EXTENDED_COMMANDS); // LCD extended commands
  LcdWriteCmd(N5110_CMD_VOP_MID); // set LCD Vop (contrast)
  LcdWriteCmd(N5110_CMD_TH_TROPICAL);
  LcdWriteCmd(N5110_CMD_BS_1_40);
  LcdWriteCmd(N5110_CMD_BASIC_COMMANDS);
  LcdWriteCmd(N5110_CMD_DC_NORMAL);
}

void loop() {
  LcdWriteData(0x55);
  LcdWriteData(0xAA);
}
