/*

  INA226/HighSideCurrentSensor
  Using the https://github.com/SV-Zanshin/INA library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/INA226/HighSideCurrentSensor

 */

#include "Arduino.h"
#include <INA.h>

const uint8_t  MAX_BUS_AMPS = 1;
const uint32_t R_SHUNT      = 398000; // µΩ

const uint32_t SERIAL_SPEED = 115200;
const uint16_t DELAY_BETWEEN_SAMPLES = 4000;

uint8_t        devicesFound =      0;
INA_Class      INA;


void setup()
{
  Serial.begin(SERIAL_SPEED);
  while (!Serial) {}
  Serial.print("\n\nDisplay INA Readings V1.0.4\n");
  Serial.print(" - Searching & Initializing INA devices\n");

  while ((devicesFound = INA.begin(MAX_BUS_AMPS, R_SHUNT)) == 0) {
    Serial.println("No INA device found, retrying in 10 seconds...");
     delay(1000);
  }
  Serial.print(" - Detected ");
  Serial.print(devicesFound);
  Serial.println(" INA devices on the I2C bus");

  INA.setBusConversion(8500);            // Maximum conversion time 8.244ms
  INA.setShuntConversion(8500);          // Maximum conversion time 8.244ms
  INA.setAveraging(128);                 // Average each reading n-times
  INA.setMode(INA_MODE_CONTINUOUS_BOTH); // Bus/shunt measured continuously
  INA.AlertOnBusOverVoltage(true, 5000);  // Trigger alert if over 5V on bus

  Serial.print("Nr Adr Type   Bus      Shunt       Bus         Bus\n");
  Serial.print("== === ====== ======== =========== =========== ===========\n");

}


void loop()
{
  static char     sprintfBuffer[100];
  static char     busChar[8], shuntChar[10], busMAChar[10], busMWChar[10];

  for (uint8_t i=0;i<devicesFound;i++) {
    dtostrf(INA.getBusMilliVolts(i)   / 1000.0, 7, 4, busChar  );
    dtostrf(INA.getShuntMicroVolts(i) / 1000.0, 9, 4, shuntChar);
    dtostrf(INA.getBusMicroAmps(i)    / 1000.0, 9, 4, busMAChar);
    dtostrf(INA.getBusMicroWatts(i)   / 1000.0, 9, 4, busMWChar);
    sprintf(
      sprintfBuffer, "%2d %3d %s %sV %smV %smA %smW\n", i+1, INA.getDeviceAddress(i),
      INA.getDeviceName(i), busChar, shuntChar, busMAChar, busMWChar
    );
    Serial.print(sprintfBuffer);
  }
  delay(DELAY_BETWEEN_SAMPLES);
}
