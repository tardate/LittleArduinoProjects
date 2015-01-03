# Fundamental Logic Gates - Simple NAND Gate

Use an Arduino to demonstrate the most basic transistor NAND gate, and plot the results with [Processing](https://www.processing.org).

## Notes

The circuit uses a digital output pins to sequence inputs to the NAND gate. The output is tapped at the collector of the transistor chain. The output voltage is read with an analog input pin, and the value is echoed to the Arduino serial port.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

Here's a sample trace without any load on the output. The lower two traces are the input signals, and the upper trace is the output.

![processing trace](./assets/processing_trace.png?raw=true)

Here's a sample trace, but with a load on the output (LED):

![processing trace](./assets/processing_trace_loaded.png?raw=true)


### Construction

![The Breadboard](./assets/SimplestNAND_bb.jpg?raw=true)

![The Schematic](./assets/SimplestNAND_schematic.jpg?raw=true)

![The Build](./assets/SimplestNAND_build.jpg?raw=true)


## Credits and References
* [Download Processing](https://www.processing.org/download/)
* [Transistor–transistor logic](http://en.wikipedia.org/wiki/Transistor%E2%80%93transistor_logic)
* [TTL NAND and AND gates](http://www.allaboutcircuits.com/vol_4/chpt_3/5.html) - explains of the basic circuit used here.
