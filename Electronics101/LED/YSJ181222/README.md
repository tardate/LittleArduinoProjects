# #583 LED Sequencer Module

Testing a simple 6xLED sequencer module (YuSiJie 宇思捷 YSJ181222).

![Build](./assets/YSJ181222_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/MbM46GIVMW8/0.jpg)](https://www.youtube.com/watch?v=MbM46GIVMW8)

## Notes

I found this
[6xLED flashing cycle module](https://www.aliexpress.com/item/4001314825358.html) on aliexpress.
I honestly just paid my few cents just to find out what it could do!

Turns out: no surprises: runs a simple sequence across 6 LEDs at about 4Hz.

It has the following specifications:

* Supply Voltage: 3-4.5V
* Size: 22*11mm
* Pin Space: 2.0mm

The pin spacing means one cannot simply solder some 2.54mm pin headers to the board, but no real problem.

The module is identified as "YSJ181222".
This appears to be produced under the YUSIJIE 宇思捷 brand by the
[Dongguan Yusijie Electronic Co., Ltd.](https://dgysj.en.alibaba.com/productgrouplist-821419988-2/LED_drive_ic_and_module.html).
They produce an array of interesting, niche LED driver ICs and modules.

## Construction

All the electronics are hidden under the black goop. It's probably something equivalent to a 555 + 4017 decade counter
circuit. No additional passives required: just power and 6 x LEDs.

The circuit is connected as follows.
Note the first two connectors are unused. I tried a few things but they really do appear to not be used (I was hoping they might be used for adjusting frequency).

![YSJ181222_schematic](./assets/YSJ181222_schematic.jpg?raw=true)

Be aware that I
[found another connection scheme](https://www.youtube.com/watch?v=VVGl8AEwOd4)
for a module also identified as "YSJ181222".
This is **not** what I used, and I confirmed it doesn't work with my modules.

![alternative_schematic](./assets/alternative_schematic.jpg?raw=true)

## Testing

Running on a breadboard, with frequency measurement conencted and reading 3.917Hz:

![Breadboard Build](./assets/YSJ181222_bb_build.jpg?raw=true)

## Credits and References

* [10pcs/lot DIY 6-LED LEDs 3-4.5V Flash Chip COB LED Driver Cycle Flashing Control Board Module IC Electronic](https://www.aliexpress.com/item/4001314825358.html) - aliexpress seller
* [Dongguan Yusijie Electronic Co., Ltd.](https://dgysj.en.alibaba.com/productgrouplist-821419988-2/LED_drive_ic_and_module.html)
