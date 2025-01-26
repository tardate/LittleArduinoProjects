# #091 SwitchPJFET

Switch an independent power source using an Arduino and p-channel JFET.

Here's a quick video of the circuit in action:

[![SwitchPJFET](./assets/SwitchPJFET_build2.jpg?raw=true)](https://www.youtube.com/watch?v=KfRI6a5oyQM)


## Notes

This is a simple switching circuit using a p-channel JFET.
The JFET I'm using is the J175 which is intended for low-power applications with maximum ratings of 30V/50mA.

What makes p-channel JFETs interesting (and challenging?) is the need for a positive gate-source voltage (Vgs) to turn them "off".
Since drain voltage is lower than source voltage when on,
this means the voltages are typically stacked: `gate >= source > drain`,
and biasing the device often involves two power supplies.
Keeping a correct orientation to positives and negatives is perhaps the trickiest part of all!

In this circuit, I wanted to use the 5V Arduino to switch a 9V circuit.
It turns out to be very easy, but caution is required to avoid inappropriate cross-connections of the circuit
which may inadvertently subject the Arduino to excessive or reversed voltages.

The load circuit is a simple 9V loop with LED indicator and sufficient resistance to limit the current.
The JFET source-drain loop is the switch in the circuit.

Conventionally p-channel JFETs are described with -Vdd to drain, and ground to source.
In practice, with the 9V supply this means the positive terminal of the supply will connect through to source,
and the negative terminal connects through to drain.

To bias the gate using a digital pin of the Arduino, we take the source of the JFET as the Arduino "ground".
So the Arduino is able to apply from 0V to 5V the gate with respect to source.
From the characteristic curves in the datasheet, we can see this is enough to effect a distinct on/off transition
* Vgs = 0V, the JFET is fully "on"
* Vgs = 5V, the JFET is fully "off"

### Rs - source resistor
I've shown an Rs of 0Ω. This is just to show that there could be a source-side resistor.
The voltage drop across Rs needs to be accounted for when determining Vg.
Too large, and Vg can approach 0 or even invert with respect to Vs.

### Rg - gate resistor
A 1MΩ resistor connects to the gate. In normal operation, this is redundant as the gate current is virtually zero (~1nA).
i.e., yes the circuit still works fine with it removed.

It does seem to be good protection in case Vgs becomes reverse biased and significant current flow through the gate is possible.

### The Code
... doesn't do anything special - just an amplified Blink! It uses a digital out pin to turn the JFET on and off.

## Construction

![Breadboard](./assets/SwitchPJFET_bb.jpg?raw=true)

NB: in the schematic below, the FET symbol is not quite correct (shows p-channel MOSFET instead of JFET)

![The Schematic](./assets/SwitchPJFET_schematic.jpg?raw=true)

![The Build](./assets/SwitchPJFET_build.jpg?raw=true)

## Credits and References

* [J175 datasheet](https://www.fairchildsemi.com/datasheets/MM/MMBFJ175.pdf)
* [JFET wikipedia](http://en.wikipedia.org/wiki/JFET)
* [P-channel JFET Basics](http://www.learningaboutelectronics.com/Articles/P-channel-JFET)
* [JFET Analysis part 1](https://www.youtube.com/watch?v=ptwJkh_IgVs)
* [JFET Biasing 1](https://www.youtube.com/watch?v=zlW-gm62WBo)
* [JFET Self Bias Tutorial](http://www.electronicstutorialsblog.com/2012/03/22/jfet-junction-field-effect-transistor-self-bias-tutorial/)

