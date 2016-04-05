# #201 555Timer/DoorbellKit

Another two-tone doorbell using a 555 timer oscillator

## Notes

I picked up
[this kit](http://www.aliexpress.com/item/Perfect-Doorbell-Suite-Electronic-DIY-Kit-for-Home-Security-6V-PCB-3-9-x-3-5/32497451130.html)
on special for $0.66. It even came with extra components to throw in the drawer.

The kit actually turns out to be a simplified version of the [TwoToneDoorbell](../TwoToneDoorbell) circuit I've built before.

It lacks the power control circuit, and draws about 4mA when idle - so if you actually use, expect to be replacing batteries
on a regular basis!

When S1 pressed:
* 555 timer reset (4) is pulled high and charges the R4/C1 RC circuit
* it bypasses R1 (via D2) so that the 555 astable behaviour is governed by R2/R3/C2
* speaker is driven with a [102.128 Hz](http://visual555.tardate.com/?mode=astable&r1=47&r2=47&c=0.1) square wave

When S1 released:
* R1 is added to the 555 astable biasing
* speaker output modultes to [76.596 Hz](http://visual555.tardate.com/?mode=astable&r1=94&r2=47&c=0.1)

The duration of the "dong" depends on the R4/C1 [RC time constant (𝛕)](http://en.wikipedia.org/wiki/RC_time_constant),
[470ms](http://www.wolframalpha.com/input/?i=47k%CE%A9+*+10%CE%BCF).
When the voltage on pin 4 falls below the reset threshold (typically 0.5V), the oscillation stops.

## Construction

![Breadboard](./assets/DoorbellKit_bb.jpg?raw=true)

![The Schematic](./assets/DoorbellKit_schematic.jpg?raw=true)

![The Build](./assets/DoorbellKit_build.jpg?raw=true)

## Credits and References
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [Doorbell DIY Kit](http://www.aliexpress.com/item/Perfect-Doorbell-Suite-Electronic-DIY-Kit-for-Home-Security-6V-PCB-3-9-x-3-5/32497451130.html) - from a seller on aliexpress
