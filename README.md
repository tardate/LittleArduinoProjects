# Little Arduino Projects

A collection of simple Arduino projects.
Most of these are variations of things found in the example code or in the wild on the net.
See the individual projects for credits where due.

Feel free to borrow any ideas, and if you spot any issues do let me know.

Circuit diagrams are drawn with the wonderful [Fritzing APP](http://fritzing.org/home/).

## The Projects

* [Blink](./playground/Blink)
* [HeartQuotes - Press a button to get a quote](./playground/HeartQuotes)
* [It's Better With Bacon](./playground/BetterWithBacon) - simple LCD test
* [LED chaser](./playground/LedChaser)
* [LightOrNot - blink rate of an LED proportional to how light it is](./playground/LightOrNot)
* [Pushbutton LED switch](./playground/PushbuttonLED)
* [Simple 7-segment common cathode LED display](./playground/Simple7SegmentDisplay)
* [Variable LED brightness (PWM)](./playground/VariableLED)

## Up and Running

The LED array projects use the [FastLED](http://fastled.io/) library, included here as a git submodule.
If you clone this repo, also update the submodules:

    $ git submodule update --init
