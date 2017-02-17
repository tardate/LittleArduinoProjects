# #292 AudioEffectsChips/H823

Figuring out how to use the H823 "Happy Birthday" music chip.

[![Build](http://img.youtube.com/vi/RdeabhoCZKI/0.jpg)](http://www.youtube.com/watch?v=RdeabhoCZKI)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The H823 chip arrived in this [CD4060 Dream Music Light DIY Kit](https://www.aliexpress.com/item/CD4060-Dream-Music-Light-DIY-Kit-Birthday-Gift-Suite-Electronic-Production-of-DIY-Parts/32748833397.html) and so far I have been unable to find a source for the H823 chip alone, or indeed anything approximating a datasheet.

Which of course is not unusual for these potted music chips! Figuring them out is half the fun;-)

![H823_chip](./assets/H823_chip.jpg?raw=true)

## Usage and Schematic

This is one of the simpler chips to control. At a minimum it just requires three connections:

* VCC: I'm using 5V, unsure yet what it's upper and lower limits are.
* GND: gound
* OUT: signal out

The signal OUT can be used to directly drive the base of a low-side NPN control of a speaker or piezo buzzer.

There is one further connection on the chip board: after some experimentation, it appears this is a volume control.
Attaching a potentiometer of around 5kΩ (through to ground) allows
a full range volume control (from silent to maximum volume).

![H823_schematic](./assets/H823_schematic.jpg?raw=true)

## Test Board

I laid out a simple circuit on protoboard (without the volume control circuit).
I'm using a salvaged speaker which provides a reasonable clear output -
certainly far better than the piezo buzzer often seen used with these chips in kits.

![H823_layout](./assets/H823_layout.jpg?raw=true)

![H823_build](./assets/H823_build.jpg?raw=true)

## Credits and References
* [CD4060 Dream Music Light DIY Kit](https://www.aliexpress.com/item/CD4060-Dream-Music-Light-DIY-Kit-Birthday-Gift-Suite-Electronic-Production-of-DIY-Parts/32748833397.html) - from a seller on aliexpress
* [LEAP#291: MusicLightKit](../../CD4060/MusicLightKit)
