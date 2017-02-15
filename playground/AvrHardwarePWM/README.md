# #254 AvrHardwarePWM

All about hardware PWM and demonstrating the modes with the Arduino UNO/ATmega328.

![Build](./assets/AvrHardwarePWM_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

Arduino provides a great "out-of-the-box" PWM capability, but it does not provide a simply way to
modify the PWM frequency. To do that you need to work directly with the processor registers.

This is my summary of hardware PWM control and example code.
[Secrets of Arduino PWM](https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM) is a great article
that goes into much more detail. It is the main source of information that I used, in addition to the
Atmel datasheet.

Although the concepts are general to the AVR processors, the details here and the example sketch
are specific to the Arduino UNO/ATmega328 and may require modification to work with other processors.

See the [AvrHardwarePWM/ATtiny](./ATtiny) project for a similar treatment, specifically for the ATtiny85 processor.

### Example Sketch

[ATmega.ino](./ATmega/ATmega.ino) exercises the PWM modes, primarily so they can be captured
with an oscilloscope. The push-button attached to pin 8 is used to cycle through a few demonstration modes:

* Mode 0a: Timer0, Fast PWM 977Hz
* Mode 1a: Timer1, Fast PWM 10-bit 1955Hz
* Mode 1b: Timer1, Phase Correct PWM, 8-bit 3906Hz
* Mode 2a: Timer2, Fast PWM 62.5kHz
* Mode 2b: Timer2, Fast PWM 977Hz

When the mode is changed, details of the new mode are sent to the Serial port, e.g

![demo_console](./assets/demo_console.png?raw=true)


### Three Approaches to PWM

If you need a PWM signal generated onboard, there are three approaches:

* use the standard library (pinMode/analogWrite). Works fine, but frequency is fixed.
* "bit-banging" i.e. manually toggling a digital output to simulate a PWM signal. While more flexible than the standard library, it ties up the processor and requires care to get the timing just right.
* directly control the PWM support built-in to the ATmega processor ("hardware PWM")

The rest of the notes here concern the third approach - hardware PWM.


### Hardware PWM - How it Works

There are basically four elements:

* Timer Control Registers TCCRx define the waveform generation mode
* Output Compare Registers OCRx define the upper compare limit (duty cycle)
* Processor clock / prescaler > Timer Clock -> increments TCNTx register
* Waveform generator produces the output in OCx according to TCCRx by comparing TCNTx with OCRx

![pwm_how_it_works](./assets/pwm_how_it_works.png?raw=true)

Summary of the TCCR registers:

![TCCR_summary](./assets/TCCR_summary.png?raw=true)


### Which Timer to Use?

In the ATMega328P there are three timers that can be used to generate PWM signals:

* Timer 0 is an 8-bit timer. But it is used for functions such as delay() and millis() - these will be affected if PWM frequency is changed.
* Timer 1 is a 16-bit timer; higher-precision duty cycle, but frequency is limited.
* Timer 2 is an 8-bit timer, and generally unencumbered (ready to use!)


| Compare Register | Timer output | Arduino output | Chip pin | Pin name |
|------------------|--------------|----------------|----------|----------|
| OCR0A            | OC0A         | 6              | 12       | PD6      |
| OCR0B            | OC0B         | 5              | 11       | PD5      |
| OCR1A            | OC1A         | 9              | 15       | PB1      |
| OCR1B            | OC1B         | 10             | 16       | PB2      |
| OCR2A            | OC2A         | 11             | 17       | PB3      |
| OCR2B            | OC2B         | 3              | 5        | PD3      |

Note:
* regardless of other settings, PWM output will only be generated on a pin if the pinMode is set to OUTPUT.
* the two outputs for each timer will normally have the same frequency, but can have different duty cycles.


### Timer Prescalers

Each timer has a prescaler that generates the timer clock by dividing the clock source by a prescale factor.
The clock source is normally the system clock, running at 16MHz on an Ardunio UNO. It is possible to use an external clock - see 17.3 in the datasheet.

The Timer 0 and Timer 1 prescaler is set in the TCCR0 ,TCCR1 registers (CS12, CS11, CS10).

For Timer 0 and Timer 1:
* the prescaler is set in the TCCR0 ,TCCR1 registers (bits CS12, CS11, CS10)
* the prescaler options are: 1, 8, 64, 256, or 1024.

The Timer 2:
* the prescaler is set in the TCCR2 register (bits CS22, CS21, CS20).
* For Timer 2, the prescaler options are: 1, 8, 32, 64, 128, 256, or 1024.



### Waveform Generation Modes

Main modes of interest:

* Fast PWM - counts up and resets on 1 extra clock pulse (hence prone to off-by-1 errors)
* PWM, Phase correct - counts up and down, avoids the off-by-1 error by half the frequency


### _BV Macro

In the example sketch I'm using the _BV macro to set register values.
This avoids hard-coding bit-offsets.

More info in the [AVR Libc Reference Manual](http://www.atmel.com/webdoc/AVRLibcReferenceManual/FAQ_1faq_use_bv.html).


### Controlling Duty Cycle with analogWrite

See the [analogWrite](https://www.arduino.cc/en/Reference/analogWrite) reference.

`analogWrite(pin, dutyCycle)`

Where:

* dutyCycle is a value from 0 (always off) and 255 (always on)
* pin is one of the PWM pins (3, 5, 6, 9, 10, or 11)

The digitalWrite() function turns off PWM output if called on a timer pin.


### Performance

These results were measured with the [ATmega.ino](./ATmega/ATmega.ino) sketch and an oscilloscope.


#### Mode 0a: Timer0, Fast PWM 977Hz

```
0a> Switching to Timer0 on pin 5, 6
  Fast PWM  : WGM01 WGM00
  Clear OC0A/OC0B on Compare Match, set OC0A/OC0B at BOTTOM (COM0A1/COM0B1)
  Frequency : 16MHz/64/256 = 977Hz (CS01 CS00)
  Pin 6     : (127+1)/256 = 50% duty cycle (OCR0A)
  Pin 5     : (191+1)/256 = 75% duty cycle (OCR0B)
GTCCR: 0
TCCR0A : 10100011
TCCR0B : 11
OCR0A  : 1111111
OCR0B  : 10111111
TCCR1A : 1
TCCR1B : 10
OCR1A  : 1111111
OCR1B  : 10111111
TCCR2A : 11
TCCR2B : 100
OCR2A  : 1111111
OCR2B  : 10111111
```

![mode_0a](./assets/mode_0a.gif?raw=true)

#### Mode 1a: Timer1, Fast PWM 10-bit 1955Hz

```
1a> Switching to Timer1 on pin 9, 10
  Fast PWM, 10-bit : WGM12 WGM11 WGM10
  Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM (COM1A1/COM1B1)
  Frequency : 16MHz/8/0x3FF = 1955Hz (CS11)
  Pin 9     : (510+1)/0x3FF = 50% duty cycle (OCR1A)
  Pin 10    : (766+1)/0x3FF = 75% duty cycle (OCR1B)
GTCCR: 0
TCCR0A : 11
TCCR0B : 11
OCR0A  : 0
OCR0B  : 0
TCCR1A : 10100011
TCCR1B : 1010
OCR1A  : 111111110
OCR1B  : 1011111110
TCCR2A : 11
TCCR2B : 100
OCR2A  : 1111111
OCR2B  : 10111111
```

![mode_1a](./assets/mode_1a.gif?raw=true)

#### Mode 1b: Timer1, Phase Correct PWM, 8-bit 3906Hz

```
1b> Switching to Timer1 on pin 9, 10
  Phase Correct PWM, 8-bit : WGM10
  Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM (COM1A1/COM1B1)
  Frequency : 16MHz/8/0xFF/2 = 3906Hz (CS11)
  Pin 9     : (127)/0xFF = 50% duty cycle (OCR1A)
  Pin 10    : (191)/0xFF = 75% duty cycle (OCR1B)
GTCCR: 0
TCCR0A : 11
TCCR0B : 11
OCR0A  : 0
OCR0B  : 0
TCCR1A : 10100001
TCCR1B : 10
OCR1A  : 1111111
OCR1B  : 10111111
TCCR2A : 11
TCCR2B : 100
OCR2A  : 1111111
OCR2B  : 10111111
```

![mode_1b](./assets/mode_1b.gif?raw=true)

#### Mode 2a: Timer2, Fast PWM 62.5kHz

```
2a> Switching to Timer2 on pin 3, 11
  Fast PWM  : WGM21 WGM20
  Clear OC2A/OC2B on Compare Match (COM2A1/COM2B1)
  Frequency : 16MHz/1/256 = 62.5kHz (CS20)
  Pin 11    : (127+1)/256 = 50% duty cycle (OCR2A)
  Pin 3     : (191+1)/256 = 75% duty cycle (OCR2B)
GTCCR: 0
TCCR0A : 11
TCCR0B : 11
OCR0A  : 1111111
OCR0B  : 10111111
TCCR1A : 1
TCCR1B : 10
OCR1A  : 1111111
OCR1B  : 10111111
TCCR2A : 10100011
TCCR2B : 1
OCR2A  : 1111111
OCR2B  : 10111111
```

![mode_2a](./assets/mode_2a.gif?raw=true)

#### Mode 2b: Timer2, Fast PWM 977Hz

```
2b> Switching to Timer2 on pin 3, 11
  Fast PWM  : WGM21 WGM20
  Clear OC2A/OC2B on Compare Match (COM2A1/COM2B1)
  Frequency : 16MHz/64/256 = 977Hz (CS22)
  Pin 11    : (127+1)/256 = 50% duty cycle (OCR2A)
  Pin 3     : (191+1)/256 = 75% duty cycle (OCR2B)
GTCCR: 0
TCCR0A : 11
TCCR0B : 11
OCR0A  : 1111111
OCR0B  : 10111111
TCCR1A : 1
TCCR1B : 10
OCR1A  : 1111111
OCR1B  : 10111111
TCCR2A : 10100011
TCCR2B : 100
OCR2A  : 1111111
OCR2B  : 10111111
```

![mode_2b](./assets/mode_2b.gif?raw=true)




## Construction

![Breadboard](./assets/AvrHardwarePWM_bb.jpg?raw=true)

![Schematic](./assets/AvrHardwarePWM_schematic.jpg?raw=true)

![AvrHardwarePWM_breadboard](./assets/AvrHardwarePWM_breadboard.jpg?raw=true)

## Credits and References
* LEAP: [AvrHardwarePWM/ATtiny](./ATtiny) project for a similar treatment, specifically for the ATtiny85 processor
* [analogWrite](https://www.arduino.cc/en/Reference/analogWrite)
* [Atmel ATmega328P Product Info](http://www.atmel.com/devices/ATMEGA328P.aspx)
* [ATmega168/328-Arduino Pin Mapping](http://www.arduino.cc/en/Hacking/PinMapping168)
* [Secrets of Arduino PWM](https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM)
* [What is all this _BV() stuff about?](http://www.atmel.com/webdoc/AVRLibcReferenceManual/FAQ_1faq_use_bv.html) - AVR Libc Reference Manual
* [..as mentioned on my blog](http://blog.tardate.com/2017/02/leap254-avr-hardware-pwm.html)
