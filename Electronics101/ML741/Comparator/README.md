# #151 ML741/Comparator

Test a comparator circuit with the ML741 discrete component opamp


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This is a demonstration of a comparator circuit using the [ML741](../) discrete component opamp.
The general operation of a comparator is to swing output from 0 to 1 based on the comparison of the inverting and non-inverting input.

![Op-Amp_Comparator](https://upload.wikimedia.org/wikipedia/commons/0/0d/Op-Amp_Comparator.svg)

| Vout | When          |
|------|---------------|
| 0    | V1(+) < V2(-) |
| 1    | V1(+) > V2(-) |

### How it works

Fundamentally, an op-amp strives to keep it's inverting an non-inverting inputs equal by modulating the output.

In the comparator configuration, when the non-inverting input rises above the inverting input,
the output will rise to offset the differential.
But since there is no feedback loop, that fails miserably and the output fast ends up hard on it's upper rail.

Conversely, when the non-inverting input falls below the inverting input, the output swings low as the op-amp
attempts to balance the input.

## Construction

I first built the ML741 circuit on a breadboard, and the basic comparator test works fine.
Subsequently I've put the circuit on a protoboard/veroboard, and that's what I'm using for later tests.
With the lower and upper rails at 0V and 8.92V respectively and no output load:
* output swings to 1.21V (low) when non-inverting input (IN+) is below inverting input (IN-)
* output swings to 8.52V (high) when non-inverting input (IN+) is above inverting input (IN-)

For this circuit:
* single rail power supply is used for simplicity i.e. VCC- is connected to ground
* the non-inverting input is set to VCC/2 with a 10kΩ/10kΩ voltage divider.
* the inverting input is from the wiper of a 10kΩ pot wired across the power rails

See below for some more test results comparing the ML741 with a standard 741 chip.

![Breadboard](./assets/Comparator_bb.jpg?raw=true)

![The Schematic](./assets/Comparator_schematic.jpg?raw=true)

### Breadboard Build

![The Build](./assets/Comparator_bb_build.jpg?raw=true)

### Protoboard Build

![The Build](./assets/Comparator_build.jpg?raw=true)

## ML741 v "real" 741 Test

Here are some results comparing the behaviour of a standard UA741CN chip with the ML741 (protoboard version).

Setup:
* power is 5V single rail, i.e. V- = GND
* non-inverting input fixed at VCC/2 with a 10kΩ/10kΩ voltage divider
* inverting input is fed a ramp wave 2Vpp with 2V DC offset (with a 1kΩ resistor in series for redundant protection)
* the function generator ramp wave input replaces the manual 10kΩ pot in the schematic above

Scope connections
* CH1: inverting input
* CH2: output
* CH2: non-inverting input

### At 5kHz

* ML741 output voltage swings are closer to the rails than the UA741CN
* ML741 seems to have slightly better response time
* UA741CN distorting the duty cycle

ML741:

![ML741_5kHz](./assets/ML741_5kHz.gif?raw=true)

UA741CN:

![UA741CN_5kHz](./assets/UA741CN_5kHz.gif?raw=true)

### At 20kHz

* both struggling to keep up
* ML741 still delivering positive output swings, although distorted
* UA741CN distorting the duty cycle to the point that time low is negligible

ML741:

![ML741_20kHz](./assets/ML741_20kHz.gif?raw=true)

UA741CN:

![UA741CN_20kHz](./assets/UA741CN_20kHz.gif?raw=true)

Measurements in action...

![probe city](./assets/Comparator_probe_city.jpg?raw=true)

## Credits and References
* [ML741](../) - the ML741 discrete component project
* [LM741 Datasheet](http://www.futurlec.com/Linear/LM741CN.shtml)
* [Comparator](https://en.wikipedia.org/wiki/Comparator) - wikipedia
* [The Op-amp Comparator](http://www.electronics-tutorials.ws/opamp/op-amp-comparator.html) - electronics-tutorials

