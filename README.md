# Little Arduino Projects

A collection of simple Arduino projects.
Most of these are variations of things found in the example code or in the wild on the net.
See the individual projects for credits where due.

Feel free to borrow any ideas, and if you spot any issues do let me know.

Circuit diagrams are drawn with the wonderful [Fritzing APP](http://fritzing.org/home/).

## The Projects

* [Blink](./playground/Blink) - the simplest thing possible
* [Capacitorial](./playground/Capacitorial) - graphing capacitor discharge with Processing
* [HeartQuotes - Press a button to get a quote](./playground/HeartQuotes)
* [It's Better With Bacon](./playground/BetterWithBacon) - simple LCD test
* [LED chaser](./playground/LedChaser)
* [LightOrNot - blink rate of an LED proportional to how light it is](./playground/LightOrNot)
* [Pushbutton LED switch](./playground/PushbuttonLED)
* [Simple 7-segment common cathode LED display](./playground/Simple7SegmentDisplay)
* [Variable LED brightness (PWM)](./playground/VariableLED)

### Programmable LED Arrays

I bought some [WS2811-based LED Strips](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) with a specific project in mind. But first, need to get them working...

* [Intro and Setup](./LEDArrays)
* [RGBCalibrate - my version](./LEDArrays/RGBCalibrate)
* [StripTease](./LEDArrays/StripTease) -demo a range of effects on the LED strip


### Fundamental Logic Gates

A microcontroller like the Arduino renders obsolete the need to delve into basic digital logic. But it's been a while since I studied this stuff, so a few refreshers are in order! In most cases here, the Arduino is just acting as a signal generator and a stand in for a real oscilloscope.

* [Simplest 1-Transistor Inverter](./LogicGates/SimplestInverter)


### Stepper Motor Control

It's common to find the 28BYJ-48 stepper motor and a X113647 Stepper Motor Driver Board in Arduino starter kits. However documentation is scant and the board is not exactly compatible with the standard Stepper library. This repo includes the [X113647Stepper](https://github.com/tardate/X113647Stepper) library for running the example programs.
See the [X113647Stepper github page](https://github.com/tardate/X113647Stepper) for details of the library, example programs, and to get custom Fritzing parts for the components.


## Getting Up and Running

Some projects use additional libraries that are included as submodules of this repository. For example:
* The LED array projects use the [FastLED](http://fastled.io/) library
* Stepper motor projects use the [X113647Stepper](https://github.com/tardate/X113647Stepper) library

If you clone this repo, also update the submodules:

    $ git submodule update --init

To pull submodule updates later on:

    $ git submodule foreach git pull

