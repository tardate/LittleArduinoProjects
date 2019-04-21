# #376 Piezo Vibration Detector and BPM Counter

Counting beats per minute with a piezo tap sensor and an Arduino/ATmega328 analog comparator.

![Build](./assets/PiezoVibrationDetector_build.jpg?raw=true)

## Notes

Some time back I picked up some [Piezo Transducers](http://www.dx.com/p/zx-18t9a1-18mm-piezo-transducer-sound-discs-w-leads-5-pcs-148144#.Wm3xP5P1XfA),
and they've been waiting for a project to happen.

This experiement is a building block. What I'd like to be able to do is detect (count) pulses from the piezo transducer.
That is, as opposed to capturing an accurate waveform from the piezo - I just want to know when a "tap" is picked up.

There are many ways to approach this, but what I'll expore here is using the built-in analog comparator of an Arduino/ATmega328
to trigger interrupts and do some software de-bouncing/noise abatement.
As a result is derives and displays a beats-per-minute (BPM) estimate.

### Piezo Transducers

What happens when a piezo transducer picks up a vibration?

Here's a scope capture of a raw signal, unfiltered, when the surface near the transducer is struck reasonably hard.
The capture is DC coupled, so what this shows is a wave peaking between +1.5V to -1V, with a total duration of say 3.6ms.

![scope_raw_input](./assets/scope_raw_input.gif?raw=true)

In other tests, it appears I can get the piezo to peak at over 6V, as well as going significantly negative.
I'm not sure if this is really required (because I suspect the power is extremely low),
but I've added a 3.3V zener across the piezo to clamp the input.

Some specifications of the piezo transducer I'm using:

* Model: ZX-18T9A1
* Material: Brass + ceramic
* Resonant frequency: 8.0 +/- 0.7kHz;
* Resonant resistance: 350Ω (max);
* Capacitance: 7000pF +/- 30%;
* Input voltage: for DC 30V;
* Operating temperature: -20~+70C;
* Storage temperature: -30~80C;
* Brass disc: 18mm +/- 0.1mm x 0.15mm +/- 0.05mm;
* Ceramic disc: 14mm +/- 0.1mm x 0.34mm +/- 0.05mm;
* Lead length: 7cm

### Using the Analog Comparator

The [PiezoVibrationDetector.ino](./PiezoVibrationDetector.ino) sketch sets up the analog comparator
to trigger an interrupt when a "beat" is detected. The code then counts and averages these beats to
derive a BPM measure.

The analog comparator will use two pins:

| ATmega Pin | Functions         | Arduino Pin | Usage                                                                     |
|------------|-------------------|-------------|---------------------------------------------------------------------------|
| PD6        | PCINT22/OC0A/AIN0 | 6           | Analog Comparator Positive Input - raw piezo pulse input                  |
| PD7        | PCINT23/AIN1      | 7           | Analog Comparator Negative Input - adjustable threshold reference voltage |


There are two registers of significance for setting this up:

![ADCSRB_register](./assets/ADCSRB_register.png?raw=true)

Clearing the Analog Comparator Multiplexer Enable in ADCSRB means the comparator will use the threshold reference voltage provided on AIN1

![ACSR_register](./assets/ACSR_register.png?raw=true)

The Analog Comparator Interrupt Flag is set to enable interrupts, and the ACIS1 and ACIS0 bits set the mode:

| ACIS1 | ACIS0 | Interrupt Mode                              |
|-------|-------|---------------------------------------------|
| 0     | 0     | Comparator Interrupt on Output Toggle       |
| 0     | 1     | Reserved                                    |
| 1     | 0     | Comparator Interrupt on Falling Output Edge |
| 1     | 1     | Comparator Interrupt on Rising Output Edge  |


The code sets a rising edge interrupt and implements the interrupt service routine to record the time between beats.


### Counting Beats

We want to extract a single pulse from the noisy raw piezo input, so it needs filtering and "de-bouncing".
This could be done off-board with comparators and filters, but in this case I'm doing it within the ATmega
with the following techniques:

* the analog comparator reference threshold set with R1 prevents (ilters) weaker pulses triggering the input
* discard pulses faster than 250 BPM/240ms - "too fast to be useful"
* reset when pulses below 33 BPM/1800ms - "threshold of the perceptual present"

The resulting BPM measure is calculated as an exponential moving average.

At the moment, the sketch just outputs the BPM to the serial console. Here's an example of me trying to maintain 120bpm:

![console_120bpm](./assets/console_120bpm.png?raw=true)

## Construction

![Breadboard](./assets/PiezoVibrationDetector_bb.jpg?raw=true)

![Schematic](./assets/PiezoVibrationDetector_schematic.jpg?raw=true)

I used a small piece of protoboard to anchor the connections and mount the threshold pot and zener diode:

![tap_pad_wip](./assets/tap_pad_wip.jpg?raw=true)

Finished "tap pad":

![tap_pad](./assets/tap_pad.jpg?raw=true)

## Credits and References
* [Piezoelectric sensor](https://en.wikipedia.org/wiki/Piezoelectric_sensor) - wikipedia
* [ZX-18T9A1 18mm Piezo Transducer Sound Discs](http://www.dx.com/p/zx-18t9a1-18mm-piezo-transducer-sound-discs-w-leads-5-pcs-148144#.Wm3xP5P1XfA)
* [ATmega168/328-Arduino Pin Mapping](https://www.arduino.cc/en/Hacking/PinMapping168)
* [What is the slowest music humanly possible?](https://www.youtube.com/watch?v=afhSDK5DJqA) - Adam Neely
* [What is the fastest music humanly possible?](https://www.youtube.com/watch?v=h3kqBX1j7f8) - Adam Neely
* [Exponential moving average](https://en.m.wikipedia.org/wiki/Moving_average#Exponential_moving_average)
* [Using the Arduino Analog Comparator](http://www.gammon.com.au/forum/?id=11916)
* 6.6 Detecting Vibration, [Arduino Cookbook](https://www.goodreads.com/book/show/11222094-arduino-cookbook)
* [..as mentioned on my blog](https://blog.tardate.com/2018/02/leap376-piezo-vibration-detector-and-bpm-counter.html)
