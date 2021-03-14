/*

  LCD/I2CAdapter
  Using an I²C adapter to reduce the Arduino pins needed to drive an LCD.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LCD/I2CAdapter

 */

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

const int PAGE_DELAY = 2000;

String lines[][2] = {
  {"Once upon a",      "midnight dreary"},
  {"while I pondered", "weak and weary"},
  {"Over many a",      "quaint and"},
  {"curious volume o", "forgotten lore"},
  {"While I nodded",   "nearly napping"},
  {"suddenly there",   "came a tapping"},
  {"As of some one",   "gently rapping"},
  {"rapping at my",    "chamber door"},
  {"Tis some visitor", "I muttered"},
  {"tapping at my",    "chamber door"},
  {"Only this, and",   "nothing more"}
};

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  recite();
}

void recite() {
  for(int page=0; page < 11; page++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lines[page][0]);
    lcd.setCursor(0, 1);
    lcd.print(lines[page][1]);
    delay(PAGE_DELAY);
  }
  delay(PAGE_DELAY);
}
