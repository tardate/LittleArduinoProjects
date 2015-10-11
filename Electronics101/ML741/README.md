# ML741

An LM741-style OpAmp built with discrete components

## Notes

This ia a "Medium-Large" version of the venerable 741, inspired by the
[XL741 kit](http://wiki.evilmadscientist.com/XL741) from the Evil Mad Scientist.
Just not so big - Lego size instead of Duplo!

The intention is to get inside a real op-amp circuit and see how it works.

So far, I've built the circuit on a breadboard, and run a basic comparator test. That all works fine.
With the lower and upper rails at 0V and 8.92V respectively and no output load:
* output swings to 1.21V (low) when non-inverting input (IN+) is below inverting input (IN-)
* output swings to 8.52V (high) when non-inverting input (IN+) is above inverting input (IN-)

I'm starting some related projects to test the ML741 in various opamp topologies:
* [Comparator](./Comparator)

## Construction

![Breadboard](./assets/ML741_bb.jpg?raw=true)

![The Schematic](./assets/ML741_schematic.jpg?raw=true)

![The Build](./assets/ML741_build.jpg?raw=true)

## Credits and References
* [XL741 Discrete 741 Op-Amp kit](http://wiki.evilmadscientist.com/XL741) by the Evil Mad Scientist
* [LM741 Datasheet](http://www.futurlec.com/Linear/LM741CN.shtml)


