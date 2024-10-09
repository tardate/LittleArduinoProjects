# #409 The Bouncy Thief LED Blinking Machine

A totally Rube-Goldberg contraption for blinking an LED with a AAA battery, homopolar motor and joule thief mechanisms.

![HomopolarJouleThiefBlinky_build](./assets/HomopolarJouleThiefBlinky_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/tx0jU6hgwhY/0.jpg)](https://www.youtube.com/watch?v=tx0jU6hgwhY)

## Notes

Here's a marriage of Homopolar motor and Joule thief that results in a truly impractical Rube-Goldberg mechanism for blinking an LED with a AAA battery.
It may be inefficient, but I like it .. mainly because I haven't seen any quite similar before!

Where did this come from? I stumbled upon the amazing "World's Simplest Electric Train" video posted by 君AmazingScience yesterday and was playing around with some copper wire
to reproduce the effect:

[![clip](https://img.youtube.com/vi/J9b0J29OzAU/0.jpg)](https://www.youtube.com/watch?v=J9b0J29OzAU)

Wayne Schmidt provides a good explanation in his [How to Build the Simplest Electric Train](https://www.youtube.com/watch?v=BWW4kPjd4yc) video.

The concept is pretty clearly derivative of [HomopolarMotor](../HomopolarMotor) concepts
and in fact was thoroughly explored in the [January 2016 issue of American Journal of Physics](https://physics.stackexchange.com/questions/150033/how-does-this-simple-electric-train-work).

After some fiddling around, I ended up with a vertically-mounted demonstration that produced a nice bouncing spring...
which immediately got me thinking about the collapsing electromegnetic field on each bounce, and how that reminded me of
what is going on in a [Joule Thief](../Electronics101/ToroidJouleThief).

Seems like this might suit the
[MacroFab Design Contest: Blink an LED Sponsored by Mouser Electronics](https://macrofab.com/blog/macrofab-design-contest-blink-an-led-sponsored-by-mouser-electronics/).
See the project I've submitted over on [hackaday.io](https://hackaday.io/project/160409).

PS: This is cool! Got a mention on [MEP#133](https://macrofab.com/blog/mep-ep-133-tales-electrical-engineer-ideas-mechanical-design/)

## The Design

Quite a simple arrangement of two subsystems:

* the battery, magnets and coil are arranged as a bouncy homopolar motor
* a diode and capacitor attached to the coil harvest the flyback energy to power the LED

The charge pump/joule thief element of the circuit enables the LED to be powered from the 1.5V AAA source, even though the LED forward voltage is higher.
The minimum forward voltages of the LEDs I've been using are as follows:

* white LED Vf ~2.6V
* red LED Vf ~1.8V

Here's a sketch of my design:

![design_notes](./assets/design_notes.jpg?raw=true)


There are only four electrical components required for this circuit:

* 1N5819HW Schottky Diode - selected for low forward voltage. Something like Mouser [621-1N5819HW-F](https://www.mouser.sg/ProductDetail/Diodes-Incorporated/1N5819HW-7-F?qs=sGAEpiMZZMuHSyTciuLGfz7QlcwO2TN6)
* a white LED 0805 package - something like Mouser [630-HSMW-C170-U0000](https://www.mouser.com/ProductDetail/Broadcom-Avago/HSMW-C170-U0000?qs=sGAEpiMZZMseGfSY3csMkUxhMwy8qEyRYICFXW4fSeAq4RjjHoIC9A%3d%3d)
* 10µF electrolytic capacitor - something like Mouser [661-EKXF251ELL100MJC](https://www.mouser.com/ProductDetail/United-Chemi-Con/EKXF251ELL100MJC5S?qs=sGAEpiMZZMsh%252b1woXyUXj1Qqd7OcgYbMwyirPCNM5Cg%3d)
* AAA battery

Hardware and additional components required:
* some neodymium magnets (I'm not sure of the formulation of the ones I have - they are strong, but not the strongest)
* copper wire for the coil
* some fine gauge hookup/magnet wire to tap the bottom of the coil to the diode

I made a second with a red LED and a 100nF ceramic capacitor:

![HomopolarJouleThiefBlinky_build_pair](./assets/HomopolarJouleThiefBlinky_build_pair.jpg?raw=true)

Here's a video of them in action:

[![clip](https://img.youtube.com/vi/8iEO_NgvEL8/0.jpg)](https://www.youtube.com/watch?v=8iEO_NgvEL8)

![HomopolarJouleThiefBlinky_in_action2](./assets/HomopolarJouleThiefBlinky_in_action2.jpg?raw=true)


## How It Works

We basically have a chain of energy transformations. Totally ineffiecient, but it works! Here's my short explanation:

* Chemical -> EM transformation:
    * When the coil is in contact with the magents on each pole of the battery, we have a dead short that establishes an electromagnetic field in the coil (inductor)
* EM -> Kinetic:
    * Given the orientation of the coil, the polarity of the magnets and the direction of the current, the EM field produces a force that "bounces" the coil up and breaks the circuit
* EM -> Electric Charge
    * As the EM field collapses, a flyback current is generated. This passes via D1 and builds up a charge in C1 (a "charge pump" effect)
* Current -> Light
    * When the voltage across C1 exceeds the forward voltage of the LED, current will flow and the LED will blink on.

Note there is no current-limiting resistor for the LED. This probably exposes the LED to higher voltages than is desirable, but so far no blow-outs!
If there were, a resistor in series would assist in sinking excess voltage.

The frequency and on-time duty cycle of the blinking LED is pretty chaotic and largely depends on the frequency and stability of the spring oscillations
that are generated.

## Construction

Here's the schematic of the charge pump/LED circuit:

![Schematic](./assets/HomopolarJouleThiefBlinky_schematic.jpg?raw=true)

![HomopolarJouleThiefBlinky_build](./assets/HomopolarJouleThiefBlinky_build.jpg?raw=true)

## Credits and References

* [LEAP#203 HomopolarMotor](../HomopolarMotor)
* [LEAP#137 Joule Thief](../Electronics101/ToroidJouleThief)
* [..as mentioned on my blog](https://blog.tardate.com/2018/08/leap410-rube-goldberg-led-blinking-machine.html)
* [..as posted on hackady.io](https://hackaday.io/project/160409-homopolar-motor-joule-thief-led-blinking-machine)
