# #458 FastAnalogRead

How to increase the Arduino ADC analog sampling rate.

![Build](./assets/FastAnalogRead_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The ATmega328P features a 10-bit successive approximation ADC with 8-channel analog multiplexer (to support multiple analog pins).

Three registers control the behaviour of the ADC:

* ADC MULTIPLEXER SELECT (ADMUX)
* ADCSRA – ADC Control and Status Register A
* ADCSRB – ADC Control and Status Register B

![ADMUX](./assets/ADMUX.jpg?raw=true)
![ADCSRA](./assets/ADCSRA.jpg?raw=true)
![ADCSRB](./assets/ADCSRB.jpg?raw=true)

### ADC Clock Frequency Recommendation

By default, the successive approximation circuitry requires an input clock frequency between 50kHz and 200kHz to get maximum resolution.
A normal conversion takes 13 ADC clock cycles.

The ADC clock may be run faster than 200kHz to get a higher sample rate, but resolution will suffer.

The data sheet quotes a sampling rate of up to 76.9kSPS, or up to 15kSPS at maximum resolution.
Given that 13 clock cycles are required for a normal sample,
this implies a maximum ADC frequency of up to [1MHz](https://www.wolframalpha.com/input/?i=76.9kHz*13),
or [195kHz](https://www.wolframalpha.com/input/?i=15kHz*13) at maximum resolution.

### Default ADC Clock Frequency

The ADC clock pre-scale is set with three bits of the ADCSRA register:

| ADPS2 | ADPS1 | ADPS0 | Division Factor |
|-------|-------|-------|-----------------|
|     0 |     0 |     0 | 2               |
|     0 |     0 |     1 | 2               |
|     0 |     1 |     0 | 4               |
|     0 |     1 |     1 | 8               |
|     1 |     0 |     0 | 16              |
|     1 |     0 |     1 | 32              |
|     1 |     1 |     0 | 64              |
|     1 |     1 |     1 | 128             |

The initial ADPSx values are 000 i.e. pre-scale by 2.
However the Arduino core adjusts the pre-scale factor during initialisation, see
[wiring.c](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/wiring.c#L353).
It picks that maximum pre-scale factor given the CPU frequency to keep the ADC clock within the 50kHz-200kHz band.

At 16MHz, the Arduino code sets a pre-scale of 128 (ADPSx = 111) i.e. [125kHz](https://www.wolframalpha.com/input/?i=16MHz%2F128).

### Increasing the Sampling Rate

The [FastAnalogRead.ino](./FastAnalogRead.ino) sketch demonstrates how to adjust the ADC pre-scaler.
In the example, it is set to 16 i.e. and ADC clock frequency of [1MHz](https://www.wolframalpha.com/input/?i=16MHz%2F16),
and reads a pot on analog pin A0.

Results from a sample run:

![console](./assets/console.png?raw=true)

```bash
FastAnalogRead
Initial ADC Settings: ADMUX = 0b0, ADCSRA = 0b10000111, ADCSRB = 0b0
100 readings with analogRead and standard prescaler = 128:
ADMUX = 0b0, ADCSRA = 0b10000111, ADCSRB = 0b0
Duration = 11312us
Read = 258, min = 258, max = 260
100 readings with analogRead and prescaler = 16:
ADMUX = 0b1000000, ADCSRA = 0b10000100, ADCSRB = 0b0
Duration = 1556us
Read = 259, min = 258, max = 259
100 readings with analogRead and standard prescaler = 128:
ADMUX = 0b1000000, ADCSRA = 0b10000111, ADCSRB = 0b0
Duration = 11256us
Read = 425, min = 425, max = 427
100 readings with analogRead and prescaler = 16:
ADMUX = 0b1000000, ADCSRA = 0b10000100, ADCSRB = 0b0
Duration = 1572us
Read = 427, min = 425, max = 428
100 readings with analogRead and standard prescaler = 128:
ADMUX = 0b1000000, ADCSRA = 0b10000111, ADCSRB = 0b0
Duration = 11252us
Read = 541, min = 540, max = 542
100 readings with analogRead and prescaler = 16:
ADMUX = 0b1000000, ADCSRA = 0b10000100, ADCSRB = 0b0
Duration = 1576us
Read = 541, min = 540, max = 543
```

### Bandwidth

The sampling rate directly constrains the bandwidth according to the [Nyquist-Shannon Theorem](https://en.wikipedia.org/wiki/Nyquist%E2%80%93Shannon_sampling_theorem).

Since one conversion takes 13 ADC clock cycles:

* at default Arduino ADC frequency of 125kHz, the bandwidth is [4.8kHz](https://www.wolframalpha.com/input/?i=125kHz%2F13%2F2)
* at the increased ADC frequency of 1MHz, the bandwidth is [38.5kHz](https://www.wolframalpha.com/input/?i=1MHz%2F13%2F2)

## Construction

![Breadboard](./assets/FastAnalogRead_bb.jpg?raw=true)

![Schematic](./assets/FastAnalogRead_schematic.jpg?raw=true)

## Credits and References

* [18.9. Measuring Analog Values Quickly](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU) - from the Arduino Cookbook
* [ATmega328P Product Info](https://www.microchip.com/wwwproducts/en/ATmega328P)
* [AVR120: Characterization and Calibration of the ADC on an AVR - AN_2559](https://www.microchip.com/wwwAppNotes/AppNotes.aspx?appnote=en591791)
* [analogRead()](https://www.arduino.cc/en/Reference/AnalogRead)
* [Nyquist-Shannon Theorem](https://en.wikipedia.org/wiki/Nyquist%E2%80%93Shannon_sampling_theorem)
