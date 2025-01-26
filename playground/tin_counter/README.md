# #380 Counter

A project by [novaprimexex](https://github.com/novaprimexex) to count tins as they roll by and detect tins without paper labels.

![The Build](./assets/tin_counter_build.jpg?raw=true)

## Notes

This project is basically to build a chute that would count tins as they roll by and detect tins without paper labels.

The label detection works by runnibg a piece of wire on the floor of the chute and connecting it to the A0 pin.
The A0 pin detects tins without labels by reading the voltage on the wire.

If the metal surface of the tin (i.e tins without labels) comes in contact with the wire, there would be a change in the voltage.
A change in voltage means the red led would blink once.. one blink for ever labeless tin that passes.

### Construction

![The Breadboard](./assets/tin_counter_bb.jpg?raw=true)

![The Schematic](./assets/tin_counter_schematic.jpg?raw=true)

## Credits and References

* [novaprimexex](https://github.com/novaprimexex) - author/contributor of this project
* [HC-SR04 datasheet](http://www.micropik.com/PDF/HCSR04.pdf)
