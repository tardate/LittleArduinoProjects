# #241 AudioAmps/GeneralPurpose358

Test a general-purpose LM358 amplifier circuit.

![Build](./assets/GeneralPurpose358_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I found this [Op-Amp Audio Amplifier circuit](http://www.techlib.com/electronics/audioamps.html#op-amp)
and decided to test it out.

My intention was to house it as a general purpose amplifier for the workbench.
However after testing the performance I think it's perhaps not such a useful circuit.

Two issues I seeing:

* the R8=1MΩ provides ridiculous gain, so most signals over 50mV or so slam to upper/lower output limits (effectively converting any input signal to a square wave)
* the push-pull output stage cannot deliver much power, and the maximum peak-peak range with a 5V supply is about 3.2V, and the output wave is offset down ~1V from the midpoint of this range, leading to early low-side clipping

Here are some scope traces:
* CH1 is the output
* CH2 is the input

With a 200mV 1kHz input signal, the output is severely clipped:

![1kHz_200mV_1M](./assets/1kHz_200mV_1M.gif?raw=true)

Replacing R8 with 31kΩ, I can eliminate clipping:

![1kHz_200mV_31k](./assets/1kHz_200mV_31k.gif?raw=true)


### Variations from the Original Circuit

Some variations in my build based on parts availability:

* [2N4401](http://parts.io/detail/5416234/2N4401) replaced with [2N3904](http://parts.io/detail/5427230/2N3904)
* [2N4403](http://parts.io/detail/5374893/2N4403) replaced with [2N3906](http://parts.io/detail/5348716/2N3906)
* [1N914S](http://parts.io/detail/9136148/1N914S) replaced with [1N4148](http://parts.io/detail/181859216/1N4148)
* 3.3µF C2 replaced with 1µF

## Construction

![Breadboard](./assets/GeneralPurpose358_bb.jpg?raw=true)

![The Schematic](./assets/GeneralPurpose358_schematic.jpg?raw=true)

![Breadboard](./assets/GeneralPurpose358_breadboard_build.jpg?raw=true)

Laid out on a protoboard:

![Build](./assets/GeneralPurpose358_protoboard_layout.jpg?raw=true)

![Build](./assets/GeneralPurpose358_build.jpg?raw=true)

![Build](./assets/GeneralPurpose358_build_rear.jpg?raw=true)

## Credits and References
* [Op-Amp Audio Amplifier](http://www.techlib.com/electronics/audioamps.html#op-amp) - LM358
* [LM358N Datasheet](https://www.futurlec.com/Linear/LM358N.shtml)
* [2N3904](http://parts.io/detail/5427230/2N3904)
* [2N3906](http://parts.io/detail/5427230/2N3904)
* [1N4148](http://parts.io/detail/181859216/1N4148)
* [..as mentioned on my blog](https://leap.tardate.com/2017/01/leap241-general-purpose-358-amplifier.html)
