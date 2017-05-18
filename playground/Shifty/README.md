# #041 Shifty

Drive 8 LEDs with 3 pins using a 74HC595 shift register.


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This is a common circuit - appears in most Arduino tutorial series.

I/O pins are finite resource, hence the many techniques to multiplex output. This approach uses a shift register to provide an 8-bit wide output. Shift registers can be chained to provide even more bandwidth.

The 74HC595 is driven using only 3 digital pins:
* latch pin (ST_CP)
* clock pin (SH_CP)
* Data in (DS)

The latch pin is taken low while a new value is loaded. The new value is presented to the shift register output pins when the latch is taken high.

Data is loaded with the clock and data pins. When the clockPin goes from low to high, the shift register reads the state of the data pin.
So to shift out 8 bits we need 8 cycles.
We could do this bit by bit, but in this case we can use the `shiftOut` function to shift out a whole byte in one command.


### Construction

![The Breadboard](./assets/Shifty_bb.jpg?raw=true)

![The Schematic](./assets/Shifty_schematic.jpg?raw=true)

![The Build](./assets/Shifty_build.jpg?raw=true)

## Credits and references
* [74HC595 datasheet](http://www.futurlec.com/74HC/74HC595.shtml)
* Based on the [Arduino ShiftOut](http://arduino.cc/en/tutorial/ShiftOut) example
* [Adafruit Eight LEDs and a Shift Register](https://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds/the-74hc595-shift-register) tutorial
* [Arduino Tutorial #3 - Shift Registers (74HC595)](https://www.youtube.com/watch?v=bqfPZXEuyuc) video by EEEnthusiast
* [Introduction to 74HC595 shift register – controlling 16 LEDs](https://protostack.com.au/2010/05/introduction-to-74hc595-shift-register-controlling-16-leds/) - protostack.com.au
