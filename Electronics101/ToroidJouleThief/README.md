# ToroidJouleThief

Test a "joule thief" circuit based on a ferrite toroid.

![The Battery Pack Build 2](./assets/ToroidJouleThief_build_AA_pack2.jpg?raw=true)

## Notes

This circuit achieves a voltage boost, enough to drive an LED with forward voltage in excess of the power supply.
In fact it can continue to run the LED as the battery is depleted.
I haven't tested this yet, but apparently it should work down to a battery voltage of ~0.3V under load

The circuit is all over the internet, but I used
[RimstarOrg's video](https://www.youtube.com/watch?v=B61DU7yEsPM)
as a guide.

In this circuit I'm driving a 5mm white strawhat LED, with a forward voltage of 3-3.2V.
No small feat for a single 1.5V AAA!

### Winding the Toroid

I used an 18mm ferrite ring and 30AWG solid core wire.
The two wires are wound in a pair in the same direction - about 10 turns - but they are connected in reverse in the circuit.

## Construction

![Breadboard](./assets/ToroidJouleThief_bb.jpg?raw=true)

![The Schematic](./assets/ToroidJouleThief_schematic.jpg?raw=true)

### On a Breadboard..
![The Build](./assets/ToroidJouleThief_build.jpg?raw=true)

### Queezed into Battery Pack
Fits a single AA or AAA battery, with a switch added for convenience. Makes a decent night light..

![The Battery Pack Build](./assets/ToroidJouleThief_build_AA_pack.jpg?raw=true)

## Credits and References
* [RelaxationJouleThief](../RelaxationJouleThief) - alternative circuit using a relaxation oscillator
* [Joule Thief](https://en.wikipedia.org/wiki/Joule_thief) - wikipedia
* [Make a Joule Thief for Zombie Batteries](https://www.youtube.com/watch?v=B61DU7yEsPM) - by RimstarOrg
* [How a Joule Thief Works](https://www.youtube.com/watch?v=0GVLnyTdqkg) - by RimstarOrg
* [Make a Joule Thief](http://www.bigclive.com/joule.htm) - great instructions for a miniaturized joule thief
* [2N5551 datasheet](http://www.futurlec.com/Transistors/2N5551.shtml)
* [Ferrite ring](http://www.aliexpress.com/item/free-shipping-5pcs-Power-Inductor-Ferrite-Ring-Iron-Toroidal-green-18mm-x-10mm-x-7mm/32297770345.html) - example of a suitable core

