# ElectretADC - convert electret signal to a full range analog input

Use an Arduino to read the amplified signal from an electret microphone.
## Notes

The electret microphone is biased to about 1V, and the AC component of the signal tapped via C1.

The microphone signal is then fed to the LM324 set for a non-inverting DC gain of 23.

    G = 1 + Ra1/Ra2 = 1 + 22/1 = 23

Although the LM324 is not particularly specialised for audio applications, it works OK for a quick test.
I'll probably redo this when I have an LM386 Low Voltage Audio Power Amplifier available.

The amplified signal is read by the Arduino and plotted with [PlotNValues (a simple Processing sketch)](../../processing/PlotNValues).


Here is a sample.
The lower trace is the mic signal presented to the non-inverting input,
the upper trace is the amplified signal output from the OpAmp:

![processing trace](./assets/processing_trace.png?raw=true)

### Construction

![The Breadboard](./assets/EElectretADC_bb.jpg?raw=true)

![The Schematic](./assets/ElectretADC_schematic.jpg?raw=true)

![The Build](./assets/ElectretADC_build.jpg?raw=true)

NB: for simplicity, the circuit is powered from the Arduino 5V pin.
That works fine, although it is equally possible to use a separate power supply (but ensuring there is a common ground connection).

## Credits and References
* [LM324 Datasheet](http://www.futurlec.com/Linear/LM324N.shtml)
