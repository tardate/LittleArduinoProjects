# #301 DHT11 Basics

Test basic temperature and humidity readings with the DHT11 sensor.

![Build](./assets/Basics_build.jpg?raw=true)

## Notes

The DHT11 sensor is a very cheap and common sensor that provides readings of:

* relative humidity: 20-80% ±5%
* temperature: 0-50°C ±2°C

### Circuit Design

I am using a DHT11 that is mounted on an adapter board that includes pull-up resistor for the data line, and a decoupling capacitor,
similar to ["New Temperature and Relative Humidity Sensor DHT11 Module with Cable for arduino Diy Kit" (aliexpress seller listing)](https://www.aliexpress.com/item/32997407491.html).

![module](../assets/module.jpg)

The schematic below shows the relevant components if a mounting module is not used. Designed with Fritzing: see [Basics.fzz](./Basics.fzz).

![Breadboard](./assets/Basics_bb.jpg?raw=true)

![Schematic](./assets/Basics_schematic.jpg?raw=true)

![Build](./assets/Basics_bb_build.jpg?raw=true)

### Demonstration Script

The DHT11 uses a single-wire two-way communications protocol.

For a first test, I'm using a simple
[DHT11Lib](https://playground.arduino.cc/Main/DHT11Lib/)
from the arduino playground.
Adafruit have support for the DHT11 within their sensor framework; I'll try that another time.

The [Basics.ino](./Basics.ino) sketch simply outputs current readings to the console:

```c
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
```

Sample console output:

![console-output](./assets/console-output.png?raw=true)

## Credits and References

* [DHT11Lib](https://playground.arduino.cc/Main/DHT11Lib/) - library on the arduino playground
* ["New Temperature and Relative Humidity Sensor DHT11 Module with Cable for arduino Diy Kit" (aliexpress seller listing)](https://www.aliexpress.com/item/32997407491.html)
* ["DHT11 Humidity & Temperature Sensor" datasheet (mouser.com)](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf)
* ["DHTxx Sensors Guide" (adafruit)](https://cdn-learn.adafruit.com/downloads/pdf/dht.pdf)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap301-dht11-sensor-basics.html)
