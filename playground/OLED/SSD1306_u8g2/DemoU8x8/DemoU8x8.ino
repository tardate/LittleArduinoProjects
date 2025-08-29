/*

  OLED/SSD1306_u8g2/DemoU8x8
  Testing the u8x8 library with a 132x32 OLED display

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/OLED/SSD1306_u8g2/DemoU8x8

 */

#include <U8x8lib.h>

U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(U8X8_PIN_NONE);


/*
 * Command: one-time setup
 */
void setup() {
  u8x8.begin();
}


/*
 * Command: main loop
 */
void loop() {
  static int counter = 0;

  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(0, 0);
  u8x8.print((int)u8x8.getCols());
  u8x8.print("x");
  u8x8.print((int)u8x8.getRows());
  u8x8.print(" count:");
  u8x8.print(counter);

  u8x8.setFont(u8x8_font_open_iconic_play_2x2);
  u8x8.drawString(0, 2, "DEFGHIJK");  // cheat: map chars to icons per https://github.com/olikraus/u8g2/wiki/fntgrpiconic#open_iconic_play_2x2

  delay(1000);
  ++counter;
}
