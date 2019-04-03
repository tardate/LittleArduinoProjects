# #318 555Timer/Bistable

Using the 555 timer as a bistable latch (debouncer).

![Build](./assets/Bistable_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Ben Eater's 8-bit computer yields more interesting circuits.
Here I'm reproducing his [bistable latch circuit based on the 555 timer](https://www.youtube.com/watch?v=WCwJNnx36Rk).

## How it Works

This circuit takes advantage of the fact that the trigger and reset pins provide direct access to the SR latch within the 555 timer that drives the output.

* The trigger pin provides a SET input when it rises above the 33% division of the 5V input - [1.67V](https://www.wolframalpha.com/input/?i=5V%2F3).
* The reset pin provides an inverted (Active low) RESET input.

With pull-ups on both trigger and reset pins, the 555 is in a SET (output high) state.

A make-before-break single-pole double-throw switch is wired up to switch between grounding either the trigger and reset pin.
This will toggle between SET and RESET, with debouncing since multiple pulses will effectively be ignored by the latch.

## Performance

The switch throw is effectively debouned - and despite using it rudely,
I haven't been able to reproduce any bouncing input signals yet.

However when zoomed in very tightly on a rising edge, there is not a very clean swing.
This appears to be cross-over distortion on the 555 output.

![scope-trigger](./assets/scope-trigger.gif?raw=true)

## Construction

![Breadboard](./assets/Bistable_bb.jpg?raw=true)

![Schematic](./assets/Bistable_schematic.jpg?raw=true)

![Build](./assets/Bistable_build.jpg?raw=true)

## Credits and References
* [Bistable 555 - 8-bit computer clock - part 3](https://www.youtube.com/watch?v=WCwJNnx36Rk) - Ben Eater
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/06/leap318-555-bistable-latch.html)
