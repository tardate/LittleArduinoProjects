# #570 MT3608 on a Breadboard

A quick breadboard test of the canonical MT3608 switch mode power supply boost converter circuit.

![Build](./assets/Breadboarded_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/sJViLFRlgVI/0.jpg)](https://www.youtube.com/watch?v=sJViLFRlgVI)

## Notes

The MT3608 (parts also produced as the B6286) is a very efficient boost converter that can deliver up to 24V at 4A.
It requires only 6 external passive components, and is readily available as a complete module for as little as $0.40.

In this project, I'm simply building the standard variable converter circuit on a breadboard to verify its performance.

### MT3608

* 2V to 24V Input Voltage
* 1.2MHz Fixed Switching Frequency
* Internal 4A Switch Current Limit
* Internal Compensation
* Up to 28V Output Voltage
* Automatic Pulse Frequency Modulation Mode at Light Loads
* up to 97% Efficiency

![MT3608_functional](../assets/MT3608_functional.png?raw=true)

## Circuit Layout

The M3608 comes in a miniscule SOT23-6 package (0.95mm pin spacing).
I've put it on a SOT23-10 DIP adapter board for use on a breadboard.

## Supporting Component Selection

### Inductor

The datasheet recommends a 4.7µH to 22µH inductor with low core loss at 1.2MHz.
I'm using a 22µH CDRH104R SMD power inductor.

### Filter Capacitors

22µF input and output ceramic capacitors are recommended. I'm using SMD 22µF ceramics mounted on a DIP adapter board.

### Diode Selection

A low forward-voltage schottky diode is recommended.
I'm using 1N5819 SMD mounted on a DIP adapter board.

### Feedback Resistors

The feedback voltage-divider with two resistors establishes the output voltage level where Vref is 0.6V:

`Vout = Vref * (1 + R1/R2)`

I'm using R1 = 100kΩ variable resistor ("rheostat" wiring), and R2 = 2.2kΩ.

This give a theoretical maximum output voltage of [27.9V](https://www.wolframalpha.com/input/?i=0.6V+*(1+%2B+100k%CE%A9%2F2.2k%CE%A9)).

The theoretical minimum output voltage is [0.6V](https://www.wolframalpha.com/input/?i=0.6V+*(1+%2B+0k%CE%A9%2F2.2k%CE%A9))
however in practice the lowest output voltage is limited to around 1 diode drop less than the input voltage,
hence there is a bit of dead zone at the lower adjustment.

Note: some boards/schematics will wire the R1 variable resistor in a potentiometer configuration, with the wiper connected to the FB pin.
The same principle applies, however the voltage divider calculations of course change.

### Enable Pin Connection

I've chosen not to use this in this build, so it is pulled high to the input power rail (always enabled).

## Construction

![Breadboard](./assets/Breadboarded_bb.jpg?raw=true)

![Schematic](./assets/Breadboarded_schematic.jpg?raw=true)

Testing on a breadboard with 5V input and a panel meter to display the boosted output:

![Breadboard Build](./assets/Breadboarded_bb_build.jpg?raw=true)

## Credits and References

* [MT3608 datasheet](https://www.olimex.com/Products/Breadboarding/BB-PWR-3608/resources/MT3608.pdf)
* [1N5819 Datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
