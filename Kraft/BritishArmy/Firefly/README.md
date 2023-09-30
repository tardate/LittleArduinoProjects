# #606 Sherman Firefly

Practicing finishing techniques on the Airfix 1:72 Sherman Firefly, then animating the turret with some ATtiny85 magic.

![Build](./assets/Firefly_build.jpg?raw=true)

Here's a demo..

[![clip](https://img.youtube.com/vi/c3XtI6FQ8cQ/0.jpg)](https://www.youtube.com/watch?v=c3XtI6FQ8cQ)

## Notes

I started the kit as a quick build to practice some weathering techniques (it is great for that) but then .. scope creep: animate the turret!

### The Kit

The [Sherman Firefly Vc Airfix No. A02341 1:72](https://www.scalemates.com/kits/airfix-a02341-sherman-firefly-vc--1260489)
is a nice little weekender - can be built in a few hours (depending on options chosen) and then spend as long as one likes finishing it;-)

![kit_parts](./assets/kit_parts.jpg?raw=true)

### Paint

I'm going to base the finish around scheme A from the kit - but without the unconfirmed black camo pattern.
I'll be using this kit as a "finishing techniques" test subject, so everything after the initial base coat will
start to go its own way!

I am using Uncle Night Shift build series on the [Char B1 bis](https://www.youtube.com/watch?v=SQZUtjNQXjg&list=PLdMxG_XHdQUa26CwwqfuoxlOWejD0L-nw)
as a perfect tutorial for the techniques I'll be trying/learning here.

![kit_scheme_a](./assets/kit_scheme_a.jpg?raw=true)

I'm using the Vallejo Model Color equivalents:

| Humbrol | Vallejo                            |
|---------|------------------------------------|
| 155     | 70.887 US Olive Drab               |
| 33      | 70.950 Black                       |
| 53      | 70.863 Gunmetal Grey               |
| 110     | 70.875 Beige Brown                 |

### The Build

I kept the build as simple as possible and went with the pre-molded tracks instead of the link-and-length option also included in the kit.
This saves a lot of time in the build - interested to see if they hold up to final scrutiny.

![build_01](./assets/build_01.jpg?raw=true)

Primed in black so I don't need to worry too much about unpainted nooks and crannies.

![build_02_primed](./assets/build_02_primed.jpg?raw=true)

Made some progress on the finishing - base coat, some color modulation
by mixing degrees of 70.917 Beige, 70.953 Flat Yellow and/or 70.989 Sky Grey.

Panel line highlighting with Tamiya Black Panel Line Accent Color.

![build_03a](./assets/build_03a.jpg?raw=true)

![build_03b](./assets/build_03b.jpg?raw=true)

ready for next round of effects - some oils, dust and chipping

![build_04a](./assets/build_04a.jpg?raw=true)
![build_04b](./assets/build_04b.jpg?raw=true)
![build_04c](./assets/build_04c.jpg?raw=true)

## Time for some Animation

The weathering is going well, but now I'm thinking: how about an animated turret?

### Circuit Design

To be packed inside the body, with only a 5V power supply (through the bottom of the hull):

* [ATtiny85](https://www.microchip.com/en-us/product/ATTINY85) microcontroller, programmed with the [Firefly](./Firefly.ino) sketch
* an electret microphone and [TL072](http://parts.io/detail/12204535/TL072) opamp to amplify the incoming sound
* a resistor/diode pair, used to set the sound threshold voltage to around 0.4V (an input sound above that level will trigger the animation)
* a "firing pin" GPIO out - am still thinking about finding/making a suitable cannon-fire sound effect, however for now it just blinks an LED for diagnostic purposes
* a [Micro Linear Servo GS-1502](https://shopee.sg/2x-1.5g-Digital-Ultra-Micro-Linear-Servo-V-Tail-Function-GS-1502-Left-Right-i.70675888.1608865461), used to rotate the turret

![Breadboard](./assets/Firefly_bb.jpg?raw=true)

![Schematic](./assets/Firefly_schematic.jpg?raw=true)

Testing the circuit on a breadboard:

![Breadboard Build](./assets/Firefly_bb_build.jpg?raw=true)

### About the Program

The ATtiny85 is configured to run at 8MHz, and programmed with the [Firefly](./Firefly.ino) sketch. The sketch:

* sets up an interrupt handler on the analog comparator:
    * when voltage in from the electret microphone goes above the diode-regulated reference voltage of about 0.4V, it triggers the `ANA_COMP_vect`
    * `ANA_COMP_vect` sets a "triggered" flag
* the main look checks for the "triggered" flag, an initiates the animation if fired.
* the animate traverses the turret by driving a linear servo using the [SoftwareServo](https://github.com/ttseng/SoftwareServo) library
    * it provides some "realistic" behaviour by stepping through a series of animation sequences
    * the animations sequences basically define a series of waypoints (degrees of arc) and how fast to traverse to the waypoint (in degrees per increment)
    * it could randomise the animation but I haven't done that yet

### Animated Turret Construction

After confirming the circuit on a breadboard, I transferred to a small piece of protoboard:

![build_05b_module](./assets/build_05b_module.jpg?raw=true)

And inserted into the hull. the power connection is provided by two pins that poke through the bottom of the hull.
Since the circuit runs fine on 5V, I'm using a USB adapter for power over USB cable.

![build_05a_electronics_inside](./assets/build_05a_electronics_inside.jpg?raw=true)

Here's an initial demo, before building a base..

[![clip](https://img.youtube.com/vi/nX1w4FhQlrQ/0.jpg)](https://www.youtube.com/watch?v=nX1w4FhQlrQ)

### A Vignette Base

Laying down the basics on an old ceramic tile. Power connector pin built-in, with USB micro connector at the rear of the hillock:

![build_06a_starting_a_base](./assets/build_06a_starting_a_base.jpg?raw=true)

Finished? I could do with some more foliage but coming up short on materials at the moment.

![build_07a](./assets/build_07a.jpg?raw=true)

## Final Gallery

![build_08a](./assets/build_08a.jpg?raw=true)

![build_08b](./assets/build_08b.jpg?raw=true)

![build_08c](./assets/build_08c.jpg?raw=true)

![build_08d](./assets/build_08d.jpg?raw=true)

Here's a demo of it on the base..

[![clip](https://img.youtube.com/vi/c3XtI6FQ8cQ/0.jpg)](https://www.youtube.com/watch?v=c3XtI6FQ8cQ)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=107359)
* [Sherman Firefly Vc Airfix No. A02341 1:72](https://www.scalemates.com/kits/airfix-a02341-sherman-firefly-vc--1260489) - scalemates
* [A02341 Sherman Firefly](https://uk.airfix.com/products/sherman-firefly-a02341) - airfix page
* [Sherman Firefly](https://en.wikipedia.org/wiki/Sherman_Firefly) - wikipedia
* [The Firefly VC](http://www.theshermantank.com/the-sherman-tank-variant-page-pages-for-each-type-of-sherman-tank/the-firefly-vc/) - theshermantank.com
* [Sherman Firefly](https://www.goodreads.com/book/show/13584144-sherman-firefly) (Osprey New Vanguard #141) by David Fletcher, Tony Bryan (Illustrations)
* [Building and Finishing the Char B1 bis](https://www.youtube.com/watch?v=SQZUtjNQXjg&list=PLdMxG_XHdQUa26CwwqfuoxlOWejD0L-nw) - Uncle Night Shift
* [TL072 datasheet](http://parts.io/detail/12204535/TL072)
* [ATtiny85 datasheet](https://www.microchip.com/en-us/product/ATTINY85)
* [Micro Linear Servo GS-1502](https://shopee.sg/2x-1.5g-Digital-Ultra-Micro-Linear-Servo-V-Tail-Function-GS-1502-Left-Right-i.70675888.1608865461)
