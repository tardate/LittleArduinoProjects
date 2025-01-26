/*

  TemperatureSensors/LM35
  Reading ambient temperature with the LM35 and an Arduino without output display on a Nokia 5110 LCD.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/TemperatureSensors/LM35

 */

#include "U8glib.h"

const int SPI_SCK_PIN = 13;
const int SPI_MOSI_PIN = 11;

const int LCD_CSN_PIN = 8;
const int LCD_SS_PIN = 9;
const int LCD_RST_PIN = 10;

U8GLIB_PCD8544 u8g(SPI_SCK_PIN, SPI_MOSI_PIN, LCD_SS_PIN, LCD_CSN_PIN, LCD_RST_PIN);

#define SENSOR_PIN (A0)
// #define VREF_MV  (4985) // 5V  when analogReference(DEFAULT)
#define VREF_MV 1060   // 1.1V when analogReference(INTERNAL)

#define DEGREES_PER_BIT (VREF_MV / 1023.0 / 10)
#define KELVIN_OFFSET  (273.15)
const int DELAY_PER_READING = 1000;

void setup() {
  Serial.begin(115200);
  analogReference(INTERNAL);
}

void loop() {
  updateDisplay(sampleTemperature());
  delay(DELAY_PER_READING);
}

float sampleTemperature() {
  float analog_reading = 1.0 * analogRead(SENSOR_PIN);
  Serial.print(F("analog_reading: "));
  Serial.println(analog_reading);
  return analog_reading * DEGREES_PER_BIT;
}

void updateDisplay(float celcius) {
  Serial.print(F("celcius: "));
  Serial.println(celcius);
  u8g.firstPage();
  do {
    u8g.setContrast(128);
    u8g.drawRFrame(0, 0, 84, 17, 3);   // Data1 frame
    u8g.drawRFrame(41, 16, 43, 10, 3); // Data1 label frame
    u8g.drawRFrame(0, 22, 35, 10, 3);  // Data2 label frame
    u8g.drawRFrame(0, 31, 84, 17, 3);  // Data2 frame
    u8g.setFont(u8g_font_5x7);
    u8g.drawStr(45, 24, "Celcius");
    u8g.drawStr(4, 30, "Kelvin");
    u8g.setFont(u8g_font_10x20);
    u8g.setPrintPos(2, 15);
    u8g.print(celcius);
    u8g.setPrintPos(2, 46);
    u8g.print(celcius + KELVIN_OFFSET);
  } while( u8g.nextPage() );
}
