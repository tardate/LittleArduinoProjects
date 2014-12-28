# Little Arduino Projects

A collection of simple Arduino projects.
Most of these are variations of things found in the example code or in the wild on the net, or inspired by ideas from the following sources:

* [Arduino Cookbook](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU)
* [Arduino StackExchange](http://arduino.stackexchange.com/)
* [Arduino Playground](http://playground.arduino.cc/)

Feel free to borrow any ideas, and if you spot any issues do let me know. See the individual projects for credits where due.


Circuit diagrams are drawn with the wonderful [Fritzing APP](http://fritzing.org/home/).

## The Projects

* [Blink](./playground/Blink) - the simplest thing possible
* [Capacitorial](./playground/Capacitorial) - graphing capacitor discharge with Processing
* [HeartQuotes - Press a button to get a quote](./playground/HeartQuotes)
* [It's Better With Bacon](./playground/BetterWithBacon) - simple LCD test
* [Internals](./playground/Internals) - report on Arduino Board internals
* [LED chaser](./playground/LedChaser)
* [LightOrNot - blink rate of an LED proportional to how light it is](./playground/LightOrNot)
* [Popcorn](./playground/Popcorn) - How to make a piezo buzzer even more annoying? Make it play popcorn!
* [Pushbutton LED switch](./playground/PushbuttonLED)
* [Simple 7-segment common cathode LED display](./playground/Simple7SegmentDisplay)
* [Variable LED brightness (PWM)](./playground/VariableLED)

### Programmable LED Arrays

I bought some [WS2811-based LED Strips](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) with a specific project in mind. But first, need to get them working...

* [Intro and Setup](./LEDArrayDemos)
* [RGBCalibrate](./LEDArrayDemos/RGBCalibrate) - quick test to make sure LEDs are correctly addressable and their color can be set correctly
* [StripTease](./LEDArrayDemos/StripTease) - demo a range of effects on the LED strip
* [AsyncLedStripEffects](./LEDArrayDemos/AsyncLedStripEffects) - demo effects on the LED strip driven using timer interrupt
* [FretBoard](./FretBoard) - a multi-project build status indicator, that pulls software build status from the net and animates the status of up to 24 projects with an LED array


### Fundamental Logic Gates

A microcontroller like the Arduino renders obsolete the need to delve into basic digital logic. But it's been a while since I studied this stuff, so a few refreshers are in order! In most cases here, the Arduino is just acting as a signal generator and a stand in for a real oscilloscope.

* [Simplest 1-Transistor Inverter](./LogicGates/SimplestInverter)

### Stepper Motor Control

It's common to find the 28BYJ-48 stepper motor and a X113647 Stepper Motor Driver Board in Arduino starter kits. However documentation is scant and the board is not exactly compatible with the standard Stepper library. This repo includes the [X113647Stepper](https://github.com/tardate/X113647Stepper) library for running the example programs.
See the [X113647Stepper github page](https://github.com/tardate/X113647Stepper) for details of the library, example programs, and to get custom Fritzing parts for the components.

### 555 Timer Circuits

* [Astable mode oscillator](./555Timer/AstableOscillator) - basic free-running oscillator using an Arduino and processing to plot the output.
* [Monostable mode](./555Timer/Monostable) - basic monostable mode using an Arduino and processing to plot the output.

### Processing Scripts

Some general purpose [Processing](https://www.processing.org/download/) scripts:

* [PlotNValues](./processing/PlotNValues) reads 1..n values from the serial port and plots on stacked charts.

## Getting Up and Running

Some projects require additional libraries. For example:
* The LED array projects use the [FastLED](http://fastled.io/) library
* EthernetShield projects use the [TextFinder](https://github.com/tardate/TextFinder) library
* Projects running a Timer interrupt routine use the [FlexiTimer2](https://github.com/wimleers/flexitimer2) library
* Stepper motor projects use the [X113647Stepper](https://github.com/tardate/X113647Stepper) library

These libraries are included as submodules of this repository and can be installed with git.
Or you can just install them normally.

If you clone this repo, also update the submodules:

    $ git submodule update --init

To pull submodule updates later on:

    $ git submodule foreach git pull

