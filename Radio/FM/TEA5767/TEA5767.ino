/*

  FM/TEA5767
  Control the TEA5767 low-power FM stereo radio chip with an Arduino.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Radio/FM/TEA5767

 */

#include <Wire.h>

// a sampling of Singapore radio stations..
const double STATIONS[] = {
  90.5, // Gold
  92.0, // Kiss
  93.3, // YES933
  95.0, // Class
  95.8, // Capital
  97.2, // Love
  99.5  // Lush
};

const double SAMPLE_DELAY = 2000;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(500);
}

void loop() {
  for(int station=0; station < sizeof(STATIONS) / sizeof(double); ++station) {
    setFrequency(STATIONS[station]);
    delay(SAMPLE_DELAY);
  }
}

void setFrequency(double frequency) {
  int frequencyB = 4 * (frequency * 1000000 + 225000) / 32768;
  byte frequencyH = frequencyB >> 8;
  byte frequencyL = frequencyB & 0xFF;

  Serial.print(F("Setting frequency "));
  Serial.println(frequency);
  Wire.beginTransmission(0x60);
  Wire.write(frequencyH & 0b00111111);
  Wire.write(frequencyL);
  Wire.write(0b10110000);
  Wire.write(0b00010000);
  Wire.write(0b00000000);
  Wire.endTransmission();
}
