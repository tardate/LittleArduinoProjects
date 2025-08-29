/*

  I2CScanner
  Simple I2C scanner for finding device addresses.
  Base on http://playground.arduino.cc/Main/I2cScanner by Frode Grimstad Bang

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/I2CScanner

 */

#include <Wire.h>

const int DELAY_BETWEEN_SCANS = 5000;
const int ADDRESS_LIMIT_LOW = 1;
const int ADDRESS_LIMIT_HIGH = 127;

void setup() {
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  Serial.print("\nScanning I2C addresses 0x");
  Serial.print(ADDRESS_LIMIT_LOW, HEX);
  Serial.print(" to 0x");
  Serial.print(ADDRESS_LIMIT_HIGH, HEX);
  Serial.println("...");

  for(byte address = ADDRESS_LIMIT_LOW; address < ADDRESS_LIMIT_HIGH; address++ ) {
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      Serial.println(address, HEX);
    } else if (error==4) {
      Serial.print("Unknown error at address 0x");
      Serial.println(address, HEX);
    }
  }

  Serial.println("Done");
  delay(DELAY_BETWEEN_SCANS);
}
