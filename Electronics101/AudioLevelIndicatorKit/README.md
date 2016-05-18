# #202 AudioLevelIndicatorKit

test an audio level indicator kit based on the LM3915

![The Build](./assets/AudioLevelIndicatorKit_build.jpg?raw=true)

## Notes

This is a build of an
[LM3915 Audio Level Indicator Kit](http://www.aliexpress.com/item/Hot-Selling-1-PCS-LM3915-Audio-Level-Indicator-DIY-Kit-Electronic-Production-Suite-Good/32285582534.html).
I picked it up for a few dollars from a seller on aliexpress. If nothing else, a cheap way to get an LM3915 and bunch of square LEDs.

Kit Specifications from the product page:

* Power supply voltage: DC9V - 12V
* PCB Size: 62mm * wide 27mm
* comprehensive PCB silk-screen

The circuit is a pretty minimal implementation of a standard LM3915 circuit with no frills,
but it does vary from the reference circuit in a couple of ways.

### Upper Reference Voltage

The upper reference voltage on the LM3915 is set with pin 6 REF HI.

In this circuit, it is set independantly of REF OUT/REF ADJ with a simple R6/R9 voltage divider:

* REF HI = [245mV](http://www.wolframalpha.com/input/?i=560%CE%A9%2F%2820k%CE%A9+%2B+560%CE%A9%29+*+9V) for 9V supply

This is below even −10 dBV, so the input signal requires futher attenuation before it can drive the LM3915 effectively

### Input Signal Processing

Input signal attenuation is achieved with R3/R7 10kΩ on each connection and the R4 50kΩ variable pot.
Since there's no coupling capacitor, that makes it possible to handle AC and DC signals.
Although, with DC you might need to consider ground levels and isolation, as the input circuit
puts 10kΩ between the external and internal grounds.

In fact here's a test where I'm measuring the input voltage sensitivity with a variable DC supply:

![AudioLevelIndicatorKit_dc_test](./assets/AudioLevelIndicatorKit_dc_test.jpg?raw=true)

There is no external rectification or peak detection in the circuit.
According to the LM3915 datasheet, it is designed to handle AC signals
direct on pin 5, and respond to positive half-cycles only but will not be damaged by signals up to ±35V.

For a better audio level display, I'd probably use a circuit like that described in this
[Sound Level Meter](http://www.aaroncake.net/circuits/vumeter.asp) post by Aaron Cake.

### LED Current

LED current is determined by the current on pin 7 REF OUT.
REF OUT is nominally 1.25V (I measured it at 1.236V) and goes to ground via R5,
so LED current is (only) [1.2mA](http://www.wolframalpha.com/input/?i=1.236V%2F1k%CE%A9).

This is quite low for LEDs, and far from the recommendation in the datasheet for handling AC signals:
"It’s recommended to use dot mode and to run the LEDs at 30 mA for high enough average intensity."

R2 is included as recommended for LED supply voltages above 7V, as it limits the voltage drop across the LM3915
and therefore the power it needs to dissipate.

### Mode Select

Jumper pin terminals are provided to seect either the dot or bar display mode:

* open: "dot" mode is where a single element lights to display the peak value
* closed: "bar" mode is where all elements light up in bar-graph fashion

Closing the jumper straps the LM3915 mode-select pin 9 to V+, putting it into "bar" mode.

## Construction

![Breadboard](./assets/AudioLevelIndicatorKit_bb.jpg?raw=true)

![The Schematic](./assets/AudioLevelIndicatorKit_schematic.jpg?raw=true)

![The Build](./assets/AudioLevelIndicatorKit_build.jpg?raw=true)

## Credits and References
* [LM3915 datasheet](http://www.futurlec.com/Linear/LM3915N.shtml)
* [LevelIndicatorLM3915](../../playground/LevelIndicatorLM3915) - project using the LM3915 to drive a display from an Arduino
* [kit on aliexpress](http://www.aliexpress.com/item/Hot-Selling-1-PCS-LM3915-Audio-Level-Indicator-DIY-Kit-Electronic-Production-Suite-Good/32285582534.html)
* [Sound Level Meter](http://www.aaroncake.net/circuits/vumeter.asp) - similar circuit
* [..as mentioned on my blog](http://blog.tardate.com/2016/05/littlearduinoprojects202-lm3915-audio.html)
