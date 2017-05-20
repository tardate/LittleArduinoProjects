# #301 DHT11/Basics

Test basic temperature and humidity readings with the DHT11 sensor.

![Build](./assets/Basics_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The DHT11 sensor is a very cheap and common sensor that provides readings of:

* relative humidity: 20-80% ±5%
* temperature: 0-50°C ±2°C


### Communications

The DHT11 uses a single-wire two-way communications protocol.

For a first test, I'm using a simple [DHT11 library](http://playground.arduino.cc/Main/DHT11Lib) from the arduino playground.
Adafruit have support for the DHT11 within their sensor framework; I'll try that another time.

### Test Output

The [Basic.ino](./Basic.ino) sketch simply outputs current readings to the console:

![console-output](./assets/console-output.jpg?raw=true)


## Construction

![Breadboard](./assets/Basics_bb.jpg?raw=true)

![Schematic](./assets/Basics_schematic.jpg?raw=true)

![Build](./assets/Basics_build.jpg?raw=true)

## Credits and References
* [DHT11Lib](http://playground.arduino.cc/Main/DHT11Lib) - library on the arduino playground
* [DHT11 Humidity & Temperature Sensor](http://www.micropik.com/PDF/dht11.pdf) - D-Robotics UK
* [DHTxx Sensors Guide](https://cdn-learn.adafruit.com/downloads/pdf/dht.pdf) - adafruit
* [..as mentioned on my blog](http://blog.tardate.com/2017/05/leap301-dht11-sensor-basics.html)
