# Little Arduino Projects

My collection of Arduino and related electronics projects.
Some are extremely trivial, their inclusion here perhaps more a measure of my OCD than anything else!
Many are variations of things found wild on the net, or inspired by ideas from the following sources:

* [Arduino Cookbook (O'Reilly)](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU)
* [Arduino StackExchange](http://arduino.stackexchange.com/)
* [Arduino Playground](http://playground.arduino.cc/)

Feel free to borrow liberally, and if you spot any issues do let me know. See the individual projects for credits where due.

Circuit diagrams are drawn with the wonderful [Fritzing](http://fritzing.org/home/) application. I've also included here my [catalog of non-standard Fritzing Parts](./FritzingParts).

# Full Builds
Projects that have been taken all the way to a full build i.e. the ones that didn't get ripped apart for spares as soon as they were done!

* [FretBoard](./FretBoard) - a multi-project build status indicator, that pulls software build status from the net and animates the status of up to 24 projects with an LED array. Look at the picks to discover why it is called "The FretBoard"
* [MeLEDy](./Electronics101/MeLEDy) - simple volume level indicator

# Arduino Playground
Projects with an Arduino microcontroller front and centre of the build.

## Programming and Internals
Onboard functionality tests.

* [Internals](./playground/Internals) - report on Arduino Board internals

### Timer Circuits
Testing various timing-related issues.

* [AsyncLedStripEffects](./LEDArrayDemos/AsyncLedStripEffects) - demo effects on an LED strip driven using timer interrupt
* [BlinkPrecision](./playground/BlinkPrecision) - use a timer to perform a function on a precise schedule

## Sensor Circuits
Arduino projects testing various sensor inputs.

* [LDRComparator](./Electronics101/LDRComparator) - Low-light/proximity Trip Detector demonstration
* [LightOrNot](./playground/LightOrNot) - uses an LDR to adjust the blink rate of an LED
* [RangeFinder](./playground/RangeFinder) - proximity/distance measurement with an HC-SR04 untrasonic ranging module
* [ElectretTrigger](./playground/ElectretTrigger) - uses an electret microphone to trigger action when over audio threshold

## Audio Input

* [ElectretADC](./playground/ElectretADC) - convert electret signal to a full range analog input and plot the raw and aplified signals
* [ElectretTrigger](./playground/ElectretTrigger) - uses an electret microphone to trigger action when over audio threshold

## Audio Output

* [Popcorn](./playground/Popcorn) - How to make a piezo buzzer even more annoying? Make it play popcorn!

## Human Input

* [HitTheLights](./playground/HitTheLights) - simple LED game with LCD output and interrupt-driven button input

## Visual Output
Arduino projects testing various visual output devices.

### LED Circuits

* [Blink](./playground/Blink) - the simplest blinking LED, with some electrical measurements thrown in
* [BlinkPrecision](./playground/BlinkPrecision) - use a timer to blink with precision
* [LED chaser](./playground/LedChaser)
* [Pushbutton LED switch](./playground/PushbuttonLED)
* [Shifty](./playground/Shifty) - drive 8 LEDs with 3 pins using a 74HC595 shift register
* [Variable LED brightness (PWM)](./playground/VariableLED)

### LCD Circuits

* [It's Better With Bacon](./playground/BetterWithBacon) - simple LCD test
* [CapacitanceTester](./Electronics101/CapacitanceTester) - capacitor tester with LCD output
* [HeartQuotes](./playground/HeartQuotes) - press a button to get a quote from the net and display on an LCD
* [HitTheLights](./playground/HitTheLights) - simple LED game with LCD output and interrupt-driven button input


### 7-Segment Displays

* [Simple 7-segment display](./playground/Simple7SegmentDisplay) - test 7-segment common cathode display


### Programmable LED Array Projects

I bought some [WS2811-based LED Strips](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) with a specific project in mind. But first, need to get them working...

* [Intro and Setup](./LEDArrayDemos)
* [RGBCalibrate](./LEDArrayDemos/RGBCalibrate) - quick test to make sure LEDs are correctly addressable and their color can be set correctly
* [StripTease](./LEDArrayDemos/StripTease) - demo a range of effects on the LED strip
* [AsyncLedStripEffects](./LEDArrayDemos/AsyncLedStripEffects) - demo effects on the LED strip driven using timer interrupt
* [FretBoard](./FretBoard) - a multi-project build status indicator, that pulls software build status from the net and animates the status of up to 24 projects with an LED array

## Kinetic Output

### DC Motors
Generally concerning [brushed DC motors](http://en.wikipedia.org/wiki/Brushed_DC_electric_motor)..

* [MotorControlPWM](./playground/MotorControlPWM) - tests PWM speed control of a DC motor driven by an Arduino


### Servo Motor

* [ServoTest](./playground/ServoTest) - test the positioning accuracy of a servo motor driven by an Arduino


### Stepper Motor Control

It's common to find the 28BYJ-48 stepper motor and a X113647 Stepper Motor Driver Board in Arduino starter kits. However documentation is scant and the board is not exactly compatible with the standard Stepper library. This repo includes the [X113647Stepper](https://github.com/tardate/X113647Stepper) library for running the example programs.
See the [X113647Stepper github page](https://github.com/tardate/X113647Stepper) for details of the library, example programs, and to get custom Fritzing parts for the components.


## Internet-Enabled Arduino Projects
Projects and demos that interface with the net

* [HeartQuotes](./playground/HeartQuotes) - press a button to get a quote from the net and display on an LCD


# Electronics 101

It's been a while since I studied this stuff, so a few refreshers are in order! In these projects, the off-board circuit is the focus - generally testing common analog or digital circuits, and sometimes just demonstrating the capabilities of specific ICs. In most cases, the Arduino is just acting as a signal generator and a stand-in for a real oscilloscope.


## 555 Timer Circuits

* [Astable mode oscillator](./Electronics101/555Timer/AstableOscillator) - basic free-running oscillator using an Arduino and processing to plot the output
* [Monostable mode](./Electronics101/555Timer/Monostable) - basic monostable mode using an Arduino and processing to plot the output
* [SimpleChime](./Electronics101/555Timer/SimpleChime) - play a sound for a fixed duration when a button is pressed
* [SimpleSiren](./Electronics101/555Timer/SimpleSiren) - classic timer circuit producing a two-tone oscillation
* [Triangular Wave Generator](./Electronics101/555Timer/TriangleWaveGen) - generate a triange wave with 555 timer and RC integrator

## 7400 series TTL

* [Quad Latch](./Electronics101/QuadLatch) - graph the basic operation of the 74LS75 4-bit bistable latch
* [Schmitt Inverter](./Electronics101/SchmittInverter) - graph the basic operation of the 74LS14 Hex Inverter with Schmitt Trigger Inputs
* [Schmitt Oscillator](./Electronics101/SchmittOscillator) - graph square wave generated using 74LS14 Hex Inverter with Schmitt Trigger Inputs

## Audio Circuits

* [MeLEDy](./Electronics101/MeLEDy) - use an electret microphone to light a series of LEDs in proportion to volume
* [SimpleChime](./Electronics101/555Timer/SimpleChime) - play a sound for a fixed duration when a button is pressed
* [SimpleSiren](./Electronics101/555Timer/SimpleSiren) - classic timer circuit producing a two-tone oscillation

## Linear Circuits

* [Capacitorial](./Electronics101/Capacitorial) - graphing capacitor discharge with Processing
* [CapacitanceTester](./Electronics101/CapacitanceTester) - capacitor tester with LCD output

## Logic Gates

A microcontrollers like the Arduino typically render obsolete the need to delve into basic digital logic. But not always.
These projects explore the basic building blocks of digital logic, using the simplest components possible, usually just a handful of BJTs.

* [Basic Transistor AND Gate](./Electronics101/BasicAND) - the classic 2-transistor design
* [Simplest 1-Transistor Inverter](./Electronics101/SimplestInverter)
* [Simplest 2-Transistor NAND Gate](./Electronics101/SimplestNAND)

## Operational Amplifiers

* [ElectretADC](./playground/ElectretADC) - plot the raw and aplified electret signal (LM324 preamp)
* [ElectretTrigger](./playground/ElectretTrigger) - LM324-amplified electret input triggers a tune when over audio threshold
* [LDRComparator](./Electronics101/LDRComparator) - demo LM324 OpAmp as threshold trigger for LDR/Wheatstone Bridge sensor
* [LDRStereoTripDetector](./Electronics101/LDRStereoTripDetector) - demo LM324 OpAmp as threshold trigger for stereo LDR/Wheatstone Bridge sensor
* [LM324Oscillator](./Electronics101/LM324Oscillator) - square wave generation with an LM324 OpAmp
* [NonInverting324](./Electronics101/NonInverting324) - demo LM324 OpAmp non-inverting DC gain mode


## Oscillators

* [Square Wave - 555](./Electronics101/555Timer/AstableOscillator) - using a 555 timer to generate a square wave
* [Square Wave - Schmitt](./Electronics101/SchmittOscillator) - using an 74LS14 Hex Inverter with Schmitt Trigger Inputs to generate a square wave
* [Square Wave - LM324](./Electronics101/LM324Oscillator) - using an LM324 OpAmp to generate a square wave
* [Triangle Wave - 555](./Electronics101/555Timer/TriangleWaveGen) - generate a triangle wave with 555 timer and RC integrator

## Power Supply Circuits

* [LM317 Adjustable Regulator](./Electronics101/Power317) - test and graph the adjustable voltage supply
* [LM7805 5V Regulated Supply](./Electronics101/Power7805) - test and graph the voltage supply
* [3.3/5V MB102 Breadboard Supply](./Electronics101/PowerMB102) - demo an MB102 power supply unit
* [Zener Regulated 5V Source](./Electronics101/PowerZener) - test and graph a power supply regulated with a 1N4733 zener diode

## Transistor Circuits

* [MeLEDy](./Electronics101/MeLEDy) - use an electret microphone to light a series of LEDs in proportion to volume
* [Switch - NPN](./Electronics101/SwitchNPN) - small-signal digital switch with NPN BJT
* [Switch - PNP](./Electronics101/SwitchPNP) - small-signal digital switch with PNP BJT


# Processing

Some general purpose [Processing](https://www.processing.org/download/) scripts:

* [PlotNValues](./processing/PlotNValues) reads 1..n values from the serial port and plots on stacked charts.


# Getting Up and Running

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

