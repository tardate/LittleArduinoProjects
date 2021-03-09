/*

  DS18S20/OneWireReading
  Basic interrogation of a DS18S20 using 1-wire protocol

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/DS18S20/OneWireReading

 */

#include <OneWire.h>

OneWire ds(10);  // on pin 10

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
}


void print_address() {
  Serial.println("----------------------------------");
  Serial.print("Address=");
  for (byte i = 0; i < 8; i++) {
    Serial.print(ds_address[i], HEX);
  }

  Serial.print(", Family=0x");
  Serial.print(ds_address[0],HEX);

  if (ds_address[0] == 0x10) {
      Serial.println(" (DS18S20)");
  }
  else if (ds_address[0] == 0x28) {
      Serial.println(" (DS18B20)");
  }
  else {
      Serial.println(" (Unknown)");
  }
}


bool find_device() {
  ds.reset_search();
  if ( !ds.search(ds_address)) {
      Serial.print("No more ds_addressesses.\n");
      ds.reset_search();
      return false;
  }

  print_address();

  if ( OneWire::crc8( ds_address, 7) != ds_address[7]) {
      Serial.print("CRC is not valid!\n");
      return false;
  }
  return true;
}


bool request_conversion() {
  ds.reset();
  ds.select(ds_address);
  ds.write(0x44,1);         // start conversion, with parasite power on at the end

  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.

  return ds.reset();
}


void read_scratchpad() {
  ds.select(ds_address);
  ds.write(0xBE);         // Read Scratchpad

  Serial.print("Data=");
  for (byte i = 0; i < 9; i++) {           // we need 9 bytes
    ds_data[i] = ds.read();
    Serial.print(ds_data[i], HEX);
  }

  Serial.print(" CRC=0x");
  Serial.print(OneWire::crc8(ds_data, 8), HEX);
  Serial.println();
}


void print_temperature() {
  int HighByte, LowByte, TReading, Tc_100, Whole, Fract;
  bool negative;

  LowByte = ds_data[0];
  HighByte = ds_data[1];
  TReading = (HighByte << 8) + LowByte;
  negative = (TReading & 0x8000) > 0;
  if (negative) {
    TReading = (TReading ^ 0xffff) + 1; // 2's comp
  }
  Tc_100 = (6 * TReading) + TReading / 4;    // multiply by (100 * 0.0625) or 6.25

  Whole = Tc_100 / 100;  // separate off the whole and fractional portions
  Fract = Tc_100 % 100;

  Serial.print("Temperature=");
  if (negative) {
     Serial.print("-");
  }
  Serial.print(Whole);
  Serial.print(".");
  if (Fract < 10)
  {
     Serial.print("0");
  }
  Serial.println(Fract);
}
