# #193 PovShakeStickKit

Build and investigate an AT89S52-based "shake stick" kit

![PovShakeStickKit_build](./assets/PovShakeStickKit_build.jpg?raw=true)

![PovShakeStickKit_demo](./assets/PovShakeStickKit_demo.jpg?raw=true)


[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I picked up a [PoV shake-stick kit](http://www.aliexpress.com/item/LDE-Shake-Stick-Flash-Stick-AT89S52-DIY-Kit-Magic-Wand-Blank-PCB-board/32496601767.html) for a few dollars recently. I'm interested in doing some persistence-of-vision projects,
so I was intrigued to find out how this one worked. I'd seen some articles - like
[Matthew Norman's blog post](http://mattnorman.co.uk/2015/Flash-Stick-AT89S52-DIY-Kit-Magic-Wand-review/) -
on the kit but nothing that really got down to the inner workings.

Building the kit is very simple.
The AT89S52 comes pre-programmed, and it only took about half an hour build the kit.
It worked perfectly straight off the bat.

Then for the fun part - sleuthing out it's provenance and internals..

### Origins

Things started to get interesting when I found [this archive](http://pan.baidu.com/share/link?shareid=532839&uk=1161248057).

If I can trust it as original work - and it does seem so - then it is the documentation and code from a student project
that appears to be the first prototype of what eventually has turned up on many online sites as a standard kit.

The project was by Zheng Zhong Xing 兴向荣 (aka zhengzhongxing39) studying Control Technology and Instruments/Principles and Applications
at a Chinese University (though I can't tell which one). Dates are ambiguous - the initial project may have been in 2009, and work on the sources revisited in 2012/2013. It's pure conjecture, but perhaps 兴向荣 dusted off the project after completing Uni to help kick-start a business.

The write-up is fascinating (and funny); I can picture a hard-working student persevering when all manner of things going wrong,
while battling unreasonable school expectations and schedules.
To translate and paraphrase some choice phrases:
* "Since unfamiliar and having no experience with drawing software application  ... beginning was a big ugly mess" (drawing the "fonts")
* "... soldering was troublesome, with lots of changes and no solid basic skills, so burned out the first board"
* "regardless of the teachers strongly recommending assembly language, I used C language" (since studied in earlier course)

Some of the specific design decisions and changes made along the way:
* initial tests with Mercury switches were not that good because they would sieze or otherwise fail. Replaced with a [vibration switch like this component]([Vibration switch Shock vibration sensor Shaked switch Shaked stick Skates (G1A3)](http://www.aliexpress.com/item/Vibration-switch-Shock-vibration-sensor-Shaked-switch-Shaked-stick-Skates-G1A3/1898867376.html?spm=2114.01010208.8.5.VTwjvL)), which is what appears in the kits for sale. The original Mercury switch mount remains in the PCB design however;-)
* experiemented with various power supplies. It's now 3V (2xAAA) in the kit.
* uses the AT89S52 processor, programmed using Keil C51 compiler. The PCB retains an ICSP header for re-programming.

Hats off to 兴向荣 for carrying the project through to successful demonstration.
I can't remember producing anything as "finished" when I was at Uni!

At it seems he/she went on to commercialise the project and start an electronics business - you can find this kit and many others in the
[兴向荣电子 taobao store](https://792758921.world.taobao.com/shop/view_shop.htm?user_number_id=155126737), which appears to have been founded by zhengzhongxing39.

### So how does the PoV work?

It's quite simple:

* the vibration switch triggers an interrupt handler on INT0 as the stick is waved back and forth
* it ignores every second interrupt i.e. triggers in only one direction
* the interrupt triggers the display of the words/graphic with a delay between each column of data
* the main loop scans for the display selector switch input - when clicked, it cycles to the next messages for display.

I've translated and expanded the operating details in one of the example source files in [annotated_source.c](./annotated_source.c).
The source is not identical to that pre-loaded in my kit (it has some different display patterns).

The interrupt handling is identical to Keil's [8051 /INT0 External Interrupt Example Program](http://www.keil.com/download/docs/188.asp).

Here's what it looks like displaying a heart (my photo/my stick!):

![PovShakeStickKit_demo](./assets/PovShakeStickKit_demo.jpg?raw=true)

### Construction

Here's my transcription of the circuit. The subsystems break down quite simply:
* power supply and power indicator LED
* 16 LEDs in common-anode configuration are directly driven by the microcontroller.
* A 1N4007 diode on the anode steps down the voltage for the LEDs, obviating the need for current-limiting resistors.
* S3 pulls down P3.7 and is used to switch the words/image being displayed
* a gyro vibration switch triggers INT0 on P3.2 and is used to synchronise the PoV display (as you wave it back and forth)
* an Atmel AT89S52 (on a 12MHz crystal) runs the program. 'nuff said!

![The Schematic](./assets/PovShakeStickKit_schematic.jpg?raw=true)

![PovShakeStickKit_parts](./assets/PovShakeStickKit_parts.jpg?raw=true)

![The Build](./assets/PovShakeStickKit_build.jpg?raw=true)

## Credits and References
* [LDE Shake Stick Flash Stick AT89S52 DIY Kit Magic Wand Blank PCB board](http://www.aliexpress.com/item/LDE-Shake-Stick-Flash-Stick-AT89S52-DIY-Kit-Magic-Wand-Blank-PCB-board/32496601767.html) - where I sourced the kit
* [兴向荣电子 taobao store](https://792758921.world.taobao.com/shop/view_shop.htm?user_number_id=155126737) - I think the store of the original author where this kit and others are available
* [Shake stick - Persistence of vision wand kit](http://mattnorman.co.uk/2015/Flash-Stick-AT89S52-DIY-Kit-Magic-Wand-review/) - Matthew Norman's review of the same/similar kit
* [source code & project docs](http://pan.baidu.com/share/link?shareid=532839&uk=1161248057) - appears to be an archive of the original project
* [Atmel AT89S52](http://www.atmel.com/devices/at89s52.aspx) - product info and datasheets
* [Atmel 8051 Microcontrollers Hardware Manual](http://www.atmel.com/Images/doc4316.pdf)
* [Keil development tools for the 8051 Microcontroller Architecture](http://www.keil.com/c51/)
* [8051 /INT0 External Interrupt Example Program](http://www.keil.com/download/docs/188.asp)
* [Vibration switch Shock vibration sensor Shaked switch Shaked stick Skates (G1A3)](http://www.aliexpress.com/item/Vibration-switch-Shock-vibration-sensor-Shaked-switch-Shaked-stick-Skates-G1A3/1898867376.html?spm=2114.01010208.8.5.VTwjvL) - example of the part used as movement input for the shake stick
* [..as mentioned on my blog](https://blog.tardate.com/2016/03/littlearduinoprojects193-pov-led-shake.html)
