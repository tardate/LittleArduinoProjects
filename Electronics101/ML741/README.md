# ML741

The "Medium-Large 741" - an LM741-style OpAmp built with discrete components

## Notes

This ia a "Medium-Large" version of the venerable 741, inspired by the
[XL741 kit](http://wiki.evilmadscientist.com/XL741) from the Evil Mad Scientist.
Just not so big - Lego size instead of Duplo!

The intention is to get inside a real op-amp circuit and see how it works.

First test was with the circuit on a breadboard, running a basic comparator test. That all worked fine.
With the lower and upper rails at 0V and 8.92V respectively and no output load:
* output swings to 1.21V (low) when non-inverting input (IN+) is below inverting input (IN-)
* output swings to 8.52V (high) when non-inverting input (IN+) is above inverting input (IN-)

Next I put the circuit on a protoboard - see the layout details below.
I've wired all the connection points to an 8-pin DIP socket that can be plugged into a breadboard,
and provided pin headers for wiring directly to the board.
The 8-pin DIP socket is wired in the same way as the LM741:

| Pin | Connection                       |
|-----|----------------------------------|
| 1   | Offset Null (non-inverting side) |
| 2   | Inverting input                  |
| 3   | Non-inverting input              |
| 4   | V-                               |
| 5   | Offset Null (inverting side)     |
| 6   | Output                           |
| 7   | V+                               |
| 8   | N/C                              |


Some related projects to test the ML741 in various opamp topologies:
* [Comparator](./Comparator)
* [Inverter](./Inverter)
* [VoltageFollower](./VoltageFollower)

### How Does it Work?

The [Evil Mad Scientist](http://wiki.evilmadscientist.com/XL741) has an excellent and detailed description on how the 741 circuit works
in their "Principles of Operation" document. I won't try to improve on it!

So just to pluck out the salient points and add some more references:


#### Differential Amplifier Stage
* A fairly conventional "long-tailed pair" arrangement
* See w2aew's excellent [#193: Back to Basics: the differential amplifier, aka long-tailed pair, diff-pair](https://youtu.be/mejPNuPAHBY) for chapeter and verse
* offset connections rarely used in practice, but wiring a 10kΩ pot across them allows fine-tuning the balance


#### Bias Generator
* provides reference current for differential amplifier using a [Widlar current source](https://en.wikipedia.org/wiki/Widlar_current_source) arrangement
* current mirror feeds the gain stage
* another excellent tutorial from w2aew: [#190: Back to Basics: Transistor Current Sources and Mirrors](https://youtu.be/xR0RfmmRhDw)

#### Gain Stage
* multiplies the signal from the differential amplifier using Darlington configuration
* [Miller capacitor](https://en.wikipedia.org/wiki/Miller_effect) stabilizes the behavior of the op-amp at the cost of some gain
* Vbe generator to avoid cross-over distortion in output from gain stage
* Yet another topical video from w2aew: [#198: Basics of a Vbe Multiplier: what it is, how it works & where it is used](https://youtu.be/Obh_PIC2qqo)

#### Output Stage
* Q14/Q20two transistors configured as emitter followers to either source or sink current
* Q15/R9 limits the current that can be sourced

## Construction

![Breadboard](./assets/ML741_bb.jpg?raw=true)

![The Schematic](./assets/ML741_schematic.jpg?raw=true)

### Breadboard Construction

![The Build](./assets/ML741_build.jpg?raw=true)

### Protoboard Construction

![Board Build](./assets/ML741_board_build.jpg?raw=true)

![Board layout](./assets/ML741_board_layout.jpg?raw=true)

![Board Front](./assets/ML741_board_front.jpg?raw=true)

![Board Rear](./assets/ML741_board_rear.jpg?raw=true)

## Credits and References
* [XL741 Discrete 741 Op-Amp kit](http://wiki.evilmadscientist.com/XL741) by the Evil Mad Scientist
* [LM741 Datasheet](http://www.futurlec.com/Linear/LM741CN.shtml)


