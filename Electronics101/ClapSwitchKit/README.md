# #170 ClapSwitchKit

Build and analyse a simple clap switch circuit available as a kit

Here's a quick video of the kit in action:

[![ClapSwitchKit Demo](http://img.youtube.com/vi/sou727DP5S4/0.jpg)](http://www.youtube.com/watch?v=sou727DP5S4)

## Notes

Here's a simple circuit that's available as a cheap kit - "shopping-cart stuffing".
There are no unusual components so aside from the PCB, everything you need is probably already in your parts bins.

![Parts](./assets/ClapSwitchKit_parts.jpg?raw=true)

The core of the circuit is a set-reset flip flop implemented with BJTs - similar to the [RSFlipFlop](../RSFlipFlop) project.

A momentary pulse from the electret is amplified with Q1/Q2 and triggers the Q3/Q3 flip:
* the cap C5/C6 on the side of the flip-flop that is "off" will charge momentarily
* when Q2 shuts-off, the charged cap voltage offset will reverse-bias the corresponding D1/D2
* causing the corresponding BJT to be enabled and trigger the flip/flop

The output LEDs are driven with a push/pull configuration of Q6 and Q7.
Q6 and Q7 are driven with complementary base "inputs" (Q5 prividing the inverted signal for Q7).

So when the right-hand output of the flip-flip (tapped at the Q4 collector) is "low":
* Q6 will be on (D3 conducting via Q4)
* Q7 is off (Q5 base pulled low via D4/R12/Q4)
* therefore LED1 (green) off, and LED2 (red) on

And when the right-hand output of the flip-flip is "high":
* Q6 will be off (D3 reverse biased)
* Q7 on (D4 reverse biased, so Q7 based pulled high by R13)
* therefore LED1 (green) on, and LED2 (red) off

## Construction

![Breadboard](./assets/ClapSwitchKit_bb.jpg?raw=true)

![The Schematic](./assets/ClapSwitchKit_schematic.jpg?raw=true)

![The Build](./assets/ClapSwitchKit_build.jpg?raw=true)

## Credits and References
* LEAP: [ClapSwitchKit2](../ClapSwitchKit2) - another clap-switch kit project
* [Clap Switch DIY Kit](http://www.aliexpress.com/item/Brand-New-Clap-Switch-Suite-Electronic-Production-DIY-Kits-Red-Green-LED-Display-Circuit/32416781115.html) - from a seller on aliexpress, USD1.70 at time of purchase
* [Wikipedia: Flip-flop](http://en.wikipedia.org/wiki/Flip-flop_%28electronics%29)
* [RSFlipFlop](../RSFlipFlop) project demonstrating the basic set-reset flip flop circuit implemented with BJTs
