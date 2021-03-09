# #585 DS1822 1-Wire Reading

Basic interrogation of a DS1822 using 1-wire protocol and results display on a Nokia 5110 LCD.

![Build](./assets/DS1822_build.jpg?raw=true)

## Notes

The DS1822 is an economy 1-Wire digital thermometer
with a range of -55°C to +125°C, at ±2.0°C Accuracy from -10°C to +85°C.

It comes in TO-92 packaging and may be powered directly (using three pins),
or take parasitic power from the data line (using two pins).

![DS1822](./assets/DS1822.jpg?raw=true)

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


## Construction

![Breadboard](./assets/DS1822_bb.jpg?raw=true)

![Schematic](./assets/DS1822_schematic.jpg?raw=true)

## The Program

The Arduino sketch is found in [DS1822.ino](./DS1822.ino).
It uses:

* [OneWire](https://github.com/PaulStoffregen/OneWire) library for temperature sensor communication
* [u8glib](https://github.com/olikraus/U8glib_Arduino) library for driving a simple display on a Nokia 5110 screen.

The sketch was written to work with the DS1822, but it can also handle DS18S20 and DS18B20 devices.

## Credits and References

* [DS1822 product info and datasheet](https://www.maximintegrated.com/en/products/sensors/DS1822.html)
* [APPLICATION NOTE 4377 1-WIRE PROTOCOL PDF OF DS18S20 VS DS18B20 DIGITAL THERMOMETERS](https://www.maximintegrated.com/en/design/technical-documents/app-notes/4/4377.html)
* [name](url)
