# #221 ResistorTransistorLogic/XOR

Test the basic resistor-transistor logic XOR gate.


## Notes

![XOR_ANSI](https://upload.wikimedia.org/wikipedia/commons/0/01/XOR_ANSI.svg)

Exclusive OR (XOR) operation is true only when inputs are different. Truth table:

| A   | B   | OUT |
|:---:|:---:|:---:|
| 0   | 0   | 0   |
| 0   | 1   | 1   |
| 1   | 0   | 1   |
| 1   | 1   | 0   |

An XOR may be constructed using combinatorial logic: an OR ANDed with a NAND.

This circuit uses a diode-bridge and a single transistor - quite neat. It does mean however that there is no output buffer,
in fact the output is powered from the inputs.

[Here's a simulation](http://www.falstad.com/circuit/circuitjs.html?cct=$+1+0.000005+10.200277308269968+52+5+50%0AL+688+224+592+224+0+1+false+3.6+0%0AL+688+416+592+416+0+1+false+3.6+0%0AM+832+336+896+336+0+2.5%0At+800+320+832+320+0+-1+3.3628309272096417+-0.09853956533713282+100%0Ad+736+320+688+272+1+0.805904783%0Ad+688+272+640+320+1+0.805904783%0Ad+736+320+688+368+1+0.805904783%0Ad+688+368+640+320+1+0.805904783%0Aw+688+368+688+416+0%0Aw+688+272+688+224+0%0Ar+736+320+800+320+0+10000%0Ag+832+400+832+416+0%0Aw+640+320+624+320+0%0Aw+624+320+624+256+0%0Aw+624+256+832+256+0%0Aw+832+256+832+304+0%0Ar+832+336+832+400+0+10000%0A)
of the circuit using Circuit Simulator by Paul Falstad.

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

![Breadboard](./assets/XOR_bb.jpg?raw=true)

![The Schematic](./assets/XOR_schematic.jpg?raw=true)

![The Build](./assets/XOR_build.jpg?raw=true)

## Credits and References
* [XOR](https://en.wikipedia.org/wiki/Exclusive_or) - wikipedia
* [Implementing XOR and XNOR Logic Functions using Diode Bridge and Transistor](https://electrosome.com/xor-xnor-logic-function-diode-bridge-transistor/)
* [How are logic gates created electronically?](http://electronics.stackexchange.com/questions/53142/how-are-logic-gates-created-electronically) - EE.SE
* [XOR in electronics](http://electronics.stackexchange.com/questions/23862/xor-in-electronics/240116#240116) - EE.SE
* [RTL XOR simulation](http://www.falstad.com/circuit/circuitjs.html?cct=$+1+0.000005+10.200277308269968+52+5+50%0AL+688+224+592+224+0+1+false+3.6+0%0AL+688+416+592+416+0+1+false+3.6+0%0AM+832+336+896+336+0+2.5%0At+800+320+832+320+0+-1+3.3628309272096417+-0.09853956533713282+100%0Ad+736+320+688+272+1+0.805904783%0Ad+688+272+640+320+1+0.805904783%0Ad+736+320+688+368+1+0.805904783%0Ad+688+368+640+320+1+0.805904783%0Aw+688+368+688+416+0%0Aw+688+272+688+224+0%0Ar+736+320+800+320+0+10000%0Ag+832+400+832+416+0%0Aw+640+320+624+320+0%0Aw+624+320+624+256+0%0Aw+624+256+832+256+0%0Aw+832+256+832+304+0%0Ar+832+336+832+400+0+10000%0A) - Circuit Simulator by Paul Falstad
* [7486 Exclusive-OR gate internals](http://www.interfacebus.com/ic-exclusive-or-gate-dual-input-dip.html)
* [..as mentioned on my blog](https://blog.tardate.com/2016/08/littlearduinoprojects221-xor-with.html)
