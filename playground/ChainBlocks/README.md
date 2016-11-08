# #268 ChainBlocks

Testing some "Chain Blocks" and demonstrate an XY Plotter block (with an MCP42010 digital potentiometer) by drawing the PrexLab logo on an Oscilloscope.

![Build](./assets/ChainBlocks_build.jpg?raw=true)

## Notes

My neighbour is developing a prototyping system called [Chain Blocks by PrexLab](http://www.prextron.com/chain),
and passed me some to try out. Disclaimer: at no charge.

### Chain Blocks?

Chain Blocks sit somewhere on the continuum of ideas that are trying to make electronics more approachable especially for novices:

* the "building block" approach, perhaps exemplified by [littlebits](http://littlebits.cc/). These require no electronics or coding backgound.
* the standard Shield/Cape/Hat approach and a miscellany or modules that can be directly wired to the microcontroller development board. These are moderately approachable by beginners but require some electronics to be learned along the way, and you must be ready to code
* kit-assisted breadboard prototyping, like [shrimping.it](http://start.shrimping.it/)
* and beyond that we get into standard protoboard/breadboarding techniques for those willing to dive head-first into electronics as a hobby

I started with a ["Chain Nano block with one application block"](http://www.prextron.com/product-page/8fe8f05f-951e-1563-b917-88adf8284543).
I turned the application block into an "XY Plotter Block".

![ChainBlocks_pair](./assets/ChainBlocks_pair.jpg?raw=true)


### The XY Plotter Block

For a test, I decided to make an XY plotter block, based on the [LEAP: XYplotter](../XYplotter) project.

It uses an MCP42010 dual digital potentiometer to draw images on an oscilloscope.

![XYBlock_upper](./assets/XYBlock_upper.jpg?raw=true)

![XYBlock_lower](./assets/XYBlock_lower.jpg?raw=true)


### Test Sketch

[ChainBlocks.ino](./ChainBlocks.ino) is a test sketch that draws "PrexLab" on a scope.

The Python script [make_data.py](./tree/make_data.py) is used to interpolate plotting points
over the fundamental text structure. It generates the [data.h](./data.h) used by the
[ChainBlocks.ino](./ChainBlocks.ino) sketch:

```
python make_data.py > data.h
```

The sketch produces the image below.
I'm using a Hantek MSO5074FG oscilloscope, and the image was captured with the following settings:

* XY plot mode
* 0.2s persistence
* display as vectors
* average over 4 samples
* CH1/X and CH2/Y offset to position the image

![scope_text](./assets/scope_text.gif?raw=true)

The time-domain plot for the generated output is like this:

![scope_text_xt](./assets/scope_text_xt.gif?raw=true)

### Construction

![Breadboard](./assets/ChainBlocks_bb.jpg?raw=true)

![Schematic](./assets/ChainBlocks_schematic.jpg?raw=true)

![Build](./assets/ChainBlocks_build.jpg?raw=true)

## Credits and References
* [Chain Blocks](http://www.prextron.com/chain) - product site
* [PrexLab](https://www.facebook.com/groups/1086037341416426/) - facebook
* [LEAP: XYplotter](../XYplotter) - the scope XY plotting project
