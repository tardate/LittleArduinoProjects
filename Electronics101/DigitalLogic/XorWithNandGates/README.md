# #283 XOR With NAND Gates

Construct an XOR gate with only an 74LS132 quad NAND gate, and demonstrate it's behaviour with an Arduino and Processing.

![Build](./assets/XorWithNandGates_build.jpg?raw=true)

## Notes

I recently needed an XOR gate, but only had NAND gates on hand.

NAND (and NOR) gates are sometimes known as "universal" logic elements, as it is possible to contruct any other
type of logic gate with them.

So while a little wasteful, I'm using the four NAND gates of a single 74LS132 chip to produce one XOR gate.


### XOR From NAND Logic

![XOR_from_NAND](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fa/XOR_from_NAND.svg/800px-XOR_from_NAND.svg.png)

|  A |  B | Q1 | Q2a | Q2b | Q |
|----|----|----|-----|-----|---|
|  0 |  0 |  1 |   1 |   1 | 0 |
|  0 |  1 |  1 |   1 |   0 | 1 |
|  1 |  0 |  1 |   0 |   1 | 1 |
|  1 |  1 |  0 |   1 |   1 | 0 |


### Output State Plot


The [XorWithNandGates.ino](./XorWithNandGates.ino) sketch drives the A/B inputs with a state change every 500ms.
Three Arduino analog pins are used to rea dthe actual A, B and Q (output) voltages.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the output value over time, with some coloration effects thrown in for good measure.

Here's a sample trace:

* top trace: Q (output)
* middle trace: B
* bottom trace: A

![processing trace](./assets/processing_trace.png?raw=true)

## Construction

![Breadboard](./assets/XorWithNandGates_bb.jpg?raw=true)

![Schematic](./assets/XorWithNandGates_schematic.jpg?raw=true)

![Build](./assets/XorWithNandGates_build.jpg?raw=true)

## Credits and References

* [XOR gate](https://en.wikipedia.org/wiki/XOR_gate) - wikipedia
* [74LS132 datasheet](https://www.futurlec.com/74LS/74LS132.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap283-xor-with-nand-gates.html)
