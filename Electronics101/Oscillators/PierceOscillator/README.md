# #242 PierceOscillator

Test a Pierce Oscillator made with a minimum of components.

![The Build](./assets/PierceOscillator_build.jpg?raw=true)

## Notes

The Pierce oscillator is named for its inventor, George W. Pierce (1872-1956). It is a derivative of the Colpitts oscillator,
and can be implemented using a minimum of components. Typically: a digital inverter, one resistor, two capacitors, and a quartz crystal.

The circuit I'm testing here is from [KF5OBS](https://www.youtube.com/watch?v=_OsvXQe_l2E). It features:

* BJT in place of the digital inverter
* takes advantage of the base-emitter capacitance to eliminate one capacitor

### Power Consumption

| Supply | Current |
|--------|---------|
| 5V     | 2.6mA   |
| 9V     | 4.4mA   |

## Construction

![Breadboard](./assets/PierceOscillator_bb.jpg?raw=true)

![The Schematic](./assets/PierceOscillator_schematic.jpg?raw=true)

![PierceOscillator_breadboard_build.jpg](./assets/PierceOscillator_breadboard_build.jpg?raw=true)

![PierceOscillator_layout](./assets/PierceOscillator_layout.jpg?raw=true)

### Sample Traces

I've tested with a range of crystals from 3Mhz to 20MHz, all oscillate satisfatorily.
It does not wotk with slower crystals such as 32768Hz.

Here are the measured frequencies for a batch of crystals according to my oscilloscope:

| Marking         | Measured Frequency (MHz) |
|-----------------|--------------------------|
| D368L0I         | 3.6865                   |
| D400048I        | 4.00006                  |
| 4.000           | 4.00036                  |
| D427K0I         | 4.2735                   |
| D427L0I         | 4.2735                   |
| 4.43619 KDSI OE | 4.4356                   |
| D700L0I         | 7.0001                   |
| CL7.023         | 7.0231                   |
| 8.000           | 8.00043                  |
| D10.24L0I       | 10.2409                  |
| 12.000          | 12.0010                  |
| D143L0I         | 14.3197                  |
| D159L0T         | 15.9758                  |
| 16.000          | 16.0023                  |
| 20.000          | 20.0032                  |

An example trace with 7MHz crystal, 9V supply:

![D700L0I](./assets/D700L0I.gif?raw=true)

And 16MHz crystal, 9V supply:

![16.000](./assets/16.000.gif?raw=true)

## Credits and References
* [Pierce oscillator](https://en.wikipedia.org/wiki/Pierce_oscillator) - wikipedia
* [KF5OBS #5: Crystal oscillator frequency pulling](https://www.youtube.com/watch?v=_OsvXQe_l2E)
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/leap242-minimal-pierce-oscillator.html)
