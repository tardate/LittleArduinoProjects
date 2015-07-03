# RingCounterController

Control the classic CD4017 walking-ring counter with an Arduino

## Notes

The [RingCounter](../../Electronics101/RingCounter) project demonstrated the classic walking ring circuit
using a 555 timer to send clock pulses to a CD4017 Decade Counter/Divider with 10 Decoded Outputs.

This project replaces the 555 with a microcontroller for more dynamic effects. The program demonstrates a few effects
achieved by controlling the CLOCK, RESET and CLOCK ENABLE pins of the CD4017.

Digital IO pins are connected to the CLOCK, RESET and CLOCK ENABLE pins via 1kΩ resistor.
The resistor is not strictly necessary as the CD4017 draws at most 1µA on the inputs.
But they provide some over-current protection for the Arduino should anything be going wrong in the circuit.

The minimum clock pulse with is 250ns when operating at 5V.
The program ensures a minimum clock pulse of 1ms which is very conservative.
In fact the sketch works equially well with no delay when pulsing the clock - just `digitalWrite` HIGH immediately followed by `digitalWrite` LOW.

## Construction

![Breadboard](./assets/RingCounterController_bb.jpg?raw=true)

![The Schematic](./assets/RingCounterController_schematic.jpg?raw=true)

![The Build](./assets/RingCounterController_build.jpg?raw=true)

## Credits and References
* [CD4017 datasheet](http://www.futurlec.com/4000Series/CD4017.shtml)
* [kit link](http://www.aliexpress.com/item/M89-Free-Shipping-New-1PC-New-NE555-CD4017-Light-Water-Flowing-Light-LED-Module-DIY-Kit/32259714112.html) - example of the same circuit available as a kit
* [RingCounter](../../Electronics101/RingCounter) - same project but in classic configuration with 555 timer
