# #146 555Timer/InvertingChargePump

Test an inverting charge pump circuit based on a 555 timer.


## Notes

The classic charge pump circuit uses a switching mechanism to alternately:
* charge a "flying capacitor" from the power source
* discharge the capacitor to an output capacitor, from which the load draws its power

Depending on configuration, charge pumps are capable of output voltages up to and above the input voltage,
as well as negative output voltages.

Charge pumps can be highly efficient compared to linear regulators, but in practice are unable to support high loads without large and expensive capacitors.
Output voltage is also highly dependent on the load, hence real life circuits usually involve an automatic feedback control system to keep the output voltage relatively regulated.

For this experiment I'm testing an unregulated charge pump that can theoretically deliver an output voltage with a gain of -1 i.e. inverse the input voltage.

To keep things simple, I'm using a 555 timer to govern the charging cycle.
R1 is set low with respect to R2, to ensure a near-50% duty cycle.
A variable resistance component of R2 allows adjustment of frequency over a wide range without greatly affecting duty cycle:
* from [0.7kHz / 50% duty cycle](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=101&c=0.01)
* to [64.9kHz / 55% duty cycle](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=1&c=0.01)

Note that the charge pump is primed directly from the 555 timer output pin 3.
555 chips are generally rated for a maximum of +/-200mA on its output pin, so this arrangement is necessarily only suitable for low-power loads.

### Some Measurements
I've seen this circuit repeated over the internet, with a wide range of component values.
And usually no explanation is to why particular values are used.
So first a (tedious!) series of tests..

Input voltage under load is ~ 8.62V

Frequencies, as measured with frequency counter:
* Fmin = 0.795kHz (actual), cf 0.7kHz (expected)
* Fmax = 73.434kHz (actual), cf 64.9kHz (expected)

OK, next here's the table of output voltage measurements with variations in the circuit:
* high and low charge frequencies
* a range of output impedences, to see how stable the voltage is to load
* flying and output capacitor values
* different diodes: 1N4001 as a representative standard rectifier; 1N4148 for its high speed; 1N5819 for its low forward voltage

