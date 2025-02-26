# #565 Breadboard Bling: Single-Shot Trigger

A debounced single-shot pulse generator with inverted amd non-inverted output designed for use on a breadboard.

![Build](./assets/SingleShotTrigger_build.jpg?raw=true)

## Notes

This little module is for those breadboard occasions where when one needs a debounced pulse - or possibly an inverted pulse for active low logic.

It uses a 555 timer in monostable mode to debounced a pushbutton, emitting a pulse of trigger a pulse of at least
[22ms](https://visual555.tardate.com/?mode=monostable&r1=20&c=1) (R1=20k and C1=1uF).

A CD4049 is used to buffer and invert the outputs (inverted amd non-inverted) so that it can match any required load.

## Construction

First testing the circuit on a breadboard:

![Breadboard](./assets/SingleShotTrigger_bb.jpg?raw=true)

![Schematic](./assets/SingleShotTrigger_schematic.jpg?raw=true)

![SingleShotTrigger_bb_build](./assets/SingleShotTrigger_bb_build.jpg?raw=true)

## Making it a "Breadboard Bling" Module

I went for dead-bug style on a small piece of protoboard in order to keep the module small (I don't have SMD versions of these chips on hand).

![SingleShotTrigger_module](./assets/SingleShotTrigger_module.jpg?raw=true)

## Performance

A scope trace of the pushbutton (CH2 - Blue) and the triggered and debounced 555 output (CH1 - Yellow):

![scope_debounce](./assets/scope_debounce.gif?raw=true)

The outputs from the CD4049 on a trigger pulse:

* CH1 - Yellow: non-inverted output
* CH2 - Blue: inverted output (offset -3.5V)

![scope_output](./assets/scope_output.gif?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [CD4049 datasheet](https://www.futurlec.com/4000Series/CD4049.shtml)
