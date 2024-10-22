# #365 Nokia 5110 LCD/AdafruitHardwareSPI

A quick Nokia 5110 LCD test using hardware SPI and the Adafruit PCD8544 library.

![Build](./assets/AdafruitHardwareSPI_build.jpg?raw=true)

Here's a quick demo..

[![5Id0RPrwmbw](https://img.youtube.com/vi/5Id0RPrwmbw/0.jpg)](https://www.youtube.com/watch?v=5Id0RPrwmbw)

## Notes

I've been having SPI conflicts with other libraries I've used for controlling the Nokia 5110 LCD,
so time to pull out the big guns - the wonderful Adafruit library set which includes a PCD8544 module.

### 5110 LCD SPI Configuration

This is a test of the hardware SPI configuration, which means pin connections are fixed for MOSI and SCK.

Here's the mapping from the terminology used by my particular 5110 module and pins on an Arduino Uno.

| Pin       | Usage                 | Arduino Uno Pin |
|-----------|-----------------------|-----------------|
| RST       | reset                 | 7               |
| CE/SCE/SS | chip enable           | 6               |
| DC/CSN    | data/command select   | 5               |
| DIN       | data in               | 11 SPI MOSI     |
| CLK       | clock                 | 13 SPI SCK      |
| VCC       | power                 | 5V              |
| BL        | Backlight on when GND | n/c             |
| GND       | Ground                | GND             |

## Construction

![Breadboard](./assets/AdafruitHardwareSPI_bb.jpg?raw=true)

![Schematic](./assets/AdafruitHardwareSPI_schematic.jpg?raw=true)

![Build](./assets/AdafruitHardwareSPI_build.jpg?raw=true)

## Credits and References

* [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) - GitHub
* [LEAP#366 AdafruitSoftwareSPI](../AdafruitSoftwareSPI) - same project using software SPI
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap365366-driving-nokia-5110-lcd-with-adafruit-library.html)
