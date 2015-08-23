# CounterModule

A general-purpose CD4017 counter module.

## Notes

See other projects like [RingCounterController](../RingCounterController) that play with the CD4017 decade counter.

This project puts the chip on a module with an array of LEDs.
The main purpose is to be a handy unit for adding simple visualisations, perhaps for diagnostic purposes.

Power and input pins are arranged so that the module can either be plugged into a breadboard, or directly into an Arduino
using the expansion "shield" pins. It can run on 3-15V supply voltage (the rating of the CD4017).

It can be operated with as little as one digital output (to the CLOCK input).
RESET and CLOCK ENABLE are pulled low by default with 100kΩ resistors.

The CLOCK input has no supporting circuitry, so as to make no assumptions about how the triggering is supplied.
This means external pull-down and or debouncing may be required, depending on the application.

LEDs are connected to all 10 outputs and also the carry out. Each is paired with a 680Ω current limiting resistor.
Note, if running at lower voltages, a single resistor could be shared at a common cathode of the LEDs.
But it depends on the specific LED ratings, as this subjects the LEDs to a reverse voltage equal to the voltage drop across the resistor.

## Construction

![Breadboard](./assets/CounterModule_bb.jpg?raw=true)

![The Schematic](./assets/CounterModule_schematic.jpg?raw=true)

![The Schematic](./assets/CounterModule_pcb_layout.jpg?raw=true)

### Plugged into an Arduino..

![The Build](./assets/CounterModule_build.jpg?raw=true)

### Plugged into a Breadboard..
![The Build](./assets/CounterModule_build_breadboard.jpg?raw=true)

## Credits and References
* [CD4017 datasheet](http://www.futurlec.com/4000Series/CD4017.shtml)
* [RingCounterController](../RingCounterController) - similar project but just running on a breadboard


