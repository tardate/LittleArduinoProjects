# #197 WienBridgeAudioToneGenerator

A fixed-frequency tone generator based on a Wien Bridge Oscillator

![The Build](./assets/WienBridgeAudioToneGenerator_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I wanted a simple tone generator to provide a test signal for audio projects:

* fixed frequency is OK
* as close to a pure sinusoid as possible
* AC-coupled output
* some gain/attenuation control would be nice

This sounded like a good application for a Wien Bridge Oscillator.

### Wien Bridge Oscillators

A [Wien bridge oscillator](https://en.wikipedia.org/wiki/Wien_bridge_oscillator) is a sinusoidal oscillator
with a resonant frequency of:

    f = 1/(2πRC)

The resonator comprises essentially:
* R-C series High Pass Filter, connected (at the non-inverting input of the opamp) with:
* R-C parallel Low Pass Filter
In other words a Band Pass Filter with a high Q factor at the resonant frequency.

The combined resistance and reactance of the RC circuits results in an average voltage input to the
non-inverting opamp input of 1/3 the upper voltage rail. this is why the opamp needs a gain of 3 in
order ot sustain oscillation.

### Design Decisions

To generate an audio frequency, I've selected R=10kΩ and C=10nF,
for a theoretical resonant frequency of
[1.592kHz](http://www.wolframalpha.com/input/?i=1%2F%282%CF%80*10k%CE%A9*10nF%29).

I'm using a venerable LM324 opamp. It doesn't have great upper and lower limits,
and without stabilisation, this leads to serious clipping. See notes later on diode stabilisation.

The opamp in the oscillator is configured for a gain of just over 3 (100kΩ/47kΩ).

Instead of dual rails, I'm using a single rail supply (tested at 5V and 9V).
One opamp in the LM324 is used to buffer and 100kΩ voltage divider, thus providing a stable "virtual ground"
at Vcc/2 for the oscillator (VGND in the schematic).

A third opamp in the LM324 is used to buffer the oscillator output to avoid any load inpact on the oscillation.

The 4th opamp unit in the LM324 is unused.

### Test Results - Breadboard Build

On a breadboard, the circuit oscillates without trouble, but the frequency (~1.195kHz) is unsurprisingly
quite a bit off the theoretical.

The basic circuit (without diode stabilisation) also gets clipped severely because the LM324 output can't get close enough
to its rails. In these scope traces:

* CH1 - AC-coupled output
* CH2 - DC-coupled non-inverting input
* CH3 - VGND

![no_diode_10nf_5v](./assets/no_diode_10nf_5v.gif?raw=true)

To avoid the clipping, we need the oscillation to stay away from the rails, yet still hit > 3 gain to ensure the
oscillation is sustained. One technique is "diode stabilisation" that effectively clamps the maximum voltage drop
across one resistor in the opamp feedback loop.

After some experimentation, I decided to double up the 1n4148 diodes to squeeze a decent gain out of the circuit
while still avoiding clipping issues. The diodes do distort the waveform however, so although it still looks OK,
it's not a pure sine wave. Here's the breadboard circuit with diode stabilisation:

![dual_diode_10nf_5v](./assets/dual_diode_10nf_5v.gif?raw=true)

That is looking pretty good. Next step was to put the circuit on a proto

### Test Results - Protoboard Build

Once on a protoboard and in a case, the circuit behaviour is even better.
Actual frequency is ~1.574kHz, very close to the theoretical resonant frequency of 1.592kHz.

Here is the output waveform:

![final_build_scope](./assets/final_build_scope.gif?raw=true)

And in the frequency domain we can see the waveform is reasonably clean:

![final_build_scope_fft](./assets/final_build_scope_fft.gif?raw=true)

## Construction

![Breadboard](./assets/WienBridgeAudioToneGenerator_bb.jpg?raw=true)

![The Schematic](./assets/WienBridgeAudioToneGenerator_schematic.jpg?raw=true)

![WienBridgeAudioToneGenerator_bb_build](./assets/WienBridgeAudioToneGenerator_bb_build.jpg?raw=true)


### Putting it in a case

![WienBridgeAudioToneGenerator_pcb_layout](./assets/WienBridgeAudioToneGenerator_pcb_layout.jpg?raw=true)

![WienBridgeAudioToneGenerator_build_wip](./assets/WienBridgeAudioToneGenerator_build_wip.jpg?raw=true)

![The Build](./assets/WienBridgeAudioToneGenerator_build.jpg?raw=true)

## Credits and References
* [The Wien Bridge Oscillator](http://www.electronics-tutorials.ws/oscillator/wien_bridge.html) - electronics-tutorials
* [Wien Bridge Oscillators](http://www.learnabout-electronics.org/Oscillators/osc34.php) - learnabout-electronics
* [Wien bridge oscillator](https://en.wikipedia.org/wiki/Wien_bridge_oscillator) - wikipedia
* [LM324 Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2016/03/littlearduinoprojects197-wien-bridge.html)
