# #262 GuitarEffects/BazzFuss

The Bazz Fuss "chocolate noisette" - a super-minimalist overdrive/distortion/fuzz effect circuit.

![BazzFuss_complete](./assets/BazzFuss_complete.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I saw [DIY Guitar Pedals](https://www.youtube.com/watch?v=Rv5iQ_aenX8) build and demo the **Bazz Fuss** on youtube
and had to try myself .. just to see how good it really is for about the simplest effect circuit I've ever seen.

Although not the true origin, the main source of information about the Bazz Fuss
circuit appears to be at [home-wrecker.com](http://home-wrecker.com/bazz.html).

I tried the first, most basic, circuit (v1) on a breadboard and was pretty impressed by the sound.

I'm using an S9013 (chosen because I know it is a little dirty), and I ended up placing two in a Darlington configuration,
though it only contributes a little to the waveform.

Here's a comparison of a single S9013 and an S9013 pair.

* CH1 (yellow) - 1kHz 2Vp-p sinusoid
* CH2 (blue) - output, with output pot full on

First a single S9013:

![scope_single_S9013](./assets/scope_single_S9013.gif?raw=true)

And then with an S9013 Darlington pair. Only a minor difference, but you can
see that it retains more of the original peak shape when clipping.
I think this adds a little more warmth to the sound.

![scope_S9013_pair](./assets/scope_S9013_pair.gif?raw=true)

### Performance

Lovely warm distortion (chocolatey?). It does pick up quite a bit of RF noise
(the wiring and non-shielded box I used in the final build don't help).

Here's what it does to a 1kHz 2Vp-p signal in the final build:

![scope_full_range](./assets/scope_full_range.gif?raw=true)

## Construction

![Breadboard](./assets/BazzFuss_bb.jpg?raw=true)

![Schematic](./assets/BazzFuss_schematic.jpg?raw=true)

Testing on a breadboard:

![BazzFuss_breadboard](./assets/BazzFuss_breadboard.jpg?raw=true)

Protoboard layout:

![BazzFuss_protoboard_layout](./assets/BazzFuss_protoboard_layout.jpg?raw=true)

Construction complete ... the internals:

![BazzFuss_internals](./assets/BazzFuss_internals.jpg?raw=true)

![Build](./assets/BazzFuss_build.jpg?raw=true)

## Credits and References
* [Bazz Fuss](http://home-wrecker.com/bazz.html) - main home at home-wrecker.com
* [Build a Guitar Pedal in 10 mins! (Fuzz)](https://www.youtube.com/watch?v=Rv5iQ_aenX8) - DIY Guitar Pedals
* [S9013 datasheet](https://www.futurlec.com/Transistors/S9013.shtml)
* [1N4148 Datasheet](https://www.futurlec.com/Diodes/1N4148.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/03/leap262-bazz-fuzz-chocolate-noisette.html)
