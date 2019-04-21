# #086 OLED/SSD1306WithAdaFruitLibraries

Running the AdaFruit example program with a monochrome 128x64 OLED Display

Here's a quick video of the circuit in action:

[![OLED/SSD1306WithAdaFruitLibraries demo](https://img.youtube.com/vi/A-Yeba9-Y1I/0.jpg)](https://www.youtube.com/watch?v=A-Yeba9-Y1I)


## Notes

This is just a quick test of a monochrome 128x64 OLED Display using the [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) library.
It runs the 128x64 SPI example from AdaFruit.

I'm using an Arduino Pro Mini running on 3.3V at 8MHz, and driving the OLED directly.

The OLED is one I got from aliexpress for USD3.93 - see the seller's page: [Yellow+Blue 0.96" SPI Serial 128X64 OLED](https://www.aliexpress.com/item/M89-Free-Shipping-Yellow-Blue-0-96-SPI-Serial-128X64-OLED-LCD-Display-Module-for-Arduino/32245505493.html). Although it's a monochrome display, this unit comes with two-tinted glass, which makes the upper fifth of the screen yellow and the lower blue.

The pin breakouts are slightly different from the AdaFruit module (used in the Fritzing diagram). These are the actual pin connections for my unit:

| Arduino | OLED |
|---------|------|
| D09     | MOSI |
| D10     | CLK  |
| D11     | D/C  |
| D12     | CS   |
| GND     | GND  |
| VCC     | VCC  |

Well, that works fine. But it does use a huge amount of the memory just to do this much:
* 20,770 bytes (67%) of program storage space
* 1,580 bytes (77%) of dynamic memory

## Construction

![The Breadboard](./assets/SSD1306WithAdaFruitLibraries_bb.jpg?raw=true)

![The Schematic](./assets/SSD1306WithAdaFruitLibraries_schematic.jpg?raw=true)

![The Build](./assets/SSD1306WithAdaFruitLibraries_build.jpg?raw=true)

## Credits and References
* AdaFruit's excellent [Monochrome OLED Breakouts](https://learn.adafruit.com/monochrome-oled-breakouts/overview) page
* [SSD1306 datasheet](https://www.adafruit.com/datasheets/SSD1306.pdf)
* Requires the [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) library
* Requires the [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library) library
* [Arduino And SSD1306 Oled Display Tutorial](https://www.youtube.com/watch?v=mggDYVzS-Xs)