# Girabot!

## Introduction

Girabot is my robot submission for the
[EE40LX Electronic Interfaces](https://courses.edx.org/courses/BerkeleyX/EE40LX/1T2015/info)
course run by BerkeleyX/Caltec.

## The Brief
The requirements are quite nicely open-ended;-)

* Change behavior based on photocell input
* Beep buzzer audibly
* Change behavior when it hears a loud noise
* Spin motors to move itself

## Final Video Demonstrations

Here is a video of the final build that demonstrates:

* Microphone/Buzzer/Motors: it dances to a tune in response to a load noise (clap)
* Photocell/Buzzer: it makes different noises when left/right photocells detect low light
* Motors: it randomly moves about when it's got nothing better to do


[![Girabot Demo](http://img.youtube.com/vi/vzpre0eKQ9U/0.jpg)](http://www.youtube.com/watch?v=vzpre0eKQ9U)

A couple of things to note in this demo:

* I've connected a 9V 1A power supply in place of the battery (because I'd run all my batteries dry at the time of filming)
* I strapped on an Arduino Uno instead of the Nano as described elsewhere, because the Nano wasn't available at the time

### Benchtest Walkthrough

The following video is a walkthrough of circuit functions on a breadboard prior to the final build:

[![Girabot Benchtest](http://img.youtube.com/vi/7voQVB9DMPM/0.jpg)](http://www.youtube.com/watch?v=7voQVB9DMPM)


## Photo Gallery

![Girabot_gallery](./assets/Girabot_gallery.jpg?raw=true)

* [the original stuffed toy](./assets/Girabot_01.jpg?raw=true)
* [breadboard benchtest](./assets/Girabot_02.jpg?raw=true)
* [circuit layout for transfering to protoboard](./assets/Girabot_03.jpg?raw=true)
* [the finished protoboard](./assets/Girabot_04.jpg?raw=true)
* [Girabot!](./assets/Girabot_05.jpg?raw=true)


## Girabot Design - My Take on the Robot Brief

I've decided to diverge from the suggested design in a couple of ways.
The most significant being that I'm basing the design on an
[Arduino Nano](http://arduino.cc/en/Main/arduinoBoardNano)
microcontroller instead of an MSP430, mainly because I had one on hand,
but also because it offers a relatively small form factor without compormising processing and I/O capabilities.

I'm also varying components and some details of the design in smaller ways.
The following sections describe how Girabot is designed to meet the primary criteria.
Along the way, I've referenced the experiments concerning various aspects of robot operation.


## Use-case: Girabot bahaves in response to photocell input

The Girabot is equiped with two LDRs - a "left eye" and "right eye".
These are actually mounted in the eyes and detect light sensitivity roughly +/- 90 degrees from front.

When Girabot detects relative darkness to one side, it will:
* provide an audible chirp (a distinct sound for left or right)
* and change it's movement towards the brighter side

### Proof-of-concept/Explorations
The following mini-projects explore the use of LDRs in a [Wheatstone Bridge](http://en.wikipedia.org/wiki/Wheatstone_bridge)

* [LDRComparator](../Electronics101/LDRComparator) - Low-light/proximity Trip Detector demonstration
* [LDRStereoTripDetector](../Electronics101/LDRStereoTripDetector) - demo LM324 OpAmp as threshold trigger for stereo LDR/Wheatstone Bridge sensor
* [StereoLightTrigger](../playground/StereoLightTrigger) - demo an interrupt-driven method for responding to LDR light threshold triggers


## Use-case: Girabot responds when it hears a loud noise

The Girabot is equiped with an electret microphone.
When it detects a loud noise (such as a clap or whistle), it will unlock a "special behaviour":
* Girabot will play a tune and dance along
* there will be at least one tune, maybe more...


### Proof-of-concept/Explorations
* [ElectretADC](../playground/ElectretADC) - plot the raw and aplified electret signal (LM324 preamp)
* [ElectretTrigger](../playground/ElectretTrigger) - LM324-amplified electret input triggers a tune when over audio threshold

### Implementation Notes

The electret microphone is biased to about 1V, and the AC component of the signal tapped via C1.

The microphone signal is then fed to the LM324 setup as a subtracting amplifier:

* positive input is set to Vcc/2 = 2.5V
* microphone signal fed to negative input

    Vo = G1 * Vmic + G2 * Vcc
    G1 = -R2/R1 = -220kΩ/2.2kΩ = -100
    G2 = (R1 + R2)/R1 * R4/(R3 + R4) = (2.2kΩ + 220kΩ)/2.2kΩ * 22kΩ/(22kΩ + 22kΩ) = 75.5

When no microphone signal, we are
[reading Vcc/2](http://www.wolframalpha.com/input/?i=%285*%282.2k%CE%A9+%2B+220k%CE%A9%29%2F2.2k%CE%A9+*+22k%CE%A9%2F%2822k%CE%A9+%2B+22k%CE%A9%29%29+-+2.5+*+220k%CE%A9%2F2.2k%CE%A9)
at the output.

But it is really sensitive to changes in the microphone signal. Basically every
[1mV results in a 100mV change in the output](http://www.wolframalpha.com/input/?i=0.001+*220k%CE%A9%2F2.2k%CE%A9).

The amplified signal is read by the Arduino, and when the signal exceeds a threshold, the Arduino triggers a tune played on the piezo speaker.


## Use-case: Girabot beeps a buzzer audibly

Girabot plays a tune on a piezo buzzer. This special behaviour is unlocked when it hears a load noise.


### Proof-of-concept/Explorations
* [El Jarabe Tapatío](../playground/JarabeTapatio) - play The Mexican Hat Dance on a piezo buzzer with LM 386 amplification
* [Popcorn](../playground/Popcorn) - How to make a piezo buzzer even more annoying? Make it play popcorn!


## Use-case: Girabot can move itself

The sample robot design does a "bouncy" thing with two DC motors.
I experimented with motor controls or various types, but after deciding on the Girabot form factor I'm thinking it is more appropriate
for Girabot to be a "walker" than a "bouncer". The walker design I'm attempting uses a single motor - similar to insect BEAM designs -
and I'm using a servo motor for better positional control.

A single-motor walker can be a difficult thing to make work with reasonable efficiency, as it relies on the right combination of weight distribution,
friction surfaces and geometry. Challenge accepted!

Worst case, Girabot is going to be a crappy walking but an outstanding dancer..

### Proof-of-concept/Explorations

* [MotorControlPWM](../playground/MotorControlPWM) - tests PWM speed control of a DC motor driven by an Arduino
* [ServoTest](../playground/ServoTest) - test the positioning accuracy of a servo motor driven by an Arduino


## Power

So far, power requirements for the various sub-systems are primarily 5V, with 9V alternative for the Arduino and the speaker sub-system:
* Arduino can take 9V unregulated or 5V regulated
* speaker subsystem tolerates a wide supply voltage. It will work with 5V, but should be louder with 9V

Power options include:
* 9V battery - allowing 9V and 5V rails
* 4 x AA/AAA - running everything at ~5V/6V, probably with zener regulated 5V source

Girabot is a pretty small build, so there's not much room for batteries. Although the AA/AAA option would provided greater capacity,
I think 9V is the way to go, purely from a size and weight perspective

So with a 9V source, I'm planning for two power rails in the system:
* 9V unregulated, current TBD
* 5V regulated, current TBD

Although the total current requirements are yet to be determined exactly, they will be more than the Arduino can safely deliver directly.
So the 5V will be supplied from the battery via an LM7805 regulator.

Given two power rails, there's a question of which should be used to power the Arduino:
* 9V unregulated fed to VIN
* 5V regulated fed to 5V pin

If a 9V supply is provided to VIN, it will go through the Arduino's regulator to provide 5V for internal operations and GPIO pins.
That is fine, however there is an issue that we now have two 5V supplies.
These will not be exactly equal and may cause problems (such as current reversals) if intermixed.
Since I will be providing 5V output from the Arduino to circuits powered by the 5V regulated supply,
I think it is safer to also power the Arduino via the 5V regulated supply.


### Proof-of-concept/Explorations
* [LM317 Adjustable Regulator](../Electronics101/Power317) - test and graph the adjustable voltage supply
* [LM7805 5V Regulated Supply](../Electronics101/Power7805) - test and graph the voltage supply
* [Zener Regulated 5V Source](../Electronics101/PowerZener) - test and graph a power supply regulated with a 1N4733 zener diode

## Issues and Workarounds

### Electrical Noise
The servo motors in particular appear responsible for putting considerable noise on the power rails.
the main side-effect is it's effect on the speaker circuit (the noise gets amplified as audible sound).

Reasonable noise abatement was achieved by filtering the power supply with 10nF capacitors across the power connections to the motors and each OpAmp unit.


### Sensitivity of the Audio Detection Circuit


## Construction

![The Breadboard](./assets/Girabot_bb.jpg?raw=true)

![The Schematic](./assets/Girabot_schematic.jpg?raw=true)

![The Build](./assets/Girabot_build.jpg?raw=true)

### Parts

| Ref | Part                            | Notes     |
|-----|---------------------------------|-----------|
| U1  | Arduino Nano v3                 | [official site](http://arduino.cc/en/Main/arduinoBoardNano) |
| IC1 | LM7805                          | [datasheet](http://www.futurlec.com/Linear/7805T.shtml) |
| IC2 | LM324N                          | [datasheet](http://www.futurlec.com/Linear/LM324N.shtml) |
| IC3 | LM386N-3                        | [datasheet](http://www.futurlec.com/Linear/LM386N-3.shtml) |
|     | TowerPro SG90                   | [datasheet](http://datasheet.sparkgo.com.br/SG90Servo.pdf) |
|     | 100nF ceramic capacitor         |   |
|     | 100μF electrolytic capacitor    |   |


## Credits and references
* [EE40LX Electronic Interfaces](https://courses.edx.org/courses/BerkeleyX/EE40LX/1T2015/info)
* [Wheatstone Bridge](http://en.wikipedia.org/wiki/Wheatstone_bridge)
* [Servo library reference](http://arduino.cc/en/Reference/Servo)
