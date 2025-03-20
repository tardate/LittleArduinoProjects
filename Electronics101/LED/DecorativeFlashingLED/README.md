# #716 Decorative Flashing LED

A quick investigation of some decorative flashing LEDs that were scattered around a restaurant feed presentation(!)

![Build](./assets/DecorativeFlashingLED_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/2coM78GFlbY/0.jpg)](https://www.youtube.com/watch?v=2coM78GFlbY)

## Notes

I first saw these at a restaurant, where the RGB flashing units were scattered around the the base of some "special" dishes.
I was curious, so I borrowed one, and found them listed on aliexpress, for example, this listing:
[12pcs white mini led balloon lamp LED balloon Light Paper Lantern Balloon Floral for Wedding Party Decoration](https://www.aliexpress.com/item/1005008096631540.html)

At first I couldn't see if the flashing circuit as separate or integrated with the LED.
After disassembly, I was able to confirm that the LED is just a standard "RGB Fast Flash" LED.
These are widely available, for example, from this seller on aliexpress:
[100PCS F3 F5 3MM 5MM RGB 7 color Fast flash/Slow flash LED light-emitting diode (LED) 3mm RGB 7 color fast flash LED Slow flash](https://www.aliexpress.com/item/1005007082822231.html)

### Circuit Design

The units simply comprise:

* RGB Fast Flash LED
* a switch mechanism
* 3 x 1.5V LR41 battery in series (4.5V total)

![bb](./assets/DecorativeFlashingLED_bb.jpg?raw=true)

![schematic](./assets/DecorativeFlashingLED_schematic.jpg?raw=true)

### Disassembly and Test

![parts1](./assets/parts1.jpg)

![parts2](./assets/parts2.jpg)

Verifying the RGB Fast Flash LED:

![parts3](./assets/parts3.jpg)

![bb_build](./assets/DecorativeFlashingLED_bb_build.jpg?raw=true)

## Credits and References

* [12pcs white mini led balloon lamp LED balloon Light Paper Lantern Balloon Floral for Wedding Party Decoration](https://www.aliexpress.com/item/1005008096631540.html) - aliexpress seller
* [100PCS F3 F5 3MM 5MM RGB 7 color Fast flash/Slow flash LED light-emitting diode (LED) 3mm RGB 7 color fast flash LED Slow flash](https://www.aliexpress.com/item/1005007082822231.html) - aliexpress seller
