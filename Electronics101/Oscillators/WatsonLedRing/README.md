# #164 Watson LED Ring

Test a Watson 3-LED Ring oscillator.

![The Build](./assets/WatsonLedRing_build.jpg?raw=true)

Here's a quick video of the circuit in action:

[![WatsonLedRing](https://img.youtube.com/vi/U6qPxcxIn7U/0.jpg)](https://www.youtube.com/watch?v=U6qPxcxIn7U)

## Notes

A neat and simple circuit that I found presented on the [rustybolt blog](http://rustybolt.info/wordpress/?p=664).

It has three n-channel mosfets linked in a ring with an RC circuit controlling the gate of each.
Each FET drives an LED. Once the circuit gets started, it oscillates indefinitely.

There is nothing inherent in the circuit that kicks off the oscillation - it is completely symmetrical -
so I guess it relies on slight component variations and residual capacitor charge to get started.
In practice I haven't seen any issues getting the oscillation started.

This runs at 5V nicely, which is enough to exceed the LED forward voltage with sufficient headroom to turn on the FETs hard enough.

## Construction

![Breadboard](./assets/WatsonLedRing_bb.jpg?raw=true)

![The Schematic](./assets/WatsonLedRing_schematic.jpg?raw=true)

![WatsonLedRing_bb_build](./assets/WatsonLedRing_bb_build.jpg?raw=true)

Here's a quick video of the circuit running on a breadboard:

[![WatsonLedRing](https://img.youtube.com/vi/Guscsbysltw/0.jpg)](https://www.youtube.com/watch?v=Guscsbysltw)

## Running at 3V

Since 5V is a bit inconvenient to package, it's possible to run off a lower voltage by adding 22kΩ resistors in parallel with the LEDs.
It also helps to switch to LEDs with a lower forward voltage.

I tested this configuration with green LEDs, and was able to get it running very nicely on a 3V coin cell.

![Breadboard](./assets/WatsonLedRing3V_bb.jpg?raw=true)

![The Schematic](./assets/WatsonLedRing3V_schematic.jpg?raw=true)

![WatsonLedRing3V_bb_build](./assets/WatsonLedRing3V_bb_build.jpg?raw=true)

Here's a quick video of the 3V circuit running on a breadboard:

[![WatsonLedRing](https://img.youtube.com/vi/AgwLT4MlFh8/0.jpg)](https://www.youtube.com/watch?v=AgwLT4MlFh8)

## Freeform Build

This is a quick freeform build that arranges the 3-LED ring in a circular frame that holds a CR2032 coin cell

![WatsonLedRing3V_build_complete](./assets/WatsonLedRing3V_build_complete.jpg?raw=true)

![The Build](./assets/WatsonLedRing_build.jpg?raw=true)

Here's a quick video of the circuit in action:

[![WatsonLedRing](https://img.youtube.com/vi/U6qPxcxIn7U/0.jpg)](https://www.youtube.com/watch?v=U6qPxcxIn7U)

## Credits and References

* [Watson’s 3 LED Ring Oscillator](http://rustybolt.info/wordpress/?p=664) - blog post describing the original circuit
* [Ring oscillator](https://en.wikipedia.org/wiki/Ring_oscillator) - wikipedia
