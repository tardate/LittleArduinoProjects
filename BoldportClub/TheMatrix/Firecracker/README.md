# #312 TheMatrix/Firecracker

A firecracker simulacrum running on the BoldportClub Matrix.

Here's a quick video showing it in action..

[![Build](./assets/Firecracker_build.jpg?raw=true)](http://www.youtube.com/watch?v=0L34ye-Hupc)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I was a bit dubious about the possibility of creating a decent firecracker animation on the 24x5 Matrix display.
The additional PWM settings create another dimension, so the simulacrum is perhaps not so far off the mark.

To light the firecracker, I want to use a real fire of course;-)
Exposing the LM35 to a naked flame is perhaps not such a good idea .. but it is only for a moment - enough to take the temp over 35°C

## Code

The [Firecracker.ino](./Firecracker.ino) sketch instantiates ["Sparklies"](./sparklies.h) which represent individual animation elements.

Doxygen source documentation is available [here](http://leap.tardate.com/BoldportClub/TheMatrix/Firecracker/doc/html/index.html).

## Construction

![Breadboard](./assets/Firecracker_bb.jpg?raw=true)

![Schematic](./assets/Firecracker_schematic.jpg?raw=true)

![Build](./assets/Firecracker_build.jpg?raw=true)

## Credits and References
* [Wire library](https://www.arduino.cc/en/reference/wire)
* [AS1130 datasheet and info](ams.com/eng/Products/Power-Management/LED-Drivers/AS1130)
* [LuckyResistor/LRAS1130](https://github.com/LuckyResistor/LRAS1130) - A library to control the AS1130 LED driver chip.
* [LEAP#299 TheMatrix](../TheMatrix)
* [LM35 Datasheet](http://www.futurlec.com/Linear/LM35DZ.shtml)
* [LEAP#079 LedTemperatureDisplay](../../../playground/LedTemperatureDisplay) - more details on using the LM35 sensor
