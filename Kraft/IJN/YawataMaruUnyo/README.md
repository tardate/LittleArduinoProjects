# #679 Yawatamaru / Un'yō Conversion

Using a Pepper's Ghost effect in a box diorama to capture the Yawatamaru (八幡丸) conversion to Taiyō-class escort carrier Un'yō (雲鷹).

![Build](./assets/YawataMaruUnyo_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/mHR9h1_hlYA/0.jpg)](https://www.youtube.com/watch?v=mHR9h1_hlYA)

And here's a behind-the-scenes view of the box diorama in action:

[![clip](https://img.youtube.com/vi/TQ0gLDy1ZRg/0.jpg)](https://www.youtube.com/watch?v=TQ0gLDy1ZRg)

## Notes

Yawatamaru (八幡丸) is one of three Nitta Maru-class cargo liners built in Japan during the late 1930s to be transferred to the Imperial Japanese Navy (IJN) for conversion to escort carrier. The Yawatamaru was converted in 1942 to Taiyō-class escort carrier Un'yō (雲鷹, Cloud Hawk).
This is described in [The Imperial Japanese Navy in the Pacific War](https://www.goodreads.com/book/show/23719933-the-imperial-japanese-navy-in-the-pacific-war) by Mark Stille.

When I discovered that Aoshima had 1:700 water line kits of both the Yawatamaru and Un'yō (both new tools from 1982), the lure was irresistible.

The interesting question was how to display the ships to best effect to describe the conversion.
I wondered whether a box diorama with a [Pepper's ghost](https://en.wikipedia.org/wiki/Pepper%27s_ghost) illusion would work.

Well, I finished making the kits back in 2021, crated the basic box diorama and electronics in 2022 but it then sat on the shelf
waiting for me to come and tweak the effect. Which I finally did today (2023-01-02) - just before I need to go back to work;-)

### The Yawatamaru

The Aoshima kit No. 045718 of the liner Yawatamaru (日本客船 八幡丸) is available in recent boxing but is a 1982 tool.
It is however reasonably well detailed and goes together just fine.

[![kit_box](./assets/yawatamaru/kit_box.jpg?raw=true)](https://www.scalemates.com/kits/aoshima-045718-yawatamaru--323875)

| Feature                                | Gunze MrHobby  | Paint Used   |
|----------------------------------------|----------------|--------------|
| Flat White: upper hull, superstructure | H11            | Vallejo 70.951 White |
| Flat Black: funnel, hull               | H12            | Vallejo 70.950 Black |
| Tan: hatches                           | H27            | Vallejo 70.941 Burnt Umber |
| Wood Brown: deck, masts, spars         | H37            | Vallejo 70.981 Orange Brown |
| Sail Color                             | H85            | Vallejo 70.951 White |

Before I knew it I'd decided to do a pretty much full build before painting

![build_01a](./assets/yawatamaru/build_01a.jpg?raw=true)

![build_01b](./assets/yawatamaru/build_01b.jpg?raw=true)

![build_01c](./assets/yawatamaru/build_01c.jpg?raw=true)

Still got some tidying up to do - windows, weathering, rigging

![build_01d](./assets/yawatamaru/build_01d.jpg?raw=true)

### Un'yō

The Aoshima kit No. 045220 of the escort carrier Un'yō (日本海軍 航空母艦 雲鷹 ) is available in recent boxing but is also a 1982 tool.
Like the Yawatamaru it is reasonably well detailed and goes together just fine.

[![kit_box](./assets/unyo/kit_box.jpg?raw=true)](https://www.scalemates.com/kits/aoshima-045220-unyo--306524)

| Feature                                     | Gunze MrHobby  | Paint Used                  |
|---------------------------------------------|----------------|-----------------------------|
| Flat White: boat covers                     | H11            | Vallejo 70.951 White        |
| Flat Black: funnel; plane engines           | H12            | Vallejo 70.950 Black        |
| Cocoa Brown: lower hull                     | H17            | Vallejo 70.985 Hull Red     |
| Wood Brown: boat decks                      | H37            | Vallejo 70.941 Burnt Umber  |
| IJN Green: plane upper surfaces             | H59            | Vallejo 70.897 Bronze Green |
| IJN Gray: plane lower surfaces              | H61            | Vallejo 70.989 Sky Grey     |
| IJN Gray: flight deck                       | H61            | Vallejo 70.990 Light Grey   |
| Dark Gray: upper hull                       | H83            | Vallejo 70.992 Neutral Grey + 30% 70.994 Dark Grey |

Starting the Un'yō..

![build_02a](./assets/unyo/build_02a.jpg?raw=true)
![build_02b](./assets/unyo/build_02b.jpg?raw=true)
![build_02c](./assets/unyo/build_02c.jpg?raw=true)

So.. the thing about building carriers!!

![build_02d](./assets/unyo/build_02d.jpg?raw=true)

Pile-up on the flight deck

![build_02e](./assets/unyo/build_02e.jpg?raw=true)

### Finishing the Ship Construction

![build_03a](./assets/build_03a.jpg?raw=true)
![build_03b](./assets/build_03b.jpg?raw=true)
![build_03c](./assets/build_03c.jpg?raw=true)
![build_03d](./assets/build_03d.jpg?raw=true)

Finished the main build of the Aoshima 1:700 kits (rigging and weathering to come).

![build_03e](./assets/build_03e.jpg?raw=true)

![build_04a](./assets/unyo/build_04a.jpg?raw=true)

![build_04b](./assets/unyo/build_04b.jpg?raw=true)

finishing details for the Un'yō - a little rigging, rust effects and modulation

![build_04c](./assets/unyo/build_04c.jpg?raw=true)

![build_05a](./assets/yawatamaru/build_05a.jpg?raw=true)

the Yawatamaru gets some rigging

![build_05b](./assets/yawatamaru/build_05b.jpg?raw=true)

### Pepper's Ghost Lighting Effects

The lighting effect is achieved with 4x 12V cool white LED strips, individually controlled by an ATtiny85 microprocessor

The Arduino sketch [YawataMaruUnyo.ino](./YawataMaruUnyo.ino) is programmed to the ATTiny85 with fuses set for 8MHz internal clock.
I used ArduinoISP to program the chip via an Arduino Uno.

LED strips are connected and used as follows:

| Pin Name               | Arduino Port | Pin | Effect                         |
|------------------------|--------------|-----|--------------------------------|
| `LEFT_FOREGROUND_LED`  | PB1          | 6   | (Yawatamaru) PWM fades         |
| `LEFT_BACKGROUND_LED`  | PB0          | 5   | (Yawatamaru) PWM fades         |
| `RIGHT_FOREGROUND_LED` | PB3          | 2   | (Un'yō)      hard on           |
| `RIGHT_BACKGROUND_LED` | PB4          | 3   | (Un'yō)      lightning flashes |

The circuit diagram is as follows. A 12V DC power supply drives the LEDs,
with a buck converter module stepping the voltage down to 5V to power the ATtiny85.

![Breadboard](./assets/YawataMaruUnyo_bb.jpg?raw=true)

![Schematic](./assets/YawataMaruUnyo_schematic.jpg?raw=true)

The sketch was initially tested on a breadboard:

![Breadboard Build](./assets/YawataMaruUnyo_bb_build.jpg?raw=true)

I transferred the design to a small piece of protoboard. Layout sketch:

![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

### Final Construction

Internal layout showing the one-way mirror on 45˚ angle in front of the Yawatamaru is a piece of acrylic with silver insulation window film applied to the rear.

![build_06a](./assets/yawatamaru/build_06a.jpg?raw=true)

The finished box

![build_06b](./assets/yawatamaru/build_06b.jpg?raw=true)

Power jack and switch on the rear..

![build_06c](./assets/yawatamaru/build_06c.jpg?raw=true)

Looking through the window when the Yawatamaru is illuminated:

![build_07a](./assets/yawatamaru/build_07a.jpg?raw=true)

Looking through the window when the Un'yō is illuminated:

![build_07b](./assets/yawatamaru/build_07b.jpg?raw=true)

Here's a demo of the final effect:

[![clip](https://img.youtube.com/vi/mHR9h1_hlYA/0.jpg)](https://www.youtube.com/watch?v=mHR9h1_hlYA)

And here's a behind-the-scenes view of the box diorama in action:

[![clip](https://img.youtube.com/vi/TQ0gLDy1ZRg/0.jpg)](https://www.youtube.com/watch?v=TQ0gLDy1ZRg)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=98268)
* [日本客船 八幡丸 Yawatamaru Aoshima No. 045718 1:700](https://www.aoshima-bk.co.jp/product/4905083045718/)
* [Japanese Pacific Ocean Liner Yawatamaru Aoshima No. 045718 1:700](https://www.scalemates.com/kits/aoshima-045718-yawatamaru--323875) - scalemates
* [日本海軍 航空母艦 雲鷹 Un'yō Aoshima No. 045220 1:700](https://www.aoshima-bk.co.jp/product/4905083045220/)
* [Japanese Aircraft Carrier Un'yō Aoshima No. 045220 1:700](https://www.scalemates.com/kits/aoshima-045220-unyo--306524) - scalemates
* [The Imperial Japanese Navy in the Pacific War](https://www.goodreads.com/book/show/23719933-the-imperial-japanese-navy-in-the-pacific-war) by Mark Stille
* [Pepper's ghost](https://en.wikipedia.org/wiki/Pepper%27s_ghost)
