/*

  INA226/HighSideMonitorBasics
  Monitoring power, voltage and current using the INA226 with the Wire library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/INA226/HighSideMonitorBasics

 */

#include "Arduino.h"
#include "ina226_driver.h"


const float R_SHUNT      = 0.398; // nominally 0.22Ω but this is what it actually measures
const float MAX_BUS_AMPS = 0.2;

const uint32_t SERIAL_SPEED = 115200;
const uint16_t DELAY_BETWEEN_SAMPLES = 1000;
const uint8_t  INA_ADDR = 0x40;

Ina226Driver ina = Ina226Driver();


void setup() {
  Serial.begin(SERIAL_SPEED);
  while (!Serial) {}
  Serial.print("\n\nINA226 High-side Monitor\n");

  ina.begin(INA_ADDR);

  ina.calibrate(R_SHUNT, MAX_BUS_AMPS);

  Serial.print("Bus         Shunt       Current     Power\n");
  Serial.print("=========== =========== =========== ===========\n");
}


void loop() {
  static char sprintfBuffer[100];
  static char bus_V[15], shunt_mV[15], current_mA[15], bus_mW[15];

  dtostrf(ina.readBusVoltage()       , 9, 3, bus_V);
  dtostrf(ina.readShuntVoltage()     , 9, 3, shunt_mV);
  dtostrf(ina.readCurrent() * 1000.0 , 9, 3, current_mA);
  dtostrf(ina.readPower() * 1000.0   , 9, 3, bus_mW);
  sprintf(
    sprintfBuffer,
    "%sV %smV %smA %smW\n",
    bus_V, shunt_mV, current_mA, bus_mW
  );
  Serial.print(sprintfBuffer);

  delay(DELAY_BETWEEN_SAMPLES);
}
