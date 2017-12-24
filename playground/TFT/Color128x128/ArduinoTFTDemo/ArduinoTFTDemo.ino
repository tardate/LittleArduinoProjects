/*

  TFT/Color128x128/ArduinoTFTDemo
  Demo using the Arduino TFT library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/TFT/Color128x128

 */

#include <SPI.h>
#include <TFT.h>

#define CS_PIN    (10)
#define DC_PIN    (9)
#define RESET_PIN (8)

TFT tftScreen = TFT(CS_PIN, DC_PIN, RESET_PIN);

// position of the line on screen
int xPos = 0;

void setup() {
  tftScreen.begin();
  tftScreen.background(250, 16, 200);
}

int counter = 0;
char counterText[4];

void loop(){
  testText();
  delay(500);
  counter++;
}


void testText() {
  tftScreen.stroke(255 ,255, 255);

  tftScreen.setTextSize(1);
  tftScreen.text("Arduino TFT Demo", 15, 43);
  tftScreen.text("Hello World!", 29, 63);

  String counterString= String(counter);
  counterString.toCharArray(counterText, 4);

  tftScreen.stroke(250, 16, 200);
  tftScreen.fill(250, 16, 200);
  tftScreen.rect(29, 83, 50, 8);
  tftScreen.stroke(255 ,255, 255);
  tftScreen.text(counterText, 29, 83);
}
