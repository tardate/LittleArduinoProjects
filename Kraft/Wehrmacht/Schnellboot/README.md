# #582 Schnellboot

Building the Bronco NB5004 1/350 German S-100 Class Schnellboot with a dockside diorama with LED effects.

![Build](./assets/Schnellboot_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/batuUuPX6cY/0.jpg)](https://www.youtube.com/watch?v=batuUuPX6cY)

## Notes

I picked up the [Bronco NB5004 1/350 German S-100 Class Schnellboot](http://www.cn-bronco.com/en/product/html/?316.html)
from an [aliexpress seller](https://www.aliexpress.com/item/32975158986.html) as pretty much a cheap impulse buy.

I turned out to be a lovely kit - even at 1:350, it is quite detailed, with a nice set of photoetch included.

## The Kit

![kit_parts](./assets/kit_parts.jpg?raw=true)

## Kit Build

The basic build is quite straight-forward, with the only fiddly bit being the photo-etch.

![build_01](./assets/build_01.jpg?raw=true)

![build_02](./assets/build_02.jpg?raw=true)

![build_03](./assets/build_03.jpg?raw=true)

## Paint Scheme

| Part                               | Recommended        | Paint Used                       |
|------------------------------------|--------------------|----------------------------------|
| propeller                          | Tamiya X-12        | Vallejo 70.878 old gold          |
| deck surface                       | Dark grey FS26187  | Vallejo 70.870 Medium Sea Grey   |
| deck surface (wood)                | Gunze H-11         | Humbrol 110                      |
| upper hull                         | Light Grey FS16515 | Vallejo 70.990 Light Grey        |
| lower hull                         | Tamiya XF-9        | Vallejo 70.985 Hull Red          |

## Diorama Base

The diorama base is imaginary dock scene. I was mainly interested in trying the idea of a split waterline display.
It came together in a fairly ad-hoc manner, and I suspect my scale might be a bit off!

![build_10](./assets/build_10.jpg?raw=true)

## The Electronics

Some simple USB-powered electronics provide LED effects:

* two white LEDs for the lamp posts on the dock
* an LM324 running two triangle-wave oscillators
    * the oscillators use the same components, but are not phase-locked, so they will drift over time (adding variety to the display)
* oscillators drive green and blue "under water" LEDs

![Breadboard](./assets/Schnellboot_bb.jpg?raw=true)

![Schematic](./assets/Schnellboot_schematic.jpg?raw=true)

Testing the oscillators on a breadboard:

![Breadboard Build](./assets/Schnellboot_bb_build.jpg?raw=true)

The final build uses a USB adapter module and the oscillator circuits are constructed "dead bug" style on the LM324 chip

![build_11](./assets/build_11.jpg?raw=true)

![build_12](./assets/build_12.jpg?raw=true)

![build_13](./assets/build_13.jpg?raw=true)

## Final Gallery

![build_20](./assets/build_20.jpg?raw=true)

![build_21](./assets/build_21.jpg?raw=true)

![build_22](./assets/build_22.jpg?raw=true)

![build_23](./assets/build_23.jpg?raw=true)

![build_24](./assets/build_24.jpg?raw=true)

## Credits and References

* [this project on scalemates](https://www.scalemates.com/profiles/mate.php?id=74137&p=projects&project=94846)
* [Bronco Model kit NB5004 1/350 German S-100 Class Schnellboot](http://www.cn-bronco.com/en/product/html/?316.html)
* [Bronco NB5004 at scalemates](https://www.scalemates.com/kits/bronco-nb5004-german-s-100-class-schnellboot--224486)
* [Bronco NB5004](https://www.aliexpress.com/item/32975158986.html) - aliexpress seller (Colorfulday Store)
* [E-boat](https://en.wikipedia.org/wiki/E-boat) - wikipedia
* [LM324N Datasheet](https://www.futurlec.com/Linear/LM324N.shtml)
* [Bronco Models: Schnellboot-Klasse S-100 der Deutschen Kriegsmarine, 1/350](http://www.modellmarine.de/index.php/bausatzvorstellungen/286-bro/2061-bronco-models-deutsche-schnellboot-klasse-s-100-1350) - good kit review at modellmarine.de
