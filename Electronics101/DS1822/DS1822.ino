/*

  DS1822
  Basic interrogation of a DS1822 using 1-wire protocol and results display on a Nokia 5110 LCD.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/DS1822

 */

#include <OneWire.h>
#include <U8glib.h>

const int SPI_SCK_PIN = 13;
const int SPI_MOSI_PIN = 11;

const int LCD_CSN_PIN = 8;
const int LCD_SS_PIN = 9;
const int LCD_RST_PIN = 10;

U8GLIB_PCD8544 u8g(SPI_SCK_PIN, SPI_MOSI_PIN, LCD_SS_PIN, LCD_CSN_PIN, LCD_RST_PIN);

#define SENSOR_PIN (7)

const int STEP_DELAY = 1000;
const int CONVERSION_DELAY = 1500; // don't make this too short, or else may encounter conversion failures.

OneWire ds(SENSOR_PIN);

byte ds_address[8];
byte ds_data[12];

float celsius;
bool address_ok = true;
bool crc_ok = true;
bool conversion_ok = true;


void setup(void) { }


void loop(void) {
  if (find_device()) {
    if (request_conversion()) {
      read_temperature();
    }
  }
  updateDisplay();
  delay(STEP_DELAY);
}


void updateDisplay() {
  u8g.firstPage();
  do {
    u8g.setContrast(128);
    u8g.drawRFrame(0, 0, 84, 17, 3);   // Data1 frame
    u8g.drawRFrame(41, 16, 43, 10, 3); // Data1 label frame
    u8g.drawRFrame(0, 22, 35, 10, 3);  // Data2 label frame
    u8g.drawRFrame(0, 31, 84, 17, 3);  // Data2 frame
    u8g.setFont(u8g_font_5x7);
    u8g.drawStr(45, 24, "Celsius");
    u8g.drawStr(4, 30, "Device");
    u8g.setFont(u8g_font_10x20);
    u8g.setPrintPos(2, 15);
    if (conversion_ok) {
      if (crc_ok) {
        u8g.print(celsius);
      } else {
        u8g.print("bad crc");
      }
    } else {
      u8g.print("bad conv");
    }
    u8g.setPrintPos(2, 46);
    if (address_ok) {
      switch (ds_address[0]) {
      case 0x10:
        u8g.print("DS18S20");
        break;
      case 0x22:
        u8g.print("DS1822");
        break;
      case 0x28:
        u8g.print("DS18B20");
        break;
      default:
        u8g.print("Unknown");
        break;
      }
    } else {
      u8g.print("N/A");
    }
  } while( u8g.nextPage() );
}


bool find_device() {
  crc_ok = true;
  address_ok = true;
  ds.reset_search();
  if (!ds.search(ds_address)) {
    address_ok = false;
    ds.reset_search();
    return false;
  }

  if (OneWire::crc8(ds_address, 7) != ds_address[7]) {
    crc_ok = false;
  }
  return crc_ok;
}


bool request_conversion() {
  ds.reset();
  ds.select(ds_address);
  ds.write(0x44, 1); // start conversion, with parasite power on at the end

  delay(CONVERSION_DELAY);

  // we might do a ds.depower() here, but the reset will take care of it.
  conversion_ok = ds.reset();
  return conversion_ok;
}


void read_temperature() {
  ds.select(ds_address);
  ds.write(0xBE); // Read Scratchpad

  for (byte i = 0; i < 9; ++i) ds_data[i] = ds.read(); // we need 9 bytes
  crc_ok = OneWire::crc8(ds_data, 8) == ds_data[8];

  if (crc_ok) {
    int temperature_reading = (ds_data[1] << 8) + ds_data[0];
    bool negative = (temperature_reading & 0x8000) > 0;
    if (negative) temperature_reading = (temperature_reading ^ 0xffff) + 1; // 2's comp
    celsius = 0.0625 * temperature_reading;
  }
}
