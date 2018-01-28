# Three Transistor ShortWave Receiver (WIP)

Building a simple 3-transistor regenerative receiver for 3MHz to 30MHz shortwave.

![Build](./assets/ThreeTransistorShortWaveReceiver_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I found [this design](http://www.netzener.net/index.php/8-project-articles/5-3-transistor-short-wave-radio)
for a 3 Transistor Short Wave Radio by netZener. It is a restoration and update of an old
Science Fair #28-110 kit from Radio Shack.

### Regenerative Receivers

A [Regenerative receiver](https://en.wikipedia.org/wiki/Regenerative_circuit)
introduces positive feedback in the RF receiver circuit, resulting in increased gain and selectivity.
It was invented by [Edwin Armstrong](https://en.wikipedia.org/wiki/Edwin_Howard_Armstrong) in 1914.

One of the disadvantages of a regen is its propensity to radiate RF back out the antenna especially when the regen is close to oscillation.
I learned on [Soldersmoke 164](http://soldersmoke.blogspot.sg/2014/08/soldersmoke-podcast-164-ancient-tribal.html)
that this was a particular risk for spies in WWII, as explained in the book [Spycatcher](https://www.goodreads.com/book/show/971569.Spycatcher).

In this circuit, the regen control comprises Q1 and it's biasing components.

Some Other Regen Designs

* [Regenerative Receivers](http://www.techlib.com/electronics/regen.html) - techlib


## Circuit

I've redrawn the original schematic in EasyEDA for my study, [available here](https://easyeda.com/tardate/ThreeTransistorShortWaveReceiver-7408f1d2a3864d6a82b865fee9ba2eaf).

![Schematic](./assets/original-schematic.png?raw=true)

Variations in my build:

* used 2.2kΩ for R12 instead of 2.7kΩ (due to parts on-hand). Works fine, probably increases the AF amp gain.
* used a 2kΩ pot for R2 (due to parts on-hand). Means the regen control is not as sensitive, but it is workable

### Parts

| Qty | Item                        | Ref    |
|-----|-----------------------------|--------|
| 1   | Transistor NPN (2N3904)     | Q1     |
| 2   | Transistor PNP (2N3906)     | Q2,Q3  |
| 2   | 33K Resistor 1/4W 5%        | R1,R5  |
| 1   | 1K Resistor 1/4W 5%         | R3     |
| 1   | 100K Resistor 1/4W 5%       | R4     |
| 1   | 2.2K Resistor 1/4W 5%       | R6     |
| 1   | 2.7K Resistor 1/4W 5%       | R12    |
| 1   | 22K Resistor 1/4W 5%        | R9     |
| 1   | 47K Resistor 1/4W 5%        | R10    |
| 1   | 12K Resistor 1/4W 5%        | R8     |
| 1   | 10K Resistor 1/4W 5%        | R11    |
| 2   | .01uF Disk Ceramic Capacitor| C1,C8  |
| 2   | 47pF Disk Ceramic Capacitor | C2,C3  |
| 1   | 15pF Disk Ceramic Capacitor | C4     |
| 1   | .047uF Multilayer Capacitor | C8     |
| 1   | .1uF Mylar Capacitor        | C9     |
| 1   | 10uF Electrolytic Capacitor | C10    |
| 1   | 47uF Electrolytic Capacitor | C7     |
| 1   | 500 Ohm Potentiometer       | R2     |
| 1   | 100K Ohm Potentiometer      | R7     |
| 1   | 140pF Variable Capacitor    | C5     |
| 1   | Air coil                    | L1     |


### The Build

Semi-modular ugly construction:
* AF amp is mounted on copper PCB stock, ugly style
* detector and tuning is mounted on single-sided protoboard with M3 stand-offs

![Build](./assets/build_1.jpg?raw=true)

![Build](./assets/build_2.jpg?raw=true)

![Build](./assets/build_3.jpg?raw=true)

![Build](./assets/build_4.jpg?raw=true)

### Tuning the Tuning Circuit!

The original documentation provided the following recommendations for the air coil inductor:

| Frequency | Recommended Coil Turns |
|-----------|------------------------|
| 4.5-7 MHz |  46                    |
| 6-10 MHz  |  25                    |
| 9-14 MHz  |  15                    |
| 13-20 MHz |  8                     |
| 19-28 MHz |  5                     |
| 26-50 MHz |  2                     |

#### First Test

First test: semi-successful! All the circuitry is working fine, but my tuning appears to be way up in the FM band.

With a range of 12 turn, 20 turn and 25 turn coils I'm able to tune across the FM band and pick up some pretty clear signals for stations from 92.4 MHz to 97.2 MHz.
Increasing the windings and size of the coil is not moving me significantly lower, so I suspect there's something up with the capacitance.

Next steps:

* check the air variable capacitor
* add more capacitance in parallel



## Credits and References
* [3 Transistor Short Wave Radio](http://www.netzener.net/index.php/8-project-articles/5-3-transistor-short-wave-radio) - original article by netZener
* [Instructables](http://www.instructables.com/id/Three-Transistor-Short-Wave-Radio/) - updated post by netZener
* [Regenerative circuit](https://en.wikipedia.org/wiki/Regenerative_circuit) - wikipedia
* [Regenerative Receiver](https://www.electronics-notes.com/articles/radio/radio-receivers/regenerative-receiver.php) - electronics-notes
* [Air Core Inductor Inductance Calculator](http://www.daycounter.com/Calculators/Air-Core-Inductor-Calculator.phtml)
* [LC Resonance Calculator](http://www.daycounter.com/Calculators/LC-Resonance-Calculator.phtml)
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml)
* [2N3906 datasheet](http://www.futurlec.com/Transistors/2N3906.shtml)
