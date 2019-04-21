# #124 EMRDetection/RFDetectorProbe

A simple RF detector mounted in a pen.

Here's a quick video of the detector in action, probing a 555 astable oscillator running at a few hundred kHz:

[![RFDetectorProbe](https://img.youtube.com/vi/Rr9iLDhYq8k/0.jpg)](https://www.youtube.com/watch?v=Rr9iLDhYq8k)


## Notes

This is a quick build of an RF detector based on the circuit presented
in dazaro3's [RF Pen detector video](https://youtu.be/G7xf_qe8P3k).
The best explanation of how this works is possibly
[w2aew's video](https://youtu.be/C8SKiyJUAlU) concerning a similar circuit.

I used 1N60P diodes, which seem to work fine for my current purposes (medium wave).

Mounted in a pen, the probe makes a pretty effective detector.
Connecting the ground wire to the circuit under test is not absolutely essential for approximate measurements,
but is probably best connected to get more accuracy especially with smaller amplitude signals.

Note there's no switch in the circuit, however the current drawn when no RF detected is negligible - a few µAmps, bascially
the transistor leakage. Still, it would be a good idea to remove the batteries when not in use.

## Construction

![Breadboard](./assets/RFDetectorProbe_bb.jpg?raw=true)

![The Schematic](./assets/RFDetectorProbe_schematic.jpg?raw=true)

### Breadboard Test

... running on 9V with a green LED and 1kΩ current-limiting resistor R1.

![The Build](./assets/RFDetectorProbe_build_breadboard.jpg?raw=true)

### Pen Build

I switched to 3V supply, a super bright white LED (since the pen handily comes with a semi-transparent green casing)
and the current-limiting resistor R1 reduced to 220Ω.

Soldered and ready for assembly..

![The Build](./assets/RFDetectorProbe_build_unassembled.jpg?raw=true)

The finished product..

![The Build](./assets/RFDetectorProbe_build.jpg?raw=true)

## Credits and References
* [Lets build a RF Pen detector](https://youtu.be/G7xf_qe8P3k) - by dazaro3
* [#161: Circuit Fun: a simple RF detector / demodulator probe for DMM or scope](https://youtu.be/C8SKiyJUAlU) - by w2aew
