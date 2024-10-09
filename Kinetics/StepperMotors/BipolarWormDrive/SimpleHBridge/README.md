# #429 Bipolar Linear Stepper with an H-Bridge

Testing some linear/worm-drive stepper motors salvaged from a DVD drive unit, using a bespoke H-bridge circuit and Arduino .. or pushbuttons!

![Build](./assets/SimpleHBridge_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/Mkn8nW2BEYc/0.jpg)](https://www.youtube.com/watch?v=Mkn8nW2BEYc)

## Notes

Many CD/DVD drives use a biopolar stepper motor with worm gear for linear positioning of the laser head.
The [tear down of an HL GCR-8483B](http://wasp.kz/articles.php?article_id=959) is a good example.

Here are two similar motor units I've scavenged. The part numbers are un-googlable internal references:

* D4907M1F/15RF073K for upper in the picture below
* D6124NID for the lower


![worm_drive_units](./assets/worm_drive_units.jpg?raw=true)


### Drive Specifications

I haven't been able to find any specifications for these drive units, but from my experiments I've gathered the following:

| Item                    |  Specification | Notes                                                                 |
|-------------------------|----------------|-----------------------------------------------------------------------|
| Voltage                 | 5V             | operates from ~2.5V but at that level not able to deliver much torque |
| Current                 | 170mA          | total current while rotating without load, including h-bridge circuit |
| Steps per Revolution    | 20             |                                                                       |
| Revolutions Full Travel | 11             | any attachment would reduce effective full travel                     |

These measurements have only been verified for the D4907M1F/15RF073K unit.

### Connections

It seems the 4 wires to the drive are connected in a somewhat unusual order: A, B, D, C.

* A and B are a coil pair
* D and C are a coil pair, but reversed polarity

NB: if the connections for D and C are reversed, the stepper still "works", but at only a fraction of the torque as half the time the coils are battling each other.

![worm_drive_connectors](./assets/worm_drive_connectors.jpg?raw=true)

### Driving a Bipolar Stepper

Some great resources for bipolar stepper motors:

* [The Adafruit guide to choosing and using stepper motors](https://learn.adafruit.com/all-about-stepper-motors/what-is-a-stepper-motor)
* [ST Application Note AN235 "Stepper motor driving"](https://www.st.com/content/ccc/resource/technical/document/application_note/57/c8/7c/c1/0d/91/46/89/CD00003774.pdf/files/CD00003774.pdf/jcr:content/translations/en.CD00003774.pdf) - an excellent place to start. It's detailed and practical.

Kevin Darrah also has a good introduction and demo of driving a bipolar stepper with push buttons:

[![clip](https://img.youtube.com/vi/ePSCZ_DtF7c/0.jpg)](https://www.youtube.com/watch?v=ePSCZ_DtF7c)


The essence of bipolar stepper control:

* two independent coils
* exciting the coils in a specific sequence, generally either:
    * in 4 full steps: 1, 3, 5, 7 in the diagram below
    * or 8 half steps
* since this requires reversing the polarity on the coils, is best achieved with an [H bridge](https://en.wikipedia.org/wiki/H_bridge)

[![bipolar_half_step_sequence.png](./assets/bipolar_half_step_sequence.png?raw=true)](https://www.st.com/content/ccc/resource/technical/document/application_note/57/c8/7c/c1/0d/91/46/89/CD00003774.pdf/files/CD00003774.pdf/jcr:content/translations/en.CD00003774.pdf)

The result is 8 combinations of drive conditions as tabulated below:

* can be cycled in either direction for forward/reverse drive control
* using only the 4 steps that drive both coils (1,3,5,7) is full-step control and delivers maximum torque
* using all 8 steps provides half-step control provides more selectivity of positioning, but at a loss of torque (because half the steps only use one drive coil)


| Step | A  | B  | C  | D  | Full | Half |
|------|----|----|----|----|------|------|
|    1 |  + |  - |  - |  + | Yes  | Yes  |
|    2 |    |    |  - |  + | No   | Yes  |
|    3 |  - |  + |  - |  + | Yes  | Yes  |
|    4 |  - |  + |    |    | No   | Yes  |
|    5 |  - |  + |  + |  - | Yes  | Yes  |
|    6 |    |    |  + |  - | No   | Yes  |
|    7 |  + |  - |  + |  - | Yes  | Yes  |
|    8 |  + |  - |    |    | No   | Yes  |


### The Arduino Stepper Library

The [Stepper Library](https://www.arduino.cc/en/reference/Stepper) is used in the example [SimpleHBridge.ino](./SimpleHBridge.ino) sketch.

It supports 4-wire bipolar steppers using an external H-bridge, and only implements full step control with the following sequence:


|Step | A  | B  | C  | D  |
|-----|----|----|----|----|
|   1 |  1 |  0 |  1 |  0 |
|   2 |  0 |  1 |  1 |  0 |
|   3 |  0 |  1 |  0 |  1 |
|   4 |  1 |  0 |  0 |  1 |


### A Bespoke H-bridge Circuit

To control a bipolar stepper, we basically need an [H bridge](https://en.wikipedia.org/wiki/H_bridge) for each coil.
There are dedicated chips/modules for this - a popular one being the [DRV8825 Stepper Motor Driver](https://www.pololu.com/product/2133).

But in this case I decided to build the H bridge control circuit on a breadboard. Key points to note:

* all MOSFETS not BJTs for more positive switching control
* all n-channel (rather than paired p-channel, n-channel) as control and motor circuits are running at 5V, so switching the high-side nFETs is no issue.
* I've included flyback diodes, though at these power levels they are not essential

I've included manual push-buttons in addition to Arduino control, and used these to verify drive control before hooking up the Arduino.

## Construction

![Breadboard](./assets/SimpleHBridge_bb.jpg?raw=true)

![Schematic](./assets/SimpleHBridge_schematic.jpg?raw=true)

## Performance

I hooked it up to a scope to see the control signals..

![SimpleHBridge_test](./assets/SimpleHBridge_test.jpg?raw=true)

Not much to see here. However, this is a capture of the onset of one coil being activated:

![scope](./assets/scope.gif?raw=true)

## Credits and References

* [HL GCR-8483B CD-ROM, complete disassembly](http://wasp.kz/articles.php?article_id=959)
* [Stepper Library](https://www.arduino.cc/en/reference/Stepper)
* [H bridge](https://en.wikipedia.org/wiki/H_bridge) - wikipedia
* [ST Application Note AN235](https://www.st.com/content/ccc/resource/technical/document/application_note/57/c8/7c/c1/0d/91/46/89/CD00003774.pdf/files/CD00003774.pdf/jcr:content/translations/en.CD00003774.pdf) - Stepper motor driving
* [The Adafruit guide to choosing and using stepper motors](https://learn.adafruit.com/all-about-stepper-motors/what-is-a-stepper-motor)
* [DRV8825 Stepper Motor Driver](https://www.pololu.com/product/2133)
* [..as mentioned on my blog](https://blog.tardate.com/2018/11/leap430-driving-scavenged-linear-steppers.html)
