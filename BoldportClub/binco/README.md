# #363 binco

BINCO is a little up or down "fidget" counter, Project #19 of the Boldport Club.

![Build](./assets/binco_build.jpg?raw=true)

## Notes

The BINCO a binary counter that can be configured to count up or down. It uses Snaptron domes as buttons (on, slow/fast and reset).
The heart of the counter is a 555 timer driving a 74HC4020D 14-bit Binary Counter from which 11 taps drive some nice reverse-mount LEDs.


## Parts and Unboxing

![kit_packaging](./assets/kit_packaging.jpg?raw=true)

|      | Item                                                     |
|------|----------------------------------------------------------|
| 1x   | 14-bit binary counter IC, Nexperia 74HC4020D,652         |
| 1x   | 555 timer IC, TI TLC555QDRG4                             |
| 11x  | Reverse mount green SMD LEDz, Kingbright KPTL-3216CGCK   |
| 1x   | N-channel MOSFET SMD transistor, ON Semi BSS123          |
| 16x  | 1.5KΩ 0805 resistors, Multicomp MCWR08X1501FTL           |
| 2x   | 47KΩ 0805 resistors, Multicomp MCWR08X4702FTL            |
| 2x   | 1µF 0805 capacitors, Multicomp MC0805F105Z160CT          |
| 1x   | CR2032 battery clip, Multicomp BC-2001                   |
| 1x   | Dome (reset), Snaptron GX05300                           |
| 1x   | Double action dome (count slow/fast), Snaptron DT10340N  |
| 1x   | Dome (on/off), Snaptron F10450                           |
| 1x   | PCB                                                      |
| 1x   | Piece of adhesive sheet                                  |

![kit_parts](./assets/kit_parts.jpg?raw=true)
![kit_pcb_front](./assets/kit_pcb_front.jpg?raw=true)
![kit_pcb_rear](./assets/kit_pcb_rear.jpg?raw=true)

## How It Works

The 555 timer is in an astable configuration, initially disabled.

* when "count slow" button is pressed, ti runs at around [15 Hz](http://visual555.tardate.com/?mode=astable&r1=1.5&r2=47&c=1)
* when "count fast" button is pressed, it runs at around [320 Hz](http://visual555.tardate.com/?mode=astable&r1=1.5&r2=1.5&c=1)

The timer provides the clock pulse to the 74HC4020D 14-bit Binary Counter. The 74HC4020D provides 12 taps of a ripple-carry chain,
but the first (pin 9) is not used, probably because the chip doesn't provide pins for the next two stages.

As always, Boldport provides a very nice
[infographic](https://github.com/boldport/binco/raw/master/docs/infographic.pdf) for the project,
but here is my re-drawing of the circuit (it's how I make sure I understand what is going on!)

![Schematic](./assets/binco_schematic.jpg?raw=true)

Interesting:

* the "on" switch only affects the LEDs; the ICs remain powered by the battery at all times. I suspect a sneaky trick to always "remember" the last state!
* but R100 stops the 555 timer running while not "on" by pulling down the reset pin.

## Construction

I decided to build the "count down" configuration, which involves making sure the LEDs point to the edge of the board, and bridging the down/right count pad.

In this configuration, R101 and IC10 are optional, so I left them off the board.

![binco_build_front](./assets/binco_build_front.jpg?raw=true)

![binco_build_rear](./assets/binco_build_rear.jpg?raw=true)

![Build](./assets/binco_build.jpg?raw=true)

Here's a quick demo, "fast mode".

[![Zv6acP0ddqo](https://img.youtube.com/vi/Zv6acP0ddqo/0.jpg)](https://www.youtube.com/watch?v=Zv6acP0ddqo)

## Credits and References

* [BINCO](https://www.boldport.com/products/binco) - product page
* [BINCO](http://community.boldport.club/projects/p19-binco/) - on the community site
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [74HC4020 Datasheet](https://www.futurlec.com/74HC/74HC4020SMD.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2017/12/leap363-binco-fidget-counter.html)