| D1/D2  |    CF | CL    | RL    | Vout (Fmin) | Vout (Fmax) |
|--------|-------|-------|-------|--------|---------|
| 1N4001 |   1µF |   1µF | 1kΩ   |  -3.07 |   -4.03 |
| 1N4001 |   1µF |   1µF | 10kΩ  |  -6.71 |   -6.35 |
| 1N4001 |   1µF |   1µF | 100kΩ |  -7.87 |   -7.64 |
| 1N4001 |   1µF |  10µF | 1kΩ   |  -3.29 |   -4.30 |
| 1N4001 |   1µF |  10µF | 10kΩ  |  -6.79 |   -6.38 |
| 1N4001 |   1µF |  10µF | 100kΩ |  -7.92 |   -7.62 |
| 1N4001 |   1µF |  47µF | 1kΩ   |  -3.28 |   -4.30 |
| 1N4001 |   1µF |  47µF | 10kΩ  |  -6.76 |   -6.33 |
| 1N4001 |   1µF |  47µF | 100kΩ |  -7.91 |   -7.65 |
| 1N4001 |   1µF | 100µF | 1kΩ   |  -3.31 |   -4.46 |
| 1N4001 |   1µF | 100µF | 10kΩ  |  -7.02 |   -6.71 |
| 1N4001 |   1µF | 100µF | 100kΩ |  -8.02 |   -7.75 |
| 1N4001 |  10µF |  10µF | 1kΩ   |  -5.29 |   -4.42 |
| 1N4001 |  10µF |  10µF | 10kΩ  |  -7.25 |   -6.51 |
| 1N4001 |  10µF |  10µF | 100kΩ |  -7.97 |   -7.63 |
| 1N4001 |  10µF | 100µF | 1kΩ   |  -5.61 |   -4.64 |
| 1N4001 |  10µF | 100µF | 10kΩ  |  -7.41 |   -6.80 |
| 1N4001 |  10µF | 100µF | 100kΩ |  -8.07 |   -7.80 |
| 1N4001 |  47µF |  47µF | 1kΩ   |  -5.61 |   -4.55 |
| 1N4001 |  47µF |  47µF | 10kΩ  |  -7.21 |   -6.46 |
| 1N4001 |  47µF |  47µF | 100kΩ |  -7.94 |   -7.64 |
| 1N4001 |  47µF | 100µF | 1kΩ   |  -5.70 |   -4.70 |
| 1N4001 |  47µF | 100µF | 10kΩ  |  -7.26 |   -6.63 |
| 1N4001 |  47µF | 100µF | 100kΩ |  -7.98 |   -7.93 |
| 1N4001 | 100µF | 100µF | 1kΩ   |  -5.87 |   -4.66 |
| 1N4001 | 100µF | 100µF | 10kΩ  |  -7.25 |   -6.74 |
| 1N4001 | 100µF | 100µF | 100kΩ |  -8.01 |   -7.81 |
| 1N4148 |   1µF |   1µF | 1kΩ   |  -3.23 |   -5.49 |
| 1N4148 |   1µF |   1µF | 10kΩ  |  -6.76 |   -7.13 |
| 1N4148 |   1µF |   1µF | 100kΩ |  -8.04 |   -7.91 |
| 1N4148 |   1µF |  10µF | 1kΩ   |  -3.28 |   -5.47 |
| 1N4148 |   1µF |  10µF | 10kΩ  |  -6.82 |   -7.08 |
| 1N4148 |   1µF |  10µF | 100kΩ |  -7.97 |   -9.98 |
| 1N4148 |   1µF |  47µF | 1kΩ   |  -3.24 |   -5.48 |
| 1N4148 |   1µF |  47µF | 10kΩ  |  -6.75 |   -7.06 |
| 1N4148 |   1µF |  47µF | 100kΩ |  -8.01 |   -7.90 |
| 1N4148 |   1µF | 100µF | 1kΩ   |  -3.26 |   -5.44 |
| 1N4148 |   1µF | 100µF | 10kΩ  |  -6.81 |   -7.15 |
| 1N4148 |   1µF | 100µF | 100kΩ |  -7.95 |   -7.82 |
| 1N4148 |  10µF |  10µF | 1kΩ   |  -5.22 |   -5.40 |
| 1N4148 |  10µF |  10µF | 10kΩ  |  -7.17 |   -7.10 |
| 1N4148 |  10µF |  10µF | 100kΩ |  -7.97 |   -7.77 |
| 1N4148 |  10µF | 100µF | 1kΩ   |  -5.35 |   -5.69 |
| 1N4148 |  10µF | 100µF | 10kΩ  |  -7.26 |   -7.15 |
| 1N4148 |  10µF | 100µF | 100kΩ |  -8.02 |   -7.87 |
| 1N4148 |  47µF |  47µF | 1kΩ   |  -5.50 |   -5.56 |
| 1N4148 |  47µF |  47µF | 10kΩ  |  -7.17 |   -7.12 |
| 1N4148 |  47µF |  47µF | 100kΩ |  -7.93 |   -7.77 |
| 1N4148 |  47µF | 100µF | 1kΩ   |  -5.46 |   -5.53 |
| 1N4148 |  47µF | 100µF | 10kΩ  |  -7.10 |   -7.08 |
| 1N4148 |  47µF | 100µF | 100kΩ |  -7.88 |   -7.67 |
| 1N4148 | 100µF | 100µF | 1kΩ   |  -5.53 |   -5.43 |
| 1N4148 | 100µF | 100µF | 10kΩ  |  -7.26 |   -7.10 |
| 1N4148 | 100µF | 100µF | 100kΩ |  -7.92 |   -7.73 |
| 1N5819 |   1µF |   1µF | 1kΩ   |  -3.64 |   -6.33 |
| 1N5819 |   1µF |   1µF | 10kΩ  |  -7.60 |   -8.03 |
| 1N5819 |   1µF |   1µF | 100kΩ |  -8.60 |   -8.76 |
| 1N5819 |   1µF |  10µF | 1kΩ   |  -3.76 |   -6.60 |
| 1N5819 |   1µF |  10µF | 10kΩ  |  -7.57 |   -8.01 |
| 1N5819 |   1µF |  10µF | 100kΩ |  -8.72 |   -8.77 |
| 1N5819 |   1µF |  47µF | 1kΩ   |  -3.74 |   -6.37 |
| 1N5819 |   1µF |  47µF | 10kΩ  |  -7.53 |   -7.99 |
| 1N5819 |   1µF |  47µF | 100kΩ |  -8.70 |   -8.56 |
| 1N5819 |   1µF | 100µF | 1kΩ   |  -3.75 |   -6.45 |
| 1N5819 |   1µF | 100µF | 10kΩ  |  -7.68 |   -8.10 |
| 1N5819 |   1µF | 100µF | 100kΩ |  -8.77 |   -8.81 |
| 1N5819 |  10µF |  10µF | 1kΩ   |  -6.23 |   -6.70 |
| 1N5819 |  10µF |  10µF | 10kΩ  |  -8.20 |   -8.15 |
| 1N5819 |  10µF |  10µF | 100kΩ |  -8.84 |   -8.89 |
| 1N5819 |  10µF | 100µF | 1kΩ   |  -6.22 |   -6.56 |
| 1N5819 |  10µF | 100µF | 10kΩ  |  -8.14 |   -8.11 |
| 1N5819 |  10µF | 100µF | 100kΩ |  -8.82 |   -8.76 |
| 1N5819 |  47µF |  47µF | 1kΩ   |  -6.45 |   -6.52 |
| 1N5819 |  47µF |  47µF | 10kΩ  |  -8.26 |   -8.17 |
| 1N5819 |  47µF |  47µF | 100kΩ |  -8.76 |   -8.65 |
| 1N5819 |  47µF | 100µF | 1kΩ   |  -6.38 |   -6.51 |
| 1N5819 |  47µF | 100µF | 10kΩ  |  -8.16 |   -8.06 |
| 1N5819 |  47µF | 100µF | 100kΩ |  -8.74 |   -8.62 |
| 1N5819 | 100µF | 100µF | 1kΩ   |  -6.63 |   -6.81 |
| 1N5819 | 100µF | 100µF | 10kΩ  |  -8.14 |   -8.05 |
| 1N5819 | 100µF | 100µF | 100kΩ |  -8.76 |   -8.65 |


