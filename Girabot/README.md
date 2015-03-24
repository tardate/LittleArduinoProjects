# Girabot! (WIP)

## Introduction

Girabot is my robot submission for the most excellent
[EE40LX Electronic Interfaces](https://courses.edx.org/courses/BerkeleyX/EE40LX/1T2015/info)
course run by BerkeleyX/Caltec.

This is currently a work-in-progress...


## The Brief
The requirements are fairly generic:

* Change behavior based on photocell input
* Beep buzzer audibly
* Change behavior when it hears a loud noise
* Spin motors to move itself

### The Original/Suggest Robot Design

## Girabot Design

I've decided to diverge from the suggested design in a couple of ways.
The most significant being that I'm basing the design on an Arduino Nano microcontroller, mainly because I had one on hand,
but also because it offers a relatively small form factor without compormising processing and I/O capabilities.

I'm also varying components and some details of the design in smaller ways.
The following sections describe how Girabot is designed to meet the primary criteria.
Along the way, I've referenced the experiments concerning various aspects of robot operation.


## Use-case: Girabot bahaves in response to photocell input

I've yet to decide on the exact behaviour to give Girabot.
...

### Proof-of-concept/Explorations
The following mini-projects explore the use of LDRs in a [Wheatstone Bridge](http://en.wikipedia.org/wiki/Wheatstone_bridge)

* [LDRComparator](../Electronics101/LDRComparator) - Low-light/proximity Trip Detector demonstration
* [LDRStereoTripDetector](../Electronics101/LDRStereoTripDetector) - demo LM324 OpAmp as threshold trigger for stereo LDR/Wheatstone Bridge sensor
* [StereoLightTrigger](../playground/StereoLightTrigger) - demo an interrupt-driven method for responding to LDR light threshold triggers


## Use-case: Girabot responds when it hears a loud noise

Load noise will trigger a particular behaviour. I think it's going to dance..
...

### Proof-of-concept/Explorations
* [ElectretADC](../playground/ElectretADC) - plot the raw and aplified electret signal (LM324 preamp)
* [ElectretTrigger](../playground/ElectretTrigger) - LM324-amplified electret input triggers a tune when over audio threshold


## Use-case: Girabot beeps a buzzer audibly

Possibly:
* Girabot is going to accompany
* Girabot is going to accompany
...

### Proof-of-concept/Explorations
* [Popcorn](../playground/Popcorn) - How to make a piezo buzzer even more annoying? Make it play popcorn!
* [Jarabe Tapatío](./playground/JarabeTapatio) - play The Mexican Hat Dance on a piezo buzzer

## Use-case: Girabot can move itself

Rather than do the "bouncy" thing with two DC motors, I'm thinking instead of a servo-powered "walker". Let's see..
...

### Proof-of-concept/Explorations

* [MotorControlPWM](../playground/MotorControlPWM) - tests PWM speed control of a DC motor driven by an Arduino
* [ServoTest](../playground/ServoTest) - test the positioning accuracy of a servo motor driven by an Arduino

## Power

...

### Proof-of-concept/Explorations
* [LM317 Adjustable Regulator](../Electronics101/Power317) - test and graph the adjustable voltage supply
* [LM7805 5V Regulated Supply](../Electronics101/Power7805) - test and graph the voltage supply
* [Zener Regulated 5V Source](../Electronics101/PowerZener) - test and graph a power supply regulated with a 1N4733 zener diode

## Bells & Whistles

LEDs in the tail? In addition to running some effects, I'm thinking these will give some visual feedback of the processing state for diagnostic purposes.

## Construction

![The Breadboard](./assets/Girabot_bb.jpg?raw=true)

![The Schematic](./assets/Girabot_schematic.jpg?raw=true)

![The Build](./assets/Girabot_build.jpg?raw=true)

### Parts

| Ref | Part                            | Notes     |
+-----+---------------------------------+-----------+
|     | TowerPro SG90                   | [datasheet](http://datasheet.sparkgo.com.br/SG90Servo.pdf) |
|     | LM7805                          | [datasheet](http://www.futurlec.com/Linear/7805T.shtml) |


## Credits and references
* [EE40LX Electronic Interfaces](https://courses.edx.org/courses/BerkeleyX/EE40LX/1T2015/info)
* [Wheatstone Bridge](http://en.wikipedia.org/wiki/Wheatstone_bridge)
* [Servo library reference](http://arduino.cc/en/Reference/Servo)
