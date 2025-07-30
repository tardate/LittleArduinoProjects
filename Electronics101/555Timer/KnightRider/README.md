# #227 Knight Rider

The familiar "Knight-Rider" LED circuit using a 555 and 4017

![The Build](./assets/KnightRider_build.jpg?raw=true)

## Notes

This is a well-known LED effects circuit using the 555 timer and 4017 decade counter.
Similar circuits can be found in many sources, such as:

* [Knight Rider](https://www.talkingelectronics.com/projects/50%20-%20555%20Circuits/50%20-%20555%20Circuits.html) on Talking Electronics
* [KNIGHT RIDER Circuit](https://www.555-timer-circuits.com/knight-rider.html) on 555 Timer Circuits

This project is a variation of the circuit published on 555 Timer Circuits - I've added steering diodes
rather than allowing paired outputs to sink each other.

### Clock Generator

The 555 timer is configured as an astable multivibrator, with a frequency of
[10.5 Hz at ~50% duty cycle](https://visual555.tardate.com/?mode=astable&r1=1&r2=68&c=1).

### Decoding the LED Display

The clock signal from the 555 drives the 4017 decade counter, providing 10 signal lines.
The 10 outputs of the 4017 (Q0 to Q9) are wired to the appropriate LEDs per the table below to generate the "Knight-Rider" pattern:

| Q high | LED1 | LED2 | LED3 | LED4 | LED5 | LED6 |
|--------|------|------|------|------|------|------|
|  Q0    | off  | off  | off  | off  | off  | ON   |
|  Q1    | off  | off  | off  | off  | ON   | off  |
|  Q2    | off  | off  | off  | ON   | off  | off  |
|  Q3    | off  | off  | ON   | off  | off  | off  |
|  Q4    | off  | ON   | off  | off  | off  | off  |
|  Q5    | ON   | off  | off  | off  | off  | off  |
|  Q6    | off  | ON   | off  | off  | off  | off  |
|  Q7    | off  | off  | ON   | off  | off  | off  |
|  Q8    | off  | off  | off  | ON   | off  | off  |
|  Q9    | off  | off  | off  | off  | ON   | off  |

Steering diodes are used to prevent 4017 outputs sinking current back to another pin connected to the same LED.

NB: diodes are omitted for LED1 and LED6 since they are only driven by one output. This does mean LED1 and LED6
are driven with a slightly higher current than other LEDs, but the difference is not noticeable; to even
up the current, redundant steering diodes could be added, or the current-limiting resistor increased proportionally.

## Construction

![Breadboard](./assets/KnightRider_bb.jpg?raw=true)

![The Schematic](./assets/KnightRider_schematic.jpg?raw=true)

![The Build](./assets/KnightRider_build.jpg?raw=true)

## Credits and References

* [CD4017 datasheet](https://www.futurlec.com/4000Series/CD4017SMD.shtml)
* [LM555 datasheet](https://www.futurlec.com/Linear/LM555CM.shtml)
* Reference Circuits:
    * [Knight Rider](https://www.talkingelectronics.com/projects/50%20-%20555%20Circuits/50%20-%20555%20Circuits.html) on Talking Electronics
    * [KNIGHT RIDER Circuit](https://www.555-timer-circuits.com/knight-rider.html) on 555 Timer Circuits
* [..as mentioned on my blog](https://blog.tardate.com/2017/01/littlearduinoprojects227-555-kight-rider.html)
