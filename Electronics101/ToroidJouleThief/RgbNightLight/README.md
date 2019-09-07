# #446 RGB Joule Thief Night Light

Testing a slow-flash RGB LED with a 1.5V joule thief power supply.

![Build](./assets/RgbNightLight_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/T3jprnHPbQM/0.jpg)](https://www.youtube.com/watch?v=T3jprnHPbQM)

## Notes

I recently got hold of some
[5mm RGB Flashing LEDs](https://www.aliexpress.com/item/100pcs-lot-F5-5mm-Fast-Slow-RGB-Flash-Red-Green-Blue-Rainbow-Multi-Color-Light-Emitting/32894320025.html)
from a seller on aliexpress - some slow and fast flashing varieties just out of curiosity.
Here I've put one the slow-flash kind in a "night light" circuit.

I decided to power from a little 1.5V CR1216 coin cell.
To boost the voltage sufficient to power the LED, I've attached a toroidal joule thief circuit, similar to
[LEAP#137 ToroidJouleThief](../).

The oscillating voltage produced by the joule thief is not suitable for the flashing LED as it is liable to get stuck on a single colour,
so I've added a diode/capacitor charge pump to provide a more stable power source for the LED.

## Construction

The circuit and breadboard equivalent are shown below, however for the actual construction I've gone a bit freeform including fashioning a battery holder from 0.9mm copper wire. The CR1216 battery slips in nicely (I haven't added a power switch - the battery must be removed to turn it off).

![Breadboard](./assets/RgbNightLight_bb.jpg?raw=true)

![Schematic](./assets/RgbNightLight_schematic.jpg?raw=true)

![RgbNightLight_layout](./assets/RgbNightLight_layout.jpg?raw=true)

## Credits and References

* [LEAP#137 ToroidJouleThief](../)
* [2N3904 datasheet](https://www.futurlec.com/Transistors/2N3904.shtml)
* [1N5819 Datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
* [5mm RGB Slow Flash LED](https://www.aliexpress.com/item/100pcs-lot-F5-5mm-Fast-Slow-RGB-Flash-Red-Green-Blue-Rainbow-Multi-Color-Light-Emitting/32894320025.html)
* [..as mentioned on my blog](https://blog.tardate.com/2019/01/leap446-rgb-joule-thief-night-light.html)
