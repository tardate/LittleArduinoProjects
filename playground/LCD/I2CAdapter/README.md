# #398 LCD I²C Adapter

Using an I²C adapter to reduce the Arduino pins needed to drive an LCD.

![Build](./assets/I2CAdapter_build.jpg?raw=true)

## Notes

LCDs based on the Hitachi HD44780 or a compatible chipset are a popular display option for Arduino project.
Common form factors are 1602 (16 column, 2 row) and 2004 (20 column, 4 row).

The basic LCDs require at least 6 Arduino pins to drive,
and the standard [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal) library is available for this.

To save pins and simplify wiring, there are I²C adapters available - either separately or packaged with an LCD.
These board basically use some form of Remote 8-Bit I/O Expander chip,
most commonly the PCF8574 or PCF8574A, for example from
[NXP](https://www.nxp.com/docs/en/data-sheet/PCF8574_PCF8574A.pdf).

I am using a product
["5pcs 1602 2004 LCD Adapter Plate IIC I2C / Interface lcd1602 I2C LCD Adapter for new" (aliexpress seller listing)](https://www.aliexpress.com/item/32656254948.html)
that uses a PCF8574AT.

![module](./assets/module.jpg?raw=true)

## I²C Addressing

The address for the module is different for the PCF8574 and PCF8574A.
The 7-bit hex address (without R/W bit) per the datasheet:

| A2 | A1 | A0 | PCF8574 | PCF8574A |
|----|----|----|---------|----------|
| 0  |  0 |  0 |    0x20 |     0x38 |
| 0  |  0 |  1 |    0x21 |     0x39 |
| 0  |  1 |  0 |    0x22 |     0x3A |
| 0  |  1 |  1 |    0x23 |     0x3B |
| 1  |  0 |  0 |    0x24 |     0x3C |
| 1  |  0 |  1 |    0x25 |     0x3D |
| 1  |  1 |  0 |    0x26 |     0x3E |
| 1  |  1 |  1 |    0x27 |     0x3F |

There are 3 unsoldered address pads on the module (A0, A1, A2) that are used to adjust the unit address. On the board I have, each of these are pulled high with a 1kΩ resistor by default. Closing the address pad will pull it low.
Thus the default address for the PCF8574 is 0x27, and PCF8574A is 0x3F.

## Code and Libraries

I²C is not supported by the standard LiquidCrystal library.
When I searched for I²C LCD libraries:

* it seems there is no clear leader
* there are many independent forks of common source code
* it's a bit of a mess!

Never-the-less, I picked a reletively recent one:
[LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C)
and it is working just fine.

The [I2CAdapter.ino](./I2CAdapter.ino) sketch is a simple test of the library.

## Construction

![Breadboard](./assets/I2CAdapter_bb.jpg?raw=true)

![Schematic](./assets/I2CAdapter_schematic.jpg?raw=true)

![Build](./assets/I2CAdapter_build.jpg?raw=true)

## Credits and References

* ["5pcs 1602 2004 LCD Adapter Plate IIC I2C / Interface lcd1602 I2C LCD Adapter for new" (aliexpress seller listing)](https://www.aliexpress.com/item/32656254948.html)
    * I²C adapter only
    * Originally purchased in a pack of 5 for US$3.28/lot (Jan-2018), currently listing for SG$2.72/lot (Jan-2026)
* ["1pcs LCD1602 LCD monitor 1602 5V blue screen and white code for arduino" (aliexpress seller listing)](https://www.aliexpress.com/item/32663355189.html)
    * LCD only
    * Originally purchased US$1.35 (Jan-2018), currently listing for SG$3.88 (Jan-2026)
* ["Blue Display IIC/I2C/TWI/SPI Serial Interface 1602 16X2 Character LCD Backlight Module LCD-1602 5V For Arduino" (aliexpress seller listing)](https://www.aliexpress.com/item/32278943097.html)
    * LCD combined with I²C adapter
    * Originally purchased US$2.06 (Jan-2018), currently listing for SG$3.21 (Jan-2026)
* [TI PCF8574 product data](https://www.ti.com/product/PCF8574)
* [TI PCF8574A product data](https://www.ti.com/product/PCF8574A)
* [NXP PCF8574/PCF8574A datasheet](https://www.nxp.com/docs/en/data-sheet/PCF8574_PCF8574A.pdf)
* [LiquidCrystal_I2C](https://github.com/marcoschwartz/LiquidCrystal_I2C) - library I am using
* [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal) - standard library
