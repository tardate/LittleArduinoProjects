# #519 555 Continuity Tester

A low-resistance continuity tester in a solder tube. Runs on 3V with a 555 timer buzzer.

![Build](./assets/ContinuityTester_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/pZHrtnM3dWI/0.jpg)](https://www.youtube.com/watch?v=pZHrtnM3dWI)

## Notes

This cicruit is based on a [circuit from www.555-timer-circuits.com](http://www.555-timer-circuits.com/continuity-tester.html),
but with a few modifications. It uses a 555 timer to generate the "continuity" tone, and has the nice property that
power is normally off until continuity detected (a good battery saver).

The original circuit is however triggered with even a quite high resistance between the probes (like up to 1MΩ).
I'm planning to use this for PCB testing instead of using a multimeter, so I've modified it
to only trigger when resistance is less than about 200Ω.

## Circuit Design

Key modifications from the original circuit:

* replaced the speaker driver with an N-FET/piezo output
* added an LED indicator
* changed the continuity switching circuit to an N-FET/P-FET combination geared for detecting only low resistance paths
* components selected/tested for operating from a 3V batttery

Note: the 555 is typically rated to required 4.5V minimum, so operating at 3V is testing the limits. In practice,
it seems to operate sufficiently well in this application.

The continuity detection is a simple low/high FET switch with probes completing a voltage divider trigger:

* I'm using MOSFETs to assist with getting a reasonably sharp on/off transition
* the continuity probes complete the pull-up of the first n-channel MOSFET (Q1)
  * R1 and R2 are selected so that a low resistance between the probes will turn on the FET
  * but a probe resistance above aroung 200Ω will be too high to generate a sufficient gate voltage to turn on the FET
  * R1 and R2 are quite low values in order for low probe resistances to effect a relatively steep voltage curve
  * when in use, this means up to [5mA](https://www.wolframalpha.com/input/?i=3V%2F%28220%CE%A9%2B330%CE%A9%29) dissipated through the probes - not great for efficiency
* since the voltage divider approach is setup for a small on-resistance band, it typically doesn't turn the N-FET fully "on",
  * to compensate for this, I have it in turn switching a p-channel FET
  * the P-FET has a high value pull-up resistor, so only a modest signal from the N-FET will switch the P-FET on hard (and hence the buzzer circuit)

An afterthought that I haven't had a chance to test yet: I could probably put another resistor at the source of Q1 and use it as a virtual ground for the
probe/pull-up; as long as this still allows enough headroom for sufficient Vgs, it should achieve the low resistance threshold while also minimising power loss
through the closed probe contact.

An alternative and more precise detection circuit would probably employ a comparator, for example along the lines of:

* [Improved W4ZCB Latching Continuity Tester](http://nerdfever.com/improved-w4zcb-continuity-tester/) - uses an opamp comparator for 25Ω continuity threshold
* [sarahemm/continuity_tester](https://github.com/sarahemm/continuity_tester) - nice design with wheatstone bridge and opamp for low resistance threshold detection

I've stuck with the FET switch approach for simplicity and low component count.

![Breadboard](./assets/ContinuityTester_bb.jpg?raw=true)

![Schematic](./assets/ContinuityTester_schematic.jpg?raw=true)

Testing on a breadboard:

![ContinuityTester_bb_build](./assets/ContinuityTester_bb_build.jpg?raw=true)

## Tester in a Bottle

I dediced to squeeze a freeform version of the circuit into an old solder tube..

![assembly_1](./assets/assembly_1.jpg?raw=true)

The 555 oscillator and output FET:

![assembly_555](./assets/assembly_555.jpg?raw=true)

I'm going to use a CR1216 3V battery for power. I don't have a suitable holder that will also fit in the tube,
so I'm going to squish it between two washers.

![assembly_2](./assets/assembly_2.jpg?raw=true)

"I'm sure this will fit in the tube." Turned out to be a finicky @#%$ exercise..

![assembly_3](./assets/assembly_3.jpg?raw=true)

Finally, all assembled and working.

![Build](./assets/ContinuityTester_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [BS250 datasheet](https://www.futurlec.com/Transistors/BS250.shtml)
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
* [CONTINUITY TESTER Circuit](http://www.555-timer-circuits.com/continuity-tester.html) - 555-timer-circuits.com
* [An automated scheme for continuity checks of the 50Ω terminated end of RPC Pickup Panels](http://www.sympnp.org/proceedings/59/G57.pdf)
* [A low resistance ( 0.25 - 4 ohm) continuity tester for checking soldered joints and connections](https://web.archive.org/web/20130305152525/http://www.zen22142.zen.co.uk/Circuits/Testgear/connectiontester.htm)
* [Improved W4ZCB Latching Continuity Tester](http://nerdfever.com/improved-w4zcb-continuity-tester/) - uses an opamp comparator for 25Ω continuity threshold
* [sarahemm/continuity_tester](https://github.com/sarahemm/continuity_tester) - nice design with wheatstone bridge and opamp for low resistance threshold detection
