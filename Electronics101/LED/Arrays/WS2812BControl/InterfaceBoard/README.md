# #xxx UART-TTL to LED Array Interface Board

Building a simple interface board for connecting a CH340-based UART-TTL adapter to an WS2811 or WS2812B LED strip.

![Build](./assets/InterfaceBoard_build.jpg?raw=true)

## Notes

In [LEAP#868 LED Array Control from macOS](../)
I played with controlling a string of WS2811 or WS2812B LEDs from macOS through a CH340-based UART-TTL adapter.

In these notes, I throw the connecting circuitry on a small protoboard for convenience.

### Circuit Design

A simple board featuring:

* 5V power supply connector
* power decoupling capacitor
* TTL (active-low) to WS28xx (active-high) logic inverter

Designed with Fritzing: see [Adapter.fzz](./Adapter.fzz).

![bb](./assets/InterfaceBoard_bb.jpg?raw=true)

![schematic](./assets/InterfaceBoard_schematic.jpg?raw=true)

### Construction

A simple layout on a small piece of protoboard:

![InterfaceBoard_board_build](./assets/InterfaceBoard_board_build.jpg?raw=true)

![InterfaceBoard_board_test](./assets/InterfaceBoard_board_test.jpg?raw=true)

### Final Test

Sending a GRB sequence to the first 6 LEDs in a WS2812B strip:

```sh
$ echo "00FF0000 00FF00 0000FF FF0000 00FF00 0000FF" | ../ws2812bify.py -p /dev/cu.usbserial-2420
Sending data to /dev/cu.usbserial-2420 at 2500000 baud...
```

![InterfaceBoard_test](./assets/InterfaceBoard_test.jpg?raw=true)

## Credits and References

* [LEAP#868 LED Array Control from macOS](../)
* [2N7000 datasheet](https://www.futurlec.com/Transistors/2N7000.shtml)
