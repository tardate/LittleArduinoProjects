# #208 FM/SingleStageTransmitterKit

Build a simple single-stage FM Transmitter Kit

![The Build](./assets/SingleStageTransmitterKit_build.jpg?raw=true)

## Notes

I've been experimenting with FM, and the hardest thing to get right tends to be the hand-wound coils.
So to get a baseline, I picked up a 1-transistor kit during a recent visit to Sim Lim Tower.

The kit is the FK702 by [Future Kit](http://futurekit.com/). It takes the hastle out of getting the LC circuit
right by printing the inductor coil on the PCB (used in conjuction with a trimmer capacitor).


### Power Connections

The PCB includes +9V and GND connectors.

### Optional Transmit-enable switch

The PCB includes connections for an optional transmit switch (not included).
I put a switch in my build.


### Performance

**tl;dr:** Not that great!

With the supplied coil antenna, I don't get much more than a metre range before the signal is lost to noise.

Adding 30cm rabbit ears gives about 5m.

Frequency is quite selective which is good, but stability is a bit all over the place - it will drift and jump over time.

Here's a trace of the signal and FFT when tuned at 83.25MHz:

![scope_signal](./assets/scope_signal.gif?raw=true)

![scope_fft](./assets/scope_fft.gif?raw=true)

## Construction

![Breadboard](./assets/SingleStageTransmitterKit_bb.jpg?raw=true)

![The Schematic](./assets/SingleStageTransmitterKit_schematic.jpg?raw=true)

![The Build](./assets/SingleStageTransmitterKit_build.jpg?raw=true)

## Credits and References
* [FK702: FM WIRELESS MIC 1-STATE](http://futurekit.com/index.php/en/future-kit/radio-frequency-equipment/93-product/future-kit/series-7xx/series-7-fm-wireless-mic/1201-fk702-fm-wireless-mic-1-state.html)
* [name](url)
* [name](url)
* [name](url)

