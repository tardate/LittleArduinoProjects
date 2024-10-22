# #559 Slow Glow

A simple slowly-glowing LED effect using a 555 timer.

![Build](./assets/SlowGlow_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/k_ZAax6D6Z4/0.jpg)](https://www.youtube.com/watch?v=k_ZAax6D6Z4)

## Notes

This is a simple circuit that flashes an LED at a fairly slow rate (0.5Hz) with ~50% duty cycle.

A 555 timer provides the oscillation, with
[R1=4.7k, R2=330k and C1=4.7uF](https://visual555.tardate.com/?mode=astable&r1=4.7&r2=330&c=4.7).

The "glow" effect is achieved with a RC filter with time constant (𝛕) of about [103ms](https://www.wolframalpha.com/input/?i=470%CE%A9*220%C2%B5F).

## Construction

![Breadboard](./assets/SlowGlow_bb.jpg?raw=true)

![Schematic](./assets/SlowGlow_schematic.jpg?raw=true)

![Build](./assets/SlowGlow_build.jpg?raw=true)

## Credits and References

* [LM555 datasheet](https://www.futurlec.com/Linear/LM555CM.shtml)
