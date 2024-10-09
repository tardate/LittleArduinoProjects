# #589 Laser Ray

Testing a "laser ray" light and sound effectbased on the 555 timer.

![Build](./assets/LaserRay_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/TO6vUcCDoZk/0.jpg)](https://www.youtube.com/watch?v=TO6vUcCDoZk)

## Notes

This is an old circuit that supposedly produces a "laser ray" effect - sound beats and blinking LED.
It works; nothing to write home about though!

## Construction

An 8Ω speaker can be directly attached to C2, however for this build I've attached a piezo buzzer (J1) with biasing resistors (R3, R4).

The circuit needs at least 5V to operate. Higher voltages up to ~12V can be used, and the voltage changes the effect.
I've provided two power points:

* micro USB with switch - taps 5V from USB
* JST connector for direct power (bypasses the switch)

![bb](./assets/LaserRay_bb.jpg?raw=true)

![schematic](./assets/LaserRay_schematic.jpg?raw=true)

![bb_build](./assets/LaserRay_bb_build.jpg?raw=true)

## Credits and References

* [LM555 datasheet](https://www.futurlec.com/Linear/LM555CM.shtml)
* [LASER RAY Circuit](https://www.555-timer-circuits.com/laser-ray-sound.html) - 555-timer-circuits
