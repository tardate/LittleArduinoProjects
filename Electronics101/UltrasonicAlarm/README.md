# #287 Ultrasonic Alarm

Build an ultrasonic motion alarm with the HC-SR04 module and discrete logic.

Here's a quick demo of it in action:

[![Build](./assets/UltrasonicAlarm_build.jpg?raw=true)](https://www.youtube.com/watch?v=18vaX6bmDes)

## Notes

The HC-SR04 Ultrasonic Ranging Module is commonly used with a microcontroller for obstacle detection and other autonomous control functions.

But that doesn't mean it can't be used in circuits that lack a processor.
Silicon Chip featured an article by Jim Rowe in the Dec-2016 edition that described
[Using An Ultrasonic Sensor Module As A Door Sentry](http://www.siliconchip.com.au/Issue/2016/December/Using+An+Ultrasonic+Sensor+Module+As+A+Door+Sentry).

It's quite ingenious:

* a free-running inverter-based oscillator provides a steady stream of trigger pulses
* echo pulse triggers a 555 timer monostable
* the 555 timer produces a calibration pulse, duration is set by R5 potentiometer
* the XOR compares the echo pulse with the calibration pulse and goes high when these are different: a pulse-width comparator

How it's used:

* place the unit, and adjust the calibration pulse timing for a null output
* then whenever anything increases of decreases the distance measurement, the alarm goes off

This project is my adaptation of the Silicon Chip article. It includes some simplification and component replacements.

### HC-SR04 Basics

The HC-SR04 is a pretty smart and independent module, with a very simple control interface.

* to trigger a range test, send a Trigger TTL pulse >10µs
* the unit runs the test independently
* echo pulse is produced, with a duration that is proportional to the distance. Distance = (high level time × velocity of sound)/2

Note there is no explicit relationship between when the trigger pulse is sent and when the echo pulse is returned.
They can be treated independently.

The module uses TCT40-16T "air ultrasonic ceramic transducers" that operate at 40kHz.

### Trigger Signal

The 74LS14 schmitt inverter is used as a free-running oscillator. The LS variant I'm using here is not great with high resistance values
in an oscillator configuration - see [LEAP#022 SchmittOscillator](../Oscillators/SchmittOscillator) for more.

So I've beefed up the capacitor to 10µF and fiddled the resistors to produce an
[80Hz](https://www.wolframalpha.com/input/?i=2%2F((1.2+*+10%C2%B5F+*+1.2k%CE%A9)+%2B+(1.2+*+10%C2%B5F+*+890%CE%A9)))
trigger pulse with a high time just under 1ms.

* when inverter output low, R = 1.2kΩ
* when inverter output high, R = 890Ω (1.2kΩ in parallel to diode + 220Ω; actual measured resistance)

Here's a scope trace of the trigger signal (CH1) and the echo (CH2)

![scope-trig-echo](./assets/scope-trig-echo.gif?raw=true)

### Calibration Pulse

A 555 timer in monostable mode is used to generate the calibration pulse.

It is triggered by the echo pulse, which is first inverted in one unit of the 74LS14.
The C2/R3 filter integrates the pulse to produce a sharp trigger, with D2 sinking any positive spike.

The 555 produce a pulse with a duration controlled by the R5 potentiometer.
The values I've selected provide for a calibration range:

* min [1.1ms](https://visual555.tardate.com/?mode=monostable&r1=10&c=0.1) -  a distance of [18cm](https://www.wolframalpha.com/input/?i=0.0011+*+340%2F2)
* max [12.1ms](https://visual555.tardate.com/?mode=monostable&r1=110&c=0.1) - a distance of [205cm](https://www.wolframalpha.com/input/?i=0.0121+*+340%2F2)

In order to calibrate for different ranges, C3 (or the resistors) can be substituted as appropriate.

### Pulse Width Comparator

The echo signal and the 555-generated calibration pulse are XORed with the CD4070. This results in an output that is:

* logical 0 when the signals are in phase
* logical 1 when the signals are out of phase. This can be one of two cases:
    * the echo pulse is shorter than the calibration pulse (meaning something has come closer to the HC-SR04)
    * the echo pulse is longer than the calibration pulse (meaning something has come moved away from the HC-SR04)

### "Alarm" Circuit

The circuit includes an LED and piezo buzzer indicator when the echo/calibration pulses are out of whack.
The LED and buzzer are switched with a simple low-side n-channel MOSFET.

The output of the Pulse Width Comparator is dampened with an RC filter.
In my build I replaced the more complicated arrangement from the Silicon Chip article with a simple 100nF/1kΩ
circuit, with a resulting time constant of [0.1ms](https://www.wolframalpha.com/input/?i=100nF+*+1k%CE%A9).
This squelches incidental noise, and also provides a little tolerance with slightly wandering echo readings.

The 100Ω R8 is not particularly necessary and doesn't alter the function of the circuit.
It may provide some protection for the FET.

### Performance

The circuit performs pretty well! Here are some scope traces with

* CH1 (Yellow) - Echo pulse
* CH2 (Blue) - 555 reset pulse
* CH3 (Red) - 555 output / comparator
* CH4 (Green) - output control signal

**Balanced Calibration - no alarm**
![scope-calibrated](./assets/scope-calibrated.gif?raw=true)

**Near object Alarm**
![scope-triggered-near](./assets/scope-triggered-near.gif?raw=true)

**Far object Alarm**
![scope-triggered-far](./assets/scope-triggered-far.gif?raw=true)

## Construction - Breadboard Prototype

![Breadboard](./assets/UltrasonicAlarm_bb.jpg?raw=true)

![Schematic](./assets/UltrasonicAlarm_schematic.jpg?raw=true)

![UltrasonicAlarm_bb_build](./assets/UltrasonicAlarm_bb_build.jpg?raw=true)

## Construction - Put it in a Box

So this works quite well, so I decided to put it on protoboard in a box.

Here's the layout and construction concept.
I've added a 7805 5V regulator with 100µF and 100nF smoothing capacitors so I can power the circuit from a 9V battery.

![UltrasonicAlarm_protoboard_layout](./assets/UltrasonicAlarm_protoboard_layout.jpg?raw=true)

![UltrasonicAlarm_protoboard_wip](./assets/UltrasonicAlarm_protoboard_wip.jpg?raw=true)

Finished:

![UltrasonicAlarm_build](./assets/UltrasonicAlarm_build.jpg?raw=true)

## Credits and References

* [HC-SR04 Datasheet](http://www.micropik.com/PDF/HCSR04.pdf)
* [74LS14 Datasheet](https://www.futurlec.com/74LS/74LS14.shtml)
* [LM555 Datasheet](https://www.futurlec.com/Linear/LM555CN.shtml)
* [CD4070 Datasheet](https://www.futurlec.com/4000Series/CD4070.shtml)
* [Using An Ultrasonic Sensor Module As A Door Sentry](http://www.siliconchip.com.au/Issue/2016/December/Using+An+Ultrasonic+Sensor+Module+As+A+Door+Sentry) - Silicon Chip Dec-2016
* [..as mentioned on my blog](https://blog.tardate.com/2017/05/leap287-ultrasonic-alarm.html)
