# #370 TS3A5018 Quad SPDT Analog Switch

Testing the TS3A5018 Quad SPDT Analog Switch with a simple 555 timer and Arduino demo.

![Build](./assets/TS3A5018_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/9xpNcJ_0jvI/0.jpg)](https://www.youtube.com/watch?v=9xpNcJ_0jvI)

## Notes

Digital switches seem to be well suited for switching applications that are more complex than can be achieved with a simple FET or BJT,
but in lower power situations than might be more suited to a relay. Particular applications I have in mind are switching amplifier gain stages,
filter gangs, and circuit subsystems.

They are available in a range of pole/throw configuration, and importantly with defined make-before-break or break-before-make behaviour.

I'm testing a TS3A5018 here, which I obtained already populated on a convenient breakout module.

The TS3A5018 is a 1.8 to 3.6V device with four SPDT switches controlled from a single input, and a master active-low enable pin.
It is guaranteed break-before-make (max 58ns).

![TS3A5018_block_diagram](./assets/TS3A5018_block_diagram.png?raw=true)

## Code Example

The [TS3A5018.ino](./TS3A5018.ino) sketch uses two of the switches in a simple demonstration with an Arduino Uno and 555 timer:

* one switch alters the timing capacitor in a 555 astable oscillator, switching the frequency from [1 Hz](https://visual555.tardate.com/?mode=astable&r1=1&r2=300&c=2.2) to  [2.4 Hz](https://visual555.tardate.com/?mode=astable&r1=1&r2=300&c=1)
* another switch changes the LED (color) running on the oscillator output

The TS3A5018 is only rated for 1.8 to 3.6V, so a 3.3V rail is used for the offboard circuit, and simple voltage divider level-shifts the Arduino output pin.

## Construction

Designed with Fritzing: see [TS3A5018.fzz](./TS3A5018.fzz).

![Breadboard](./assets/TS3A5018_bb.jpg?raw=true)

![Schematic](./assets/TS3A5018_schematic.jpg?raw=true)

![Build](./assets/TS3A5018_build.jpg?raw=true)

## Credits and References

* [TS3A5018 Info and Datasheet](http://www.ti.com/product/TS3A5018)
* [TS3A5018 module](https://www.aliexpress.com/item/5pcs-lot-5018-TS3A5018-10R-Quad-SPDT-Analog-Switch/32818493727.html) - from an aliexpress seller
* [..as mentioned on my blog](https://blog.tardate.com/2018/01/leap370-ts3a5018-digital-switch.html)
