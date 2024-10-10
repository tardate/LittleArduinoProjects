# #620 LED-LDR Ring Oscillator

Building a simple ring oscillator using a light dependent resistor to couple the LED stages. From a circuit published in Elektor 2012/07.

![Build](./assets/LdrLedRing_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/LFlyb8KRiKg/0.jpg)](https://www.youtube.com/watch?v=LFlyb8KRiKg)

## Notes

The [LEAP#164 Watson LED Ring](../WatsonLedRing) demonstrated the typical LED ring oscillator with BJTs to couple stages.

This circuit from [Elektor 2012/07](https://www.elektormagazine.com/magazine/elektor-201207/19908/) is even simpler, using LDRs to couple the stages:

* the LDR triggers the capacitor discharge (turning off the LED)
* and the feed resistor on the anode determines the charge time to turn on the LED in combination with the capacitor

The LDR is pointed at the previous LED in the ring:

* the circuit is enabled when ambient light is low (when too bright, all LEDs are effectively bypassed by the LDRs).
* as an LED turns on, the light will strike the LDR of the neighboring LED, turning it off
* when the next LED turns off, it allows the subsequent LED to turn on

So the net effect is:

* in bright light, all LEDs off
* in low light, all LEDs want to be on, but an "off LED" will chase around the ring

### Circuit Design

I'm using LDR 5528 which is specified as dark: 1MΩ, light: 8-20kΩ.

![bb](./assets/LdrLedRing_bb.jpg?raw=true)

![schematic](./assets/LdrLedRing_schematic.jpg?raw=true)

## Breadboard Test

![bb_build](./assets/LdrLedRing_bb_build.jpg?raw=true)

## Freeform Build

Why not?

Just a quick bit of freeform wire sculpting...

![build01](./assets/build01.jpg?raw=true)

![build02](./assets/build02.jpg?raw=true)

## Credits and References

* [LED-LDR Ring Oscillator](https://www.elektormagazine.com/magazine/elektor-201207/19908/) - By Burkhard Kainka (Germany) published in Elektor Magazine, issue 7/2012 p30
