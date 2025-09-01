/*

  TemperatureLoggerTypeK
  Simple high-temperature monitor using Type K (differential) and LM35 (cold-junction) sensors

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/TemperatureLoggerTypeK

 */

#include "U8glib.h"

U8GLIB_PCD8544 u8g(13, 11, 10, 9, 8);   // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8

// actual reference voltage of the board, in mV (as measured)
#define VREF_MV 4930     // 5V  when analogReference(DEFAULT)
//#define VREF_MV 1060   // 1.1V when analogReference(INTERNAL)

#define TYPEK_SENSOR_PIN   A0
#define LM35_SENSOR_PIN    A1

#define R1 1.0                                    // non-inverting amplifier R1 in kΩ
#define R2 330.0                                  // non-inverting amplifier R2 in kΩ
#define GAIN (1 + R2/R1)                          // non-inverting amplifier gain
#define MV_PER_ANALOG_DIVISION (VREF_MV / 1023.0)
#define CELCIUS_PER_MV (1.0 / 0.041)              // based on 41µV per ˚C linear approximation for Type K > 0˚C
const float typekReadingScaler = CELCIUS_PER_MV / GAIN * MV_PER_ANALOG_DIVISION;

void setup() {
  analogReference(DEFAULT);
}

void loop() {
  updateDisplay(sampleTemperature());
  delay(250);
}

/*
 * return the current temperature reading
 */
float sampleTemperature() {
  return sampleColdJunctionTemperature() + sampleTemperatureOffset();
}

/*
 * read the Type K temperature differential at 41µV/˚C
 */
float sampleTemperatureOffset() {
  float analog_reading = 1.0 * analogRead(TYPEK_SENSOR_PIN);
  return analog_reading * typekReadingScaler;
}

/*
 * read the LM35 cold-junction temperature at 10mV/˚C
 */
float sampleColdJunctionTemperature() {
  float current_temperature = map(analogRead(LM35_SENSOR_PIN), 0, 1023, 0, VREF_MV) / 10.0;
  return current_temperature;
}

/*
 * update the 5110 LCD display
 */
void updateDisplay(float temperature) {
  u8g.firstPage();
  do {
    u8g.setContrast(128);
    u8g.drawRFrame(0, 0, 84, 17, 3);   //Data1 frame
    u8g.drawRFrame(41, 16, 43, 10, 3); //Data1 label frame
    u8g.setFont(u8g_font_5x7);
    u8g.drawStr(45, 24, "Celsius");
    u8g.setFont(u8g_font_10x20);
    u8g.setPrintPos(2, 15);
    u8g.print(temperature);
  } while(u8g.nextPage());
}
