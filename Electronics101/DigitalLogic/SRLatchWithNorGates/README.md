# #077 NOR Gate SR Latch

Set-Reset latch implemented with NOR gates.

![The Build](./assets/SRLatchWithNorGates_build.jpg?raw=true)

## Notes

This circuit is another implementation of a Set-Reset flip-flop, this time using NOR gates.
Sometimes this is referred to as a "NOR Latch".
A 74LS02 is used to provide the two NOR gates required.

See the [LEAP#061 SRLatch](../SRLatch) circuit for an implementation using BJTs.

Ben Eater has a great video explaining SR latch behaviour:

[![KM0DdEaY5sY](https://img.youtube.com/vi/KM0DdEaY5sY/0.jpg)](https://www.youtube.com/watch?v=KM0DdEaY5sY)

### Truth Table

| Set(t) | Reset(t) | Output Q(t+1) |
|--------|----------|---------------|
|      0 |        0 | no change     |
|      0 |        1 | 0             |
|      1 |        0 | 1             |
|      1 |        1 | invalid state |

### Construction

![The Breadboard](./assets/SRLatchWithNorGates_bb.jpg?raw=true)

![The Schematic](./assets/SRLatchWithNorGates_schematic.jpg?raw=true)

![The Build](./assets/SRLatchWithNorGates_build.jpg?raw=true)

## Credits and References

* [LEAP#061 SRLatch](../SRLatch)
* [74LS02 datasheet](https://www.futurlec.com/74LS/74LS02.shtml)
* [NOR-gate Latch](http://hyperphysics.phy-astr.gsu.edu/hbase/electronic/norlatch.html)
* [NOR gate S-R latch](http://www.allaboutcircuits.com/vol_6/chpt_7/3.html)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap061-set-reset-latches.html)
