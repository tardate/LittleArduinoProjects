# #021 Schmitt Inverter

Use an Arduino to demonstrate the basic operation of 74LS14 Hex Inverter with Schmitt Trigger Inputs chip, and plot the results with [Processing](https://www.processing.org).

Here's a quick video of the circuit in action:

[![Schmitt Inverter](http://img.youtube.com/vi/xGmdBrGDc2E/0.jpg)](http://www.youtube.com/watch?v=xGmdBrGDc2E)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The circuit uses a digital output pin to drive one inverter unit of the 74LS14 chip.
The input and output levels are read with analog input pins, and the values is echoed to the Arduino serial port for plotting.

All unused outputs on the 74LS14 are left open circuit. Unused inputs are grounded, as is recommended to avoid unstable operation.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

Here's a sample trace. The lower trace is the signal input, and the upper trace is the output of the inverter.

![processing trace](./assets/processing_trace.png?raw=true)

Compared with a [simple BJT inverter](../ResistorTransistorLogic/NOT), we see a much cleaner signal.

### Construction

![The Breadboard](./assets/SchmittInverter_bb.jpg?raw=true)

![The Schematic](./assets/SchmittInverter_schematic.jpg?raw=true)

![The Build](./assets/SchmittInverter_build.jpg?raw=true)


## Credits and References
* [Download Processing](https://www.processing.org/download/)
* [74LS14 Datasheet](http://www.futurlec.com/74LS/74LS14.shtml)
