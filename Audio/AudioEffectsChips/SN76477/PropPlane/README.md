# #550 SN76477 Prop Plane

Testing the SN76477 propeller plane sound effect configuration

![Build](./assets/PropPlane_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/B78GgHcby3E/0.jpg)](https://www.youtube.com/watch?v=B78GgHcby3E)

## Notes

The Texas Instruments [SN76477](https://en.wikipedia.org/wiki/Texas_Instruments_SN76477)
is a complex sound generator chip from the late 1970's and still reasonably easy to find as refurb or new-old stock.
It was covered in some detail in [Elektor Magazine 1981-03, p3-22](https://www.elektormagazine.com/magazine/elektor-198103) - "Multiple Sound Effects Generator".

It was apparently widely used in arcade games and synthesizers and does its magic by integrating a number of subsystems:

* low frequency oscillator
* noice generator
* voltage controlled oscillator
* envelope generator and modulator
* mixer
* output preamp

Features are variously enabled/controlled via pins with either:

* resistor
* capacitor
* logic level
* analog voltage level

The data sheet describes the configuration for a number of specific sound effects, including:

* steam train/propeller plan
* race car motor/crash
* siren/space war/phasor gun
* gunshot/explosion
* bird chirp
* musical organ
* steam train with whistle

As a first simple demonstration, I've put the "propellor plane" on a breadboard below.

### Breadboard Adapter

The SN76477 comes in unusual "N" and "NF" DIP sizes. I think these correspond to
[JEDEC MS-011](https://www.jedec.org/standards-documents/docs/ms-011-b) and
[JEDEC MS-010](https://www.jedec.org/standards-documents/docs/ms-010-c).

The pin and row spacing is not compatible with a breadboard so I whipped up a simple adapter with some protoboard.
I didn't go full dead bug, as I wanted to keep the pin assignments in conventional arrangement.

![SN76477_dip_adapter](./assets/SN76477_dip_adapter.jpg?raw=true)

## Construction

This is the "propeller plane" configuration described in the data sheet.

The "speed" of the engine is controlled with a variable resistor input to the low frequency oscillator on pin 20.

![Breadboard](./assets/PropPlane_bb.jpg?raw=true)

![Schematic](./assets/PropPlane_schematic.jpg?raw=true)

![Build](./assets/PropPlane_build.jpg?raw=true)

## Credits and References

* [SN76477](https://en.wikipedia.org/wiki/Texas_Instruments_SN76477) - wikipedia
* [SN76477 datasheet](https://web.archive.org/web/20110707231245/http://docs.bgmicro.com/pdf/ics76477.pdf)
* [Elektor Magazine 1981-03](https://www.elektormagazine.com/magazine/elektor-198103) - "Multiple Sound Effects Generator", p3-22
