# #222 StairStepGenerator

Generate a stair-step waveform with analog components.


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

Once again I'm inspired to go and build a circuit by  [yet another great tutorial from w2aew](https://youtu.be/Kqb5zcrgv7s?list=PL4ZSD4omd_Aw-ozOphzFCkhWMtBdyEIrP).

I won't try and repeat the circuit description here - see the video and attached notes.
Suffice to say, it is quite an ingenious combination of 3 sub-systems:

* a "high" (265Hz) frequency pulse (555 timer) provides the charge to step-up the output
* the step pulse feeds an OpAmp pulse integrator/accumulator
* a low frequency pulse generator (OpAmp oscillator) provides the reset pulse that clears the accumulator and resets the 555

I'm using an LMV324 opamp, which gives decent rail-to-rail performance. It has a maximum supply specification of 6V,
hence I'm running the circuit at 5V only.

### Performance

This is a trace of the circuit on a breadboard (a little noisy). But it works!

In this trace:
* CH1: 555 timer signal
* CH2: reset pulse
* CH3: output

![scope](./assets/scope.gif?raw=true)

## Construction

![Breadboard](./assets/StairStepGenerator_bb.jpg?raw=true)

![The Schematic](./assets/StairStepGenerator_schematic.jpg?raw=true)

![The Build](./assets/StairStepGenerator_build.jpg?raw=true)

## Credits and References
* [#231: Circuit Fun: Stairstep generator using 555 and op amps](https://youtu.be/Kqb5zcrgv7s?list=PL4ZSD4omd_Aw-ozOphzFCkhWMtBdyEIrP) - inspiration for this circuit
* [annotated circuit](http://www.qsl.net/w2aew//youtube/231-KL0S_Notes.pdf) - by KL0S
* [LM555 Datasheet](http://www.futurlec.com/Linear/LM555CN.shtml)
* [LMV324 Datasheet](https://www.fairchildsemi.com/datasheets/LM/LMV324.pdf)
