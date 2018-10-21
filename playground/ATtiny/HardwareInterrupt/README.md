# #126 ATtiny Hardware Interrupt

Test hardware interrupts with an ATtiny85 processor on a breadboard.

Here's a quick video of the circuit in action:

[![HardwareInterrupt](http://img.youtube.com/vi/VTJ1ycVzYq0/0.jpg)](http://www.youtube.com/watch?v=VTJ1ycVzYq0)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is a little test of hardware interrupts with an ATtiny85 microcontroller (8-pin DIP).

I'm using an Arduino Uno as an in-system programmer, using the technique described in the [ProgrammingWithArduinoISP](../ProgrammingWithArduinoISP) project.

A push-button is attached to D2 (pin 7 of the chip) and a hardware interrupt service routine activates on rising edge.
When an interrupt is received, it triggers a little LED blinking procedure just for demonstration purposes.

Once the ATtiny is programmed, the Arduino Uno ISP is detached, and it will run independently.

The ATtiny85 requires 1.8-5.5V to operate. I successfully tested with 3.3V and 5V supplies.

## Construction

![Breadboard](./assets/HardwareInterrupt_bb.jpg?raw=true)

![The Schematic](./assets/HardwareInterrupt_schematic.jpg?raw=true)

![The Build](./assets/HardwareInterrupt_build.jpg?raw=true)

## Credits and References
* [ATtiny85 datasheet](http://www.atmel.com/devices/ATTINY85.aspx)
