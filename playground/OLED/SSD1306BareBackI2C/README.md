# #529 SSD1306 OLED Bareback I²C

Test driving a monochrome 128x32 OLED Display with an Arduino and the raw command set over I²C.

![Build](./assets/SSD1306BareBackI2C_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/QbW2QIIWK5I/0.jpg)](https://www.youtube.com/watch?v=QbW2QIIWK5I)

## Notes

In [LEAP#087](../SSD1306BareBack) I investigated using the raw command set to drive an OLED display
over SPI. This is the same idea, but using a display with an I²C interface.

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

[SSD1306BareBackI2C.ino](./SSD1306BareBackI2C.ino?raw=true) demonstrates the basics of bringing up the OLED
display and running some graphics and text routines. A 5*8 font is defined in `font.h`.

The only dependency is the [Arduino Wire library](https://www.arduino.cc/en/reference/wire).
Communication with the device is not optimised (all data is sent a byte per message)
but it is enough to demonstrate that running the OLED with raw commands is not too difficult.

## Construction

![Breadboard](./assets/SSD1306BareBackI2C_bb.jpg?raw=true)

![Schematic](./assets/SSD1306BareBackI2C_schematic.jpg?raw=true)

## Credits and References

* [white 128x32 0.91" OLED Module](https://www.aliexpress.com/item/32672229793.html)
* [SSD1306 datasheet](https://www.adafruit.com/datasheets/SSD1306.pdf)
* [Arduino Wire library](https://www.arduino.cc/en/reference/wire)
