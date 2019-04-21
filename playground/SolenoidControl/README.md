# #102 SolenoidControl

Controlling a mini solenoid with an Arduino.

Here's a quick demo of the circuit in action:

[![SolenoidControl](https://img.youtube.com/vi/CDqSoQETEIg/0.jpg)](https://www.youtube.com/watch?v=CDqSoQETEIg)


## Notes

[Solenoids](https://en.wikipedia.org/?title=Solenoid) are useful devices for converting electrical signals and digital logic into
physical movement. Whereas motors provide rotation, solenoids  are usually used for binary control
(valves on or off, locks engaged or free).

So we basically need the Arduino to be a switch. Connecting an Arduino to a solenoid just requires attention to two factors:
* the current (and possibly voltage) required by the solenoid probably exceeds the power an Arduino can directly provide, so we'd use a transistor or FET to switch a higher-power current source
* being electromagenetic devices, solenoids can produce significant [back-EMF](https://en.wikipedia.org/wiki/Counter-electromotive_force) and require a [flyback diode](https://en.wikipedia.org/wiki/Flyback_diode) to proect other components in the circuit

For this circuit, I'm using a mini push-pull solenoid that is rated for 3-12V. The data I have from the
[seller page on aliexpress](https://www.aliexpress.com/item/5pcs-mini-DC3-12V-Push-Pull-Type-Solenoid-Electromagnet-DC-Micro-Solenoid-Free-shipping/32309067252.html) specifies:
* Length: 20.3 MM
* Weight: 12g
* Voltage: DC 3 V, current: 0.08 A
* voltage: 6 V, Current: 0.17 A
* voltage: 9 V, Current: 0.26 A
* Voltage: 12v, current: 0.35 A
* Internal resistance: 32.8 ohm

That kind of makes sense, although I'm not sure why the rated current is a tad under the voltage/resistance calculation.

The switching transsitor used here is the S9013, which is rated for 500mA continuous collector current - sufficient for this application.
A 1N4001 diode provide flyback protection.


## Construction

![Breadboard](./assets/SolenoidControl_bb.jpg?raw=true)

![The Schematic](./assets/SolenoidControl_schematic.jpg?raw=true)

![The Build](./assets/SolenoidControl_build.jpg?raw=true)

## Credits and References
* [8.6. Controlling Solenoids and Relays](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU) - from the Arduino Cookbook
* [Mini push-pull solenoids on aliexpress](https://www.aliexpress.com/item/5pcs-mini-DC3-12V-Push-Pull-Type-Solenoid-Electromagnet-DC-Micro-Solenoid-Free-shipping/32309067252.html) - 3-12V
* [S9013 datasheet](https://www.futurlec.com/Transistors/S9013.shtml)
* [1N4001-1N4007 datasheet](https://www.futurlec.com/Diodes/1N4001.shtml)
