# #183 PolarityTester

demonstrate a polarity-testing circuit


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

A simple polarity testing circuit uses a series of inverters.
The input signal is pumped into two parallel chains:
* a single inverter
* a series of two inverters

So, regardless of input polarity, one chain output will be high and the other low.


| input | Single-inverter Output | Dual-inverter Output |
|-------|------------------------|----------------------|
| LOW   | HIGH                   | LOW                  |
| HIGH  | LOW                    | HIGH                 |


The signals are tied together with two reverse-polarity LEDs in series. So one will always be alight when the other is not.
The unlit LED is subject to a reverse voltage equivalent to the forward voltage of the other LED. Most LEDs will handle this without complaint.

## Construction

![Breadboard](./assets/PolarityTester_bb.jpg?raw=true)

![The Schematic](./assets/PolarityTester_schematic.jpg?raw=true)

![The Build](./assets/PolarityTester_build.jpg?raw=true)

## Credits and References
* [CD4069 datasheet](https://www.futurlec.com/4000Series/CD4069.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2016/02/littlearduinoprojects183-polarity.html)


