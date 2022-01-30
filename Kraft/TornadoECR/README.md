# #613 Tornado ECR

Building the 1:144 Tornado ECR from Revell with wireless LEDs in the Tailpipe.

![Build](./assets/TornadoECR_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/2ga6ZbmDSCU/0.jpg)](https://www.youtube.com/watch?v=2ga6ZbmDSCU)

## Notes

### About the Tornado

The [Panavia Tornado](https://en.wikipedia.org/wiki/Panavia_Tornado#ECR)
was a joint project of United Kingdom, Germany, Italy and the Netherlands to develop a new multi-role combat aircraft.
The UK saw it as a replacement for the Avro Vulcan and Blackburn Buccaneer and avoided over dependence on other suppliers (i.e. the US).
The consortium was founded in 1969 and the first production aircraft flight was on 10 July 1979.

Originally expected to largely plays its role in the cold war and probably never be used in anger, history of course took over and it saw a
surprisingly long and active career (Kosovo and the Gulf wars). The UK retired the aircraft in 2019.

I'd never paid much attentio to the Tornado until I got this kit. It really is quite a beautiful design.
I read and can highly recommend John Nichol's
[Tornado: In the Eye of the Storm](https://www.goodreads.com/book/show/55318695-tornado)
which provides an excellent account of the aircraft's development and operational use.

[![tornado_ECR_JBG-32.jpg](./assets/tornado_ECR_JBG-32.jpg?raw=true)](https://upload.wikimedia.org/wikipedia/commons/2/2a/Tornado_ECR_JBG-32_NATO_Tiger_Meet_2011_Cambrai_%285808438509%29.jpg)

### The Kit

I picked up this [Revell 1:144 Tornado ECR kit 04048](https://www.revell.de/en/produkte/modellbau/flugzeuge/militaer-modern-revell/tornado-ecr.html)
because of those tiger stripes and also because I was interested to try something in 1:144. But mainly those tiger stripes!

* Scale: 1:144
* Number of parts: 63
* Length: 118 mm
* Wingspan: 85 mm

[![kit_box](./assets/kit_box.jpg?raw=true)](https://www.revell.de/en/produkte/modellbau/flugzeuge/militaer-modern-revell/tornado-ecr.html)

This is my first Revell kit and I couldn't have been more impressed:

* the detail is extremely good for 1:144 and the plastic they use is just hard enough to keep all the features crisp
* the engineering is perfect - it even has articulated parts (swing wing and adjustable tail fins)

![kit_parts](./assets/kit_parts.jpg?raw=true)

### Livery and Paint Scheme

Tornado ECR, 1. Staffel, JaboG 32, Lechfeld AB, 1994

| Key | Application                 | Name                                    | Paint Used |
|-----|-----------------------------|-----------------------------------------|------------|
| A   | fuselage, cockpit details   | anthracite grey, matt                   | 70.992 Neutral Grey |
| B   | fuselage                    | dark green, matt 80% + yellow, matt 20% | 70.893 US Dark Green + 70.953 Flat Yellow (4:1) |
| C   | tail tip                    | mouse grey, matt                        | 70.870 Medium Sea Grey |
| D   | nose, trim                  | black, matt                             | 70.950 Black |
| E   | fuselage, cockpit details   | dark green, matt                        | 70.893 US Dark Green |
| F   | landing gear, missiles      | white, matt                             | 70.951 White |
| G   | cockpit details, inner wing | light grey, matt                        | 70.990 Light Grey |
| H   |                             | bronze green, matt                      | |
| I   | tailpipe                    | steel, metallic                         | |
| K   | landing gear, spiggots      | aluminium, metallic                     | |
| L   | nav lights                  | leaf green, satin                       | |
| M   | nav lights                  | fiery red, satin                        | |
| O   | fuselage near cockpit       | yellow, matt                            | 70.953 Flat Yellow over pink undercoat (70.951 white + 70.909 vermillion, 3:1) |


### Wireless LEDs in the Tailpipe

To do something a little different with this model I decided to put orange LEDs in the tailpipe for a "jet effect glow".
Rather than run wires to the model, I'm goig to do this wirelessly.

This is a simple oscillator circuit (similar to a joule thief) that emits just enough power to light an LED.
Adding a toroid to the transmit and receive coil boosts the electromagnectic field just enough to span the distance from the base to the body of the model.

Note that the LEDs are connected in reverse polarity so each gets a half-wave. The power transmitted is not completely symetrical - one LED lights brighter that the other - I suspect because when powered by the L1 phase, some power is dropped over R1. I didn't try to even this out.

![bb](./assets/TornadoECR_bb.jpg?raw=true)

![schematic](./assets/TornadoECR_schematic.jpg?raw=true)

The coil, toroid and LEDs fit nicely into the rear of the Tornado. Holes drilled in the jet exhaust - perfect size for 3mm LEDs (I used orange LEDs).

![build01a](./assets/build01a.jpg?raw=true)

Note: I admit, after the fact I forgot about weighting the front of the plane so ended up with a tail-sitter.
Had to do surgery and chop off the nose to add a counterweight (small nut and bolt).

The power goes in a custom base quickly thrown together with some Daiso craft wood. Single AAA battery, oscillator, coil and switch mounted on the side.

![build01b](./assets/build01b.jpg?raw=true)

Testing the electronics with the unfinished base and primed Tornado. All good!

![build01c](./assets/build01c.jpg?raw=true)

I tried the pink undercoat trick and it seems to have worked a treat - no trouble getting a vibrant yellow over the top:

![build02a](./assets/build02a.jpg?raw=true)

Finished painting and tiger stripes (I put it off for a few days as I feared a decal disaster).

![build02b](./assets/build02b.jpg?raw=true)

![build02c](./assets/build02c.jpg?raw=true)

On the base. Probably the most poorly maintained bit of hard stand I've ever seen;-)

![build03a](./assets/build03a.jpg?raw=true)

One flaw in the tiger stripe decals is that they don't go over the in-air refueling equipment. I'll have to mask and spray the extension to the scheme.

![build03b](./assets/build03b.jpg?raw=true)

I left the base as raw wood. Think I like it that way...

![build03c](./assets/build03c.jpg?raw=true)

The money shot - tailpipes light up when the plane is on the base...

![build04a](./assets/build04a.jpg?raw=true)
![build04b](./assets/build04b.jpg?raw=true)
![build04c](./assets/build04c.jpg?raw=true)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=115212)
* [Panavia Tornado ECR](https://en.wikipedia.org/wiki/Panavia_Tornado#ECR)
* [Tornado ECR Revell - No. 04048 - 1:144](https://www.scalemates.com/kits/revell-04048-tornado-ecr--104311) - scalemates
* [Tornado ECR Revell - No. 04048 - 1:144](https://www.revell.de/en/produkte/modellbau/flugzeuge/militaer-modern-revell/tornado-ecr.html) - revell.de
* [Tornado: In the Eye of the Storm](https://www.goodreads.com/book/show/55318695-tornado) - John Nichol
