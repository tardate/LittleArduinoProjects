# #337 GlowBall

Building LED effects for a Glass Eye Studio Celestial Planet Weight.

Here's is a video with a few soothing minutes of the glow effect;-)

[![Build](./assets/GlowBall_build.jpg?raw=true)](https://www.youtube.com/watch?v=hcFyM52ok7U)

## Notes

This [Glass Eye Studio "Celestial Super Nova"](http://www.glasseyestudio.com/492f-glass-eye-studio-celestial-super-nova/) was a gift.
Quite an awesome piece of glass work ... I have no idea how these can be manufactured in any quantity with consistency!
Perhaps I should find a [class](http://www.artglasscentre.com/studio.php)?!

You can buy a base with built-in lighting effects, but where is the fun in that?

Here's a project to make a base for the glass ball. Because it is going to be used on a desk, I decided to combine two functions:

* a multi-colour "glow" effect to light the ball
* or switch to power a 3528 LED strip (1m, 60 LEDs, 12V, cold white)


![GlowBall_build2](./assets/GlowBall_build2.jpg?raw=true)

## Case Construction

I found an old iPhone earbud case which makes a perfect housing.

![GlowBall_internals](./assets/GlowBall_internals.jpg?raw=true)

I pulled a bit of black cushion padding from another box to fill the clear box case
while allowing the LEDs to poke through to light the glass ball:

![GlowBall_case_front](./assets/GlowBall_case_front.jpg?raw=true)

LED strip plugs in on the left, power on the right:

![GlowBall_case_rear](./assets/GlowBall_case_rear.jpg?raw=true)


## Circuit Construction

The electronics are a combination of circuits (with some modifications) from two projects:

* [LEAP#337 RGB LED Glow Effects](../../Electronics101/RgbLedGlow)
* [LEAP#231 current-regulated LED dimmer circuit](../../Electronics101/LED/Dimmer/CurrentRegulator)


I've set this up powered from 12V. A three-position SPDT switch selects between: off, the glow ball effect, and powering the LED strip.

Key notes on the RGB LED Glow circuit:

* I've intentionally got the PNP driver transistors in back-to-front (C and E flipped). The transistors work, but just not as well. In this context, that is a good thing, because it creates an expanded "linear" region and very nice glow effects (I think). Current is not so high, hence the current-limiting resistors (360Ω) are lower than you might expect for 12V.
* the three triangle-wave oscillators are nominally identical, but component tolerances lead to the slight variation in performance which causes the red, green and blue LED poles to oscillate just slightly out of sync.
* the wave-offset adjustment pot (VR1) is a trimmer that I haven't exposed for external adjustment. I just set-and-forget it to a nice value for best effect.

Key notes on the LED Strip circuit:

* I'm using a 1N5711 instead of a 1N5819 because it was available. It is not carrying any real load so the most important feature is the similar forward voltage.
* the dimmer pot is the one mounted on the front of the case

![Schematic](./assets/GlowBall_schematic.jpg?raw=true)

![Breadboard](./assets/GlowBall_bb.jpg?raw=true)

FWIW, here are my scratchy notes on how I laid out the protoboard:

![GlowBall_board_layout](./assets/GlowBall_board_layout.jpg?raw=true)

![GlowBall_build](./assets/GlowBall_build.jpg?raw=true)

## Credits and References

* [LEAP#337 RgbLedGlow](../../Electronics101/RgbLedGlow) - project where I experimented with the basic RGB LED glow circuit
* [LEAP#231 LED/Dimmer/CurrentRegulator](../../Electronics101/LED/Dimmer/CurrentRegulator) - the project I borrowed the LED dimmer circuit from
* [Glass Eye Studio](http://www.glasseyestudio.com/)
* [Glass Eye Studio - Celestial Super Nova](http://www.glasseyestudio.com/492f-glass-eye-studio-celestial-super-nova/)
* [1N5711 Datasheet](https://www.futurlec.com/Diodes/1N5711.shtml)
* [A42 datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/138719/JIANGSU/A42.html)
* [2N3906 datasheet](https://www.futurlec.com/Transistors/2N3906.shtml)
* [RGB LED datasheet](https://www.futurlec.com/LED/RGB5LED.shtml)
* [LM358N Datasheet](https://www.futurlec.com/Linear/LM358N.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/08/leap338-going-glowball.html)
