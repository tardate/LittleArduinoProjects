# #003 LedChaser

Blinks a series of 12 LEDs in a continuous loop.

![The Build](./assets/LedChaser_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

There seems to a general mis-conception that resistors should be connected to the
anode of a LED: [not true](http://electronics.stackexchange.com/questions/13746/why-does-a-resistor-need-to-be-on-the-anode-of-an-led).

This circuit simplifies things with a single resistor (1k is about right for the LEDs I used) on the common
cathode part of the circuit. That's fine in this case because we're only going to have one LED on at any time.

![The Breadboard Schematic](./assets/LedChaser_bb.jpg?raw=true)

## Credits and References
* Similar to the [Arduino ForLoop example](http://arduino.cc/en/Tutorial/ForLoop)
