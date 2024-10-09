# #381 CD4046/VCO

Audio range voltage-controlled oscillator using the CD4046 PLL/VCO IC.

![Build](./assets/VCO_build.jpg?raw=true)

## Notes

The 4046 includes a VCO sub-system in addition to phase comparators and other components.

As noted in the Art of Electronics (p291, Second Edition):

> When shopping for VCO chips, don't overlook the ICs known as phase-locked loops (PLL), which contain both a VCO and a phase detector.
> An example is the popular CMOS 4046 (and its faster cousin, the 74HC4046).

The VCO produces a square wave with 50% duty cycle, and a frequency range of approaching 0 Hz to over 1 MHz (1.3 MHz at 9V VDD).
The VCO frequency is determined by the voltage at VCO IN (pin 9).
Voltage-to-frequency linearity is about 1%.

The VCO can be used independently. This project is inspired by Ray Marston's "CMOS Clock Circuits" article,
and simply demonstrates using the VCO sub-system as a voltage-controlled
signal source with a frequency range in the audio spectrum of about 20 Hz to 20 kHz.

[![CD4046_functional_diagram](./assets/CD4046_functional_diagram.png?raw=true)](https://www.futurlec.com/4000Series/CD4046.shtml)


## Output

The datasheet I have doesn't include specific ratings for the VCO output, but seems to imply nothing greater than ~8mA.
The device does not really appear to be desinged to drive any significant load.

For that reason, I'm using the output to switch a load via a MOSFET.
While testing, I just had an LED indicator wired up.
Since I'm aiming for an audible range, this could be a speaker output.


## Determining Minimum and Maximum Frequency

External R/C components determine the minimum and maximum frequency of the VCO.

* C1 - across pins 6 and 7. C1 ≥ 50 pF
* R1 - connected to pin 11. R1 ≥ 10kΩ
* R2 - connected to pin 12. R2 ≥ 10kΩ

Minimum frequency (Fmin) is determined by C1 and R2 time constant.

Maximum frequency (Fmax) is determined by C1 and the R1||R2 parallel resistance time constant.

Although not mentioned in the datasheet, a "rule of thumb" estimate is 2 x time constant:

    fmin = 2/(C1R2)
    fmax = 2/(C1(R1||R2))

With  R1=10kΩ, R2=10MΩ, C1=10nF, these produce the following estimates:

* [fmin = 20Hz](https://www.wolframalpha.com/input/?i=2%2F(10nF+*10M%CE%A9))
* [fmax = 20kHz](https://www.wolframalpha.com/input/?i=2%2F(10nF+*1%2F(1%2F10M%CE%A9%2B1%2F10k%CE%A9)))

These are reasonably close to the 30Hz - 22.4kHz range I've measured in practice.


## Test Results

Measured for various combinations of R1, R2, C1:

| R1   | R2   | C1    | Fmin   | Fmax    |
|------|------|-------|--------|---------|
| 10kΩ | 1MΩ  | 100pF |  16KHz |  774kHz |
| 10kΩ | 1MΩ  | 100nF |   20Hz | 1.45kHz |
| 10kΩ | 10MΩ | 100nF |    1Hz | 1.39kHz |
| 10kΩ | 10MΩ | 100pF | 1.5kHz |  765kHz |
| 10kΩ | 10MΩ | 10nF  |   30Hz | 22.4kHz |


### Scope: R1=10kΩ, R2=10MΩ, C1=10nF

Measured minimum frequency:

![fmin](./assets/fmin.gif?raw=true)

Measured maximum frequency:

![fmax](./assets/fmax.gif?raw=true)


## Construction

![Breadboard](./assets/VCO_bb.jpg?raw=true)

![Schematic](./assets/VCO_schematic.jpg?raw=true)

![Build](./assets/VCO_build.jpg?raw=true)

## Credits and References

* [CD4046 Datasheet](https://www.futurlec.com/4000Series/CD4046.shtml)
* CMOS Clock Circuits - Ray Marston. Radio-Electronics, November 1984.
* [Practical Oscillator Handbook](https://www.goodreads.com/book/show/3365243-practical-oscillator-handbook) - includes a page on CD4046 VCO
* [Practical Oscillator Circuits](https://www.goodreads.com/book/show/12491266-practical-oscillator-circuits) - apparently has good coverage of CD4046 VCO (I haven't read it)
* [The Art of Electronics](https://www.goodreads.com/book/show/569775.The_Art_of_Electronics)
