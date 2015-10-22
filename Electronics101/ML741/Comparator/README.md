# ML741/Comparator

Test a comparator circuit with the ML741 discrete component opamp

## Notes

This is a demonstration of a comparator circuit using the [ML741](../) discrete component opamp.
The general definition of a comparator is to swing output from 0 to 1 based on the comparison of the inverting and non-inverting input:

    Vo = 0, V+ < V-
    Vo = 1, V+ > V-

So far, I've built the ML741 circuit on a breadboard, and the basic comparator test works fine.
With the lower and upper rails at 0V and 8.92V respectively and no output load:
* output swings to 1.21V (low) when non-inverting input (IN+) is below inverting input (IN-)
* output swings to 8.52V (high) when non-inverting input (IN+) is above inverting input (IN-)

For this circuit:
* single rail power supply is used for simplicity i.e. VCC- is connected to ground
* the non-inverting input is set to VCC/2 with a 10kΩ/10kΩ voltage divider.
* the inverting input is from the wiper of a 10kΩ pot wired across the power rails

See below for some more test results comparing the ML741 with a standard 741 chip.

## Construction

![Breadboard](./assets/Comparator_bb.jpg?raw=true)

![The Schematic](./assets/Comparator_schematic.jpg?raw=true)

### Breadboard Build

![The Build](./assets/Comparator_bb_build.jpg?raw=true)

### Protoboard Build

![The Build](./assets/Comparator_build.jpg?raw=true)

## ML741 v "real" 741 Test

Here are some results comparing the behaviour of a standard UA741CN chip with the ML741 (protoboard version).

Setup:
* power is 5V single rail, i.e. V- = GND
* inverting input is fed a ramp wave 2Vpp with 2V DC offset
* non-inverting input fixed at VCC/2 with a 10kΩ/10kΩ voltage divider

Scope connections
* CH1: inverting input
* CH2: output
* CH2: non-inverting input

### At 5kHz

* ML741 output voltage swings are closer to the rails than the UA741CN
* ML741 seems to have slightly better response time
* UA741CN distorting the duty cycle

ML741:
![ML741_5kHz](./assets/ML741_5kHz.gif?raw=true)

UA741CN:
![UA741CN_5kHz](./assets/UA741CN_5kHz.gif?raw=true)

### At 20kHz

* both struggling to keep up
* ML741 still delivering positive output swings, although distorted
* UA741CN distorting the duty cycle to the point that time low is negligible

ML741:
![ML741_20kHz](./assets/ML741_20kHz.gif?raw=true)

UA741CN:
![UA741CN_20kHz](./assets/UA741CN_20kHz.gif?raw=true)


## Credits and References
* [ML741](../) - the ML741 discrete component project
* [LM741 Datasheet](http://www.futurlec.com/Linear/LM741CN.shtml)
* [Comparator](https://en.wikipedia.org/wiki/Comparator) - wikipedia
* [The Op-amp Comparator](http://www.electronics-tutorials.ws/opamp/op-amp-comparator.html) - electronics-tutorials

