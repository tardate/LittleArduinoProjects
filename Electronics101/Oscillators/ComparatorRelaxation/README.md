# #336 Comparator-based Relaxation Oscillator

Test a classic comparator-based relaxation oscillator, modified for single-supply LM358 OpAmp.

![Build](./assets/ComparatorRelaxation_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The comparator-based relaxation oscillator is similar to the astable opamp oscillator -
[see LEAP#039](../AstableOpamp) - but is a more straight-forward and symmetrical circuit, one that is easy to intuit.

[![OpAmpHystereticOscillator](https://upload.wikimedia.org/wikipedia/commons/1/15/OpAmpHystereticOscillator.svg)](https://en.wikipedia.org/wiki/Relaxation_oscillator#/media/File:OpAmpHystereticOscillator.svg)

Rather than use dual (+/-) supply, I'm using a voltage divider and buffer to provide a half-supply reference.

The theoretical frequency `f = 1/(2ln(3)RC)`

I tried a few combinations, and performance was remarkably close to the theory:

| R     | C     | f (actual) | f (theoretical)                                                                       |
|-------|-------|------------|---------------------------------------------------------------------------------------|
| 100kΩ | 10µF  | 437mHz     | [455mHz](https://www.wolframalpha.com/input/?i=1%2F(2+ln(3)+*+100k%CE%A9+*+10%C2%B5F)) |
| 100kΩ | 100nF | 44.8Hz     | [45.51Hz](https://www.wolframalpha.com/input/?i=1%2F(2+ln(3)+*+100k%CE%A9+*+100nF))    |


Here's the 100kΩ/100nF combo on the scope. Channels connected per the schematic,
clearly showing the hysteresis of the capacitor charging curve as it battles the positive feedback.

![scope_100k_100n](./assets/scope_100k_100n.gif?raw=true)

## Construction

![Breadboard](./assets/ComparatorRelaxation_bb.jpg?raw=true)

![Schematic](./assets/ComparatorRelaxation_schematic.jpg?raw=true)

![Build](./assets/ComparatorRelaxation_build.jpg?raw=true)

## Credits and References
* [Comparator–based relaxation oscillator](https://en.wikipedia.org/wiki/Relaxation_oscillator#Comparator.E2.80.93based_relaxation_oscillator) - wikipedia
* [LEAP#039 AstableOpamp](../AstableOpamp) - astable opamp oscillator
* [LM358N Datasheet](https://www.futurlec.com/Linear/LM358N.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/08/leap336-comparator-based-relaxation-oscillator.html)
