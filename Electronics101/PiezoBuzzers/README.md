# #455 Piezo Transducers and Buzzers

Exploring techniques for driving piezo transducers and buzzer units for audio output.

![Build](./assets/PiezoBuzzers_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/TUH7J-5sV4k/0.jpg)](https://www.youtube.com/watch?v=TUH7J-5sV4k)

## Notes

[Piezoelectric sensors](https://en.wikipedia.org/wiki/Piezoelectric_sensor) for generating sound are commonly found in two form factors:

* indicator (aka buzzer): complete piezoelectric unit including circuit to produce sound
  * just requires an applied voltage to produce sound - fixed frequency by default
  * may be combined with external circuitry to mix/alter the sound and frequency

* transducer: a basic piezoelectric diaphragm/disk
  * sometimes called a "passive" buzzer element
  * can be used as an input transducer as well as for sound generation
  * does not self-oscillate - requires external circuit to produce sound

![PiezoBuzzers](./assets/PiezoBuzzers.jpg?raw=true)

## Driving Piezoelectric Indicators

Piezoelectric indicators (aka buzzers) are simple voltage-controlled devices.
Typically used as alarms or action feedback indicators.
They come in a range of forms - from the very cheap suited to breadboard experiments through
to quality devices suited to security alarm installations.

Driving a piezoelectric indicator is simple - it just needs a voltage applied.

### Common PCB Mount

Available [for pennies](https://www.aliexpress.com/item/33026767889.html)
and ideal for PCB or breadboard prototyping
(however I have come across devices with leads that are far too thick to use on a breadboard without damaging it).
It is usually OK to even drive a 3-5V component directly from a 20mA-limit GPIO pin

[![buzzer_pcb1](./assets/buzzer_pcb1.jpg?raw=true)](https://www.aliexpress.com/item/33026767889.html)

### High Volume Alarms

Beefier devices are more suited to serious alarm purposes, for example this
[95dB SPL Continuous Sound Beeper](https://www.aliexpress.com/item/32783807336.html)

* Buzzer Type: Piezoelectric
* Sound Pressure Level 95 dB
* Rate Voltage: 12V DC
* Operating Voltage: 3 - 24V
* Max Current Rating 10mA
* Frequency 3900±500Hz
* Drive Method: Drive Circuit Built in Mounting Holes
* Sound: "Di" Continuous

[![buzzer_alarm1](./assets/buzzer_alarm1.jpg?raw=true)](https://www.aliexpress.com/item/32783807336.html)

![buzzer_alarm1_build](./assets/buzzer_alarm1_build.jpg?raw=true)

### Alarms with Effects

Sometimes the piezo indicator circuit has a built-in effect, like for example
[this device](https://www.aliexpress.com/item/32984518008.html)
which emits a beep every half a second or so.

* Sound Pressure Level 95 dB
* Rate Voltage: 12V DC
* Operating Voltage: 3 - 24V

[![buzzer_alarm2](./assets/buzzer_alarm2.jpg?raw=true)](https://www.aliexpress.com/item/32984518008.html)

![buzzer_alarm2_build](./assets/buzzer_alarm2_build.jpg?raw=true)

## Driving Piezoelectric Transducers

Piezoelectric Transducers require an external oscillator to produce sound output.

A common circuit for turning a Piezoelectric disk into a buzzer uses a low-side switch.
Plain piezo disks require a bypass resistor to dump the charge (else no sound will be produced).
Additional resistance can be added to limit current and reduce volume.

In the following test circuit, I have a 555 astable oscillator with variable resistor to generate
a pulse from about
[152 Hz](https://visual555.tardate.com/?mode=astable&r1=1&r2=100&c=0.047) to about
[10kHz](https://visual555.tardate.com/?mode=astable&r1=1&r2=1&c=0.047)

The 555 output switches a low-side 2N7000 n-channel FET.

I've selected a 10kΩ bypass resistor. Lower values start to attenuate the output.

A 2.2kΩ series resistor limits current without much impact on volume.

![Breadboard](./assets/PiezoBuzzers_bb.jpg?raw=true)

![Schematic](./assets/PiezoBuzzers_schematic.jpg?raw=true)

![Build](./assets/PiezoBuzzers_build.jpg?raw=true)

## Credits and References

* [Piezoelectric sensor](https://en.wikipedia.org/wiki/Piezoelectric_sensor) - wikipedia
* [Piezoelectric speaker](https://en.wikipedia.org/wiki/Piezoelectric_speaker) - wikipedia
* [Buzzer types](https://en.wikipedia.org/wiki/Buzzer) - wikipedia
* [Buzzer Basics - Technologies, Tones, and Drive Circuits](https://www.cuidevices.com/blog/buzzer-basics-technologies-tones-and-driving-circuits)
