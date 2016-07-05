# #212 StayCreative

Audio level VU meter driving a custom LED sign.

Here's a quick video of it in action:

[![StayCreative](http://img.youtube.com/vi/lfrAL8ZSpl4/0.jpg)](http://www.youtube.com/watch?v=lfrAL8ZSpl4)

## Notes

A simple project inspired by [Make your own LED Sign VU Meter by GreatScott!](https://youtu.be/Jyrpx9rEGMI).
The catch-phrase should be familiar if you subscribe to his channel;-)

It's a VU meter, but rather than doing the "bar graph" thing à la LM3915, it pulses the intensity of all LEDs
to the volume of the incoming audio.

### Audio Input

Consists of a standard electret biasing ciruit. The AC signal via 1µF ceramic
feeds through an adjustable passive attenuator (22kΩ | 100kΩ pot) to the amplifier stage.

The audio signal is amplified with an LM358 in non-inverting amplifier configuration with a hefty 330x gain.
This means I can get good dynamic range even with weak input signals.

### LED power supply

Power for the LEDs is provided with a
[simple buck converter module](https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BuckConverterModules#module-1)
dialed in at ~3V, which is around the nominal forward voltage of the blue LEDs I'm using.

LED brightness control is enabled with an n-channel MOSFET on the common cathode connection of the LEDs.
At first I though I might need some serious juice, and was going to use an IRF540N which can handle many amps.
But it turns out that the current draw is about 50mA with all the LEDs fully on so I ended up using a 2N7000 instead.

## Construction

![Breadboard](./assets/StayCreative_bb.jpg?raw=true)

![The Schematic](./assets/StayCreative_schematic.jpg?raw=true)

![The Build](./assets/StayCreative_build.jpg?raw=true)

![StayCreative_layout](./assets/StayCreative_layout.jpg?raw=true)

## Credits and References
* [2N7000 datasheet](url) n-channel MOSFET
* [LM358N Datasheet](http://www.futurlec.com/Linear/LM358N.shtml)
* [IRF540N datasheet](url) n-channel MOSFET
* [Make your own LED Sign VU Meter by GreatScott!](https://youtu.be/Jyrpx9rEGMI)
* [BuckConverter Module](https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/BuckConverterModules#module-1)
* [..as mentioned on my blog](http://blog.tardate.com/2016/07/littlearduinoprojects212-stay-creative.html)
