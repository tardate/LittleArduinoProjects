# Libraries

Some projects require additional libraries. For example:
* The LED array projects use the [FastLED](http://fastled.io/) library
* Stepper motor projects use the [X113647Stepper](https://github.com/tardate/X113647Stepper) library
* EthernetShield projects use the [interactive-matter/HTTPClient](https://github.com/interactive-matter/HTTPClient) library

These libraries are included as submodules of this repository and can be installed with git.
Or you can just install them normally.
For information on installing libraries, see: http://arduino.cc/en/Guide/Libraries

## Install with Git

If you clone this repo, also update the submodules:

    $ git submodule update --init

To pull submodule updates later on:

    $ git submodule foreach git pull


## Pull updates for a specific library

e.g. to pull the latest X113647Stepper updates:

    $ git submodule update --remote libraries/X113647Stepper

## Adding a new module to the Repo

    $ git submodule add https://github.com/repo_path/name libraries/name
