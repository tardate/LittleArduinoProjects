/*

  DS18S20/OneWireReading
  Basic interrogation of a DS18S20 using 1-wire protocol

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/DS18S20/OneWireReading

 */

#include <OneWire.h>

const int STEP_DELAY = 1000;
const int CONVERSION_DELAY = 1500; // don't make this too short, or else may encounter conversion failures.

#define SENSOR_PIN (10)

OneWire ds(SENSOR_PIN);

byte ds_address[8];
byte ds_data[12];


void setup(void) {
  Serial.begin(9600);
}


void loop(void) {
  if (find_device()) {
    if (request_conversion()) {
      read_scratchpad();
      print_temperature();
    } else {
      Serial.println("Conversion failed.");
    }
  }
  delay(STEP_DELAY);
}


void print_address() {
  Serial.println("----------------------------------");
  Serial.print("Address=");
  for (byte i = 0; i < 8; i++) {
    Serial.print(ds_address[i], HEX);
  }

  Serial.print(", Family=0x");
  Serial.print(ds_address[0], HEX);

  switch (ds_address[0]) {
  case 0x10:
    Serial.println(" (DS18S20)");
    break;
  case 0x22:
    Serial.println(" (DS1822)");
    break;
  case 0x28:
    Serial.println(" (DS18B20)");
    break;
  default:
    Serial.println(" (Unknown)");
    break;
  }
}


bool find_device() {
  ds.reset_search();
  if (!ds.search(ds_address)) {
    Serial.print("No more ds_addressesses.\n");
    ds.reset_search();
    return false;
  }

  print_address();

  if (OneWire::crc8(ds_address, 7) != ds_address[7]) {
    Serial.print("CRC is not valid!\n");
    return false;
  }
  return true;
}


bool request_conversion() {
  ds.reset();
  ds.select(ds_address);
  ds.write(0x44, 1); // start conversion, with parasite power on at the end

  delay(CONVERSION_DELAY);
  // we might do a ds.depower() here, but the reset will take care of it.

  return ds.reset();
}


void read_scratchpad() {
  ds.select(ds_address);
  ds.write(0xBE); // Read Scratchpad

  for (byte i = 0; i < 9; ++i) ds_data[i] = ds.read(); // we need 9 bytes

  Serial.print("Data=");
  for (byte i = 0; i < 9; ++i) Serial.print(ds_data[i], HEX);

  Serial.print(" CRC=0x");
  Serial.print(OneWire::crc8(ds_data, 8), HEX);
  Serial.println();
}


void print_temperature() {
  int hi_byte, lo_byte, temperature_reading, tc_100, whole_part, fractional_part;
  bool negative;

  lo_byte = ds_data[0];
  hi_byte = ds_data[1];
  temperature_reading = (hi_byte << 8) + lo_byte;
  negative = (temperature_reading & 0x8000) > 0;
  if (negative) temperature_reading = (temperature_reading ^ 0xffff) + 1; // 2's comp

  tc_100 = 6 * temperature_reading + temperature_reading / 4; // multiply by (100 * 0.0625) or 6.25

  whole_part = tc_100 / 100; // separate off the whole_part and fractional_partional portions
  fractional_part = tc_100 % 100;

  Serial.print("Temperature=");
  if (negative)  Serial.print("-");
  Serial.print(whole_part);
  Serial.print(".");
  if (fractional_part < 10) Serial.print("0");
  Serial.println(fractional_part);
}
