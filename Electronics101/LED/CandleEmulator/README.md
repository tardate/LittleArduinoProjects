# #594 Candle Emulator

An Arduino LED candle emulation.

![Build](./assets/CandleEmulator_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/d92NyvZ8ZS0/0.jpg)](https://www.youtube.com/watch?v=d92NyvZ8ZS0)

## Notes

LEDs and candle lights that appear to flicker like real candles have become quite mainstream.
There are many imitation candle products available, and some even with wireless control.

This all seems to have been enabled by low-cost microcontrollers with a smart flicker emulator embedded into LED package itself:

[![flicker-chip](./assets/flicker-chip.jpg?raw=true)](https://cpldcpu.wordpress.com/2013/12/08/hacking-a-candleflicker-led/)

Why a microcontroller? Well it turns out that emulating a candle flicker is not so straight-forward.
I just discovered a wonderful series of articles by ["Tim"](https://cpldcpu.wordpress.com/about/)
concerning LED candles:

* [reverse engineering a real candle](https://cpldcpu.wordpress.com/2016/01/05/reverse-engineering-a-real-candle/)
* [reverse engineering an LED candle](https://cpldcpu.wordpress.com/2013/12/08/hacking-a-candleflicker-led/)
* [making a LED-Candle based on the 3 cent MCU](https://cpldcpu.wordpress.com/2019/09/28/a-led-candle-based-on-the-3-cent-mcu/)

In this little project I am simply exploring the [emulator code](https://github.com/cpldcpu/CandleLEDhack)
that Tim released and adapting it for Arduino.

## Emultion Algorithm Essentials

[Tim's work](https://cpldcpu.wordpress.com/2013/12/08/hacking-a-candleflicker-led/) basically established that flicker LEDs:

* drive the LED with a PWM signal at around 440Hz
* use 16 levels of brightness
  - the lowest 4 hardly ever used (<0.4% of samples)
  - 50% of samples are max brightness
  - the other 12 levels are almost evenly distributed
* changes the brightness level every 32 cycles (Tim calls a "frame")

## Construction

Randomly selected pin 11 on the Arduino for the LED. The code implements a pulse-width modulation (PWM) algorithm but
just uses a GPIO pin to drive the LED (so does not need a pin with hardware PWM).

A low value (220Ω) current-limiting resistor ensures decent brightness
with a yellow LED while keeping current within spec.

![bb](./assets/CandleEmulator_bb.jpg?raw=true)

![schematic](./assets/CandleEmulator_schematic.jpg?raw=true)

![bb_build](./assets/CandleEmulator_bb_build.jpg?raw=true)

## Code

The [CandleEmulator.ino](./CandleEmulator.ino) code is a refactored version of [CandeflickerLED.c](https://github.com/cpldcpu/CandleLEDhack/blob/master/Emulator/CandeflickerLED.c):

* simplified and cleaned up the algorithm
* now Arduino-specific

## Credits and References

* [Hacking a Candleflicker LED](https://cpldcpu.wordpress.com/2013/12/08/hacking-a-candleflicker-led/)
* [CandleLEDhack](https://github.com/cpldcpu/CandleLEDhack) - github
* [5mm LED Flicker Diodes](https://www.aliexpress.com/item/32782781815.html) - example LED product on aliexpress
