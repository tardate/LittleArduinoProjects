# #552 Freeform Popsicle Airways

aka Aircraft Navigation Lights!

Demonstrating a simple aircraft navigation beacon sequence implemented with a couple of 555 timers.

![Build](./assets/AircraftNavigationLights_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/AiXiwGwCQng/0.jpg)](https://www.youtube.com/watch?v=AiXiwGwCQng)

## Notes

I came across this [Aircraft Navigation Beacon circuit](http://www.talkingelectronics.com/projects/50%20-%20555%20Circuits/50%20-%20555%20Circuits.html#Beacon) and thought it was an interesting trick to achieve with some 555 timers.
It runs white LED beacons that flash twice then delay 2 seconds before repeating.

These apparently simulate [anti-collision strobe lights](https://en.wikipedia.org/wiki/Navigation_light#Aviation_navigation_lights) for aircraft.

After a few tweaks found the circuit works reasonably well, however it is very touchy and component values need to be carefully selected in order to get the timing right.

To show the circuit off a little better, I fashioned a little aeroplane model from some popsicle sticks that sits proudly atop a 9V battery.

## Construction

The circuit uses two 555 timers running as astable oscillators.

The first 555 timer provides the basic on/off cycle, with a very low duty cycle since D1 diode steering selects a different resistor for charge/discharge:

* on time is governed by R1/C1 (470kΩ, 2.2µF) [nominally 0.7s](https://visual555.tardate.com/?mode=astable&r1=0&r2=470&c=2.2)
* off time is governed by R2/C1 (2MΩ, 2.2µF) [nominally 3s](https://visual555.tardate.com/?mode=astable&r1=0&r2=2000&c=2.2)

The second 555 timer provides the oscillator for the LEDs.

* frequency is governed by R3/C2 (1MΩ, 220nF) [nominally 3.2Hz](https://visual555.tardate.com/?mode=astable&r1=0&r2=1000&c=0.22)
* is only enabled (vai pin 4) when the first 555 timer output is high

![Breadboard](./assets/AircraftNavigationLights_bb.jpg?raw=true)

![Schematic](./assets/AircraftNavigationLights_schematic.jpg?raw=true)

Testing on a breadboard:

![AircraftNavigationLights_bb_build](./assets/AircraftNavigationLights_bb_build.jpg?raw=true)

In order to ensure two LED flashes each cycle, the on time of the first timer must be just right for the frequency of the second timer. I fiddled around with component values a bit to get it "close". Still not perfect; here's a scope trace showing how my "on time" is just a little bit too short to get two equal flashes each cycle:

* CH1 (Yellow) - timer 1 output
* CH2 (Blue) - timer 2 output

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [project page on hackaday.io](https://hackaday.io/project/179479-freeform-popsicle-airways)
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [Aircraft Navigation Beacon](http://www.talkingelectronics.com/projects/50%20-%20555%20Circuits/50%20-%20555%20Circuits.html#Beacon) - talkingelectronics
