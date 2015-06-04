# OLED/ArdWinVaders

An Arduino & OLED version of a classic

## Notes

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

Note that my OLED doesn't have a reset connection, so I'm not able to use a reset to get the display back to default configuration,
hence the `setup` method runs through and sets all the configuration options regardless.


## Construction

![The Breadboard](./assets/ArdWinVaders_bb.jpg?raw=true)

![The Schematic](./assets/ArdWinVaders_schematic.jpg?raw=true)

![The Build](./assets/ArdWinVaders_build.jpg?raw=true)

## Credits and References
* [SSD1306 datasheet](https://www.adafruit.com/datasheets/SSD1306.pdf)
* [SSD1306BareBack](../SSD1306BareBack) - a sketch the exlores and explains OLED driving basics
