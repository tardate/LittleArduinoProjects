# #606 CD4049 Relaxation Oscillator

Testing a simple relaxation oscillator using the CD4049 hex inverter with an RC network.

![Build](./assets/RelaxationOscillator_build.jpg?raw=true)

## Notes

The [CD4049](https://www.futurlec.com/4000Series/CD4049.shtml) is a hex inverter buffer/driver with the ability to operate over a wide voltage range of 3V to 15V. Unlike standard inverters, it can provide higher output drive capability, making it suitable for interfacing between different logic families and driving capacitive or resistive loads. It features symmetrical output rise and fall times, low power consumption, and high noise immunity. The CD4049 is often used in logic level shifting, waveform generation, and simple amplification applications, especially where standard logic gates do not provide sufficient drive strength.

### Circuit Design

This relaxation oscillator uses two inverters with an RC network to slow down the state changes.

The frequency is determined by the RC time constant,
and in the Inverter/NAND Gate Waveform configuration can be estimated as `f = 1 / (2.2 * R1 * C)`. R2 should be approximately 10 times R1.

With R1=6.8kΩ and C=100nF, the expected frequency is [668.4 Hz](https://www.wolframalpha.com/input?i=1%2F%282.2*6.8k%CE%A9*100nF%29).

A final inverter is chained to buffer the output. An indicator LED is included in the circuit

![bb](./assets/RelaxationOscillator_bb.jpg?raw=true)

![schematic](./assets/RelaxationOscillator_schematic.jpg?raw=true)

![bb_build](./assets/RelaxationOscillator_bb_build.jpg?raw=true)

### Test Result

Running on a breadboard, I am getting a result close to predicted: 610 Hz at 43.2% +duty cycle.

The scope trace shows CH1 connected to OUT.

![scope_6k8_100n](./assets/scope_6k8_100n.gif?raw=true)

## Credits and References

* [CD4049 datasheet](https://www.futurlec.com/4000Series/CD4049.shtml)
* [Relaxation oscillator](https://en.wikipedia.org/wiki/Relaxation_oscillator)
* [Inverter-based RC oscillator and its waveform](https://www.researchgate.net/figure/nverter-based-RC-oscillator-and-its-waveform_fig1_337297970)
* [Waveform Generators](https://www.electronics-tutorials.ws/waveforms/generators.html)
* See also:
    * [LEAP#590 74HC04 Relaxation Oscillator](https://leap.tardate.com/electronics101/74hc04/relaxationoscillator/)
