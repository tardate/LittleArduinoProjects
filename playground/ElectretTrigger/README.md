# ElectretTrigger - triggers a tone sequence when mic input over threshold

Use an Arduino to monitor the amplified signal from an electret microphone. When a threshold is exceeded,
plays a ditty on the piezo speaker.

Here's a quick video of the circuit in action:

[![ElectretTrigger](http://img.youtube.com/vi/ql-fEP85yUc/0.jpg)](http://www.youtube.com/watch?v=ql-fEP85yUc)

## Notes

The electret microphone is biased to about 1V, and the AC component of the signal tapped via C1.

The microphone signal is then fed to the LM324 setup as a subtracting amplifier:

* positive input is set to Vcc/2 = 2.5V
* microphone signal fed to negative input

    Vo = G1 * Vmic + G2 * Vcc
    G1 = -R2/R1 = -330kΩ/2.2kΩ = -150
    G2 = (R1 + R2)/R1 * R4/(R3 + R4) = (2.2kΩ + 330kΩ)/2.2kΩ * 22kΩ/(22kΩ + 22kΩ) = 75.5

When no microphone signal, we are
[reading Vcc/2](http://www.wolframalpha.com/input/?i=5*%282.2k%CE%A9+%2B+330k%CE%A9%29%2F2.2k%CE%A9+*+22k%CE%A9%2F%2822k%CE%A9+%2B+22k%CE%A9%29+-+2.5+*330k%CE%A9%2F2.2k%CE%A9)
at the output.

But it is really sensitive to changes in the microphone signal. Basically every
[1mV results in a 150mV change in the output](http://www.wolframalpha.com/input/?i=0.001+*330k%CE%A9%2F2.2k%CE%A9).

The amplified signal is read by the Arduino, and when the signal exceeds a threshold, the Arduino triggers a tune played on the piezo speaker.

Other amplifier configurations are possible. For example the [ElectretADC](../ElectretADC) demo uses a non-inverting amplifier configuration.

### Construction

![The Breadboard](./assets/ElectretTrigger_bb.jpg?raw=true)

![The Schematic](./assets/ElectretTrigger_schematic.jpg?raw=true)

![The Build](./assets/ElectretTrigger_build.jpg?raw=true)

NB: for simplicity, the circuit is powered from the Arduino 5V pin.
That works fine, although it is equally possible to use a separate power supply (but ensuring there is a common ground connection).

## Credits and References
* [LM324 Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)
