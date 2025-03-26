# #051 El Jarabe Tapatío - The Mexican Hat Dance

Play The Mexican Hat Dance on a piezo buzzer! Here's a quick demo:

[![JarabeTapatio](https://img.youtube.com/vi/oAiCtdJKnDU/0.jpg)](https://www.youtube.com/watch?v=oAiCtdJKnDU)

## Notes

A simplified version of the melody in scored in this [GuitarPro](./assets/Jarabe Tapatío simple melody.gpx) file.
It is the basis of the song played by the sketch.

### Amplification

The signal from the Arduino can be directly fed to a piezo, however this doesn't result in a very loud sound.

This circuit uses an LM 386 Low Voltage Audio Power Amplifier as a simple way to amplify the AC signal.
Given that we are only interested in the alternating signal, the amplifier input and output signals are isolated with capacitors.
The LM 386 is used in the default configuration, which results in a relatively low gain (x20) but that is sufficient for our purposes here.

### Construction

![The Breadboard](./assets/JarabeTapatio_bb.jpg?raw=true)

![The Schematic](./assets/JarabeTapatio_schematic.jpg?raw=true)

![The Build](./assets/JarabeTapatio_build.jpg?raw=true)

## Credits and References

* [LM 386 datasheet](https://www.futurlec.com/Linear/LM386N-1.shtml)
* Based on the [Arduino Tone](http://arduino.cc/en/Tutorial/Tone) example
* Enhanced with ideas from 9.2 Playing a Simple Melody in the [Arduino Cookbook](../../books/arduino-cookbook/)
