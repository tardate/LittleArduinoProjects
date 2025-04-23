# #138 BJT Monostable

Test a 2-transistor monostable multivibrator.

Here's a quick video of the circuit in action:

[![BJTMonostable](https://img.youtube.com/vi/UpARBfVGHoU/0.jpg)](https://www.youtube.com/watch?v=UpARBfVGHoU)

## Notes

The stable state:

* Q2 is on, biased through R2
* Q1 is off, since R4 pulls-down the base
* Voltage across C1 is VCC-0.7V, since Q1 collector is non-conducting and Q2 base will be at approximately one diode drop.
* output is "low"

When input pulse received:

* Q1 turns on
* C1 voltage immediately shifted down by ~VCC volts
* this pulls Q2 base negative, turning it off
* output is "high"
* C1 "discharges" via R2 with a time constant of [1000ms](https://www.wolframalpha.com/input/?i=100k%CE%A9*10%C2%B5F)
* output remains high until C1 pulls the base of Q2 high enough to turn it back on and reset the cycle

Increasing C1 or R2 will increase the "on" time accordingly.

## Construction

![Breadboard](./assets/Monostable_bb.jpg?raw=true)

![The Schematic](./assets/Monostable_schematic.jpg?raw=true)

![The Build](./assets/Monostable_build.jpg?raw=true)

## Credits and References

* [Monostable Multivibrator circuit](https://www.electronics-tutorials.ws/waveforms/monostable.html) - circuit and detailed explanation
* [Monostable Multivibrator circuit](https://www.pcbheaven.com/userpages/basic_transistor_circuits/) - another version from pcbheaven
* [S9013 Datasheet](https://www.futurlec.com/Transistors/S9013.shtml)
* [RC time constant](http://en.wikipedia.org/wiki/RC_time_constant)
