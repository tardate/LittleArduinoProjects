# #231 LEDDimmer/CurrentRegulator

Test a current-regulator style LED dimmer circuit.

![CurrentRegulator_build](./assets/CurrentRegulator_build.jpg?raw=true)


## Notes

I'm looking at some alternatives for dimming a 12V LED strip.
This circuit is
[by Jim Keith at electroschematics](http://www.electroschematics.com/9256/led-dimmer-control/).
Rather than using PWM, this circuit controls the current and theoretically should provide
better flicker-free lighting even when dimmed.

### LED Strip Specifications

I'm using this (very) cheap [3014 Led Strip Light](https://www.aliexpress.com/item/5M-60LED-M-Led-Strip-Light-3014-SMD-Fiexble-Light-Non-waterproof-Indoor-Outdoor-Lighting-Holiday/32287328315.html). According to the seller specs:

| Attribute          | Specification                  |
|--------------------|--------------------------------|
| Length             | 5m                             |
| LED Density        | 60 LED/m                       |
| Color              | cold white                     |
| View angle         | 120°                           |
| Working Voltage    | 12V DC                         |
| Power consumption  | 20W, 4W/m, ~67mW/LED           |
| Working Tempreture | -40 to 70°                     |
| Luminous Flux      | 880-1080 Lumens/Meter          |
| Size               | L500cm (5M) x W0.5cm x T0.20cm |
| lifespan           | >100,000 hours                 |


### LED Load and Power Supply

I'm using a 1m length strip for testing. At maximum load, that should be about 4W according to the specs.

Running the LED strip direct from a 12V supply, I actually measure 270mA or [3.24W](https://www.wolframalpha.com/input/?i=12V*270mA).

The 12V/1.5A/18W power supply I'm using is quite adequate for this.

### Dimmer Circuit

The dimmer circuit is essentially a high-gain PNP (NPN + PNP combo) with a 0.25Ω (1Ω x 4 in parallel) shunt resistor.

A 1kΩ pot controls the PNP current. The 1N5819 diode offsets the pot so it has little dead zone yet can still turn the LEDs "off".
The voltage divider necessarily means there's at least 1.1mA leakage even when the LEDs are off.

The PNP control and shunt resistor means there's also ~1.3V knowcked off the supply. So a 12V supply will
never drive the LEDs to max brightness. For my purposes, they are bright enough already.

I'm measuring ~150mA on max brightness with this circuit and a 12V supply so [1.8W](https://www.wolframalpha.com/input/?i=12V*150mA)
power consumption.

At that current, I was able to get away with an A42 NPN (rated for 500mA), but higher currents would need something beefier.


## Construction

![Breadboard](./assets/CurrentRegulator_bb.jpg?raw=true)

![The Schematic](./assets/CurrentRegulator_schematic.jpg?raw=true)

![CurrentRegulator_breadboard_build](./assets/CurrentRegulator_breadboard_build.jpg?raw=true)

Protoboard Layout:

![CurrentRegulator_protoboard_layout](./assets/CurrentRegulator_protoboard_layout.jpg?raw=true)

![CurrentRegulator_protoboard_build](./assets/CurrentRegulator_protoboard_build.jpg?raw=true)

![CurrentRegulator_build](./assets/CurrentRegulator_build.jpg?raw=true)


## Credits and References
* [Current Controlled LED Dimmer](http://www.electroschematics.com/9256/led-dimmer-control/) - Jim Keith, electroschematics
* [5M 60LED/M Led Strip Light 3014 SMD Fiexble Light Non-waterproof Indoor/Outdoor Lighting Holiday Decoration Brighter Than 3528](https://www.aliexpress.com/item/5M-60LED-M-Led-Strip-Light-3014-SMD-Fiexble-Light-Non-waterproof-Indoor-Outdoor-Lighting-Holiday/32287328315.html) - seller on aliexpress
* [1N5819 Datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
* [A42 datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/138719/JIANGSU/A42.html)
* [2N3906 datasheet](https://www.futurlec.com/Transistors/2N3906.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap231-led-dimmer.html)
