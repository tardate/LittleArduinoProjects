# #356 AudioEffectsChips/PX088A

Figuring out how to use the PX088A "Für Elise" music chip.

![Build](./assets/PX088A_build.jpg?raw=true)

Here's a quick demo...

[![Build](https://img.youtube.com/vi/k8RLe6Krhd0/0.jpg)](https://www.youtube.com/watch?v=k8RLe6Krhd0)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The PX088A potted music chip is usually listed as something like
"Alice Music Voice Module Tone Loop Control IC Chip Board for DIY/Toy 3V-4.5V".

Turns out it plays the main theme from Beethoven's Für Elise.

![PX088A_chip](./assets/PX088A_chip.jpg?raw=true)

## Usage and Schematic

This is one of the simpler chips to control, as it only has a single effect.
But as with all these potted music chips, information is scarce and ofter wrong or misleading!

There are 5 connectors:

* VCC: some sources indicate a working voltage of 3 to 4.5V. It actually works down to 1V (although volume suffers)
* "T": apparently a tone switch?
* C: transistor collector and signal out
* B: transistor base
* E/GND: transistor emitter/ground

The documentation I have found (listed on some sellers' aliexpress pages) indicates the music chip should be used with:

* 3-4.5V battery
* a small signal NPN transistor e.g. S8050
* a speaker or buzzer of some description

The picture below shows 3 (of many possible) configurations:

* A: the "recommended" configuration. I found this to be totally unsuitable for an 8Ω speaker: it presents a very low resistance to the battery and draws as much current as it can, and smits a continuous tone. Bad!
* B: adding a 22Ω resistor tames the circuit. This works.
* C: this wierd configuration also works without needing a resistor.

In all cases, the "T" (tone?) button has little if any effect. I think I can discern a slight tone shift, but it is minimal.

![PX088A_schematic](./assets/PX088A_schematic.jpg?raw=true)

## Test Board

Thinking I might use a common board for a few different chips, I laid out a version of configuration "B" Manhattan-style on PCB stock.

![PX088A_test_board](./assets/PX088A_test_board.jpg?raw=true)

### Demos

Here's a quick demo of configuration "B":

[![Build](https://img.youtube.com/vi/k8RLe6Krhd0/0.jpg)](https://www.youtube.com/watch?v=k8RLe6Krhd0)

And alternative configuration "C" for comparison:

[![Build](https://img.youtube.com/vi/LwAlxbyrHlE/0.jpg)](https://www.youtube.com/watch?v=LwAlxbyrHlE)


## Credits and References
* [Alice Music Voice Module Tone Loop Control IC Chip Board for DIY/Toy 3V-4.5V](https://www.aliexpress.com/item/10PCS-PX088-Alice-Music-Voice-Module-Tone-Loop-Control-IC-Chip-Board-High-Songs-3V-4/32821795206.html) - seller on aliexpress
* [S8050 Datasheet](http://electronics.se-ed.com/magic/s8050.pdf) - NPN BJT
* [Für Elise](https://en.wikipedia.org/wiki/F%C3%BCr_Elise)
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap356-px088a-music-chip.html)
