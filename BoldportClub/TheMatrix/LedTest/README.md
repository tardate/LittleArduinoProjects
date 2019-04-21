# #300 TheMatrix/LedTest

Testing The Matrix (Boldport Club project #11) with @luckyresistor's LRAS1130 library

![Build](./assets/LedTest_build.jpg?raw=true)

## Notes

Testing [LEAP#299 TheMatrix](../TheMatrix) - Boldport Club Project #11 - with the
[LRAS1130](https://github.com/LuckyResistor/LRAS1130) Arduino library from @luckyresistor.


I'm using a version of the
[LedTest.ino](https://github.com/LuckyResistor/LRAS1130/blob/master/examples/LedTest/LedTest.ino)
script.


### Visual Result

In the initial test I found two LEDs that needed a connection fix:


![initial_result](./assets/initial_result.jpg?raw=true)

After fixing those LEDs, all are performing correctly.
However note the intensity of a few LEDs is not the same as others.
As far as I can tell, it may be a problem with the LEDs themselves.

![final_result](./assets/final_result.jpg?raw=true)

### Test Output

The Matrix is laid out in a 5x24 matrix as described in the datasheet (Figure 54).
This means the LED addresses A thu F are not populated i.e. only 10 out of every 16 LED addresses are used.

For the LEDs that are populated, the test script says they are all OK:

```
Initialize chip
Run the LED test
LED 0x0:  OK
LED 0x1:  OK
LED 0x2:  OK
LED 0x3:  OK
LED 0x4:  OK
LED 0x5:  OK
LED 0x6:  OK
LED 0x7:  OK
LED 0x8:  OK
LED 0x9:  OK
LED 0xA:  open
LED 0xB:  disabled
LED 0xC:  disabled
LED 0xD:  disabled
LED 0xE:  disabled
LED 0xF:  disabled
LED 0x10:  OK
LED 0x11:  OK
LED 0x12:  OK
LED 0x13:  OK
LED 0x14:  OK
LED 0x15:  OK
LED 0x16:  OK
LED 0x17:  OK
LED 0x18:  OK
LED 0x19:  OK
LED 0x1A:  open
LED 0x1B:  disabled
LED 0x1C:  disabled
LED 0x1D:  disabled
LED 0x1E:  disabled
LED 0x1F:  disabled
LED 0x20:  OK
LED 0x21:  OK
LED 0x22:  OK
LED 0x23:  OK
LED 0x24:  OK
LED 0x25:  OK
LED 0x26:  OK
LED 0x27:  OK
LED 0x28:  OK
LED 0x29:  OK
LED 0x2A:  open
LED 0x2B:  disabled
LED 0x2C:  disabled
LED 0x2D:  disabled
LED 0x2E:  disabled
LED 0x2F:  disabled
LED 0x30:  OK
LED 0x31:  OK
LED 0x32:  OK
LED 0x33:  OK
LED 0x34:  OK
LED 0x35:  OK
LED 0x36:  OK
LED 0x37:  OK
LED 0x38:  OK
LED 0x39:  OK
LED 0x3A:  open
LED 0x3B:  disabled
LED 0x3C:  disabled
LED 0x3D:  disabled
LED 0x3E:  disabled
LED 0x3F:  disabled
LED 0x40:  OK
LED 0x41:  OK
LED 0x42:  OK
LED 0x43:  OK
LED 0x44:  OK
LED 0x45:  OK
LED 0x46:  OK
LED 0x47:  OK
LED 0x48:  OK
LED 0x49:  OK
LED 0x4A:  open
LED 0x4B:  disabled
LED 0x4C:  disabled
LED 0x4D:  disabled
LED 0x4E:  disabled
LED 0x4F:  disabled
LED 0x50:  OK
LED 0x51:  OK
LED 0x52:  OK
LED 0x53:  OK
LED 0x54:  OK
LED 0x55:  OK
LED 0x56:  OK
LED 0x57:  OK
LED 0x58:  OK
LED 0x59:  OK
LED 0x5A:  open
LED 0x5B:  disabled
LED 0x5C:  disabled
LED 0x5D:  disabled
LED 0x5E:  disabled
LED 0x5F:  disabled
LED 0x60:  OK
LED 0x61:  OK
LED 0x62:  OK
LED 0x63:  OK
LED 0x64:  OK
LED 0x65:  OK
LED 0x66:  OK
LED 0x67:  OK
LED 0x68:  OK
LED 0x69:  OK
LED 0x6A:  open
LED 0x6B:  disabled
LED 0x6C:  disabled
LED 0x6D:  disabled
LED 0x6E:  disabled
LED 0x6F:  disabled
LED 0x70:  OK
LED 0x71:  OK
LED 0x72:  OK
LED 0x73:  OK
LED 0x74:  OK
LED 0x75:  OK
LED 0x76:  OK
LED 0x77:  OK
LED 0x78:  OK
LED 0x79:  OK
LED 0x7A:  open
LED 0x7B:  disabled
LED 0x7C:  disabled
LED 0x7D:  disabled
LED 0x7E:  disabled
LED 0x7F:  disabled
LED 0x80:  OK
LED 0x81:  OK
LED 0x82:  OK
LED 0x83:  OK
LED 0x84:  OK
LED 0x85:  OK
LED 0x86:  OK
LED 0x87:  OK
LED 0x88:  OK
LED 0x89:  OK
LED 0x8A:  open
LED 0x8B:  disabled
LED 0x8C:  disabled
LED 0x8D:  disabled
LED 0x8E:  disabled
LED 0x8F:  disabled
LED 0x90:  OK
LED 0x91:  OK
LED 0x92:  OK
LED 0x93:  OK
LED 0x94:  OK
LED 0x95:  OK
LED 0x96:  OK
LED 0x97:  OK
LED 0x98:  OK
LED 0x99:  OK
LED 0x9A:  open
LED 0x9B:  disabled
LED 0x9C:  disabled
LED 0x9D:  disabled
LED 0x9E:  disabled
LED 0x9F:  disabled
LED 0xA0:  OK
LED 0xA1:  OK
LED 0xA2:  OK
LED 0xA3:  OK
LED 0xA4:  OK
LED 0xA5:  OK
LED 0xA6:  OK
LED 0xA7:  OK
LED 0xA8:  OK
LED 0xA9:  OK
LED 0xAA:  open
LED 0xAB:  disabled
LED 0xAC:  disabled
LED 0xAD:  disabled
LED 0xAE:  disabled
LED 0xAF:  disabled
LED 0xB0:  OK
LED 0xB1:  OK
LED 0xB2:  OK
LED 0xB3:  OK
LED 0xB4:  OK
LED 0xB5:  OK
LED 0xB6:  OK
LED 0xB7:  OK
LED 0xB8:  OK
LED 0xB9:  OK
LED 0xBA:  open
```

## Construction

![Breadboard](./assets/LedTest_bb.jpg?raw=true)

![Schematic](./assets/LedTest_schematic.jpg?raw=true)

![Build](./assets/LedTest_build.jpg?raw=true)

## Credits and References
* [LuckyResistor/LRAS1130](https://github.com/LuckyResistor/LRAS1130) - A library to control the AS1130 LED driver chip.
* [LEAP#299 TheMatrix](../TheMatrix)
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap300-the-matrix-led-test.html)
