/*

  Lcd5110/JuliansU8glibDemo
  Quick test drive of Julian Ilett's 5110 LCD demo with the u8glib library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/Lcd5110/JuliansU8glibDemo

 */

#include "U8glib.h"

const int LCD_SCK   = 13;
const int LCD_MOSI  = 11;
const int LCD_CS    = 10;
const int LCD_A0    = 9;
const int LCD_RESET = 8;

U8GLIB_PCD8544 u8g(LCD_SCK, LCD_MOSI, LCD_CS, LCD_A0, LCD_RESET);

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
