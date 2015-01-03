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

See the datasheet for the related formulae. You can also find various websites that offer 555 timer calcuators,
but I decided to write my own [Visual 555 Calculator](http://visual555.tardate.com) so that I could play around with HTML5 animation of the resulting circuit;-)


### Powering the project

The breadboard can be happily powered from an independent 9V supply, as indicated in the schematic.
In this configuration, connecting the Arduino is purely optional -- enabling the realtime processing plot of the output state.

However, it is also possible to power the board directly from the Arduino 5V pin.

### Output State Plots

The output voltage is tapped at the anode of the LED, read with an analog input pin and echoed to the Arduino serial port.
It's important to have the Arduino measure the voltage across the LED only, since with a 9V supply this will only be in the order of 2V or so, not the full 7V+ at the
outpu pin 3 of the 555 timer.

[PlotNValues (a simple Processing sketch)](../../processing/PlotNValues) reads the data from the serial port and plots the output value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

Here's a sample trace:

![processing trace](./assets/processing_trace.png?raw=true)


### Construction

![The Breadboard](./assets/AstableOscillator_bb.jpg?raw=true)

![The Schematic](./assets/AstableOscillator_schematic.jpg?raw=true)

![The Build](./assets/AstableOscillator_build.jpg?raw=true)


## Credits and References
* [Download Processing](https://www.processing.org/download/)
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [Beginning Analog Electronics through Projects](http://www.amazon.com/gp/product/0750672838/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=0750672838&linkCode=as2&tag=itsaprli-20&linkId=D6X64MWAYQPEYQJC)
