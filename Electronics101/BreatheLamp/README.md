# BreatheLamp

Build and test a common LED visual effect circuit.

## Notes

The "Breathing Lamp" is commonly found from sellers on ebay and aliexpress as a cheap parts kit,
for example: [M126 Blue Led 5MM Light LM358 Breathing Lamp Parts Kit](http://www.aliexpress.com/item/M126-Blue-Led-5MM-Light-LM358-Breathing-Lamp-Parts-Kit-DIY-Interesting-Product-Suite/1940760853.html)

So what exactly is a "Breathing Lamp"? That's what I wanted to know! It turns out to be quite prosaic:
the circuit is just an op-amp oscillator controlling the intensity of an array of LEDs.

Most of these kits are based on an identical circuit and use the two op-amps from an LM358. The circuit diagram is published by most sellers.

But at first glance, the way the op-amp oscillator is wired looks a bit strange - so the primary purpose of this build is
to understand how the oscillator is designed.

Note that in this build, I've used 2 quarters of an LM324 op-amp, since I don't have an LM358 on hand.

A sample trace confirms that the two op-amp units are operating as a square wave multivibrator integrated to a triangle wave.
The triangle wave is used to control the LED array (via Q1 BJT). The duty cycle is far from 50%, but this probably enhances the effect.

The lower trace is the square-wave output of the first stage (pin 7),
and the upper trace is the triangle-wave output of the second stage (pin 1).


![processing trace](./assets/processing_trace.png?raw=true)

What's a little confusing is the fact that C1 is performing double-duty in both stages of the oscillator.
I haven't exactly untangled it all in my head yet, but its a curious thing that it works.

From a parts cost and count perspective, I'm not sure there's much advantage in using an op-amp oscillator
over, for example, a [555 timer-based triangle wave generator](../555Timer/TriangleWaveGen).

## Construction

![Breadboard](./assets/BreatheLamp_bb.jpg?raw=true)

![The Schematic](./assets/BreatheLamp_schematic.jpg?raw=true)

![The Build](./assets/BreatheLamp_build.jpg?raw=true)

## Credits and references
* [LM324N Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)
* [LM358N Datasheet](http://www.futurlec.com/Linear/LM358N.shtml)
* [S8050 Datasheet](http://electronics.se-ed.com/magic/s8050.pdf) - NPN BJT, note there are other S8050 transistor datasheets on the web that purport to be PNP
