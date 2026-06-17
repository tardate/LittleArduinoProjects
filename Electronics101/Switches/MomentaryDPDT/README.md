# #xxx DPDT Momentary Push-buttons

description here

![Build](./assets/MomentaryDPDT_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/4YDH20ePlHo/0.jpg)](https://www.youtube.com/watch?v=4YDH20ePlHo)

## Notes

While designing [LEAP#847 2d6 Dice Roller](../../../playground/2d6/) I considered one option that required a momentary dual pole push-button.
I didn't have any in my parts store, and it turns out that this particular switch configuration is quite rare, especially for low voltage applications.

I did find one part in a reasonable small form factor:
["5PCS 10PCS PS-202 Mini 6MM 6Pin SPDT DPDT Momentary Push Button Switch 2A 250VAC 5A 120VAC Toggle Switch With Red Cap" (aliexpress seller)](https://www.aliexpress.com/item/1005006487128734.html). I purchased 5 pieces for SG$4.88 (Jun-2026).

![dpst01a](./assets/dpst01a.jpg)

This particular part has a mirrored layout of the two poles on either side of the switch.
The switch itself has a nice positive "click" between states, but is non-latching off course.

![dpst01b](./assets/dpst01b.jpg)

I've attached some pin headers to make a breadboard-compatible switch:

![dpst01c-dip-adapter](./assets/dpst01c-dip-adapter.jpg)

### Circuit Design

Designed with Fritzing: see [MomentaryDPDT.fzz](./MomentaryDPDT.fzz).

This is a simple demonstration of a non-latching (momentary) 4-way crossover switch.

![bb](./assets/MomentaryDPDT_bb.jpg?raw=true)

![schematic](./assets/MomentaryDPDT_schematic.jpg?raw=true)

Circuit setup on a breadboard:

![bb_build](./assets/MomentaryDPDT_bb_build.jpg?raw=true)

When the button is not pressed, yellow LED is on.

![test-off](./assets/test-off.jpg?raw=true)

When the button is pressed, current is reversed. The yellow LED turns off, and the red LED turns on.

![test-on](./assets/test-on.jpg?raw=true)

## Credits and References

* ["5PCS 10PCS PS-202 Mini 6MM 6Pin SPDT DPDT Momentary Push Button Switch 2A 250VAC 5A 120VAC Toggle Switch With Red Cap" (aliexpress seller)](https://www.aliexpress.com/item/1005006487128734.html)
    * Purchased 5 pieces for SG$4.88 (Jun-2026)
* <https://en.wikipedia.org/wiki/Switch>
