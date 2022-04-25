# #631 Long Running Timer

Building a very low frequency 555 timer circuit.

![Build](./assets/LongRunning_build.jpg?raw=true)

## Notes

It's possible to configure the 555 Timer for very long periods,
for example
[5 minutes (300346.200 ms) @ 50.254% duty](https://visual555.tardate.com/?mode=astable&r1=10&r2=980&c=220)
using R1=10kΩ, R2=1MΩ, C1=220µF.

I tried to use a "zero electrolytics" approach with very large (1GΩ) capacitors to compenstate,
following a design published in Elektor Magazine.
Bottom line: I suspect leakage in my 555 timers sabotaged this attempt. I have documented the failure,
and also covered circuit combinations that do work.

So my conclusion for now: if I need a low frequency timer circuit (like over 5 minutes), then:

* use a 555 with electrolytics but accept that accuracy and stability issues
* or save all this bother and just use a microprocessor!

### Zero Electrolytics

With a normal stock of components it is hard to achieve very long periods without using electrolytic capacitors.

Electrolytics are not ideal and can makes the circuit less accurate and reliable. Main issues include
relatively high leakage current compared to ceramic film capacitors.

I saw a design for a Zero-Electrolytics 555 Timer by Albert van Dalen [Published in Elektor 5/2014 on page 74](https://www.elektormagazine.com/magazine/elektor-201405/26447). The solution is of course to use some very high resistances to compensate for lower capacitor values,
in this case a might 1GΩ!

The application in the article was for a timer to turn on a vacuum pump for a short period roughly every five minutes.

### First Attempt

I obtained some [1GΩ](https://www.aliexpress.com/item/32880593944.html) resistors and got to work.
Measureing 5 in parallel (the only way to get them within the range of any meters I own!) the average resistance clock in
t around 940MΩ - within the surpirsingly large 10% tolerance.

I simplified the circuit for testing purposes as I don't need to control an actual pump. Specific changes:

* using two LM555 timers rarther than single TLC556CN
* powered by 5V instead of 12V
* switch R1 and R2 so that R2 has the high-value resistor. This produces a duty cycle approaching 50% instead of 100%.
* added edge-trigger between oscillator (IC1) output and the monostable switch (IC2)
* changed the monostable switch (IC2) period to a short pulse of [510ms](https://visual555.tardate.com/?mode=monostable&r1=1000&c=0.47)

### Measuring with an Arudino

Since the frequency is far too low to measure with any frequency counters or scopes I have to hand,
I've also employed an Arduino Uno to monitor and log the actual period of each timer cycle.

See the [LongRunning.ino](./LongRunning.ino) sketch for details. It logs measurements to the serial console.

![bb](./assets/LongRunning_bb.jpg?raw=true)

![schematic](./assets/LongRunning_schematic.jpg?raw=true)

![bb_build](./assets/LongRunning_bb_build.jpg?raw=true)

## Breadboard Test

Hmmm. I was unable to get the breadboard circuit working with a single 1GΩ resistor.
It seems that leakage current or stray capacitances are too much for such a high resistance.

The best I could achieve was with 1GΩ cut down with 10mΩ in parallel. Some results:

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
I could no sustain oscillation with anything higer than 680pF for ~475ms frequency. Which kind
of defeats the purpose of using a high resistance for low frequancy timing.

The initial protoboard had fixed R1=10MΩ, R2=1GΩ, C1=470nF, with cockets for putting additional resistors in parallel with R2.
As with the breadboard, I could only get it to run with 10MΩ in parallel with R2:

![protoboard-initial](./assets/protoboard-initial.jpg?raw=true)


I do however get good results with 10MΩ resistors. Two examples:

R1=10MΩ, R2 = 10MΩ, C1 = 105 cermamic (1µF)
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

## Conclusions

I don't like giving up aon a circuit idea. But I am going to do that here.

The idea of using a 1GΩ resistor for a low frequency 555 counter without using electrolytics
is perhaps fine in theory. However it appears to be very finnecky and hard to achieve in practice.

The Elektor labs did report success, but with a few caveats about circuit design and careful component handling in order to achieve resonable results. I wasn't able to acheive anything even close. I primarily suspect excessive leakage that totally defeats the 1GΩ resistor; it is possible my "cheap 555 timers" are responsible, compared to the quality components used in the Elektor Lab.

So my conclusion for now: if I need a low frequency timer circuit (like over 5 minutes), then:

* use a 555 with electrolytics but accept that accuracy and stability issues
* or save all this bother and just use a microprocessor!

## Credits and References

* [Zero-Electrolytics 555 Timer](https://www.elektormagazine.com/magazine/elektor-201405/26447) By Albert van Dalen Published in Elektor 5/2014 on page 74
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [AttachInterrupt](https://www.arduino.cc/en/Reference/AttachInterrupt) function reference
* [RI40 0.25W 1G ohm glass glaze thick film resistors 10%](https://www.aliexpress.com/item/32880593944.html)
