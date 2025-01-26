/*

  INA226/HighSideCurrentSensor
  Using the https://github.com/jarzebski/Arduino-INA226 library

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/INA226/HighSideCurrentSensor

 */

#include "Arduino.h"
#include <INA226.h>

INA226 ina;

const float MAX_BUS_AMPS = 0.2;
const float R_SHUNT      = 0.398;

const uint32_t SERIAL_SPEED = 115200;
const uint16_t DELAY_BETWEEN_SAMPLES = 1000;


void checkConfig() {
  Serial.print("Mode:                  ");
  switch (ina.getMode()) {
    case INA226_MODE_POWER_DOWN:      Serial.println("Power-Down"); break;
    case INA226_MODE_SHUNT_TRIG:      Serial.println("Shunt Voltage, Triggered"); break;
    case INA226_MODE_BUS_TRIG:        Serial.println("Bus Voltage, Triggered"); break;
    case INA226_MODE_SHUNT_BUS_TRIG:  Serial.println("Shunt and Bus, Triggered"); break;
    case INA226_MODE_ADC_OFF:         Serial.println("ADC Off"); break;
    case INA226_MODE_SHUNT_CONT:      Serial.println("Shunt Voltage, Continuous"); break;
    case INA226_MODE_BUS_CONT:        Serial.println("Bus Voltage, Continuous"); break;
    case INA226_MODE_SHUNT_BUS_CONT:  Serial.println("Shunt and Bus, Continuous"); break;
    default: Serial.println("unknown");
  }

  Serial.print("Samples average:       ");
  switch (ina.getAverages()) {
    case INA226_AVERAGES_1:           Serial.println("1 sample"); break;
    case INA226_AVERAGES_4:           Serial.println("4 samples"); break;
    case INA226_AVERAGES_16:          Serial.println("16 samples"); break;
    case INA226_AVERAGES_64:          Serial.println("64 samples"); break;
    case INA226_AVERAGES_128:         Serial.println("128 samples"); break;
    case INA226_AVERAGES_256:         Serial.println("256 samples"); break;
    case INA226_AVERAGES_512:         Serial.println("512 samples"); break;
    case INA226_AVERAGES_1024:        Serial.println("1024 samples"); break;
    default: Serial.println("unknown");
  }

  Serial.print("Bus conversion time:   ");
  switch (ina.getBusConversionTime()) {
    case INA226_BUS_CONV_TIME_140US:  Serial.println("140uS"); break;
    case INA226_BUS_CONV_TIME_204US:  Serial.println("204uS"); break;
    case INA226_BUS_CONV_TIME_332US:  Serial.println("332uS"); break;
    case INA226_BUS_CONV_TIME_588US:  Serial.println("558uS"); break;
    case INA226_BUS_CONV_TIME_1100US: Serial.println("1.100ms"); break;
    case INA226_BUS_CONV_TIME_2116US: Serial.println("2.116ms"); break;
    case INA226_BUS_CONV_TIME_4156US: Serial.println("4.156ms"); break;
    case INA226_BUS_CONV_TIME_8244US: Serial.println("8.244ms"); break;
    default: Serial.println("unknown");
  }

  Serial.print("Shunt conversion time: ");
  switch (ina.getShuntConversionTime()) {
    case INA226_SHUNT_CONV_TIME_140US:  Serial.println("140uS"); break;
    case INA226_SHUNT_CONV_TIME_204US:  Serial.println("204uS"); break;
    case INA226_SHUNT_CONV_TIME_332US:  Serial.println("332uS"); break;
    case INA226_SHUNT_CONV_TIME_588US:  Serial.println("558uS"); break;
    case INA226_SHUNT_CONV_TIME_1100US: Serial.println("1.100ms"); break;
    case INA226_SHUNT_CONV_TIME_2116US: Serial.println("2.116ms"); break;
    case INA226_SHUNT_CONV_TIME_4156US: Serial.println("4.156ms"); break;
    case INA226_SHUNT_CONV_TIME_8244US: Serial.println("8.244ms"); break;
    default: Serial.println("unknown");
  }

  Serial.print("Max possible current:  ");
  Serial.print(ina.getMaxPossibleCurrent());
  Serial.println(" A");

  Serial.print("Max current:           ");
  Serial.print(ina.getMaxCurrent());
  Serial.println(" A");

  Serial.print("Max shunt voltage:     ");
  Serial.print(ina.getMaxShuntVoltage());
  Serial.println(" V");

  Serial.print("Max power:             ");
  Serial.print(ina.getMaxPower());
  Serial.println(" W");
}


void setup() {
  Serial.begin(SERIAL_SPEED);
  while (!Serial) {}
  Serial.print("\n\nINA226 Monitor\n");

  // Default INA226 address is 0x40
  ina.begin();

  ina.configure(INA226_AVERAGES_1, INA226_BUS_CONV_TIME_1100US, INA226_SHUNT_CONV_TIME_1100US, INA226_MODE_SHUNT_BUS_CONT);

  ina.calibrate(R_SHUNT, MAX_BUS_AMPS);

  checkConfig();

  Serial.print("Bus      Shunt       Bus         Bus\n");
  Serial.print("======== =========== =========== ===========\n");

}


void loop() {
  static char     sprintfBuffer[100];
  static char     busV[8], shuntV[10], shuntA[10], busW[10];

  dtostrf(ina.readBusVoltage()  , 7, 4, busV  );
  dtostrf(ina.readShuntVoltage()* 1000.0, 7, 4, shuntV);
  dtostrf(ina.readShuntCurrent()* 1000.0, 7, 4, shuntA);
  dtostrf(ina.readBusPower()    * 1000.0, 7, 4, busW);
  sprintf(
    sprintfBuffer,
    "%sV %smV %smA %smW\n",
    busV, shuntV, shuntA, busW
  );
  Serial.print(sprintfBuffer);

  delay(DELAY_BETWEEN_SAMPLES);
}
