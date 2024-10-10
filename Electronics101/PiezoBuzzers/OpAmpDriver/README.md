# #583 OpAmp Piezo Driver

Testing a circuit for driving a piezoelectric transducer for sound output with a TL072 opamp oscillator.

![Build](./assets/OpAmpDriver_build.jpg?raw=true)

## Notes

As discussed in [LEAP#455 Piezo Transducers and Buzzers](./..), piezoelectric transducer
require an external oscillator to produce sound.

This is an example of an OpAmp driver:

* comparator-based relaxation oscillator implemented with one OpAmp from a TL072
* 2N7000 switch to enable the oscillator
* driving a [passive buzzer element](https://www.aliexpress.com/item/32913849609.html)

NB: I have seen silimar circuits with an NPN BJT switch but some of these don't seem to turn the oscillator hard enough off.

## Construction

![Breadboard](./assets/OpAmpDriver_bb.jpg?raw=true)

![Schematic](./assets/OpAmpDriver_schematic.jpg?raw=true)

![Build](./assets/OpAmpDriver_build.jpg?raw=true)

## Results

Works fine - emits a constant tone when the button is pressed.

A crude estimate just considering the 20kΩ and 10nF RC path suggest a frequncy [~796 Hz](https://www.wolframalpha.com/input/?i=1%2F%282%CF%80+*+20k%CE%A9+*+10nF%29). Actually 844Hz acording to the scope..

![output](./assets/output.gif?raw=true)

## Credits and References

* [TL072CP datasheet](https://www.futurlec.com/Linear/TL072CP.shtml)
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* [Piezo Passive Buzzer Element](https://www.aliexpress.com/item/32913849609.html) - example from aliexpress
