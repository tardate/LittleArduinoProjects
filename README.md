# 587 Little Electronics and Arduino Projects

> Latest addition:sparkles: [RGB Auto-ranging Ohmmeter](./playground/RgbOhmMeter) - An auto-ranging ohmmeter that uses an LCD and RGB LEDs to display the bes-matched E24 standard resistor color code for the measured resistance.

Just my collection of electronics projects, many involving an Arduino in one way or another.
Some are full builds (like [The FretBoard](./FretBoard)),
while many are trivial breadboard kata, intended to test or explore a single idea.

Many are variations of things found wild on the net, or inspired by ideas from the sources such as:

* [Boldport Club](https://www.boldport.club/)
* [Elektor magazine](https://www.elektormagazine.com/)
* [Nuts & Volts magazine](https://www.nutsvolts.com/)
* [Silicon Chip magazine](https://www.siliconchip.com.au/)
* [Electrical Engineering StackExchange](https://electronics.stackexchange.com/)
* [Arduino StackExchange](https://arduino.stackexchange.com/)
* [Arduino Playground](https://playground.arduino.cc/)
* books from [my electronics bookshelf](https://www.goodreads.com/review/list/17475014-paul?shelf=electronics)
* the many great electronics YouTube channels e.g.
    * [Afrotechmods](https://www.youtube.com/channel/UCosnWgi3eorc1klEQ8pIgJQ)
    * [Ben Eater](https://www.youtube.com/channel/UCS0N5baNlQWJCUrhCEo8WlA)
    * [GreatScott!](https://www.youtube.com/channel/UC6mIxFTvXkWQVEHPsEdflzQ)
    * [Julian Ilett](https://www.youtube.com/channel/UCmHvGf00GDuPYG9DZqQKd9A)
    * [Scullcom Hobby Electronics](https://www.youtube.com/channel/UCDqryeq1kMDSEQwltWqASrA)
    * [w2aew](https://www.youtube.com/channel/UCiqd3GLTluk2s_IBt7p_LjA)
* and my favourite podcasts e.g.
    * [Embedded.fm](https://embedded.fm/)
    * [Ham Radio Workbench](https://www.hamradioworkbench.com/)
    * [MacroFab Engineering Podcast](https://macrofab.com/blog/podcast/)
    * [The Amp Hour](https://theamphour.com/)
    * [Unnamed Reverse Engineering Podcast](https://unnamedre.com/)

Feel free to borrow liberally, and if you spot any issues do let me know. See the individual projects for credits where due.
There are even now a few projects contributed by others - send your own over in a pull request
if you would also like to add to this collection.

## The LEAP Project Index

The best way to browse the projects is to take a look at the
[LEAP Catalog](https://leap.tardate.com/).
It's actually a static web site generated directly from the repository. Try it out:

[![leap-splash](./catalog/assets/images/leap-splash.png?raw=true)](https://leap.tardate.com/)

## Getting Up and Running

Some projects require additional libraries including FastLED, FlexiTimer2, RadioHead.
A set of such libraries are included as submodules of this repository,
see the [libraries/](./libraries) page for more information on the included libraries and submodule management.

For Arduino projects, I have the Arduino IDE sketchbook location (in preferences) set to the root of this repository.
This makes all the projects available to me in the IDE, and automatically includes libraries
that are linked as git submodules in the [libraries/](./libraries) folder.

If you don't have the Arduino IDE setup this way, libraries can be retrieved with git,
or you can just install them separately as you would any other library.

If you clone this repo, also update the submodules to have them available for compilation:

    $ git submodule update --init

To pull submodule updates later on:

    $ git submodule foreach git pull
