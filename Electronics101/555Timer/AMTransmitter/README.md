# #132 555 AM Transmitter

A simple 555-based AM transmitter.

![The Build](./assets/AMTransmitter_build.jpg?raw=true)

Here's a quick video of the circuit in action, transmitting [Lullaby/Колыбельная](https://youtu.be/8etPN7Or8ZE) by Аіда Николайчук:

[![555Timer/AMTransmitter](https://img.youtube.com/vi/1QtLAnv1PCg/0.jpg)](https://www.youtube.com/watch?v=1QtLAnv1PCg)

## Notes

There are quite a few circuits (see links below) that use a humble 555 timer chip as a medium-wave transmitter.
Here's my variant. It doesn't get much simpler than this!

The 555 is used to generate a carrier wave, with the pot adjusting the frequency between the
extremes of
[64.8kHz](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=11&c=0.001) and
[648kHz](http://visual555.tardate.com/?mode=astable&r1=0.22&r2=1&c=0.001).
Since R1 is comparatively small compared to R2, the duty cycle is kept close to 50%.

The timer output (pin 3) drives the base of an NPN transistor which switches a signal to nowhere .. or at least just down a length of wire acting as the antenna. I used a BC547, but any small-signal NPN would work.

The audio input modulates the output by wiggling the base voltage around a 10nF capacitor link to ground.

Since the circuit is essentially modulating a square wave, the carrier is not particularly selective and
the result is quite a broadband signal. There's no trouble picking up the signal on an AM radio above and
below the natural and harmonic frequencies. Well, we get a signal, but lots of noise also ... but it does work!

## Construction

![AMTransmitter_bb](./assets/AMTransmitter_bb.jpg?raw=true)

![AMTransmitter_schematic](./assets/AMTransmitter_schematic.jpg?raw=true)

![AMTransmitter_bb_build](./assets/AMTransmitter_bb_build.jpg?raw=true)

## Credits and References

* [My simple 555 AM transmitter circuit](http://soundation.blogspot.sg/2012/04/my-simple-555-based-am-transmitter.html) - Shadi Soundation
* [AM Radio Transmitter Using 555 Chip](http://electronics-diy.com/am-radio-transmitter-using-555-chip.php)
* [555 AM Transmitter](https://www.instructables.com/id/555-AM-Transmitter/)
* [Simple 555 Timer AM Transmitter Schematic for Science Fair Project](http://www.circuitsgallery.com/2013/08/555-AM-transmitter-circuit.html)
* [BC547 datasheet](https://www.futurlec.com/Transistors/BC547.shtml)
* [Lullaby/Колыбельная](https://youtu.be/8etPN7Or8ZE) performed by Аіда Николайчук, originally by Polina Gagarina/Полина Гагарина.
