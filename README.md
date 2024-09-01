# 755 Little Electronic Art Projects

> Latest addition:sparkles: [9V (PP3) to 5V or 3.3V Power Adapter](./Electronics101/Power/pp3power) - Building an MC34063-based buck converter adapter for a 9V battery, with output voltage selectable between 5V and 3.3V.

LEAP is just my personal collection of projects.
Two main themes have emerged in recent years, sometimes combined:

* electronics - usually involving an Arduino or other microprocessor in one way or another. Some are full-blown projects, while many are trivial breadboard experiments, intended to learn and explore something interesting
* scale modelling - I caught the bug after deciding to build a Harrier during covid to demonstrate an electronic jet engine simulation. Let the fun begin..

To be honest, I haven't quite figured out if these two interests belong in the same
GitHub repo or not. But for now - they are all here!

Projects are often inspired by things found wild on the net,
or ideas from the many great electronics and scale modelling podcasts and YouTube channels.
Feel free to borrow liberally, and if you spot any issues do let me know (or send a PR!).
See the individual projects for credits where due.

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

    git submodule update --init

To pull submodule updates later on:

    git submodule foreach git pull
