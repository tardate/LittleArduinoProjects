# CrystalTester

A Colpitts Oscillator circuit for testing crystal oscillators with a frequency counter.

## Notes

[G3PTO's Xtal Tester](http://www.qsl.net/g3pto/xtest.html) is a simple circuit for
measuring an (unknown) crystal's fundamental resonant frequency with a frequency counter.
It's a very basic test, but good enough to verify the crystal is working and finding it's frequency.

Of course, the reverse is also true: the circuit provides a nice reference signal for testing a frequency counter!

The circuit is a variant of a [Colpitts Oscillator](https://en.wikipedia.org/wiki/Colpitts_oscillator),
and is similar to [the one built by w2aew](https://youtu.be/blalAktxFoI) - except with component values varied for a different supply voltage.

## Construction

![Breadboard](./assets/CrystalTester_bb.jpg?raw=true)

![The Schematic](./assets/CrystalTester_schematic.jpg?raw=true)

![The Build](./assets/CrystalTester_build.jpg?raw=true)

## Credits and References
* [Colpitts Oscillator](https://en.wikipedia.org/wiki/Colpitts_oscillator)
* [G3PTO Xtal Tester](http://www.qsl.net/g3pto/xtest.html) - the original circuit reproduced here
* [Oscillator Crystal Test Circuit](https://youtu.be/EiBTzh7DQ0I) - Tony T's demo of the circuit
* [Victor VC3165 0.01Hz-2.4GHz Frequency Counter](http://www.amazon.com/gp/product/B00CW8Q2Z0/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00CW8Q2Z0&linkCode=as2&tag=itsaprli-20&linkId=3GSZ3KBONNZVLXTF)
* [#123: Build a crystal oscillator from schematic thru prototype construction and testing - DIY](https://youtu.be/blalAktxFoI) - great tutorial by w2aew of building a similar circuit using the island cutter technique
