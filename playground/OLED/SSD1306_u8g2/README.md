# #527 SSD1306 With u8g v2

Testing an SSD1306 128x32 OLED with the new v2 u8g library.

![Build](./assets/SSD1306_u8g2_build.jpg?raw=true)

## Notes

I grabbed a [white 128x32 0.91" OLED Module](https://www.aliexpress.com/item/32672229793.html) to test for a new project,
and discovered there's a new version of the [U8g library](https://github.com/olikraus/U8g2_Arduino) (v2) that's also worth checking out.

It seems the author has put a lot of work into refactoring and improving what was already one of
the best lightweight libraries for driving monochrome displays.

One of the main differences is that Arduino support is provided in two classes that can be chosen to best suit the application:

* [U8g2](https://github.com/olikraus/u8g2/wiki/u8g2reference) - includes all graphics procedures, many fonts, but requires buffer memory
* [U8x8](https://github.com/olikraus/u8g2/wiki/u8x8reference) - text only, fonts that fit an 8x8 grid, writes direct to device (no buffer memory)

I cobbled together two sketches to test each of the interfaces:
[DemoU8g2](./DemoU8g2/DemoU8g2.ino?raw=true) and [DemoU8x8](./DemoU8x8/DemoU8x8.ino?raw=true) respectively.

## OLED Module Specs

* OLED display, self-illuminating (no backlight), also lower consumption.
* Driver IC: SSD1306
* Size: 0.91 inch
* OLED Resolution: 128 x 32
* I²C interface

| Pin | Description          |
|-----|----------------------|
| GND | Power Ground         |
| VCC | Power + (DC 3.3 ~5v) |
| SCL | Clock Line           |
| SDA | Data Line            |

![oled_mechanical1](./assets/oled_mechanical1.jpg?raw=true)
![oled_mechanical2](./assets/oled_mechanical2.jpg?raw=true)

## Construction

The module works well on 3.3V or 5V. I have added pull-up resistors on the I²C, but with short jumper wires these don't seem essential.
Combinations I've tested that work:

* 5V Arduino, 3.3V power to OLED, with pull-up resistors
* 5V Arduino, 5V power to OLED, with pull-up resistors
* 5V Arduino, 5V power to OLED, no pull-up resistors

![Breadboard](./assets/SSD1306_u8g2_bb.jpg?raw=true)

![Schematic](./assets/SSD1306_u8g2_schematic.jpg?raw=true)

## Testing

Testing a couple of fonts with the U8g2 library API. Flash size: 9482 bytes.

![DemoU8g2](./assets/DemoU8g2.jpg?raw=true)

Testing a couple of fonts with the U8x8 library API. Flash size: 6764 bytes.

![DemoU8x8](./assets/DemoU8x8.jpg?raw=true)

## Credits and References

* [white/blue OLED 128X32 OLED LCD LED Display Module 0.91" IIC Communicate for ardunio](https://www.aliexpress.com/item/32672229793.html) - aliexpress
* [U8glib V2 library for Arduino](https://github.com/olikraus/U8g2_Arduino)
* [SSD1306 Datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)
