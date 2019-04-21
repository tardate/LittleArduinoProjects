# #219 DS18S20/OneWireReading

Basic interrogation of a DS18S20 using 1-wire protocol

![DS18S20](./assets/DS18S20.jpg?raw=true)


## Notes

The DS18S20 is an inexpensive 1-Wire digital thermometer
with a range of -55°C to +125°C, at ±0.5°C Accuracy from -10°C to +85°C.

It comes in TO-92 packaging and may be powered directly (using three pins),
or take parasitic power from the data line (using two pins).

### Basic Operation

The sequence of operations boils down to this:

* Send a search request on the wire to find a device
* Get the device address and ensure the family code is as expected
* Issue conversion command (0x44)
* Wait for conversion, then read the conversion scratchpad from the device
* Process the data received

### Family Codes

| Model   | Code |
|---------|------|
| DS18S20 | 0x10 |
| DS18B20 | 0x28 |
| DS1822  | 0x22 |


### Example Code

The [OneWireReading.ino](./OneWireReading.ino) sketch is a basic demonstration based on the
examples on the [OneWire Arduino playground page](http://playground.arduino.cc/Learning/OneWire).

I've refactored a little to make the code more readable.

It constantly polls the DS18S20 device and logs to the serial output. Here's an example:

![screenshot](./assets/screenshot.png?raw=true)

## Construction

![Breadboard](./assets/OneWireReading_bb.jpg?raw=true)

![The Schematic](./assets/OneWireReading_schematic.jpg?raw=true)

![The Build](./assets/OneWireReading_build.jpg?raw=true)

## Credits and References
* [DS18S20](https://www.maximintegrated.com/en/products/analog/sensors-and-sensor-interface/DS18S20.html) product page and datasheet
* [OneWire library](https://github.com/PaulStoffregen/OneWire)
* [OneWire](http://playground.arduino.cc/Learning/OneWire) - Arduino playground page
* [..as mentioned on my blog](https://blog.tardate.com/2016/07/littlearduinoprojects219-ds18s20-1-wire.html)
