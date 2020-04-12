# #256 Pease

A Bob Pease tribute, LM331 voltage-to-frequency kit from The Boldport Club (Project #1).

Here's a quick demo video to show it works..

[![Build](./assets/Pease_build.jpg?raw=true)](https://www.youtube.com/watch?v=-JQLJ-RI_1A)


## Notes

The Pease is a tribute to the legendary analogue designer Bob Pease.

> 'My favorite programming language is... solder' –Bob Pease

It is another beautiful PCB from the Bolport Club, and is a great
excuse to find out more about the featured chip - the LM331 voltage to frequency converter.

I joined the Boldport Club rather late, and missed out on the original Pease kit (now out of stock).
But I did manage to snaffle the PCB in sale of ["Just Less the Perfect"](http://www.boldport.club/shop/product/437169103) boards.
Sweet!

![Pease_board_front](./assets/Pease_board_front.jpg?raw=true)

### About the LM331

Although the LM331 is used here in its basic voltage-to-frequency converter mode,
it is actually quite a bit more versatile, with applications in:

* Voltage to Frequency Conversions
* Frequency to Voltage Conversions
* Remote-Sensor Monitoring
* Tachometers

See the [LM331 Datasheet](http://www.ti.com/lit/ds/symlink/lm331.pdf) for more.

### Kit Modifications


Since I was kit-less, I decided to experiment a bit. Firstly, I'm using a 20kΩ LDR for input rather than
a phototransistor. Secondly, after testing the original circuit on a breadboard, I decided to slow down the frequency.

* the original runs at hundreds of kHz, so acts like a PWM LED dimmer
* I pulled the operating frequency down to 4-10 Hz, so it visibly blinks

The end result is a light/voltage controlled "blinky". Depending on the potentiometer trim, it will:

* stay "off" in bright light
* start to blink at ~10Hz with a very low duty cycle (~1%) as light levels drop
* blink hard at <7Hz with high duty cycle (50% and over) in dark conditions

The specific component changes (with reference to the schematic below):

| Ref | Original | Replacement | Rationale                                                            |
|-----|----------|-------------|----------------------------------------------------------------------|
| R6  | 330Ω     | 220Ω        | a brighter LED                                                       |
| R1  | 6.81kΩ   | 1MΩ         | massively reduce base frequency                                      |
| C1  | 330pF    | 100nF       | massively reduce base frequency                                      |
| C2  | 1nF      | 1µF         | achieve greater duty cycles at the reduced frequency                 |
| S1  | Vishay BPW96C Phototransistor | 20kΩ LDR  | ..because I didn't have a phototransistor on-hand |

The particular LDR used has a range of about 200Ω (bright light) to 20kΩ (dark).

The component selection means the board works happily from 5-9V.
I repurposed an old mouse USB lead as a 5V USB power supply connector for the board.


### The Build

No unboxing this time - a pity, as the original kit packaging looks really neat.


Testing the circuit on a breadboard to experiment with component values..

![build_breadboard](./assets/build_breadboard.jpg?raw=true)

Final component selection..

![build_components](./assets/build_components.jpg?raw=true)

Build complete, front:

![build_complete_front](./assets/build_complete_front.jpg?raw=true)

Finished, around the back...

* hmm, still trying to get perfectly round globules of solder.
* Hot glue to the rescue for securing the USB power connector. Is that allowed on a Bolport Club kit???!

![build_complete_back](./assets/build_complete_back.jpg?raw=true)

### Performance

Obviously, ambient light conditions and the trim of the pot alter the circuit performance, but here are some scope traces
for roughly "light" and "dark" situations.

#### Bright Light - Original R/C components

High frequency 175kHz; duty cycle ~40%

![scope_original_light](./assets/scope_original_light.gif?raw=true)

#### In Darkness - Original R/C components

Frequency reduced to ~ 30kHz, and duty cycle over 80%..

![scope_original_dark](./assets/scope_original_dark.gif?raw=true)



#### Bright Light - Replacement R/C components

Low frequency 9 Hz, and low duty cycle <5%

![scope_revised_light](./assets/scope_revised_light.gif?raw=true)

#### In Darkness - Replacement R/C components

Frequency reduced to ~4 Hz, and duty cycle over 50%..

![scope_revised_dark](./assets/scope_revised_dark.gif?raw=true)


## Construction

![Breadboard](./assets/Pease_bb.jpg?raw=true)

![Schematic](./assets/Pease_schematic.jpg?raw=true)

![Build](./assets/Pease_build.jpg?raw=true)

## Credits and References

* [Pease](http://www.boldport.club/shop/product/206712811) - in the Boldport shop
* [Pease](http://www.boldport.com/products/pease-second-edition/) - project page
* [Pease](https://github.com/boldport/pease-2ed) - OSH files on GitHub
* [Pease](http://community.boldport.club/projects/p01-pease/) - club community site, packed with resources for the project
* [LM331 Datasheet](http://www.ti.com/lit/ds/symlink/lm331.pdf)
* ["Just Less the Perfect"](http://www.boldport.club/shop/product/437169103) - where you can still obtain the Pease board
* [Bob Pease](https://en.wikipedia.org/wiki/Bob_Pease) - wikipedia
* [..as mentioned on my blog](http://lblog.tardate.com/2017/02/leap256-the-boldportclub-pease.html)
