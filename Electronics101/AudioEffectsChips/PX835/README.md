# #373 AudioEffectsChips/PX835

Figuring out how to use the PX835 "16 Kind of Sound Doorbell Chip" music chip.

![Build](./assets/PX835_build.jpg?raw=true)

Here's a quick demo (if you really want one!)..

[![clip](http://img.youtube.com/vi/57C38rkTg_A/0.jpg)](http://www.youtube.com/watch?v=57C38rkTg_A)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The PX835 music chip is usually listed as something like
"16 Kind of Sound Doorbell Chip Music Voice Module For DIY/Toy".

I obtained it from a seller on aliexpress, but I can't find any current listings for the chip.

The chip runs on 3V, and is silent at power-on, and supports two input push-buttons (pull-up to V+):

* play next/change song
* repeat last song

It apparently supports a "0.5W to 2W" output. With an 8Ω 0.5W speaker, I got best results with a 47Ω resistor in series.

![Schematic](./assets/PX835_schematic.jpg?raw=true)

The sound generated appears to be a PWM tone:

![scope](./assets/scope.gif?raw=true)
