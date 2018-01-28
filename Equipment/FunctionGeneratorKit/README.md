# #282 FunctionGeneratorKit

Build and test a function generator kit based on the XR-2206 monolithic function generator.

![Build](./assets/FunctionGeneratorKit_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I couldn't resist checking out this reasonably cheap [Function Generator Kit](https://www.aliexpress.com/item/Function-Signal-Generator-DIY-Kit-Sine-Triangle-Square-Output-1Hz-1MHz-Signal-Generator-Adjustable-Frequency-Amplitude/32733774803.html) from a seller on aliexpress.

The XR-2206 monolithic function generator is a pretty capable chip that can do a whole lot more than is required for this function generator (like sweep and AM/FM synthesis). The part now appears to be obsolete however, which probably explains why it is showing up
in a flood of kits similar to this one.

Note that I used a 9V battery for my tests and it seemed to function just fine, although this may have been under-powering the chip:
the XR-2206 is actually rated for a supply range of 10V to 26V.

Performance is remarkably good - see the scope traces below.

There are perhaps only two significant drawbacks of this circuit:

* there is no feedback or calibration of actual frequency and amplitude being generated. If the details matter, it is necessary to also hookup an oscilloscope or frequency counter.
* the analog controls - despite having a "fine adjust" - make it quite hard to dial in precise frequencies
* there's no warning or protection against clipping the output when amplitude control set too high

NB: GreatScott! reviewed the same kit in his [7$ Function Generator VS 107$ Function Generator](https://www.youtube.com/watch?v=GopZJKdCqrA) video, and pointed out some other issues:

* relatively high 600~1000Ω output impedance so can't drive much load
* no DC offset control

### Parts

The kit comes with a custom acrylic case and some decent instructions in English.

![kit_parts](./assets/kit_parts.jpg?raw=true)

The PCB front and rear:

![kit_pcb_front](./assets/kit_pcb_front.jpg?raw=true)

![kit_pcb_rear](./assets/kit_pcb_rear.jpg?raw=true)

## Construction

Takes only a few minutes to solder:

![kit_soldered](./assets/kit_soldered.jpg?raw=true)

![Schematic](./assets/FunctionGeneratorKit_schematic.jpg?raw=true)

Completed build:

![Build](./assets/FunctionGeneratorKit_build.jpg?raw=true)

## Performance

Performance is remarkably good.

At 1kHz the waveforms are pretty pure as one would expect. Here is the scope showing

* CH1 (yellow): square wave output
* CH2 (blue): sine wave output

![scope_1khz](./assets/scope_1khz.gif?raw=true)

The FFT of the sine wave has a decently low noise floor.

![scope_1khz_fft](./assets/scope_1khz_fft.gif?raw=true)


Pushing the device to the extreme, the highest frequency it will generate for me is 1.237MHz.
At this level, the output waveforms are distorted however still recognisable and probably quite usable for some applications:

![scope_1Mhz](./assets/scope_1Mhz.gif?raw=true)

The FFT of the sine wave remains quite respectable:

![scope_1Mhz_fft](./assets/scope_1Mhz_fft.gif?raw=true)


## Credits and References
* [Function Signal Generator DIY Kit Sine/Triangle/Square Output 1Hz-1MHz Signal Generator Adjustable Frequency Amplitude XR2206](https://www.aliexpress.com/item/Function-Signal-Generator-DIY-Kit-Sine-Triangle-Square-Output-1Hz-1MHz-Signal-Generator-Adjustable-Frequency-Amplitude/32733774803.html) - from a seller on aliexpress
* [XR-2206D data](http://parts.io/detail/8975104/XR-2206D) - parts.io
* [7$ Function Generator VS 107$ Function Generator](https://www.youtube.com/watch?v=GopZJKdCqrA) - review of the same kit by GreatScott!
* [..as mentioned on my blog](https://blog.tardate.com/2017/04/leap282-function-generator-kit.html)
