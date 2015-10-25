# LM324/SplitterBuffer

Demonstrate load-independance of an LM324 buffer and signal splitter

## Notes

I'm considering using an LM324 as a buffer to split an input signal (up to 100kHz).
What I'm not sure of is how well it does at isolating the two split outputs. Hence this test.

I'm taking an input signal and feeding it into two quarters of an LM324,
with the LM324 units configured as voltage followe/buffer.

The load on each output is different - in the second I have a variable resistor to allow manual modification of the load.

What I'd like to see is 1:1 transmission of the input signal to the output of both op-amps, ragardless of load.
Let's see...

For this test, I have the following setup:
* 5V single rail configuration (i.e. LM324 V- = GND, V+ = 5V)
* input signal FG is sourced from a signal generator at 3.5V DC offset and 1V peak-to-peak
* op-amp unit 1 has a fixed load of 10kΩ
* op-amp unit 2 has a variable load of 1kΩ + (0-10kΩ)

### Results

It seems to work. Adjusting the load does not change the output of either opamp.
* CH1: input
* CH3: opamp 1 output
* CH3: opamp 2 output

at 1kHz:

![1kHz](./assets/SplitterBuffer_1kHz.gif?raw=true)

at 100kHz:

![100kHz](./assets/SplitterBuffer_100kHz.gif?raw=true)


## Construction

![Breadboard](./assets/SplitterBuffer_bb.jpg?raw=true)

![The Schematic](./assets/SplitterBuffer_schematic.jpg?raw=true)

![The Build](./assets/SplitterBuffer_build.jpg?raw=true)

## Credits and References
* [LM324 Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)
* [name](url)

