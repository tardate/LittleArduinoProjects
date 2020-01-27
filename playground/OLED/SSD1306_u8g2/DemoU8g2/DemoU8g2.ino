/*

  OLED/SSD1306_u8g2/DemoU8g2
  Testing the u8g2 library with a 132x32 OLED display

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/OLED/SSD1306_u8g2/DemoU8g2

 */

#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);


/*
 * Command: one-time setup
 */
void setup() {
  u8g2.begin();
}


/*
 * Command: main loop
 */
void loop() {
  static int counter = 0;

  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_helvB08_tr);
    u8g2.setCursor(0, 8);
    u8g2.print((int)u8g2.getCols());
    u8g2.print("x");
    u8g2.print((int)u8g2.getRows());
    u8g2.print(" count: ");
    u8g2.print(counter);

    u8g2.setFont(u8g2_font_open_iconic_play_2x_t);
    u8g2.drawStr(0, 32, "DEFGHIJK"); // cheat: map chars to icons per https://github.com/olikraus/u8g2/wiki/fntgrpiconic#open_iconic_play_2x
  } while (u8g2.nextPage());

  delay(1000);
  ++counter;
}
