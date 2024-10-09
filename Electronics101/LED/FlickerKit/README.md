# #631 LED Flicker Kit

A flame or fire emulator driven by an ATtiny85 suitable for use in scale models or displays.

![Build](./assets/FlickerKit_build.jpg?raw=true)

## Notes

It is quite common that I'll want to add fire or flame effects to a scale model build.
This project is a general-purpose solution that could be installed to provide a range of effects
from a raging billowing fire through to gently glowing embers.

I have tried various ways to mimic fire, but one of the most reliable is the one used here:
a simple algorithm implemented in a microcontroller (an ATtiny85 in this case).

### Circuit Design

The controller is implemented in code on an ATtiny85. Some circuit notes:

* the PWM outputs are used to control low-side n-channel FETs rather than directly drive the outputs. This ensures that current load on the ATtiny85 does not exceed limits (10mA per pin, 60mA total).
* the LEDs and accompanying current-limiting resistors are just for demonstration purposes - these can be changed as required for a particular application.
* the flame animation aggressiveness is set with a variable resistor.
* I initially built this to be run from 5V USB but got stumped trying to hide a suitable power supply in the picture frame. Luckily, the circuit also works just fin on 3V (2xAAA) - though I don't know how long the batteries will last.

![bb](./assets/FlickerKit_bb.jpg?raw=true)

![schematic](./assets/FlickerKit_schematic.jpg?raw=true)

Testing on a breadboard:

![bb_build](./assets/FlickerKit_bb_build.jpg?raw=true)

### Code

The code is available in GitHub. It comprises:

* [FlickerKit.ino](./FlickerKit.ino) - main program
* [dial.h](./dial.h) / [dial.cpp](./dial.cpp) - encapsulates the variable resistor input
* [flame.h](./flame.h) / [flame.cpp](./flame.cpp) - flame class, implements the flicker algorithm. Instantiated for each LED output.

### Protoboard Build

After breadboard verification, I put the circuit on a small protoboard.
I've given this one to a fellow modeller.

![protoboard_build](./assets/protoboard_build.jpg?raw=true)

## Credits and References

* [ATtiny85 datasheet](https://www.microchip.com/en-us/product/ATTINY85)
