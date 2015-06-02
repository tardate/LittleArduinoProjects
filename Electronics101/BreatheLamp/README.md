# BreatheLamp

Build and test a common LED visual effect circuit.

## Notes

The "Breathing Lamp" is commonly found from sellers on ebay and aliexpress and a cheap parts kit,
for example: [M126 Blue Led 5MM Light LM358 Breathing Lamp Parts Kit](http://www.aliexpress.com/item/M126-Blue-Led-5MM-Light-LM358-Breathing-Lamp-Parts-Kit-DIY-Interesting-Product-Suite/1940760853.html)

So what exactly is a "Breathing Lamp"? That's what I wanted to know! It turns out to be quite prosaic: this circuit is just an op-amp oscillator controlling the inensity of an array of LEDs.

Most of these kits are based on an identical circuit and use the two op-amps from an LM358. The circuit diagram is published by most sellers.

But at first glance, the way the op-amp oscillator is wired looks a bit strange - so the primary purpose of this build is
to understand how the oscillator is designed.


## Construction

![Breadboard](./assets/BreatheLamp_bb.jpg?raw=true)

![The Schematic](./assets/BreatheLamp_schematic.jpg?raw=true)

![The Build](./assets/BreatheLamp_build.jpg?raw=true)

## Credits and references
* [LM324N Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)
* [LM358N Datasheet](http://www.futurlec.com/Linear/LM358N.shtml)
* [S8050 Datasheet](http://electronics.se-ed.com/magic/s8050.pdf) - NPN BJT, note there are other S8050 transistor datasheets on the web that purport to be PNP
