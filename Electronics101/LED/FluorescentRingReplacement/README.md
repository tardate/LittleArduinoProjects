# #471 Fluorescent Ring LED Replacement

Understanding fluorescent lighting and installing an LED replacement.

![Build](./assets/FluorescentRingReplacement_build.jpg?raw=true)

## Notes

My home has fluorescent lighting fixtures circa the late 1990s.
The ballasts are starting to fail, and so I am gradually replacing the units with higher efficiency LED alternatives.

## Typical Installation

Mostly I have circular ceiling units that are the problem.
These use the preheating/switchstart system involving:

* electromagentic ballast - [Tridonic Atco Electromagnetic Fluorescent Lighting Ballast EC36/40](https://sg.rs-online.com/web/p/lighting-ballasts/6657624/)
* starter
* fluorescent ring

![fluorescent_installation](./assets/fluorescent_installation.jpg?raw=true)

## How Fluorescent Lighting Works

In [fluorescent lighting](https://en.wikipedia.org/wiki/Fluorescent_lamp),
an electric current excites low-pressure mercury vapor, producing short-wave ultraviolet light that causes a phosphor coating on the inside of the lamp to fluoresce.

The noble gas used in the tube (commonly argon) must be ionized before the arc can strike.
Larger tubes require higher voltages for this (up to thousands of volts).

The starter is a very basic switching oscillator that can generate the required voltages in the ballast - in essence we have the basics of a switching boost converter.
Once the arc has struck, the starter is bypassed and stops.

When in operation, the ballast acts as a governor for the tube, preventing the current draw from running away and blowing itself up.

[![fluorescent_installation](./assets/1250px-Fluorescent_Light.svg.png?raw=true)](https://en.wikipedia.org/wiki/File:Fluorescent_Light.svg)

"EXPLAINED : Working of tubelight" by brain amplifier provides a very good explanation of the internals of this kind of system:

[![clip](https://img.youtube.com/vi/43j4hrGtgGs/0.jpg)](https://www.youtube.com/watch?v=43j4hrGtgGs)

##  LED Replacement

I found a
[15W LED Ring PANEL Circle Light AC220V - 240V SMD 5730 LED Round Ceiling](https://www.aliexpress.com/item/1X-5W-12W-15W-18W-23W-LED-Ring-PANEL-Circle-Light-AC85-265V-SMD-5730-LED/32334102143.html) from a seller on aliexpress.
These turned out to be a perfect replacement for the 30cm fluorescent rings with a diffuser cover.

The LED ring is 201mm in diameter, and has 15x 5730 LEDs in series, with each of the 15 serials stages containing 2 LEDs in parallel.
Hence the model number: `ø201mm-5730-2P15S`!

![kit_parts](./assets/kit_parts.jpg?raw=true)

Note: there are some LED ring units that connect directly to mains and do not need a separate driver unit (the driver is built-in to the LED board),
such as the

[![alt_without_driver](./assets/alt_without_driver.jpg?raw=true)](http://www.energy-saving.sg-best-1.com/led-panel-light-replacement-for-circular-fluorescent-tube-lamp/)

### LED Driver

The LED driver is a simple switching converter

![kit_driver](./assets/kit_driver.jpg?raw=true)

![kit_driver_rear](./assets/kit_driver_rear.jpg?raw=true)

The driver follows a standard circuit recommended for the WS3441 high precision buck constant current LED driver.
This is my re-drawing of the actual circuit:

![Schematic](./assets/FluorescentRingReplacement_schematic.jpg?raw=true)

It uses an MB10 full bridge rectifier on the input.

## Wiring Standards

In Singapore, the [Cable Colour Code](https://elise.ema.gov.sg/safety/about.html) changed from 2009-03-01.

![sg_wiring_code](./assets/sg_wiring_code.jpg?raw=true)

My property is pre-2009, so I have:

* blue: line
* black: neutral
* yellow-green: earth

## Installation

The LED ring fits quite nicely in the same dome housing as the original 30cm circular fluorescent tube.

![kit_installed](./assets/kit_installed.jpg?raw=true)

## Credits and References

* [Fluorescent Lamp](https://en.wikipedia.org/wiki/Fluorescent_lamp) - wikipedia
* [15W LED Ring PANEL Circle Light AC220V - 240V SMD 5730 LED Round Ceiling](https://www.aliexpress.com/item/1X-5W-12W-15W-18W-23W-LED-Ring-PANEL-Circle-Light-AC85-265V-SMD-5730-LED/32334102143.html)
* [Tridonic Atco Electromagnetic Fluorescent Lighting Ballast EC36/40](https://sg.rs-online.com/web/p/lighting-ballasts/6657624/)
* [Project ‘Green’ House #1: LED replacement lighting for circular fluorescent tubes](https://davidjb.com/blog/2014/07/project-green-house-1-led-replacement-lighting-for-circular-fluorescent-tubes/)
* [How to Replace a Fluorescent Light Ballast](https://www.youtube.com/watch?v=qscaybO-pJo) by Home Repair Tutor
* [WS3441 datasheet](http://www.winsemi.com/en/upload/20160322030442_2040.pdf)
