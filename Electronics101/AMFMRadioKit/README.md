# #131 AMFMRadioKit

Notes on an AM/FM radio kit build.

## Notes

AM/FM radios are pretty rare these days but I wanted one for checking the behaviour of some RF circuits.
So I got [this kit from a seller on aliexpress](http://www.aliexpress.com/item/Free-Shipping-AM-FM-stereo-AM-radio-kit-DIY-CF210SP-electronic-production-suite/32326761697.html). It's a pretty nice kit - good PCB and no problem with the components - and the finished product works fine.

The kit is designed around 3 core integrated circuits:
* CD7642 one-chip AM radio amp - pretty amazing, seems like all the guts of a 6-transistor superheterodyne stuffed into a TO-92 package.
* CD9088 Monolithic Power FM radio tuner circuit in a 16 pin SMD
* TDA2822 One Watt Stereo Amp IC - although marked as such, the circuit uses an 8-pin DIP which I'm guessing is one half of the chip i.e. mono. But I can't find that datasheet.

Some clarifications/intepretations of the instructions. Yes, its's all in simplified Chinese;-)
* battery leads are connected to pads marked GB+/GB-
* the inductor with ferrite core fits in a plastic mount that slides/clips to the PCB. The leads are soldered to the two pads marked AM. This is the medium wave/AM antenna
* the LED needs to stand-off the PCB to peep through the front casing properly. To get the measurements correct, it's best to solder the LED in place with the PCB resting in the case in its final position.
* I used a bit of flux to first solder the CD9088 SMD in place and avoid bridging the pins, but the PCB is well prepared and all the other components went in without trouble and without any flux assist.

## Construction

![The Schematic](./assets/AMFMRadioKit_schematic.jpg?raw=true)

![The Build](./assets/AMFMRadioKit_build.jpg?raw=true)

![The Build](./assets/AMFMRadioKit_parts.jpg?raw=true)

![The Build - PCB front](./assets/AMFMRadioKit_pcb_build_front.jpg?raw=true)

![The Build - PCB rear](./assets/AMFMRadioKit_pcb_build_rear.jpg?raw=true)

## Credits and References
* [kit from a seller on aliexpress](http://www.aliexpress.com/item/Free-Shipping-AM-FM-stereo-AM-radio-kit-DIY-CF210SP-electronic-production-suite/32326761697.html)
* [CD7642 datasheet](http://www.datasheetarchive.com/CD7642CP-datasheet.html) / [TA7642 datasheet](http://www.futurlec.com/Others/TA7642.shtml)
* [CD9088 datasheet](http://www.datasheetbank.com/CD9088-Datasheet-ETC.html)
* [TDA2822 datasheet](http://www.futurlec.com/Philips/TDA2822.shtml) - the 16-pin stereo version

