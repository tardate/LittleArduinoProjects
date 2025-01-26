# #621 KübelMagic

A walnut, Brengun 1:144 Kübelwagen and a miniaturised SMD version of a BJT oscillator - and with a bit of practice, some close-up model magic.

![Build](./assets/KubelMagic_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/MaPvuJEQeow/0.jpg)](https://www.youtube.com/watch?v=MaPvuJEQeow)

## Notes

I picked up this pair of [1:144 Kübelwagen](http://www.brengun.cz/e-shop/1-144-construction-kits-18/kubelwagen-(2pcs)-1768)
on impulse when buying a PE kit from Hauler/Brengun.

[![BRS144052-1](./assets/BRS144052-1.jpg?raw=true)](http://www.brengun.cz/e-shop/1-144-construction-kits-18/kubelwagen-(2pcs)-1768)

They sat on the shelf for some time. I think it was seeing some
artwork for Episode 21 "Going small" of the
[just making conversation](https://podcasts.apple.com/us/podcast/just-making-conversation/id1539297245) podcast
that inspired me to wonder if I could use the two vehicles with a bit of sleight of hand...

I asked James & Malcolm from the podcast about the artwork and they clued me in:
The original model was by Mike Zax. He has a video covering the build:

[![clip](https://img.youtube.com/vi/S6vDsUlAK-o/0.jpg)](https://www.youtube.com/watch?v=S6vDsUlAK-o)

The vehicle he used was a
1:150 Ford GPA Amphibious Jeep/Seep,
rescaled from a [1:87 R & P Models paper kit](https://randpmodels.jex.cz/rubriky/models-1-87).

## Electronic Circuit Design

In the "exploded" view, I have some fast flashing LEDs to intimate a blazing fire.
I'm using a simple BJT oscillator, but with SMD components and a 3V battery holder to try and conceal it within the shell of a walnut.

The circuit uses a tilt-switch to turn on the circuit when up the "right" way.

I verified this on a breadboard first in order to finalise the component selection.
I settled on 1µF capacitors and 100kΩ resistors for the RC circuit, leading to
a relatively fast flash of around
[7.2 Hz](https://www.wolframalpha.com/input/?i=1%2F%28ln%282%29+*+%28100k%CE%A9+*+1%C2%B5F+%2B+100k%CE%A9+*+1%C2%B5F+%29%29).

![bb](./assets/KubelMagic_bb.jpg?raw=true)

![schematic](./assets/KubelMagic_schematic.jpg?raw=true)

NB: same basic circuit as covered in [LEAP#049 BJT RC Oscillator](../../Electronics101/Oscillators/BjtRcOscillator)

## Electronics Build

I used a small piece of perfboard for mounting the SMD version of the circuit as compactly as I could.

![build01a](./assets/build01a.jpg?raw=true)
![build01b](./assets/build01b.jpg?raw=true)

## Model Construction

The Brengun kit is very nice - resin with PE and decals for quite a detailed model at 1:144.
I think the front door handles are back-to-front however, ended up fixing this.

![build02a](./assets/build02a.jpg?raw=true)
![build02b](./assets/build02b.jpg?raw=true)

I grabbed a handful of Vallejo Model Color for the paint. Didn't record all the paints used...

![build02c](./assets/build02c.jpg?raw=true)
![build02d](./assets/build02d.jpg?raw=true)

## The Shell

Just a Walnut shell, carefully split with a piece of plasticard as a ground plane between the two halves.

In one half we have a "peaceful" scene with a tree and some kind of bowser (actually it is the tilt switch)

![build03a](./assets/build03a.jpg?raw=true)

With the Kübelwagen in place.

![build03b](./assets/build03b.jpg?raw=true)
![build03c](./assets/build03c.jpg?raw=true)
![build03d](./assets/build03d.jpg?raw=true)

On the reverse, we have the destroyed Kübelwagen with a plume of smoke and the LEDs flickering like flames.
Don't know exectly what happened, but it was pretty devastating!

![build04c](./assets/build04c.jpg?raw=true)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=117579)
* [Volkswagen Kübelwagen](https://en.wikipedia.org/wiki/Volkswagen_K%C3%BCbelwagen) - wikipedia
* [Kübelwagen - Brengun BRS144052 - 1:144](https://www.scalemates.com/kits/brengun-brs144052-kubelwagen--1315976) - scalemates
* [Kübelwagen - Brengun BRS144052 - 1:144](http://www.brengun.cz/e-shop/1-144-construction-kits-18/kubelwagen-(2pcs)-1768) - brengun
