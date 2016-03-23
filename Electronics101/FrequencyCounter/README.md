# #207 FrequencyCounter

Test a CMOS frequency counter circuit with a 100Hz - 5MHz range

## Notes

I found this circuit published in Electronics magazine (Sep 16 1976).

It's a classic demonstration of the CD4026 "bucket-brigade" and CD4047 astable oscillator.

### Sample/Display Time configuration

The frequency counter is governed by a CD4047 oscillator. Since this offers a clean 50% duty cycle,
it is ideal for flipping the circuit between two modes:

* sampling period
* display period

The frequency is tuned with 10nF and a resistor network comprising 2 x 220kΩ and a 20kΩ pot.
Thus the frequency limits are expected to be between about
[49Hz](http://www.wolframalpha.com/input/?i=1%2F%284.4+*+%282+*+220k%CE%A9+%2B+20k%CE%A9%29+*+10nF%29) and
[51Hz](http://www.wolframalpha.com/input/?i=1%2F%284.4+*+2+*+220k%CE%A9+*+10nF%29).

At 50Hz, the cycle time is [20ms](http://www.wolframalpha.com/input/?i=1%2F50Hz).
At 50% duty cycle, that's 10ms for sampling and 10ms for display.

So given the frequency count displayed is based on a 10ms sample,
the reading is therefore in tenths of a kHz.
The decimal point is enabled on the second digit in the display so the result may be easily read as kHz.

Here are some traces of the trigger signal:

* CH1: oscillator output Q COMPLEMENT
* CH2: reset trigger signal

![trigger_oscillator](./assets/trigger_oscillator.gif?raw=true)

Close-up on the trigger signal:

![trigger_edge](./assets/trigger_edge.gif?raw=true)

### 7-Segment CD4026 Display

The counter is based on the classic CD4026 "bucket-brigade" configuration

### Input Modulation

A signal may be directly fed into the CD4026 chain.
That works fine as long as the signal is suitable.

With a 2V p-p sine wave directly connected with a 10nF decoupling capacitor, the counter works up to 3MHz or so.

To get a little more headroom, I was able to extend the frequency range to just over 5MHz
with a NE5534P op amp configured as an adjustable comparator.

### Performance

At 5kHz, the NE5534P op amp procudes a clear square wave input to the counter.

* CH1: input signal
* CH2: non-inverting input
* CH3: op amp output/input to counter

![counter_input_5kHz](./assets/counter_input_5kHz.gif?raw=true)

At 5MHz, the NE5534P op amp output is quite distorted, however it is still good enough to drive the counter.

* CH1: input signal
* CH2: non-inverting input
* CH3: op amp output/input to counter

![counter_input_5MHz](./assets/counter_input_5MHz.gif?raw=true)


## Construction

![Breadboard](./assets/FrequencyCounter_bb.jpg?raw=true)

![The Schematic](./assets/FrequencyCounter_schematic.jpg?raw=true)

![The Build](./assets/FrequencyCounter_build.jpg?raw=true)

## Credits and References
* [Frequency Counter Design](http://www.epanorama.net/sff/Test_equipment/Counters/Minimum%20Parts%20Count%20Frequency%20Counter.pdf) - Lloyd F. Botway, Electronics Sep 16 1976
* [CD4026 Datasheet](http://www.futurlec.com/4000Series/CD4026.shtml)
* [CD4047 datasheet](http://www.futurlec.com/4000Series/CD4047.shtml)
* [NE5534P datasheet](http://www.ti.com/product/NE5534/datasheet)
