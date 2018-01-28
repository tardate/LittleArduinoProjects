# #045 SimpleSiren

Classic timer circuit producing a two-tone oscillation.


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is a build of a circuit published by [electronicshub](http://www.electronicshub.org/ding-dong-sound-generator-circuit/).

It is allegedly a "ding dong" bell.. sounds more like a siren to me!

It operates with two oscillating 555 timers chained together.

The first 555 provides the low frequency oscillation between high and low output states. The frequency is determined by the values of R1, VR1 and C1.
With [R1=2.2kΩ, VR1 at 22kΩ and C1=47μF](http://visual555.tardate.com/?mode=astable&r1=2.2&r2=22&c=47) this runs at 0.7Hz and 52% duty cycle.

The pin 3 output of the first time switches the control voltage of the second 555 timer.
In practice, with R3=1kΩ in place, it switches from 1.57V to 7.06V, as measured with a multimeter.

The oscilation of the second 555 drives the output peizo, and the frequency is modified by the control voltage.


1.57 high
7.06 low

When Vcontrol = 1.57V, the frequency of the oscillation is 566 Hz - see the [actual calculation on WolframAlpha](http://www.wolframalpha.com/input/?i=f+%3D+1%2F%28+100*10^-9+*+%282200+%2B+22000%29ln%281+%2B+1.57%2F%282+*+%289+-+1.57%29%29%29+%2B+100*10^-9+*+22000+*+ln%282%29+%29)

When Vcontrol = 7.06V, the frequency of the oscillation reduces to 248 Hz - see the [actual calculation on WolframAlpha](http://www.wolframalpha.com/input/?i=f+%3D+1%2F%28+100*10^-9+*+%282200+%2B+22000%29ln%281+%2B+7.06%2F%282+*+%289+-+7.06%29%29%29+%2B+100*10^-9+*+22000+*+ln%282%29+%29).

The derivation of the fomula considering a control voltage is explained in a
[question on EE.SE](http://electronics.stackexchange.com/questions/101530/what-is-the-equation-for-the-555-timer-control-voltage).
The formula with variables as named in this circuit is:

    f = 1/( C2.(R2+VR2)ln(1 + Vcontrol/(2(Vcc - Vcontrol))) + C2.VR2.ln(2) )


### Construction

![The Breadboard](./assets/SimpleSiren_bb.jpg?raw=true)

![The Schematic](./assets/SimpleSiren_schematic.jpg?raw=true)

![Breadboard Build](./assets/SimpleSiren_build.jpg?raw=true)

## Credits and references
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [What is the equation for the 555 timer control voltage?](http://electronics.stackexchange.com/questions/101530/what-is-the-equation-for-the-555-timer-control-voltage) - Q&A on EE.SE
* [Ding Dong Bell Sound Generator](http://www.electronicshub.org/ding-dong-sound-generator-circuit/) - original circuit from electronicshub

