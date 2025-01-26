# #396 CapacitiveTouchOrgan

A simple chromatic scale organ, controlled with a Freescale/NXP MPR121 Proximity Capacitive Touch Sensor and an Arduino.

![Build](./assets/CapacitiveTouchOrgan_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/11-BnUGQX18/0.jpg)](https://www.youtube.com/watch?v=11-BnUGQX18)

## Notes

The MPR121 is a capacitive touch sensor.
Originally produced by Freescale (now NXP), the part is end-of-life but still widely available, especially
on breakout boards
[like this one](https://www.aliexpress.com/item/Free-shipping-MPR121-Breakout-v12-Proximity-Capacitive-Touch-Sensor-Controller-Keyboard-Development-Board/32236870852.html).

![MPR121_module](./assets/MPR121_module.jpg?raw=true)

Both [Sparkfun](https://learn.sparkfun.com/tutorials/mpr121-hookup-guide) and
[Adafruit](https://learn.adafruit.com/adafruit-mpr121-12-key-capacitive-touch-sensor-breakout-tutorial/overview)
have procude boards and tutorials at one point.

I think I first picked up one of these modules after watching Julian Ilett's video:

[![clip](https://img.youtube.com/vi/AhVizoU8CB4/0.jpg)](https://www.youtube.com/watch?v=AhVizoU8CB4)


## Voltage Matching

The MPR121 is a <3.6V device, but I'm testing it here with an Arduino Uno running at 5V.
The Uno conveniently provides 3.3V, which is fine to power the module,
but that doesn't help the I²C bus and interrupt.

Although I believe some have run the I²C at 5V without immediately destroying the module, I'm running the bus through a level shiter module.

Since the interrupt is output from the module (active low), it doesn't need level shifting.


## Code

The [CapacitiveTouchOrgan](./CapacitiveTouchOrgan.ino) sketch implements a simple 12-tone (chromatic scale from C5/523.25Hz) organ:

* on interrupt from the MPR121..
* uses the Adafruit_MPR121 library to get touch state via I²C/Wire
* sounds the corresponding tone on pin 8

Uses:

* Standard [Wire Library](https://www.arduino.cc/en/Reference/Wire)
* Standard [tone function](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)
* [Adafruit_MPR121](https://github.com/adafruit/Adafruit_MPR121)

## Breadboard Construction

![Breadboard](./assets/CapacitiveTouchOrgan_bb.jpg?raw=true)

![Schematic](./assets/CapacitiveTouchOrgan_schematic.jpg?raw=true)

Here's an initial breadboard build:

![CapacitiveTouchOrgan_bb_build](./assets/CapacitiveTouchOrgan_bb_build.jpg?raw=true)

## Organ Construction

I decided to use 12 old 5 cent coins for touch control, and mount it on some Ikea honeycomb
cardboard packing material (surprisingly useful for quick builds).

Some protoboard with headers provides mountings for the MPR121 and level-shifting modules.

An 8Ω speaker with 100Ω current-limiting resistor is also mounted on the cardboard  base.

I decided not to build-in and Arduino, so just provided a row of headers for connecting an external Arduino

![CapacitiveTouchOrgan_build](./assets/CapacitiveTouchOrgan_build.jpg?raw=true)

My sketch of pin layouts on the protoboard:

![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

All connections on the underside of the cardboard base:

![CapacitiveTouchOrgan_build_reverse](./assets/CapacitiveTouchOrgan_build_reverse.jpg?raw=true)

## Credits and References

* [MPR121: Proximity Capacitive Touch Sensor Controller](https://www.nxp.com/products/no-longer-manufactured/proximity-capacitive-touch-sensor-controller:MPR121) - archived product data
* [MPR121 Hookup Guide](https://learn.sparkfun.com/tutorials/mpr121-hookup-guide) - sparkfun
* [1-Day Project: MPR121 Capacitive Touch Sensor Music Organ](https://www.youtube.com/watch?v=AhVizoU8CB4) - Julian Ilett
* [Adafruit MPR121 12-Key Capacitive Touch Sensor Breakout Tutorial](https://learn.adafruit.com/adafruit-mpr121-12-key-capacitive-touch-sensor-breakout-tutorial/overview)
* [MPR121 Breakout v12 Proximity Capacitive Touch Sensor Controller Keyboard Development Board](https://www.aliexpress.com/item/Free-shipping-MPR121-Breakout-v12-Proximity-Capacitive-Touch-Sensor-Controller-Keyboard-Development-Board/32236870852.html) - example from aliexpress seller
* [Frequencies for equal-tempered scale, A4 = 440 Hz](https://pages.mtu.edu/~suits/notefreqs.html)
* [..as mentioned on my blog](https://blog.tardate.com/2018/07/leap396-capacitive-touch-organ.html)
