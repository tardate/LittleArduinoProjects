# #252 555Timer/BipolarLedFlasher

Two-LED flasher with a 555 and minimal components.

![Build](./assets/BipolarLedFlasher_build.jpg?raw=true)

## Notes

I haven't come across a true bipolar LED in a very long time.
This is a veriation of a bi-polar LED flasher circuit that uses two single LEDs.

The [original circuit](http://www.555-timer-circuits.com/bi-polar-led-driver.html)
described how to flash a bipolar LED with a 55 timer chip.
But due to the 220Ω + 220Ω bridge across the power supply, it drew over 20mA.

By replacing the bipolar LED with two LEDs, and spliting the in & out paths, the effect is the same,
but current draw is 25% less (~15mA).


## Construction

![Breadboard](./assets/BipolarLedFlasher_bb.jpg?raw=true)

![Schematic](./assets/BipolarLedFlasher_schematic.jpg?raw=true)

![Build](./assets/BipolarLedFlasher_build.jpg?raw=true)

## Credits and References
* [BI-POLAR LED DRIVER Circuit](http://www.555-timer-circuits.com/bi-polar-led-driver.html) - 555-timer-circuits
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
