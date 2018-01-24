# #129 RelaxationJouleThief

Test a "joule thief" circuit based on a relaxation oscillator.


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This circuit achieves a voltage boost, enough to drive an LED with forward voltage in excess of the power supply.
In fact it can continue to run the LED as the battery is depleted.
I haven't tested this yet, but apparently it should work down to a battery voltage of ~0.3V under load

The circuit is from a kit sold by [Ears To Our World](http://www.earstoourworld.org).
Proceeds from the sale of the kit benefit the "Ears To Our World" charity which provides self-powered radios and other technology to rural, impoverished and remote regions of the world.

How it works is best explained in [this excellent video by w2aew](https://www.youtube.com/watch?v=qfgX93o8HzY).

Here's the essence:
* When power is applied, the second transistor (Q2) is immediately turned on but Q1 remains off since the capacitor holds the base voltage high
* This allows current to build in the inductor, establishing a magnetic field
* As the capacitor charges (primarily through the 100kΩ resistor), Q1 eventually switches on
* When Q1 switches on, Q2 shuts off. This cuts the current through the inductor, generating a flyback surge which is dumped through the LED
* As the capacitor discharges, Q2 is eventually turns back on. When this happens, the voltage across the inductor shifts back to ground, forcing the capacity voltage negative, and in turn shutting off Q1.
* And the cycle repeats...

The circuit I've built here uses some different component values, primarily because of what I had "on hand",
but also to tweak what seemed to work best with the specific LED load:

| Part | Original Value | Actual Value Used   |
|------|----------------|---------------------|
| L1   | 4.7mH          | 1mH                 |
| R1   | 100kΩ          | 22kΩ                |
| C1   | 470pF          | 10nF                |
| LED  | 5mm white..?   | 3mm Red, Vf~ 2-2.2V |

I've also put an LED in circuit directly across the power supply - just to prove the point that the battery cannot power it without help!

### Waveforms

Here's a trace of the circuit with 4 probes at interesting points in the circuit:
* CH1 - output voltage
* CH2 - Q1 base
* CH3 - Q2 base
* CH4 - input voltage - this is a fairly fresh 1.5V AAA

![RelaxationJouleThief_scope](./assets/RelaxationJouleThief_scope.gif?raw=true)

## Construction

![Breadboard](./assets/RelaxationJouleThief_bb.jpg?raw=true)

![The Schematic](./assets/RelaxationJouleThief_schematic.jpg?raw=true)

![The Build](./assets/RelaxationJouleThief_build.jpg?raw=true)

## Credits and References
* [Joule Thief](https://en.wikipedia.org/wiki/Joule_thief) - wikipedia
* [#187: Circuit Walkthrough: A single cell LED light supporting Ears to Our World](https://www.youtube.com/watch?v=qfgX93o8HzY) - another great video from w2aew; explains the circuit demonstrated here
* [Relaxation oscillator](https://en.wikipedia.org/wiki/Relaxation_oscillator) - wikipedia
* [..as mentioned on my blog](https://blog.tardate.com/2016/02/littlearduinoprojects129-relaxation.html)
