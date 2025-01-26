# #531 ATtiny SSD1306 I²C

Basic demonstration using an ATtiny85 to drive an SSD1306 OLED over I²C

![Build](./assets/BasicDemo_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/6ig4Ndb5gGg/0.jpg)](https://www.youtube.com/watch?v=6ig4Ndb5gGg)

## Notes

In [LEAP#530](../../../OLED/SSD1306BareBackI2C) I driving an I²C OLED display with an Arduino.
This is the same idea, but using an ATtiny85.

For this test, I'm using a [white 128x32 0.91" OLED Module](https://www.aliexpress.com/item/32672229793.html).

## OLED Module Specs

* OLED display, self-illuminating (no backlight), also lower consumption.
* Driver IC: SSD1306
* Size: 0.91 inch
* OLED Resolution: 128 x 32
* I²C interface

| Pin | Description         |
|-----|---------------------|
| GND | Power Ground        |
| VCC | Power + (DC 3.3~5v) |
| SCL | Clock Line          |
| SDA | Data Line           |

## Example Sketch

[BasicDemo.ino](./BasicDemo.ino?raw=true) demonstrates the basics of bringing up the OLED
display and running some graphics and text routines.

Since most OLED drivers require the [Arduino Wire library](https://www.arduino.cc/en/reference/wire),
they can't be used with the ATtiny.

As a replacement, I'm using the [Tiny4kOLED](https://github.com/datacute/Tiny4kOLED) driver,
which uses the [Adafruit-TinyWireM](https://github.com/adafruit/TinyWireM) I²C library for the ATtiny.

## Construction

![Breadboard](./assets/BasicDemo_bb.jpg?raw=true)

![Schematic](./assets/BasicDemo_schematic.jpg?raw=true)

![Build](./assets/BasicDemo_build.jpg?raw=true)

## Credits and References

* [ATtiny85 datasheet](https://www.microchip.com/en-us/product/ATTINY85)
* [white 128x32 0.91" OLED Module](https://www.aliexpress.com/item/32672229793.html)
* [SSD1306 datasheet](https://www.adafruit.com/datasheets/SSD1306.pdf)
* [Tiny4kOLED](https://github.com/datacute/Tiny4kOLED)
* [Adafruit-TinyWireM](https://github.com/adafruit/TinyWireM)
