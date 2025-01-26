# #023 NAND Gate with Resistor-Transistor Logic

Test the basic resistor-transistor logic NAND gate.

## Notes

Resistor–transistor logic (RTL) is a class of digital circuits built using resistors as the input network and bipolar junction transistors (BJTs) as switching devices. RTL is the earliest class of transistorized digital logic circuit and is largely obsolete now.

It is interesting to see how various logic gate may be realised with BJTs and resistors alone. Here is the basic NAND gate.

This is the "classic" two-transistor NAND gate, often used when describing the fundamentals of digital logic.
Given two **ideal** transistors (NPN) with collector-emitter in series, we treat them as switches:
only when both are on should there be a low output.

| A   | B   | OUT |
|:---:|:---:|:---:|
| 0   | 0   | 1   |
| 0   | 1   | 1   |
| 1   | 0   | 1   |
| 1   | 1   | 0   |

However, that's the idealised view. In practice things are a little messier. In particular:
* A pull-down resistor (Rp) is required to get a clean "off", else the input would be floating.
* With the lower transistor on, we can see partial activation. This is because we are applying a voltage to the base while the collector is not driven, so the base is appearing on the emitter. We have to work around this problem be definining the threshold for "high" to be above this voltage.

Here's a sample trace. The lower two traces are the signal inputs, and the upper trace is the output of the gate.

![processing trace](./assets/processing_trace.png?raw=true)

The Arduino is not really a core part of the circuit. It only does the following:
* provides +5V power supply (for convenience)
* automates the toggling of the driving inputs
* measures the input and output voltages for plotting

## Construction

The circuit uses a digital output pins to sequence inputs to the gate.
Three analog input pins are used to read the two input signals and the resuting output, with the values is echoed to the Arduino serial port
for plotting with [PlotNValues](../../../processing/PlotNValues) (a simple Processing sketch).

![Breadboard](./assets/NAND_bb.jpg?raw=true)

![The Schematic](./assets/NAND_schematic.jpg?raw=true)

![The Build](./assets/NAND_build.jpg?raw=true)

## Credits and References

* [Resistor-Transistor Logic](https://en.wikipedia.org/wiki/Resistor%E2%80%93transistor_logic) - wikipedia page
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml) - the NPN used in this circuit
* [AND Gate](http://en.wikipedia.org/wiki/AND_gate) - wikipedia
* [TTL NAND and AND gates](http://www.allaboutcircuits.com/vol_4/chpt_3/5.html) - describes a practical implementation of a "real" AND gate
* [Logic Gates using Transistors](http://hyperphysics.phy-astr.gsu.edu/hbase/electronic/trangate.html)
* [Logic Gates using Transistors #2](https://electrosome.com/logic-gates-using-transistors/) - note, when last checked, the AND circuit is wrong?
* [Logic AND Gate Tutorial](http://www.electronics-tutorials.ws/logic/logic_2.html) - explains of the basic circuit used here.
* [Electronics Projects: How to Create a Transistor NAND Gate Circuit](https://www.dummies.com/programming/electronics/diy-projects/electronics-projects-how-to-create-a-transistor-nand-gate-circuit/)
* [From Transistors to Functions](http://www.cs.bu.edu/~best/courses/modules/Transistors2Gates/)
