# #357 TheMonarch

The Monarch is the third in a series of beautiful electronic "bug" boards from the Boldport Club, Project #18 October 2017.

![Build](./assets/TheMonarch_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

### Parts

| Ref    | Item                                            | Qty   |
|--------|-------------------------------------------------|-------|
| IC1    | 555 IC timer, TI TLC555CP                       | 1x    |
| IC2    | Quad 2-input XOR, TI SN74HC86N                  | 1x    |
| IC3    | Octal D-type flip-flop, TI SN74HC273N           | 1x    |
| -      | IC DIP 8 contact socket, TruConnect DS1009-08   | 1x    |
| -      | IC DIP 14 contact socket, TruConnect DS1009-14  | 1x    |
| -      | IC DIP 20 contact socket, TruConnect DS1009-20  | 1x    |
| LED1-8 | 5mm clear lens red LEDs, TruOpto OSR5PA5C31C    | 8x    |
| SW1    | Switch, C&K JS202011SCQN                        | 1x    |
| -      | CR2032 batter clip, Multicomp BC-2001           | 1x    |
| C1,2   | 1µF capacitors, Suntan TS170R1H105MSBFA0R       | 2x    |
| R1,2,3 | 10KΩ resistors, Multicomp MCF 0.25W 10K         | 3x    |
| R4-22  | 560Ω resistors, Multicomp MCF 0.25W 560         | 18x   |
| -      | 20AWG wire                                      | 16cm  |

![monarch_parts](./assets/TheMonarch_parts.jpg?raw=true)

### Circuit

![Breadboard](./assets/TheMonarch_bb.jpg?raw=true)

![Schematic](./assets/TheMonarch_schematic.jpg?raw=true)


### My Take on "How it Works"

The core components:

* a 555 astable timer that is enabled when the "feelers" are touched together, running at around [48 Hz](http://visual555.tardate.com/?mode=astable&r1=10&r2=10&c=1)
* 74HC273 D flip-flop, that latches the input (D) to the output (Q) on the rising edge of the clock input
* a 74HC86 quad 2-input XOR

Considering an initial condition of all registers (Q) high:

* XOR Y2 = 1 xor 1 = 0
* XOR Y1 = 1 xor 0 = 1
* XOR Y4 = 1 xor 1 = 0

So on the next 3 clock cycles:

* input D1=0 cascades to Q1,2,3

On the 4th clock cycle, Q4 goes low, XOR Y4 becomes 1, ... and so on.

I wrote a little script to simulate this.

```
$ ./lfsr.py
```

Which outputs (for the first 32 steps)..

|  CLK |  Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 | Q8 |
|------|-----|----|----|----|----|----|----|----|
|    0 |   1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |
|    1 |   0 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |
|    2 |   0 |  0 |  1 |  1 |  1 |  1 |  1 |  1 |
|    3 |   0 |  0 |  0 |  1 |  1 |  1 |  1 |  1 |
|    4 |   0 |  0 |  0 |  0 |  1 |  1 |  1 |  1 |
|    5 |   1 |  0 |  0 |  0 |  0 |  1 |  1 |  1 |
|    6 |   0 |  1 |  0 |  0 |  0 |  0 |  1 |  1 |
|    7 |   1 |  0 |  1 |  0 |  0 |  0 |  0 |  1 |
|    8 |   1 |  1 |  0 |  1 |  0 |  0 |  0 |  0 |
|    9 |   1 |  1 |  1 |  0 |  1 |  0 |  0 |  0 |
|   10 |   1 |  1 |  1 |  1 |  0 |  1 |  0 |  0 |
|   11 |   0 |  1 |  1 |  1 |  1 |  0 |  1 |  0 |
|   12 |   0 |  0 |  1 |  1 |  1 |  1 |  0 |  1 |
|   13 |   0 |  0 |  0 |  1 |  1 |  1 |  1 |  0 |
|   14 |   1 |  0 |  0 |  0 |  1 |  1 |  1 |  1 |
|   15 |   1 |  1 |  0 |  0 |  0 |  1 |  1 |  1 |
|   16 |   0 |  1 |  1 |  0 |  0 |  0 |  1 |  1 |
|   17 |   1 |  0 |  1 |  1 |  0 |  0 |  0 |  1 |
|   18 |   0 |  1 |  0 |  1 |  1 |  0 |  0 |  0 |
|   19 |   0 |  0 |  1 |  0 |  1 |  1 |  0 |  0 |
|   20 |   0 |  0 |  0 |  1 |  0 |  1 |  1 |  0 |
|   21 |   0 |  0 |  0 |  0 |  1 |  0 |  1 |  1 |
|   22 |   0 |  0 |  0 |  0 |  0 |  1 |  0 |  1 |
|   23 |   0 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |
|   24 |   0 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |
|   25 |   1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |
|   26 |   0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |
|   27 |   0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |
|   28 |   0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |
|   29 |   1 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |
|   30 |   1 |  1 |  0 |  0 |  0 |  1 |  0 |  0 |
|   31 |   1 |  1 |  1 |  0 |  0 |  0 |  1 |  0 |


The repeating pattern is obvious. This is actually an instance of a
[linear-feedback shift register (LFSR)](https://en.wikipedia.org/wiki/Linear-feedback_shift_register).
Since The Monarch has XOR taps at registers 8, 6, 5, 4, the feedback function can be expressed as `x^8 + x^6 + x^5 + x^4 + 1`

With that function, it should repeat every 255 cycles. Which it does..

```
$ ./lfsr.py -1
```

|  CLK |  Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 | Q8 |
|------|-----|----|----|----|----|----|----|----|
|    0 |   1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |
|    1 |   0 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |
|    2 |   0 |  0 |  1 |  1 |  1 |  1 |  1 |  1 |
|  ... |     |    |    |    |    |    |    |    |
|  254 |   1 |  1 |  1 |  1 |  1 |  1 |  1 |  0 |
|  255 |   1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |



Recently Julian Ilett delved deep into LFSRs in his inimitable style with "The 10,000 Year Shift Register":

[![clip](http://img.youtube.com/vi/juoM7VhXQDM/0.jpg)](http://www.youtube.com/watch?v=juoM7VhXQDM)


### Construction

![monarch_build_front](./assets/TheMonarch_build_front.jpg?raw=true)

![monarch_build_rear](./assets/TheMonarch_build_rear.jpg?raw=true)

![Build](./assets/TheMonarch_build.jpg?raw=true)

Here is a quick video of the LED sequencing in action:

[![test drive](http://img.youtube.com/vi/tzV3l_iAMh8/0.jpg)](http://www.youtube.com/watch?v=tzV3l_iAMh8)


### All Bugs Together

The Monarch joins [The Lady](../TheLady) and [The Gent](../TheGent) in the Boldport Bug series.
They are all beautiful boards, so I think mounted together would be nice.

I had an Ikea RIBBA picture frame, discarded the front glass and mounted reflective film at the rear.
The bugs are all wired into a 2xAA battery pack with switch on the rear.

Here's a video of the frame:

[![all bugs](http://img.youtube.com/vi/JVAooJmsS20/0.jpg)](http://www.youtube.com/watch?v=JVAooJmsS20)

![bug_case_1](./assets/bug_case_1.jpg?raw=true)
![bug_case_2](./assets/bug_case_2.jpg?raw=true)
![bug_case_3](./assets/bug_case_3.jpg?raw=true)
![bug_case_rear](./assets/bug_case_rear.jpg?raw=true)

## Credits and References
* [Monarch](https://www.boldport.com/products/the-monarch) - Boldport product information
* [Monarch](http://www.boldport.club/shop/product/1033698228) - in the Boldport shop
* [Monarch](https://github.com/boldport/monarch) - OSH files on GitHub
* [Monarch](http://community.boldport.club/projects/p18-themonarch/) - club community site, packed with resources for the project
* [74HC273 datasheet](http://www.futurlec.com/74HC/74HC273.shtml)
* [LM555 datasheet](http://www.futurlec.com/Linear/LM555CM.shtml)
* [74HC86 datasheet](http://www.futurlec.com/74HC/74HC86.shtml)
* [Ikea RIBBA Frame](http://www.ikea.com/sg/en/catalog/products/80378437/)
* [LFSR](https://en.wikipedia.org/wiki/Linear-feedback_shift_register) - wikipedia
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap357-the-monarch.html)
