# #280 FM/BreadboardTransmitter

Build a simple 3-stage FM transmitter on a breadboard from a design by dazaro3.

![Build](./assets/BreadboardTransmitter_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The [dazaro3](https://www.youtube.com/channel/UCU5ca_ymxbKi9GqVH7BMxbg) Youtube channel has some of the simplest and most practical FM transmitter circuits around,
with a bonus that he actually shows them working. He also sells kits and finished products at [www.bug-transmitter.com/](http://www.bug-transmitter.com/).

[A Breadboard FM Transmitter Bug](https://www.youtube.com/watch?v=lUpujUAa2ZQ) even demonstrates how it is possible to build a working transmitter on a breadboard.

This project is simply a reproduction of that circuit to find out how easy it is to get working.

My first attempt was a complete flop - oscillation was very temperamental, and when it did transmit it was running far to high in the 200MHz range. Two problems:

* the first breadboard I used was quite old, and wasn't making good contacts - especially with small ceramic caps with very thin leads
* the coil was not quite right - I think the inductance too low

Switching to a newer breadboard fixed the connection issues. Getting the coil right required a bit of trial and error.


### Getting the Coil Right

I've learned to hate making coils, because no matter how precise the isntructions and how studiously I follow them,
I always seem to end up with results that vary greatly from the original plan.

I recently got hold of a handheld frequency meter, and this made the whole process much less frustrating.

With the first L1 coil I made, the circuit was oscillating but up in the 200MHz range, indicating the inductance was too low.

After a few trials (varying the dimensions, tuns and the wire), I settled on a coil that along with a 33pF C4 produced a stable transmission at 83.35MHz.
This coil is 4-turns of solid-core AWG18, length=8.5mm, diameter=5.5mm.

The [LC resonance calculation](http://www.daycounter.com/Calculators/LC-Resonance-Calculator.phtml) implies the coil has an inducatance of
[110nH](http://www.wolframalpha.com/input/?i=(1%2F(2*%CF%80*83.35MHz))%5E2%2F33pF&rawformassumption=%7B%22C%22,+%22pF%22%7D+-%3E+%7B%22Unit%22%7D).

That's quite a bit different than the 44nH predicted by a simplified [air coil calculator](http://www.qsl.net/in3otd/indcalc.html).
I suspect the variation may be largely due to the fact that I'm using unusually heavy AWG18 solid-core wire.


### Performance

It is surprisingly good! With a 165cm AWG30 antenna connected, I can easily walk from one end of the house to the other and pickup a good signal.

## Construction

![Breadboard](./assets/BreadboardTransmitter_bb.jpg?raw=true)

![Schematic](./assets/BreadboardTransmitter_schematic.jpg?raw=true)

![BreadboardTransmitter_layout](./assets/BreadboardTransmitter_layout.jpg?raw=true)

![Build](./assets/BreadboardTransmitter_build.jpg?raw=true)

## Credits and References
* [LEAP#281 FM/ThreeStageTransmitter](../ThreeStageTransmitter) - the same circuit, built ugly-style in a can
* [A Breadboard FM Transmitter Bug](https://www.youtube.com/watch?v=lUpujUAa2ZQ) - dazaro3
* [dazaro3 channel](https://www.youtube.com/channel/UCU5ca_ymxbKi9GqVH7BMxbg)
* [www.bug-transmitter.com/](http://www.bug-transmitter.com/) - sells kits by dazaro3
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml)
* [air coil calculator](http://www.qsl.net/in3otd/indcalc.html)
* [LC resonance calculator](http://www.daycounter.com/Calculators/LC-Resonance-Calculator.phtml)
