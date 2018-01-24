# #265 XYplotter

Draw pictures on a Digital Oscilloscope using an MCP42010 dual digital potentiometer and an Arduino.
Of course, the first thing to try is the classic Christmas Tree.

![Build](./assets/XYplotter_build.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

There's a geeky meme that's been around for years .. "drawing" pictures on an oscilloscope.
I'm inspired to try something similar by [w2aew's video](https://youtu.be/Dx9N91FnPdo?list=PL049620539B359102)
based on the the [Christmas Tree by johngineer](http://www.johngineer.com/blog/?p=648).

The techniques usually exploit the behaviour of analog scopes.
This doesn't work so well on digitial oscilloscopes since they are generally too good at picking up discontinuities.

In this experiment, I'm using an MCP42010 digital potentiometer to drive an X-Y plot with an Arduino.
Using a digital potentiometer is a convenience - it could also be achieved with PWM outputs and RC filter
for smoothing. While this approach works, it is quite sensitive to the output frequency and capabilities
of the oscilloscope.

### The Classic Christmas Tree

Of course, the first thing to try is to re-create the classic Christmas Tree.

The Python script [build_data.py](./tree/build_data.py) is used to interpolate plotting points
over the fundamental tree structure. It generates the [data.h](./tree/data.h) used by the
[tree.ino](./tree/tree.ino) sketch:

```
cd tree
./build_data.py > data.h
```

When running on the Arduino, it produces the image below. Scope settings:

* XY plot mode
* 8s persistence
* average over 8 samples
* X and Y offset by -2.5V (to produce a roughly centred image)

![scope_tree](./assets/scope_tree.gif?raw=true)

The time-domain plot for the generated output is like this:

![scope_tree_xt](./assets/scope_tree_xt.gif?raw=true)

## Construction

![Breadboard](./assets/XYplotter_bb.jpg?raw=true)

![Schematic](./assets/XYplotter_schematic.jpg?raw=true)

![Build](./assets/XYplotter_breadboard.jpg?raw=true)

## Credits and References
* [OSCILLOSCOPE CHRISTMAS TREE](http://www.johngineer.com/blog/?p=648) - uses PWM and RC filters
* [#78: Use an Arduino to draw pictures on an oscilloscope using XY mode](https://youtu.be/Dx9N91FnPdo?list=PL049620539B359102) - w2aew
* [MCP42010 datasheet](http://parts.io/detail/1372149/MCP42010-I%2FSL) - parts.io
* [LEAP#264 MCP42010](../../Electronics101/DigitalPots/MCP42010) - basic test of the MCP42010
* [..as mentioned on my blog](https://blog.tardate.com/2017/04/leap265-xyplotter-fun.html)
