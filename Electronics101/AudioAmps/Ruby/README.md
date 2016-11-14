# #104 AudioAmps/Ruby

A version of the runoffgroove Ruby LM386 guitar amp.


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

The Ruby amp is similar to the [LittleGem](./LittleGem), however it introduces a JFET buffer on the input
and discrete volume and gain controls.

The build here is based on the [runoffgroove schematic](http://www.runoffgroove.com/ruby.html), but with a few variations:
* adds a coupling capacitor on the input
* J201 n-channel JFET instead of the original MPF102

## Construction

![Breadboard](./assets/Ruby_bb.jpg?raw=true)

NB: in the schematic below, the FET symbol is not quite correct (shows n-channel MOSFET instead of JFET)

![The Schematic](./assets/Ruby_schematic.jpg?raw=true)

## Breadboard Build

Running the amp on a breadboard is possible, but noise and interferance can be a real problem.
So performace on a breadboard is not a very good indicator of actual performance if you build the circuit on a PCB.

![The Build](./assets/Ruby_build.jpg?raw=true)

## Prototype Build

Running on a protoboard. Works really well! I need to find some pots to replace the trimmers then I can mount it properly.

Here's the layout I used:

![The Schematic](./assets/Ruby_pcb_build.jpg?raw=true)

![The Schematic](./assets/Ruby_pcb_front.jpg?raw=true)

![The Schematic](./assets/Ruby_pcb_rear.jpg?raw=true)

## Credits and References
* [Ruby](http://www.runoffgroove.com/ruby.html) 386-based 9v battery amp
* [LM386 datasheet](http://www.futurlec.com/Linear/LM386N-3.shtml)
* [J201 datasheet](http://www.futurlec.com/Transistors/J201.shtml)