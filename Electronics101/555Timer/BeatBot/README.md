# #555 Beat Bot

A silly little @MaywaDenki-inspired critter using multiple 555 timers and a CD4017 to play and dance to a tune.

![Build](./assets/BeatBot_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/IHyEona3Ixk/0.jpg)](https://www.youtube.com/watch?v=IHyEona3Ixk)

## Notes

Project #555 had to feature the 555 timer of course.
I was inspired by the crazy creations of [@MaywaDenki](https://twitter.com/MaywaDenki).

I borrowed a 555 timer [music box](http://www.555-timer-circuits.com/music-box.html) idea for the basic sequencer:

* a 555 timer provides the clock pulse
* driving a CD4017 wich acts as the sequencer
* with another 555 timer providing the modulated audio output
* a pushbutton provides a trigger to short-circuit the sequence (although in the build for the demo clip I realised I'd used a normally-closed pushbutton by mistake, so the effect is inverted)

The synchonized hand-waving uses another monostable 555 timer to pulse a solenoid.

## Construction

![Breadboard](./assets/BeatBot_bb.jpg?raw=true)

![Schematic](./assets/BeatBot_schematic.jpg?raw=true)

Testing the basic tone sequencer on a breadboard:

![BeatBot_bb_build](./assets/BeatBot_bb_build.jpg?raw=true)

After circuit testing complete, I renderd the circuit on some protoboard for installation:

![BeatBot_protoboard_layout](./assets/BeatBot_protoboard_layout.jpg?raw=true)

Installation, using a small box as the base of the project:

![BeatBot_board_installation](./assets/BeatBot_board_installation.jpg?raw=true)

Final construction:

![BeatBot_build_rear](./assets/BeatBot_build_rear.jpg?raw=true)
![BeatBot_build](./assets/BeatBot_build.jpg?raw=true)

## Credits and References

* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [CD4017 datasheet](https://www.futurlec.com/4000Series/CD4017.shtml)
* [MUSIC BOX Circuit](http://www.555-timer-circuits.com/music-box.html)
