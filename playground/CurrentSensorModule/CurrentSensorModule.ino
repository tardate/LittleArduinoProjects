/*

  CurrentSensorModule
  Demo an ACS712 current sensor with display on a 5110 LCD

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/CurrentSensorModule

 */

#include "U8glib.h"

U8GLIB_PCD8544 u8g(13, 11, 10, 9, 8);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8

#define CURRENT_SENSOR_PIN   A0
#define CURRENT_FULL_RANGE   40.0

void setup() {
  Serial.begin(9600);
}

void loop() {
  updateDisplay(sampleCurrent());
  delay(250);
}

float sampleCurrent() {
  float analog_reading = 1.0 * analogRead(CURRENT_SENSOR_PIN);
  return analog_reading * CURRENT_FULL_RANGE / 1023.0  - CURRENT_FULL_RANGE / 2;
}

void updateDisplay(float current) {
  u8g.firstPage();
  do {
    u8g.setContrast(128);
    u8g.drawRFrame(0, 0, 84, 17, 3);   //Data1 frame
    u8g.drawRFrame(41, 16, 43, 10, 3); //Data1 label frame
    u8g.setFont(u8g_font_5x7);
    u8g.drawStr(45, 24, "Current");
    u8g.setFont(u8g_font_10x20);
    u8g.setPrintPos(2, 15);
    u8g.print(current);
  } while( u8g.nextPage() );
}
