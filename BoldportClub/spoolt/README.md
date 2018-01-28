# #325 spoolt

Pimp my spoolt - the Boldport Club solder dispenser (Project #15, July 2017).

Here's a quick demo of it in action..

[![Build](./assets/spoolt_build.jpg?raw=true)](http://www.youtube.com/watch?v=mSZUleERjIs)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The latest Boldport Club project is a neat exercise in using the PCB as a structural element, similar to the impressive
[Bright Sparks 2017 Trophy](https://www.boldport.com/blog/2017/5/13/a-case-stufy-of-designing-a-trophy-for-engineers)
designed by Boldport.

In this project we have a simple solder spool holder/dispenser. In itself, a very pleasant way to while away a Sunday afternoon
with some solder construction, but its also a reminder and inspiration to consider how PCBs can also be
used as a structural element in a design.

The really nice thing is it actually works, and is now part of my actual solder station setup.
Usage tip: I found it works best fully loaded with solder and standing on what I think was originally intended as the back
(as in the pictures I have included here). It stands tall (minimal foot print), and the spools rotate and stay in place nicely without needing to tack the spindle.

### Pimp My Spoolt

But wait, where are the electronics?!

This is of course one of those projects just begging for some bells and whistles. Even some decorative adornments .. resistors and so .. would work well.

I decided it really needs LEDs (all things are better with LEDs). After examining the spoolt PCBs,
specifically where the continuity of the copper is maintained and where it breaks,
I discovered an arrangement for adding a scattering of SMD 0805 LEDs and an NPN Darlington pair for a touch-sensitive display:

* turns on when you pull solder from the dispenser (the solder makes contact with the touch-enabled part of the PCB and you provide the potential)
* turns on if you touch the front panel


I secreted the NPN transistors behind the front panel, using traces on the top and bottom of the panel for all the circuit connections.
A clear varnish (actually glue) to the non-touch parts of the PCB on the front panel prevents any shorts.

![spoolt_circuit_detail](./assets/spoolt_circuit_detail.jpg?raw=true)

## Construction

![spoolt_parts](./assets/spoolt_parts.jpg?raw=true)

Here's the circuit and layout of the simple Darlington pair touch-switch enabled LEDs.
With a 3V supply and red LEDs with a forward voltage of probably 2.1V, I've dispensed with any current limiting resistors as unnecessary.
There are 10 LEDs in parallel, although there's actually space for more.

![Breadboard](./assets/spoolt_bb.jpg?raw=true)

![Schematic](./assets/spoolt_schematic.jpg?raw=true)

![Build](./assets/spoolt_build.jpg?raw=true)

## Credits and References
* [spoolt](https://www.boldport.com/products/spoolt/) - Boldport Product Page
* [spoolt](http://community.boldport.club/projects/p15-spoolt/) - on the community site
* [2N3904 datasheet](http://www.futurlec.com/Transistors/2N3904.shtml)
* [LEAP#130 DarlingtonTouchSwitch](../../Electronics101/DarlingtonTouchSwitch) - more on Darlington touch switches
* [..as mentioned on my blog](https://blog.tardate.com/2017/07/leap325-pimp-my-boldportclub-spoolt.html)
