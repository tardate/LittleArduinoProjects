# #319 555Timer/DigitalLogicClock

Build a flexible, low-frequency digital logic clock module.

![Build](./assets/DigitalLogicClock_build.jpg?raw=true)

## Notes

This digital clock module was [designed by Ben Eater](https://www.youtube.com/watch?v=SmQ5K7UQPMM) as part of his 8-bit computer build.
It is also an interesting demonstration of the 555 timer in all its major modes of operation.

The clock module features in summary:

* 5V CMOS & TTL compatible output
* relatively low frequency operation
* variable frequency automatic (continuous) mode
* manual mode - trigger individual clock pulses by hand
* switch between auto and manual mode with button debounce
* HALT override to disable all clock output
* LED indicator of the clock output

### Automatic (Astable) Mode

The first 555 timer (IC1) is configured in astable mode with variable frequency. It can generate pulses from:

* [0.71Hz @ 50% duty](http://visual555.tardate.com/?mode=astable&r1=0.47&r2=101&c=10), to
* [58Hz @ 60% duty](http://visual555.tardate.com/?mode=astable&r1=0.47&r2=1&c=10)

This is the source of the automatic (continuous) clock.

### Manual (Monostable) Mode

The second 555 timer (IC2) is configured in monostable mode. When switch S1 is pressed, it generates a single pulse:

* [110ms high time](http://visual555.tardate.com/?mode=monostable&r1=10&c=10)

This is the source of the manual trigger clock.

### Selector (Bistable)

The third 555 timer (IC3) is configured as a bistable debouncer for switch S2.
Switch S2 selects between the automatic and manual clock source.

The selection is implemented with NAND gate logic on IC4

### Halt

Switch S3 is combined with NAND gate logic on IC5 to provide a master enable/disable switch.

### Combining the Signals

There are four inputs that need to be resolved into the final output:

* (a) Automatic (Astable) input
* (b) Manual (Monostable) input
* (c) Selector input
* (d) Halt input

The basic logic can be intuited: `d'.(a.c + b.c')`

I verified that with a Karnaugh map analysis. I decided to go with the idea of converting this to an implementation
solely based on NAND gates.

![DigitalLogicClock_logic](./assets/DigitalLogicClock_logic.jpg?raw=true)

## Construction

![Breadboard](./assets/DigitalLogicClock_bb.jpg?raw=true)

![Schematic](./assets/DigitalLogicClock_schematic.jpg?raw=true)

Breadboard build and test:

![DigitalLogicClock_bb_build](./assets/DigitalLogicClock_bb_build.jpg?raw=true)

Layout for a protoboard implementation:

![DigitalLogicClock_protoboard_layout](./assets/DigitalLogicClock_protoboard_layout.jpg?raw=true)

Protoboard build:

![Build](./assets/DigitalLogicClock_build.jpg?raw=true)

## Credits and References
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [74LS00 datasheet](https://www.futurlec.com/74LS/74LS00.shtml)
* [Visual 555 Calculator](http://visual555.tardate.com)
* [Astable 555 timer - 8-bit computer clock - part 1](https://www.youtube.com/watch?v=kRlSFm519Bo) - Ben Eater
* [Monostable 555 timer - 8-bit computer clock - part 2](https://www.youtube.com/watch?v=81BgFhm2vz8) - Ben Eater
* [Bistable 555 - 8-bit computer clock - part 3](https://www.youtube.com/watch?v=WCwJNnx36Rk) - Ben Eater
* [Clock logic - 8-bit computer clock - part 4](https://www.youtube.com/watch?v=SmQ5K7UQPMM) - Ben Eater
* [..as mentioned on my blog](https://blog.tardate.com/2017/06/leap319-digital-logic-clock.html)
