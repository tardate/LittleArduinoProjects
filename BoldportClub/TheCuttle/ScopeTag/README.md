# #267 TheCuttle/ScopeTag

Get the Boldport Cuttle to write its name on a Digital Oscilloscope with an MCP42010 digital potentiometer.

![ScopeTag_test_run](./assets/ScopeTag_test_run.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I just built [The Cuttle](../) so time for a quick test.

I thought I'd borrow an idea from the [XYplotter](../../playground/XYplotter) project and get The Cuttle
to write its name on an oscilloscope.


The Python script [make_data.py](./tree/make_data.py) is used to interpolate plotting points
over the fundamental text structure. It generates the [data.h](./data.h) used by the
[ScopeTag.ino](./ScopeTag.ino) sketch:

```
python make_data.py > data.h
```

When running on The Cuttle, it produces the image below.
I'm using a Hantek MSO5074FG oscilloscope, and the image was captured with the following settings:

* XY plot mode
* 0.2s persistence
* display as vectors
* average over 4 samples
* CH1/X offset by -4V
* CH2/Y offset by 40mV
* 570mV per grid

![scope_text](./assets/scope_text.gif?raw=true)

The time-domain plot for the generated output is like this:

![scope_text_xt](./assets/scope_text_xt.gif?raw=true)

## Construction

![Breadboard](./assets/ScopeTag_bb.jpg?raw=true)

![Schematic](./assets/ScopeTag_schematic.jpg?raw=true)

![ScopeTag_breadboard](./assets/ScopeTag_breadboard.jpg?raw=true)

## Credits and References
* [LEAP#265 XYplotter](../../playground/XYplotter) - the scope XY plotting project
* [LEAP#266 The Cuttle](../) - building the cuttle
* [MCP42010 datasheet](http://parts.io/detail/1372149/MCP42010-I%2FSL) - parts.io
* [..as mentioned on my blog](https://blog.tardate.com/2017/04/leap267-cuttle-scope-graffiti.html)
