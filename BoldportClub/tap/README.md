# #285 The Tap

Harking back to a 7400-series logic circuit published in a 1974 Elektor article,
this retro Boldport Club project is a classic.

[![Build](./assets/tap_build.jpg?raw=true)](http://www.youtube.com/watch?v=WQKIWN_7tfE)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The [Touch Activated Programmer (TAP) Sensor from Elektor magazine of December 1974](./assets/elektor-12-74-TAP.pdf?raw=true) was a very early
example of a capacitive touch circuit.

And Boldport Club members were lucky enough to get a "modern" rendering of the same circuit.
The PCB design is as psychadelic as you would expect from a 70's vintage design. What is amazing is that the parts are still
quite readily available.

The PCB is well up to Boldport standards. Altough this can create some assembly confusion - you must pay close attention to
which side of the board the parts are inserted. It looks just as good both ways.

Electrically, touch pads A, B and C are connected to an NPN transistor pair in a Darlington configuration.
I've covered the operation of this kind of switch in [LEAP#130 DarlingtonTouchSwitch](../Electronics101/DarlingtonTouchSwitch).

All manner of outputs are provided. For each touchpad there are four:

* `Q`/`Q1¯` - the logic-level output and its complement
* `S`/`S¯` which are logically identical, but an open-collector configuration able to sink greater current

### Behaviour

| Action        | Q1 | Q1¯ | Q2 | Q2¯ | Q3 | Q3¯ |
|---------------|----|-----|----|-----|----|-----|
| At power-on   |  1 |  0  |  1 |  0  |  1 |  0  |
| Touch A       |  0 |  1  |  1 |  0  |  1 |  0  |
| Touch B       |  1 |  0  |  0 |  1  |  1 |  0  |
| Touch C       |  1 |  0  |  1 |  0  |  0 |  1  |
| Touch RESET   |  1 |  0  |  1 |  0  |  1 |  0  |


### S/S¯ and Q/Q¯ Outputs

S/S¯ and Q/Q¯ outputs follow the same logic behaviour.

It appears the only difference is that Q/Q¯ are mostly suited to digital integration as
they are limited in the current they can sink (16mA).

* Q and Q¯ source current, logic 1 : 0.4mA
* Q and Q¯ sink current, logic 0 : -16mA

The S/S¯ outputs are controlled with low-side NPN switches and can sink up to 1A -
the absolute maximum collector current for the PN2222ATA.
Higher currents would need closer attention to heatsinking and wire/connector ratings.

## RB (Reset Bar) and CB (Contact Bar)

The RB and CB pins are intended to allow chaining of mulitple sensor units with a common reset/contact bus.

### Parts and Unboxing

| Ref   | Item                                                          | Qty |
|-------|---------------------------------------------------------------|-----|
| T1-7, 9-14 | bipolar (BJT) single transistor NPN, Fairchild PN2222ATA | x13 |
| T8    | bipolar (BJT) single transistor PNP Fairchild BC556BTA        |  x1 |
| IC1,2 | NAND gate 4 gate, 2 input, TI SN7400                          |  x2 |
| D1-3  | Small signal diode 1V Multicomp 1N4148                        |  x3 |
| R1-3  | 100KΩ resistor, Multicomp MCF 0.25W 100K                      |  x3 |
| R4-7  | 10MΩ resistor, Multicomp MCF 0.25W 10M                        |  x4 |
| R8    | 1KΩ resistor, Multicomp MCF 0.25W 1K                          |  x1 |
| R9-15 | 27KΩ resistor, Multicomp MCF 0.25W 27K                        |  x7 |
| C1,2  | 220pF capacitor, Vishay K221J15C0GF53L2                       |  x2 |
| C3    | 47nF capacitor, Multicomp MC0805B472K500A5.08MM               |  x1 |
|       | 14-pin IC DIP socket , TE Connectivity 1-2199298-3            |  x2 |
|       | 20-contacts 2.54 mm header, Multicomp MC34739                 |  x1 |

![kit_unboxing1](./assets/kit_unboxing1.jpg?raw=true)
![kit_unboxing2](./assets/kit_unboxing2.jpg?raw=true)
![kit_parts](./assets/kit_parts.jpg?raw=true)
![kit_pcb_rear](./assets/kit_pcb_rear.jpg?raw=true)
![kit_pcb_front](./assets/kit_pcb_front.jpg?raw=true)

The transistor markings on the silkscreen threw me at first. They are special!
I was confused because they don't replicate the standard NPN/PNP schematic exactly.
Just focus on the arrow flow: NPN points out from the emitter; PNP points in to the emitter.

![transistor_symbols](./assets/transistor_symbols.jpg?raw=true)

## Construction

The Boldport and Elektor resources already provide thorough details of the circuit.
But as is my way, I just had to redraw the circuit. This time with Fritzing:

![Breadboard](./assets/tap_bb.jpg?raw=true)

![Schematic](./assets/tap_schematic.jpg?raw=true)


![kit_complete_rear](./assets/kit_complete_rear.jpg?raw=true)

![kit_complete](./assets/kit_complete.jpg?raw=true)

Running some initial current tests. It never peaks beyond 23mA.

![kit_initial_test](./assets/kit_initial_test.jpg?raw=true)

Hooked up for monitoring under test (analog scopea and logic analyzer)

![kit_scope_test](./assets/kit_scope_test.jpg?raw=true)

The final build:

![Build](./assets/tap_build.jpg?raw=true)

## Performance

The first trace I took was from a transition to "A" on (from RESET state).
CH1 shows Q1 output, CH2 shows Q1¯ output.
As we can see, there's some pre-emptive voltage reduction prior to the switch and some jitter and one significant bounce.
From this we can see that using the TAP as an input for a sensitive instrument would still need some debouncing.

![scope_A_analog](./assets/scope_A_analog.gif?raw=true)

Here is the same switch with alogic analyser. There's quite a delay (2-3µs) between the analog transition and the digital - but I think that is more the
scope than the circuit. The important point is that we still see one bounce at logic levels, and the other outputs are as expected.

* CH1 - Q1 output (trigger)
* D0 - Q1 output
* D1 - Q1¯ output
* D2 - Q2 output
* D3 - Q2¯ output
* D4 - Q3 output
* D5 - Q3¯ output
* D6 - unused
* D7 - unused

![scope_A_la](./assets/scope_A_la.gif?raw=true)

## Credits and References
* [Tap Sensor](./assets/elektor-12-74-TAP.pdf?raw=true) - original circuit and article from Elektor magazine December 1974
* [The Tap](https://www.boldport.com/products/the-tap/) - Boldport product information
* [The Tap](http://www.boldport.club/shop/product/344511320) - in the Boldport shop
* [The Tap](https://github.com/boldport/tap) - OSH files on GitHub
* [The Tap](http://community.boldport.club/projects/p05-tap/) - club community site, packed with resources for the project
* [SN7400N info and datasheet](http://parts.io/detail/931870/SN7400N) - parts.io
* [PN2222ATA info and datasheet](http://parts.io/detail/1027929/PN2222ATA) - parts.io
* [BC556BTA info and datasheet](http://parts.io/detail/1015198/BC556BTA) - parts.io
* [LEAP#130 DarlingtonTouchSwitch](../Electronics101/DarlingtonTouchSwitch)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap285-the-boldport-tap.html)
