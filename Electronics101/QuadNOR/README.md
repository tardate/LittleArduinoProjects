# #073 QuadNOR

Demonstrates simple cascading NOR gate logic with the 74LS02 and an Arduino

Here's the quick demo of the circuit in action:

[![QuadNOR](https://img.youtube.com/vi/D_5Da_8R8Ek/0.jpg)](https://www.youtube.com/watch?v=D_5Da_8R8Ek)


## Notes

See the [NOR7402 project readme](../NOR7402) for more detail on the 74LS02.
This is a simple extension of the [NOR7402](../NOR7402) circuit that cascades 2 NOR gate into 1,
with the resulting logic table:

| A1 | B1 | Y1/A3 | A2 | B2 | Y2/B3 | Y3 |
|:--:|:--:|:-----:|:--:|:--:|:-----:|:--:|
| 0  | 0  | 1     | 0  | 0  | 1     | 0  |
| 0  | 0  | 1     | 0  | 1  | 0     | 0  |
| 0  | 0  | 1     | 1  | 0  | 0     | 0  |
| 0  | 0  | 1     | 1  | 1  | 0     | 0  |
| 0  | 1  | 0     | 0  | 0  | 1     | 0  |
| 0  | 1  | 0     | 0  | 1  | 0     | 1  |
| 0  | 1  | 0     | 1  | 0  | 0     | 1  |
| 0  | 1  | 0     | 1  | 1  | 0     | 1  |
| 1  | 0  | 0     | 0  | 0  | 1     | 0  |
| 1  | 0  | 0     | 0  | 1  | 0     | 1  |
| 1  | 0  | 0     | 1  | 0  | 0     | 1  |
| 1  | 0  | 0     | 1  | 1  | 0     | 1  |
| 1  | 1  | 0     | 0  | 0  | 1     | 0  |
| 1  | 1  | 0     | 0  | 1  | 0     | 1  |
| 1  | 1  | 0     | 1  | 0  | 0     | 1  |
| 1  | 1  | 0     | 1  | 1  | 0     | 1  |


### Construction

![The Breadboard](./assets/QuadNOR_bb.jpg?raw=true)

![The Schematic](./assets/QuadNOR_schematic.jpg?raw=true)

![The Build](./assets/QuadNOR_build.jpg?raw=true)


## Credits and References
* [NOR7402](../NOR7402) project
* [74LS02 datasheet](https://www.futurlec.com/74LS/74LS02.shtml)
* [7400 series](http://en.wikipedia.org/wiki/7400_series)

