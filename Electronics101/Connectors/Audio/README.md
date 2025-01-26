# #309 Audio Connectors

Notes on miscellaneous audio connectors.

![Audio_build](./assets/Audio_build.jpg?raw=true)

## Notes

Audio signals can be carried by any kind of connection, but there are some more commonly used standard connectors for audio applications.
This project is a collection of notes on some of the connectors I use/have encountered.

For more thorough coverage of the variety of audio connectors, see:

* Chapter 7 of John M. Hughes' [Practical Electronics: Components and Techniques](https://www.goodreads.com/book/show/21483234-practical-electronics).
* [Tech Basics: Cables & Connectors](https://www.udemy.com/tech101-cables-and-connectors/) - udemy course


### 3.5mm Connectors

Commonly used for analog audio.

![stereo_plug_3.5mm](./assets/stereo_plug_3.5mm.jpg?raw=true)

#### 3.5mm PCB-mount Stereo Socket

Example of a stereo socket with bypass. For this specific socket, pin arrangement is as below:

| Pin | Description                                                                |
|-----|----------------------------------------------------------------------------|
| 1   | Left                                                                       |
| 2   | Left bypass. Plug inserted: not connected; no plug: connected to LEFT(1)   |
| 3   | Right bypass. Plug inserted: not connected; no plug: connected to RIGHT(4) |
| 4   | Right                                                                      |
| 5   | Common/ground                                                              |

![stereo_socket_3.5mm](./assets/stereo_socket_3.5mm.jpg?raw=true)


### 6.35mm (1/4") Connectors

Primarily used for instruments, mono and stereo.

![6.35mm](./assets/6.35mm.jpg?raw=true)


### RCA/Phono

Commonly used for analog audio and video.

![rca_socket](./assets/rca_socket.jpg?raw=true)

### XLR

* shielded audio
* professional audio
* snake - multiple XLR connectors in one bundle


### Audio Adapters

e.g.

* RCA to 3.5mm plug
* XLR to RCA
* adapter packages

## Credits and References

* [Practical Electronics: Components and Techniques](https://www.goodreads.com/book/show/21483234-practical-electronics)
* [Tech Basics: Cables & Connectors](https://www.udemy.com/tech101-cables-and-connectors/) - udemy course
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap309-audio-connectors.html)
