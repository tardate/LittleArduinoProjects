# #377 Nokia 5110 Shield

Putting a Nokia 5110 on an Arduino Uno shield for no-fuss prototyping.

![Build](./assets/DIYShield_build.jpg?raw=true)

## Notes

I'm finding myself using a Nokia 5110 display in various little projects, and wiring it up
every time is getting a bit tiresome.

I have some prototyping shields
[like this](https://www.aliexpress.com/item/Free-Shipping-UNO-Proto-Shield-prototype-expansion-board-with-SYB-170-mini-bread-board-based-For/32502867722.html)
and decided to mount a 5110 screen on one.

It turns out to be a tight squeeze, and I've actually bent out the pin headers on the shield a bit so they are still accessible for use.

## Pin Arrangement

There are a range of libraries that can be used with the 5110. Some use hardware SPI, others just software control.
Pin assignments do not really matter, with the exception of MOSI and SCK for hardware SPI.
I decided to use the following pins for the shield

| Pin       | Usage                 | Arduino Uno Pin |
|-----------|-----------------------|-----------------|
| RST       | reset                 | 10              |
| CE/SCE/SS | chip enable           | 9               |
| DC/CSN    | data/command select   | 8               |
| DIN       | data in               | 11 SPI MOSI     |
| CLK       | clock                 | 13 SPI SCK      |
| VCC       | power                 | 5V              |
| BL        | Backlight on when GND | n/c             |
| GND       | Ground                | GND             |

## Test Sketch

The [DIYShield.ino](./DIYShield.ino) sketch runs a simple hardware SPI demo on the 5110, using the
[Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library).

## Construction

![Breadboard](./assets/DIYShield_bb.jpg?raw=true)

![Schematic](./assets/DIYShield_schematic.jpg?raw=true)

Wiring the protoboard. Note that by default I don't have the backlight on.

![DIYShield_wiring](./assets/DIYShield_wiring.jpg?raw=true)

![Build](./assets/DIYShield_build.jpg?raw=true)

## Credits and References
* [UNO Proto Shield](https://www.aliexpress.com/item/Free-Shipping-UNO-Proto-Shield-prototype-expansion-board-with-SYB-170-mini-bread-board-based-For/32502867722.html) - aliexpress seller
* [Adafruit-PCD8544 Library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) - GitHub
* [..as mentioned on my blog](https://blog.tardate.com/2018/02/leap377-diy-nokia-5110-shield.html)
