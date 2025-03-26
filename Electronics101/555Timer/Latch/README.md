# #692 Push-button Latch

Testing a simple push-button latched switch circuit for on/off control using the 555 timer.

![Build](./assets/Latch_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/LyaoLRMI-wE/0.jpg)](https://www.youtube.com/watch?v=LyaoLRMI-wE)

## Notes

Pressing the button will toggle the output between on and off.

This is a simple latching circuit for push-button on/off control using the 555 timer.
See [LEAP#004](../../../playground/PushbuttonLED/)
for how you may do this with an Arduino instead.

How it works:

* by default:
    * the push-button is not pressed
    * the R1/R2 voltage divider pulls the 555 threshold and trigger pins to the mid-level
    * thus neither THRESHOLD(reset) or TRIGGER(set) inputs to the 555 are enabled and
    * the 555 output state is unchanged
* when the push-button is pressed:
    * if the current output is LOW,
        * the R1/R2 voltage divider mid-point will be pulled LOW
        * TRIGGER(set) falls bellow the 1/3 set-point, causing the 555 to set and output to go HIGH
        * the capacitor C1 holds the button input LOW for long enough for the button to be released
    * if the current output is HIGH,
        * the R1/R2 voltage divider mid-point will be pulled HIGH
        * THRESHOLD(reset) rises above the 2/3 set-point, causing the 555 to reset and output to go LOW
        * the capacitor C1 holds the button input high for long enough for the button to be released

### Circuit Design

![bb](./assets/Latch_bb.jpg?raw=true)

![schematic](./assets/Latch_schematic.jpg?raw=true)

Testing on a breadboard:

![Latch_bb_build](./assets/Latch_bb_build.jpg?raw=true)

### Protoboard Build

Transferring the design to a small protoboard so that it can be used as a latched switch input.

![protoboard_build](./assets/protoboard_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Simple Latching Circuit using 555 timer](https://www.circuits-diy.com/simple-latching-circuit-using-555-timer/)
* [Build a 555 Timer IC based Simple Push-on Push-off Circuit](https://circuitdigest.com/electronic-circuits/555-timer-push-on-push-off-circuit) - dodgy schematic and poor description
* [555 LATCH Circuit](https://www.555-timer-circuits.com/latch.html) - another 555 "latch" circuit but this is different - uses an external latching circuit to enabled/disable a 555 astable.
* [Toggle ON / OFF Switch with a single push-button](https://www.electronics-lab.com/project/toggle-on-off-switch/)
