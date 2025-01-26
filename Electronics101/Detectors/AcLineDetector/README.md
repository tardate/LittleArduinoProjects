# #535 AC Line Detector

Playing around with a simple AC line current detector.

![Build](./assets/AcLineDetector_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/SgX1PESmsKk/0.jpg)](https://www.youtube.com/watch?v=SgX1PESmsKk)

## Notes

There are a bunch of suggested circuits for simple AC line detection if you just google.

This is a quick build of a common approach - essentially using an antenna to stimulate a "triple Darlington" cascade of NPN transistors for extreme gain.

## Construction

The most common circuit is perhaps this design. It is powered from 9V,
with resistors sized for current-limiting the transistors and load (usually and LED, piezo or both):

[![common_circuit](./assets/common_circuit.png?raw=true)](https://www.jameco.com/Jameco/workshop/jamecofavorites/non-contact-AC-voltage-detector.html)

The circuit I've built here is however sized for a lower voltage. I've seen examples running from 4.5V, but I'm pushing the extreme end at 3V.
To achieve that, all resistors are eliminated, and the construction of the antenna starts to become more significant.

Since we're detecting 50/60Hz hum, the resonant frequency of the antenna is not particularly important,
it is more a case of having sufficient inductance to tap enough energy to trigger the detector (I think).

![Schematic](./assets/AcLineDetector_schematic.jpg?raw=true)

![Breadboard](./assets/AcLineDetector_bb.jpg?raw=true)

## Breadboard Test

I initially tested the circuit on a breadboard:

![AcLineDetector_bb_build](./assets/AcLineDetector_bb_build.jpg?raw=true)

A quick demo showing it actually working:

[![clip](https://img.youtube.com/vi/qbaslZapmZA/0.jpg)](https://www.youtube.com/watch?v=qbaslZapmZA)

## Final Build

Finalizing the circuit, attached to a 2xAAA battery holder:

![AcLineDetector_build](./assets/AcLineDetector_build.jpg?raw=true)

## Credits and References

* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [How to Make an AC Line Detector](https://www.instructables.com/id/How-to-Make-an-AC-Line-Detector/)
* [How to Build Your Own Non-contact Voltage Detector](https://www.jameco.com/Jameco/workshop/jamecofavorites/non-contact-AC-voltage-detector.html)
* [Top 3 Electronics Project With BC547 transistor](https://www.youtube.com/watch?v=LLsDq0cN2H8) - by SR electric; one of the projects was the inspiration for this build
* [Non-contact AC voltage detector circuit using CD4060](https://www.eleccircuit.com/non-contact-ac-detector-voltage-tester-using-cd4060/)
* [mains hum and static electrocity detector](https://www.edaboard.com/showthread.php?309680-mains-hum-and-static-electrocity-detector)
* [RIDICULOUSLY SENSITIVE ELECTRIC CHARGE DETECTOR](http://amasci.com/emotor/chargdet.html)
