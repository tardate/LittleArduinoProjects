# #375 Three Transistor Shortwave Receiver

Building a simple 3-transistor regenerative receiver for HF shortwave.

![Build](./assets/ThreeTransistorShortWaveReceiver_build.jpg?raw=true)

## Notes

I found [this design](https://web.archive.org/web/20180114085548/http://www.netzener.net/index.php/8-project-articles/5-3-transistor-short-wave-radio)
for a 3 Transistor Short Wave Radio by netZener. It is a restoration and update of an old
Science Fair #28-110 kit from Radio Shack.

### Regenerative Receivers

A [Regenerative receiver](https://en.wikipedia.org/wiki/Regenerative_circuit)
introduces positive feedback in the RF receiver circuit, resulting in increased gain and selectivity.
It was invented by [Edwin Armstrong](https://en.wikipedia.org/wiki/Edwin_Howard_Armstrong) in 1914.

One of the disadvantages of a regen is its propensity to radiate RF back out the antenna especially when the regen is close to oscillation.
I learned on [Soldersmoke 164](http://soldersmoke.blogspot.sg/2014/08/soldersmoke-podcast-164-ancient-tribal.html)
that this was a particular risk for spies in WWII, as explained in the book [Spycatcher](https://amzn.to/4292G3D).

In this circuit, the regen control comprises Q1 and it's biasing components.

Some Other Regen Designs

* [Regenerative Receivers](http://www.techlib.com/electronics/regen.html) - techlib
* [A Short Wave Regenerative Receiver Project](http://www.tuberadio.com/receivers.html) - tuberadio
* [A Simple Regen Radio for Beginners](http://www.arrl.org/files/file/Technology/tis/info/pdf/0009061.pdf) - QST September 2000, pp 61-64

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

That's almost finished. A couple of final changes:

* I finished soldering (I hadn't yet soldered the audio out connection when I took the pictures above)
* I moved the coupling capacitor C8: in the pictures above, it is connected directly to R5, C6. But I subsequently took the short-cut: directly from L1/C5 to the R7 wiper.

### Tuning the Tuning Circuit

The original documentation provided the following recommendations for the air coil inductor:

| Frequency | Recommended Coil Turns |
|-----------|------------------------|
| 4.5-7 MHz |  46                    |
| 6-10 MHz  |  25                    |
| 9-14 MHz  |  15                    |
| 13-20 MHz |  8                     |
| 19-28 MHz |  5                     |
| 26-50 MHz |  2                     |

#### First Test, ~16m

Great results for some stations around 16m with a 12 turn coil, approx 15mm diameter and 43mm long.
The wire is 0.9mm diameter insulated copper.
The tuning range is from 12350 kHz (25m) to 22830 kHz (15m).

Here is the rig as tested:

![HF_16m](./assets/HF_16m.jpg?raw=true)

Amongst others, two very strong signals for:

* [All India Radio](http://shortwaveschedule.com/index.php?station=85) transmitting on 17895 kHz 10:00-11:00 UTC with 500 KW from
[Bengaluru](https://www.google.com.sg/maps/place/All+India+Radio/@12.954889,77.4908559,11z/data=!4m8!1m2!2m1!1sAll+India+Radio+Bengaluru!3m4!1s0x3bae166f26d2866f:0xb1a17e4e4b88454b!8m2!3d12.9827125!4d77.5928575?hl=en)
* [Radio Free Asia](http://shortwaveschedule.com/index.php?station=268) transmitting on 17685 kHz with 250 KW from
[Tinian Island](https://www.google.com.sg/maps/place/Tinian/@14.9924224,145.5673148,11.66z/data=!4m5!3m4!1s0x66df525597fe6bcf:0x79e4d5d171efc87f!8m2!3d15.0043455!4d145.6356577?hl=en)

Here's a quick recording of me tuning in on Radio Free Asia, 17685 kHz. I'm using a Tecsun PL-660 to cross-check and verify:

[![17685](https://img.youtube.com/vi/o7-lSoD7qCw/0.jpg)](https://www.youtube.com/watch?v=o7-lSoD7qCw)

And here's a quick demo of tuning in on All India Radio, 17895 kHz:

[![17895](https://img.youtube.com/vi/Qt0ikHhbLLI/0.jpg)](https://www.youtube.com/watch?v=Qt0ikHhbLLI)

#### Tuning Below 12 MHz

I've wound a couple of coils for a longer wavelength - aiming to pick up a very strong BBC World Service signal on 9740 kHz.

NB: in all cases, I've been using 0.9mm diameter copper wire (some with/without insulation). Generally a 15mm coil diameter but varying number of turns and length.

By tuning in to the radiated signal on the Tecsun PL-660, I can verify a tuning range of around 7 MHz to 12MHz.
However I can't seem to tame the regen: I can get a very faint signal on 9740 kHz, but it is overwhelmed by oscillation or noise (depending on the regen control).

.. time for some more study to learn how I might get this under control!

## Credits and References

* [3 Transistor Short Wave Radio](https://web.archive.org/web/20180114085548/http://www.netzener.net/index.php/8-project-articles/5-3-transistor-short-wave-radio) article by netZener on the web archive
    * [original article](http://www.netzener.net/index.php/8-project-articles/5-3-transistor-short-wave-radio) is no longer online
    * related [Instructables post](https://www.instructables.com/id/Three-Transistor-Short-Wave-Radio/) by netZener is no longer online
* [Regenerative circuit](https://en.wikipedia.org/wiki/Regenerative_circuit) - wikipedia
* [Regenerative Receiver](https://www.electronics-notes.com/articles/radio/radio-receivers/regenerative-receiver.php) - electronics-notes
* [Air Core Inductor Inductance Calculator](http://www.daycounter.com/Calculators/Air-Core-Inductor-Calculator.phtml)
* [LC Resonance Calculator](http://www.daycounter.com/Calculators/LC-Resonance-Calculator.phtml)
* [Tuning A Regenerative Receiver](http://www.arrl.org/tuning-a-regenerative-receiver) - ARRL
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [2N3906 datasheet](https://www.futurlec.com/Transistors/2N3906.shtml)
