# #630 Flickering Flame Effect

A flickering fire effect with 3 LEDs and adjustable brightness controlled by an ATtiny85.

![Build](./assets/FlickeringFireEffect_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/n3E-piAeGrw/0.jpg)](https://www.youtube.com/watch?v=n3E-piAeGrw)

## Notes

The circuit demonstrates a flickering flame / fire effect using an ATtiny85.
It provides 3 PWM outputs that can be used to drive a suitable selection of LEDs for the application.

The brightness level is adjustable using a variable resistor. The current level is read using an analog input.
This is optional if a fixed brightness is satisfactory, and the code can be simplified accordingly.

The code is written to be compatible with an ATtiny, however it can be used with any Arduino provided the appropriate pins are selected.

### Circuit Design

Key points:

* a 100kΩ pot provides the variable brightness control.
* C1 and C2 stabilise the power supply. They are not really necessary for the LEDs used in the demo, but will protect the microprocessor if higher load LEDs are used
* the PWM outputs are used to control low-side n-channel FETs rather than directly drive the LEDs. This ensures that current load on the ATtiny85 does not exceed limits (10mA per pin, 60mA total).
* the LEDs and accompanying current-limiting resistors are just for demonstration purposes - these can be changed as required for a particular application.

![bb](./assets/FlickeringFireEffect_bb.jpg?raw=true)

![schematic](./assets/FlickeringFireEffect_schematic.jpg?raw=true)

### Code Organisation

The main script [FlickeringFireEffect.ino](./FlickeringFireEffect.ino) runs the main loop. It uses two support classes to orchestrate the effect:

* `level_control.h`/`level_control.cpp` encapsulates reading the brightness input.
* `flame.h`/`flame.cpp` implements the flickering algorithm for a single flame (PWM output).
    * on each update it adjusts the flames brightness
    * the maximum change per update is set by the brightness input
    * the actual change in brightness is determined by the `mix` value for each flame. This sets the percentage of the new value that is mixed with the old value. Lower values will mean more slowly changing updates

## Credits and References

* [ATtiny85 datasheet](https://www.microchip.com/en-us/product/ATTINY85)
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* [Realistic Flickering Flame Effect With Arduino and LED's](https://www.instructables.com/Realistic-Fire-Effect-with-Arduino-and-LEDs/)
* [Simple flickering flame effect class for Arduino](https://github.com/micromouseonline/flickering-flame#readme)
* [Using an Arduino Uno for a flickering/flame Effect on 17 3mm LEDs](https://forum.arduino.cc/t/using-an-arduino-uno-for-a-flickering-flame-effect-on-17-3mm-leds/1002442)
