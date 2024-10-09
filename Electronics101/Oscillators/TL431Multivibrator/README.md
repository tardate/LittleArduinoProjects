# #540 TL431 Multivibrator

An unusual multivibrator using a programmable reference with clean square wave output.

![Build](./assets/TL431Multivibrator_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/NoJr3C3UPhU/0.jpg)](https://www.youtube.com/watch?v=NoJr3C3UPhU)

## Notes

I found an unusual multivibrator design by Gilles Clément in [Elektor Magazine, issue 7/2009](https://www.elektormagazine.com/magazine/elektor-200907/19093/).
It is similar to BJT designs, but uses a TL431 precision voltage reference instead. And it oscillates - who'da thunk!

## Construction

Here's my version of the circuit, available in [EasyEDA](https://easyeda.com/tardate/tl431-multivibrator):

![Schematic](./assets/TL431Multivibrator_schematic.png?raw=true)

Testing on a breadboard first:

![TL431Multivibrator_bb_build](./assets/TL431Multivibrator_bb_build.jpg?raw=true)

Then transfered to freeform on a micro USB adapter for 5V power:

![TL431Multivibrator_wip](./assets/TL431Multivibrator_wip.jpg?raw=true)

Final build:

![Build](./assets/TL431Multivibrator_build.jpg?raw=true)

## Performance

With my selection of RC components, I'm getting a very nice 4Hz square wave driving the LEDs:

* CH1 (yellow):, left, offset -1V
* CH2 (blue):, right, offset -5V

![scope](./assets/scope.gif?raw=true)

## How does it work?

The Elektor article explains in full, but there's the essence as I understand it..

* cathode voltage Vk swings between supply voltage and a lower limit 2v
* internally, the TL431 essentially compares the reference voltage to an 2.5V reference
* RC crossed multivibrator
* capacitor can discharge via Vref to cathode when Vk is low

[![tl431_functional](./assets/tl431_functional.png?raw=true)](https://www.futurlec.com/Linear/TL431CLP.shtml)

## Credits and References

* [TL431 Multivibrator](https://www.elektormagazine.com/magazine/elektor-200907/19093/) - Elektor Magazine, issue 7/2009 on page 40
* [TL431 datasheet](https://www.futurlec.com/Linear/TL431CLP.shtml) - Programmable Precision Reference
