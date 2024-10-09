# #506 Single-stage Delay Switch

Comparing BJT and MOSFETs for creating a simple turn-off delay with discrete components.

![Build](./assets/SingleStageDelay_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/YTcEi-I5jsQ/0.jpg)](https://www.youtube.com/watch?v=YTcEi-I5jsQ)

## Notes

Adding an RC timing component to a single-stage low-side control circuit is a simple way of creating a "turn off delay".

The delay is proportional to the RC time constant, but the actual behaviour is quite different
depending on whether an NPN BJT or n-channel MOSFET is used as the active control component.

In both cases, a capacitor is charged during the "on" period. When power is disconnected (switch off):

* an NPN BJT will gradually turn off as the capacitor is discharged via the resistor and B-E junction. The current will reduce with voltage, producing a prolonged "fade out" effect.
* an n-channel MOSFET will turn off as the gate voltage drops, but the ohmic region will be relatively small, producing a sharper off transition

I was inspired to whip up a quick demonstration after seeing learnelectronics's "How to make a simple delay circuit" video:

[![clip](https://img.youtube.com/vi/iiwri9meO00/0.jpg)](https://www.youtube.com/watch?v=iiwri9meO00)

## Demo Circuit

To compare the BJT and MOSFET behaviour, I put both on a breadboard, triggered by a DPDT switch.
I used an 2N3904 NPN transistor, and a 2N7000 n-FET, though the parts selection is not critical.

For visually testing the circuit, the delay is set rather slow with R=1MΩ and C=1µF, for a time constant of [1s](https://www.wolframalpha.com/input/?i=1M%CE%A9+*+1000nF).

![Breadboard](./assets/SingleStageDelay_bb.jpg?raw=true)

![Schematic](./assets/SingleStageDelay_schematic.jpg?raw=true)

Actually on a breadboard:

![SingleStageDelay_bb_build](./assets/SingleStageDelay_bb_build.jpg?raw=true)

### Behaviour

To capture behaviour with an oscilloscope, I switched to R=10kΩ and C=1µF for a time constant of [10ms](https://www.wolframalpha.com/input/?i=10k%CE%A9+*+1000nF).

In the following trace, the channels are all offset by -2V and set for 1V/division. Channels are assigned:

* CH1 (Yellow) - MOSFET switch: MOSFET drain
* CH2 (Blue) - MOSFET switch: capacitor anode/MOSFET gate
* CH3 (Red) - BJT switch: BJT collector
* CH4 (Green) - BJT switch: capacitor anode

![scope_off_transition](./assets/scope_off_transition.gif?raw=true)

Points to note:

* n-channel MOSFET switch: when capacitor voltage drops to ~2V, the FET rapidly switches off within about 6ms
* NPN BJT switch: when capacitor voltage drops to 0.9V, the BJT fades over more than 100ms

### The Obligatory OCD Build

I felt like flowing some solder, so made the circuit permanent in a very literal transposition of the circuit to
a freeform build mounted on a bit of cardboard:

![Build](./assets/SingleStageDelay_build.jpg?raw=true)

## Credits and References

* [Single Mosfet Timer Circuit](https://www.homemade-circuits.com/simple-mosfet-switch-circuit-with-delay/)
* [Simple Delay Timer Circuits Explained](https://www.homemade-circuits.com/simple-delay-timer-circuits-explained/)
* [Simple time Delay Circuit using MOSFET](https://www.eleccircuit.com/off-on-after-delay-switch-by-mosfet/)
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
