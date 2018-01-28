# #020 Internals

This is an investigation of all the internal details of the Arduino Board from a programming perspective.
Results are dumped to the serial port.


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

Here's typical output (from an Arduino Uno):

![console log](./assets/console_log.png?raw=true)

## Credits and References

* Chapter 17. Advanced Coding and Memory Handling - [Arduino Cookbook](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU)
* [A Tour of Arduino Internals](http://urbanhonking.com/ideasfordozens/2009/05/18/an_tour_of_the_arduino_interna/) - interesting blog post disecting how pin operations actually interact with the AVR microcontroller
