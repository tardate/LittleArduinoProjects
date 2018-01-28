# #246 CMOSOscillators

Testing a 4-pin CMOS oscillator component.

![Build](./assets/CMOSOscillators_build.jpg?raw=true)



[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

4-pin CMOS oscillators - like the SaRonix NCH060C I'm testing here - contain all the circuitry
necessary to produce an oscillation when voltage is applied.

Internal details are hard to find, but I'm guessing NCH060C is a combination of
crystal resonator with CMOS inverter gate and buffer.


### SaRonix NCH060C Pin Connections

| Pin | Use                       |
|-----|---------------------------|
| 1   | tristate (n/a on the NHC) |
| 7   | GND                       |
| 8   | output                    |
| 14  | +5V                       |

![package_a](./assets/package_a.png?raw=true)


### Tri-state Control

Some oscillators feature "tri-state" control on one pad (the NCH060C does not have this feature).
This effectively inhibits the clock output, and may be used for testing or for master circuit control.

Typical behaviour is as follows:

| Tri-state pin state        |  Output                |
|----------------------------|------------------------|
| no connect or a logic high | Enabled (clocking)     |
| logic low                  | Disabled (no clocking) |


### Performance

According to my oscilloscope, the NCH060C (20MHz) is running at 19.9996MHz - marginal difference that may be as much to do with my scope as the component itself. The signal appears to not be a perfect square wave (but I may be reaching the limits of my scope).

![scope](./assets/scope.gif?raw=true)

## Construction

![Breadboard](./assets/CMOSOscillators_bb.jpg?raw=true)

![Schematic](./assets/CMOSOscillators_schematic.jpg?raw=true)

![Build](./assets/CMOSOscillators_bb_build.jpg?raw=true)

## Credits and References
* [SaRonix NCH060C](http://resume.wizzard.com/w1995/SaRonix/ttl.html#CMOS) - the only good information I've been able to find about this particular oscillator
* [Oscillator FAQ](http://www.ecliptek.com/oscillators/faq/TEN10-001-012_EB52_54C5_Series_TCXO_Oscillator_FAQ.pdf) - useful guide although for another product range
* [Designing Crystal Oscillators with Modern CMOS Gates](http://www.onsemi.com/pub_link/Collateral/AND8053-D.PDF)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap246-cmos-oscillators.html)
