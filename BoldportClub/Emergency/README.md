# #257 Emergency

Pimp the Boldport Club Emergency kit (Project #2) .. now a LED blinky with 3 passives and a transistor (Esaki Effect)

Here's a quick video to show it working..

[![Build](./assets/Emergency_build.jpg?raw=true)](https://www.youtube.com/watch?v=PPUZth8RfCE)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I joined the Boldport Club rather late, but manage to snaffle up the Emergency kit PCB in sale of ["Just Less the Perfect"](http://www.boldport.club/shop/product/437169103) boards.

The tiny 'engineer superhero' emergency kit, second edition was Boldport Club Project #2.

As originally intended, it is a kit with a few components and a nice travel case that will possibly save your engineering superhero status at some point!

With all the components soldered into the (of course beautiful) PCB, it works as a battery/continuity tester (the LED lights up if you apply voltage)

![Emergency_board_front](./assets/Emergency_board_front.jpg?raw=true)

![Emergency_board_rear](./assets/Emergency_board_rear.jpg?raw=true)


### Circuit Modifications

Since I'm working from scratch (PCB only - not the full kit), there's an obvious challenge to do something a bit different.

@mehradzie asked on [Boldport Slack](https://boldportclub.slack.com) if it is possible to make it blink. Challenge accepted!

I was actually thinking along similar lines, at first using a blinking "joule thief" circuit. But I just couldn't figure
how to get it to work within the constraints of the PCB.

So then I turned to an interesting idea: Negative Differential Resistance (NDR) effect or Esaki Effect. Basically causing an
Emitter-Collector avalanche, a behaviour noted by Leo Esaki and exploited by many since to create interesting effects with
BJTs.

After a bit of experimentation, I was able to get something to work with only a few liberties taken with the original PCB:

* I had to accommodate larger capacitor. Anything over ~100µF is workable, but best effects achieved with 330µF electrolytic. I selected the smallest package I could find, but it is still a bit of a squeeze to fit it in where the capacitor should be.
* an NPN BJT replaces the n-channel MOSFET. I'm using an S9013. Note: yes, this is in "backwards" (emitter to +ve, collector to -ve)
* moved one resistor to make wiring easier
* cut and rewired a few traces

Transistor selection is crucial, as the blinking effect is really exploiting a "defect" in the transistor.
Of all the small-signal NPN BJTs I had on hand, only two worked at all, or at reasonable voltages (S9013, S9018).
I went with the S9013 because I could excite the effect conveniently around 9V.

The revised circuit essentially works like this:

* battery charges the capacitor
* over a certain voltage, the emitter-collector junction experiences an avalanche and inrush of current from the capacitor
* the LED turns on
* as the capacitor discharges, the avalanche breaks down and the transistor junction closes
* repeat...

Here is a scope capture from a breadboard build/test:

* CH1 (yellow; AC-coupled): capacitor voltage
* CH2 (blue; AC-coupled): collector (LED anode) voltage

![scope](./assets/scope.gif?raw=true)


## Construction

![Breadboard](./assets/Emergency_bb.jpg?raw=true)

![Schematic](./assets/Emergency_schematic.jpg?raw=true)

Testing on a breadboard:

![Emergency_breadboard](./assets/Emergency_breadboard.jpg?raw=true)

Final layout and component selection. Build complete:

![Emergency_layout](./assets/Emergency_layout.jpg?raw=true)

Power on, and it's blinking! Why? Because!

![Build](./assets/Emergency_build.jpg?raw=true)

## Credits and References
* [Emergency](http://www.boldport.com/blog/2014/02/the-tiny-engineer-superhero-emergency.html) - on the Boldport blog
* [Emergency](http://www.boldport.club/shop/product/235066412) - in the Boldport shop
* [Emergency](https://github.com/boldport/emergency) - OSH files on GitHub
* [Emergency](https://bitbucket.org/boldport/pcbmode/wiki/The%20tiny%20engineer%20superhero%20emergency%20kit%20assembly%20guide) - assembly guide
* [Emergency](http://community.boldport.club/projects/p02-emergency/) - club community site, packed with resources for the project
* [A Negative Differential Resistance Oscillator with a Negistor](http://jlnlabs.online.fr/cnr/negosc.htm)
* [Simplest LED Flasher Circuit](http://www.cappels.org/dproj/simplest_LED_flasher/Simplest_LED_Flasher_Circuit.html)
* [World's Simplest Single Transistor Oscillator - BJT with Negative Resistance](https://www.youtube.com/watch?v=rpGOKGrcpAk&t=335s)
* [Leo Esaki](https://en.wikipedia.org/wiki/Leo_Esaki) - wikipedia
* [..as mentioned on my blog](https://blog.tardate.com/2017/02/leap257-blinking-emergency.html)
