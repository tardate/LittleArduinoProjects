# #094 BJTLongTailPair

Test a BJT "long-tail" differential amplifier circuit.

Here's a quick demo of the circuit in action:

[![BJTLongTailPair](http://img.youtube.com/vi/Uo1UbQSjO6E/0.jpg)](http://www.youtube.com/watch?v=Uo1UbQSjO6E)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Differential amplifiers are excellently described in [w2aew's tutorial on YouTube](https://youtu.be/mejPNuPAHBY).

This is a build and test of the basic long-tail circuit with no frills, which means the circuit is not ideal because:
* it relies on matched transistors
* output voltage varies with input voltage levels
* differential gain varies with input voltage levels
* only has moderate differential gain

The circuit includes an LED pair and resistor load between the outputs. This provides red/green - left/right balance indicator.

What is immediately noted is that gain varies wildly given different input voltages,
from approaching 0 at large voltage differences (clipped by the circuit I believe),
to 10-100 for small variations.

There are two improvements suggested by w2aew that will bring this circuit closer to an OpAmp:
* constant current circuit on the emitter, to eliminate the impact of input voltage on output voltage and gain.
* current mirror on the collectors, to improve gain

I'll try these improvements in another project file.

### Monitoring with an Arduino

The Arduino program is used to monitor the input and output voltages, calculate the differentials and gain.
Readings are made using 1MΩ voltage dividers, to limit impact on the circuit and to scale the voltages to
the 5V range supported by the Arduino analog input pins.

Although not particularly accurate, it gives a rough indication of behaviour. For example:

```
Sample:
                ao1: 2919 mV
                ao2: 2371 mV
                ab1: 1837 mV
                ab2: 1793 mV
 input_differential: -88 mV
output_differential: -1096 mV
               gain: 12.45
```


## Construction

![Breadboard](./assets/BJTLongTailPair_bb.jpg?raw=true)

![The Schematic](./assets/BJTLongTailPair_schematic.jpg?raw=true)

![The Build](./assets/BJTLongTailPair_build.jpg?raw=true)

## Credits and References
* [#193: Back to Basics: the differential amplifier, aka long-tailed pair, diff-pair](https://youtu.be/mejPNuPAHBY) by w2aew
* [w2aew's tutorial notes](http://www.qsl.net/w2aew//youtube/longtailedpair.pdf)
* [S9013 datasheet](http://www.futurlec.com/Transistors/S9013.shtml)


