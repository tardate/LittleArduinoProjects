/*

  DHT21 Sensor Library Test
  Using a AM2301 (DHT21-compatible) temperature and humidity sensor

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/DHT21/Tester

 */

#include "DHT.h"

const int DHT_PIN = 2;
const int DHT_TYPE = AM2301;
const int DELAY = 2000;

DHT dht(DHT_PIN, DHT_TYPE);


/*
 * Command: one-time setup
 */
void setup() {
  Serial.begin(115200);
  Serial.println("AM2301 test!");

  dht.begin();
}


/*
 * Command: main loop
 */
void loop() {
  delay(DELAY);

  float humidity = dht.readHumidity();
  float temp_c = dht.readTemperature();
  float temp_f = dht.readTemperature(true);

  if (isnan(humidity) || isnan(temp_c) || isnan(temp_f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float heat_index_c = dht.computeHeatIndex(temp_c, humidity, false);
  float heat_index_f = dht.computeHeatIndex(temp_f, humidity);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temp_c);
  Serial.print("˚C ");
  Serial.print(temp_f);
  Serial.print("˚F\t");
  Serial.print("Heat index: ");
  Serial.print(heat_index_c);
  Serial.print("˚C ");
  Serial.print(heat_index_f);
  Serial.println("˚F");
}
