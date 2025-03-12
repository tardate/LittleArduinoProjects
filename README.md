# 675 Little Electronic Art Projects

> Latest addition:sparkles: [74LS74 Clap Switch](./Electronics101/74LS74/ClapSwitch) - Building a clap-switch circuit with electret input, 555 trigger and 74LS74 latch.

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

## The 10th Anniversary Archive

I started the
[LittleArduinoProjects](https://github.com/tardate/LittleArduinoProjects)
GitHub repository back in 2014.
Over the years it accumulated over 2Gb of obsolete commits, and so much git history that it wasn't even possible
to do a `git push` of the entire repo without resorting to [batch tricks](https://stackoverflow.com/questions/15125862/github-remote-push-pack-size-exceeded).

Entering the 11th year of the repository, I decided to do a one-time squash of the project history and essentially restart the git history from scratch:

* <https://github.com/tardate/LittleArduinoProjects> remains the primary repo
    * but with the git history squashed
        * retains the original first commit as the base, so any clones and forks will share a common root commit
    * I've taken the opportunity to rename the working branch from `master` to `main`
* <https://github.com/tardate/LittleArduinoProjects-archive-2014-2024> is a snapshot of the repository prior to the squash
    * marked as `archived` in GitHub, with issues etc disabled
    * retains the full git history in the very unlikely event that anyone needs to refer back to specific change

What this means in practice:

* if you are just viewing LittleArduinoProjects on [GitHub](https://github.com/tardate/LittleArduinoProjects) or the [web](https://leap.tardate.com/), there is no impact
* if you have a clone of the LittleArduinoProjects repository:
    * the simplest is just to throw it away and make a fresh clone of the repo
    * if you have work-in-progress changes on private branches, you will probably want to cherry-pick the changes to a branch based on the new `main` branch
        * if you need help with that, reach out or post an issue
* old pull requests (PR) will be based on the old history. Reviving any old PRs will require the changes to be rebased on the new history.

Hopefully this will help make the LittleArduinoProjects repository fit for use for another 10 years or more..
