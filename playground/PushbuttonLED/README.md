# #004 Pushbutton LED Switch

Momentary push button switch is used to toggle the LED on and off.

![The Build](./assets/PushbuttonLED_build.jpg?raw=true)

## Notes

A simple circuit showing how to wire a pushbutton with a pull-down resistor for a digital input that is normally low
but pulls high when pressed.

Pressing the button will toggle the LED between on and off.
See [LEAP#692](../../Electronics101/555Timer/Latch/) for how to achieve a similar result with a simple 555 timer chip.

## The Sketch

The [PushbuttonLED.ino](./PushbuttonLED.ino) sketch:

* reads the push-button digital input
* toggles the LED output state between ON and OFF when a button press is detected
* logs to serial output so one can inspect the behaviour

## Construction

![The Breadboard](./assets/PushbuttonLED_bb.jpg?raw=true)

![The Schematic](./assets/PushbuttonLED_schematic.jpg?raw=true)

![The Build](./assets/PushbuttonLED_build.jpg?raw=true)

## Credits and References

* Based on the [Arduino Pushbutton example](http://www.arduino.cc/en/Tutorial/Pushbutton)
