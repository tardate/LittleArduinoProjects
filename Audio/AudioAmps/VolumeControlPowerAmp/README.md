# #097 Volume Control Power Amp

An LM386 fixed-gain audio power amp with volume control.

![The Build](./assets/VolumeControlPowerAmp_build.jpg?raw=true)

## Notes

This variant in the line of LM386-based amplifiers is based on a design in
[Beginning Analog Electronics through Projects](../../../books/beginning-analog-electronics-through-projects/).

It is similar to the [LEAP#095 Little Gem](../LittleGem/), but with a few differences:

* The LM386 gain is actually fixed at 200x with 10μF C5, with volume control on the input provided by R1.
* it adds a small RF-bypass capacitor C2 to prevent RF-breakthrough of radio signals
* the output coupling capacitor is slightly smaller at 10μF
* additional 100nF low-pass filter on the power supply

How it performs:

* the input volume control works fine, although it is pretty redundant as it is doing the same job as a guitar's onboard volume control
* the RF-bypass capacitor does appear to give a cleaner signal
* the lack of gain control means the overdrive level is fixed. It's a pretty nice and warm effect that cuts in with higher input volumes

### The LM386

The LM386 is a low-voltage, low-power audio power amplifier integrated circuit, originally developed by National Semiconductor in the mid-1970s. It operates from a single power supply, typically between 4V and 12V, and requires very few external components to produce an audio amplifier with a typical output power of up to 0.5W. Its internally configured voltage gain is 20 (26dB). The chip incorporates internal biasing, thermal protection and a bypass pin for reducing power-supply and bias-related noise. With its low component count, small size and ease of use, the LM386 is widely used in battery-powered audio devices, small radios, intercoms, portable speakers and simple guitar practice amplifiers.

![lm386-ref](../../../Electronics101/LM386/assets/lm386-ref.jpg)

## Circuit Design

Designed with Fritzing: see [VolumeControlPowerAmp.fzz](./VolumeControlPowerAmp.fzz).

![Breadboard](./assets/VolumeControlPowerAmp_bb.jpg?raw=true)

![The Schematic](./assets/VolumeControlPowerAmp_schematic.jpg?raw=true)

![The Build](./assets/VolumeControlPowerAmp_build.jpg?raw=true)

## Credits and References

* Based on "Project 05 - Variable-Gain Audio Power Amplifier" from [Beginning Analog Electronics through Projects](../../../books/beginning-analog-electronics-through-projects/)
* [LEAP#095 Little Gem](../LittleGem/)
* [Smokey Amps](https://www.smokeyamps.com/) - official site
* [Smokey Amp Analysis](https://web.archive.org/web/20260518123756/https://electrosmash.com/smokey-amp-analysis) - excellent circuit analysis of the original Smokey amp.
* [Observations on the Smokey circuit by Dave Stork](http://www.blueguitar.org/new/schem/_ss/smokey.txt)
* [LM386 Product Info - TI](https://www.ti.com/product/LM386)
* [LM386 datasheet](https://www.futurlec.com/Linear/LM386N-3.shtml)
