# #436 LED Drivers: QX5252 Joule Thief

Using a QX5252/YX805 LED driver chip as a joule thief for driving an LED from a low-voltage battery.

![Build](./assets/QX5252JouleThief_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/t6bDAJE5T_M/0.jpg)](https://www.youtube.com/watch?v=t6bDAJE5T_M)

## Notes

I recently "discovered" solar LED driver ICs that are mainly designed to drive solar-powered lights,
such as the QX5252 and YX805. They come in TO-94 and DIP-8 packages, and most applications only require an additional external inductor.

I've since used these chips in some circuits like the [LEAP#436 BEAM Vibrabot](https://github.com/tardate/LittleArduinoProjects/tree/master/Kinetics/BEAM/Vivian).

The QX5252 and YX805 turn out to be identical in form and function, but since I was more successful in finding resources for the QX5252,
I will mainly refer to that product.

The core features include:

* a switching circuit for voltage boost from 0.9-1.5V to the 2-3V required to drive an LED (similar to a joule thief circuit)
* charging a rechargeable battery from a solor cell, with integrated Schottky Diode for reverse polarity protection
* over-discharge protection
* light control switch, only available in DIP-8 package - requires external photocell to achieve a similar result with TO-94 package

Key specifications:

* Operating voltage: 0.9V-1.5V
* Output current: 3mA-300mA


The primary configuration is as follows:

* rechargeable battery e.g. [NiMh](https://en.wikipedia.org/wiki/Nickel%E2%80%93metal_hydride_battery) is the main power source for the LEDs
* a fast oscillation (100kHz +) on the LX pin turn the inductor into a boost converter to drive the LEDs at sufficient voltage
* a solar cell will charge the battery (no fancy charging circuitry)

![primary_configuration](./assets/primary_configuration.png?raw=true)


### The Simple "Joule Thief" Configuration

As a test and demonstration, I'm ignoring the solar charging aspect here, and just use the chip as a "joule thief" to drive an LED
with a battery that has a lower voltage than the forward voltage of the LED.

To make things a little interesting, I'll build this as a free-standing circuit that just clips onto the battery.

The battery I'm using here is an AG8 (aka LR1120, 191) rated at 1.55V, and I confirmed it cannot directly drive the LED I'm using -
a nice blue 0805 SMD (and blue typically has much higher forward voltage than other colours).

Only 4 parts  are required:

| Item | Description             |
|------|-------------------------|
| IC1  | QX5252 (or YX805)       |
| L1   | inductor                |
| LED1 | The LED - blue 0805 SMD |
| BAT  | Battery - AG8 1.55V     |


The only question to answer is the size of the inductor:

* some versions of the datasheet mention 68µH as a guide. That works.
* or it can be calculated: `LED Power = 2 * VBAT / L * 10^-6` (formula from QX5252 datasheet)
* or one can experiment..

In truth, a wide range of inductance will work, with the considerations:

* too low, and it may not generate sufficient voltage to drive the LED
* too high, and it may fry the LED (if the battery can deliver enough power)

Here are some examples at both ends of the spectrum.

First, with a larger inductor of 100µH, voltage output from the boost converter (at LX, driving the LED) looks like this.
This is a good curve, peaking at just over 3V which is ample to drive the LEDs (Vf = 2.7V).
The switching frequency is around 130kHz, and duty cycle over Vf is perhaps 20%. This results in a nice strong LED illumination.

![scope_100uH](./assets/scope_100uH.gif?raw=true)

Dropping the inductance to 1µH and the result is quite anaemic. Sufficient voltage to drive the LED is only generated for
a very short period. So while it does still manage to illuminate the LED, it does so quite weakly.

![scope_1uH](./assets/scope_1uH.gif?raw=true)


## Construction

![Breadboard](./assets/QX5252JouleThief_bb.jpg?raw=true)

![Schematic](./assets/QX5252JouleThief_schematic.jpg?raw=true)

Carefully put together so that it forms a clip over the battery:

![build_01](./assets/build_01.jpg?raw=true)

![build_02](./assets/build_02.jpg?raw=true)

![build_03](./assets/build_03.jpg?raw=true)

## Credits and References

* [QX5252 product info](http://www.qxmd.com.cn/en/?product/QX5252.html)
* [List of battery sizes](https://en.wikipedia.org/wiki/List_of_battery_sizes) - wikipedia
* [..as mentioned on my blog](https://blog.tardate.com/2018/11/leap437-qx5252-joule-thief.html)
