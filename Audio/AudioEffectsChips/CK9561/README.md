# #520 CK9561 Audio Effects Chip

Figuring out how to use the CK9561 music chip with 4 sound effects - alarm/siren/weapon sounds that sound strangely familiar if you have ever walked through a toy department at Christmas!

![Build](./assets/CK9561_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/wS0hG0z_4rM/0.jpg)](https://www.youtube.com/watch?v=wS0hG0z_4rM)

## Notes

The CK9561 is the latest in a series of music effects chips I've been testing.
The CK9561 is sometimes labelled KD9561 of XK9561 - I presume these are just different manufacturer's names for boards based on the same chip.

The module,with pins attached for testing on a breadboard:

![Build](./assets/CK9561_module.jpg?raw=true)

## Usage and Schematic

The chip requires just a few external components to operate:

* the resistor (100kΩ-390kΩ) controls the speed of the effect - higher resistance slows the effect down
* a small signal NPN transistor (I used a 2N3904) for controlling the speaker
* and switches - not shown in the schematic below:
    * the effect is "always on", so a switch in the power line can be used for on/off control
    * switching connections "1" and "2" between unconnected/pulled-low/pulled-high select from the range of sound effects according to the following table


| Pad 1 | Pad 2      | Effect      |
|-------|------------|-------------|
| n/c   | n/c        | alarm       |
| high  | n/c or low | fire alarm  |
| low   | n/c        | ambulance   |
| any   | high       | machine gun |


![Schematic](./assets/CK9561_schematic.jpg?raw=true)

Testing on a breadboard:

![Build](./assets/CK9561_bb_build.jpg?raw=true)

I also added the chip to one of my "audio effects" copper-clad test boards. I've added a few components:

* resistor is 100kΩ fixed + 200kΩ variable resistor
* mini push-button switch on the power connection (effect on/off)
* a 3-position switch for toggling pad 1 between unconnected/pulled-low/pulled-high
* mini push-button switch on pad 2
* external 8Ω speaker

![Build](./assets/CK9561_build.jpg?raw=true)

## Credits and References

* [KD9561 CK9561 Alarm Module](https://www.aliexpress.com/item/32893135639.html) - from a seller on aliexpress
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
