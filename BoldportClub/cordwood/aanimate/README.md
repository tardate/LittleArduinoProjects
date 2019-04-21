# #270 cordwood/aanimate

Run a demo animation using aaronjasso's Cordwood library

Here's a quick video showing it in action..

[![Build](./assets/aanimate_build.jpg?raw=true)](https://www.youtube.com/watch?v=0WyH_XYZ9tg)

## Notes

[The Cordwood library](https://github.com/aaronjasso/Cordwood) by aaronjasso provides a simple interface
to the [BoldportClub cordwood](../). It provides a number of animations.

This is just a quick test.

I'm using [The Cuttle](../../TheCuttle), but any Arduino would do.

Since The Cuttle pins are aligned identically to the ATmega328 pins, the sketch
uses the analog pins for digital out, as they are the only 6 GPIO pins in an unbroken sequence.

See the [ATmega168/328-Arduino Pin Mapping](https://www.arduino.cc/en/Hacking/PinMapping168) for details on mapping the ATmega328 pins to Arduino port names.

## Construction

![Breadboard](./assets/aanimate_bb.jpg?raw=true)

![Schematic](./assets/aanimate_schematic.jpg?raw=true)

![Build](./assets/aanimate_build.jpg?raw=true)

## Credits and References
* [Cordwood on GitHub](https://github.com/aaronjasso/Cordwood) - library by aaronjasso
* [LEAP#269 cordwood](../) - building the BoldportClub cordwood
* [LEAP#266 The Cuttle](../../TheCuttle) - building the BoldportClub Cuttle
* [ATmega168/328-Arduino Pin Mapping](https://www.arduino.cc/en/Hacking/PinMapping168)
* [It showed up in a hackaday article!](http://hackaday.com/2017/03/24/retrotechtacular-tinkertoy-and-cordwood-in-the-pre-ic-era/)
* [..as mentioned on my blog](https://blog.tardate.com/2017/04/leap270-cordwood-aanimations.html)
