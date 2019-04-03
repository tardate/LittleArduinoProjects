# #252 555Timer/MessageWaiting

Two-LED flasher with a 555 and minimal components - turned into a "message waiting" indicator with some free-wired SMD construction.

Here's a quick video demo:

[![MessageWaiting](./assets/MessageWaiting_build.jpg?raw=true)](https://www.youtube.com/watch?v=_ujCu5yxSXQ)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

This is a variation of a bi-polar LED flasher circuit that uses two single LEDs.
Since that's not very interesting,  I free-wired it with surface mount components
to make a little "message waiting!" indicator. Putting a card in the slot turns on the LED flasher.

The [BI-POLAR LED DRIVER Circuit](http://www.555-timer-circuits.com/bi-polar-led-driver.html)
published by 555-timer-circuits described how to flash a bipolar LED with a 555 timer chip.

I haven't come across a true bipolar LED in a very long time, so I first simulated it
with two LEDs back-to-back on a breadboard.
But due to the 220Ω + 220Ω bridge across the power supply, it drew over 20mA.

By replacing the bipolar LED with two LEDs, and spliting the in & out paths, the effect is the same,
but current draw is 25% less (~15mA).

### Circuit Modifications

* replaced the RC timer circuit with 1µF & 220kΩ. This slows the flashing (was a little fast) and means I can use a small SMD ceramic capacitor instead of an electrolytic package.
* tap the green LED with 1kΩ, to even the apparent brightness of the red and green LEDs.

## Construction

![Breadboard](./assets/MessageWaiting_bb.jpg?raw=true)

![Schematic](./assets/MessageWaiting_schematic.jpg?raw=true)

Testing on a breadboard:

![MessageWaiting_build_breadboard](./assets/MessageWaiting_build_breadboard.jpg?raw=true)

Free-wire/SMD layout and construction:

![MessageWaiting_build_layout](./assets/MessageWaiting_build_layout.jpg?raw=true)

Finished "Message Waiting" gadget. Putting a card in the slot turns on the flasher.

![Build](./assets/MessageWaiting_build.jpg?raw=true)

## Credits and References
* [BI-POLAR LED DRIVER Circuit](http://www.555-timer-circuits.com/bi-polar-led-driver.html) - 555-timer-circuits
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [Bi-ploar LED parts](http://parts.io/search/term-bi-polar%20led/Class-Optoelectronics/Category-Visible%20LEDs?Configuration=COMMON%20BIPOLAR%20TERMINAL%2C%202%20ELEMENTS) - at parts.io
* [..as mentioned on my blog](https://blog.tardate.com/2017/02/leap252-message-waiting.html)
