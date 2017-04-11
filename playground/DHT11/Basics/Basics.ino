/*

  DHT11/Basics
  Test basic temperature and humidity readings with the DHT11 sensor.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/DHT11/Basics

 */

#include "dht11.h"

dht11 DHT11;
const int DHT11_PIN = 2;


void setup() {
  Serial.begin(115200);
}


void loop() {
  if (read_sensor() == DHTLIB_OK) display_readings();
  delay(2000);
}


int read_sensor() {
  int status = DHT11.read(DHT11_PIN);
  Serial.print("Read sensor: ");
  switch (status) {
  case DHTLIB_OK:
    Serial.println("OK");
    break;
  case DHTLIB_ERROR_CHECKSUM:
    Serial.println("Checksum error");
    break;
  case DHTLIB_ERROR_TIMEOUT:
    Serial.println("Time out error");
    break;
  default:
    Serial.println("Unknown error");
    break;
  }
  return status;
}


void display_readings() {
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("Temperature (°C): ");
  Serial.println((float)DHT11.temperature, 2);
}