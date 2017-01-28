# #242 PierceOscillator

Test a Pierce Oscillator made with a minimum of components.

![The Build](./assets/PierceOscillator_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

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


### Sample Traces

I've tested with a range of crystals from 1Mhz to 16MHz, all oscillate satisfatorily.

Here's a trace with 7MHz crystal, 9V supply:

![7MHz_9V](./assets/7MHz_9V.gif?raw=true)

And 16MHz crystal, 9V supply:

![16MHz_9V](./assets/16MHz_9V.gif?raw=true)

## Construction

![Breadboard](./assets/PierceOscillator_bb.jpg?raw=true)

![The Schematic](./assets/PierceOscillator_schematic.jpg?raw=true)

![PierceOscillator_breadboard_build.jpg](./assets/PierceOscillator_breadboard_build.jpg?raw=true)

![PierceOscillator_layout](./assets/PierceOscillator_layout.jpg?raw=true)

![PierceOscillator_build](./assets/PierceOscillator_build.jpg?raw=true)

## Credits and References
* [Pierce oscillator](https://en.wikipedia.org/wiki/Pierce_oscillator) - wikipedia
* [KF5OBS #5: Crystal oscillator frequency pulling](https://www.youtube.com/watch?v=_OsvXQe_l2E)
* [..as mentioned on my blog](http://blog.tardate.com/2017/01/leap242-minimal-pierce-oscillator.html)
