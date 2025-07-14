# #149 Nokia 5110 LCD U8glib Demo

Quick test drive of Julian Ilett's 5110 LCD demo with the u8glib library.

## Notes

Nothing new here, I'm just testing [Julian's Ardutorials: Arduino, Nokia 5110 LCD & u8glib](https://youtu.be/t31n6Y-0bYg).

### SPI Configuration

The [u8glib](https://github.com/olikraus/u8glib) takes advantage of hardware SPI, which means
pin connections are dictated for at least MOSI and SCK.

Here's the mapping from the terminology used by my particular 5110 module and pins on an Arduino Uno.

| Pin    | Usage                 | Arduino Uno Pin |
|--------|-----------------------|-----------------|
| RST    | reset                 | 8               |
| CE/SCE | chip enable           | 10 SPI SS       |
| DC     | address line 0        | 9               |
| DIN    | data in               | 11 SPI MOSI     |
| CLK    | clock                 | 13 SPI SCK      |
| VCC    | power                 |                 |
| BL     | Backlight on when GND |                 |
| GND    | Ground                |                 |

## Construction

![Breadboard](./assets/JuliansU8glibDemo_bb.jpg?raw=true)

![The Schematic](./assets/JuliansU8glibDemo_schematic.jpg?raw=true)

![The Build](./assets/JuliansU8glibDemo_build.jpg?raw=true)

## Credits and References

* [Julian's Ardutorials: Arduino, Nokia 5110 LCD & u8glib](https://youtu.be/t31n6Y-0bYg) - great tutorial and code as used here
* [u8glib](https://github.com/olikraus/u8glib)
* [Philips PCD8544 datasheet](http://eia.udg.edu/~forest/PCD8544_1.pdf)
