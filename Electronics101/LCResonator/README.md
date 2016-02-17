# #195 LCResonator

Measure the resonant frequency of an LC circuit or inductance of an inductor

## Notes

Again I'm inspired by one of [w2aew's videos](https://www.youtube.com/watch?v=Ff5xOENID7w).

This circuit is used to measure the resonant frequency of an LC circuit. It works in two ways:
* by attaching an LC circuit without the calibration capacitor
* by inserting a known-value calibration capacitor, the inductance of the inductor can be derived (calculated)

```
L = 1 / ( C * (2πf)^2 )
```


### JFET Selection

The [original circuit](http://archive.org/stream/73-magazine-1990-09/09_September_1990#page/n49/mode/1up) used a 2N5245 N-JFET,
w2aew used a J310. I ended up comparing J201 and J310.

| JFET   | R2   | Idss    | Vgs(off)       |
|--------|------|---------|----------------|
| 2N5245 | 470Ω | 5-15mA  | -1V to -6V     |
| J310   | 1kΩ  | 24-60mA | -2V to -6.5V   |
| J201   |      | 0.2-1mA | -0.3V to -1.5V |


### Breadboard Test Results

Here are some measurements. Where "n/a" it means I was not able to provoke an oscillation.

| JFET | R2    | C1    | C2   | f        | L(nom) | L(calc) |
|------|-------|-------|------|----------|--------|-----------|
| J310 | 4.7kΩ | 150pF | 33pF | 438kHz   | 1mH    | [0.88mH](http://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80*+438kHz%29^2+%29) |
| J310 | 2.2kΩ |  50pF | 33pF | 660kHz   | 1mH    | [1.16mH](http://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*+660kHz%29^2+%29) |
| J310 | 4.7kΩ | 150pF | 33pF | 1.307MHz | 100µH  | [99µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80*+1.307MHz%29^2+%29) |
| J310 | 2.2kΩ | 150pF | 33pF | 1.311MHz | 100µH  | [98µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80*+1.311MHz%29^2+%29) |
| J310 | 2.2kΩ |  50pF | 33pF | 1.988MHz | 100µH  | [128µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*+1.988MHz%29^2+%29) |
| J201 | 2.2kΩ |  50pF | 33pF | 2.088MHz | 100µH  | [116µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*+2.088MHz%29^2+%29) |
| J201 | 4.7kΩ |  33pF | 15pF | 2.43MHz  | 100µH  | [130µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+33pF+*+%282%CF%80*+2.43MHz%29^2+%29) |
| J201 | 4.7kΩ |  50pF | 15pF | 2.08MHz  | 100µH  | [117µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*+2.08MHz%29^2+%29) |
| J201 | 2.2kΩ | 150pF | 33pF | 1.33MHz  | 100µH  | [95µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+150pF+*+%282%CF%80*+1.33MHz%29^2+%29) |
| J201 | 4.7kΩ | 470pF | 15pF | n/a      | 100µH  | n/a |
| J201 | 2.2kΩ | 470pF | 33pF | n/a      | 100µH  | n/a |
| J201 | 2.2kΩ |  33pF | 33pF | 8.196MHz | 10µH   | [11.4µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+33pF+*+%282%CF%80*+8.196MHz%29^2+%29) |
| J310 |   1kΩ |  50pF | 33pF | 6.729MHz | 10µH   | [11.2µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+50pF+*+%282%CF%80*6.729MHz%29^2+%29) |
| J310 | 2.2kΩ |  33pF | 33pF | 7.82MHz  | 10µH   | [12.5µH](http://www.wolframalpha.com/input/?i=1+%2F+%28+33pF+*+%282%CF%80*+7.82MHz%29^2+%29) |
| J310 | 2.2kΩ |  50pF | 33pF | n/a      | 10µH   | n/a |
| J310 |   1kΩ | 150pF | 33pF | n/a      | 10µH   | n/a |
| J201 | 2.2kΩ | 150pF | 33pF | n/a      | 10µH   | n/a |
| J201 | 2.2kΩ |  50pF | 33pF | n/a      | 10µH   | n/a |
| J310 | 2.2kΩ |  50pF | 33pF | n/a      | 1µH    | n/a |
| J310 | 2.2kΩ |  33pF | 33pF | n/a      | 1µH    | n/a |
| J310 | 4.7kΩ |  33pF | 33pF | n/a      | 1µH    | n/a |
| J201 | 2.2kΩ |  33pF | 15pF | n/a      | 1µH    | n/a |

### Findings

As long as the oscillation can be sustained, measured results and inferred inductance is surprisingly close to theory.
I've only done these tests on a breadboard; I'll have to try on a protoboard or PCB to see if it helps sustain oscillation
and in particular measure inductors below 10µH.

In summary, with a breadboard build and 9V supply:

* 10µH is minimum inductance I could measure
* more accurate results with C1=50pF or higher
* if C1 too high (over 150pF), can't sustain oscillation
* R2 sweet spot is around 2.2kΩ


Sample trace measuring a 100µH choke with J201, R2=2.2kΩ, and C1=50pF:

![J201/100µH/2.2kΩ/50pF](./assets/scope_J201L100uR22C50.gif?raw=true)

Sample trace measuring a 10µH choke with J201, R2=2.2kΩ, and C1=33pF:

![J201/10µH/2.2kΩ/33pF](./assets/scope_J201L10uR22C33.gif?raw=true)

## Construction

![Breadboard](./assets/LCResonator_bb.jpg?raw=true)

![The Schematic](./assets/LCResonator_schematic.jpg?raw=true)

![The Build](./assets/LCResonator_build.jpg?raw=true)

## Credits and References
* [Measuring coil inductance and IF transformer resonant frequency](https://www.youtube.com/watch?v=Ff5xOENID7w) - w2aew
* [The Coil Tester](http://archive.org/stream/73-magazine-1990-09/09_September_1990#page/n49/mode/1up) - article from 73 Amateur Radio - September 1990
* [L/C/F and Single-Layer Coil Winding Calculator](http://www.arrl.org/shop/L-C-F-and-Single-Layer-Coil-Winding-Calculator/) - ARRL Store
* [2N5245 datasheet](http://www.farnell.com/datasheets/46878.pdf)
* [J310 datasheet](http://www.futurlec.com/Transistors/J310.shtml)
* [J201 datasheet](http://www.futurlec.com/Transistors/J201.shtml)
* [JFET](https://en.wikipedia.org/wiki/JFET) - wikipedia
