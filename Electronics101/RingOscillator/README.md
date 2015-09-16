# RingOscillator

test an oscillator built with a 74LS14 Inverter chip

## Notes

A [Ring Oscillator](https://en.wikipedia.org/wiki/Ring_oscillator) is constructed
with an odd number of inverters in series, with the output feeding back to the input.

Since an odd number of inverters, the output is logically the complement of the input.
This conflict results in oscillation.

The frequency of oscillation is governed by the inherent propagation delay of the inverter:

    f = 1 / (2 * t * n)
    where:
    2 : since two oscillations make a complete cycle
    t : propagation delay of a single inverter
    n : number of inverters

The propagation delay is not subject to a range of instabilities:
* jitter (noise)
* temparature
* voltage

The frequency of the oscillator may be controlled in a number of ways:
* vary voltage within the limits supported by the inverter
* add more inverters to the ring
* add an RC network to the circuit to further slow the oscillation according the the RC time constant

The demo circuit here is built with 3 inverters in a 74LS14 chip.
An RC network is added to the ouput to test control of the oscillation.
The follow table lists my frequency measurements with various resistor/capacitor values.

| R1  | C1    | Frequency |
|-----|-------|-----------|
| c/c | o/c   | 11768 kHz |
| 1kΩ | o/c   | 1943 kHz  |
| 1kΩ | 100pF | 1366 kHz  |
| 1kΩ | 1nF   | 394 kHz   |
| 1kΩ | 10nF  | 82 kHz    |
| 1kΩ | 100nF | 11.8 kHz  |

## Construction

![Breadboard](./assets/RingOscillator_bb.jpg?raw=true)

![The Schematic](./assets/RingOscillator_schematic.jpg?raw=true)

![The Build](./assets/RingOscillator_build.jpg?raw=true)

## Credits and References
* [Ring Oscillator](https://en.wikipedia.org/wiki/Ring_oscillator) - wikipedia
* [74LS14 Datasheet](http://www.futurlec.com/74LS/74LS14.shtml)

