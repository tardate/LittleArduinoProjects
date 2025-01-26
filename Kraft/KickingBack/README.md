# #492 Kicking Back

A useless machine/desktop toy that employs some overly complex mechanics to simply kick a ball (in a minor homage to @mPinoe).

![Build](./assets/KickingBack_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/zd012kxD8V8/0.jpg)](https://www.youtube.com/watch?v=zd012kxD8V8)

## Notes

Kicking Back is a desktop toy that uses a hall-effect sensor picking up a magnet in a ball to trigger the player to kick it back. The sensor input goes to an edge-detection circuit that triggers a 555 monostable, ensuring a reliable (and adjustable) "kick" pulse is delivered to the solenoid that controls the player, regardless of how fleeting the sensor input is.

The project started as an experiment with hall effect sensors and edge detection, but soon blossomed into a fully-fledged desktop toy.
And along the way became a minor homage to [@mPinoe](https://twitter.com/mPinoe) - I just hope she's not offended by the rough and ready paint job!

Does this also count as a "useless machine"? Perhaps?!! .. so on the off-chance I've entered it in the [MacroFab Design Contest: Useless Machine](https://macrofab.com/blog/macrofab-design-contest-useless-machine-sponsored-by-mouser-electronics/)


## Control Circuit

The control circuit triggers a solenoid that provides the kinetic movement for the sculpture.

The circuit breaks down into the following stages:

* a hall-effect sensor detects a neodymium magnet in the ball
* falling edge detection with a PNP inverter (Q1) generates a pulse when edge detected
* the falling edge pulse triggers a 555 timer configured for monostable operation
* the 555 timer's threshold input is normally pulled low (R6), and a diode (D1) is included to absorb the opposite edge pulse.
* a 50kΩ pot (R2) adjusts the monostable output pulse width
* 555 output is active-low, so is used for PNP (Q2) high-side switching of the solenoid and indicator LED
* a diode (D2) provides flyback protection from the solenoid

The adjustable output pulse allows it to be set at an appropriate length to fully activate the solenoid with out it remaining on too long.

![Breadboard](./assets/KickingBack_bb.jpg?raw=true)

![Schematic](./assets/KickingBack_schematic.jpg?raw=true)

The scope trace below shows the pulse generated on the rising edge of the input.
The output pulse is around 55ms, close to the calculated [52ms](https://visual555.tardate.com/?mode=monostable&r1=4.7&c=10).

* CH1 (yellow) - hall-effect sensor output
* CH2 (blue) - edge-detection pulse (input to the 555)
* CH3 (red) - output, measured at the collector of the high-side PNP switch Q2

![trigger_signal_scope](./assets/trigger_signal_scope.gif?raw=true)

## Construction

The build (in fact this project) started with playing around with a rocker design (onto which the ball is mounted), and evolved from there..

![design_notes](./assets/design_notes.jpg?raw=true)

The rocker is quite well balanced, so that any impact on the ball generates a generous movement that oscillates freely.

![build_ball_rocker](./assets/build_ball_rocker.jpg?raw=true)

All the eletronics are on protoboard that is inserted in the base. In the final build (after this photo),
I took the LED off the board and mounted it in the base.

![build_control_board](./assets/build_control_board.jpg?raw=true)

Building the player. Simple wire and pulley system with the key movements:

* solendoid pulls on lever to kick the leg
* in turn joined to separate arm levers (making the left arm go forward, and right arm go back)

It's all ad-hoc wire contruction, with popsicle sticks for arms and legs.

![build_player_wip](./assets/build_player_wip.jpg?raw=true)

Mounting the control board in the base (which is actually Ikea packaging material).

![build_install1](./assets/build_install1.jpg?raw=true)

Finally built *save the head!) and ready for final beautifiction.

![build_install3](./assets/build_install3.jpg?raw=true)

All done and painted..

![KickingBack_build](./assets/KickingBack_build.jpg?raw=true)

![KickingBack_build2](./assets/KickingBack_build2.jpg?raw=true)

![KickingBack_demo](./assets/KickingBack_demo.gif?raw=true)

## Credits and References

* [2N3906 datasheet](https://www.futurlec.com/Transistors/2N3906.shtml)
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* Entered in the [MacroFab Design Contest: Useless Machine ](https://macrofab.com/blog/macrofab-design-contest-useless-machine-sponsored-by-mouser-electronics/) - [see all the contest entries](https://hackaday.io/projects?tag=MacroFab%20Design%20Contest%3A%20Useless%20Machine)
* [MP4 to GIF converter](https://www.onlineconverter.com/mp4-to-gif) - the tool I used to create the animated GIFs (nice - supports scaling)
* [Kicking Back](https://hackaday.io/project/167412-kicking-back) - on hackaday.io
