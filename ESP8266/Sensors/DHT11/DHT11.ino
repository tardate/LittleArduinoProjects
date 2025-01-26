/*

  Sensors/DHT11
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/ESP8266/Sensors/DHT11

 */

#include "DHT.h"

const int DHT_PIN = 2;

DHT dht(DHT_PIN, DHT11, 0);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.println("");

  delay(2000);

}