# #609 USB Audio Level Indicator Kit

An electret-input audio level kit based on cascading LM358 stages with LED indicators.

![Build](./assets/UsbLedVolumeIndicatorKit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/k13FuwNF-LE/0.jpg)](https://www.youtube.com/watch?v=k13FuwNF-LE)

PS: [Samba do Cajón - Abellán Oficial](https://www.youtube.com/watch?v=DX3VwDKX4Gc)

## Notes

This 20-LED audio volume indicator kit is widely available from sellers on aliexpress - mine came
[from WAVGAT Official Store](https://www.aliexpress.com/item/1005002730758395.html).

It is USB powered, and uses an electret microphone for sound input.

It produces a very nice symmetrical display, pumping out to right and left as the volume increases.

### Kit Specifications

Voltage: 5-12V
LED: 12 green, 8 red
Board size: 160mm x 18.5mm

![kit-parts](./assets/kit-parts.jpg?raw=true)
![kit-pcb](./assets/kit-pcb.jpg?raw=true)
![kit-manual](./assets/kit-manual.jpg?raw=true)

### Parts List

| Item                             | Qty  | Ref |
|----------------------------------|------|-----|
| 2kΩ                              | 1    | R28 |
| 1kΩ                              | 1    | R24 |
| 510Ω                             | 11   | R26,27,22,21,18,17,14,13,9,10,5 |
| 5.1kΩ                            | 3    | R6,4,2 |
| 100Ω                             | 4    | R11,12,7,8 |
| 1N5819                           | 1    | D23 |
| 1MΩ                              | 1    | R3 |
| 500kΩ trimmer                    | 1    | RP1 |
| 1N4148                           | 2    | D1,22 |
| 430Ω                             | 2    | R23,22 |
| 200Ω                             | 3    | R19,16,15 |
| 10kΩ                             | 2    | R25,1 |
| 104, 100nF                       | 2    | C1,3 |
| 5mm Red LED                      | 8    | D14-21 |
| 5mm Green LED                    | 12   | D2-13 |
| LM358                            | 6    | U1-6 |
| DIP8 socket                      | 6    | U1-6 |
| electret mic                     | 1    | MIC1 |
| 100µF electrolytic               | 1    | C2 |
| 4.7µF electrolytic               | 1    | C4 |
| micro USB socket                 | 1    | K1 |

### Circuit Design

Here's my redrawing of the circuit using Fritzing, so any errors are mine.
Layed out this way, the circuit behaviour is easily apparent. A quick summary:

* the electret mic is based with a conventional input circuit wit the AC signal offset and fed to LM358 (U1a) op-amp, configured as a non-inverting amplifier with the amplification (sensitivity) set with RP1
* LM358 (U1b) buffers the signal and outputs the "audio reference signal"
* the audio reference signal is fed to 10 op-amp units used as comparators against 10 discrete voltage levels
    * the 10 discrete voltage levels are set with a multi-stage voltage divider
    * each op-amp output drives two LEDs (left and right)

![schematic](./assets/UsbLedVolumeIndicatorKit_schematic.jpg?raw=true)

The circuit is actually the basis of the LM3915 that I covered in 
[#065 LevelIndicatorLM3915](https://leap.tardate.com/playground/LevelIndicatorLM3915/) and 
[#202 Audio Level Indicator Kit](https://leap.tardate.com/audio/visualization/audiolevelindicatorkit/).
Note that the resistors are not identical on the LM3915, but form a logarithmic scale. If a linear scale is needed, there is the LM3914 that is otherwise identical. Linear scale is usually better for voltage control of batteries, and logarithmic one for audio level.

Construction complete:

![build01](./assets/build01.jpg?raw=true)

## Next Step

The unit works very well, even on 4.5V (3xAA).
I'm thinking of making a case for it next with option of battery or USB power.

## Credits and References

* [USB audio spectrum lamp kit LED car volume level indicator music audio display circuit board to increase the hands-on ability](https://www.aliexpress.com/item/1005002730758395.html) - kit from aliexpress seller WAVGAT Official Store
* [LM358N Datasheet](https://www.futurlec.com/Linear/LM358N.shtml)
* [1N4148 Datasheet](https://www.futurlec.com/Diodes/1N4148.shtml)
* [1N5819 Datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
