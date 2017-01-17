# #106 SwitchPFET

Using a small-signal p-channel MOSFET as a switch, with turn-on delay.


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

P-Channel Enhancement MOSFETs (like their n-channel cousins) are easy to use as a digital switch:

* ON when gate-source voltage is much higher than threshold voltage (into saturation region)
* OFF when gate-source voltage is below threshold voltage (-0.1 to -3.5V for BS250)

This circuit demonstrates the basic switch, with the addition of a turn-on delay.

With the switch normally open, the gate is pulled low and therefore Vgs is below the threshold voltage.
When the switch is closed, Vgs is brought up to 0V and the FET turns on.

The turn-on delay is implemented with a simple RC circuit: the R1=220kΩ C1=10μF pair having a time constant of
[2.2 seconds](http://www.wolframalpha.com/input/?i=220k%CE%A9+*+10%CE%BCF).
When the switch is opened, C1 takes some time to discharged, hence then FET is delayed in turning back on.

## Construction

![Breadboard](./assets/SwitchPFET_bb.jpg?raw=true)

![The Schematic](./assets/SwitchPFET_schematic.jpg?raw=true)

![The Build](./assets/SwitchPFET_build.jpg?raw=true)

## Credits and References
* [LEAP#66 SwitchNFET](../SwitchNFET) - same circuit but using n-channel MOSFET
* [BS250 datasheet](http://www.futurlec.com/Transistors/BS250.shtml)
* [P-channel MOSFET Switch](http://www.electronics-tutorials.ws/transistor/tran_7.html)
* [P-Channel Power MOSFET Switch Tutorial](http://www.bristolwatch.com/ele/tr1.htm)
* [Practical MOSFET Tutorial #3 - P Channel and the Mobility of Holes](https://youtu.be/AkwxrmDjZMY)
