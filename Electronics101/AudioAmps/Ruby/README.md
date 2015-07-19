# AudioAmps/Ruby

A version of the runoffgroove Ruby LM386 guitar amp.

## Notes

The Ruby amp is similar to the [LittleGem](./LittleGem), however it introduces a JFET buffer on the input
and discrete volume and gain controls.

The build here is based on the [runoffgroove schematic](http://www.runoffgroove.com/ruby.html), but with a few variations:
* adds a 10nF coupling capacitor on the input
* modified R-C gain control
* J201 n-channel JFET instead of the original MPF102

## Construction

![Breadboard](./assets/Ruby_bb.jpg?raw=true)

NB: in the schematic below, the FET symbol is not quite correct (shows n-channel MOSFET instead of JFET)

![The Schematic](./assets/Ruby_schematic.jpg?raw=true)

![The Build](./assets/Ruby_build.jpg?raw=true)

## Credits and References
* [Ruby](http://www.runoffgroove.com/ruby.html) 386-based 9v battery amp
* [LM386 datasheet](http://www.futurlec.com/Linear/LM386N-3.shtml)
* [J201 datasheet](http://www.futurlec.com/Transistors/J201.shtml)