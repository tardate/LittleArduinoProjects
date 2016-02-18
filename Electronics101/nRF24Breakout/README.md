# #176 nRF24Breakout

A simple PCB breadboard adapter for 8-pin nRF24 modules

![Build](./assets/nRF24Breakout_build.jpg?raw=true)

## Notes

This is my version of project 1 from the
[KiCad like a Pro](http://txplore.tv/courses/kicad-pro)
course from Tech Explorations.

It's about as simple as it gets - my main objective here is to try out the process
of sending PCB design to a small-quantity production fab.
I got interested in doing this after [seeing this hangout](https://www.youtube.com/watch?v=XssjD97-xGM) with the
founder of OSH Park.

The PCB design was done with [KiCad](http://kicad-pcb.org/).

I sent these off for production at [OSH Park](https://oshpark.com/shared_projects/Js6JrEyC), and they arrived (in Singapore) a month later (Jan 17th -> Feb 17th). They turned out quite well, certainly no issues with the fab. I'll be using these for some nRF24 projects.

After examining the PCBs, I can see a few things that could be improved in the design:
* the font size I used for pin labelling is just barely large enough to read
* I didn't allow space between the 2x4 pin header and the pin labels (with the pin adapter installed, the labels are partially obscured)
* the board size does not match the nRF24 unit very well (the module overlaps the edge of the board). I think the module might be better rotated 90˚.

See [nRF24/PingPong](../playground/nRF24/PingPong), my first shot at using the adapters for real. They worked great!

## Construction

See the [KiCad project](./kicad_project/nrf24_breakout.pro) for all the details. Here's the result:

![The Schematic](./assets/nRF24Breakout_schematic.png?raw=true)

![PCB](./assets/nRF24Breakout_pcb.png?raw=true)

![PCB render](./assets/nRF24Breakout_pcb_render.png?raw=true)

![Build](./assets/nRF24Breakout_build.jpg?raw=true)

## Credits and References
* [KiCad like a Pro](http://txplore.tv/courses/kicad-pro) - course materials
* [This nRF24Breakout project on OSH Park](https://oshpark.com/shared_projects/Js6JrEyC)
* [KiCad](http://kicad-pcb.org/)
* [gerblook](http://gerblook.org/) - nice tool for testing a set of gerber files
* [OSH Park](https://oshpark.com/)
* [HARDWARE HANGOUT with James "Laen" Neal from OSH Park!](https://www.youtube.com/watch?v=XssjD97-xGM) - where I first learned of OSH Park
* [..as mentioned on my blog](http://blog.tardate.com/2016/02/littlearduinoprojects176-nrf24-breakout.html)
