# #364 Classic Nokia 3310 Ringtone

Just a quick transcription of the classic Nokia 3310 ringtone for Arduino.

![Build](./assets/ClassicNokia_build.jpg?raw=true)

Here's a quick demo..

[![U6u6AV16lg8](https://img.youtube.com/vi/U6u6AV16lg8/0.jpg)](https://www.youtube.com/watch?v=U6u6AV16lg8)

## Notes

For obscure reasons, I wanted a version of the classic Nokia ringtone on an Arduino. So...

I transcribed the score in [Guitar Pro](./assets/nokia_3310_ringtone.gp),
see the
[PDF](./assets/nokia_3310_ringtone.pdf)
and [MusicXML](./assets/nokia_3310_ringtone.xml)
exports.

I borrowed the basic sketch structure from [LEAP#051 El Jarabe Tapatío](../JarabeTapatio).

For a quick test, I'm not using any amplification, simply an 8Ω speaker and a 100Ω current-limiting resistor on the tone pin.

## Construction

![Breadboard](./assets/ClassicNokia_bb.jpg?raw=true)

![Schematic](./assets/ClassicNokia_schematic.jpg?raw=true)

![Build](./assets/ClassicNokia_build.jpg?raw=true)

## Credits and References

* [LEAP#051](../JarabeTapatio) -  El Jarabe Tapatío
* [Arduino library: tone](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap364-classic-nokia-ringtone.html)
