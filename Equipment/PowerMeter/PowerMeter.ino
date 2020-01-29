/*

  PowerMeter
  A voltage, current and power meter using the INA226, with an ATtiny85 driving the process and displaying measurements to a 128X32 OLED display.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Equipment/PowerMeter

 */

#include "ina226_driver.h"

#if defined(__AVR_ATtiny85__)
  #include <TinyWireM.h>
  #include <Tiny4kOLED.h>
  #define LARGE_FONT FONT8X16
  #define SMALL_FONT FONT6X8
#else
  #include <U8x8lib.h>
  U8X8_SSD1306_128X32_UNIVISION_HW_I2C oled(U8X8_PIN_NONE);
  const uint8_t * LARGE_FONT = u8x8_font_px437wyse700a_2x2_r;
  const uint8_t * SMALL_FONT = u8x8_font_amstrad_cpc_extended_r;
  const uint32_t SERIAL_SPEED = 115200;
#endif

const float   R_SHUNT      = 0.046758; // needs to be replaced with the actual shunt resistance (in ohms)
const float   MAX_BUS_AMPS = 0.500; // set desired full-range current (used to scale the calibration factor)
const uint8_t INA_ADDR     = 0x40; // I²C address of the INA226

const uint16_t DELAY_SPLASH = 2000; // ms delay on the initial splash screen
const uint16_t DELAY_BETWEEN_SAMPLES = 1000; // ms delay between updating the display with a new value

Ina226Driver ina = Ina226Driver();


void setup() {
  #ifdef HAVE_HWSERIAL0
    Serial.begin(SERIAL_SPEED);
    while (!Serial) {}
    Serial.print("\n\nINA226 Power Meter\n");
  #endif

  ina.begin(INA_ADDR);
  ina.calibrate(R_SHUNT, MAX_BUS_AMPS);

  #if defined(__AVR_ATtiny85__)
    oled.begin();
    oled.clear();
    oled.switchRenderFrame();
    oled.clear();
    oled.switchRenderFrame();
    oled.on();
    oled.setFont(LARGE_FONT);
    oled.setCursor(40, 0); oled.print(F("INA226"));
    oled.setFont(SMALL_FONT);
    oled.setCursor(26, 2); oled.print(F("Power  Meter"));
    oled.setCursor(16, 3); oled.print(F("leap.tardate.com"));
  #else
    oled.begin();
    oled.setFont(LARGE_FONT);
    oled.drawString(2, 0, "INA226");
    oled.setFont(SMALL_FONT);
    oled.drawString(2, 2, "Power  Meter");
    oled.drawString(0, 3, "leap.tardate.com");
  #endif

  delay(DELAY_SPLASH);

  #if defined(__AVR_ATtiny85__)
    oled.clear();
    oled.setFont(LARGE_FONT);
    oled.setCursor(94, 0); oled.print(F("V"));
    oled.setFont(SMALL_FONT);
    oled.setCursor(94, 2); oled.print(F("mA"));
    oled.setCursor(94, 3); oled.print(F("mW"));
  #else
    oled.clearDisplay();
    oled.setFont(LARGE_FONT);
    oled.drawString(14, 0, "V");
    oled.setFont(SMALL_FONT);
    oled.drawString(14, 2, "mA");
    oled.drawString(14, 3, "mW");
  #endif
}


void loop() {
  static char bus_V[15], shunt_mV[15], current_mA[15], bus_mW[15];

  dtostrf(ina.readBusVoltage()      , 7, 3, bus_V);
  dtostrf(ina.readShuntVoltage()    , 9, 3, shunt_mV);
  dtostrf(ina.readCurrent() * 1000.0, 9, 3, current_mA);
  dtostrf(ina.readPower() * 1000.0  , 9, 3, bus_mW);

  #if defined(__AVR_ATtiny85__)
    oled.setFont(LARGE_FONT);
    oled.setCursor(35, 0); oled.print(bus_V);
    oled.setFont(SMALL_FONT);
    oled.setCursor(36, 2); oled.print(current_mA);
    oled.setCursor(36, 3); oled.print(bus_mW);
  #else
    oled.setFont(LARGE_FONT);
    oled.drawString(0, 0, bus_V);
    oled.setFont(SMALL_FONT);
    oled.drawString(4, 2, current_mA);
    oled.drawString(4, 3, bus_mW);
  #endif

  delay(DELAY_BETWEEN_SAMPLES);
}
