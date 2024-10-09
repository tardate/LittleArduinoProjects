# #497 Tesla Coil Plasma Speaker Kit

Playing with a Tesla coil circuit that also acts as an audio speaker with pulsing LED effects.

![Build](./assets/MusicalKit_build.jpg?raw=true)

Here's a quick demo, spinning a little [Baby Diner](https://www.youtube.com/watch?v=X76IXhqAEtE):

[![clip](https://img.youtube.com/vi/9yhTIx6dcRo/0.jpg)](https://www.youtube.com/watch?v=9yhTIx6dcRo)

## Notes

The "Mini Music Tesla Coil Plasma Speaker" is a pretty popular kit,
widely available on ebay or for example [here on aliexpress](https://www.aliexpress.com/item/4000030185359.html).
I was encouraged to pop one in my cart (USD6.29 at the time) after seeing the build video by NFM:

[![clip](https://img.youtube.com/vi/GdhTVwSygqo/0.jpg)](https://www.youtube.com/watch?v=GdhTVwSygqo)


### Kit and Parts

The kit may or not come with a schematic (mine didn't), but it is not needed for construction - only understanding!

Most sellers specify

* voltage: 15-24V DC
* current: 2A

Part list:

| Ref  | Item                                  | Qty  |
|------|---------------------------------------|------|
| C1   | 10µF 50V electrolytic capacitor       | 1    |
| C2   | 1µF 105J 100V polyester capacitor     | 1    |
| D1   | LED red                               | 1    |
| D2   | LED blue                              | 1    |
| R3,5 | 2kΩ resistor                          | 2    |
| D1,4 | 10kΩ resistor                         | 3    |
| Q1   | BD243C High Power NPN 100V            | 1    |
| Q2   | 80NF70 N-channel 68V Power MOSFET     | 1    |
|      | pre-wound coil                        | 1    |
|      | stereo audio socket                   | 1    |
|      | power jack                            | 1    |
|      | heatsink                              | 2    |
|      | 3.5mm stereo audio cable              | 1    |
|      | wire                                  | 15cm |
|      | strip double-sided tape               | 5cm  |
|      | screws                                | 8 (only 6 required) |
|      | brass standoffs                       | 4    |
|      | PCB                                   | 1    |


![kit_parts](./assets/kit_parts.jpg?raw=true)

![kit_pcb](./assets/kit_pcb.jpg?raw=true)

## Circuit Design

The circuit is based on what is commonly known as a "slayer exciter" version of a Tesla transformer.
The slayer exciter circuit uses feedback from the secondary coil to produce a self-governing oscillation.

This version of the circuit makes some clever additions:

* audio input modulates the current to the coil via the 80NF70 NFET (Q2)
* one LED is modulated by the audio input (D2)
* one LED is modulated by the coild oscillations input (D1)
* the audio-modulated coil (amazingly) vibrates and the plastic tube that is the core of the coil resonantes for this to act as a speaker!

![Schematic](./assets/MusicalKit_schematic.jpg?raw=true)

The essence of the circuit is the "slayer exciter" self-governing oscillation:

* Initially Q1 on, current flow builds in promarimy winding
* magnatic field induces currentin the secondary winding
* secondary sees a very small air-ground capacitor at one end, so initially cannot conduct but starts to pull Q1 base negative
* until Q1 base current throttled enough to turn off
* magnetic field collapses, and flyback voltage discharges into the air (generating a plasma!)

The scope trace below shows these the operation with VCC=14V and no audio input,
with channels connected to J1, J2, J3 (see schematic).

* CH1 (Yellow): J3
* CH2 (Blue): J1
* CH3 (Red): J2

![MusicalKit_scope](./assets/MusicalKit_scope.gif?raw=true)

Note the frequency: 3.9 MHz, just a bit above the 80m amateur radio band. This is a few components away from being a morse/CW transmitter;-)

My testing showed:

* at takes about 14V to start arcing
* increased up to 20V but after about 16V it doesn't have an appreciable affect on the arc or sound volume

Some measurements of actual power consumption at different voltages:

| Voltage | Current | Power |
|---------|---------|-------|
| 14V     | 0.5A    | 7W    |
| 18V     | 0.7A    | 13W   |


## Testing the Completed Kit

All finished:

![MusicalKit_build_complete](./assets/MusicalKit_build_complete.jpg?raw=true)

Here's a quick demo, spinning a little [Baby Diner](https://www.youtube.com/watch?v=X76IXhqAEtE):

[![clip](https://img.youtube.com/vi/9yhTIx6dcRo/0.jpg)](https://www.youtube.com/watch?v=9yhTIx6dcRo)

It can even be used as a basic nixie tube tester!

![testing_nixies](./assets/testing_nixies.jpg?raw=true)

## Credits and References

* [Mini Music Tesla Coil Plasma Speaker Tesla Wireless Transmission DIY Coil Kit](https://www.aliexpress.com/item/4000030185359.html) - example from aliexpress seller
* [Tesla Coil](https://en.wikipedia.org/wiki/Tesla_coil) - wikipedia
* [Tesla Transformer: Slayer-Exciter-Circuit](https://steemit.com/technology/@elektr1ker/tesla-transformer-slayer-exciter-circuit) - very good
* [Slayer Exciter Circuit with a Tesla Coil](https://www.electroboom.com/?p=521)
* [How to Build a Slayer Exciter](https://www.instructables.com/id/How-to-Build-a-Slayer-Exciter/) - but note theory of operation is a bit dodgy
* [Switched on Pop](https://www.switchedonpop.com/baby-shark/) - for tips on recovering from Baby Shark
