# #047 LDRStereoTripDetector - Low-light Trip Detector

Monitor two LDR sensors for stereo light-level triggering effects.

Here's a quick video of the circuit in action:

[![LDRStereoTripDetector demo](http://img.youtube.com/vi/Wo1voY0uE9c/0.jpg)](http://www.youtube.com/watch?v=Wo1voY0uE9c)



[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This demonstrates two circuit concepts:
* a light sensor comprising a light-dependent resistor (LDR) and [Wheatstone Bridge](http://en.wikipedia.org/wiki/Wheatstone_bridge).
* a threshold detector using an OpAmp comparator.

### Calibrating the Wheatstone Bridge

The particular LDR used has a range of about 200Ω (bright light) to 20kΩ (dark).
However the ambient light conditions used for testing the circuit exhibited a typical range of 2kΩ-5kΩ,
hence 4.7kΩ is selected as the common resistor value in the bridge so that we can drive positive and negative voltages from the bridge.
A 50kΩ variable resistor opposes the LDR, so that the actual threshold level can be trimmed.

The voltage differential measured across the bridge - from the base of the pot to the base of the LDR -
will tend to rise in lighter conditions as the LDR resistance drops.
As conditions get darker, the LDR resistance rises until a point there the voltage differential will go negative.

### Comparator

This voltage differential is fed to an OpAmp comparator (an LM324 Low Power Quad Op-Amp).
By feeding the LDR end of the differential to the negative input of the comparator, it acts as a low-threshold trigger.
Reversing the inputs to the comparator could be used for a high-threshold trigger.

Note: the circuit as described does not follow
[best practices for tethering the unused OpAmp units](http://www.electronicproducts.com/Analog_Mixed_Signal_ICs/Amplifiers/Properly_terminating_an_unused_op_amp.aspx)
 in the LM324 since this is only a test and it didn't have a noticable impact on behaviour.

### Behaviour

For plots of received light to triggering, see the [LDRComparator](../LDRComparator) project. It is pretty much identical
to this circuit except uses a single LDR only and monitors results with an Arduino.

### Construction

![The Breadboard](./assets/LDRStereoTripDetector_bb.jpg?raw=true)

![The Schematic](./assets/LDRStereoTripDetector_schematic.jpg?raw=true)

![The Build](./assets/LDRStereoTripDetector_build.jpg?raw=true)


## Credits and References
* [LM324 datasheet](http://www.futurlec.com/Linear/LM324N.shtml) - Low Power Quad Op-Amp
* [Properly terminating an unused op amp](http://www.electronicproducts.com/Analog_Mixed_Signal_ICs/Amplifiers/Properly_terminating_an_unused_op_amp.aspx)
* A similar application of an OpAmp is in "Project 06 - Hi-Lo Trip Detector" from [Beginning Digital Electronics Through Projects](http://www.amazon.com/gp/product/0750672692/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672692&linkCode=as2&tag=itsaprli-20&linkId=S6GVIV6DHZABMHTA)

