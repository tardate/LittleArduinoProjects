/*

  VL53L0X/LaserTapeMeasure
  Using a VL53L0X ranging sensor to make a short-range laser tape measure with an Arduino with Nokia 5110 display.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/VL53L0X/LaserTapeMeasure

 */

#include <U8glib.h>
// #include <Adafruit_VL53L0X.h>
#include "Adafruit_VL53L0X_Customised.h" // patches the class interface to make DeviceInfo public

const int INTRO_DELAY = 1000;
const int UPDATE_DELAY = 100;

const int LCD_SCK = 13;
const int LCD_MOSI = 11;
const int LCD_CS = 9;
const int LCD_A0 = 8;
const int LCD_RESET = 10;


//
// Hardware configuration
//
U8GLIB_PCD8544 lcd(LCD_SCK, LCD_MOSI, LCD_CS, LCD_A0, LCD_RESET);
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

//
// latest measurement
//
VL53L0X_RangingMeasurementData_t measure;


void setup()   {
  if (!lox.begin()) {
    showError();
    while(1);
  }
  showIntro();
}


void loop() {
  rangeTest();
  showMeasurement();
  delay(UPDATE_DELAY);
}


void rangeTest() {
  lox.rangingTest(&measure, false);
}


void showMeasurement() {
  lcd.firstPage();
  do {
    lcd.setContrast(128);
    lcd.drawRFrame(0, 0, 84, 17, 3);   // top frame
    lcd.drawRFrame(0, 22, 70, 10, 3);  // bottom label frame
    lcd.drawRFrame(0, 31, 84, 17, 3);  // bottom frame
    lcd.setFont(u8g_font_5x7);
    lcd.drawStr(4, 30, "Distance (mm)");
    lcd.setFont(u8g_font_10x20);
    lcd.setPrintPos(2, 15);
    lcd.print(lox.DeviceInfo.Type);
    lcd.setPrintPos(2, 46);
    if (measure.RangeStatus != 4) {
      lcd.print(measure.RangeMilliMeter);
    } else {
      lcd.print("n/a");
    }
  } while( lcd.nextPage() );
}


void showIntro() {
  lcd.firstPage();
  do {
    lcd.setContrast(128);
    lcd.drawRFrame(0, 0, 84, 17, 3);   // top frame
    lcd.drawRFrame(51, 16, 33, 10, 3); // top label frame
    lcd.drawRFrame(0, 31, 84, 17, 3);  // bottom frame
    lcd.setFont(u8g_font_5x7);
    lcd.setPrintPos(55, 24);
    lcd.print("v");
    lcd.print(lox.DeviceInfo.ProductRevisionMajor);
    lcd.print(".");
    lcd.print(lox.DeviceInfo.ProductRevisionMinor);
    lcd.setFont(u8g_font_10x20);
    lcd.setPrintPos(2, 15);
    lcd.print(lox.DeviceInfo.Type);
    lcd.setFont(u8g_font_5x7);
    lcd.setPrintPos(17, 39);
    lcd.print("Laser Tape");
    lcd.setPrintPos(25, 46);
    lcd.print("Measure");
  } while( lcd.nextPage() );
  delay(INTRO_DELAY);
}


void showError() {
  lcd.firstPage();
  do {
    lcd.setContrast(128);
    lcd.drawRFrame(0, 0, 84, 17, 3);   // top frame
    lcd.drawRFrame(0, 31, 84, 17, 3);  // bottom frame
    lcd.setFont(u8g_font_10x20);
    lcd.setPrintPos(2, 15);
    lcd.print("VL53L0X");
    lcd.setFont(u8g_font_5x7);
    lcd.setPrintPos(2, 38);
    lcd.print("Failed to boot");
  } while( lcd.nextPage() );
}
