# #402 pips

Rolling the BoldportClub Pips (Project #23) - a classic Elektor die circuit using the CD4060 ripple counter.

![Build](./assets/pips_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The Pips circuit is based on "Dicing with LEDs" by Elektor (December 2006),
but with a new PCB designed as only Boldport can (and a flash red baggie).

The ripple counter toggles through all die states at around [8.8kHz](https://www.wolframalpha.com/input/?i=1+%2F+(2.2+*+(470k%CE%A9*470k%CE%A9)%2F(470k%CE%A9%2B470k%CE%A9)+*+220pF)). Diode steering is used to light the appropriate LEDs for each state and reset the count when it gets to "7".
This runs fast enough that it appears all LEDs are on at the same time.

When the button is pressed, the counter stops - this is a "roll".

This is a similar concept (but quite a different implementation) to the
[LEAP#229 Dice](../../Electronics101/555Timer/Dice) project, which uses a 555 and CD4017 to also achieve a slow-down effect.

## The Kit

![pips_arrives](./assets/pips_arrives.jpg?raw=true)

![pips_kit_parts](./assets/pips_kit_parts.jpg?raw=true)

## Construction

![Breadboard](./assets/pips_bb.jpg?raw=true)

![Schematic](./assets/pips_schematic.jpg?raw=true)

![Build](./assets/pips_build.jpg?raw=true)

## Credits and References
* [Pips](https://www.boldport.com/products/pips) - official Boldport page
* [CD4060 datasheet](http://www.futurlec.com/4000Series/CD4060.shtml)
