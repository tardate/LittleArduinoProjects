# #065 Digital Logic Switch - N-Channel Enhancement FET

Using a small-signal n-channel MOSFET as a switch, with turn-off delay.

Here's a quick video of the circuit in action:

[![SwitchNFET demo](http://img.youtube.com/vi/OQDaS_fVWGQ/0.jpg)](http://www.youtube.com/watch?v=OQDaS_fVWGQ)

## Notes

N-Channel Enhancement FETs are easy to use as a digital switch:

* ON when gate-source voltage is much greater than threshold voltage (into saturation region)
* OFF when gate-source voltage is below threshold voltage (0.8-3V for 2N7000)

This circuit demonstrates the basic switch, with the addition of a turn-off delay.

The turn-off delay is implemented with a simple RC circuit: the R1=220kΩ C1=10μF pair having a time constant of
[2.2 seconds](http://www.wolframalpha.com/input/?i=220k%CE%A9+*+10%CE%BCF).

### Construction

![The Breadboard](./assets/SwitchNFET_bb.jpg?raw=true)

![The Schematic](./assets/SwitchNFET_schematic.jpg?raw=true)

![The Build](./assets/SwitchNFET_build.jpg?raw=true)

## Credits and References
* [SwitchPFET](../SwitchPFET) - same circuit but using p-channel MOSFET
* [2N7000 datasheet](http://www.futurlec.com/Transistors/2N7000.shtml)
* [MOSFET as a Switch](http://www.electronics-tutorials.ws/transistor/tran_7.html)