#### The "Sweet Spot" Configuration

For this circuit and range of loads, higher frequencies are more robust, and CF/CL seem best when over 10µF.
With the variable resistor replaced with fixed 555 astable configuration of
[64.9kHz with 220Ω/1kΩ/10nF](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=1&c=0.01),
here are some measurements with larger capacitor values:

| D1/D2  |  R1  |    R2 |    C1 |    CF | CL    | RL    | Vin  | Iin    | Vout  | Iload  | Pin     | Pout   | Efficiency |
|--------|------|-------|-------|-------|-------|-------|------|--------|-------|--------|---------|--------|------------|
| 1N5819 | 220Ω |   1kΩ |  10nF |  10µF |  10µF | 1kΩ   |      |        | -6.39 |        |         |        |            |
| 1N5819 | 220Ω |   1kΩ |  10nF |  10µF |  10µF | 10kΩ  |      |        | -8.01 |        |         |        |            |
| 1N5819 | 220Ω |   1kΩ |  10nF |  10µF |  10µF | 100kΩ |      |        | -8.58 |        |         |        |            |
| 1N5819 | 220Ω |   1kΩ |  10nF | 100µF | 100µF | 1kΩ   |      |        | -6.77 |        |         |        |            |
| 1N5819 | 220Ω |   1kΩ |  10nF | 100µF | 100µF | 10kΩ  |      |        | -8.12 |        |         |        |            |
| 1N5819 | 220Ω |   1kΩ |  10nF | 100µF | 100µF | 100kΩ |      |        | -8.96 |        |         |        |            |
| 1N5819 | 220Ω |   1kΩ |  10nF | 220µF | 220µF | 1kΩ   | 8.57 | 32.1mA | -6.80 | 6.89mA | 275.1mW | 46.9mW | 17.0%      |
| 1N5819 | 220Ω |   1kΩ |  10nF | 220µF | 220µF | 10kΩ  | 8.52 | 26.7mA | -8.14 | 814µA  | 227.5mW |  6.6mW |  2.9%      |
| 1N5819 | 220Ω |   1kΩ |  10nF | 220µF | 220µF | 100kΩ | 8.47 | 25.4mA | -9.32 | 86µA   | 215.1mW |  0.8mW |  0.4%      |

That conversion efficiency looks terrible!

