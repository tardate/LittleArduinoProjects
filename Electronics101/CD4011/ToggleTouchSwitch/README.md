# #795 CD4011 Toggle Touch Switch

Testing a common CD4011 touch switch circuit with single on/off toggle pad.

![Build](./assets/ToggleTouchSwitch_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/CWf8M0lE_Rc/0.jpg)](https://www.youtube.com/watch?v=CWf8M0lE_Rc)

## Notes

This is a common touch switch circuit based on two NAND gates from a CD4011.

I've made a touch pad from a small piece of copper-clad circuit board, with pins
for plugging into a breadboard.

In practice, the performance is quite unreliable, certainly not good enough for a real-world application.

### Circuit Design

Designed with Fritzing: see [ToggleTouchSwitch.fzz](./ToggleTouchSwitch.fzz).

![bb](./assets/ToggleTouchSwitch_bb.jpg?raw=true)

![schematic](./assets/ToggleTouchSwitch_schematic.jpg?raw=true)

### Performance

Testing on a breadboard:

![bb_build](./assets/ToggleTouchSwitch_bb_build.jpg?raw=true)

See a quick demo..

[![clip](https://img.youtube.com/vi/CWf8M0lE_Rc/0.jpg)](https://www.youtube.com/watch?v=CWf8M0lE_Rc)

In practice, the performance is quite unreliable. It appears very dependent on ambient humidity, and how dry or moist one's fingers are.
Certainly not reliable enough for a real-world application.

Replacing the touch pads with a push-button actually works quite well. Adjusting the capacitor value could improve debouncing the switch.

![bb_alt](./assets/ToggleTouchSwitch_bb_alt.jpg?raw=true)

## Credits and References

* [CD4011 datasheet](https://www.futurlec.com/4000Series/CD4011.shtml)

### Reference Circuit #1

<https://www.talkingelectronics.com/projects/TouchSwitch/TouchSwitch-1.html>

[![Toggle_touch_sw1](assets/Toggle_touch_sw1.gif)](https://www.talkingelectronics.com/projects/TouchSwitch/TouchSwitch-1.html)
