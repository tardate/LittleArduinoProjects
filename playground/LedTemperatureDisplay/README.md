# LedTemperatureDisplay

Measure ambient temperature and display with a 4-digit 7-segment LED unit

![The Build](./assets/LedTemperatureDisplay_demo.jpg?raw=true)

## Notes

This circuit uses an LM35 Precision Centigrade Temperature Sensor to measure ambient temperature,
and display the result on a 4-digit 7-segment LED unit.

The LM35 is incredibly easy to use, especially for working in centigrade.
It provides a linear 10.0 mV/degree output for an operating range of -55°C to 150°C.
So for example, 250mV is 25°C. How easy is that?

The LM35 output is read with an analog input which has an analog to digital resolution of only 1024 levels (0-1023).
So with the default 5V reference voltage that means [4.88mv](http://www.wolframalpha.com/input/?i=5000%2F1024)
per step. That's reduced the LM35 to having a resolution of only 0.5°C. Not so good.

As suggested in [this article](http://playground.arduino.cc/Main/LM35HigherResolution) and elsewhere,
an easy improvement is to change the [Arduino voltage reference](http://www.arduino.cc/en/Reference/AnalogReference)
from 5V to 1.1V, which improves our resolution to about [1.07mv](http://www.wolframalpha.com/input/?i=1100%2F1024), or 0.1°C.
That's good enough. Note that by switching to the 1.1V reference, the maximum temperature we can read is 110°C.

Although at this resolution, it doesn't make a great deal of difference, we can expect the actual voltage reference
provided by the Arduino to not be exactly the 5V or 1.1V we select in code.
I will typically measure the actual voltage reference (on the AREF pin) and use that value for calculations rather than the theoretical value.
In this case, my 1.1V reference is actually 1.06V.

### LED Display

See the [Led4Digit7Segment](../Led4Digit7Segment) projects for an investigation of 4-digit 7-segment displays,
how to drive them, and the details of the specific SMA420564 unit used in this test.

While you can wire up each segment pin to a digital out on the Arduino, it soon becomes pretty wasteful of pins.
This project uses an 8-bit shift register to feed segment values and some BJTs to control digit selection.

A 74HC595 is used to shift out the segment values in a block, requiring only 3 pins.

S9013 NPN BJTs are used to switch the sinking of each digit's common cathode connection.
In this circuit, the BJTs are directly controlled with an additional 4 pins.
The S9013 is selected for no other reason than it's a nice reliable small-signal transistor, and some were on hand.
Pretty much any NPN transistor would do.

This circuit puts the current-limiting resistors in series of the common cathode pins.
Which is a bit of an approximation, as current (brightness) varies a little depending on how many LED segments are on.
The better way is to put a resistor on each segment pin. But this was good enough for a simple test.

### Construction

![The Breadboard](./assets/LedTemperatureDisplay_bb.jpg?raw=true)

![The Schematic](./assets/LedTemperatureDisplay_schematic.jpg?raw=true)

![The Build](./assets/LedTemperatureDisplay_build.jpg?raw=true)

## Credits and references
* [LM35 Datasheet](http://www.futurlec.com/Linear/LM35DZ.shtml)
* [74HC595 Datasheet](http://www.futurlec.com/74HC/74HC595.shtml)
* [S9013 Datasheet](http://www.futurlec.com/Transistors/S9013.shtml)
* [KW4-561 Datasheet](http://www.sme.com.hk/globetec/LED%20Displays/Four%20Digit%20Display/KW4-561.pdf) - not matching the part I have, but a pretty stanrd example
* [Arduino AnalogReference](http://www.arduino.cc/en/Reference/AnalogReference)
* [High-resolution LM35 readings](http://playground.arduino.cc/Main/LM35HigherResolution)
* [Get Accurate Temperature form LM35 on Arduino - correctly!](https://www.timdejong.nl/blog/get-accurate-temperature-lm35-arduino-correctly)