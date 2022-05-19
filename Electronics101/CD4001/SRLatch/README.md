# #635 CD4001 SR Latch

Set-Reset latch implemented with CD4001 NOR gates.

![Build](./assets/SRLatch_build.jpg?raw=true)

Here's a quick demo..

[![clip](https://img.youtube.com/vi/95eyO3oV5bk/0.jpg)](https://www.youtube.com/watch?v=95eyO3oV5bk)

## Notes

This circuit is another implementation of a Set-Reset flip-flop, this time using NOR gates.
Sometimes this is referred to as a "NOR Latch".
A CD4001 is used to provide the two NOR gates required.

See the [LEAP#061 SRLatch](../DigitalLogic/SRLatch) circuit for an implementation using BJTs.

Ben Eater has a great video explaining SR latch behaviour:

[![KM0DdEaY5sY](https://img.youtube.com/vi/KM0DdEaY5sY/0.jpg)](https://www.youtube.com/watch?v=KM0DdEaY5sY)

### Truth Table

| Set(t) | Reset(t) | Output Q(t+1) |
|--------|----------|---------------|
|      0 |        0 | no change     |
|      0 |        1 | 0             |
|      1 |        0 | 1             |
|      1 |        1 | invalid state |

## Construction

![bb](./assets/SRLatch_bb.jpg?raw=true)

![schematic](./assets/SRLatch_schematic.jpg?raw=true)

![Build](./assets/SRLatch_build.jpg?raw=true)

## Credits and References

* [LEAP#061 SRLatch](../DigitalLogic/SRLatch)
* [CD4001 datasheet](https://www.futurlec.com/4000Series/CD4001.shtml)
* [NOR-gate Latch](http://hyperphysics.phy-astr.gsu.edu/hbase/electronic/norlatch.html)
* [NOR gate S-R latch](http://www.allaboutcircuits.com/vol_6/chpt_7/3.html)