Fortunately(?) it turns out that this is mainly due to the 555 timer chip.

My NE555P chips are drawing 25mA with no load on pin 3.
That's much higher than the datasheet would lead me to expect.

Subtract the "cost" of running the 555 chip, and efficiencies work out closer to 77%.
That's better but still not particularly good.

#### Improved Efficiency

So why is the 555 drawing so much power?
It seems to be due to the very low R1 value (220Ω), as hinted at
[on this site](http://www.555-timer-circuits.com/common-mistakes.html).

Examining the internal schematic of the 555 in the datasheet, pin 7 is simply connected via collector-emitter of an NPN transistor to ground,
so it is clear why there's a high load during discharge (VCC > 220Ω > C-E > GND).

Moderating the 555 configuration with a larger R1 and sacrificing a little speed down to
[13.9kHz](http://visual555.tardate.com/?mode=astable&r1=10&r2=47&c=0.001), the 555 timer draws only 5mA with no load.
A check with a frequency counter confirms the circuit is running at 13.38kHz.

Here are some new measurements:

| D1/D2  |  R1  |    R2 |    C1 |    CF | CL    | RL    | Vin  | Iin    | Vout  | Iload  | Pin     | Pout   | Efficiency |
|--------|------|-------|-------|-------|-------|-------|------|--------|-------|--------|---------|--------|------------|
| 1N5819 | 10kΩ |  47kΩ |   1nF | 220µF | 220µF | 1kΩ   | 9.17 | 11.7mA | -6.86 | 7.08mA | 107.3mW | 48.6mW | 45.3%      |
| 1N5819 | 10kΩ |  47kΩ |   1nF | 220µF | 220µF | 10kΩ  | 9.28 |  5.9mA | -7.96 |  803µA |  54.8mW |  6.4mW | 11.7%      |
| 1N5819 | 10kΩ |  47kΩ |   1nF | 220µF | 220µF | 100kΩ | 9.32 |  5.3mA | -8.57 |   85µA |  49.4mW |  0.7mW |  1.5%      |

OK, still not great, but the circuit is still doing a decent job of an inverting charge pump,
and the power lost through the 555 has been greatly reduced.

### Some Conclusions

Diode selection:
* 1N5819 is ideal, maximising the voltage gain
* but 1N4001 still works, with some loss, and there's not much benefit in using 1N4148 instead

Frequency:
* higher frequencies are more robust under varying loads (lower voltage drop at lower output impedences)

Capacitor values:
* for this circuit and range of loads, CF and CL should be at least 10µF
* while 10µF is workable, higher values get the circuit closer to unity gain

Output Impedence:
* this circuit struggles to maintain voltage for low impedences (under 10kΩ)
* understandable, since they want to rapidly deplete the output capacitor
* for low impedence loads, the circuit would need to change so that a heavy charging current could be delivered via a BJT or FET

Oscillator:
* the 555 chip is an expensive way to drive a low-power charge pump, being responsible for the bulk of conversion losses

## Construction

![Breadboard](./assets/InvertingChargePump_bb.jpg?raw=true)

![The Schematic](./assets/InvertingChargePump_schematic.jpg?raw=true)

![The Build](./assets/InvertingChargePump_build.jpg?raw=true)

## Credits and References
* [Charge Pump](https://en.wikipedia.org/wiki/Charge_pump) - wikipedia
* [555 DC boost converter circuits](http://www.eleccircuit.com/the-many-dc-to-dc-converters-using-ic-555/) - original source of circuit design
* [NE555 Datasheet](http://www.ti.com/lit/ds/symlink/ne555.pdf)
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [1N4001 Datasheet](https://www.futurlec.com/Diodes/1N4001.shtml)
* [1N4148 Datasheet](https://www.futurlec.com/Diodes/1N4148.shtml)
* [1N5819 Datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
* [SMPS Tutorial (3): Charge Pumps, Buck Converters, Switched Mode Power Supplies](https://youtu.be/r_AAdxwfim8) - great overview from The Post Apocalyptic Inventor
* [Calculating Essential Charge-Pump Parameters](http://powerelectronics.com/passive-components/calculating-essential-charge-pump-parameters) - detailed article on the workings of charge pumps
* [Charge Pumps: An Overview by Louie Pylarinos](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.128.4085)
