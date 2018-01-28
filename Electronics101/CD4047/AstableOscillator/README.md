# #206 CD4047/AstableOscillator

Test the astable operating mode of the CD4047


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

The CD4047 is capable of running in astable or monostable configurations,
with operating frequency configured by an external RC network.
So in one sense, sounds like the 555 timer!

Unlike the 555, the CD4047 provides a fixed 50% duty cycle with good frequency stability (+/- 2% @ 100KHz).


### Astable Oscillation Frequency

This is a test of the astable operating mode. The frequency of oscillation is (roughly)

    f = 1/(4.4RC)

Here are some measurements from the breadboarded circuit:

| C             |     R | Measured f | Theoretical f |
|---------------|-------|------------|---------------|
| 1nF ceramic   | 220kΩ |    936.3Hz | [1033Hz](http://www.wolframalpha.com/input/?i=1%2F%284.4+*+220k%CE%A9+*+1nF%29) |
| 1nF mylar     | 220kΩ |    996.2Hz | [1033Hz](http://www.wolframalpha.com/input/?i=1%2F%284.4+*+220k%CE%A9+*+1nF%29) |
| 10nF ceramic  | 220kΩ |    147.9Hz | [103.3Hz](http://www.wolframalpha.com/input/?i=1%2F%284.4+*+220k%CE%A9+*+10nF%29) |
| 10nF mylar    | 220kΩ |    102.1Hz | [103.3Hz](http://www.wolframalpha.com/input/?i=1%2F%284.4+*+220k%CE%A9+*+10nF%29) |
| 68nF mylar    | 220kΩ |    15.11Hz | [15.19kHz](http://www.wolframalpha.com/input/?i=1%2F%284.4+*+220k%CE%A9+*+68nF%29) |
| 100nF ceramic | 220kΩ |    15.38Hz | [10.33Hz](http://www.wolframalpha.com/input/?i=1%2F%284.4+*+220k%CE%A9+*+100nF%29) |


### Astable Gating

The astable oscillation can be gated with pins 4 and 5:

| pin 4 -ASTABLE | pin 5 ASTABLE  | Oscillator    |
|----------------|----------------|---------------|
| HIGH           | HIGH           | Running       |
| HIGH           | LOW            | LOW & stopped |
| LOW            | HIGH           | Running       |
| LOW            | LOW            | Running       |

So it is possible to gate the oscillator using two complementary schemes:

* Hold pin 4 `HIGH`, and pin 5 is the gate function (`HIGH=ON`, `LOW=OFF`)
* Hold pin 5 `LOW`, and pin 4 is the gate function (`HIGH=OFF`, `LOW=ON`)


### Waveforms

Here's how the oscillator appears on the scope with C=1nF mylar and R=220kΩ

* CH1 - Q output
* CH2 - OSC OUT oscillator output (2*f, but duty cycle not guaranteed)

![scope_1nF_220k](./assets/scope_1nF_220k.gif?raw=true)

Close-up of the rising edge:

![scope_1nF_220k_rising_edge](./assets/scope_1nF_220k_rising_edge.gif?raw=true)

## Construction

![Breadboard](./assets/AstableOscillator_bb.jpg?raw=true)

![The Schematic](./assets/AstableOscillator_schematic.jpg?raw=true)

![The Build](./assets/AstableOscillator_build.jpg?raw=true)

## Credits and References
* [CD4047 datasheet](http://www.futurlec.com/4000Series/CD4047.shtml)
* [Review – CD4047 Astable/Monostable Multivibrator](http://tronixstuff.com/2011/02/11/review-cd4047-astablemonostable-multivibrator/)
* [..as mentioned on my blog](https://blog.tardate.com/2016/06/littlearduinoprojects206-cd4047-astable.html)
