# #362 AudioEffectsChips/H83A

Figuring out how to use the H-83A "12 songs" music chip.

![Build](./assets/H83A_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The H-83A is yet another music chip, this time programmed with 12 tunes.
I haven't figured out all the songs, but they sound like classic Chinese folk tunes.

![H83A_chip](./assets/H83A_chip.jpg?raw=true)

## Usage and Schematic

This chip requires very minimal external components:

* push-button switch
* 180kΩ resistor
* speaker (e.g. 8Ω)
* 3-4.5V power

Songs start playing when the switch is pressed. Pressing the switch again will switch tunes.
The song ends after one cycle (i.e. not infinite repeat!)

Volume is very decent without any amplification.

![Schematic](./assets/H83A_schematic.jpg?raw=true)

![Build](./assets/H83A_build.jpg?raw=true)

Here's a demo FWIW. There is a bit of warbling, I think mainly due to imperfect breadboard connections.

[![mdSMwFA3bzw](http://img.youtube.com/vi/mdSMwFA3bzw/0.jpg)](http://www.youtube.com/watch?v=mdSMwFA3bzw)

## Credits and References
* [5PCS 12 Kind of Songs Sound Music IC Voice Chip Module for DIY/Toy Integrated Circuit 3-4.5V](https://www.aliexpress.com/item/5PCS-12-Kind-of-Sound-Music-IC-Voice-Chip-Module-for-DIY-Toy-Integrated-Circuit-3/32658454214.html) - from aliexpress seller
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap362-h-83a-12-song-music-chip.html)
