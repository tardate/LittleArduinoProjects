# ElectretTrigger - triggers a tone sequence when mic input over threshold

Use an Arduino to monitor the amplified signal from an electret microphone. When a threshold is exceeded,
plays a ditty on the piezo speaker.

Here's a quick video of the circuit in action:

[![ElectretTrigger](http://img.youtube.com/vi/ql-fEP85yUc/0.jpg)](http://www.youtube.com/watch?v=ql-fEP85yUc)

## Notes

The electret microphone is biased to about 1V, and the AC component of the signal tapped via C1.

The microphone signal is then fed to the LM324 set for a non-inverting DC gain of 23.

    G = 1 + Ra1/Ra2 = 1 + 22/1 = 23

Although the LM324 is not particularly specialised for audio applications, it works well enough here.

The amplified signal is read by the Arduino, and when the signal exceeds a threshold, the Arduino triggers a tune played on the pieze speaker.


### Construction

![The Breadboard](./assets/ElectretTrigger_bb.jpg?raw=true)

![The Schematic](./assets/ElectretTrigger_schematic.jpg?raw=true)

![The Build](./assets/ElectretTrigger_build.jpg?raw=true)

NB: for simplicity, the circuit is powered from the Arduino 5V pin.
That works fine, although it is equally possible to use a separate power supply (but ensuring there is a common ground connection).

## Credits and References
* [LM324 Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)
