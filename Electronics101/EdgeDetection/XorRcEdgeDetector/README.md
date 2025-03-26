# #488 XOR-RC Edge Detector

Dual edge detection with a 74LS86 XOR and RC circuit.

![Build](./assets/XorRcEdgeDetector_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/IZa2RNOWJiA/0.jpg)](https://www.youtube.com/watch?v=IZa2RNOWJiA)

## Notes

A XOR gate can be used as an edge detector by feeding it with two signals:

* the original input signal
* a modified version of the input signal, containing delay or hysteresis

One way of doing this is to put and RC filter on the second input.
That's the circuit demonstrated here: where a 10kΩ and 1µF RC filter yields a [10ms time constant](https://www.wolframalpha.com/input/?i=10k%CE%A9*1%C2%B5F).
Increasing the time constant will increase the minimum output pulse width, and also acts as a de-bouncing trick.

Another technique is to replace the RC filter with an even number of inverters, the idea being that propagation delay in the inverters
produces the differential input to the XOR gate.
Note: I'm using a 74LS86, and configuring some of the XOR units as inverters "works" but only very poorly as the <23ns propagation delay
only produces a very weak pulse when an edge is detected.

## Behaviour

The scope trace below shows the pulses generated on the rising and falling edge of the input.

* CH1 (yellow) - output
* CH2 (blue) - input signal
* CH3 (red) - filtered input signal

![scope](./assets/scope.gif?raw=true)

## Construction

I'm using a 74LS86 Quad 2-Input Exclusive-OR Gate in this demo.

![Breadboard](./assets/XorRcEdgeDetector_bb.jpg?raw=true)

![Schematic](./assets/XorRcEdgeDetector_schematic.jpg?raw=true)

![Build](./assets/XorRcEdgeDetector_build.jpg?raw=true)

## Credits and References

* [74LS86 datasheet](https://www.futurlec.com/74LS/74LS86.shtml)
* [Rising edge pulse detector from logic gates](https://electronics.stackexchange.com/questions/165552/rising-edge-pulse-detector-from-logic-gates)
* [Dual edge detector](https://electronics.stackexchange.com/a/270908/52289)
* [ARRL's Hands-On Radio Experiments Volume 3](../../../books/arrl-hands-on-radio-experiments-vol3/) Experiment #125 (covers Schmitt Trigger edge detection)
