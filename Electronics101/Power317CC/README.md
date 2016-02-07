# #092 Power317CC

A low-power constant current source using the LM317

Here's a quick video of the circuit in action:

[![Power317CC](./assets/Power317CC_build3.jpg?raw=true)](http://www.youtube.com/watch?v=YYR-RNSDh-4)

## Notes

The LM317 is typically used as an adjustable voltage supply as demonstrated in the [Power317](../Power317) project.

But it can also be used as a constant current supply. The details are hiding towards the end of the
application notes in the datasheet, with little explanation.
However [this tutorial on YouTube](https://youtu.be/iuMngik0GR8) does an excellent job of clarifying how it works.

So my intention here is to test a low-power constant current source to drive a variable number of LEDs
with constant brightness.

Let's set the design criteria to be around 2-3mA constant current. That's far from max brightness for an LED, but enough to be definitely on.

Since the 317 will attempt to maintain 1.25V across output to adjustment pins, we therefore select an appropriate value
for R1 such that (by ohms law) we get our desired current.

In my case, it seems 470Ω is a good fit. This should result in a constant current of [2.66mA](http://www.wolframalpha.com/input/?i=1.25V%2F470%CE%A9).

Using some 3mm LEDs that have a forward voltage Vf of about 1.9-2V, that means a 9V supply should handle up to 3 LEDs in series at 2.66mA
before we run out of voltage headroom (VCC - ~2V = 7V).

So how does it work in practice? Pretty much spot on! With 1,2, or 3 LEDs in series, the 317 holds the current at 2.71mA.

Some notes on the circuit:
* The first DIP switch is a master on/off that will light LED1 when on. When off we get 0 current as is expected.
* The second and third DIP switches selectively enable or bypass LED2 and LED3
* The 10μF electrolytic capacitors smooth the power supply and are not really necessary for this circuit

## Construction

![Breadboard](./assets/Power317CC_bb.jpg?raw=true)

![The Schematic](./assets/Power317CC_schematic.jpg?raw=true)

![The Build](./assets/Power317CC_build.jpg?raw=true)

### With 1 LED on
![The Build](./assets/Power317CC_build1.jpg?raw=true)

### With 2 LEDs on
![The Build](./assets/Power317CC_build2.jpg?raw=true)

### With 3 LEDs on
![The Build](./assets/Power317CC_build3.jpg?raw=true)

## Credits and References
* [LM317 datasheet](http://www.futurlec.com/Linear/LM317T.shtml)
* [Laser / LED Driver and Constant Current Source Tutorial!](https://youtu.be/iuMngik0GR8) - excellent video on the subject

