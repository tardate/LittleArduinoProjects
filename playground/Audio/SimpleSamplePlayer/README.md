# #417 Audio/SimpleSamplePlayer

Playing short audio samples on an Arduino using some PWM tricks from the PCM library.

![Build](./assets/SimpleSamplePlayer_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/FcADRSu5XVk/0.jpg)](https://www.youtube.com/watch?v=FcADRSu5XVk)

## Notes

Microcontrollers typically don't have a lot of on-board memory, so the idea of playing audio samples
is generally out of reach without somehow solving the storage issue (or delving into synthesised sound).

But even with the limited memory of an Arduino (32kb flash in most cases), it is possible to
handle short samples.

I borrowed this project from [Simple Arduino audio samples](http://highlowtech.org/?p=1963),
which uses the [PCM](https://github.com/damellis/PCM) library
to play an 8kHz, 8-bit sample stored in flash memory.

### The PCM Library

The [PCM](https://github.com/damellis/PCM) library
plays 8-bit PCM audio on pin 11 using pulse-width modulation (PWM).

It uses two timers (Timer 1, 2) to modulate a 62.5kHz carrier with the 8-bit
sound information (which adjusting pulse-width).

Because the library uses the two timers, these cannot also be used for other purposes at the same time. Specifically:

* prohibits PWM for Arduino pins 9 and 10 (Timer 1)
* prohibits PWM for Arduino pins 3 and 11 (Timer 2)

### Encoding Sound Samples

I used a simple ruby program -
[sample_encoder.rb](./encoder/sample_encoder.rb) -
to generate the C header file with the necessary memory definition.

It can read WAV files in various format and output the necessary 8-bit samples.
It uses the [wavefile](http://wavefilegem.com/) ruby gem to interpret the WAV file format.

At the moment, it cannot re-sample the source WAV file - so it must be an 8kHz file to avoid pitch-shift.

I grabbed a few sample files and used [audacity](https://www.audacityteam.org/)
to re-sample the source at 8kHz and ensure the clips were under the ~4sec
limit that can fit into available flash memory.

Setting up to run the encoder. A Gemfile is provided, so bundler can install the necessary pre-requisites:

    cd encoder
    bundle install

To run the encoder, simply invoke with a WAV file parameter. The resulting header file
will be sent to standard out, which can be piped to a header file for compilation like this:

    ./sample_encoder.rb ../sounds/phone.wav > ../sample_phone.h

The sample to be programmed is selected by ensuring the correct include
definition is included in the
[SimpleSamplePlayer.ino](./SimpleSamplePlayer.ino) script.

There are many other ways of preparing the audio sample - see the original
[post](http://highlowtech.org/?p=1963)
for an iTunes/processing option.

## Construction

This script requires is a speaker (or audio in) connected to pin 11.
With a speaker, it's a good idea to include a series resistor to avoid overloading the Arduino pins.
I've used 100Ω. In practice, things will work just fine without a resistor ... until a sample
wants to peg the output high, which risks pulling more current that the Atmega chip can handle.

I've included a push-button on pin 2, which is configured with built-in pull-up resistor (INPUT_PULLUP).
On a FALLING interrupt (i.e. when you press the button), the script plays the audio sample.

I've provided two encoded samples:

* [sample_phone.h](./sample_phone.h) - a phone ring-tone (the example I demonstrate in the video)
* [sample_pop.h](./sample_pop.h) - a "pop" sound effect
* [sample_arduino_duemilanove.h](./sample_arduino_duemilanove.h) - a phrase, as used in the [original example](http://highlowtech.org/?p=1963)

One just needs to include the corresponding header file in the main script.

![Breadboard](./assets/SimpleSamplePlayer_bb.jpg?raw=true)

![Schematic](./assets/SimpleSamplePlayer_schematic.jpg?raw=true)

![Build](./assets/SimpleSamplePlayer_build.jpg?raw=true)

## Credits and References

* [Simple Arduino audio samples](http://highlowtech.org/?p=1963) - blog post introducing the idea I used for this project
* [PCM](https://github.com/damellis/PCM) Arduino library by damellis
* [audacity](https://www.audacityteam.org/)
* [wavefile](http://wavefilegem.com/) -  ruby gem
* [..as mentioned on my blog](https://blog.tardate.com/2018/10/leap417-playing-sounds-samples-with-arduino.html)
