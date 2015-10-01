# 555Timer/VoltageDoublerChargePump

Test a voltage-doubling charge pump circuit based on a 555 timer.

## Notes

See the [555Timer/InvertingChargePump](../InvertingChargePump) project for similar circuit (but with inverted output)
that explores the inners of charge pumps in more detail.

This configuration can theoretically deliver an output voltage that is double the output voltage.

The 555 oscillator is configured with a reasonable larger R1 in order to minimise power loss in the 555 - in this configuration it draws only 5mA with no load.
This means the frequency is a little lower that desirable at
[13.9kHz](http://visual555.tardate.com/?mode=astable&r1=10&r2=47&c=0.001).

Flyback and output capacitors could be larger, but only only have on hand 1µF rated for over 16V.

I'm using 1N5819 diodes for their low forward voltage, but as shown in the InvertingChargePump circuit, other rectifiers such as 1N4001 are possible but at the expense of voltage gain.

Here are some measurements:

| D1/D2  |  R1  |    R2 |    C1 |    CF | CL    | RL    | Vin  | Iin    | Vout   | Iload  | Pin     | Pout    | Efficiency |
|--------|------|-------|-------|-------|-------|-------|------|--------|--------|--------|---------|---------|------------|
| 1N5819 | 10kΩ |  47kΩ |   1nF |   1µF |   1µF | 1kΩ   | 8.52 | 32.3mA | -13.68 | 13.8mA | 275.2mW | 188.8mW | 68.6%      |
| 1N5819 | 10kΩ |  47kΩ |   1nF |   1µF |   1µF | 10kΩ  | 9.25 |  8.5mA | -16.79 |  1.7mA |  78.6mW |  28.5mW | 36.3%      |
| 1N5819 | 10kΩ |  47kΩ |   1nF |   1µF |   1µF | 100kΩ | 9.27 | 5.46mA | -18.18 |  182µA |  50.6mW |   3.3mW |  6.5%      |


### Some Conclusions

Pretty much the same as for the InvertingChargePump circuit:

Diode selection:
* 1N5819 is ideal, maximising the voltage gain
* but 1N4001 still works, with some loss, and there's not much benefit in using 1N4148 instead

Frequency:
* higher frequencies are more robust under varying loads (lower voltage drop at lower output impedences)

Capacitor values:
* for this circuit and range of loads, CF and CL should be at least 1µF
* higher values get the circuit closer to unity gain
* note the need to ensure the capacitors are rated for the voltage generated

Output Impedence:
* this circuit struggles to maintain voltage for low impedences (under 10kΩ)
* understandable, since they want to rapidly deplete the output capacitor
* for low impedence loads, the circuit would need to change so that a heavy charging current could be delivered via a BJT or FET

Oscillator:
* the 555 chip is an expensive way to drive a low-power charge pump, being responsible for the bulk of conversion losses

## Construction

![Breadboard](./assets/VoltageDoublerChargePump_bb.jpg?raw=true)

![The Schematic](./assets/VoltageDoublerChargePump_schematic.jpg?raw=true)

![The Build](./assets/VoltageDoublerChargePump_build.jpg?raw=true)

## Credits and References
* [555Timer/InvertingChargePump](../InvertingChargePump) - related project
* [Charge Pump](https://en.wikipedia.org/wiki/Charge_pump) - wikipedia
* [555 DC boost converter circuits](http://www.eleccircuit.com/the-many-dc-to-dc-converters-using-ic-555/) - original source of circuit design
* [NE555 Datasheet](http://www.ti.com/lit/ds/symlink/ne555.pdf)
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [1N4001 Datasheet](http://www.futurlec.com/Diodes/1N4001.shtml)
* [1N4148 Datasheet](http://www.futurlec.com/Diodes/1N4148.shtml)
* [1N5819 Datasheet](http://www.futurlec.com/Diodes/1N5819.shtml)
* [SMPS Tutorial (3): Charge Pumps, Buck Converters, Switched Mode Power Supplies](https://youtu.be/r_AAdxwfim8) - great overview from The Post Apocalyptic Inventor
* [Calculating Essential Charge-Pump Parameters](http://powerelectronics.com/passive-components/calculating-essential-charge-pump-parameters) - detailed article on the workings of charge pumps
* [Charge Pumps: An Overview by Louie Pylarinos](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.128.4085)

