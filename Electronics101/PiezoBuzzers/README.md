# #455 PiezoBuzzers

Exploring techniques for driving piezo transducers and buzzer units for audio output.

![Build](./assets/PiezoBuzzers_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/TUH7J-5sV4k/0.jpg)](https://www.youtube.com/watch?v=TUH7J-5sV4k)

## Notes

[Piezoelectric sensors](https://en.wikipedia.org/wiki/Piezoelectric_sensor) for generating sound are commonly found in two form factors:

* a basic diaphragm/disk - can be used as a transducer as well as for sound generation
* a buzzer unit in the familiar plastic cylinder

![PiezoBuzzers](./assets/PiezoBuzzers.jpg?raw=true)


## Driving Piezoelectric Disks

A common circuit for turning a Piezoelectric disk into a buzzer uses a low-side switch.
Plain piezo disks require a bypass resistor to dump the charge (else no sound will be produced).
Additional resistance can be added to limit current and reduce volume.

In the following test circuit, I have a 555 astable oscillator with variable resistor to generate
a pulse from about
[152 Hz](https://visual555.tardate.com/?mode=astable&r1=1&r2=100&c=0.047) to about
[10kHz](https://visual555.tardate.com/?mode=astable&r1=1&r2=1&c=0.047)

The 555 output switched a low-side 2N7000 n-channel FET.

I've selected a 10kΩ bypass resistor. Lower values start to attenuate the output.

A 2.2kΩ series resistor limits current without much impact on volume.

![Breadboard](./assets/PiezoBuzzers_bb.jpg?raw=true)

![Schematic](./assets/PiezoBuzzers_schematic.jpg?raw=true)

![Build](./assets/PiezoBuzzers_build.jpg?raw=true)

## Credits and References
* [Piezoelectric sensor](https://en.wikipedia.org/wiki/Piezoelectric_sensor) - wikipedia
* [Piezoelectric speaker](https://en.wikipedia.org/wiki/Piezoelectric_speaker) - wikipedia
