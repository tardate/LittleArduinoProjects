# #119 RotaryEncoderModule

Testing a Rotary Encoder module controlling an LED 8x8 display

Here's a quick video of the circuit in action:

[![RotaryEncoderModule](http://img.youtube.com/vi/9sDoqK0cRAA/0.jpg)](http://www.youtube.com/watch?v=9sDoqK0cRAA)

## Notes

In the [RotaryEncoderMethods](../RotaryEncoderMethods) project I determined that the [Rotary library](https://github.com/brianlow/Rotary) was by far the best option for reading a rotary encoder.

This project is similar, but uses a rotary encoder "module" that includes switch functionality. The module I am using
[is this one from seller on aliexpress](http://www.aliexpress.com/item/Rotary-Encoder-Module-for-Arduino-Dropshipping/1989393805.html).
The module has built-in 10kΩ pull-up resistors on the signal lines, and external connections as follows:

| Label   | Use |
|---------|-----|
| CLK     | Trigger rotational read on falling edge |
| DT(DAT) | When CLK triggered, DT pulled low for counter-clockwise, DT pulled high for clockwise |
| SW      | Switch output - pulls the output low when pressed |
| +       | Upper supply rail (5V) |
| GND     | Ground |

Note the CLK/DT nomenclature is just a simplification of the underlying workings of the rotary encoder.
These pins are actually just the regular two quadrature output phases of the encoder.
Treating one as a clock and the other as the direction indicator is a workable analogy though.

This sketch uses the rotary encoder to control the position of a single enabled LED on an 8x8 LED display.
This makes the accuracy of encoder input quite obvious, as it is very easy to single-step the LED position backwards and forwards.

The rotary encoder module includes a switch (press on the encoder shaft). This is hooked up to clear/reset the display.



## Construction

![Breadboard](./assets/RotaryEncoderModule_bb.jpg?raw=true)

![The Schematic](./assets/RotaryEncoderModule_schematic.jpg?raw=true)

![The Build](./assets/RotaryEncoderModule_build.jpg?raw=true)

## Credits and References
* [Rotary Encoder Module](http://www.aliexpress.com/item/Rotary-Encoder-Module-for-Arduino-Dropshipping/1989393805.html) - from seller on aliexpress
* [RotaryEncoderMethods](../RotaryEncoderMethods) - a project to test/find the best method for reading a mini rotary encoder
* [Rotary_encoder](https://en.wikipedia.org/wiki/Rotary_encoder) - wikipedia page

