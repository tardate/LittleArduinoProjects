/*

  UnifiedSensorTest

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/DHT11/UnifiedSensorTest

 */

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

const int DHT_PIN = 2;
const int DHT_TYPE = DHT11;

DHT_Unified dht(DHT_PIN, DHT_TYPE);
DHT dht_functions(DHT_PIN, DHT_TYPE); // only needed to access computeHeatIndex

uint32_t delayMS;

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println(F("DHT11 Unified Sensor Example"));
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  delay(delayMS);

  sensors_event_t temperature_event;
  sensors_event_t humidity_event;

  dht.temperature().getEvent(&temperature_event);
  dht.humidity().getEvent(&humidity_event);

  if (isnan(temperature_event.temperature)) {
    Serial.println(F("Error reading temperature!"));
    return;
  }

  if (isnan(humidity_event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
    return;
  }

  float heat_index_c = dht_functions.computeHeatIndex(temperature_event.temperature, humidity_event.relative_humidity, false);

  Serial.print("Humidity: ");
  Serial.print(humidity_event.relative_humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature_event.temperature);
  Serial.print("˚C ");
  Serial.print("Heat index: ");
  Serial.print(heat_index_c);
  Serial.println("˚C ");
}
