# ML741/Comparator

Test a comparator circuit with the ML741 discrete component opamp

## Notes

This is a demonstration of a comparator circuit using the [ML741](../) discrete component opamp.
The general definition of a comparator is to swing output from 0 to 1 based on the comparison of the inverting and non-inverting input:

    Vo = 0, V+ < V-
    Vo = 1, V+ > V-

So far, I've built the ML741 circuit on a breadboard, and the basic comparator test works fine.
With the lower and upper rails at 0V and 8.92V respectively and no output load:
* output swings to 1.21V (low) when non-inverting input (IN+) is below inverting input (IN-)
* output swings to 8.52V (high) when non-inverting input (IN+) is above inverting input (IN-)

For this circuit:
* single rail power supply is used for simplicity i.e. VCC- is connected to ground
* the non-inverting input is set to VCC/2 with a 10kΩ/10kΩ voltage divider.
* the inverting input is from the wiper of a 10kΩ pot wired across the power rails

## Construction

![Breadboard](./assets/Comparator_bb.jpg?raw=true)

![The Schematic](./assets/Comparator_schematic.jpg?raw=true)

![The Build](./assets/Comparator_build.jpg?raw=true)

## Credits and References
* [ML741](../) - the ML741 discrete component project
* [Comparator](https://en.wikipedia.org/wiki/Comparator) - wikipedia
* [The Op-amp Comparator](http://www.electronics-tutorials.ws/opamp/op-amp-comparator.html) - electronics-tutorials

