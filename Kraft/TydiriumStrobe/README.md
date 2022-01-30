# #589 Tydirium Strobe

Figuring out the navigation light strobe frequency of the Lambda-class shuttle "Tydirium" and building a freeform circuit sculpture to demonstrate the effects (running an ATtiny85 on 3V).

![Build](./assets/TydiriumStrobe_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/6BTHMVjaiEY/0.jpg)](https://www.youtube.com/watch?v=6BTHMVjaiEY)

## Notes

I've recently discovered the ModelGeek podcast and started bingeing the back catalog.
In
[ModelGeek's Podcast Episode 1; Who the Heck Are the ModelGeeks, What Do They Build and Why?](https://www.modelgeekspodcast.com/1568581/7191259-modelgeeks-episode-1-who-the-heck-are-the-modelgeeks-what-do-they-build-and-why)
one of the hosts (Andrew Frill) talks about
wanting to put the navigation lights on a
[Star Wars Shuttle Tydirium AMT/ERTL](https://www.scalemates.com/kits/amt-ertl-8783-shuttle-tydirium--237585) model (at around 0:48:40).

How would one do that? And what is the correct blinking sequence anyway?
Good questions that got me thinking ... and heading off down a rabbit hole..

[![Tyderium_btm](./assets/Tyderium_btm.jpg?raw=true)](https://www.theforce.net/swtc/lambda.html)

## What is the Navigation Strobe Pattern?

[![shuttle3](./assets/shuttle3.jpg?raw=true)](https://www.theforce.net/swtc/lambda.html)

My searches turned up quite a bit of information about [Lambda-class Shuttles](https://www.theforce.net/swtc/lambda.html),
but nothing definitive on the running lights sequence.

So I went back to source and checked out one of the clearest scenes:
[Star Wars: Return of the Jedi - Shuttle Tydirium Approaches Endor](https://youtu.be/vN1WxLth9Mw?t=107).

I ended up chopping the clip up and adding a time sync:

[![clip](https://img.youtube.com/vi/5xd6kZG1V0M/0.jpg)](https://www.youtube.com/watch?v=5xd6kZG1V0M)

My conclusions:

* the basic pattern is "Fl W 1.7s" - white flash every 1.7 seconds. On-time is approximately 0.2 seconds
* however the pattern is often broken as the scene cuts away. I write this off as 20th century editing quirks!

## Demonstration Circuit

There are many possible circuit designs. The first two that come to mind are:

* use a pair of 555 timers - similar to the design I used for [LEAP#560 Hurst Point Lighthouse](../HurstPointLighthouse)
* use a microcontroller

The 555 timer approach is a nice "hardware only" solution, but it can be a bit of a pain to get the timing just right.
So for this demonstration, I'll use a microcontroller.

I only need 1 GPIO pin, and would ideally like to run off a 3V coin cell (CR2032), so I've picked an ATtiny85 in DIP8 package.
Nice and easy!

The sketch [TydiriumStrobe.ino](./TydiriumStrobe.ino) is about as simple as it gets - toggle the GPIO with the appropriate delays.
I programmed the ATtiny85 to run at 1MHz with internal clock, with the code uploaded using an Arduino Uno running ArduinoISP.
See [LEAP#070](../../playground/ProgrammingWithArduinoISP) for more info on programming the ATtiny85.

## Construction

Very simple circuit, running at 3V on a CR2023 coin cell.
The 3mm bright white LEDs I'm using have a nominal forward voltage of 2.7V, so
a [75Ω](https://www.wolframalpha.com/input/?i=0.3V%2F4mA) current limiting resistor will keep current around 4mA. I've rounded up to 100Ω resistors.

![Breadboard](./assets/TydiriumStrobe_bb.jpg?raw=true)

![Schematic](./assets/TydiriumStrobe_schematic.jpg?raw=true)

Testing on a breadboard:

![Breadboard Build](./assets/TydiriumStrobe_bb_build.jpg?raw=true)

## Circuit Sculpture

Watching LEDs flash on a breadboard is a bit boring, so my evening turned into a bit of a zen wire bending session.
The design is ad-hoc and judged by eye, but I think turned out to ba a reasonable representation of a Lambda-class Shuttle in only a few components and
wire off-cuts!

![Build](./assets/TydiriumStrobe_build.jpg?raw=true)

## Credits and References

* [project page on hackaday.io](https://hackaday.io/project/179600-tydirium-strobe-lights)
* [ModelGeek's Podcast Episode 1; Who the Heck Are the ModelGeeks, What Do They Build and Why?](https://www.modelgeekspodcast.com/1568581/7191259-modelgeeks-episode-1-who-the-heck-are-the-modelgeeks-what-do-they-build-and-why)
* [Star Wars Shuttle Tydirium AMT/ERTL - No. 8783 - 1:89](https://www.scalemates.com/kits/amt-ertl-8783-shuttle-tydirium--237585) - scalemates
* [Lambda-class Shuttles](https://www.theforce.net/swtc/lambda.html)
* [Tydirium](https://starwars.fandom.com/wiki/Tydirium/Legends) - starwars.fandom
* [LEAP#070 ProgrammingWithArduinoISP](../../playground/ProgrammingWithArduinoISP) shows programming an ATtiny with Arduino ISP
* [Atmel ATtiny85 Product Info](http://www.atmel.com/devices/ATTINY85.aspx)
* [ATtiny microcontroller support for the Arduino IDE](https://github.com/damellis/attiny)
