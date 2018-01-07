# #368 GranularSynth

Building an ATmega328 granular synth module in an Altoids can .. because granular synthesis is a basically how they make Altoids, right?

![Build](./assets/GranularSynth_build.jpg?raw=true)

Here's a quick demo .. if you can tolerate 5 minutes of me fiddling around!

[![clip](http://img.youtube.com/vi/1UOCTyM_3Ns/0.jpg)](http://www.youtube.com/watch?v=1UOCTyM_3Ns)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I found out about the "Granular Synth" from [Notes & Volts](http://www.notesandvolts.com/2014/07/build-auduino-granular-synth-part-1.html),
and it's history goes back to the [Auduino](http://code.google.com/p/tinkerit/wiki/Auduino) developed by
what appers to be the defunct "tinkerit".


## Code

[GranularSynth.ino](./GranularSynth.ino) is my adaptation of the original [Auduino](http://code.google.com/p/tinkerit/wiki/Auduino) code.
I have dropped support for processors other than the ATmega328.

Pin mapping used by the sketch is as follows:

| Pin        | Function                   |
|------------|----------------------------|
| Analog 0   | Grain 1 pitch              |
| Analog 1   | Grain 1 decay              |
| Analog 2   | Grain 2 decay              |
| Analog 3   | Grain 2 pitch              |
| Analog 4   | Grain repetition frequency |
| Digital 3  | Audio out                  |
| Digital 13 | LED; ICSP SCK              |
| Digital 12 | ICSP MISO                  |
| Digital 11 | ICSP MOSI                  |
| Digital 1  | ICSP RESET                 |


### Audio Generation

The "audio" signal generated on pin 3 is actually a PWM signal, constructed based on the settings of the 5 pots.

PWM on pin 3 uses:

* Timer 2 (8-bit timer)
* OCR2B compare register
* OC2B timer output
* see "12. 8-bit Timer/Counter0 with PWM" in the Atmel ATmega datasheet

PWM is configured with registers TCCR2A/B

* TCCR2 _BV(WGM20): PWM, Phase Correct; TOP=0xFF; updates OCR2 at TOP; TOV set on BOTTOM
* TCCR2 _BV(COM2B1): Clear OC0B on Compare Match when up-counting.
* TCCR2 _BV(CS20): no pre-scaling of the clock

In Phase Correct mode, the timer counts from 0 to 255 and back down to 0.
Because it counts up and down and no prescaler, the frequency of the PWM time is 16Mhz/1/256/2 = 31.25kHz.

The output turns off as the timer hits the output compare register (OCR2B) value on the way up, and turns back on as the timer hits the output compare register value on the way down.

The sketch hooks TIMER2_OVF_vect and enables interrupts:

  TIMSK2 = _BV(TOIE2);

When the interrupt is triggered, the sketch fiddles the output compare register (OCR2B) given the current settings of the 5 pots.
It also directly toggles the LED each time a full sync cycle is complete.

The [granular synthesis](https://en.wikipedia.org/wiki/Granular_synthesis) algorithm is implemented with two "grains":

* each has a frequency and decay set by the corresponding pot.
* each interrupt, the grain counters are updated, and combined.
* the mixed signal (value) is used to adjust the output compare register

The master frequency control is used to adjust the counter limit at which time the grains are re-synchronised.


## Breadboard Construction

I started with a breadboard and an Uno for initial tests. The potentiometers I'm using are a selection of 5kΩ, 10kΩ and 20kΩ linear.
I don't believe it is particularly important to have them matched, as they are just voltage dividers.
I fact higher values are preferred - at 5kΩ, 5 in parallel effectively put [1kΩ](http://toolbox.tardate.com/?formula=5000%7C5000%7C5000%7C5000%7C5000#ResistorCalculator)
across the 5V supply and that's 5mA of wasted power.

![Breadboard](./assets/GranularSynth_breadboard_bb.jpg?raw=true)

![Schematic](./assets/GranularSynth_breadboard_schematic.jpg?raw=true)

![Build](./assets/GranularSynth_breadboard_build.jpg?raw=true)


## Warning: output impedence

The circuits used here send the ATmega328 output pin straight to the audio out (left) channel with no protection.
This means care is required not to plug it directly into any low impedence device; doing so could damage the microprocessor.


## Putting it in a Can

To fit in an Altoids can, I replaced the Arduino Uno with:

* ATmega328P with 16MHz crystal
* 7805 regulator
* ICSP header
* LED for pin 13

Potentiometers and LED are mounted on the lid, and the electronics on two sections of protoboard. It just fits in nicely!

![Schematic](./assets/GranularSynth_schematic.jpg?raw=true)

![can_1](./assets/can_1.jpg?raw=true)

![can_2](./assets/can_2.jpg?raw=true)

Finished and under test:

![Build](./assets/GranularSynth_build.jpg?raw=true)

## Credits and References
* [Granular synthesis](https://en.wikipedia.org/wiki/Granular_synthesis) - wikipedia
* [Build the Auduino Granular Synth - Part 1](http://www.notesandvolts.com/2014/07/build-auduino-granular-synth-part-1.html) - Notes & Volts
* [Auduino](http://code.google.com/p/tinkerit/wiki/Auduino) - original sources
* [Atmel ATmega328P Product Info](http://www.atmel.com/devices/ATMEGA328P.aspx)
* [LM7805 datasheet](http://www.futurlec.com/Linear/7805T.shtml)
* [..as mentioned on my blog](http://blog.tardate.com/2018/01/leap368-granular-synth.html)
