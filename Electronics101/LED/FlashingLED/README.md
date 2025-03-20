# #717 Flashing LEDs

A quick test and review of a range of 5mm flashing LEDs: red , slow RGB, fast RGB.

![Build](./assets/FlashingLED_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/7EdzYHdnOAo/0.jpg)](https://www.youtube.com/watch?v=7EdzYHdnOAo)

## Notes

I have a range of flashing LEDs in by parts drawers.
These are 3mm and 5mm form-factor clear LEDs, but contain  all the circuitry to flash - no external components required. Very convenient when a simple flashing effect is required.

They come in different configurations, for example, I have on hand:

* 5mm Red flash
* 5mm RGB Slow flash
* 5mm RGB Flash flash

These are widely available.
For example:
[this seller on aliexpress](https://www.aliexpress.com/item/1005007519775384.html) has a full range of 3mm, 5mm, Red, RGB flashing options. Look for listings similar to:

> 100Pcs 3mm 5mm Led Diode Flashing White Red Green Blue Yellow RGB Fast Slow Flash Diffused Clear Color Changing Light Emitting

### Circuit Design

A single LED can easily be powered from a CR2032 coin cell.

For this demo I'm running 9 LEDs in parallel (3x red, 3x slow RGB, 3x fast RGB), so I'm running it from a bench power supply set to 3V. It draws around 40mA peak.

![bb](./assets/FlashingLED_bb.jpg?raw=true)

![schematic](./assets/FlashingLED_schematic.jpg?raw=true)

![bb_build](./assets/FlashingLED_bb_build.jpg?raw=true)

## Credits and References

* [100Pcs 3mm 5mm Led Diode Flashing White Red Green Blue Yellow RGB Fast Slow Flash Diffused Clear Color Changing Light Emitting](https://www.aliexpress.com/item/1005007519775384.html) - seller listing on aliexpress
