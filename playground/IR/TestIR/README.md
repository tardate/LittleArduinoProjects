# #074 Raw Arduino Infrared

Tests raw IR reception.

## Notes

An exploration of IR Sensor reception based on the [adafruit sample code available here](https://learn.adafruit.com/ir-sensor/using-an-ir-sensor).

I've cleaned up the code a bit and modified it to optionally pump data out for plotting with [LEAP#090 PlotNValues (a simple Processing sketch)](https://leap.tardate.com/playground/plotnvalues/). This provides a simple graphical illustration of the PWM characteristics of IR protocols.

Here's a sample trace of the "0" key being pressed on a common MP3 player remote control:

![processing trace](./assets/mp3_key_0.png?raw=true)

And another showing an LG remote control "power on/off" key press:

![processing trace](./assets/LG_key_power.png?raw=true)

This all got me reading [IR Remote Control Theory](http://www.sbprojects.com/knowledge/ir/index.php) to better understand operation and protocols.
Next step is to start decoding the signals, however for that I might avoid re-inventing the wheel and instead try the [IRremote library](https://github.com/shirriff/Arduino-IRremote).

### Construction

![The Breadboard](./assets/TestIR_bb.jpg?raw=true)

![The Schematic](./assets/TestIR_schematic.jpg?raw=true)

![The Build](./assets/TestIR_build.jpg?raw=true)

## Credits and References

* [IR Remote Control Theory](http://www.sbprojects.com/knowledge/ir/index.php) - the best reference I've found so far for IR theory and also protocol details.
* [Using an IR Sensor](https://learn.adafruit.com/ir-sensor/using-an-ir-sensor) - a good IR tutorial that this project is based upon
* [TSOP1838 datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/26604/VISHAY/TSOP1838.html) - one of many similar IR sensors
* [Port Registers](http://www.arduino.cc/en/Reference/PortManipulation) - explains Arduino raw port methods
* [IRremote library](https://github.com/shirriff/Arduino-IRremote) - an IR library (not used here)
