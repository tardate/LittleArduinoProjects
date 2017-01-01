# Fritzing Part for the Boldport Cuttle

[The Cuttle](http://www.boldport.com/tc/) is perhaps the most beautiful ATmega328-based board around.

As an Arduino-compatible board, I thought it made sense there should be a Frtizing part for it!
Since the design files are open source, it didn't take much effort to get a decent looking part working.
I used [pcbmode](https://github.com/boldport/pcbmode) to generate an initial SVG from the
[cuttle design files](https://github.com/boldport/thecuttle).

This is an example of what it looks like in a sketch:

![cuttle_blinky_example_bb](./cuttle_blinky_example/cuttle_blinky_example_bb.jpg?raw=true)

## Fritzing Sources

The part is packaged in [TheCuttle.fzpz](./TheCuttle.fzpz) and the source SVG files are here if anyone would like to try and improve it.

## Example

See [cuttle_blinky_example](./cuttle_blinky_example) for an example sketch - simple D13 blinky using the Cuttle

## Credits and References
* [TheCuttle](http://www.boldport.club/shop/product/390973459) - in the Boldport shop
* [TheCuttle](http://www.boldport.com/tc/) - project page
* [LEAP#266 TheCuttle](../../BoldportClub/TheCuttle/) - my build of the Boldport Cuttle
* [pcbmode](https://github.com/boldport/pcbmode) - Boldport board design software
* [thecuttle](https://github.com/boldport/thecuttle) - OSH files for The Cuttle on GitHub
