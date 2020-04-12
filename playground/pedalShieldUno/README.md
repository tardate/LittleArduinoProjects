# #247 pedalShieldUno

Build and test a genuine pedalSHIELD UNO.

![Build](./assets/pedalShieldUno_build.jpg?raw=true)


## Notes

In the [AudioDSP](../AudioDSP) project, I built an Arduino pedal/DSP unit based on the Electrosmash pedalSHIELD design.
It worked well enough that I wanted to build the "real thing", not only to give myself a good baseline
on expected performance, but also to payback Electrosmash in a small way. Good OSH deserves support!


### Unboxing and Parts Check

| Reference                     | Qty | Value             | Check |
|-------------------------------|-----|-------------------|-------|
| C2, C5, C7, C8, C9            | 5   | 6.8nF             | √     |
| C3, C6, C10                   | 3   | 4.7µF             | √     |
| C1, C11                       | 2   | 100nF             | √     |
| C4                            | 1   | 270pF             | √     |
| R12, R13, R10, R9, R6, R4, R3 | 7   | 4.7kΩ             | √     |
| R5, R7, R8                    | 3   | 100kΩ             | √     |
| R1, R2                        | 2   | 1MΩ               | √     |
| R11                           | 1   | 1.2MΩ             | √     |
| RV1                           | 1   | 500kΩ trimmer     | √     |
| D1                            | 1   | LED 3mm blue      | √     |
| U1                            | 1   | TL972 DIP8        | √     |
| socket                        | 1   | DIP8 socket       | √     |
| SW1                           | 1   | 3DPT footswitch   | √     |
| SW2                           | 1   | Toggle switch     | √     |
| SW3, SW4                      | 2   | Pushbutton        | √     |
| Conn1,2,3,4                   | 1   | 40 pin header     | √     |
| J1, J2                        | 2   | 1/4" Audio Jack   | √     |
|                               | 1   | PCB               | √     |
|                               | 1   | Acrylic faceplate | √     |

![kit_box](./assets/kit_box.jpg?raw=true)

![kit_parts](./assets/kit_parts.jpg?raw=true)

### Assembly

About 60 minutes of soldering, continuity test and inspection.

Then an electrical test, powered independantly from 5V (i.e. no in the shield).
All the test points check out OK, and current draw is ~2mA. Good to go .. and it works!

![pedalShieldUno_test](./assets/pedalShieldUno_test.jpg?raw=true)


### Programming

The [examples](./examples) folder contains the collection of samples provided on the
[How to start programming pedalSHIELD UNO](https://www.electrosmash.com/forum/pedalshield-uno/114-how-to-start-programming-pedalshield-uno) forum page. These are currently unmodified, and all work as expected.


## Performance

It is surprisingly good, although it does tail off at the higher frequencies.

Quick test of the standard examples ..


#### pedalshield_uno_bit_crusher

This effect boosts the signal into overdrive (level determined by the pushbuttons).

![scope](./assets/scope_bit_crusher.gif?raw=true)


#### pedalshield_uno_booster

A simple volume boost (level determined by the pushbuttons).

![scope](./assets/scope_booster.gif?raw=true)


#### pedalshield_uno_clean

As you would expect: signal in, signal out. With a bit of high frequency noise..


#### pedalshield_uno_daft_punk_octaver

Effectively downsamples the input (level determined by the pushbuttons).

Trick effect. Solo not so nice - takes too much character out of the sound.

![scope](./assets/scope_daft_punk_octaver.gif?raw=true)


#### pedalshield_uno_delay

Mixes a delayed signal with the input (delay depth determined by the pushbuttons).

Not so much delay, more like a bit of reverb?

![scope](./assets/scope_delay.gif?raw=true)


#### pedalshield_uno_distortion

Performs an asymmetrical clipping (top-side) to a level determined by the pushbuttons.
Bluesy warm distortion..

![scope](./assets/scope_distortion.gif?raw=true)


#### pedalshield_uno_fuzz

Performs a symmetrical clipping and boost to a level determined by the pushbuttons -
signals above the threshold are thrown to the upper/lower rail.

Nice fuzz, full-on distortion. It does have a harsh cut-off at lower volumes,
so palm muting doesn't work so well. Good for djenting!

![scope](./assets/scope_fuzz.gif?raw=true)


#### pedalshield_uno_metronome

Generates a metronome tone, at a frequency determined by the pushbuttons.


#### pedalshield_uno_monitor

Performs a clean transform of the guitar signal, and logs the settings to the serial port.

Since the serial logging is performed within the interrupt routine, the signal transform is severely disrupted.


#### pedalshield_uno_signal_generator

Generates a tone described in a provided dataset.


#### pedalshield_uno_tremolo

Modulates the signal volume at a speed governed by the pushbutton setting.

Great effect. The scope trace doesn't tell the story though .. it swells the volume.

![scope](./assets/scope_tremolo.gif?raw=true)



## Construction

[![Schematic](./assets/pedalShieldUno_schematic.png?raw=true)](https://www.electrosmash.com/images/tech/pedalshield-uno/pedalshield-uno-schematic.png)

![Build](./assets/pedalShieldUno_assembled.jpg?raw=true)

## Credits and References

* [pedalSHIELD UNO](https://www.electrosmash.com/pedalshield-uno-start) - getting started guide
* [pedalSHIELD UNO](https://www.electrosmash.com/pedalshield-uno) - main page
* [pedalSHIELD UNO Schematic](https://www.electrosmash.com/images/tech/pedalshield-uno/pedalshield-uno-schematic.png)
* [How to start programming pedalSHIELD UNO](https://www.electrosmash.com/forum/pedalshield-uno/114-how-to-start-programming-pedalshield-uno)
* [The Arduino Guitar Pedal](https://www.instructables.com/id/Arduino-Guitar-Pedal/) - another pedal proejct
* [..as mentioned on my blog](https://blog.tardate.com/2017/02/leap247-pedalshield-uno.html)
