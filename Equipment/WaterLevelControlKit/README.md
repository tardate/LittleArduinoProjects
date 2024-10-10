# #601 Water-Level Control Kit

Build and test a high-low switching circuit with relay output. It is intended for monitoring a water tank level and switching a pump.

![Build](./assets/WaterLevelControlKit_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/j3tgy-CU2bo/0.jpg)](https://www.youtube.com/watch?v=j3tgy-CU2bo)

## Notes

This is a simple 5V circuit in a cheap kit form that demonstrates a high-low control circuit.
An LM324 is used as a comparator to evaluate two switch inputs ("low", "high") and trigger a relay accordingly.
The relay can be used to control a compensating service (e.g. turn on a pump if low state triggered, and turn it off when high state triggered).

I don't actually have a water tank to control; I picked this kit up just to study the circuit,
but now I'm thinking there may be other applications I can put it usefully to work in.

## The Kit

The [kit](https://www.aliexpress.com/item/1005003449634082.html) is available form aliexpress sellers for around SGD$2.90 as I write this.

![kit_parts](./assets/kit_parts.jpg?raw=true)

A well-made single-sided PCB:

![kit_pcb](./assets/kit_pcb.jpg?raw=true)

![kit_instructions](./assets/kit_instructions.jpg?raw=true)

## Parts

| Ref                  | Component            | Qty |
|----------------------|----------------------|-----|
| R7                   | 220Ω                 |  1  |
| R5,9,14              | 1kΩ                  |  3  |
| R11,17,20            | 2.2kΩ                |  3  |
| R10                  | 4.7kΩ                |  1  |
| R21,22               | 10kΩ                 |  2  |
| R1,2,3,8,12,16,18,19 | 47kΩ                 |  8  |
| R6,15                | 100kΩ                |  2  |
| R4,13                | 1MΩ                  |  2  |
| C1                   | 22nF (223) ceramic   |  1  |
| C2,3,4,5,7,8,9       | 100nF (104) ceramic  |  7  |
| C10                  | 10µF                 |  1  |
| C6                   | 100µF                |  1  |
| D1,2,4,5             | 1n4148               |  4  |
| D9                   | 1n4007               |  1  |
| D6,D8                | 5mm LED red          |  2  |
| D7                   | 5mm LED yellow       |  1  |
| D3                   | 5mm LED green        |  1  |
| Q1,Q2                | S8050 NPN            |  2  |
| J                    | 5V relay             |  1  |
|                      | LM324                |  1  |
|                      | 14 pin DIP socket    |  1  |
| J3                   | 2 pin terminal block |  1  |
| J4                   | 3 pin terminal block |  1  |
| J1,J2                | 2.54mm pin header x2 |  2  |
| S1                   | switch               |  1  |
|                      | PCB                  |  1  |

## How It Works

There are two inputs:

* J1 - "low state" input switch
* J2 - "high state" input switch

State table:

| State          | J1     | J2     | D6 Red | D7 Yellow | D3 Green | VIN | Relay State |
|----------------|--------|--------|--------|-----------|----------|-----|--------------|
| low            | open   | open   | ON     | OFF       | OFF      | High    | ON  |
| low -> medium  | closed | open   | OFF    | ON        | OFF      | ~ VCC/2 | ON  |
| medium -> high | closed | closed | OFF    | OFF       | ON       | Low     | OFF |
| high -> medium | closed | open   | OFF    | ON        | OFF      | ~ VCC/2 | OFF |
| medium -> low  | open   | open   | ON     | OFF       | OFF      | High    | ON  |

Note:

* J1=open, J2=closed is an invalid/undefined state
* switch S1 is used to invert the relay output

The interesting trick in this circuit is how it arranges for the hysteresis effect through the "medium" state:

* when "filling" (i.e. low->medium->high), the relay ("pump") stays on in the medium state
* when "emptying" (i.e. high->medium->low), the relay ("pump") stays off in the medium state

This is achieved with feedback from the final output opamp unit LM324d(pin14) to its non-inverting input (pin12) i.e.:

* with J1 closed, LM324c(pin8) is low
* with J2 closed, LM324b(pin7) is low
* then the final output LM324d(pin14) is pulled high
* but when J2 opened, LM324b(pin7) goes high, but the resulting voltage on LM324d inverting input is not high enough to LM324d feedback to its non-inverting input
* but when J1 also opened, LM324c(pin8) also goes high and is finally enough to flip LM324d

Note: LM324a, the first opamp unit, is configured as a square wave oscillator running at about 710Hz.
This provides the AC signal switched via J1 and J2 to pull their respective LM324 opamp units high
via the DC-blocking capacitors. See the signal trace, tapped at pin 1 of the LM324:

![scope_osc](./assets/scope_osc.gif?raw=true)

## Construction

Here is my redraw of the schematic and a possible breadboard layout:

![bb](./assets/WaterLevelControlKit_bb.jpg?raw=true)

![schematic](./assets/WaterLevelControlKit_schematic.jpg?raw=true)

I don't actually have a water tank to monitor, so I did a quick simulation and test on a breadboard:

![bb_build](./assets/WaterLevelControlKit_bb_build.jpg?raw=true)

## Credits and References

* [LM324 chip automatic drainage dual-function controller DIY learning welding spare parts automatic water level controller kit](https://www.aliexpress.com/item/1005003449634082.html)
* [S8050 Datasheet](http://electronics.se-ed.com/magic/s8050.pdf) - NPN BJT
* [LM324N Datasheet](https://www.futurlec.com/Linear/LM324N.shtml)
