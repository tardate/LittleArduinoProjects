# 555 Timer - A-Stable Oscillator

Use an Arduino to demonstrate the basic astable mode of operation, and plot the results with [Processing](https://www.processing.org).

Here's a quick video of the circuit in action:

[![555 Timer - A-Stable Oscillator](http://img.youtube.com/vi/1vZiGZan2ok/0.jpg)](http://www.youtube.com/watch?v=1vZiGZan2ok)

## Notes

The oscillator circuit is based on project 1 from [Beginning Analog Electronics through Projects](http://www.amazon.com/gp/product/0750672838/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672838&linkCode=as2&tag=itsaprli-20&linkId=D6X64MWAYQPEYQJC), and any number of other examples you can find with a quick Google search.

The a-stable mode of operation is actually well described in the [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml).
This circuit produces a free-running square wave at the output pin 3, with frequency and duty cycle determined by the values of R1, R2, and C1.


### Selecting R1, R2, C1 Values

The circuit described uses
[R1=10k, R2=330k and C1=2.2uF](http://visual555.tardate.com?r1=10&r2=330&c=2.2),
which results in a frequency of just about 1Hz and 50% duty cycle. i.e. half a second on, half a second off.

When selecting R1, R2, and C1 values, note that:

* the time low is a function of R2 and C1, so R1 will not affect it. Increasing R1 and C1 will increase the time low.
* the time high is a function of R1, 2*R2, C1. Increasing any of these values will increase the time high.
* the ratio of time high to time low is (R1 + R2)/R2, so the smaller R1 is compared to R2, the closer we get to a 50% duty cycle.

The formulae for calculating timings are:

    t(high) = 0.693 x (R1 + R2) x C1
    t(low) = 0.693 x R2 x C1

See the datasheet for your chip to confirm the formulae. You can also find various websites that offer 555 timer calcuators,
but I decided to write my own [Visual 555 Calculator](http://visual555.tardate.com) so that I could play around with HTML5 animation of the resulting circuit;-)


### Powering the project

The breadboard can be happily powered from an independent 9V supply, as indicated in the schematic.
In this configuration, connecting the Arduino is purely optional -- enabling the realtime processing plot of the output state.

However, it is also possible to power the board directly from the Arduino 5V pin.

### Output State Plots

The output voltage is tapped at the anode of the LED, read with an analog input pin and echoed to the Arduino serial port.
It's important to have the Arduino measure the voltage across the LED only, since with a 9V supply this will only be in the order of 2V or so, not the full 7V+ at the
output pin 3 of the 555 timer.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

Here's a sample trace for [R1=10k, R2=330k and C1=2uF](http://visual555.tardate.com?r1=10&r2=330&c=2):

![processing trace](./assets/processing_trace.png?raw=true)


### Construction

![The Breadboard](./assets/AstableOscillator_bb.jpg?raw=true)

![The Schematic](./assets/AstableOscillator_schematic.jpg?raw=true)

![The Build](./assets/AstableOscillator_build.jpg?raw=true)


## Credits and References
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [Beginning Analog Electronics through Projects](http://www.amazon.com/gp/product/0750672838/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672838&linkCode=as2&tag=itsaprli-20&linkId=D6X64MWAYQPEYQJC)
* [Download Processing](https://www.processing.org/download/)
