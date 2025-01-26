# #118 RotaryEncoderMethods

Finding the best method for reading a rotary-encoder.

![The Build](./assets/RotaryEncoderMethods_build.jpg?raw=true)

## Notes

I'm testing some mini rotary encoders I got from a
[seller on aliexpress](https://www.aliexpress.com/item/10-pcs-Handle-Length-15MM-EC12-E12-Audio-Encoder-360-Degree-Rotary-Encoder-Tripod/32308666522.html).

[Incremental rotary encoders](https://en.wikipedia.org/wiki/Rotary_encoder#Incremental_rotary_encoder)
generate step pulses trains that are 90˚ out of phase. Their relative sequencing therefore indicates rotation and direction:

![Quadrature_Diagram CW](https://upload.wikimedia.org/wikipedia/commons/6/68/Quadrature_Diagram.svg)

It should be possible to hook a rotary encoder directly to an Arduino and sample the pin A/B signals.
The [RotaryEncoders](http://playground.arduino.cc/Main/RotaryEncoders)
page in the Arduino playground provides some good background and many examples
but they all pretty much use the same method - read the two pins and do a direct test to see if moving forwards or reverse.
These are similar to the techniques described in the Arduino Cookbook
[6.10. Tracking the Movement of a Dial](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU).

My first attempts were pretty unsatisfactory.
At both high and low rotation speeds, I'd routinely see all the possible problems: missed steps, "extra" steps, and unexpected reversals.
Basically, the experience is that if the encoder is rotated right by say 30˚ and then left by the same amount, then there's a very high chance
that an encoder counter will *not* retrun to the same value.
Either my rotary encoders are not very reliable, or the programming techniques are doing a poor job of reliably capturing the input.

It doesn't take [much research](https://hifiduino.wordpress.com/2010/10/20/rotaryencoder-hw-sw-no-debounce/) to discover this is a common experience.
Perhaps if I had expensive, high-precision encoders then things would "just work", but the typical rotary encoders used for manual
input do seem notoriously noisy.

So my experiement here has turned into a test of the various techniques, in search of the most suitable for general use.
Read on for more details, but here's the summary so far:

| Technique | Accuracy                                                                                                        |
|-----------|-----------------------------------------------------------------------------------------------------------------|
| [RotaryISR](./RotaryISR/RotaryISR.ino) - change-triggered interrupt using the Rotary library | Perfect. 100% accuracy at all speeds       |
| [RotaryPolling](./RotaryPolling/RotaryPolling.ino) - poll with the Rotary library | Perfect. 100% accuracy at all speeds                      |
| [Polling](./Polling/Polling.ino) - simple polling with hardware debounce | Pretty good. the occasional extra event in the wrong direction |
| [OnChangeISR](./OnChangeISR/OnChangeISR.ino) - change-triggered interrupt and standard digitalRead methods | OK, direction usually correct but lots of 'bounce' |
| [Polling](./Polling/Polling.ino) - simple polling and standard digitalRead methods | Poor, direction bounces around quite a bit |
| [OnChangeDirectPortAccessISR](./OnChangeDirectPortAccessISR/OnChangeDirectPortAccessISR.ino) - change-triggered interrupt and direct port methods | Poor, strong left-bias |
| [FallingEdgeISR](./FallingEdgeISR/FallingEdgeISR.ino) - falling-edge triggered interrupt and standard digitalRead methods | Very poor, highly susceptible to bounce |
| [FallingEdgeDirectPortAccessISR](./FallingEdgeDirectPortAccessISR/FallingEdgeDirectPortAccessISR.ino) - falling-edge triggered interrupt and direct port methods | Extremely poor, highly susceptible to bounce |

It is pretty clear that the Rotary library is the best option by far, and delivers stunningly good results.
All other options are susceptible to bouncing inputs to varying degrees.
The secret to the Rotary library is that it models the state machine of the grey code produced by the rotary encoder,
and only responds to valid state transitions. This effectively eliminates all the noise.
See Ben Buxton's [blog post on the rotary library](http://www.buxtronix.net/2011/10/rotary-encoders-done-properly.html)
for more detail of how and why this works so well.

See the [RotaryEncoderModule](../RotaryEncoderModule) for an example of using the Rotary library
with a rotary encoder module driving an 8x8 LED array.

## Encoding Considerations

Here's a quick summary of the main considerations when interfacing with a rotary encoder

### Full-step, Half-step or Quarter-step?

![Quadrature_Diagram CW](https://upload.wikimedia.org/wikipedia/commons/6/68/Quadrature_Diagram.svg)

From the timing/phase diagram it's clear there are 4 distinct transitions per "cycle":

| Position | A | B |
|----------|---|---|
| Step1    | 0 | 0 |
|  1/4     | 1 | 0 |
|  1/2     | 1 | 1 |
|  3/4     | 0 | 1 |
| Step2    | 0 | 0 |
| ...      |   |   |

Different techniques lead to differing levels of resolution, for example:

* the Rotary library looks for a full cycle by default i.e. only one even per step
* a rising or falling edge interrupt will only catch one event per cycle per pin
* a change interrupt on both pins will catch all 4 transitions per step

Capturing more transitions is not much use if bounce is not effectively dealt with.

### Polling or Interrupt Handler

While it is possible to read a rotary encoder with a polling approach, it is liable to become increasingly inaccurate as the program gets more complex.

Rotary encoders are prime example of where using an interrupt routine yields the best results.
Most examples where attach a hardware interrupt to either or both of the encoder pins.
If this is not possible, an alternative would be to use a timer interrupt to
poll the encoder on a frequent and reliable basis.

Note that hardware interrupts can at first make the bounce problem worse, as they will trigger on all the bouncing transitions -
transitions that might have been missed with a polling approach for example.

### Hardware or Software Debouncing

The general experience is that debouncing is critical when using mini-rotary encoders.

#### Hardware Debouncing

Many people have experiemented with hardware debouncing.
Adding hardware debouncing (see the alternative schematics below) does yield some improvement.
For example a 10kΩ/100nF RC filter on the [Polling](./Polling) sketch eliminates most of the noise. But not all -
it still triggers the occasional "wrong" signal.

#### Software Debouncing

Software debouncing generally uses time-based techniques to discard "probably wrong" readings.
For example
[this example on the Arduno playgound](http://playground.arduino.cc/Main/RotaryEncoders#Example16)
sets a minimum time between accepting valid signals.
Others have used the [Bounce/Bounce2](https://github.com/thomasfredericks/Bounce2) library for the same purpose.
I haven't included a software debounce example here yet, mainly because just like hardware debouncing, they don't totally solve the problem
and just add size and complexity to the code.

#### "State Machine" Debouncing

This is the approach used by the Rotary library.
It basically means building in the knowledge of the valid state transitions that apply for a rotary encoder, and only accepting
input that follows a valid sequence. This effectively eliminates all the noise and bouncing.
See Ben Buxton's [blog post on the rotary library](http://www.buxtronix.net/2011/10/rotary-encoders-done-properly.html)
for more detail of how and why this works so well.

### Standard or Direct Port Access

The standard library methods for working with GPIO pins - e.g. `digitalRead` - are notoriously slow.
And if we use these methods to read the two rotary encoder pins, we can't escape the fact that the two pins are never read simultaneously.

[Direct port access](https://www.arduino.cc/en/Reference/PortManipulation) adds complexity and some portability concerns to the code,
but does both speed up port access, and also allow us to read two pins simultaneously. This is similar the the approach described
[by Oleg Mazurov in this article](https://www.circuitsathome.com/mcu/rotary-encoder-interrupt-service-routine-for-avr-micros).

However, as my experiements show here, that in itself does not make for a better rotary encoder reader.
In fact it makes things worse, because the program just gets better and better at detecting the noise on the input.

## Construction

### Basic Direct-Connect

![Breadboard](./assets/RotaryEncoderMethods_bb.jpg?raw=true)

![The Schematic](./assets/RotaryEncoderMethods_schematic.jpg?raw=true)

### With Hardware Debouncing

![Breadboard](./assets/RotaryEncoderMethods_hw_debounce_bb.jpg?raw=true)

![The Schematic](./assets/RotaryEncoderMethods_hw_debounce_schematic.jpg?raw=true)

## Credits and References

* [RotaryEncoders](http://playground.arduino.cc/Main/RotaryEncoders) - Arduino playground
* [Rotary_encoder](https://en.wikipedia.org/wiki/Rotary_encoder) - wikipedia page
* [Rotary library](https://github.com/brianlow/Rotary)
* [Arduino Port Registers](https://www.arduino.cc/en/Reference/PortManipulation) - all the info needed for direct port manipulation
* [6.10. Tracking the Movement of a Dial](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU) - from the Arduino Cookbook
* [6.12. Tracking the Movement of a Dial in a Busy Sketch](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU) - from the Arduino Cookbook
* [Rotary Encoder: H/W, S/W or No Debounce?](https://hifiduino.wordpress.com/2010/10/20/rotaryencoder-hw-sw-no-debounce/) - good discussion and investigation of different debouncing schemes
* [Reading rotary encoder on Arduino](https://www.circuitsathome.com/mcu/programming/reading-rotary-encoder-on-arduino) by Oleg Mazurov
* [Rotary encoder interrupt service routine for AVR micros](https://www.circuitsathome.com/mcu/rotary-encoder-interrupt-service-routine-for-avr-micros) updated article by Oleg Mazurov
* [Five things I never use in Arduino projects](https://miscsolutions.wordpress.com/2011/10/16/five-things-i-never-use-in-arduino-projects/) - including #5 External debouncing hardware for rotary encoders
* [Arduino: Using a rotary encoder](http://practicalusage.com/?p=267)
* [RotaryEncoderModule](../RotaryEncoderModule) - a project that tests a rotary encoder module driving an 8x8 LED array
