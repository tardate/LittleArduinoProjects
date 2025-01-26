# #012 Capacitorial - Graphing Capacitor Discharge

Use an Arduino to charge a capacitor and graph the discharge with [Processing](https://www.processing.org).

Here's a quick video of the circuit in action:

[![Capacitor discharge graphs with Arduino and Processing](https://img.youtube.com/vi/hmDOkpburF8/0.jpg)](https://www.youtube.com/watch?v=hmDOkpburF8)


## Notes

The circuit uses a digital output pin to charge the capacitor.
When the pin is brought low, the LED will be powered by the capacitor discharge (through a current-limiting resistor). A diode prevents the discharge from being fed back into the digital output pin.

The voltage at the positive terminal of the capacitor is read with an analog input pin, with the value echoed to the Arduino serial port.

[Grapher (a simple Processing sketch)](./Grapher) reads the data from the serial port and plots the value over time, with some coloration effects thrown in for good measure. In other words, we're using Arduino and Processing as a basic oscilloscope! And it kind of works, mainly because the frequency is so low.

![The Breadboard Schematic](./assets/Capacitorial_bb.jpg?raw=true)

![The Build](./assets/Capacitorial_build.jpg?raw=true)

### Varying the capacitance

Varying the capacitance will affect the storage potential and discharge rate.

#### 47uF
At 47uF, the capacitor is given enough time to fully charge (note the plateau), and discharge is very rapid.
![47uF](./assets/47uF.png?raw=true)

#### 470uF
![470uF](./assets/470uF.png?raw=true)

#### 1000uF
![1000uF](./assets/1000uF.png?raw=true)

## Credits and References

* [Download Processing](https://www.processing.org/download/)
* [How to Use a Charged Capacitor to Light an LED](http://www.learningaboutelectronics.com/Articles/How-to-use-a-charged-capacitor-to-light-an-led)
* ["Most basic capacitor circuit." from the arduino forum](http://forum.arduino.cc/index.php?topic=52838.0)
