# Fundamental Logic Gates - Basic AND Gate

Use an Arduino to demonstrate the basic two-transistor AND gate, and plot the results with [Processing](https://www.processing.org).

## Notes

This is the "classic" two-transistor AND gate, often used when describing the fundamentals of digital logic.
Given two **ideal** transistors (NPN) with collector-emitter in series, we treat them as switches: only when both are
on should there be a high output.

| Q2b | Q1b | Out (Q2e) |
|:---:|:---:|:---:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

However, that's the idealised view, but in practice things are a little messier, as can be seen in the trace below.
In particular:

* For the "10" case, we can see partial activation. This is because we are applying a voltage to the base of Q2 while the collector is not driven, so the base is appearing on the emitter. We have to work around this problem be definining the threshold for "high" to be above this voltage.

Here's a sample trace. The lower two traces are the signal inputs, and the upper trace is the output of the gate.

![processing trace](./assets/processing_trace.png?raw=true)

The resistor R4 is required to fully pull-down the output when low. Without it, the low output is quite noisy. That looks like mains frequency interference. Here's the trace without the pull-down resistor:

![processing trace without pull-down](./assets/processing_trace_without_pulldown.png?raw=true)

### Construction

The circuit uses a digital output pins to sequence inputs to the AND gate. Three analog input pins are used to read the two input signals and the resuting output, with the values is echoed to the Arduino serial port.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

![The Breadboard](./assets/BasicAND_bb.jpg?raw=true)

![The Schematic](./assets/BasicAND_schematic.jpg?raw=true)

![The Build](./assets/BasicAND_build.jpg?raw=true)

## Credits and References
* [Download Processing](https://www.processing.org/download/)
* [AND Gate](http://en.wikipedia.org/wiki/AND_gate) - wikipedia
* [TTL NAND and AND gates](http://www.allaboutcircuits.com/vol_4/chpt_3/5.html) - describes a practical implementation of a "real" AND gate
* [Logic Gates using Transistors](http://hyperphysics.phy-astr.gsu.edu/hbase/electronic/trangate.html)
* [Logic Gates using Transistors #2](https://electrosome.com/logic-gates-using-transistors/) - note, when last checked, the AND circuit is wrong?
* [Logic AND Gate Tutorial](http://www.electronics-tutorials.ws/logic/logic_2.html) - explains of the basic circuit used here.
