# #593 Weevil Eye Kit

Building a simple but fun light-sensitive DIY kit, a perfect gift for someone learning to solder.

![Build](./assets/WeevilEyeKit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/Az2TM6Gtp0o/0.jpg)](https://www.youtube.com/watch?v=Az2TM6Gtp0o)

## Notes

I saw this kit on
[aliexpress](https://www.aliexpress.com/item/1005001350039494.html)
for a few dollars, and the nicely designed PCB convinced me to buy a few.

The circuit is simply a pair of light-sensitive LED "eyes". Surprrisingly fun to play with, especially for children.

The circuit is nicely laid out with generous, perfectly prepared pads, so it also makes an ideal kit for learning through-hole soldering.

The kit comes with standard 5mm red LEDs. I replaced these with slow and fast flashing RGB LEDs to spice up the effect.

### The Kit

[![kit_vendor](./assets/kit_vendor.jpg?raw=true)](https://www.aliexpress.com/item/1005001350039494.html)

Packing list:

* 1 x WeevilEye PCB
* 2 x Red LEDs
* 1 x 47k Ohm Resistor
* 1 x Miniature Photocell (LDR)
* 1 x 20mm Coin Cell Battery Holder(Batteries not included)
* 1 x 2N3904 Transistor
* 2 x 220 Ohm Resistors

![kit_parts](./assets/kit_parts.jpg?raw=true)

## Circuit

It is a simple circuit, with the photocell/LDR controlling the low-side NPN transistor:

* when exposed to light, the LDR resistance is lowered pulling the NPN base to ground and cutting the current for the LEDs
* when in darkness, the LDR resistance rises, allowing the 47kΩ to feed base current to the NPN transistor and turning on the LEDs
* how hard the NPN is turned on will be proportional to the ambient light on the LDR

Here's my transcription of the schematic:

![bb](./assets/WeevilEyeKit_bb.jpg?raw=true)

![schematic](./assets/WeevilEyeKit_schematic.jpg?raw=true)

And a simple breadboard verification:

![bb_build](./assets/WeevilEyeKit_bb_build.jpg?raw=true)

## Credits and References

* [LED Tube Module Electronic Diy Kit Electronics Beginner Learn To Solder Fun Kit](https://www.aliexpress.com/item/1005001350039494.html) - example from aliexpress seller
* [50pcs/lot F5 5mm Fast/Slow RGB Flash Red Green Blue Rainbow Multi Color Light Emitting Diode Round LED Full Color DIY](https://www.aliexpress.com/item/32950189409.html) - example from aliexpress seller
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
