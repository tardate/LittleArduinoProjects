/*

  TFT/Color128x128
  Demo using the TFT_ILI9163C library - based on example from http://henrysbench.capnfatz.com/henrys-bench/arduino-displays/arduino-1-44-in-spi-tft-display-tutorial/

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/TFT/Color128x128

 */

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

#define BLUE    (0x001F)
#define CYAN      (0x07FF)
#define WHITE     (0xFFFF)
#define CS_PIN    (10)
#define DC_PIN    (9)
#define RESET_PIN (8)

TFT_ILI9163C tftScreen = TFT_ILI9163C(CS_PIN, DC_PIN, RESET_PIN);

void setup() {
  tftScreen.begin();
  tftScreen.fillScreen(BLUE);
}

int counter = 0;

void loop(){
  testText();
  delay(500);
  counter++;
}

void testText() {
  tftScreen.setTextColor(WHITE);
  tftScreen.setTextSize(1);
  tftScreen.setCursor(15, 43);
  tftScreen.println("TFT_ILI9163C Demo");
  tftScreen.setCursor(29, 63);
  tftScreen.println("Hello World!");
  tftScreen.fillRect(29, 83, 50, 10, BLUE);
  tftScreen.setCursor(29, 83);
  tftScreen.println(counter);
}