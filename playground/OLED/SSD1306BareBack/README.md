# OLED/SSD1306BareBack

Test driving a monochrome 128x64 OLED Display with an Arduino and the raw command set

Here's a quick video of the circuit in action:

[![OLED/SSD1306BareBack demo](http://img.youtube.com/vi/A-Yeba9-Y1I/0.jpg)](http://www.youtube.com/watch?v=A-Yeba9-Y1I)

## Notes

It runs a simple demo cycle, including the reading and display of a voltage from the A0 pin.

There are a few commonly-used libraries - [such as ladyada's](https://github.com/adafruit/Adafruit_SSD1306),
as demoed in the [SSD1306WithAdaFruitLibraries](../SSD1306WithAdaFruitLibraries) project -
however this sketch uses the instruction set for device directly, as documented in the [SSD1306 datasheet](https://www.adafruit.com/datasheets/SSD1306.pdf).

I'm using an Arduino Pro Mini running on 3.3V at 8MHz, and driving the OLED directly.

The OLED is one I got from aliexpress for USD3.93 - see the seller's page: [Yellow+Blue 0.96" SPI Serial 128X64 OLED](http://www.aliexpress.com/item/M89-Free-Shipping-Yellow-Blue-0-96-SPI-Serial-128X64-OLED-LCD-Display-Module-for-Arduino/32245505493.html). Although it's a monochrome display, this unit comes with two-tinted glass, which makes the upper fifth of the screen yellow and the lower blue.


The pin breakouts are slightly different from the AdaFruit module (used in the Fritzing diagram). These are the actual pin connections for my unit:

| Arduino | OLED |
|---------|------|
| D09     | MOSI |
| D10     | CLK  |
| D11     | D/C  |
| D12     | CS   |
| GND     | GND  |
| VCC     | VCC  |


## Construction

![The Breadboard](./assets/SSD1306BareBack_bb.jpg?raw=true)

![The Schematic](./assets/SSD1306BareBack_schematic.jpg?raw=true)

![The Build](./assets/SSD1306BareBack_build.jpg?raw=true)

## Credits and References
* AdaFruit's excellent [Monochrome OLED Breakouts](https://learn.adafruit.com/monochrome-oled-breakouts/overview) page
* [SSD1306 datasheet](https://www.adafruit.com/datasheets/SSD1306.pdf)
* [1-Day Project: Arduino Uno and I2C OLED Display Challenge](https://www.youtube.com/watch?v=VEZGn0zYHiE)
* [Introduction to I²C and SPI protocols](http://www.byteparadigm.com/applications/introduction-to-i2c-and-spi-protocols/)
* [Arduino And SSD1306 Oled Display Tutorial](https://www.youtube.com/watch?v=mggDYVzS-Xs)