# #104 Ruby Guitar Amp

A version of the runoffgroove Ruby LM386 guitar amp.

![The Build](./assets/Ruby_build.jpg?raw=true)

## Notes

The Ruby amp is similar to the * [LEAP#095 Little Gem](../LittleGem/), however it introduces a JFET buffer on the input and discrete volume and gain controls for the LM386.

![lm386-ref](../../../Electronics101/LM386/assets/lm386-ref.jpg)

The build here is based on the [runoffgroove schematic](http://www.runoffgroove.com/ruby.html), but with a few variations:

* adds a coupling capacitor on the input
* J201 n-channel JFET instead of the original MPF102

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
