# #465 MrBiJuT Simple Transistor Tester

Mr BiJuT is a freeform realisation of a simple NPN/PNP transistor testing circuit
using a CD4011 Schmitt oscillator.

![Build](./assets/MrBiJuT_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/hCzHK4Sgnn0/0.jpg)](https://www.youtube.com/watch?v=hCzHK4Sgnn0)

## Notes

I found this neat little circuit in the
[Radio and Electronics Cookbook](https://www.goodreads.com/book/show/3415601-radio-and-electronics-cookbook) (69 A bipolar transistor tester, p240).

I tested it out on a breadboard, liked it's simplicity, and decided to do a little #FreeformFriday rendition: Mr BiJuT!

## Circuit Design and How it Works

Here's my re-drawing of the circuit and the basis for a breadboard build:

![Breadboard](./assets/MrBiJuT_bb.jpg?raw=true)

![Schematic](./assets/MrBiJuT_schematic.jpg?raw=true)

The circuit uses a CD4011 (NAND gates configured as inverters) to generate a square wave. Gates C and D are responsible for this.
The oscillator stage is free running at around 109Hz. Here's a scope trace of the output at pin 10 of the CD4011:

![scope_oscillator](./assets/scope_oscillator.gif?raw=true)

NAND Gate A acts as a buffer for the oscillator, so the device under test does not interfere with the signal.

The final inverter stage (NAND gate B) is the source and sink of the BJT/LED stage, providing an oscillating
"power supply" that inverts polarity at the frequency of the oscillator.
and is applied across the transistor device under test.

Depending on whether the transistor is an NPN or PNP it will light a corresponding LED.
This is how it manages to achieve that:

* R1 and R2 act as a 1/2 voltage divider to bias the base of the transistor at half signal voltage, so it should always be "on" if correctly polarised.
* R3 provides some current-limiting to the transistor under test and the indicator LEDs
* The collector-emitter current flows through two diodes (D1 & D2 or D3 & D4) if the transistor is "on"

If the transistor is NPN:

* it will conduct when R3 and the diodes are on the high-side of signal
    * LED1 (red) will be off since reverse-biased
    * LED2 (yellow) will also be off, since the total voltage drop across the D1, D2 and the transistor will be less than the LED forward voltage (Vf)
* but when R3 and the diodes are on the low-side of signal
    * LED1 (red) will be on, since the transistor will not conduct and bypass the LED
    * LED2 (yellow) will be off since reverse-biased
* so, the red LED1 will be on with a ~50% duty cycle and is the "NPN indicator"

Similarly, if the transistor is PNP:

* it will conduct when R3 and the diodes are on the low-side of signal
    * LED2 (yellow) will be off since reverse-biased
    * LED1 (red) will also be off, since the total voltage drop across the D1, D2 and the transistor will be less than the LED forward voltage (Vf)
* but when R3 and the diodes are on the high-side of signal
    * LED2 (yellow) will be on, since the transistor will not conduct and bypass the LED
    * LED1 (red) will be off since reverse-biased
* so, the yellow LED2 will be on with a ~50% duty cycle and is the "PNP indicator"

## Breadboard Build

Playing around with the circuit on a breadboard. Testing an NPN:

![bb_test_npn](./assets/bb_test_npn.jpg?raw=true)

Testing a PNP:

![bb_test_pnp](./assets/bb_test_pnp.jpg?raw=true)

## Freeform

It's a nice little circuit with some symmetries that lend themselves to a bit of freeform construction.
I scavenged the connector plate from an old 9V battery as the base and just built it up by eye (and a little sketching).

Introducing "Mt BiJut", the transistor tester. It winks depending on whether an NPN or PNP is plugged or touched to the contacts
on top of it's head.

![MrBiJuT_build1](./assets/MrBiJuT_build1.jpg?raw=true)

![MrBiJuT_build2](./assets/MrBiJuT_build2.jpg?raw=true)

Testing an NPN:

![ff_test_npn](./assets/ff_test_npn.jpg?raw=true)

Testing a PNP:

![ff_test_pnp](./assets/ff_test_pnp.jpg?raw=true)

## Credits and References

* [CD4011 datasheet](https://www.futurlec.com/4000Series/CD4011.shtml)
* [Radio and Electronics Cookbook](https://www.goodreads.com/book/show/3415601-radio-and-electronics-cookbook) - 69 A bipolar transistor tester, p240.
* [..as mentioned on my blog](https://blog.tardate.com/2019/03/leap465-mr-bijut.html)
