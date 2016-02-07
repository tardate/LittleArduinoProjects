# #182 PowerSupply317Kit

Build and test a mains-powered 1.25V-12V DC LM317 power supply kit.

## Notes

I found
[this kit](http://www.aliexpress.com/item/EU-US-LM317-1-25V-12V-Continuously-Adjustable-Regulated-Voltage-Power-Supply-DIY-Kit/32463018423.html)
for a reasonable price and decided to give it a go. Some things that attracted me:
* 220V/110V mains-powered
* continuously adjustable output voltage
* isolated output
* nice transparent case
* built-in LED voltmeter

It doesn't have constant-current/current-limit or a current display, which would have been ideal.

The kit and PCB comes with a few "valued-added features" unrelated to the power supply function:
* square wave generator based on a CD4069 oscillator
* piezo buzzer controlled by external input
* external input polarity tester implemented with CD4069

For now I've decided not the implement the "valued-added features" because the CD4069 oscillator is not particularly good and
I've not much use for the buzzer and polarity tester.

This leaves a bit of space in the case and on the PCB, and perhaps I use it to add a current display and/or limiter later..

### Operating Principle

It's quite a standard and straightforward circuit:
* the transformer provides step down from mains to 12V AC fed into a full-wave rectifier
* conventional LM317 linear regulator circuit allowing continuous adjustment using RP1
* smoothing capacitors on the input and output side of the LM317
* input and output short protection (D1/D2)

This style of step-down transformer-based power supply is nice to see in action.
They are becoming a bit of an antique ..
[switch-mode](https://en.wikipedia.org/wiki/Switched-mode_power_supply),
[capacitive](http://en.wikipedia.org/wiki/Capacitive_power_supply) and related buck/boost
circuits are just so much cheaper and compact (no chunky transformer required).

In fact, I have a hard time finding a 220V/12V transformer for sale for less than the cost of this whole kit!
And the ones on offer are usually used or refurbished.


### Specifications

Per the product listing:
* Plug Type: EU / US (optional)
* Input Voltage: 220V(EU) 110V(US)
* Output Voltage: 1.25V-12V Continuously Adjustable
* Power: 2W
* PCB Size: 7.3 * 6.2cm / 2.8 * 2.4in
* Item Weight: 340g / 12oz
* Package Size: 15 * 15 * 5cm / 5.9 * 5.9 * 2in
* Package Weight: 344g / 12.1oz

### How it performs

Nice! No smoke on power-up, but a few things to note and/or improve:

#### Output Voltage Range

The specs say 1.25V-12V but that's not quite true. It depends on the AC supply.
On 240V the maximum output voltage is 15.8V.

#### LED Power Indicator

The blue power indicator LED is connected on the output rail. As a result:
* LED intensity (and current draw) varies with output voltage
* the LED goes off for voltages below the LED forward voltage (about 2.2V for the blue LED supplied)

The voltmeter makes the LED indicator superfluous, so the blue power indicator LED is really just bling.
But I'm not sure if I did the circuit over - I think I would prefer it on the input side of the 317. This would mean:
* LED is always on, regardless of output voltage
* constant brightness/current

#### Safety

While DC output is isolated from the AC input, I think the unit would probably flunk a formal safety certification,
mainly because:
* lacks full double-insulation for a [Class II](https://en.wikipedia.org/wiki/Appliance_classes#Class_II) device
* I can't be sure that it meets the requirement for insulation between mains and every touchable part to withstand flashover voltage of 4240V
* Around the base, the distance between mains voltage carrying parts and touchable parts falls below the "at least 6 mm" threshold
* Holes in the case for DC-side screwdriver-adjustment do not physically prevent access to AC-side components (if you really try)

Also note that the heatsink is "live" with DC output voltage (see the LM317 datasheet).

So while I'm quite happy it's safe enough for a kit built and used in a private (dry) lab, I wouldn't give it away or let anyone else use it;-)


## Construction

### Parts

| Count | Item                              |
|-------|-----------------------------------|
| 1     | [LM317T](http://www.futurlec.com/Linear/LM317T.shtml) 1.5A |
| 4     | 1N4007 rectifier diode            |
| 2     | 1N4148 high-speed diode           |
| 1     | 5kΩ pot with nut                  |
| 1     | 100kΩ trim pot                    |
| 1     | 240Ω 1/4w resistor                |
| 3     | 100kΩ 1/4w resistor               |
| 2     | 10kΩ 1/4w resistor                |
| 4     | 1kΩ                               |
| 1     | 5mm LED red                       |
| 1     | 5mm LED yellow                    |
| 1     | 5mm LED blue                      |
| 1     | 5mm LED green                     |
| 2     | 1000µF electrolytic capacitor 35V |
| 2     | 10µF  electrolytic capacitor 25V  |
| 2     | 100nF ceramic capacitor           |
| 1     | [CD4069](http://www.futurlec.com/4000Series/CD4069.shtml) |
| 1     | DIP-14 socket                     |
| 1     | 3 digit LED voltmeter module DSN-DVM-368 V3.01 |
| 1     | pot knob                          |
| 1     | S9014 NPN BJT                     |
| 1     | piezo buzzer (active)             |
| 1     | heatsink                          |
| 1     | 2 point terminal block            |
| 1     | 3 point terminal block            |
| 1     | PCB with printed silkscreen       |
| 1     | AC power cord                     |
| 1     | AC transformer (D?)B351491 220-12V        |
| 1     | clear acrylic case kit (6 panels) |
| 2     | alligator clips                   |
| 1     | 2-strand wire (power out)         |
| 2     | heatshrink tube                   |
| 12    | 1.5 x 10mm bolt with nut          |
| 8     | 2.5 x 10mm bolt with nut          |
| 1     | 2.5 x 10mm bolt                   |
| 8     | plastic washer/stand-offs         |


### Schematic

![The Schematic](./assets/PowerSupply317Kit_schematic.jpg?raw=true)

### Build

Construction complete (note: excluding the "value-added features")

![The Build](./assets/PowerSupply317Kit_build_complete.jpg?raw=true)

Here's the final unit, set for 5V output:

![The Build](./assets/PowerSupply317Kit_build.jpg?raw=true)

## Credits and References
* [EU/US LM317 1.25V-12V Continuously Adjustable Regulated Voltage Power Supply DIY Kit](http://www.aliexpress.com/item/EU-US-LM317-1-25V-12V-Continuously-Adjustable-Regulated-Voltage-Power-Supply-DIY-Kit/32463018423.html) - my source for the kit built here
* [LM317T datasheet](http://www.futurlec.com/Linear/LM317T.shtml)
* [CD4069 datasheet](http://www.futurlec.com/4000Series/CD4069.shtml)
* [How to protect LM317 from output short?](http://electronics.stackexchange.com/questions/148340/how-to-protect-lm317-from-output-short)
