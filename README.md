# 641 Little Electronic Art Projects

> Latest addition:sparkles: [Tydirium Strobe Module](./Kraft/TydiriumStrobe/Module) - Packaging the ATtiny85 Lambda-class shuttle Tydirium navigation strobe circuit as a small board that can be added to an existing lighting setup.

LEAP is just my personal collection of electronics projects - usually involving an Arduino or other microprocessor in one way or another.
Some are full-blown projects, while many are trivial breadboard experiments, intended to learn and explore something interesting.

Projects are often inspired by things found wild on the net,
or ideas from the many great [electronics podcasts and YouTube channels](./notebook/).
Feel free to borrow liberally, and if you spot any issues do let me know (or send a PR!).
See the individual projects for credits where due.

For a while I have also included various scale modelling projects here too,
but I've now split those off into a new repository.
Check out
[LittleModelArt](https://modelart.tardate.com/)
if you are looking for the modelling projects!

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
