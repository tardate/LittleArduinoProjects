# #273 VoltageControlledOscillator

Exploring varicap diodes (KV1471) and their use in frequency tuning of a Colpitts-style voltage-controlled oscillator.

![Build](./assets/VoltageControlledOscillator_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This project is a study inspired by yet another great [video tutorial from w2aew](https://youtu.be/icw8terKP-M).

It demonstrates how varicap diodes can be used to create a voltage-controlled oscillator.

[![Varicap_symbol](https://upload.wikimedia.org/wikipedia/commons/0/0e/Varicap_symbol.svg)](https://en.wikipedia.org/wiki/Varicap)

A varicap diode is type of diode designed to exploit the voltage-dependent capacitance of a reversed-biased p–n junction.
This is a feature of all diodes, but is more pronounced in those produced specifically for this purpose.
In my version of the circuit I am using the KV1471 diode.

The demonstration circuit is based on a design presented in Chapter 4.6 of
[Experimental Methods in RF Design](https://www.goodreads.com/book/show/2386153.Experimental_Methods_in_RF_Design).

The basic circuit is a Colpitts oscillator. The varicap diode:

* alters the capacitance of the oscillator and thus the frequency
* has a capacitance inversely-proportional to the applied voltage
* is capacitor-coupled to the oscillator tank so that the varicap voltage does not play a role in the oscillator
* has a back-to-back varicap twin to compensate for rectification effects

Voltage tuning with diodes in circuits such as this can compromise noise and stability,
so it is generally recommended to limit the frequency range (capacitance).
It is of course possible to adjust the components so that the varicap produces a much wider frequency swing.

I have the circuit operating on 5V, and by default the varicap voltage is varied from 0-5V with a trim pot.
On my protoboard build, I made that jumper-configurable, so an external control voltage can be applied (I tested up to 12V).

In practice (both on a breadboard for initial tests, and then finally on protoboard)
I was unable to achieve the 14MHz oscillation originally intended for this circuit.
However by replacing the 1µH inductor with 10µH, I was able to get a nice stable oscillator at 5.46MHz (with no varicap voltage applied),
and a varicap tuning range of a quite sizable 0.35MHz.

I suspect to get 14MHz I need a construction with a better ground plane and perhaps shielding (w2aew used Manhattan-style on a solid copper PCB for 14MHz). I will probably come back to try this at some point.

### Performance

The following scope traces are for the protoboard build.

5.46MHz, with varicap voltage VCONTROL=disconnected (floating):

![scope_no_vcontrol](./assets/scope_no_vcontrol.gif?raw=true)

5.45MHz, with varicap voltage VCONTROL=0V:

![scope_5v_min](./assets/scope_5v_min.gif?raw=true)

5.80MHz, with varicap voltage VCONTROL=5V:

![scope_5v_max](./assets/scope_5v_max.gif?raw=true)

5.82MHz, with varicap voltage VCONTROL=12V:

![scope_12v](./assets/scope_12v.gif?raw=true)

### Summary of Circuit Variations

These are the critical difference in my  circuit tests here from the one used by w2aew and as presented in Experimental Methods in RF Design:

| Item            | Original          | As USed Here  |
|-----------------|-------------------|---------------|
| D1, D2 Varicap  | BB104/MV104       | KV1471        |
| L1 Inductor     | 1µH wound toroid  | 10µH RF choke |

The other main difference (which I'm sure limits the frequency I could achieve) is construction:

* In Experimental Methods in RF Design, they describe a circuit mounted in a 1590A (metal I presume) enclosure with coaxial output
* w2aew used Manhattan-style construction on a solid copper PCB ground plane

I have just used:
* breadboard for initial tests
* protoboard for final tests, but it lacks a decent groub plane and was not enclosed or shielded.

## Construction

![Breadboard](./assets/VoltageControlledOscillator_bb.jpg?raw=true)

![Schematic](./assets/VoltageControlledOscillator_schematic.jpg?raw=true)

I used the breadboard to first make sure I could get a good oscillation.
Shown here without the varicaps installed:

![VoltageControlledOscillator_breadboard](./assets/VoltageControlledOscillator_breadboard.jpg?raw=true)

The protoboard layout is shown here. Since I have KV1471 diodes in surface-mount packages, I had first mounted them on a
fragment of protoboard and made it breadboard pluggable. In the protoboard version, I'd just soldered it directly in.

The pin header provides convenient access to (from left to right):

* ground
* ground
* vcontrol (for external vcontrol power supply)
* VCC/5V (so it can be jumpered to vcontrol)
* output

![VoltageControlledOscillator_protoboard_layout](./assets/VoltageControlledOscillator_protoboard_layout.jpg?raw=true)

## Credits and References
* [#147: Basics of Varactor Diodes | Voltage Controlled Oscillator VCO Example](https://youtu.be/icw8terKP-M) - from w2aew
* [w2aew's notes](http://www.qsl.net/w/w2aew//youtube/Varactor_diodes_with_VCO_example.pdf)
* [Varicap](https://en.wikipedia.org/wiki/Varicap) - wikipedia
* [Varicap, Varactor Diode circuit demo](https://www.youtube.com/watch?v=68qOrDl55tc) - AllAmericanFiveRadio
* [Experimental Methods in RF Design](https://www.goodreads.com/book/show/2386153.Experimental_Methods_in_RF_Design)
* [KV1471 datasheet](http://www.sumzi.com/upload/files/2007/06/2007062317524107881.PDF)
* [J310 datasheet](http://www.futurlec.com/Transistors/J310.shtml)
