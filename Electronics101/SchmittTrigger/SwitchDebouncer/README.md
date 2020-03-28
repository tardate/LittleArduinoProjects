# #537 Schmitt Switch Debouncer

Testing a simple Schmitt Trigger debounce circuit using a 74HC14.

![Build](./assets/SwitchDebouncer_build.jpg?raw=true)

## Notes

The hysteresis of a Schmitt Trigger used in conjunction with a suitable RC filter provides effective switch debouncing:

* the RC time constant for charge/discharge filters most of the switch bounce
* Schmitt Trigger hysteresis can help with ensuring positive on and off transitions

The circuit demonstrated here is based on Experiment #125 from
[ARRL's Hands-On Radio Experiments Volume 3](https://www.goodreads.com/book/show/38899190-arrl-s-hands-on-radio-experiments-volume-3).

## Construction

I've put double-inversion in the circuit; the result is that the LED is normally on, and turns off while the pushbutton is depressed.

Time constants are purposely large:

* on, a function of R2=10kΩ, C1=1µF: [10ms](https://www.wolframalpha.com/input/?i=10k%CE%A9*1%C2%B5F)
* off, a function of R1=100kΩ, C1=1µF: [100ms](https://www.wolframalpha.com/input/?i=100k%CE%A9*1%C2%B5F)

R2 needs to be much less than R1, else pressing the button will not pull down the voltage sufficient to switch the inverter.

![Breadboard](./assets/SwitchDebouncer_bb.jpg?raw=true)

![Schematic](./assets/SwitchDebouncer_schematic.jpg?raw=true)

![Build](./assets/SwitchDebouncer_build.jpg?raw=true)

## Behaviour

The on-off cycle is captured in the following scope trace where

* CH1 (Yellow) - switch output
* CH2 (Blue) - inverter input
* CH3 (Red) - output to LED

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [ARRL's Hands-On Radio Experiments Volume 3](https://www.goodreads.com/book/show/38899190-arrl-s-hands-on-radio-experiments-volume-3) Experiment #125
* [74HC14 Datasheet](https://www.futurlec.com/74HC/74HC14SMD.shtml)
