# #637 CD4069 Logic Probe

A simple logic probe using inverter gates.

![Build](./assets/LogicProbe_build.jpg?raw=true)

## Notes

This is a variation of the [LEAP#636 CD4001 Logic Probe](../../CD4001/LogicProbe) circuit
but using inverter gates instead of NOR gates.
It was
[suggested by Steve Schnepp](https://github.com/tardate/LittleArduinoProjects/issues/29) as he noted that in the original circuit,
most NOR gates were being used as inverters anyway.

This logic probe design can detect and indicate:

* logic high (red LED on)
* logic low (green LED on)
* oscillating signal (yellow LED on)

### About the CD4069

The CD4069UBC is a pack of 6 inverter circuits. Key features:

* operating range (VDD): 3-15V
* monolithic CMOS
* low power TTL compatibility
* all inputs protected by standard CMOS protection circuit; voltage at any pin −0.5V to VDD+0.5V

See the [CD4069 datasheet](https://www.futurlec.com/4000Series/CD4069.shtml) for more.

### Construction

The first inverter (IC1a) is used as a buffer of the input signal.

When LOW input:

* first inverter output will be high
* with high output, D2 (green) on, D1 (red) off

When HIGH input:

* first inverter output will be low
* with low output, D2 (green) off, D1 (red) on

The second inverter (IC1f) feeds a simple RC high-pass filter i.e. edge detector (C1,R4).
This is buffered by IC1e and triggers an LED driven by IC1d; note these could be combined on one inverter.
With an oscillating input, the edge detector will cause D3 (yellow) to flicker at the same frequency (limited by the RC time constant).

![bb](./assets/LogicProbe_bb.jpg?raw=true)

![schematic](./assets/LogicProbe_schematic.jpg?raw=true)

Breadboard test, with logic high input:

![LogicProbe_bb_build_high](./assets/LogicProbe_bb_build_high.jpg?raw=true)

Breadboard test, with logic low input:

![LogicProbe_bb_build_low](./assets/LogicProbe_bb_build_low.jpg?raw=true)

Breadboard test, with oscillating input (500Hz square wave from FY3200S signal generator):

![LogicProbe_bb_build_osc](./assets/LogicProbe_bb_build_osc.jpg?raw=true)

Scope trace showing CH1 input (IC1 pin 1) and CH2 output (IC1 pin 8):

![scope_500hz](./assets/scope_500hz.jpg?raw=true)

### Circuit Simulation

Follow the link to see the simulation create by [Steve Schnepp](https://github.com/steveschnepp) for this circuit concept:

[![simulation](./assets/simulation.jpg?raw=true)](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l5AWAnC1b0DYQHZobEtgBwCsGJ2ATIZBSAliSCZMwKYC0YYAUAO7NsWSlRAZKCECMpQeYcWIngkM8ZOlSQAEzYAzAIYBXADYAXDsbZbwUWzEi95qpRrUgAzJVYydBk+ctrVghWe14AJ0VJAmdoyiJbMHgeSLdPVjSiSWDkgTcwePpPcELIHgBzKI8sqoQ4Ox4AJSKZAoSEYqJQ2zrmOyhoEib6JGFRBAQEjW96KUG5plDBngBjEC7vUSyp0WDYeAPDuDBObBAuaCR3FGJsKiSC92wQ-fgI9cnqyW2pXfAjuQKJK9ShKYGbGQ+PRGMwWKw2EIDBz8KptHBeEoJMoCKjBQo-NHY5gYbxkYkQ2QCMgU6lSIhYlG0jQUMYyIkkApSXocyG7Rmc5mc9yISnMAXjUa-NnDJlKWkxfrc-owIaVWnpckedxYUI8XRiyHcklc1judzgeb2Sh6g0eEXqkXFMCW2DW-XYbV2yTESTC32tF2QN04T0SVg+k1ai2LV0VHA1DURs062TNCOg701BXdJXdFUoj2snAi6YF0O9QtS0Xprb1Us4moadP06uNsk16X6pATL0gFAyP0eAMxoM27vqXr9yNm6NI62VKcaxee3XNKcZvsqZRsnqsRZ2ZYCcdVoiS+t9nsaY+DonHsMX9R8o9bjRJSA7aXP3kydct28vsl1yfEMi0rG8Un+Xo0XBKQlByOA41PLANSQrUUzKaxUJQs9RChPwzBRVCNB+UtMJwmQiJcbRoX8YZKO+SVs13Po82WAAjdYiAHEgmAeXiiB1FE3CbEtgIJQoYMJFE3w-SCKTKSofncGofjqPMeA454kA8EhzS6aIajKDjkASdxdOYIhzTAQyeAAe3ACB5A8EpqD3JFjlsPTbFMuyHPAFMwA6J5zXsDzQs8IgwG1SgMFPLp4gQIRbFaCB3B4ZT1hAAAxVLkvqLhsvCNgAEdDDYAA7FYAE8eCAA)

## Credits and References

* [CD4069 datasheet](https://www.futurlec.com/4000Series/CD4069.shtml)
* [LEAP#636 CD4001 Logic Probe](../../CD4001/LogicProbe)
* [CD4001/LogicProbe Improvement using CD4069UB](https://github.com/tardate/LittleArduinoProjects/issues/29) - suggestion from [Steve Schnepp](https://github.com/steveschnepp)
* [CD4069/LogicProbe Another Improvement and some explanations](https://github.com/tardate/LittleArduinoProjects/issues/30) - another suggestion from [Steve Schnepp](https://github.com/steveschnepp)
* [circuit simulation](https://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l5AWAnC1b0DYQHZobEtgBwCsGJ2ATIZBSAliSCZMwKYC0YYAUAO7NsWSlRAZKCECMpQeYcWIngkM8ZOlSQAEzYAzAIYBXADYAXDsbZbwUWzEi95qpRrUgAzJVYydBk+ctrVghWe14AJ0VJAmdoyiJbMHgeSLdPVjSiSWDkgTcwePpPcELIHgBzKI8sqoQ4Ox4AJSKZAoSEYqJQ2zrmOyhoEib6JGFRBAQEjW96KUG5plDBngBjEC7vUSyp0WDYeAPDuDBObBAuaCR3FGJsKiSC92wQ-fgI9cnqyW2pXfAjuQKJK9ShKYGbGQ+PRGMwWKw2EIDBz8KptHBeEoJMoCKjBQo-NHY5gYbxkYkQ2QCMgU6lSIhYlG0jQUMYyIkkApSXocyG7Rmc5mc9yISnMAXjUa-NnDJlKWkxfrc-owIaVWnpckedxYUI8XRiyHcklc1judzgeb2Sh6g0eEXqkXFMCW2DW-XYbV2yTESTC32tF2QN04T0SVg+k1ai2LV0VHA1DURs062TNCOg701BXdJXdFUoj2snAi6YF0O9QtS0Xprb1Us4moadP06uNsk16X6pATL0gFAyP0eAMxoM27vqXr9yNm6NI62VKcaxee3XNKcZvsqZRsnqsRZ2ZYCcdVoiS+t9nsaY+DonHsMX9R8o9bjRJSA7aXP3kydct28vsl1yfEMi0rG8Un+Xo0XBKQlByOA41PLANSQrUUzKaxUJQs9RChPwzBRVCNB+UtMJwmQiJcbRoX8YZKO+SVs13Po82WAAjdYiAHEgmAeXiiB1FE3CbEtgIJQoYMJFE3w-SCKTKSofncGofjqPMeA454kA8EhzS6aIajKDjkASdxdOYIhzTAQyeAAe3ACB5A8EpqD3JFjlsPTbFMuyHPAFMwA6J5zXsDzQs8IgwG1SgMFPLp4gQIRbFaCB3B4ZT1hAAAxVLkvqLhsvCNgAEdDDYAA7FYAE8eCAA)
