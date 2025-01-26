/*

  VoltageReference/LT1019
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/VoltageReference/LT1019

 */

const int SPI_SCK_PIN             = 13;
const int SPI_MOSI_PIN            = 11;
const int LCD_SS_PIN              = 6;
const int LCD_CSN_PIN             = 5;
const int LCD_RST_PIN             = 7;

const int VOLTAGE_MEASUREMENT_PIN = A0;
const float VREF                  = 2.5;

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(LCD_CSN_PIN, LCD_SS_PIN, LCD_RST_PIN);

void setup() {
  // switch to external voltage reference
  analogReference(EXTERNAL);

  display.begin();
  display.setContrast(0xC8);
  display.setTextSize(1);
  display.setTextColor(BLACK);

  display.clearDisplay();
  display.setCursor(0, 25);
  display.println("LT1019 VREF");
  display.display();
  delay(2000);
}

void loop() {
  int analog_measurement = analogRead(VOLTAGE_MEASUREMENT_PIN);
  float voltage = VREF * analog_measurement / 1023;

  displayMeasurement(analog_measurement, voltage);

  delay(500);
}

void displayMeasurement(int analog_measurement, float voltage) {
  display.clearDisplay();

  display.setCursor(0, 5);
  display.println("Analog Input:");
  display.setCursor(0, 15);
  display.println(analog_measurement);

  display.setCursor(0, 25);
  display.println("Voltage:");
  display.setCursor(0, 35);
  display.println(voltage);

  display.display();
}

