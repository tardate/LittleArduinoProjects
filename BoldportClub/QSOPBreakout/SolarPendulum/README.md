# #296 QSOPBreakout Solar Pendulum

Build a solar-powered pendulum similar to the popular "solar wobble/flip-flop toys" on the Boldport QSOP breakout board.

Here's a quick video showing it in action on a quite overcast afternoon..

[![Build](./assets/SolarPendulum_build.jpg?raw=true)](https://www.youtube.com/watch?v=buP3zrMjN94)

## Notes

I have a spare BoldPort QSOP Breakout board and for a while I've been trying to find some interesting use for it. I think I've found one ...
a solar pendulum!

I discovered some new and creative solar wobble/flip-flap toys while travelling recently, which started me wondering how they work.
What is quite impressive is how well they work with only modest internal lighting and very small photovoltaic cells.

The trick appears to be in the switching of capacitor-backed pulses through a coil. There are some good teardowns available,
such as the one by
[Ludic Science](https://www.youtube.com/watch?v=M6L-d_dYWIc) and the excellent
[analysis by dmercer](https://ez.analog.com/community/university-program/blog/2015/04/27/solar-powered-motion-toy-tear-down),
but they all fall short because the interesting electronics in these toys are invariably potted.
I'm not sure if this is as much license-avoidance as it might be IP protection, as there are patents out there for such toys such as
[US3783550](https://www.google.com/patents/US3783550?dq=3783550&hl=en&sa=X&ei=X67xUqHPMoOZkQWA5IDYDw&ved=0CDMQ6AEwAA&pageId=105188957426397764872) and [101352268A](https://worldwide.espacenet.com/publicationDetails/biblio?CC=CN&NR=101352268A&KC=A&FT=D&ND=&date=20090128&DB=EPODOC&locale=en_EP).


After some more research, I found two practical circuits: the first being a
[Solar Powered Pendulum article](http://nutsvolts.texterity.com/nutsvolts/201208/?folio=32&pg=32#pg32) in Nuts & Volts,
and the second covered in the thoroughly useful [laboratory notebook](http://www.elektronik-labor.de/Labortagebuch/Tagebuch0716.html#pendel2)
edited by Burkhard Kainka.

I tried both circuits, and found that the Nuts & Volts approach appeared to work best for photovoltaics with lower driving power.


## Breadboard Prototype

I tested a few circuits on a breadboard, finally picking the approach from Nuts & Volts:

![SolarPendulum_bb_build](./assets/SolarPendulum_bb_build.jpg?raw=true)

## Solar Panel Selection

I wanted to go with the smallest solar panel I have available - a 25mm x 30mm unit with an open circuit voltage of around 1V.
It works just well enough in decent light.

I also tested a larger panel with open circuit voltage of around 3.5-4V; it works very well (sometimes too well), but is larger than I wanted to use.

For this reason I also selected the very-low-forward-voltage 1N5819 as the diode. General purpose NPN and PNP transistors provide the switching (2N3904/2N3906).

Note: if the pendulum is not swinging, gently hold the pendulum you should feel at least a weak pulse. If there's no pulse at all, take a closer look at the circuit to make
sure it is built correctly, but also check that the voltage from the PVC is sufficient to at least overcome the forward voltage of the diode.

## Sizing the Pendulum

The weight and arc of the pendulum are obviously important design factors as they influence the resonant frequency.
With such small electromagenetic pulses, we don't want the pendulum "fighting" the motive power.

Now I must admit I skipped the calculations for now. What I do know is that the pendulum is not ideal in my current build.
The weight is a little too much for the arc. It would probably work better with a longer arc (slowing it down).

I have small but relatively strong neodymium magnets on the end of the pendulum, oriented to be repelled when the coil is pulsed.

It also works when the magnets are oriented to be attracted when the coil is pulsed, but this tends not to work so well, as the timing of
ending the pulse becomes much more critical lest it act to dampen the pendulum oscillation.

I played around with the positioning to get the best effect - basically at rest, the pendulum is aligned just off-centre from the windings i.e. so when it is repelled, it will push the pendulum off in the right direction to start it swinging.

## Sizing the Coil

I fudged this also. The coil I'm using is perhaps 100+ turns of 0.2mm enamelled winding wire with 1cm outer diameter.
It is air-core. Works just well enough!

## Circuit

![Breadboard](./assets/SolarPendulum_bb.jpg?raw=true)

![Schematic](./assets/SolarPendulum_schematic.jpg?raw=true)


## QSOP Breakout Build

So the QSOP/0805 breakout ... is intended as a breakout board! But it has enough interesting features to make it
serviceable as the protoboard for this circuit.

Here is the QSOP Board during assembly, with all components fitted. I used SMD 0805 resistors but all other components
where through-hole.

![construction_1](./assets/construction_1.jpg?raw=true)

Rear of the board is where the coil is to ba attached. Only five bodge wires required, and they provided some fine pitch soldering practice!

![construction_2](./assets/construction_2.jpg?raw=true)

The coil in the final build is an air coil perhaps 100+ turns of 0.2mm enamelled winding wire, with a coil diameter of 16mm and width of 5mm.
With my LCR45 meter, it measures at 248µH, 3.6Ω (DC).

With coil attached..

![construction_3](./assets/construction_3.jpg?raw=true)

Here's the circuit layout I used on the QSOP/0805 circuit board.

![construction_4_layout](./assets/construction_4_layout.jpg?raw=true)

Final construction .. the base is a repurposed box from the Boldport Club [Tap project](../../tap).

![Build](./assets/SolarPendulum_build.jpg?raw=true)

## Credits and References

* [QSOP and 0805 breakout and soldering practice board](http://www.boldport.club/shop/product/437246682) - in the Boldport Shop
* [1N5819 Datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [2N3906 datasheet](https://www.futurlec.com/Transistors/2N3906.shtml)
* [Solar Pendulum](https://www.youtube.com/watch?v=M6L-d_dYWIc) - teardown and analysis by Ludic Science
* [Magnet powered pendulum](https://www.youtube.com/watch?v=yrKtY7nWc-o) - teardown and analysis by RHEAD100
* [Solar Powered Pendulum](http://nutsvolts.texterity.com/nutsvolts/201208/?folio=32&pg=32#pg32) - nuts and volts
* [Solar powered motion toy tear-down](https://ez.analog.com/community/university-program/blog/2015/04/27/solar-powered-motion-toy-tear-down)
* [Flip Flap](https://en.wikipedia.org/wiki/Flip_Flap) - wikipedia article on the flapping toy
* [Solar-Winker seziert](http://www.elektronik-labor.de/Labortagebuch/Tagebuch0716.html#pendel2)
* [Drinking bird](https://en.wikipedia.org/wiki/Drinking_bird) - wikipedia
* [Magic pendulum](http://www.elektronik.nmp24.de/?Bauanleitungen:Magisches_Pendel)
* [Watches with mechanical oscillator](http://www.hwynen.de/tba840.html)
* [Novelty electric motor](https://www.google.com/patents/US3783550?dq=3783550&hl=en&sa=X&ei=X67xUqHPMoOZkQWA5IDYDw&ved=0CDMQ6AEwAA&pageId=105188957426397764872) - US patent with unfortunately little detail on the electronics
* [Solar plant ornaments with swinging flowers, fruits, branches and leaves CN101352268](https://worldwide.espacenet.com/publicationDetails/biblio?CC=CN&NR=101352268A&KC=A&FT=D&ND=&date=20090128&DB=EPODOC&locale=en_EP) - patent for SHENZHEN LONGGANG PINGHU TENGY that describes the common wobble toys of today
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap296-solar-pendulum-on-a-boldport-qsop-breakout.html)
