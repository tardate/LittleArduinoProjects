# #840 NOR Gate with NAND Logic

Demonstrating how a NOR gate may constructed solely from NAND gates.

![Build](./assets/NOR_build.jpg?raw=true)

## Notes

The NAND boolean function has the property of functional completeness, meaning that any Boolean expression can be expressed with an equivalent expression using only NAND operations.

The NAND Truth Table:

| A | B | Q |
|---|---|---|
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

The NOR Truth Table:

| A | B | Q |
|---|---|---|
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 0 |

A NOR gate is an OR gate with an inverted output.

![nor-with-nand](./assets/nor-with-nand.jpg)

### Circuit Design

Designed with Fritzing: see [NOR.fzz](./NOR.fzz).

To demonstrate an OR gate made from NAND gates, I have the circuit constructed on a breadboard using
the CD4011 Quad 2-Input NAND Buffered B Series Gate.

An Arduino is used to automate a demo cycle of inputs.

Inputs and outputs are indicated with LEDs, and captured with an oscilloscope.

![bb](./assets/NOR_bb.jpg?raw=true)

![schematic](./assets/NOR_schematic.jpg?raw=true)

![bb_build](./assets/NOR_bb_build.jpg?raw=true)

### The Sketch

See [NOR.ino](./NOR.ino).

The sketch simply automates the A, B inputs, cycling through all 4 possibilities.

### Test Results

Here's a scope trace capturing all 4 states, and demonstrating the the output is correct as expected.
Traces are offset vertically for clarity.

* CH1 (yellow): input A
* CH2 (blue): input B
* CH3 (red): output Q

![scope](./assets/scope.gif)

## Credits and References

* [CD4011 datasheet](https://www.futurlec.com/4000Series/CD4011.shtml)
* <https://en.wikipedia.org/wiki/NAND_logic>
* See also:
    * [LEAP#838 AND Gate with NAND Logic](../AND/)
    * [LEAP#839 OR Gate with NAND Logic](../OR/)
    * [LEAP#840 NOR Gate with NAND Logic](../NOR/)
    * [LEAP#841 NOT Gate with NAND Logic](../NOT/)
    * [LEAP#842 XOR Gate with NAND Logic](../XOR/)
    * [LEAP#843 XNOR Gate with NAND Logic](../XNOR/)
