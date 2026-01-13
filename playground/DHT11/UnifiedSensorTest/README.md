# #816 DHT11 Unified Sensor Library Test

Using the Adafruit Unified Sensor Library to log temperature and humidity from a DHT11 sensor.

![Build](./assets/UnifiedSensorTest_build.jpg?raw=true)

## Notes

This is a test of the Adafruit DHT Sensor Library with the unified sensor framework.

See [LEAP#301 DHT11 Basics](../Basics/) for an introduction to the DHT11 sensor,
and [LEAP#815 DHT11 Sensor Library Test](../Tester/) for an example using the Adafruit DHT Sensor Library without the unified sensor framework.

### Circuit Design

I am using a DHT11 that is mounted on an adapter board that includes pull-up resistor for the data line, and a decoupling capacitor,
similar to ["New Temperature and Relative Humidity Sensor DHT11 Module with Cable for arduino Diy Kit" (aliexpress seller listing)](https://www.aliexpress.com/item/32997407491.html).

![module](../assets/module.jpg)

The schematic below shows the relevant components if a mounting module is not used.
Designed with Fritzing: see [UnifiedSensorTest.fzz](./UnifiedSensorTest.fzz).

![bb](./assets/UnifiedSensorTest_bb.jpg?raw=true)

![schematic](./assets/UnifiedSensorTest_schematic.jpg?raw=true)

![bb_build](./assets/UnifiedSensorTest_bb_build.jpg?raw=true)

### Demonstration Script

The DHT11 uses a single-wire two-way communications protocol.

The [Tester.ino](./Tester.ino) sketch simply outputs current readings to the console.

Requires the following Arduino libraries:

* [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
* [Adafruit Unified Sensor Lib](https://github.com/adafruit/Adafruit_Sensor)

It is based on the `DHTtester.ino` example.

```c
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
```

## Credits and References

* [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
* [Adafruit Unified Sensor Lib](https://github.com/adafruit/Adafruit_Sensor)
* ["DHTxx Sensors Guide" (adafruit)](https://cdn-learn.adafruit.com/downloads/pdf/dht.pdf)
* ["New Temperature and Relative Humidity Sensor DHT11 Module with Cable for arduino Diy Kit" (aliexpress seller listing)](https://www.aliexpress.com/item/32997407491.html)
* ["DHT11 Humidity & Temperature Sensor" datasheet (mouser.com)](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf)
