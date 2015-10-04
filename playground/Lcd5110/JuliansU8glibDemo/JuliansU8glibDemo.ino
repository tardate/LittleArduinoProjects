/*

  Lcd5110/JuliansU8glibDemo
  Quick test drive of Julian Ilett's 5110 LCD demo with the u8glib library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/Lcd5110/JuliansU8glibDemo

 */

#include "U8glib.h"

U8GLIB_PCD8544 u8g(13, 11, 10, 9, 8);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8

void setup() {
}

void loop() {
  static unsigned long thisMicros = 0;
  static unsigned long lastMicros = 0;

  // picture loop
  u8g.firstPage();
  do {
    u8g.setContrast(128);
    u8g.drawRFrame(0, 0, 84, 17, 3);   //Data1 frame
    u8g.drawRFrame(51, 16, 33, 10, 3); //Data1 label frame
    u8g.drawRFrame(0, 22, 33, 10, 3);  //Data2 label frame
    u8g.drawRFrame(0, 31, 84, 17, 3);  //Data2 frame
    u8g.setFont(u8g_font_5x7);
    u8g.drawStr(55, 24, "Data1");
    u8g.drawStr(4, 30, "Data2");
    u8g.setFont(u8g_font_10x20);
    u8g.setPrintPos(2, 15);
    u8g.print(thisMicros - lastMicros);
    u8g.setPrintPos(2, 46);
    u8g.print(thisMicros - lastMicros);
  } while( u8g.nextPage() );

  lastMicros = thisMicros;
  thisMicros = micros();
  delay(250);
}