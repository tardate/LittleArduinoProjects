# #689 Programmable Frequency Reference

Build and test a programmable frequency reference capable of dialing in 4095 discrete frequencies between 488Hz and 1MHz.

![Build](./assets/ProgrammableFrequencyReference_build.jpg?raw=true)

## Notes

I discovered this interesting little circuit in
[ARRL's Hands-on Radio Experiments Volume 2](https://www.goodreads.com/book/show/40198290-arrl-s-hands-on-radio-experiments-volume-2) by H. Ward Silver.
It is Experiment 97, p91.

### How if Works

The essentials:

* the CD4001is used as a Pierce oscillator to generate a 4MHz crystal-locked clock signal and it's complement
* the clock drives the 4040 ripple counter
* a series of DIP switches enable the corresponding ripple counter output positions to pull the J-input low on the 74LS73 J-K Flip-Flop
* when the J-input on the 74LS73 J-K Flip-Flop is:
    * low: it causes the output Q to go low on the falling edge of the clock input
    * high: it causes the output Q to toggle on the falling edge of the clock input
    * NB: the clock input is the complement of the main clock (out of phase)
    * when  output Q goes high, it triggers the reset of the 4040 ripple counter and also clocks the second 74LS73 J-K Flip-Flop
* the second 74LS73 J-K Flip-Flop is used to convert the output of the first flip-flop to a symmetric waveform

The resulting frequencies for clock frequency `f` given the DIP switches set to the binary value `B`:

* first 74LS73 Flip-Flop output:
    * frequency: `f/(B + 1)`
    * but is not symmetrical (will be a high pulse with duration of `1/f` for all frequencies i.e <= 50% duty)
* second  74LS73 Flip-Flop output:
    * half the frequency of the first 74LS73 Flip-Flop output i.e.
    * frequency: `f/((B + 1) * 2)`
    * but it is a symmetrical (50% duty) square wave

The following timing diagram illustrates the logic for two cases:

* left: DIP selected Q1 (i.e. 001b)
* left: DIP selected Q2 (i.e. 010b)

![timing_spec](./assets/timing_spec.jpg?raw=true)

Note: The original CD4027 flip-flop logic is slightly different because it transitions on the rising edge, but the end result is the same

### Circuit Design

I have made some part substitutions and minor changes to the circuit as follows:

* CD4001 instead of 74HC4001
* 74LS73 instead of CD4027
* CD4040 instead of 74HC4040
* added one inverter from the CD4001 to buffer the oscillator output

![bb](./assets/ProgrammableFrequencyReference_bb.jpg?raw=true)

![schematic](./assets/ProgrammableFrequencyReference_schematic.jpg?raw=true)

![bb_build](./assets/ProgrammableFrequencyReference_bb_build.jpg?raw=true)

### Breadboard Test Results

Output frequency by DIP switch selection.
Some values from the [4095](https://www.wolframalpha.com/input?i=2%5E12+-+1) possibilities (0 is not a valid configuration).

| 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | Measured (kHz) | Expected (kHz)   |
|----|----|----|---|---|---|---|---|---|---|---|---|----------------|------------------|
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 999.990        | `f/4` = [1000.000](https://www.wolframalpha.com/input?i=4MHz%2F%28%281+%2B+1%29+*+2%29) |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 666.660        | `f/6` = [666.667](https://www.wolframalpha.com/input?i=4MHz%2F%28%282+%2B+1%29+*+2%29) |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 499.995        | `f/8` = 500.000  |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 399.995        | `f/10` = 400.000 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 333.328        | `f/12` = 333.333 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 285.710        | `f/14` = 285.714 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 249.997        | `f/16` = 250.000 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 222.219        | `f/18` = 222.222 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 199.998        | `f/20` = 200.000 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 0 | 181.815        | `f/22` = 181.818 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 166.664        | `f/24` = 166.667 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 153.884        | `f/26` = 153.846 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 142.855        | `f/28` = 142.857 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 0 | 133.331        | `f/30` = 133.333 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 124.998        | `f/32` = 125.000 |
| 0  | 0  | 0  | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 117.645        | `f/34` = 117.647 |
| 0  | 0  | 0  | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 60.605         | `f/66` = 60.606  |
| 0  | 0  | 0  | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 30.796         | `f/130` = 30.769 |
| 0  | 0  | 0  | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 15.504         | `f/258` = 15.504 |
| 0  | 0  | 0  | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 7.781          | `f/514` = 7.782  |
| 0  | 0  | 1  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 3.891          | `f/1026` = 3.897 |
| 0  | 1  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1.950          | `f/2050` = 1.951 |
| 1  | 0  | 0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0.975          | `f/4098` = 0.976 |
| 1  | 1  | 1  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0.488          | `f/8194` = 0.488 |

Some sample scope traces where:

* CH1 Yellow: 74LS73 Q2 (final output)
* CH2 Blue: clock
* CH3 Red: 74LS73 Q1 (final output)

DIP 000000000001b, expected output frequency 1MHz:

![scope_000000000001](./assets/scope_000000000001.gif?raw=true)

DIP 000000000111b, expected output frequency 250kHz:

![scope_000000000111](./assets/scope_000000000111.gif?raw=true)

### Protoboard Build

![protoboard_build](./assets/protoboard_build.jpg?raw=true)
![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

## Credits and References

* [ARRL's Hands-on Radio Experiments Volume 2](https://www.goodreads.com/book/show/40198290-arrl-s-hands-on-radio-experiments-volume-2) - H. Ward Silver, Experiment 97, p91
* [CD4001 datasheet](https://www.futurlec.com/4000Series/CD4001.shtml)
* [CD4027 datasheet](https://www.futurlec.com/4000Series/CD4027.shtml) Dual J-K Master/Slave Flip-Flop with Set and Reset
* [CD4040 datasheet](https://www.futurlec.com/4000Series/CD4040.shtml)
* [74LS73 Datasheet](https://www.futurlec.com/74LS/74LS73.shtml) Dual Negative-Edge-Triggered Master-Slave J-K Flip-Flops with Clear and Complementary Outputs
