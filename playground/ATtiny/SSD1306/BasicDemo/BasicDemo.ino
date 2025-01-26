/*

  ATtiny/SSD1306/BasicDemo
  Basic demonstration using an ATtiny to drive an SSD1306 OLED over I²C

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/ATtiny/SSD1306/BasicDemo

 */

#include <TinyWireM.h>
#include <Tiny4kOLED.h>

void setup() {
  oled.begin();
  oled.setFont(FONT6X8);

  // To clear all the memory, clear both rendering frames:
  oled.clear();
  oled.switchRenderFrame();
  oled.clear();
  oled.switchRenderFrame();

  oled.on();
}

void loop() {
  demoGraphics();
  demoPositionedText();
}

void demoGraphics() {
  oled.clear();
  oled.setCursor(0, 2);
  oled.startData();
  for (uint8_t i = 0; i < 16; i++) {
    oled.sendData(0x02);
    oled.sendData(0x02);
    oled.sendData(0x02);
    oled.sendData(0x0C);
    oled.sendData(0x10);
    oled.sendData(0x10);
    oled.sendData(0x10);
    oled.sendData(0x0C);
  }
  oled.endData();
  delay(600);
}

void demoPositionedText() {
  oled.clear();
  for(int i = 0; i < 5; ++i) {
    oled.setCursor(5 * i, i);
    oled.print(F("Demo!")); // 5 characters x 6 pixels = 30 pixels
  }
  delay(1000);
  oled.setInverse(true);
  delay(1000);
  oled.setInverse(false);
}
