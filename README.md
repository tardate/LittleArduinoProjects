# Little Arduino Projects

My collection of Arduino and related electronics projects.
Some are extremely trivial, their inclusion here perhaps more a measure of my OCD than anything else!
Many are variations of things found wild on the net, or inspired by ideas from the following sources:

* [Arduino Cookbook (O'Reilly)](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU)
* [Arduino StackExchange](http://arduino.stackexchange.com/)
* [Arduino Playground](http://playground.arduino.cc/)

Feel free to borrow liberally, and if you spot any issues do let me know. See the individual projects for credits where due.

Circuit diagrams are drawn with the wonderful [Fritzing](http://fritzing.org/home/) application. I've also included here my [catalog of non-standard Fritzing Parts](./FritzingParts).

## Arduino Projects

### Playground Projects
The basics.
These are projects with the Arduino as the core component, often interfacing with off-board support circuits.

* [Blink](./playground/Blink) - the simplest blinking LED, with some electrical measurements thrown in
* [BlinkPrecision](./playground/BlinkPrecision) - use a timer to blink with precision
* [HeartQuotes - Press a button to get a quote](./playground/HeartQuotes)
* [It's Better With Bacon](./playground/BetterWithBacon) - simple LCD test
* [Internals](./playground/Internals) - report on Arduino Board internals
* [LED chaser](./playground/LedChaser)
* [LightOrNot - blink rate of an LED proportional to how light it is](./playground/LightOrNot)
* [Popcorn](./playground/Popcorn) - How to make a piezo buzzer even more annoying? Make it play popcorn!
* [Pushbutton LED switch](./playground/PushbuttonLED)
* [Simple 7-segment common cathode LED display](./playground/Simple7SegmentDisplay)
* [Variable LED brightness (PWM)](./playground/VariableLED)

### Stepper Motor Control

It's common to find the 28BYJ-48 stepper motor and a X113647 Stepper Motor Driver Board in Arduino starter kits. However documentation is scant and the board is not exactly compatible with the standard Stepper library. This repo includes the [X113647Stepper](https://github.com/tardate/X113647Stepper) library for running the example programs.
See the [X113647Stepper github page](https://github.com/tardate/X113647Stepper) for details of the library, example programs, and to get custom Fritzing parts for the components.

### Display Output
Arduino projects testing various output devices.

* [It's Better With Bacon](./playground/BetterWithBacon) - simple LCD test
* [Simple 7-segment common cathode LED display](./playground/Simple7SegmentDisplay)

### Timer Circuits
Testing various timing-related issues.

* [BlinkPrecision](./playground/BlinkPrecision) - use a timer to perform a function on a precise schedule
* [AsyncLedStripEffects](./LEDArrayDemos/AsyncLedStripEffects) - demo effects on an LED strip driven using timer interrupt

### Programmable LED Array Projects

I bought some [WS2811-based LED Strips](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) with a specific project in mind. But first, need to get them working...

* [Intro and Setup](./LEDArrayDemos)
* [RGBCalibrate](./LEDArrayDemos/RGBCalibrate) - quick test to make sure LEDs are correctly addressable and their color can be set correctly
* [StripTease](./LEDArrayDemos/StripTease) - demo a range of effects on the LED strip
* [AsyncLedStripEffects](./LEDArrayDemos/AsyncLedStripEffects) - demo effects on the LED strip driven using timer interrupt
* [FretBoard](./FretBoard) - a multi-project build status indicator, that pulls software build status from the net and animates the status of up to 24 projects with an LED array


## Electronics 101 Projects

It's been a while since I studied this stuff, so a few refreshers are in order! In these projects, the off-board circuit is the focus - generally testing common analog or digital circuits, and sometimes just demonstrating the capabilities of specific ICs. In most cases, the Arduino is just acting as a signal generator and a stand-in for a real oscilloscope.

### Fundamental Logic Gates

A microcontroller like the Arduino renders obsolete the need to delve into basic digital logic. These projects explore the basic building blocks of digital logic, using the simplest components possible, usually just a handful of BJTs.

* [Basic Transistor AND Gate](./Electronics101/BasicAND) - the classic 2-transistor design
* [Simplest 1-Transistor Inverter](./Electronics101/SimplestInverter)
* [Simplest 2-Transistor NAND Gate](./Electronics101/SimplestNAND)
* [Switch - NPN](./Electronics101/SwitchNPN) - digital switch with NPN BJT

### Linear Circuits

* [Capacitorial](./Electronics101/Capacitorial) - graphing capacitor discharge with Processing
* [CapacitanceTester](./Electronics101/CapacitanceTester) - capacitor tester with LCD output

### 555 Timer Circuits

* [Astable mode oscillator](./Electronics101/555Timer/AstableOscillator) - basic free-running oscillator using an Arduino and processing to plot the output
* [Monostable mode](./Electronics101/555Timer/Monostable) - basic monostable mode using an Arduino and processing to plot the output
* [Triangular Wave Generator](./Electronics101/555Timer/TriangleWaveGen) - generate a triange wave with 555 timer and RC integrator

### 7400 series TTL

* [Quad Latch](./Electronics101/QuadLatch) - graph the basic operation of the 74LS75 4-bit bistable latch
* [Schmitt Inverter](./Electronics101/SchmittInverter) - graph the basic operation of the 74LS14 Hex Inverter with Schmitt Trigger Inputs
* [Schmitt Oscillator](./Electronics101/SchmittOscillator) - graph square wave generated using 74LS14 Hex Inverter with Schmitt Trigger Inputs


### Operational Amplifiers


### Power Supply Circuits

* [LM317 Adjustable Regulator](./Electronics101/Power317) - test and graph the adjustable voltage supply
* [LM7805 5V Regulated Supply](./Electronics101/Power7805) - test and graph the voltage supply
* [3.3/5V MB102 Breadboard Supply](./Electronics101/PowerMB102) - demo an MB102 power supply unit
* [Zener Regulated 5V Source](./Electronics101/PowerZener) - test and graph a power supply regulated with a 1N4733 zener diode


### Oscillators

* [Square Wave - 555](./Electronics101/555Timer/AstableOscillator) - using a 555 timer to generate a square wave
* [Square Wave - Schmitt](./Electronics101/SchmittOscillator) - using 74LS14 Hex Inverter with Schmitt Trigger Inputs
* [Triangle Wave - 555](./Electronics101/555Timer/TriangleWaveGen) - generate a triangle wave with 555 timer and RC integrator


## Processing

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

