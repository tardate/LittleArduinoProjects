# #297 CD4070/Oscillator

Examine a classic CD4070 oscillator design and variations.

![Build](./assets/Oscillator_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

There's a widely-shared circuit of a "square wave generator with CD4070", for example a circuit that is intended to run at 2 MHz:

[![canonical-circuit](./assets/canonical-circuit.png?raw=true)](http://www.next.gr/circuits/Square-wave-generator-with-CD4070-l23572.html)

I had a few spare minutes so I thought I'd give it a go. Should be straight-forward, looks like a familiar oscillator circuit
based on logic gates.

Well, not so fast. I found this configuration extremely temperamental on a breadboard, and the output is more sinusoid than square.
It also made me wonder about the performance of this circuit with buffered and unbuffered versions of the chip.

Ultimately, I came up with three workable variants of this circuit. All interesting, but none worth much for practical purposes
as the stability and output characteristics are very poor. But they do work, after a fashion!


### Check - Are my Chips Bufferred or Unbufferred?

Newer versions of the CD4070 are almost guaranteed to be buffered designs and should have the "B" suffix indicates a buffered circuit.

I can't find any current datasheets for unbuffered versions of the CD4070, but I understand that umpteen years ago they probably would have been unbuffered - which may be when the oscillator circuit dates from. This [TI application note](http://www.ti.com/lit/an/scha004/scha004.pdf) explains the difference very well, and how this can result in different behaviour.

As a diversion, I thought I'd verify my chips really are the buffered design (my source is not necessarily guarateed to give me chips that live up to their labeling).

The TI application note gives a good hint on a decent test: plot output to input voltage.
Buffered design should deliver a sharp step-change, while the unbuffered design will exhibit a more gradual change.

So I plugged a signal generator into the chip and plotted the X-Y input versus output. This looks like definitive buffered behaviour:

![scope-buffer-test-xy](./assets/scope-buffer-test-xy.gif?raw=true)

### Circuit Variations

So, somewhat disatisfied with my first build of the cribbed circuit on a breadboard, I started experimenting with variations.

First, I never saw clean square waves, so I buffer all the outputs via a CD4069 inverter to sharpen them up.

Ultimately, I came up with three variations that are quite interesting:

* variant on the cribbed circuit (but with output tapped directly from the XOR output)
* variant on the cribbed circuit without the capacitor to ground
* RC circuit between inputs, with a variable capacitor to provide some measure of frequency trim

In all cases, the achieved frequency will vary with supply voltage.

To eliminate the noise and stray capacitance of a breadboard, I put the three circuits on a protoboard for evaluation.

![protoboard_layout](./assets/protoboard_layout.jpg?raw=true)

![Oscillator_build_solo](./assets/Oscillator_build_solo.jpg?raw=true)


### Variant A: R feedback, C to ground

The first quarter of the CD4070 runs a variant on the cribbed circuit (but with output tapped directly from the XOR output).
This produces a free running 1.5MHz oscillation at 5V

* CH2: CD4070 first XOR output
* CH1: CD4069 rectified output

![scope-variant-a](./assets/scope-variant-a.gif?raw=true)


### Variant B: R feedback

The second quarter of the CD4070 runs a variant on the cribbed circuit without the capacitor to ground.
This produces a free running 6.4MHz oscillation at 5V

* CH2: CD4070 second XOR output
* CH1: CD4069 rectified output

![scope-variant-b](./assets/scope-variant-b.gif?raw=true)


### Variant c: RC feedback

The third quarter of the CD4070 runs a variant with RC circuit between XOR inputs, with a variable capacitor (40-120pF) to provide some measure of frequency trim. This produces a free running oscillation that can be trimmed from around 7.02MHz to about 7.08MHz at 5V

* CH2: CD4070 third XOR output
* CH1: CD4069 rectified output

At minimum trim:

![scope-variant-c-min](./assets/scope-variant-c-min.gif?raw=true)

At maximum trim:

![scope-variant-c-max](./assets/scope-variant-c-max.gif?raw=true)


## Construction

![Breadboard](./assets/Oscillator_bb.jpg?raw=true)

![Oscillator_breadboard_build](./assets/Oscillator_breadboard_build.jpg?raw=true)

![Schematic](./assets/Oscillator_schematic.jpg?raw=true)

![Oscillator_build_solo](./assets/Oscillator_build_solo.jpg?raw=true)

## Credits and References
* [CD4070 Datasheet](http://www.futurlec.com/4000Series/CD4070.shtml)
* [CD4069 datasheet](http://www.futurlec.com/4000Series/CD4069.shtml)
* [Square wave generator with CD4070](http://www.next.gr/circuits/Square-wave-generator-with-CD4070-l23572.html)
* [Understanding Buffered and Unbuffered CD4xxxB Series Device Characteristics](http://www.ti.com/lit/an/scha004/scha004.pdf) - TI AppNote
* [..as mentioned on my blog](http://blog.tardate.com/2017/05/leap297-cd4070-oscillator.html)
