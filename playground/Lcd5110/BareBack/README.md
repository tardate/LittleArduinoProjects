# #085 Lcd5110/BareBack

Test driving a Nokia 5110 LCD Display with an Arduino and the raw command set

Here's a quick video of the circuit in action:

[![Lcd5110BareBack demo](https://img.youtube.com/vi/nDB-FT9jysI/0.jpg)](https://www.youtube.com/watch?v=nDB-FT9jysI)


## Notes

This quick demo is inspired by Julian Ilett's [tutorial series on YouTube](https://www.youtube.com/watch?v=RAlZ1DHw03g).

It runs a simple demo cycle, including the reading and display of a voltage from the A0 pin.

There are a few commonly-used libraries - [such as ladyada's](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) -
however this sketch uses the instruction set for device directly, as documented in the [PCD8544 datasheet](http://eia.udg.edu/~forest/PCD8544_1.pdf).

A couple of observations:
* it seems different modules have different pin arrangements, so it is important to match the 5110 pins to the Arduino correctly.
* it works fine with 5V logic connections
* with 5V logic connections, there appears to be no need to connect Vcc, it works fine disconnected! In fact, some circuits that "do the right thing" and connect 3.3V supply to Vcc are not behaving as might be execpted. At least with my module, the Vcc is already taken up to 4.2+V by the login pins.

This is the module I'm using:

![Module Front](./assets/N5110_front.jpg?raw=true)

## Construction

![The Breadboard](./assets/BareBack_bb.jpg?raw=true)

![The Schematic](./assets/BareBack_schematic.jpg?raw=true)

![The Build](./assets/BareBack_build.jpg?raw=true)

## Credits and References

* [Philips PCD8544 datasheet](http://eia.udg.edu/~forest/PCD8544_1.pdf)
* [Arduino Nokia 5110 LCD Tutorial #1 - Connecting and Initial Programming](https://www.youtube.com/watch?v=RAlZ1DHw03g)
* [Arduino Nokia 5110 LCD Tutorial #2 - Getting Text on the Display](https://www.youtube.com/watch?v=E6PUa4n2DnA)
* [Arduino Nokia 5110 LCD Tutorial #3 - Live Numerical Data](https://www.youtube.com/watch?v=cwsCxUhHbQM)
* [Nokia 5110 graphics tutorial](https://www.instructables.com/id/Nokia-5110-graphics-tutorial/?ALLSTEPS) - uses the [LCD5110_Graph library](http://www.rinkydinkelectronics.com/download.php?f=LCD5110_Graph.zip)
* [How to use a Nokia 5110 84X48 LCD display with your Arduino](https://www.instructables.com/id/How-to-use-a-Nokia-5110-84X48-LCD-display-with-you/) - using the [AdaFruit library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library)