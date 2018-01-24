# #345 mostap

Upgrading the tap to **modern** CMOS and MOSFET technology, circa 1975 - another Boldport Club retro classic.
The mostap is a touch sensor using NAND-gate flip-flops and FET output drivers.

Here's a quick demo of it in action..

[![Build](./assets/mostap_build.jpg?raw=true)](http://www.youtube.com/watch?v=TFuhajrzV-M)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The MOS TAP circuit was originally published in Elektor magazine in Feb 1975.
It was an update or the original TTL [Tap](../tap) circuit to use
"state-of-the-art" COSMOS (CMOS) components.

In practical terms, that means [4000-series logic](https://en.wikipedia.org/wiki/4000_series)
instead of [7400-series logic](https://en.wikipedia.org/wiki/7400_series).

The Boldport Club version of this venerable circuit makes an additional improvement by
replacing the output stage BJT drivers with 2N7000 n-channel MOSFETs so that it really does
live up to it's name.

### COSMOS?

I love the name! The Elektor article is the first time I've come across it.
As far as I can figure CMOS was initially marketed with "COS/MOS" labeling by RCA .. so it's a trade name that was displaced by CMOS as an industry standard term.

Interestingly, the name appears to have re-emerged in recent times with the
[DARPA COSMOS program](https://www.darpa.mil/program/compound-semiconductor-materials-on-silicon) .. geared towards high speed SoC-type applications.
See also ["Beyond CMOS" from 2013](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3928903/).


## Parts and Unboxing

| Ref            | Item                                                          | Qty |
|----------------|---------------------------------------------------------------|-----|
| R1,3,5,7,9,12  | 10MΩ resistor Multicomp MCF 0.25W 10M                         |  x6 |
| R2,4,6,8,10,11 | 1MΩ resistor Multicomp MCF 0.25W 1M                           |  x6 |
| R13            | 2.7MΩ resistor Multicomp MCF 0.25W 2M7                        |  x1 |
| C1             | 47nF capacitor Suntan TS15001H473MSBUB0R                      |  x1 |
| C2             | 470pF capacitor Suntan TS15001H471KSBPA0R                     |  x1 |
| IC1-3          | Quad 2-input NAND gate TI CD4011BE                            |  x3 |
| T1-5           | MOSFET n-channel transistor Fairchild 2N7000_D26Z             |  x5 |
| D1-5           | Small signal diode Diotec 1N4148                              |  x5 |
|                | IC DIP 14 contact socket TruConnect DS1009-14                 |  x3 |
|                | 20-pin 2.54mm header Multicomp MC34739                        |  x1 |
|                | Lovely lovely copper PCB                                      |  x1 |


![kit_unbox](./assets/kit_unbox.jpg?raw=true)
![kit_parts](./assets/kit_parts.jpg?raw=true)
![kit_pcb_front](./assets/kit_pcb_front.jpg?raw=true)
![kit_pcb_rear](./assets/kit_pcb_rear.jpg?raw=true)

## Construction

The MOSTAP is designed to be chainable, but I only have one so I am not using the modifications for chaining
(dash-dot lines in the schematic).
In the stand-alone configuration:

* 5 sensors with flip-flops and output drivers (touch pad A, B, C, D, E)
* the final flip-flop (X) is configured as a monostable reset
* touch-pad X resets the flip-flops

[![Schematic](./assets/mostap_schematic.png?raw=true)](https://github.com/boldport/mostap/raw/master/docs/schematics.pdf)

![mostap_build_front](./assets/mostap_build_front.jpg?raw=true)

![mostap_build_rear](./assets/mostap_build_rear.jpg?raw=true)

### Initial Breadboard Test

Works OK on a breadboard, but it is a bit cumbersome..

![mostap_breadboard_test](./assets/mostap_breadboard_test.jpg?raw=true)

### A MOSTAP Test Jig

I decided to whip together a test jig mounted on the Boldport box. It features:

* power connector and power LED
* female header for all output connectors
* for each open-drain output:
  * LEDs and 470Ω current limiting resistors on each open-drain output
  * 12kΩ pull-ups (so logic-level output is available)
* reset bus push-button (momentarily pulls-down the reset bus)
* common bus push-button (momentarily pulls-up the common bus)

Here's a sketch of the layout I used:

![mostap_test_jig_layout](./assets/mostap_test_jig_layout.jpg?raw=true)

And the final build:

![mostap_test_jig_build](./assets/mostap_test_jig_build.jpg?raw=true)


### Operating Mode Modification

The wire link connecting touch pad X to the reset bus is responsible
for the "one-shot" behaviour. IF removed, then all outputs remain latched until explicitly reset.

Replacing the link with a switch allows the operating mode to be selected:

* open - latched mode. Outputs remain on until pad X touched/reset bus pulled low
* close - one-shot mode. Outputs remain on until another output is activated or all reset

![mostap_build](./assets/mostap_build.jpg?raw=true)

### Performance

The mostap performs excellently as a touch switch - with none of the bouncing and transients I'd seen in the original tap.

Here's a capture of a set of tap outputs when activated:

* CH1 (yellow) - A output
* CH2 (blue) - A' output

The mostap was mounted in my test jig for this, and the supply voltage set at 5V.

![scope_trigger](./assets/scope_trigger.gif?raw=true)

## Credits and References
* [MOS TAP](./assets/elektor-02-75-MOSTAP.pdf?raw=true) - original circuit and article from Elektor magazine February 1975
* [LEAP#285 The Tap](../tap) - Boldport Club project for the original BJT design
* [MOSTAP](https://www.boldport.com/products/mostap) - Boldport product information
* [MOSTAP](http://www.boldport.club/shop/product/977922148) - in the Boldport shop
* [MOSTAP](https://github.com/boldport/mostap) - OSH files on GitHub
* [MOSTAP](http://community.boldport.club/projects/p05-tap/) - club community site, packed with resources for the project
* [CD4011 datasheet](http://www.futurlec.com/4000Series/CD4011.shtml)
* [2N7000 datasheet](http://www.futurlec.com/Transistors/2N7000.shtml)
* [1N4148 Datasheet](http://www.futurlec.com/Diodes/1N4148.shtml)
* [4000-series logic](https://en.wikipedia.org/wiki/4000_series)
* [7400-series logic](https://en.wikipedia.org/wiki/7400_series)
* [..as mentioned on my blog](https://blog.tardate.com/2017/10/leap345-boldport-club-mostap.html)
