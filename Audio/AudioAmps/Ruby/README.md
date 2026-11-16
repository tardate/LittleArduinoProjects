# #104 Ruby Guitar Amp

A version of the runoffgroove Ruby LM386 guitar amp.

![The Build](./assets/Ruby_build.jpg?raw=true)

## Notes

The Ruby amp is similar to the * [LEAP#095 Little Gem](../LittleGem/), however it introduces a JFET buffer on the input and discrete volume and gain controls for the LM386.

The build here is based on the [runoffgroove schematic](http://www.runoffgroove.com/ruby.html), but with a few variations:

* adds a coupling capacitor on the input
* J201 n-channel JFET instead of the original MPF102

### The LM386

The LM386 is a low-voltage, low-power audio power amplifier integrated circuit, originally developed by National Semiconductor in the mid-1970s. It operates from a single power supply, typically between 4V and 12V, and requires very few external components to produce an audio amplifier with a typical output power of up to 0.5W. Its internally configured voltage gain is 20 (26dB). The chip incorporates internal biasing, thermal protection and a bypass pin for reducing power-supply and bias-related noise. With its low component count, small size and ease of use, the LM386 is widely used in battery-powered audio devices, small radios, intercoms, portable speakers and simple guitar practice amplifiers.

![lm386-ref](../../../Electronics101/LM386/assets/lm386-ref.jpg)

## Circuit Design

Designed with Fritzing: see [Ruby.fzz](./Ruby.fzz).

![Breadboard](./assets/Ruby_bb.jpg?raw=true)

NB: in the schematic below, the FET symbol is not quite correct (shows n-channel MOSFET instead of JFET)

![The Schematic](./assets/Ruby_schematic.jpg?raw=true)

I first tested the amp on a breadboard. It works, but noise and interference can be a problem.

![Ruby_bb_build](./assets/Ruby_bb_build.jpg?raw=true)

## Protoboard Build

I transferred the design to some protoboard. Works really well!

I've left the volume control with a trimpot, as in practice it is not really required if the guitar has a volume control already.

Here's the layout I used:

![Ruby_protoboard_layout](./assets/Ruby_protoboard_layout.jpg?raw=true)

![Ruby_protoboard_build](./assets/Ruby_protoboard_build.jpg?raw=true)

## Credits and References

* [LEAP#095 Little Gem](../LittleGem/)
* [Ruby](http://www.runoffgroove.com/ruby.html) 386-based 9v battery amp
* [LM386 Product Info - TI](https://www.ti.com/product/LM386)
* [LM386 datasheet](https://www.futurlec.com/Linear/LM386N-3.shtml)
* [J201 datasheet](https://www.futurlec.com/Transistors/J201.shtml)
