# #160 LM324/SplitterBuffer

Demonstrate load-independance of an LM324 buffer and signal-splitter


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

I'm considering using an LM324 as a buffer to split an input signal (up to 100kHz).
What I'm not sure of is how well it does at isolating the two split outputs. Hence this test.

I'm taking an input signal and feeding it into two quarters of an LM324,
with the LM324 units configured as voltage follower/buffer.

The load on each output is different - in the second I have a variable resistor to allow manual modification of the load.

What I'd like to see is 1:1 transmission of the input signal to the output of both op-amps, regardless of load.
Let's see...

For this test, I have the following setup:
* 5V single rail configuration (i.e. LM324 V- = GND, V+ = 5V)
* input signal FG is sourced from a signal generator at 3.5V DC offset and 1V peak-to-peak
* op-amp unit 1 has a fixed load of 10kΩ
* op-amp unit 2 has a variable load of 1kΩ + (0-10kΩ)

### Results

Here are some test results:
* CH1: input
* CH2: opamp 1 output
* CH3: opamp 2 output

At 1kHz, adjusting the load does not change the output of either opamp. Output signals are relatively undistorted.

![1kHz](./assets/SplitterBuffer_1kHz.gif?raw=true)

At 100kHz, adjusting the load still has no impact of the output of either opamp.
Output signals are somewhat phase-shifted. But this appears unrelated to the split configuration,
as it is the same as seen when just a single opamp is used.

![100kHz](./assets/SplitterBuffer_100kHz.gif?raw=true)

## Construction

![Breadboard](./assets/SplitterBuffer_bb.jpg?raw=true)

![The Schematic](./assets/SplitterBuffer_schematic.jpg?raw=true)

![The Build](./assets/SplitterBuffer_build.jpg?raw=true)

## Credits and References
* [LM324 Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)

