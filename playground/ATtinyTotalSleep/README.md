# ATtinyTotalSleep

Test a total power shutdown with an ATtiny85 processor on a breadboard.

Here's a quick video of the circuit in action:

[![ATtinyTotalSleep](http://img.youtube.com/vi/Id6DoiL4zDo/0.jpg)](http://www.youtube.com/watch?v=Id6DoiL4zDo)

## Notes

The [ATtinySleep](../ATtinySleep) project showed me that even in CPU sleep mode, an ATtiny85 circuit can
still draw something in the order of 238µA.

This project tests a scheme for total power shutdown triggered by the microcontroller itself.
The circuit then draws virtually no current (certainly less than 100µA - the resolution of the ammeter I was using in-circuit).

The trade-off is that the circuit requires an external trigger to wake-up again. Here it uses a push-button.

How it works:
* power is supplied to the ATtiny and other circuit elements through a p-channel MOSFET (I'm using a BS250 here)
* when power is turned on, the 1MΩ resistor charges the 100nF capacitor with a time constant of [100ms](http://www.wolframalpha.com/input/?i=1M%CE%A9*100nF)
* this keeps the FET Vgs negative long enough for the ATtiny to power up and apply a high signal to the base of the NPN transistor
* the NPN collector-emitter conduction holds the FET Vgs negative, and therefore "powered on"
* when the ATtiny wants to power-down, it brings the NPN base low, cutting the collector-emitter channel, and sending the FET Vgs to 0V.
* this turns off the FET and everything is powered down. The current drawn in this state is limited to leakage of the components
* to powerup, the push-button shorts the capacitor, bringing the FET Vgs down and setting the cycle off again

This all seems to work very reliably.

## Construction

![Breadboard](./assets/ATtinyTotalSleep_bb.jpg?raw=true)

![The Schematic](./assets/ATtinyTotalSleep_schematic.jpg?raw=true)

![The Build](./assets/ATtinyTotalSleep_build.jpg?raw=true)

## Credits and References
* [ATtiny85 datasheet](http://www.atmel.com/devices/ATTINY85.aspx)
* [BS250 datasheet](http://www.futurlec.com/Transistors/BS250.shtml)
* [BC547 datasheet](http://www.futurlec.com/Transistors/BC547.shtml)
* [Arduino DigitalPins reference](https://www.arduino.cc/en/Tutorial/DigitalPins)
* [Topic: Circuit for MCU to control its own power on/off](http://forum.arduino.cc/index.php?topic=118504.0) - another approach using a flip-flop
* [Self Shutting Down Arduino](http://letsmakerobots.com/content/self-shutting-down-arduino-or-any-other-microcontroller-matter) - a similar approach, but one that may not work depending on the specific p-channel FET usde.

