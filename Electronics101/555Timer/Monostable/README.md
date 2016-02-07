# #017 555 Timer - Monostable Demo

Use an Arduino to demonstrate the monostable mode of operation, and plot the results with [Processing](https://www.processing.org).

Here's a quick video of the circuit in action:

[![555 Timer - Monostable Demo](http://img.youtube.com/vi/FJI0kTbzS4I/0.jpg)](http://www.youtube.com/watch?v=FJI0kTbzS4I)

## Notes

The monostable mode of operation is actually well described in the [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml).

When pin 2 is pulled low (the trigger), output pin 3 goes high and will remain high for a period of time determined by the values of R1 and C1.

### Selecting R1, C1 Values

The circuit described uses [R1=22k and C1=47uF](http://visual555.tardate.com/?mode=monostable&r1=22&c=47)
which results in the output remaining high for just over a second when triggered.
The formula for calculating the high period is:

    t = 1.1 x R1 x C1

See the datasheet for your chip to confirm the formula. You can also find various websites that offer 555 timer calcuators,
but I decided to write my own [Visual 555 Calculator](http://visual555.tardate.com) so that I could play around with HTML5 animation of the resulting circuit;-)


### Powering the project

The breadboard is powered directly from the Arduino 5V pin, although it could also be powered by an independent 5-9V supply.

### Input/Output State Plots

The output voltage is tapped at the anode of the LED, read with an analog input pin and echoed to the Arduino serial port.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

Here's a sample trace:

![processing trace](./assets/processing_trace.png?raw=true)


### Construction

![The Breadboard](./assets/Monostable_bb.jpg?raw=true)

![The Schematic](./assets/Monostable_schematic.jpg?raw=true)

![The Build](./assets/Monostable_build.jpg?raw=true)


## Credits and References
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [Beginning Analog Electronics through Projects](http://www.amazon.com/gp/product/0750672838/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672838&linkCode=as2&tag=itsaprli-20&linkId=D6X64MWAYQPEYQJC)
* [Download Processing](https://www.processing.org/download/)
* [#216: Back to Basics: 555 based monostable multivibrator | 555 tutorial](https://youtu.be/MbWc70ZzTlI) - another great video from w2aew that tells you all you ever wanted to know about 555 monostables
