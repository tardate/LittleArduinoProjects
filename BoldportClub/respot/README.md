# #442 respot

Boldport puts the "pot" back in the resistance - a classic decade resistor box in custom pots.

![Build](./assets/respot_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

As any good electronics hobbyist must have done,
I've already built a decade programmable resistor box - see [LEAP#414](../../Electronics101/DecadeProgrammableResistor) -
but this is one with the Boldport twist.

A [decade box](https://en.wikipedia.org/wiki/Decade_box) is an old-fashioned bit of test equipment, allowing
an arbitrary resistance to be dialed up to order.

Essentially a decade box comprises multiple stages of 9 resistors in series.

* each stage output is tapped from the base of the resistor series
* hence the resistance between input and ouput varies from 0 to 9x the resistor value, with a switch to select the point at which the input is connected

By setting up stages with resistors at 10x the prior stage, it is possible to dial up an arbitrary restistance with the granularity of the smallest resistor value.

## The Kit

The kit contains 10 of each 1Ω, 10Ω, 100Ω, 1kΩ, 10kΩ, 100kΩ resistors and 5 PCBs, so it is possible to construct a decade box of either 1MΩ range and 10Ω resolution, or 100kΩ range and 1Ω resolution with the parts supplied.

![kit_parts](./assets/kit_parts.jpg?raw=true)

As always, the Boldport PCBs are works of art in their own right...

![kit_pcb](./assets/kit_pcb.jpg?raw=true)


## Circuit

The circuit is essentially the same as I used for my DecadeProgrammableResistor: a cascade of series resistors with a switches for each stage:

![Schematic](https://github.com/tardate/LittleArduinoProjects/blob/master/Electronics101/DecadeProgrammableResistor/assets/DecadeProgrammableResistor_schematic.png?raw=true)


## Switching

One thing that is left up to the builder of the Boldport kit is how to arrange the resistor switching. Options include:

* plug into a breadboard and select with jumper wires
* add manual switches
* use electronic switches and a microcontroller

For now, I have some
[pushwheel/thumbwheel decade switches](https://www.aliexpress.com/item/UXCELL-10-Pcs-Single-Unit-Pushwheel-Thumbwheel-Switch-Km1-0-9/32804224919.html)
on hand, so I'm going to hook up at least one stage with these to make a breadboard compatible switchable-resistor.

![build_front](./assets/build_front.jpg?raw=true)
![build_rear](./assets/build_rear.jpg?raw=true)

With this one stage plugged (using 1kΩ resistors) into a breadboard, it is now selectable from 0-9kΩ in 1kΩ steps:

![Build](./assets/respot_build.jpg?raw=true)

All the pot plants lined up:

![pot_plants](./assets/pot_plants.jpg?raw=true)



## Credits and References
* [respot](https://www.boldport.com/products/respot/) - product page
* [respot](http://community.boldport.club/projects/p30-respot/) - on the community site
* [LEAP#414 DecadeProgrammableResistor](../../Electronics101/DecadeProgrammableResistor)
* [..as mentioned on my blog](https://blog.tardate.com/2018/12/leap442-boldport-respot.html)
