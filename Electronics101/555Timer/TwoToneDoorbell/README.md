# #059 555Timer/TwoToneDoorbell

A basic two-tone doorbell using a 555 timer oscillator, with n-channel FET for power conservation.

Here's a quick video of the circuit in action:

[![TwoToneDoorbell](http://img.youtube.com/vi/yD5Hbg0qQJE/0.jpg)](http://www.youtube.com/watch?v=yD5Hbg0qQJE)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

When the button is pressed, it triggers three actions:

* 555 timer reset (4) is pulled high and charges the R4/C2 RC circuit
* it bypasses R1 (via D1) so that 555 astable behaviour is governed by R2/R3/C1
* it pulls Q1 gate high and charges the R5/C4 RC circuit

While the button is down ("ding"), the frequency of 555 astable oscillation
is governed by [R2=47kΩ, R3=47kΩ and C1=33nF](http://visual555.tardate.com/?mode=astable&r1=47&r2=47&c=0.033),
which results in a frequency of about 309Hz.

When the button is released:

* R1 comes into play, reducing the 555 astable oscillation
* 555 remains triggered while C2 drains through R4

The "dong" frequency of 555 astable oscillation
is governed by [R1+R2=94kΩ, R3=47kΩ and C1=33nF](http://visual555.tardate.com/?mode=astable&r1=94&r2=47&c=0.033),
which results in a frequency of about 232Hz.

The duration of the "dong" depends on the R4/C2 [RC time constant (𝛕)](http://en.wikipedia.org/wiki/RC_time_constant),
[220ms](http://www.wolframalpha.com/input/?i=22k%CE%A9+*+10%CE%BCF).
When the voltage on pin 4 falls below the reset threshold (typically 0.5V), the oscillation stops.

The circuit remains "live" while Q1 permits drain-source current flow. Q1 will remain on while C4 discharges and maintains gate voltage above the gate threshold voltage.

A couple of bypass capacitors minimize the impact of voltage spikes and noise on the operation of the 555 timer, especially during transitions of the timer's output transistors:

* 100nF (C5) between control pin (5) and ground
* 100nF (C6) across the power supply

### Construction

![The Breadboard](./assets/TwoToneDoorbell_bb.jpg?raw=true)

![The Schematic](./assets/TwoToneDoorbell_schematic.jpg?raw=true)

![The Build](./assets/TwoToneDoorbell_build.jpg?raw=true)

### Protoboard Build

OK, this is a pretty crappy doorbell, but just for the heck of it I put the circuit on a protoboard and used as a
short-term replacement for a corroded/failed bell.

![Protoboard build](./assets/TwoToneDoorbell_pcb_build.jpg?raw=true)

![Protoboard layout](./assets/TwoToneDoorbell_pcb_layout.jpg?raw=true)


## Credits and References
* [2N7000 Datasheet](http://www.futurlec.com/Transistors/2N7000.shtml)
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [Two-tone Doorbell kit](http://cdselectronics.com/kits/two%20tone%20door%20bell.htm) - example of a similar circuit as a kit, using a mosfet for switching (looks like a very old site, not sure if still available).
* [Two-tone Doorbell kit](http://www.aliexpress.com/item/555-doorbell-kit-ding-dong-doorbell-kit-diy-electronic-kit-diy-digital-kit/1682713914.html) - another example circuit as a kit; this uses BJT for coupling the output speaker and an RC network to provide timed-on power.
