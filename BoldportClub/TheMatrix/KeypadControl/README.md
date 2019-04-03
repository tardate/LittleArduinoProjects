# #307 TheMatrix/KeypadControl

Use a 20-button keypad to write a scrolling message on the Boldport Matrix.

Here's a quick video showing it in action..

[![Build](./assets/KeypadControl_build.jpg?raw=true)](https://www.youtube.com/watch?v=qg2Bs1Q0ACw)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

So... ways to get arbitrary messages onto the Boldport Matrix?

I happen to have a [KeyboardMatrixModule](../../../playground/KeyboardMatrixModule) that is coincidentally 5 keys high by 4 wide ..
a number that neatly fits into the 24x5 display port of the Matrix.

So I've wired it up and enabled a couple of commands in the [KeypadControl.ino](./KeypadControl.ino) sketch:

* pressing any single button toggles the state of the corresponding LED
* at first, it is operating on the left-most 4 columns of LEDs
* pressing S3+S4 together shift the working window 4 LEDs right
* pressing S1+S2 together shift the working window 4 LEDs left
* pressing S2+S3 together toggle the message scrolling..

Interesting ... but not very practical! Maybe good for a gadget that you can let random bystanders fiddle with your matrix display..

I had a problem getting the scrolling to stop started, but a little help from the
[BoldportClub Community on Slack](https://boldportclub.slack.com/) goes a long way!
Problem sorted: it seems you must let the movie finish by switching it out of infinite loop first e.g.:
```
ledDriver.setMovieLoopCount(AS1130::MovieLoop1);
ledDriver.setFrameDelayMs(0);
```

A recent update to the [LuckyResistor/LRAS1130 library (v0.9.5)](https://github.com/LuckyResistor/LRAS1130/releases/tag/v0.9.5)
fixed some issues with LED brightness control. Now everything is looking so much brighter!

![bright_matrix](./assets/bright_matrix.jpg?raw=true)

## Construction

![Breadboard](./assets/KeypadControl_bb.jpg?raw=true)

![Schematic](./assets/KeypadControl_schematic.jpg?raw=true)

![Build](./assets/KeypadControl_build.jpg?raw=true)

## Credits and References
* [LEAP#299 TheMatrix](../TheMatrix)
* [LEAP#303 KeyboardMatrixModule](../../../playground/KeyboardMatrixModule)
* [LuckyResistor/LRAS1130](https://github.com/LuckyResistor/LRAS1130) - A library to control the AS1130 LED driver chip.
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap307-boldport-matrix-keypad-control.html)
