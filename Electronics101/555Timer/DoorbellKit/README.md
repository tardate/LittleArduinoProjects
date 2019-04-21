# #201 555Timer/DoorbellKit

Another two-tone doorbell using a 555 timer oscillator


## Notes

I picked up
[this kit](https://www.aliexpress.com/item/Perfect-Doorbell-Suite-Electronic-DIY-Kit-for-Home-Security-6V-PCB-3-9-x-3-5/32497451130.html)
on special for $0.66. It even came with extra components, so a bit of a bargain impulse-buy.

The kit turns out to be a simplified version of the [TwoToneDoorbell](../TwoToneDoorbell) circuit I've built before.

It lacks the power control circuit, and draws about 4mA when idle - so if you actually use it, expect to be replacing batteries
on a regular basis.

The basic operation is similar. When S1 pressed:
* 555 timer reset (4) is pulled high and charges the R4/C1 RC circuit
* it bypasses R1 (via D2) so that the 555 a-stable behaviour is governed by R2/R3/C2
* speaker is driven with a [102.128 Hz](http://visual555.tardate.com/?mode=astable&r1=47&r2=47&c=0.1) square wave

When S1 released:
* R1 is added to the 555 a-stable biasing
* speaker output modultes to [76.596 Hz](http://visual555.tardate.com/?mode=astable&r1=94&r2=47&c=0.1)

The duration of the "dong" depends on the R4/C1 [RC time constant (𝛕)](http://en.wikipedia.org/wiki/RC_time_constant),
[470ms](https://www.wolframalpha.com/input/?i=47k%CE%A9+*+10%CE%BCF).
When the voltage on pin 4 falls below the reset threshold (typically 0.5V), the oscillation stops.

## Behaviour

Here are some traces of the circuit in operation with 3 channels on a scope:

* CH1: monitoring the C2 charge (pin 2, 6 input)
* CH2: monitoring the pin 4 reset charge/discharge
* CH3: monitoring the pin 3 output

Here's a trace of the initial trigger shwoing the reset line coming high, and the oscillation kick-off:

![scope_trigger](./assets/scope_trigger.gif?raw=true)

And on a wider scale - though hard to see the details - here's a complete "ding-dong" cycle.
The main point to note is the reset discharge over about 1.2s before the 555 shuts off:

![scope_trigger](./assets/scope_decay.gif?raw=true)

## Construction

![Breadboard](./assets/DoorbellKit_bb.jpg?raw=true)

![The Schematic](./assets/DoorbellKit_schematic.jpg?raw=true)

![The Build](./assets/DoorbellKit_build.jpg?raw=true)

## Credits and References
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Doorbell DIY Kit](https://www.aliexpress.com/item/Perfect-Doorbell-Suite-Electronic-DIY-Kit-for-Home-Security-6V-PCB-3-9-x-3-5/32497451130.html) - from a seller on aliexpress
* [eBay Cheap: $0.75 Electronic Doorbell Kit NE555](https://youtu.be/zGkbNP23zo4) - Julian Ilett's build
* [..as mentioned on my blog](https://blog.tardate.com/2016/04/littlearduinoprojects201-yet-another.html)
