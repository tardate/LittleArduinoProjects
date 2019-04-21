# #195 LCResonator

Measure the resonant frequency of an LC coil or inductance of an inductor

![LCResonator_build](./assets/LCResonator_build.jpg?raw=true)


## Notes

Again I'm inspired by one of [w2aew's videos](https://www.youtube.com/watch?v=Ff5xOENID7w).
I really needed something like this, as my attempts at winding my own inductors (for some RF projects)
have failed miserably, and it's a really usefull thing to be able to measure the inductance
of a custom coil (or unknown inductor), and/or resononant frequency of the resulting LC pair.

The circuit is used to measure the resonant frequency of an LC circuit. It works in two ways:
* by attaching an LC circuit without the calibration capacitor
* by inserting a known-value calibration capacitor, the inductance of the inductor can be derived (calculated)

If the capacitane is known, then the inductance may be calculated with a re-arrangement of the LC resonant frequency formula:

```
L = 1 / ( C * (2πf)^2 )
```

### JFET Selection

The [original circuit](http://archive.org/stream/73-magazine-1990-09/09_September_1990#page/n49/mode/1up) used a 2N5245 N-JFET with 470Ω R2,
w2aew used a J310 with 1kΩ R2. I ended up comparing J201 and J310 qith a range of R2 values.

| JFET   | Idss    | Vgs(off)       |
|--------|---------|----------------|
| 2N5245 | 5-15mA  | -1V to -6V     |
| J310   | 24-60mA | -2V to -6.5V   |
| J201   | 0.2-1mA | -0.3V to -1.5V |


### Breadboard Test Results

I did my first tests on a breadboard build:

![LCResonator_bb_build](./assets/LCResonator_bb_build.jpg?raw=true)

Here are some measurements. Where "n/a" it means I was not able to provoke an oscillation.

| JFET | R2    | C1    | C2   | f        | L(nom) | L(calc) |
|------|-------|-------|------|----------|--------|-----------|
| J310 | 4.7kΩ | 150pF | 33pF | 438kHz   | 1mH    | [0.88mH](https://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80*+438kHz%29^2+%29) |
| J310 | 2.2kΩ |  50pF | 33pF | 660kHz   | 1mH    | [1.16mH](https://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*+660kHz%29^2+%29) |
| J310 | 4.7kΩ | 150pF | 33pF | 1.307MHz | 100µH  | [99µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80*+1.307MHz%29^2+%29) |
| J310 | 2.2kΩ | 150pF | 33pF | 1.311MHz | 100µH  | [98µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80*+1.311MHz%29^2+%29) |
| J310 | 2.2kΩ |  50pF | 33pF | 1.988MHz | 100µH  | [128µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*+1.988MHz%29^2+%29) |
| J201 | 2.2kΩ |  50pF | 33pF | 2.088MHz | 100µH  | [116µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*+2.088MHz%29^2+%29) |
| J201 | 4.7kΩ |  33pF | 15pF | 2.43MHz  | 100µH  | [130µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+33pF+*+%282%CF%80*+2.43MHz%29^2+%29) |
| J201 | 4.7kΩ |  50pF | 15pF | 2.08MHz  | 100µH  | [117µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*+2.08MHz%29^2+%29) |
| J201 | 2.2kΩ | 150pF | 33pF | 1.33MHz  | 100µH  | [95µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80*+1.33MHz%29^2+%29) |
| J201 | 4.7kΩ | 470pF | 15pF | n/a      | 100µH  | n/a |
| J201 | 2.2kΩ | 470pF | 33pF | n/a      | 100µH  | n/a |
| J201 | 2.2kΩ |  33pF | 33pF | 8.196MHz | 10µH   | [11.4µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+33pF+*+%282%CF%80*+8.196MHz%29^2+%29) |
| J310 |   1kΩ |  50pF | 33pF | 6.729MHz | 10µH   | [11.2µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*6.729MHz%29^2+%29) |
| J310 | 2.2kΩ |  33pF | 33pF | 7.82MHz  | 10µH   | [12.5µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+33pF+*+%282%CF%80*+7.82MHz%29^2+%29) |
| J310 | 2.2kΩ |  50pF | 33pF | n/a      | 10µH   | n/a |
| J310 |   1kΩ | 150pF | 33pF | n/a      | 10µH   | n/a |
| J201 | 2.2kΩ | 150pF | 33pF | n/a      | 10µH   | n/a |
| J201 | 2.2kΩ |  50pF | 33pF | n/a      | 10µH   | n/a |
| J310 | 2.2kΩ |  50pF | 33pF | n/a      | 1µH    | n/a |
| J310 | 2.2kΩ |  33pF | 33pF | n/a      | 1µH    | n/a |
| J310 | 4.7kΩ |  33pF | 33pF | n/a      | 1µH    | n/a |
| J201 | 2.2kΩ |  33pF | 15pF | n/a      | 1µH    | n/a |

### Findings - Breadboard Tests

As long as the oscillation can be sustained, measured results and inferred inductance is surprisingly close to theory.

In summary, with a breadboard build and 9V supply:

* 10µH is minimum inductance I could measure
* more accurate results with C1=50pF or higher
* if C1 too high (over 150pF), can't sustain oscillation
* R2 sweet spot is around 2.2kΩ

I hoped that a protoboard or PCB build would helps sustain oscillation
and in particular measure inductors below 10µH. Which turns out to be true .. read on for the results - they are good!

Sample trace measuring a 100µH choke with J201, R2=2.2kΩ, and C1=50pF:

![J201/100µH/2.2kΩ/50pF](./assets/scope_J201L100uR22C50.gif?raw=true)

Sample trace measuring a 10µH choke with J201, R2=2.2kΩ, and C1=33pF:

![J201/10µH/2.2kΩ/33pF](./assets/scope_J201L10uR22C33.gif?raw=true)

### PCB Test Results

So next I've copied w2aew and put the circuit on a copper PCB (with 6 islands), and the improvement is staggering.
I'm able to measure much lower inductances without having to raise the power rail from 9V.
I made both L1 and C1 interchangeable (with pins on the board to add random capacitors, inductors, coils or LC modules)

A few minor component switches/selections:

* I put J310's down on the board, even though J201 seemed to perform in the same ballpark
* replaced "ordinary" ceramic disc capacitors with supposedly higher-quality multi-layer ceramics
* C2 33nF replaced with a 30nF multi-layer ceramic
* I settled on 2.2kΩ for R2 (FET source load)

Here are some measurements:

| C1    | f         | L(nom) | L(calc) |
|-------|-----------|--------|-----------|
|  50pF |  6.802MHz | 10µH   | [10.95µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80+*+6.802MHz%29^2+%29) |
| 150pF |  4.255MHz | 10µH   | [9.33µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80+*+4.255MHz%29^2+%29) |
| 150pF | 12.608MHz |  1µH   | [1.06µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80+*+12.608MHz%29^2+%29) |
|  30pF | 24.631MHz |  1µH   | [1.39µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+30pF+*+%282%CF%80+*+24.631MHz%29^2+%29) |
|  30pF | 34.094MHz | hand wound #1  | [0.73µH](https://www.wolframalpha.com/input/?i=1+%2F+%28+30pF+*+%282%CF%80+*+34.094MHz%29^2+%29) |

The hand wound #1 coil is simply an 8mm diameter coil, about 2mm long, with 4.5 turns of 0.2mm enamelled copper wire.
According to [this coil calculator](http://www.66pacific.com/calculators/coil_calc.aspx)
the inductance should be ablout 0.28µH. My measurement says 0.73µH,
and given the accuracy of the other readings with "known" inductors, I'm encouraged to go with my measured value.
No wonder my RF circuits are all off - it seems coil inductance calculators need to be treated with a big pinch of salt.


Here's a very nice trace measuring a 10µH choke and C1=150pF:

![10µH/150pF](./assets/scope_pcb10uh150pf.gif?raw=true)

And finally I can crack the 10µH barrier. Here's a measurement of a 1µH choke and C1=30pF:

![1µH/30pF](./assets/scope_pcb1uh30pf.gif?raw=true)

And a sub-1µH custom coil with C1=30pF:

![custom coil #1/30pF](./assets/scope_pcbL1h30pf.gif?raw=true)


## Construction

![Breadboard](./assets/LCResonator_bb.jpg?raw=true)

![The Schematic](./assets/LCResonator_schematic.jpg?raw=true)

Here's the build on a breadboard:

![LCResonator_bb_build](./assets/LCResonator_bb_build.jpg?raw=true)

And now on a chopped-up PCB:

![LCResonator_build](./assets/LCResonator_build.jpg?raw=true)

## Credits and References
* [LC circuit](https://en.wikipedia.org/wiki/LC_circuit) - wikipedia
* [Measuring coil inductance and IF transformer resonant frequency](https://www.youtube.com/watch?v=Ff5xOENID7w) - w2aew
* [The Coil Tester](http://archive.org/stream/73-magazine-1990-09/09_September_1990#page/n49/mode/1up) - article from 73 Amateur Radio - September 1990
* [L/C/F and Single-Layer Coil Winding Calculator](http://www.arrl.org/shop/L-C-F-and-Single-Layer-Coil-Winding-Calculator/) - ARRL Store
* [2N5245 datasheet](http://www.farnell.com/datasheets/46878.pdf)
* [J310 datasheet](https://www.futurlec.com/Transistors/J310.shtml)
* [J201 datasheet](https://www.futurlec.com/Transistors/J201.shtml)
* [JFET](https://en.wikipedia.org/wiki/JFET) - wikipedia
* [a coil calculator](http://www.66pacific.com/calculators/coil_calc.aspx)
* [..as mentioned on my blog](https://blog.tardate.com/2016/03/littlearduinoprojects195-coil-resonance.html)