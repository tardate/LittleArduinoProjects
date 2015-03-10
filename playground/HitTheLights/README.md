# HitTheLights

A simple LED game with LCD output.

## Notes

This is a quick build in response to a
[question on EE.SE](http://electronics.stackexchange.com/questions/93269/arduino-uno-r3-plus-digital-pins-overused).
It demonstrates there's no issue driving a series of LEDs and a 16x2 LCD at the same time.

### Game Mechanics

I'm not sure what the OP had in mind, but here's my version of the game:

Objective
* turn off all the LEDs as fast as possible

Rules
* LED1 to 4 turn on for a brief period in sequence
* pressing the button while the LED is on will disable it
* LEDs need to be disabled in sequence, LED4 to LED1
* game is over when all LEDs are off

The code keeps track of the current best score. It is not saved so will be lost over each reset of the Arduino.

The code is easily modified to do things like crank up the difficulty on each attempt.
With the default settings, the game is stupidly easy to play i.e. the anti Flappy Bird of the Arduino world.

## Handling the Button Press
Pushbutton is connected to pin 2, which is attached to hardware interrupt 0.

Normally the input is pulled low, but when the button is pressed, the pin is pulled high, triggering the RISING interrupt.

There is no debouncing implemented. Not that it matters much wiht this circuit, but I haven't seen any bouncing quirks so far.

### Construction

![The Breadboard](./assets/LedGame_bb.jpg?raw=true)

![The Schematic](./assets/LedGame_schematic.jpg?raw=true)

![The Build](./assets/LedGame_build.jpg?raw=true)

## Credits and References
* See the [original question](http://electronics.stackexchange.com/questions/93269/arduino-uno-r3-plus-digital-pins-overused) on EE.SE
* Arduino [LiquidCrystal](http://arduino.cc/en/Reference/LiquidCrystal) library reference
* [AttachInterrupt](http://arduino.cc/en/Reference/AttachInterrupt) function reference