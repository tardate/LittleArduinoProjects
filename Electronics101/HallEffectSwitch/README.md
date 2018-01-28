# #198 HallEffectSwitch

Testing a Hall effect switch.

Here's a quick video of the circuit in action:

[![HallEffectSwitch](http://img.youtube.com/vi/kvyXPPBrkeU/0.jpg)](http://www.youtube.com/watch?v=kvyXPPBrkeU)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Hall-effect sensors generally support one of three modes:
* switch - turn on in the presence of a magnetic field of a specified polarity
* latch - turn on in the presence of a magnetic field, and stay on until exposed to the reverse polarity
* linear sensor - output is proportional to the magnetic field strength

A common use for Hall-effect sensors is to detect and measure rotation.
A good demonstration of this is to sequence a PoV display as demonstrated in
[Great Scott's latest video - HACKED!: Old Fan becomes a POV Display](https://www.youtube.com/watch?v=57carjNxI9A).

The components I have are marked "44E/938" and are nominally compatible with the A3144 or OH3144.
These are switches that turn on when facing a south magnetic polarity.

![44E938](./assets/44E938.jpg?raw=true)

With the beveled-edges and package markings to the front, the pin-outs from left to right are:

Pin | Use
----|-----
1   | VCC
2   | Ground
3   | Open collector output

The chip is rated for continuous output current of 25mA, so that is sufficient to drive an LED (as demonstrated here).
For other switching applications, the output can be used to switch a transistor or pull a microcontroller output low.

Since the chip is configured as open collector, the LED and and current-limiting resistor sink into the output pin (rather than be driven by the output pin).

Testing with some neodymium magnets, I get a strong full-on when the south pole of the magnets are
within 23mm directly to the front of the chip. The output remains on until I pull back to over 40mm.

## Construction

![Breadboard](./assets/HallEffectSwitch_bb.jpg?raw=true)

![The Schematic](./assets/HallEffectSwitch_schematic.jpg?raw=true)

![The Build](./assets/HallEffectSwitch_build.jpg?raw=true)

## Credits and References
* [OH3144 Datasheet](http://www.datasheet4u.com/pdf/OH3144-pdf/950724)
* [A3144 Datasheet](https://e-radionica.com/productdata/A3141.pdf)
* [Basic Hall Effect Sensors 1](https://www.youtube.com/watch?v=9BFdGtvo9JE) - video tutorial by Lewis Loflin
* [Hall_effect_sensor](https://en.wikipedia.org/wiki/Hall_effect_sensor) - wikipedia
* [..as mentioned on my blog](https://blog.tardate.com/2016/04/littlearduinoprojects198-hall-effect.html)