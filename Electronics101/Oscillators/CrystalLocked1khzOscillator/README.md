# #486 Crystal-locked 1kHz Oscillator

A 4.096MHz crystal oscillator divided by a CD4060, governing a wien-bridge oscillator to produce buffered sine and square wave outputs locked at 1kHz.

![Build](./assets/CrystalLocked1khzOscillator_build.jpg?raw=true)

## Notes

This circuit is based upon an article by Michael Harvey in
[Silicon Chip 2018-12 p80](http://www.siliconchip.com.au/Issue/2018/December?res=nonflash&page=80). I've made a few changes:

* modified to work from a single +5V supply (no longer needing +/- 12V in addition to 5V)
* some component substitutions:
  * TL074 replaces LF347 op-amp
  * J201 replaces MPF102 JFET
* removed the phase-lock indicator LEDs
  * I'm aligning with an oscilloscope
  * and using the 4th op-amp unit to generate the "half-voltage" virtual ground


## Circuit Schematic

![Schematic](./assets/CrystalLocked1khzOscillator_schematic.jpg?raw=true)

Three key changes were required to get this circuit to work well with a single 5V supply:

* use an op-amp unit to generate/buffer the "half-voltage" virtual ground
* R11 increased to 3kΩ (from 1kΩ), required to provide enough adjutment headroom to lock-on in phase
* R10 increased to 68kΩ (from 47kΩ), to reduce the gain of the Wien-bridge oscillator and prevent clippping of the resulting sine wave


The RC filter in the breadboard build is a bit lose, as I substituted 12kΩ resistors for 15kΩ (due to parts availability),
so the corner frequency is around
[1.326kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80+*+12k%CE%A9+*+10nF)) instead of the desired
[1.061kHz](https://www.wolframalpha.com/input/?i=1%2F(2%CF%80+*+15k%CE%A9+*+10nF)). It works "well enough" but distorts the sine wave somewhat.


## Breadboard Build

![Breadboard](./assets/CrystalLocked1khzOscillator_bb.jpg?raw=true)

![CrystalLocked1khzOscillator_bb_build](./assets/CrystalLocked1khzOscillator_bb_build.jpg?raw=true)

## Breadboard Test Results

I used an oscilloscope to verify the individual subsystems before integration.

First, the 1kHz pulse generator, nicely locked on to 1.00000kHz:

![scope-bb-1khz_po](./assets/scope-bb-1khz_po.gif?raw=true)

Next, the free-running Wien-bridge oscillator showing a natural frequency of around 971Hz:

![scope-bb-wien_fr](./assets/scope-bb-wien_fr.gif?raw=true)

Next, the buffered sine and square wave outputs with the Wien-bridge oscillator running free (not crystal-locked yet):

![scope-bb-out_fr](./assets/scope-bb-out_fr.gif?raw=true)

Finally, crystal-locked and aligned:

* CH1 (Yellow): crystal-oscillaotr pulse out
* CH2 (Blue): buffered sine wave out
* CH3 (Red): buffered square wave out

![scope-bb-locked](./assets/scope-bb-locked.gif?raw=true)

## Protoboard Build

I built the oscillator as a seperate module that plugs into the main circuit but can also be used on a breadboard:

![cxo_mod](./assets/cxo_mod.jpg?raw=true)
![cxo_mod_back](./assets/cxo_mod_back.jpg?raw=true)
![cxo_mod_front](./assets/cxo_mod_front.jpg?raw=true)

Final construction:

![Build](./assets/CrystalLocked1khzOscillator_build.jpg?raw=true)

Oscilloscope capture of the crystal oscillator, showing

* CH1 (Yellow): raw 1kHz pulse
* CH2 (Blue): RC-filter output

![scope-cxo_mod](./assets/scope-cxo_mod.gif?raw=true)

Oscilloscope capture of the final build:

* CH1 (Yellow): raw 1kHz pulse
* CH2 (Blue): square-wave output
* CH3 (Red): sine-wave output

![scope-locked](./assets/scope-locked.gif?raw=true)

Note that the square and sine wave outputs are locked 180 degrees out of phase.
Locking without a phase shift seems to require a bit more work to refine the circuit.
I'm not sure if that was the design intention of the original circuit, but it works well and the outputs can always be inverted to bring in phase.

## Credits and References

* [1kHz crystal-locked sine wave oscillator](http://www.siliconchip.com.au/Issue/2018/December?res=nonflash&page=80) - Silicon Chip 2018-12 p80
* [wien-bridge oscillator](https://en.wikipedia.org/wiki/Wien_bridge_oscillator) - wikipedia
* [J201 datasheet](https://www.futurlec.com/Transistors/J201.shtml)
* [TL074CN datasheet](https://www.futurlec.com/Linear/TL074CN.shtml)
* [LF347N datasheet](https://www.futurlec.com/Linear/LF347N.shtml)
* [CD4060 datasheet](https://www.futurlec.com/4000Series/CD4060.shtml)
