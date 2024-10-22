# #574 MicroSD WAV Player

A basic demonstration of playing a sound file (WAV) from an SD card with an Arduino.

![Build](./assets/WavePlayer_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/c4J7TjWiGJ0/0.jpg)](https://www.youtube.com/watch?v=c4J7TjWiGJ0)

## Notes

Microcontrollers generally have very limited memory, so playing audio samples of any complexity usually requires external storage.
An [SD card](https://en.wikipedia.org/wiki/SD_card) is a convenient option, as it can easily be prepared on most computers.

This is a quick test of an SD card reader with an Arduino to play an audio file from the SD card.

## MicroSD Card Module

I'm using one of the very common Micro SD card reader modules [from an aliexpress seller](https://www.aliexpress.com/item/4000002592780.html).

The module uses SPI, and includes level shifting and regulation so that it is 5V tolerant.

| Feature         | Min | Nominal | Max | Unit |
|-----------------|-----|---------|-----|------|
| Supply Voltage  | 4.5 |       5 | 5.5 | V    |
| Current         | 0.2 |      80 | 200 | mA   |
| Supported cards | MicroSD < 2Gb | | MicroSDHC < 32Gb | |


![module_functional](./assets/module_functional.jpg?raw=true)
![module_image](./assets/module_image.jpg?raw=true)

## Construction

I'm just using a pieze buzzer for output, without any current limiting resistor R1 (may be required depending on the piezo component).
Of course, any other audio output device could be substituted here.

![Breadboard](./assets/WavePlayer_bb.jpg?raw=true)

![Schematic](./assets/WavePlayer_schematic.jpg?raw=true)

![Build](./assets/WavePlayer_build.jpg?raw=true)

## Code

The [TMRpcm Library](https://github.com/TMRh20/TMRpcm) does all the heavy lifting of reading the sound file and streaming the audio output.
It uses the [Arduino SD Library](https://www.arduino.cc/en/reference/SD) under the covers.

I've kept the demo code in `WavePlayer.ino` super-simple - it just plays a single given file (`SAMPLE.WAV`) when the push-button is pressed.

## Preparing the Audio

I'm using a short sample - included in the `sample` folder as an [Audacity](https://www.audacityteam.org/) project.

The sample has been reduced to mono 16kHz, and exported to `sample.wav` as an unsigned 8-bit PCM file.
This file is then written to the SD card.

![audacity_export](./assets/audacity_export.jpg?raw=true)

## Credits and References

* [1pcs/lot Micro SD card mini TF card reader module SPI interfaces with level converter chip for arduino](https://www.aliexpress.com/item/4000002592780.html) - aliexpress seller
* [TMRpcm Library](https://github.com/TMRh20/TMRpcm) - GitHub
* [Arduino SD Library](https://www.arduino.cc/en/reference/SD)
* [SD card](https://en.wikipedia.org/wiki/SD_card) - wikipedia
* [Audacity](https://www.audacityteam.org/)
* [Arduino Wave Audio Player with SD Card](https://simple-circuit.com/arduino-wave-audio-player-sd-card/)

