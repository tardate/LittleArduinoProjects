# #670 Nano/ExpansionBoard

Testing and reverse engineering a cheap Arduino Nano Expansion board, also pondering why GVS instead of GSV or GVSG.

![Build](./assets/ExpansionBoard_build.jpg?raw=true)

## Notes

Another impulse buy:
[Nano Multifunction Expansion Board](https://www.aliexpress.com/item/4000587268145.html)
for S$1.30 from an aliexpress seller.

Features of the board:

* 5.5 x 2.1mm barrel jack for power supply (recommended input voltage for Nano: 7-12V)
* additional red LED 5V power indicator
* additional AMS1117 3.3V regulator
    * tantalum and ceramic input and output smoothing caps
    * bank of 3 pairs of 3.3V + GND pins
* "GVS" (ground - voltage - signal) pin banks for each GPIO of the Nano

### Circuit Design

Sketching the schematic for the additional components that make up the expansion board:

![bb](./assets/ExpansionBoard_bb.jpg?raw=true)

![schematic](./assets/ExpansionBoard_schematic.jpg?raw=true)

Testing the board with a Nano installed:

![Test](./assets/ExpansionBoard_test.jpg?raw=true)

### An Aside on GVS

[GVS](https://elinux.org/BBB-GVS#What_is_GVS.3F)
is an unofficial standard for positioning ground and power with each signal pin:

* 0.1" pitch pins
* Ordered: Ground - Voltage - Signal

There are a large number of modules for input or output (e.g. sensors) that have a GVS connector.
There is a 4 wire version (GVSS) for bidirectional serial communications.

I guess the original thinking was to keep the power wires together, and then add 1 or more signals to the end.

However on an expansion board like this it does mean a bit of a missed opportunity:

* if the order was GSV, then 2-pin jumpers could be used to pull the signal pin high or low
* with GVS, a 2-pin jumper can only be used to pull the signal high.

![GVS_connectors](./assets/GVS_connectors.jpg?raw=true)

Perhaps a better design for an expansion board would be to put headers for GVSG:

* the GVS part could be used for standard GVS cable connections
* and the VSG part could be used to pull signal high or low with a 2-pin jumper

## Credits and References

* [Nano Multifunction Expansion Board](https://www.aliexpress.com/item/4000587268145.html)
* [AMS1117 datasheet](http://www.advanced-monolithic.com/pdf/ds1117.pdf)
* [1N4007 datasheet](https://www.futurlec.com/Diodes/1N4007.shtml)
* [What is GVS](https://elinux.org/BBB-GVS#What_is_GVS.3F)
* [Ground Voltage Signal Wiring Standard](https://learnarduinonow.com/2012/06/04/ground-voltage-signal-wiring-standard.html)
