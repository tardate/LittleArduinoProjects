# Little Arduino Projects

Just my collection of electronics projects, many involving an Arduino in one way or another.
Some are extremely trivial, their inclusion here perhaps more a measure of my OCD than anything else.
Many are variations of things found wild on the net, or inspired by ideas from the following sources:

* [Arduino Cookbook (O'Reilly)](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU)
* [Arduino StackExchange](http://arduino.stackexchange.com/)
* [Arduino Playground](http://playground.arduino.cc/)

Feel free to borrow liberally, and if you spot any issues do let me know. See the individual projects for credits where due.


## Highlights
Projects that have been taken all the way to a full build i.e. the ones that didn't get ripped apart for spares as soon as they were done!

* [Breadboard 5V Regulator](./Electronics101/PowerBreadboard5V) - custom regulated 5V power supply module for standard breadboard
* [FretBoard](./FretBoard) - a multi-project build status indicator, that pulls software build status from the net and animates the status of up to 24 projects with an LED array. Look at the picks to discover why it is called "The FretBoard"
* [Girabot](./Girabot) - EE40LX Electronic Interfaces robot project
* [MeLEDy](./Electronics101/MeLEDy) - simple volume level indicator


## Other Bits

* [Custom Fritzing Parts](./FritzingParts) - Most projects have a circuit schematic drawn with the wonderful [Fritzing](http://fritzing.org/home/) application. But often I needed a non-standard part for the diagram. Here they are.
* [PlotNValues](./processing/PlotNValues) - a [Processing](https://www.processing.org/download/) script that reads 1..n values from the serial port and plots on stacked charts. I've often used this as a super-low-rent stand-in for an oscilliscope.


## 63 Projects...
Latest addition - [RFSwitchASK](./playground/RFSwitchASK), simple remote data communications using ASK protocol over 433Mhz transmitter/receiver set.

| Project                                                      | Category                   | Description                               |
|--------------------------------------------------------------|----------------------------|-------------------------------------------|
| [Arduino Internals](./playground/Internals)                  | Arduino                    | report on Arduino Board internals         |
| [AsyncLedStripEffects](./LEDArrayDemos/AsyncLedStripEffects) | LED Array, Timing, Arduino | demo effects on the LED strip driven using timer interrupt |
| [Blink](./playground/Blink)                                  | LED, Arduino               | the simplest blinking LED, with some electrical measurements thrown in |
| [BlinkPrecision](./playground/BlinkPrecision)                | LED, Timing, Arduino       | use a timer to perform a function on a precise schedule |
| [Breadboard 5V Regulator](./Electronics101/PowerBreadboard5V)| Power                      | custom regulated 5V power supply module for standard breadboard |
| [CapacitanceTester](./Electronics101/CapacitanceTester)      | LCD, RC, Arduino           | capacitor tester with LCD output |
| [Capacitorial](./Electronics101/Capacitorial)                | RC                         | graphing capacitor discharge with Processing |
| [Comparator741](./Electronics101/Comparator741)              | OpAmp                      | demo LM741 OpAmp comparator mode (with PWM-to-analog side-topic) |
| [El Jarabe Tapatío](./playground/JarabeTapatio)              | Audio, Arduino             | play The Mexican Hat Dance on a piezo buzzer with LM 386 amplification |
| [ElectretADC](./playground/ElectretADC)                      | Audio, Arduino             | convert electret signal to a full range analog input with an LM324 preamp and plot the raw and aplified signals |
| [ElectretTrigger](./playground/ElectretTrigger)              | Sensors, Audio, OpAmp, Arduino | uses an electret microphone and LM324 amplifier to trigger action when over audio threshold |
| [FunctionGenerator324](./Electronics101/FunctionGenerator324) | OpAmp, Oscillators        | LM324 configured as a low-frequency square, triangle, sine, and cosine function generator |
| [FretBoard](./FretBoard)                                     | LED Array, Arduino         | a multi-project build status indicator, that pulls software build status from the net and animates the status of up to 24 projects with an LED array |
| [Gates - Basic Transistor AND](./Electronics101/BasicAND)    | Logic Gates, BJT           | the classic 2-transistor design |
| [Gates - 1-Transistor Inverter](./Electronics101/SimplestInverter) | Logic Gates, BJT     | Simplest 1-Transistor Inverter  |
| [Gates - 2-Transistor NAND](./Electronics101/SimplestNAND)   | Logic Gates, BJT           | Simplest 2-Transistor NAND      |
| [Gates - RS Flip Flop](./Electronics101/RSFlipFlop)          | Logic Gates, BJT           | Set/Reset flip-flop with BJTs |
| [Gates - RS Flip Flop with Arduino](./Electronics101/RSFlipFlopFlipper) | Logic Gates, BJT, Arduino  | Set/Reset flip-flop with BJTs, under Arduino control and monitoring |
| [Girabot](./Girabot)                                         | Sensors, OpAmp, Arduino    | EE40LX Electronic Interfaces robot project |
| [HeartQuotes](./playground/HeartQuotes)                      | LCD, Ethernet, Arduino     | press a button to get a quote from the net and display on an LCD |
| [HitTheLights](./playground/HitTheLights)                    | LCD, Human Input, Arduino  | simple LED game with LCD output and interrupt-driven button input |
| [It's Better With Bacon](./playground/BetterWithBacon)       | LCD, Arduino               | simple LCD test |
| [JoystickServoControl](./playground/JoystickServoControl)    | Human Input, Arduino       | controlling two servos with a joystick |
| [LDRComparator](./Electronics101/LDRComparator)              | Sensors, OpAmp, Arduino    | Low-light/proximity Trip Detector demonstration using LM324 and LDR/Wheatstone Bridge sensor |
| [LDRStereoTripDetector](./Electronics101/LDRStereoTripDetector) | OpAmp                   | demo LM324 OpAmp as threshold trigger for stereo LDR/Wheatstone Bridge sensor |
| [LED chaser](./playground/LedChaser)                         | LED, Arduino               | |
| [LEDArrayDemos](./LEDArrayDemos)                             | LED Array, Arduino         | Intro and Setup.. I bought some [WS2811-based LED Strips](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) with a specific project in mind. But first, need to get them working... |
| [LightOrNot](./playground/LightOrNot)                        | Sensors, Arduino           | uses an LDR to adjust the blink rate of an LED |
| [LM317 Adjustable Regulator](./Electronics101/Power317)      | Power                      | test and graph the adjustable voltage supply |
| [LM7805 5V Regulated Supply](./Electronics101/Power7805)     | Power                      | test and graph the voltage supply |
| [MB102 3.3/5V Breadboard Supply](./Electronics101/PowerMB102)| Power                      | demo an MB102 power supply unit |
| [MeLEDy](./Electronics101/MeLEDy)                            | Audio                      | use an electret microphone to light a series of LEDs in proportion to volume |
| [Monostable](./Electronics101/555Timer/Monostable)           | 555 Timer                  | basic monostable mode using an Arduino and processing to plot the output |
| [MotorControlPWM](./playground/MotorControlPWM)              | Motors, Arduino            | tests PWM speed control of a DC motor driven by an Arduino |
| [NonInverting324](./Electronics101/NonInverting324)          | OpAmp                      | demo LM324 OpAmp non-inverting DC gain mode |
| [Popcorn](./playground/Popcorn)                              | Audio, Arduino             | How to make a piezo buzzer even more annoying? Make it play popcorn! |
| [Pushbutton LED switch](./playground/PushbuttonLED)          | LED, Arduino               | |
| [Quad Latch](./Electronics101/QuadLatch)                     | 74xx TTL                   | graph the basic operation of the 74LS75 4-bit bistable latch |
| [RangeFinder](./playground/RangeFinder)                      | Sensors, Arduino           | proximity/distance measurement with an HC-SR04 untrasonic ranging module |
| [RCOscillator](./Electronics101/RCOscillator)                | Oscillators                | simple RC/transistor multistable vibrator |
| [RelayControlTest](./playground/RelayControlTest)            | Servo, Arduino             | quick test to drive a motor with a common relay using NPN switching circuit under Arduino control |
| [RelayModuleTest](./playground/RelayModuleTest)              | Servo, Arduino             | quick test of a common relay board to switch a motor under Arduino control |
| [RFSwitch](./Electronics101/RFSwitch)                        | RF, OpAmp                  | simple remote control switch with 433Mhz transmitter/receiver and some analog signal processing |
| [RFSwitchASK](./playground/RFSwitchASK)                      | RF, ASK, Arduino           | data communications using ASK protocol over 433Mhz RF transmitter and receiver set |
| [RGBCalibrate](./LEDArrayDemos/RGBCalibrate)                 | LED Array, Arduino         | quick test to make sure LEDs are correctly addressable and their color can be set correctly |
| [Schmitt Inverter](./Electronics101/SchmittInverter)         | 74xx TTL                   | graph the basic operation of the 74LS14 Hex Inverter with Schmitt Trigger Inputs |
| [ServoTest](./playground/ServoTest)                          | Servo, Arduino             | test the positioning accuracy of a servo motor driven by an Arduino |
| [Shifty](./playground/Shifty)                                | LED, Arduino               | drive 8 LEDs with 3 pins using a 74HC595 shift register |
| [Simple 7-segment display](./playground/Simple7SegmentDisplay) | 7-Segment, Arduino       | test 7-segment common cathode display |
| [SimpleChime](./Electronics101/555Timer/SimpleChime)         | 555 Timer                  | play a sound for a fixed duration when a button is pressed |
| [SimpleSiren](./Electronics101/555Timer/SimpleSiren)         | 555 Timer                  | classic timer circuit producing a two-tone oscillation |
| [StereoLightTrigger](./playground/StereoLightTrigger)        | Sensors, Arduino           | demo an interrupt-driven method for responding to LDR light threshold triggers |
| [StripTease](./LEDArrayDemos/StripTease)                     | LED Array, Arduino         | demo a range of effects on the LED strip |
| [Square Wave - 555](./Electronics101/555Timer/AstableOscillator) | 555 Timer, Oscillators | using a 555 timer to generate a square wave and an Arduino and processing to plot the output |
| [Square Wave - LM324](./Electronics101/LM324Oscillator)      | OpAmp, Oscillators         | using an LM324 OpAmp to generate a square wave |
| [Square Wave - Schmitt](./Electronics101/SchmittOscillator)  | 74xx TTL, Oscillators      | using an 74LS14 Hex Inverter with Schmitt Trigger Inputs to generate a square wave |
| [Switch - NPN](./Electronics101/SwitchNPN)                   | BJT                        | small-signal digital switch with NPN BJT |
| [Switch - PNP](./Electronics101/SwitchPNP)                   | BJT                        | small-signal digital switch with PNP BJT |
| [Triangle Wave - 555](./Electronics101/555Timer/TriangleWaveGen) | 555 Timer, Oscillators | generate a triangle wave with 555 timer and RC integrator |
| [TwoToneDoorbell](./Electronics101/555Timer/TwoToneDoorbell) | 555 Timer, Oscillators     | basic two-tone doorbell using a 555 timer oscillator, with n-channel FET for power conservation |
| [Variable LED brightness (PWM)](./playground/VariableLED)    | LED, Arduino               | |
| [X113647Stepper](https://github.com/tardate/X113647Stepper)  | Stepper, Arduino           | It's common to find the 28BYJ-48 stepper motor and a X113647 Stepper Motor Driver Board in Arduino starter kits. However documentation is scant and the board is not exactly compatible with the standard Stepper library. See the [X113647Stepper github page](https://github.com/tardate/X113647Stepper) for details of the library, example programs, and custom Fritzing parts for the components. |
| [Zener Regulated 5V Source](./Electronics101/PowerZener)     | Power                      | test and graph a power supply regulated with a 1N4733 zener diode |


# Getting Up and Running

Some projects require additional libraries including FastLED, FlexiTimer2, RadioHead.
A set of such libraries are included as submodules of this repository,
see the [libraries/](./libraries) page for more information on the included libraries and submodule management.

Libraries can be retrieved with git, or you can just install them separately as you would any other library.

If you clone this repo, also update the submodules to have them available for compilation/installation:

    $ git submodule update --init

To pull submodule updates later on:

    $ git submodule foreach git pull

