# NOR7402 - 74LS02 Quad 2-input NOR gate test

Use an Arduino to demonstrate a basic 74LS02 Quad 2-input NOR gate circuit, and plot the results with [Processing](https://www.processing.org).

## Notes

The 74LS02 Quad 2-input NOR gate is from the [7400 series](http://en.wikipedia.org/wiki/7400_series) of TTL integrated circuits.
"Quad 2-input" means it contains four independent gates each with 2 inputs.
"74LS" means this is Low-power Schottky sub-family device (reduced power consumption and switching speed compared to 74S)

Each gate implements standard NOR logic:

| A | B | Y (output) |
|:-:|:-:|:----------:|
| 0 | 0 | 1          |
| 0 | 1 | 0          |
| 1 | 0 | 0          |
| 1 | 1 | 0          |

The 74LS02 is a 5V device with logic levels bounded as follows (from the datasheet):
* HIGH inputs are recommended to be 2.0V minimum
* LOW inputs are recommended to be 0.8V maximum
* HIGH output is 2.7V minimum, typically 3.4V
* LOW output is 0.5V maximum, typically 0.35V

This circuit demonstrates the basic operation.
It uses the Arduino to sequence inputs through the truth table on a single NOR gate.
The NOR gate outpur drives an LED and is also measured by the Arduino with an analog input.

### Behaviour

Here's a sample trace taken with [PlotNValues (a simple Processing sketch)](../../processing/PlotNValues).
The lower two traces are the gate inputs, and the upper trace is the gate output.
The HIGH output voltage measures at 3.42V (a tad over typical value according to the datasheet)

![processing trace](./assets/processing_trace.png?raw=true)


### Construction

![The Breadboard](./assets/NOR7402_bb.jpg?raw=true)

![The Schematic](./assets/NOR7402_schematic.jpg?raw=true)

![The Build](./assets/NOR7402_build.jpg?raw=true)


## Credits and References
* [74LS02 datasheet](http://www.futurlec.com/74LS/74LS02.shtml)
* [7400 series](http://en.wikipedia.org/wiki/7400_series)
