# #117 SolenoidDIY

Build and test basic electromechanical solenoid.

![The Build](./assets/SolenoidDIY_build.jpg?raw=true)

Here's a quick video of the solenoid in action:

[![SolenoidDIY](https://img.youtube.com/vi/Lakz1MZA9wI/0.jpg)](https://www.youtube.com/watch?v=Lakz1MZA9wI)

## Notes

A [solenoid](https://en.wikipedia.org/wiki/Solenoid) technically refers to a coil of wire
through which a current may flow to generate an electromagnetic field, according to [Ampere's Law](https://en.wikipedia.org/wiki/Ampere%27s_Law).

The [right-hand rule](https://en.wikipedia.org/wiki/Right-hand_rule) indicates the orientation of the field with respect to current.

In practice, the term solenoid usually refers to the electromechanical solenoid. This includes a steel or iron armature that moves in response
to changes in the electromagnetic field.

The objective of this project is to construct a solenoid from scratch and demonstrate its operation with an Arduino.

### Making the Solenoid
The solenoid I've constructed here is 9m of wire wound around a ~7mm drinking straw, in about three layers over a 4cm stretch.
I didn't count them, but that should work out at about [400 turns](https://www.wolframalpha.com/input/?i=9%2F%28%CF%80*7*10^-3%29).

The wire used is similar to [this product from a seller on aliexpress](https://www.aliexpress.com/item/0-2mm-100m-Copper-Wire-Polyurethane-enameled-wire-QA-1-130-Red-Free-shipping/2054129524.html). It is 0.2mm enameled copper wire.

The resistance of the winding wire reads at around 10Ω in total.
With a 9V supply, we'd expect a current of about [900mA](https://www.wolframalpha.com/input/?i=9V%2F10%CE%A9).
And that's what I measure when I insert an ammeter in the circuit.

The armature is an old screw - some kind of mild steel I think.

![SolenoidDIY_component](./assets/SolenoidDIY_component.jpg?raw=true)

### The Circuit

An Arduino is used to switch the solenoid. A pulse of about 150ms duraction is required
to ensure the solenoid performs a positive and complete action.

An IRF540N n-channel MOSFET is used to switch the current to the solenoid.
A flyback diode across the solenoid handles any back-EMF when power is cut.
The MOSFET allows the 5V Android to switch the 9V power supply.
The power supply is rated for 1A - just enough for this solenoid.

An LED with current-limiting resistor provides a visual indicator when power is on the solenoid.

### Increasing the Force
It works! That has me pretty chuffed. But it is not particularly powerful. There are basically three strategies for
increasing the force applied by the solenoid:
* higher current
* more turns
* higher permeability magnetic core

## Construction

![Breadboard](./assets/SolenoidDIY_bb.jpg?raw=true)

![The Schematic](./assets/SolenoidDIY_schematic.jpg?raw=true)

![The Build](./assets/SolenoidDIY_build.jpg?raw=true)

## Credits and References

* [IRF540 datasheet](https://www.futurlec.com/Transistors/IRF540.shtml)
* [Solenoid](https://en.wikipedia.org/wiki/Solenoid) - wikipedia
* [Right-hand rule](https://en.wikipedia.org/wiki/Right-hand_rule) - wikipedia
* [Engineer's Mini-Notebook - Magnet and Sensor Projects](https://www.goodreads.com/book/show/18007328-engineer-s-mini-notebook) - Forrest M. Mims III
* [Easy to Make Solenoid Engine](https://www.youtube.com/watch?v=HM9zdyX9Ix0)
* [Como Hacer un Motor de Solenoide - Muy fácil de hacer](https://www.youtube.com/watch?v=S2vL3FjqHpI)
* [How to make a homemade solenoid](https://www.youtube.com/watch?v=sRN5UhHhSxY)
* [Solenoid Basics - Part 1](https://www.youtube.com/watch?v=hsoggQOoG4s)
* [Create a Simple Solenoid Musical Instrument](http://www.jameco.com/jameco/workshop/diy/crashspace.html)
* [How to make a simple Electromagnet](https://www.youtube.com/watch?v=iSuSWi7YThA)
* [Homemade Mini Electro-Magnet](https://www.youtube.com/watch?v=PwVuLK0Q-po)
* [0.2mm enameled wire](https://www.aliexpress.com/item/0-2mm-100m-Copper-Wire-Polyurethane-enameled-wire-QA-1-130-Red-Free-shipping/2054129524.html) - seller on aliexpress
