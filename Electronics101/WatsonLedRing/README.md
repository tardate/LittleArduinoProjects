# #164 WatsonLedRing

Test a Watson 3-LED Ring oscillator.

Here's a quick video of the circuit in action:

[![WatsonLedRing](http://img.youtube.com/vi/Guscsbysltw/0.jpg)](http://www.youtube.com/watch?v=Guscsbysltw)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

A neat and simple circuit that I found presented on the [rustybolt blog](http://rustybolt.info/wordpress/?p=664).

It has three n-channel mosfets linked in a ring with an RC circuit controlling the gate of each.
Each FET drives an LED. Once the circuit gets started, it oscillates indefinitely.

There is nothing inherent in the circuit that kicks off the oscillation - it is completely symmetrical -
so I guess it relies on slight component variations and residual capacitor charge to get started.
In practice I haven't seen any issues getting the oscillation started.

This runs at 5V nicely, which is enough to exceed the LED forward voltage with sufficient headroom to turn on the FETs hard enough.

Since 5V is a bit inconvenient to packaging, it's possible to run off a lower voltage by adding 22kΩ resistors in parallel with the LEDs.
In this configuration, I was able to get by with as low as 3V.

## Construction

![Breadboard](./assets/WatsonLedRing_bb.jpg?raw=true)

![The Schematic](./assets/WatsonLedRing_schematic.jpg?raw=true)

![The Build](./assets/WatsonLedRing_build.jpg?raw=true)

## Credits and References
* [Watson’s 3 LED Ring Oscillator](http://rustybolt.info/wordpress/?p=664) - blog post describing the original circuit
