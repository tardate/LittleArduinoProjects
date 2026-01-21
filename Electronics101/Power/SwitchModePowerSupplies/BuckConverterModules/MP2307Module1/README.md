# #824 MP2307DN 1.0V-17V Mini Buck Converter Module

A common MP2307DN-based buck converter module that is extremely small and convenient for relatively low-power requirements under 17V.

![Build](./assets/MP2307Module1_build.jpg?raw=true)

## Notes

NB: see [LEAP211 Buck Converter Modules](../) for an overview of all the buck converter modules I have tried.

I purchased the
["10pcs Mini-360 DC-DC Buck Converter Step Down Module 4.75-23V to 1-17V For Arduino 340KHz" (aliexpress seller listing)](https://www.aliexpress.com/item/32436860547.html)
originally purchased as a lot of 10 for US$5.03/lot (May-2016).

The product is no longer available from the same seller, but the same item is
["1/5/10Pcs Mini360 DC-DC Converter Step Down Power Supply Module 4.75-23V To 1-17V 340Khz Mini-360 Ultra-Small" (aliexpress seller listing)](https://www.aliexpress.com/item/1005008498998352.html)
currently listed as a lot of 10 items for SG$5.22/lot (Jan-2026).

Board comprises:

* MP2307 monolithic buck converter with standard support circuits per datasheet recommendations
* pretty small package!

### Circuit Design

In the test configuration, I have the buck converter adjusted to ~3V output,
and two blue LEDs in parallel with the load. The LEDs have a forward voltage Vf of ~3V.

Designed with Fritzing: see [MP2307Module1.fzz](./MP2307Module1.fzz).

![bb](./assets/MP2307Module1_bb.jpg?raw=true)

![schematic](./assets/MP2307Module1_schematic.jpg?raw=true)

![bb_build](./assets/MP2307Module1_bb_build.jpg?raw=true)

### Performance

Quite impressive for the size. There's no scope capture below because despite my best attempts, the output voltage remained flat as a board (no detectable ripples or spikes .. just the normal noise floor)

## Credits and References

* ["10pcs Mini-360 DC-DC Buck Converter Step Down Module 4.75-23V to 1-17V For Arduino 340KHz" (aliexpress seller listing)](https://www.aliexpress.com/item/32436860547.html)
    * Originally purchased as a lot of 10 for US$5.03/lot (May-2016).
    * No longer offered by this seller.
* ["1/5/10Pcs Mini360 DC-DC Converter Step Down Power Supply Module 4.75-23V To 1-17V 340Khz Mini-360 Ultra-Small" (aliexpress seller listing)](https://www.aliexpress.com/item/1005008498998352.html)
    * Same product, currently listed as a lot of 10 items for SG$5.22/lot (Jan-2026).
* [MP2307 datasheet](https://cdn-shop.adafruit.com/datasheets/MP2307_r1.9.pdf)
