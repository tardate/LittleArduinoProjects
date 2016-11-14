# #113 TTLBufferDriver

Using an OpAmp as a final buffer stage for TTL or similar circuits


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

TTL devices and other logic circuits often need to chain to other circuits.
A buffer is generally needed to ensure there is a good impedence match to the following circuit,
and also to ensure a consistent signal is passed on.

OpAmp buffers can be used to provide unity gain and isolate the input and output sides.

This circuit uses an LM324 configured as a comparator in order to "clean up" the output of an
imperfect [Resistor-Transistor Logic AND Gate](../ResistorTransistorLogic/AND).

With a 5V power supply, the basic AND gate drives a 3.8V output when both transistors are on, and 0V when both are off.
But when the lower transistor is on, there's gate-emitter leakage resulting in a semi-on state of about 1.9V.

The voltage divider Rd1/Rd2 set the 0/1 threshold for the OpAmp comparator at half-way (2.5V), so the resulting output is
a clean ON or OFF - nothing in between.

Here's a sample trace. The lower two traces are the inputs to the AND gate.
The top trace is the output of the OpAmp, and the lower-top trace is the output of the AND gate.

![processing trace](./assets/processing_trace.png?raw=true)

The Arduino is not really a core part of the circuit. It only does the following:
* provides +5V power supply (for convenience)
* automates the toggling of the driving inputs
* measures the input and output voltages for plotting

## Construction

![Breadboard](./assets/TTLBufferDriver_bb.jpg?raw=true)

![The Schematic](./assets/TTLBufferDriver_schematic.jpg?raw=true)

![The Build](./assets/TTLBufferDriver_build.jpg?raw=true)

## Credits and References
* [LM324 Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml) - the NPN used in this circuit
* [Resistor-Transistor Logic AND Gate](../ResistorTransistorLogic/AND) - the basic AND gate project without buffer
