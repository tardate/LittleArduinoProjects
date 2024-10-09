# #514 FM Converter

Playing with a simple FM frequency conversion circuit, and demonstrating how it can be used for external tuning.

![Build](./assets/FrequencyConverter_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/jncR-viUNDc/0.jpg)](https://www.youtube.com/watch?v=jncR-viUNDc)

## Notes

[Frequency converter](https://www.electroschematics.com/frequency-converter/) circuits are used to shift a
signal band. A common application in the past was to shift VHF/UHF TV signals (say ~35.3 MHz) to the
FM broadcast band so they could be received with a normal FM radio.

Although I've no practical use for this, it is interesting to investigate how it is achieved with so few components.

The idea and design for my build comes from Lechoslowianin's video on Youtube:

[![clip](https://img.youtube.com/vi/X4NbhIQ6Z84/0.jpg)](https://www.youtube.com/watch?v=X4NbhIQ6Z84)

## Construction

I've made a few modifications and component substitutions.

* BF245 n-channel depletion mode JFET - replaced by J201
* AAP155 germanium diode - replaced with 1N60P
* C1, originally 47pF, replaced with 5pF
* C2, originally 51pF, replaced with variable capacitor (actual range 9pF - 52pF)
* L1: total ~0.48µH. 0.9mm copper wire, 9 turn air coil ~30mm long, ø8mm, with tap on the 4th turn from ground
* L2: 8.5µH. About 30 turns of 0.1mm enamelled wire on ø5.5mm adjustable inductor shell with ferrite core

These may be far from ideal, but are what I arrived at for a workable circuit that transposes the FM broadcast band
(rather than shift another band into the FM broadcast band).
As built, this circuit is more like an external FM tuner rather than a band converter.

Performance? Not that great - very sensitive and prone to hum - but it basically works.
Here's my version of the circuit in [EasyEDA](https://easyeda.com/tardate/fmconverter):

[![Schematic](./assets/FrequencyConverter_schematic.png?raw=true)](https://easyeda.com/tardate/fmconverter)

How does it work? To be honest, I only have a sketchy appreciation so far.
The tank circuit is pretty self-explanatory (FM tuner), but I think the magic occurs between the inductor tap and "peak detector" diode, producing the frequency-shift.
I'd like to get a handle on the theory for how the band conversion calculations could be done, but a bit more research is required first.

## Credits and References

* [BF245 datasheet](https://www.onsemi.com/pub/Collateral/BF245A-D.PDF)
* [J201 datasheet](https://www.futurlec.com/Transistors/J201.shtml)
* [AAP155 germanium diode](https://www.radiomuseum.org/tubes/tube_aap155.html)
* [1N60P datasheet](https://www.futurlec.com/Diodes/1N60P.shtml)
* [frequency converter](https://www.electroschematics.com/frequency-converter/)
