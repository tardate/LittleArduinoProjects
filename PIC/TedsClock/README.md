# #533 Ted's LED Clock

Building a freeform 20th anniversary clone of [@tedyapo's](https://twitter.com/tedyapo) LED clock, driven with a PIC16F84A.

![Build](./assets/TedsClock_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/oq4bqvXI8DM/0.jpg)](https://www.youtube.com/watch?v=oq4bqvXI8DM)

## Notes

I saw [@tedyapo's tweet](https://twitter.com/tedyapo/status/1228024969902379009) about the LED clock he made 20 years ago.
It is controlled with a PIC16F84A and he shared the [original source code](https://gist.github.com/tedyapo/5a17257cfacd6c2447a9994b7962ac1a).

[![teds_tweet](./assets/teds_tweet.png?raw=true)](https://twitter.com/tedyapo/status/1228024969902379009)

Now if that isn't an invitation to attempt a replica of the project, I don't know what is!

The project seems perfectly suited to a freeform construction, so that's what I've done here.

## Building the Code

I'm running [MPLABX IDE](https://www.microchip.com/mplab/mplab-x-ide) on MacOSX, and it's testament to
Microchip's custodianship of the aging PIC platform that I had no trouble at all recompiling the code with
MPLabX 5.30 and mpasm 5.86.

I'm using an unmodified copy of the original source. See [clock.asm](./TedsClock.X/clock.asm) for the code used.

## Construction

I've selected components based on a visual inspection of a few photographs that Ted shared.

The project uses a 32.768 kHz clock (as this perfectly divides for time-based applications).
The code sets LP clock mode accordingly in the configuration bits,
and per the datasheet, I've used 100pF loading capacitors (not sure what Ted originally used).
With this configuration, the clock seems to keep time reasonably well.

The circuit uses a neat trick to have a single GPIO pin double as LED output and push-button input.
This is used for the hour and minute adjust buttons, as there are not enough pins on the PIC16F84A
to dedicate a pin for each function. Essentially:

* the LED and low value (180Ω) current-limiting resistor are connected normally for active high output
* a normally-open push-button is wired to pull-up the pin to VDD
* so that the pin is positively pulled down when being scanned as an input, a 10kΩ resistor is in parallel with the LED. This is a high enough value that it does not interfere with the normal LED operation
* a 1kΩ resistor is in series with the pull-up push button so that when active. This is large enough so that it does not light the LED too much, but small enough (compared with the 10kΩ resistor) that it provides a sufficient pull-up voltage on the pin.

I've sketched the circuit and initially tested it successfully on a breadboard:

![Breadboard](./assets/TedsClock_bb.jpg?raw=true)

![Schematic](./assets/TedsClock_schematic.jpg?raw=true)

![TedsClock_bb_build](./assets/TedsClock_bb_build.jpg?raw=true)

## Freeform build

I used an old cardboard box as formwork for the dial:

![build_wip](./assets/build_wip.jpg?raw=true)

The dial part uses 0.9mm copper wire, with some 1.2mm copper wire for the more structural stand parts. It solders really well with my favourite "shiny" 2% silver solder.
I never forget to pick up more copper wire from the jewelry/craft section if I find myself in a Daiso or Tokyo Hands!

The rest of the build was just done by eye on a lazy Saturday afternoon, with my usual preference for "anything but straight lines";-)

![Build](./assets/TedsClock_build.jpg?raw=true)

### Updated Code

Ted shared an
[updated version of the code](https://gist.github.com/tedyapo/885f93b2383ac20441e33801e6f8812c),
which improves the hour/minute adjust handling.
It did work before but was really touchy. Now it is very easy to use.

Local sources files updated; here's a quick demo:

[![clip](https://img.youtube.com/vi/4HAepAYWl00/0.jpg)](https://www.youtube.com/watch?v=4HAepAYWl00)

## Credits and References

* [@tedyapo's tweet about the project](https://twitter.com/tedyapo/status/1228024969902379009)
* [original source code - clock_1.asm](https://gist.github.com/tedyapo/5a17257cfacd6c2447a9994b7962ac1a)
* [original source code - clock_2.asm](https://gist.github.com/tedyapo/885f93b2383ac20441e33801e6f8812c)
* [PIC16F84A datasheet and info](https://www.microchip.com/wwwproducts/en/PIC16F84A)
* [the project on hackaday.io](https://hackaday.io/project/171175-teds-led-clock)
* [Hacking on Ted's LED clock software](https://hackaday.io/page/7182-hacking-on-teds-led-clock-software) - Ken Yap's experimental port to C
