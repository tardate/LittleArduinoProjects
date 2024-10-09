# #426 ATtiny Software PWM

Generating arbitrary PWM signals with an ATtiny85 and bit-banging techniques.

![Build](./assets/SoftwarePWM_build.jpg?raw=true)

## Notes

In most cases, direct hardware support is by far the preferred way of generating PWM signals with an ATtiny, but
there are limitations:

* there is a restricted set of prescaled frequencies
* duty cycle granulatity is fixed at 1:256

NB: or you can generate a wider range of frequencies in counter mode, but duty cycle is fixed at 50%.

But what if you need to generate an arbitrary PWM signal that doesn't match one of these available options,
for example 1.2kHz at 98% duty cycle?

| Frequency | Duty | Time High | Time Low |
|-----------|------|-----------|----------|
| 1.2kHz    | 98%  |   816.7µs | [16.67µs](https://www.wolframalpha.com/input/?i=1%2F1.2kHz*0.02) |


### Using Timers to Generate Arbitrary Waveforms

The basic idea:

* setup a timer with a known interrupt frequency given a specific clock frequency (prescalar) and count
* trigger an interrupt on counter reset
* in the interrupt, use the knowledge of the expected interrupt frequency to determine whether to flip the output of the desired waveform

There are serious limitations to consider: if we want, say 2% resolution of the duty cycle (to generate a 98% wave):

* then we need the interrupt to be 50 times the frequency of the desired output wave
* so for a 1.2kHz, we need at least a 60kHz interrupt

Even running the ATtiny at 8MHz, it doesn't take long to run out of clock cycles, especially if the interrupt handler needs to do a number of operations to calculate the waveform.
Basically, the higher the duty cycle resolution, the maximum possible PWM frequency is reduced.

So depending on the requirements, at this point we might start to consider alternatives:

* is the frequency critical? can I use a standard frequency supported by jardware PWM instead?
* bump up the clock frequency to 16 or 20 MHz? But this requires an external crystal oscillator, so we lose 2 precious pins
* switch to another microprocessor that can provide more timers, PWM channels and higher clock speeds - ATmega328P, ARM Cortex etc
* or switch to external oscillators/PWM generators

### The Example

But say we decide to proceed with bit banging some PWM,
the [SoftwarePWM.ino](./SoftwarePWM.ino) sketch is an example of generating 2 independent PWM signals (on PB0, PB2).

It also runs a separate routine that performs output on PB1 - just to show we still have some clock cycles left over!

Given that we want to generate something like 1.2kHz at 98% duty cycle, we need an interrupt frequency of around
[16.67µs](https://www.wolframalpha.com/input/?i=1%2F1.2kHz*0.02).

The ATtiny is configured at 8MHz internal clock speed and a Timer1 interrupt with:

* divide by 32 prescalar
* top count of [(F_CPU/1000000 * 16.7/32 - 1) ~= 3](https://www.wolframalpha.com/input/?i=8MHz+*+16.7%C2%B5s+%2F+32+-+1)

So the interrupt period would actually be [16µs](https://www.wolframalpha.com/input/?i=1%2F(8MHz%2F32)+*+4) (considering rounding),
i.e. a frequency of [62.5kHz](https://www.wolframalpha.com/input/?i=1%2F(16%C2%B5s)).


#### PWM Wave 1 on PB0

We want a 98% duty cycle, so that corresponds to 1 interrupt cycle low, and 49 cycles high,
for an expected resulting frequency of [1.25kHz](https://www.wolframalpha.com/input/?i=62.5kHz+%2F+50)
(it's slightly off the original spec due to rounding errors).


#### PWM Wave 2 on PB2

I've arbitrarily decided to generate a wave that is 13 interrupt cycles on, and 4 off.
In other words, an expected frequency of
[3.676kHz](https://www.wolframalpha.com/input/?i=62.5kHz+%2F+(13+%2B+4))
and [76.47%](https://www.wolframalpha.com/input/?i=13+%2F+(13+%2B+4)) duty cycle.


#### GPIO on PB1

The main loop of the sketch toggles PB1 using regular `delay` and `digitalWrite` functions,
showing that

* Timer0 is unaffected
* direct manipulation of `PORTB` is not having side-effects
* and there's enough clock cycles left over to at least do this much!


### Test Results

So how did it perform? Here are the resulting waves stacked on a scope:

* CH1 (yellow) - PB1
* CH2 (blue) - PB0 (offset for clarity)
* CH3 (red) - PB2 (reduced scale for clarity)

![all_traces](./assets/all_traces.gif?raw=true)


#### PWM Wave 1 on PB0

| Measure   | Expected | Actual    |
|-----------|----------|-----------|
| Frequency | 1.25 kHz | 1.307 kHz |
| +Duty     | 98%      | 98%       |

![wave_pb0](./assets/wave_pb0.gif?raw=true)


#### PWM Wave 2 on PB2

| Measure   | Expected | Actual    |
|-----------|----------|-----------|
| Frequency | 3.676 kHz| 3.845 kHz |
| +Duty     | 76.47%   | 76.5%     |


![wave_pb2](./assets/wave_pb2.gif?raw=true)


#### GPIO on PB1

| Measure   | Expected | Actual    |
|-----------|----------|-----------|
| Frequency | 1.000 Hz | 1.043 Hz  |
| +Duty     | 50%      | 50%       |

![wave_pb1](./assets/wave_pb1.gif?raw=true)


## Construction

![Breadboard](./assets/SoftwarePWM_bb.jpg?raw=true)

![Schematic](./assets/SoftwarePWM_schematic.jpg?raw=true)

![Build](./assets/SoftwarePWM_build.jpg?raw=true)

## Credits and References

* [Bit banging](https://en.wikipedia.org/wiki/Bit_banging) - wikipedia
* [ATtiny85 datasheet](https://www.microchip.com/en-us/product/ATTINY85)

