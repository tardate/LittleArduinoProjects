# #011 Using the X113647Stepper Library

A standard Stepper-compatible Arduino library that supports half-stepping the 28BYJ-48 unipolar stepper motor with a ULN2003A/X113647 Stepper Motor Driver Board.

![The Build](./assets/X113647StepperLibrary_build.jpg?raw=true)

## Notes

It's common to find the 28BYJ-48 stepper motor and a X113647 Stepper Motor Driver Board in Arduino starter kits.

However documentation is scant and the board is not exactly compatible with the standard Stepper library.
See [LEAP#431 28BYJ-48](../) for more details.

One thing that is not possible for the 28BYJ-48 to do with the standard Stepper library is half-stepping.

The [X113647Stepper library](https://github.com/tardate/X113647Stepper) is a demonstration of a
library that is drop-in compatible with the standard Stepper library, but also supports other modes such as half-stepping.

The library is in a separate GitHub repository.
See the [X113647Stepper repo](https://github.com/tardate/X113647Stepper) for more details.

## Credits and References
* [X113647Stepper library](https://github.com/tardate/X113647Stepper)
