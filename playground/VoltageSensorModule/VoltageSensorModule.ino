/*

  VoltageSensorModule
  Demo a voltage sensor with display on a 5110 LCD

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/VoltageSensorModule

 */

#include "U8glib.h"

U8GLIB_PCD8544 u8g(13, 11, 10, 9, 8);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8

#define VOLTAGE_SENSOR_PIN   A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  updateDisplay(sampleVoltage());
  delay(250);
}

float sampleVoltage() {
  int analog_reading = analogRead(VOLTAGE_SENSOR_PIN);
  return (float)analog_reading * 25.0 / 1023;
}

void updateDisplay(float voltage) {
  u8g.firstPage();
  do {
    u8g.setContrast(128);
    u8g.drawRFrame(0, 0, 84, 17, 3);   //Data1 frame
    u8g.drawRFrame(41, 16, 43, 10, 3); //Data1 label frame
    u8g.setFont(u8g_font_5x7);
    u8g.drawStr(45, 24, "Voltage");
    u8g.setFont(u8g_font_10x20);
    u8g.setPrintPos(2, 15);
    u8g.print(voltage);
  } while( u8g.nextPage() );
}
