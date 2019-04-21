# #259 DigitalPots/M62429

Control the M62429 dual channel volume control with an Arduino.

![Build](./assets/M62429_build.jpg?raw=true)


## Notes

I'm trying out some digital potentiometers for an application. This is a test of the M62429.

The M62429 is a dual channel electronic volume control:

* dual channel, with independant channel control
* Volume 0 to -83dB (1dB/step)
* Vcc = 4.5 to 5.5V
* controlled with a simple serial data protocol

The chip is primarily designed for audio applications as:

* volume levels are set on a logarithmic scale (dB)
* it centres the output around VCC/2

It does work with both AC and DC signals however.

The programming interface is a very simple two-wire (data, clock) serial protocol.
But being so simple (and having a strange command length of 11 bits) it's not really possible to use either
the standard Wire or SPI libraries. Time for some bit-banging!

### Protocol

![data_format](./assets/data_format.png?raw=true)

* Reads data signal at the rising edge of clock signal
* Reads latch signal at the falling edge of clock
* Clock cycle time: min 4µs
* Clock pulse width: min 1.6µs
* Clock rise/fall time: max 0.4µs
* Data setup time: min 0.8µs
* Data hold time: min 0.8µs


### Level Encoding

| D6 | D5 | D4 | D3 | D2 | D8 | D7 | Level |
|----|----|----|----|----|----|----|-------|
|  0 |  0 |  0 |  0 |  0 |  x |  x |  -∞dB |
|  0 |  0 |  0 |  0 |  1 |  0 |  0 | -83dB |
|  0 |  0 |  0 |  0 |  1 |  0 |  1 | -82dB |
|  0 |  0 |  0 |  0 |  1 |  1 |  0 | -81dB |
|  0 |  0 |  0 |  0 |  1 |  1 |  1 | -80dB |
|  0 |  0 |  0 |  1 |  0 |  0 |  0 | -79dB |
|  . |  . |  . |  . |  . |  . |  . |    .. |
|  1 |  0 |  1 |  0 |  0 |  1 |  1 |  -4dB |
|  1 |  0 |  1 |  0 |  1 |  0 |  0 |  -3dB |
|  1 |  0 |  1 |  0 |  1 |  0 |  1 |  -2dB |
|  1 |  0 |  1 |  0 |  1 |  1 |  0 |  -1dB |
|  1 |  0 |  1 |  0 |  1 |  1 |  1 |   0dB |


### Performance

The [M62429.ino](./M62429.ino) sketch is a simple exercise of the chip.

* input for both channels is AC-coupled 1kHz sine wave
* left channel is set to max volume
* right channel volume is stepped up through all gradations

Here is a capture of two frames of clock/data output from the Arduino, captured with a logic analyzer:

![la_capture](./assets/la_capture.png?raw=true)

The first sequence reads: `11011101011` + latch (data high on falling clock). That breaks down as:
* `11` 2CH, channel at a time
* `01110` ATT1: -28dB
* `10` ATT2: -2dB
* `11` end bits
* i.e. set channel 2 to -30dB

The first sequence reads: `11011100111` + latc:
* `11` 2CH, channel at a time
* `01110` ATT1: -28dB
* `01` ATT2: -1dB
* `11` end bits
* i.e. set channel 2 to -29dB

Yes, that's as expected - the script is sequencing through level settings on channel 2.


The scope trace tells the story of what is happening on the left and right channel outputs:

* CH1 (yellow) is DC-coupled left channel
* CH2 (blue) is the AC-coupled right-channel

![ac_test](./assets/ac_test.gif?raw=true)

Next test was with a 5V DC signal on left and right channel input.

* CH1 (yellow) is DC-coupled left channel
* CH2 (blue) is the DC-coupled right-channel, offset by -2.5V

![dc_test](./assets/dc_test.gif?raw=true)

## Construction

![Breadboard](./assets/M62429_bb.jpg?raw=true)

![Schematic](./assets/M62429_schematic.jpg?raw=true)

![Build](./assets/M62429_build.jpg?raw=true)

## Credits and References
* [M62429FP info & datasheet](http://parts.io/detail/5005065/M62429FP) - parts.io
* [AD5171 Digital Potentiometer](https://www.arduino.cc/en/Tutorial/DigitalPotentiometer) - tutorial
* [krupski/M62429](https://github.com/krupski/M62429) - M62429 support encapsulated in a library
* [..as mentioned on my blog](https://blog.tardate.com/2017/03/leap259-m62429-digital-pot.html)
