# #602 Long Running Timer

Building a very low frequency 555 timer circuit, and pushing the envelope with a 1GΩ zero-electrolytic design using the low-leakage TLC556C.

![Build](./assets/LongRunning_build.jpg?raw=true)

## Notes

It's possible to configure the 555 Timer for very long periods,
for example
[5 minutes (300346.200 ms) @ 50.254% duty](https://visual555.tardate.com/?mode=astable&r1=10&r2=980&c=220)
using R1=10kΩ, R2=1MΩ, C1=220µF.

I tried to use a "zero electrolytics" approach with a very large (1GΩ) resistor to compensate,
following a design published in Elektor Magazine.

I didn't have any success with this at first, as represented in the first design and set of conclusions below ("Zero Electrolytics - Round 1").

It turned out that discharge leakage overwhelmed the low currents with a 1GΩ resistor.

I ran a second round of tests using a low-leakage TLC556C. This was much more successful - a true long-running zero-electrolytic solution.
See "Zero Electrolytics - Round 2".

So my final conclusion:

* long running timer circuits using high value (1GΩ) resistors and zero-electrolytics is possible, but requires a low-leakage timer. The TLC556C is the only variant I currently know that satisfies this requirement.
* if one does not have a low-leakage TLC556C, then:
    * use a 555 with electrolytics but accept that accuracy and stability issues
    * or save all this bother and use a microprocessor or other digital circuit timing circuit!

## Zero Electrolytics - Round 1

### Zero Electrolytics

With a normal stock of components it is hard to achieve very long periods without using electrolytic capacitors.

Electrolytics are not ideal and can makes the circuit less accurate and reliable. Main issues include
relatively high leakage current compared to ceramic film capacitors.

I saw a design for a Zero-Electrolytics 555 Timer by Albert van Dalen [Published in Elektor 5/2014 on page 74](https://www.elektormagazine.com/magazine/elektor-201405/26447). The solution is of course to use some very high resistances to compensate for lower capacitor values,
in this case a mighty 1GΩ!

The application in the article was for a timer to turn on a vacuum pump for a short period roughly every five minutes.

### First Attempt

I obtained some [1GΩ](https://www.aliexpress.com/item/32880593944.html) resistors and got to work.
Measuring 5 in parallel (the only way to get them within the range of any meters I own!), the average resistance was
around 940MΩ - within the surprisingly large 10% tolerance.
I simplified the circuit for testing purposes as I don't need to control an actual pump. Specific changes:

* using two LM555 timers rather than single TLC556CN
* powered by 5V instead of 12V
* switch R1 and R2 so that R2 has the high-value resistor. This produces a duty cycle approaching 50% instead of 100%.
* added edge-trigger between oscillator (IC1) output and the monostable switch (IC2)
* changed the monostable switch (IC2) period to a short pulse of [510ms](https://visual555.tardate.com/?mode=monostable&r1=1000&c=0.47)

### Measuring with an Arduino

Since the frequency is far too low to measure with any frequency counters or scopes I have to hand,
I've also employed an Arduino Uno to monitor and log the actual period of each timer cycle.

See the [LongRunning.ino](./LongRunning.ino) sketch for details. It logs measurements to the serial console.

![bb](./assets/LongRunning_bb.jpg?raw=true)

![schematic](./assets/LongRunning_schematic.jpg?raw=true)

![bb_build](./assets/LongRunning_bb_build.jpg?raw=true)

## Breadboard Test

Hmmm. I was unable to get the breadboard circuit working with a single 1GΩ resistor.
It seems that leakage current or stray capacitances are too much for such a high resistance.

The best I could achieve was with 1GΩ cut down with 10MΩ in parallel. Some results:

### R2 = 10MΩ

[9771.300 ms @ 66.667 % duty cycle](https://visual555.tardate.com/?mode=astable&r1=10000&r2=10000&c=0.47)
with R1=10MΩ, R2=10MΩ, C1=470nF.

The actual cycle time is averaging a little higher than predicted, but relatively stable ±20ms.

Sample results logged by the Arduino:

    Triggered ON after : 11040 ms
    Triggered ON after : 11062 ms
    Triggered ON after : 11078 ms
    Triggered ON after : 11079 ms
    Triggered ON after : 11079 ms
    Triggered ON after : 11070 ms
    Triggered ON after : 11065 ms
    Triggered ON after : 11070 ms

### Adding a 1GΩ

With a 1GΩ resistors in parallel with 10MΩ for R2,
[9706.803 ms @ 66.777 % duty](https://visual555.tardate.com/?mode=astable&r1=10000&r2=9900.99&c=0.47)

Sample results logged by the Arduino:

    Triggered ON after : 11013 ms
    Triggered ON after : 11015 ms
    Triggered ON after : 11018 ms
    Triggered ON after : 11017 ms
    Triggered ON after : 11016 ms
    Triggered ON after : 11007 ms
    Triggered ON after : 11014 ms
    Triggered ON after : 11012 ms

## Protoboard Build

I thought perhaps I'd have better luck putting the circuit on a breadboard.

TLDR: no! The best I could achieve was with two 1GΩ in parallel (500MΩ) but in that case
I could no sustain oscillation with anything higher than 680pF for ~475ms frequency. Which kind
of defeats the purpose of using a high resistance for low frequency timing.

The initial protoboard had fixed R1=10MΩ, R2=1GΩ, C1=470nF, with sockets for putting additional resistors in parallel with R2.
As with the breadboard, I could only get it to run with 10MΩ in parallel with R2:

![protoboard-initial](./assets/protoboard-initial.jpg?raw=true)

I do however get good results with 10MΩ resistors. Two examples:

R1=10MΩ, R2 = 10MΩ, C1 = 105 ceramic (1µF)
[20790.000 ms](https://visual555.tardate.com/?mode=astable&r1=10000&r2=10000&c=1)
measured: 21879 ms

While resorting to electrolytics, I get good low frequency results.
With R1=10MΩ, R2 = 10MΩ, C1 = 10µF electrolytic
[207900.000 ms](https://visual555.tardate.com/?mode=astable&r1=10000&r2=10000&c=10)
measured: 270739 ms

    Triggered ON after : 270739 ms
    Triggered ON after : 270415 ms
    Triggered ON after : 270280 ms
    Triggered ON after : 270272 ms
    Triggered ON after : 270136 ms
    Triggered ON after : 270040 ms

Stability is not too bad?? (±500ms).

## Conclusions - Round 1

I don't like giving up on a circuit idea. But I did for a time!

The idea of using a 1GΩ resistor for a low frequency 555 counter without using electrolytics
is perhaps fine in theory. However it appears to be very finnicky and hard to achieve in practice.

The Elektor labs did report success, but with a few caveats about circuit design and careful component handling in order to achieve reasonable results. I wasn't able to achieve anything even close. I primarily suspect excessive leakage that totally defeats the 1GΩ resistor; it is possible my "cheap 555 timers" are responsible, compared to the quality components used in the Elektor Lab.

So my conclusion for now: if I need a low frequency timer circuit (like over 5 minutes), then:

* use a 555 with electrolytics but accept that accuracy and stability issues
* or save all this bother and just use a microprocessor!

Hmm, do we really need a microprocessor?

[Steve Schnepp](https://github.com/steveschnepp) makes a
[good point](https://github.com/tardate/LittleArduinoProjects/issues/28)
that cascading CD4060 counters is a perfectly good digital solution that provides the accuracy and reliability without need to
go all-in on a microprocessor:

> To have long delays, you are right, to avoid analogic error margins, one usually needs to go digital.
>
> But I'm not sold on always using an MCU. It is the "too easy" road.
>
> As soon as you realize you will only leverage its counter/timer it makes a CD4060 rather well suited to the task. You can cascade them if very long delays are needed, or use it with a quartz if precision is important.
>
> Only power of 2 are available, but if you go with a watch clock quartz of 32kHz, 2 CD4060 in cascade & some DIP-switch and diode logic, you can have a very easy programmable timer.
>
> Note: if you really want to go the no-surprise road, you might need to leverage a CD4040 instead of the 2nd CD4060, as the latter has "holes" (to offer bigger divisions without increasing of the DIP form factor).

## Zero Electrolytics - Round 2

### Revisiting the 1GΩ Zero-Electrolytic Design

The [TLC556CD](https://www.ti.com/product/TLC556) used in the original Elektor circuit is not your normal 556.

Looking closer at the datasheet, it promises:

> Accurate time delays and oscillations are possible with smaller, less-expensive timing capacitors than the NE556 because of the high input impedance.

I was steered towards the critical [discharge leakage](https://github.com/tardate/LittleArduinoProjects/issues/28) specification
by [Steve Schnepp](https://github.com/steveschnepp).
At VCC=5V, the TLC556C discharge off-state current is 0.5nA max.

This compares to the 200x larger 100nA max for the [LM555](https://www.futurlec.com/Linear/LM555CN.shtml) and most other 555/556 variants I have seen.

I purchased some [TLC556CD](https://www.ti.com/product/TLC556), so time to see if the reduced leakage current makes a big enough difference.

### Revised Circuit

![bb](./assets/LongRunning-TLC556_bb.jpg?raw=true)

![schematic](./assets/LongRunning-TLC556_schematic.jpg?raw=true)

![bb_build](./assets/LongRunning-TLC556_bb_build.jpg?raw=true)

### Measured Results

With R1=10MΩ, R2 = 1GΩ, C1 = 474 ceramic (470nF) the expected duration is
[654677 ms](https://visual555.tardate.com/?mode=astable&r1=10000&r2=1000000&c=0.47)

Again I'm using  the Arduino sketch [LongRunning.ino](./LongRunning.ino) to log measurements to the serial console.

While running in steady state, I collected the following samples, for an average of 628516ms.
this is pretty good result: fairly stable ±1%, and only 4% lower than the predicted value.

    Triggered ON after : 633412 ms
    Triggered ON after : 631109 ms
    Triggered ON after : 629737 ms
    Triggered ON after : 628732 ms
    Triggered ON after : 627938 ms
    Triggered ON after : 627244 ms
    Triggered ON after : 626650 ms
    Triggered ON after : 626099 ms
    Triggered ON after : 625724 ms

![LongRunning-TLC556_console](./assets/LongRunning-TLC556_console.jpg?raw=true)

## Conclusions - Round 2

A low leakage timer like the [TLC556C](https://www.ti.com/product/TLC556) makes it possible to
configure a long running timer with high value resistors and no electrolytics.

Results, even on a breadboard, are very stable and close to predicted timings.

The caveat is that the timer component is critical: it must have a very low discharge off-state current like the TLC556C.

## Credits and References

* [Zero-Electrolytics 555 Timer](https://www.elektormagazine.com/magazine/elektor-201405/26447) By Albert van Dalen Published in Elektor 5/2014 on page 74
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [TLC556 Datasheet](https://www.ti.com/product/TLC556)
* [AttachInterrupt](https://www.arduino.cc/en/Reference/AttachInterrupt) function reference
* [RI40 0.25W 1G ohm glass glaze thick film resistors 10%](https://www.aliexpress.com/item/32880593944.html)
