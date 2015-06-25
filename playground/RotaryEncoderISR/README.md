# RotaryEncoderISR

Demo interrupt-driven rotary-encoder input

## Notes

I'm testing some mini rotary encoders I got from a
[seller on aliexpress](http://www.aliexpress.com/item/10-pcs-Handle-Length-15MM-EC12-E12-Audio-Encoder-360-Degree-Rotary-Encoder-Tripod/32308666522.html).

[Incremental rotary encoders](https://en.wikipedia.org/wiki/Rotary_encoder#Incremental_rotary_encoder)
generate step pulses trains that are 90˚ out of phase. Their relative sequencing therefore indicates rotation and direction:

![Quadrature_Diagram CW](https://upload.wikimedia.org/wikipedia/en/6/68/Quadrature_Diagram.svg)

It should be possible to hook a rotary encoder directly to an Arduino and sample the pin A/B signals.
To avoid missing transitions, the encoder input can be triggered on one of the signal edges.
That's the approach used here: triggering input on the falling edge of pin A.

My first attempts were unsatisfactory. Either my rotary encoders are not very reliable, or the sketch is doing a poor job of
capturing every input and reading it reliably.

Adding hardware debouncing (see the alternative schematics) below did not improve the situation.

So far my conclusion is that this approach (or perhaps with these specific rotary encoders), the input is too unreliable for accurate positioning.

One possibility is that the inaccuracy due to the fact that the sketch never reads the two pins at exactly the same time and therefore could be subject to timing issues. I'll try some direct pin reading next to see if that helps, similar to that described
[by Oleg Mazurov in this article](https://www.circuitsathome.com/mcu/rotary-encoder-interrupt-service-routine-for-avr-micros)

### A sample trace of encoder input
Not as smooth as I'd like...
```
position: 0, delta: 0
1
2
1
0
1
2
3
4
3
2
position: 2, delta: -1
3
4
3
2
3
4
5
6
7
8
9
10
11
10
9
position: 9, delta: -1
10
11
12
13
14
15
16
15
14
position: 14, delta: -1
```

## Construction

### With Hardware Debouncing

![The Build](./assets/RotaryEncoderInput_hw_debounce_build.jpg?raw=true)

![Breadboard](./assets/RotaryEncoderInput_hw_debounce_bb.jpg?raw=true)

![The Schematic](./assets/RotaryEncoderInput_hw_debounce_schematic.jpg?raw=true)

### Basic Direct-Connect

![Breadboard](./assets/RotaryEncoderInput_bb.jpg?raw=true)

![The Schematic](./assets/RotaryEncoderInput_schematic.jpg?raw=true)


## Credits and References
* [Rotary_encoder](https://en.wikipedia.org/wiki/Rotary_encoder) - wikipedia page
* [6.10. Tracking the Movement of a Dial](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU) - from the Arduino Cookbook
* [6.12. Tracking the Movement of a Dial in a Busy Sketch](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU) - from the Arduino Cookbook
* [Rotary Encoder: H/W, S/W or No Debounce?](https://hifiduino.wordpress.com/2010/10/20/rotaryencoder-hw-sw-no-debounce/) - good discussion and investigation of different debouncing schemes
* [Reading rotary encoder on Arduino](https://www.circuitsathome.com/mcu/programming/reading-rotary-encoder-on-arduino) by Oleg Mazurov
* [Rotary encoder interrupt service routine for AVR micros](https://www.circuitsathome.com/mcu/rotary-encoder-interrupt-service-routine-for-avr-micros) updated article by Oleg Mazurov
