# #366 Nokia 5110 LCD/AdafruitSoftwareSPI

A quick Nokia 5110 LCD test using software SPI and the Adafruit PCD8544 library.

![Build](./assets/AdafruitSoftwareSPI_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I've been having SPI conflicts with other libraries I've used for controlling the Nokia 5110 LCD,
so time to pull out the big guns - the wonderful Adafruit library set which includes a PCD8544 module.

### 5110 LCD SPI Configuration

This is a test of the software SPI configuration, which means we steer clear of the hardware SPI pins (10-13 on an Arduino Uno).

Here's the mapping from the terminology used by my particular 5110 module and pins on an Arduino Uno.

| Pin       | Usage                 | Arduino Uno Pin |
|-----------|-----------------------|-----------------|
| RST       | reset                 | 7               |
| CE/SCE/SS | chip enable           | 6               |
| DC/CSN    | data/command select   | 5               |
| DIN       | data in               | 8 SPI MOSI      |
| CLK       | clock                 | 9 SPI SCK       |
| VCC       | power                 | 5V              |
| BL        | Backlight on when GND | n/c             |
| GND       | Ground                | GND             |

## Construction

![Breadboard](./assets/AdafruitSoftwareSPI_bb.jpg?raw=true)

![Schematic](./assets/AdafruitSoftwareSPI_schematic.jpg?raw=true)

![Build](./assets/AdafruitSoftwareSPI_build.jpg?raw=true)

## Credits and References
* [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) - GitHub
* [LEAP#365 AdafruitHardwareSPI](../AdafruitHardwareSPI) - same project using hardware SPI
* [..as mentioned on my blog](http://blog.tardate.com/2017/12/leap365366-driving-nokia-5110-lcd-with-adafruit-library.html)
