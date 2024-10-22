# #343 Sensors/DHT11

Reading temperature and humidity with a DHT11 sensor and ESP-01, coding with ESP8266 core for Arduino.

![Build](./assets/DHT11_build.jpg?raw=true)

## Notes

The DHT11 sensor is a very cheap and common sensor that provides readings of:

* relative humidity: 20-80% ±5%
* temperature: 0-50°C ±2°C

I've used this before with an Arduino - see [LEAP#301](../../../playground/DHT11/Basics).
This time I'm testing with the most basic ESP8266 board - an ESP-01, which exposes one free GPIO.

### Programming Setup

I'm using a [LEAP#194 DIYDevBoard](../../DIYDevBoard) to host the ESP-01 module,
and a cheap [CH340G-based USB to UART adapter](https://www.aliexpress.com/item/CH340-module-USB-to-TTL-CH340G-upgrade-download-a-small-wire-brush-plate-STC-microcontroller-board/32354359382.html).
With the
[correct drivers installed](../../../notebook/arduino.md#arduinos-using-the-ch340g-serial-chip),
it shows up in the tty device list.

My host computer is running MacOSX.

### Required Libraries

I'm using [ESP8266 core](https://github.com/esp8266/Arduino) with the Arduino IDE,
and the Adafruit sensor library to interface with the DHT11:

* [Adafruit Unified Sensor Library](https://github.com/adafruit/Adafruit_Sensor)
* [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)

These need to be installed in the Arduino IDE.

### Test Sketch

The [DHT11.ino](./DHT11.ino) sketch simply reads the sensor every 2 seconds
and outputs the readings to the serial port.

Here is a test run:

![console_output](./assets/console_output.png?raw=true)

## Construction

![Breadboard](./assets/DHT11_bb.jpg?raw=true)

![Schematic](./assets/DHT11_schematic.jpg?raw=true)

![Build](./assets/DHT11_build.jpg?raw=true)

## Credits and References

* [DHT11 Humidity & Temperature Sensor](http://www.micropik.com/PDF/dht11.pdf) - D-Robotics UK
* [ESP8266 core for Arduino](https://github.com/esp8266/Arduino)
* [Adafruit Unified Sensor Library](https://github.com/adafruit/Adafruit_Sensor)
* [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
* [LEAP#194 DIYDevBoard](../../DIYDevBoard) - the dev board I'm using to host the ESP-01
* [LEAP#301 DHT11/Basics](../../../playground/DHT11/Basics) - similar project for an Arduino
* [..as mentioned on my blog](https://blog.tardate.com/2017/09/leap343-esp8266-dht11-sensor-reading.html)
