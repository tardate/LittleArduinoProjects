# #385 widlar

Hacking the BoldportClub Widlar (Project #21) to get the classic μA723 to do something other than voltage regulation (LED blinky).

![Build](./assets/widlar_build.jpg?raw=true)

Here's a quick demo..

[![clip](http://img.youtube.com/vi/jR9F6w2ItQ8/0.jpg)](http://www.youtube.com/watch?v=jR9F6w2ItQ8)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

[BoldportClub Widlar](http://www.boldport.com/widlar) project is really all about two things:

* Bod Widlar's classic μA723 voltage regulator, in SMD packaging
* a beautiful circuit board that breaks out the chip to allow building any of the standard circuits supported by the μA723 "voltage regulator toolkit"

The μA723 comprises a number of functional sub-systems:

* internal voltage reference, 7.15V (typical)
* voltage reference amplifier
* error amplifier
* current limiter
* output control transistor
* output zener diode

With a few external components, these allow the μA723 to be tailored for specific voltage regulation goals.
I've experimented with some of the basic 723 circuits previously:

* [LEAP#383 LM723/LowVoltageRegulator](../../Electronics101/LM723/LowVoltageRegulator)
* [LEAP#384 LM723/HighVoltageRegulator](../../Electronics101/LM723/HighVoltageRegulator)

Although not recommended or particularly useful for modern designs,
it is widely discussed and documented, so makes an excellent learning tool.

As it came out in the same year I was born (1967), I also find it a personally interesting benchmark from which to
judge how much things have changed, ... and how they haven't;-)


## The Kit

Another wonderfully packaged kit from Boldport..

![widlar_kit](./assets/widlar_kit.jpg?raw=true)
![widlar_pcb_front](./assets/widlar_pcb_front.jpg?raw=true)
![widlar_pcb_rear](./assets/widlar_pcb_rear.jpg?raw=true)

### Parts

|Qty | Item                                               |
|----|----------------------------------------------------|
| x1 | μA723, TI UA723CDR                                 |
| x1 | NPN BJT TO-220, Fairchild BD239BTU                 |
| x5 | 470Ω resistor 250mW, Multicomp MCF 0.25W 470       |
| x5 | 4.3KΩ resistor 500mW, RS PRO739-8809               |
| x5 | 1.5KΩ resistor 500mW, RS PRO739-8767               |
| x3 | 10KΩ resistor 250mW, Multicomp MCF 0.25W 10K       |
| x1 | 10Ω resistor 600mW, Multicomp MCMF006FF100JA50     |
| x1 | 3Ω resistor 600mW, Vishay MBB02070C3008FCT00       |
| x1 | 10KΩ trimmer, Bourns 3306W-1-103                   |
| x2 | 100pF ceramic capacitor, Suntan TS15001H101KSBSA0R |
| x2 | 470pF ceramic capacitor, Suntan TS15001H471KSBPA0R |
| x1 | PCB                                                |

## Going Off Road..

This kit came packed with components for building a wide range of possible μA723 configurations.

But since I've already looked at the basic μA723 circuits, and I don't really need another regulator,
the attraction of course it to try and do something different
(even though the 723 is generally though to "not have applications beyond the relatively narrow field of voltage regulation").

But I spy an error amplifier, so that means it should be possible to get the 723 to behave like some form of
[oscillator](https://www.allaboutcircuits.com/worksheets/opamp-oscillator-circuits/).

Using the 723 voltage reference as a virtual ground,
I configured an opamp oscillator circuit around the error amplifier,
disabled the current limiter,
and got a nice effect for "blinking" and LED at about 2Hz.

NB: Since I've left a DC offset on the oscillation, the LED blink is more a "glow", as it never goes fully off.

I used a breadboard build to experiment and confirm component values:

![723_blinking_breadboard](./assets/723_blinking_breadboard.jpg?raw=true)

Without load, I'm getting a square-ish wave with low duty cycle, and Vref providing a DC offset:

![oscillation_no_load](./assets/oscillation_no_load.gif?raw=true)

With the LED load attached, the waveform is more complex:

![oscillation_led_load](./assets/oscillation_led_load.gif?raw=true)

## Construction

![Breadboard](./assets/widlar_bb.jpg?raw=true)

![Schematic](./assets/widlar_schematic.jpg?raw=true)

![widlar_layout](./assets/widlar_layout.jpg?raw=true)

![Build](./assets/widlar_build.jpg?raw=true)

## Credits and References
* [Widlar](http://www.boldport.com/widlar) - official Boldport page
* [μA723 Datasheet](http://www.ti.com/lit/ds/symlink/ua723.pdf)
* [OpAmp Oscillators](https://www.allaboutcircuits.com/worksheets/opamp-oscillator-circuits/)
* [..as mentioned on my blog](https://blog.tardate.com/2018/04/leap385-bolportclub-widlar-blinky.html)
