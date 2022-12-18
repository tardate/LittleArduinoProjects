# #025 74LS75 Quad Latch Test

Use an Arduino to demonstrate a basic 74LS75 Quad Latch driver circuit, and plot the results with [Processing](https://www.processing.org).

Here's a quick video of the circuit in action:

[![74LS75 Quad Latch Test](https://img.youtube.com/vi/nsRWAuc6J5w/0.jpg)](https://www.youtube.com/watch?v=nsRWAuc6J5w)

## Notes

The 74LS75 Quad Latch is a 4-bit bistable latch from the [7400 series](http://en.wikipedia.org/wiki/List_of_7400_series_integrated_circuits) of TTL integrated circuits.

This circuit demonstrates the basic operation. It uses the Arduino to latch a data series to the 4 input pins (D1-D4), while sampling the 4 output bits Q1-4.
The 7475 also handily offers inverted output pins, but they are not used here.

Data is transferred from input to output pins when enable pins go HIGH.
While enable is kept high, latch output will follow latch input. When enable goes low, previous output state is maintained, regardless of subsequent input changes.

It is possible to separately latch bits 1-2 and 3-4, but for simplicity this circuit latches all bits at once (with pins 4 and 13 in tandem).

Here's a sample trace, with Q1-4 plots stacked:

![processing trace](./assets/processing_trace.png?raw=true)

The trace is generated with [LEAP#090 PlotNValues (a simple Processing sketch)](../../playground/PlotNValues).
It reads the data from the serial port and plots the input and output value over time, with some coloration effects thrown in for good measure.
In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

### Construction

The circuit uses a digital output pins to sequence inputs to D1-4 and latch the value.
Four analog input pins are used to sample the latched output Q1-4, with the values is echoed to the Arduino serial port.

The circuit diagram uses a custom 74LS75 Fritzing Part [available here](../../FritzingParts/74LS75).

![The Breadboard](./assets/QuadLatch_bb.jpg?raw=true)

![The Schematic](./assets/QuadLatch_schematic.jpg?raw=true)

![The Build](./assets/QuadLatch_build.jpg?raw=true)

## Credits and References

* [Download Processing](https://www.processing.org/download/)
* [74LS75 Datasheet](https://www.futurlec.com/74LS/74LS75.shtml)
