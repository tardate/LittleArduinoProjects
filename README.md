# 149 Little Arduino Projects

* Latest addition - [AD9833/BasicDemoCycle](./playground/AD9833/BasicDemoCycle) - run a basic waveform demo with an AD9833 module.

Just my collection of electronics projects, many involving an Arduino in one way or another.
Some are full builds like
[The FretBoard](./FretBoard) (a multi-project build status indicator),
while most are quite trivial breadboard kata, intended to test or explore a single idea.

Many are variations of things found wild on the net, or inspired by ideas from the sources such as:

* [Arduino StackExchange](http://arduino.stackexchange.com/)
* [Electrical Engineering StackExchange](http://electronics.stackexchange.com/)
* [Arduino Playground](http://playground.arduino.cc/)
* [Arduino Cookbook (O'Reilly)](http://www.amazon.com/gp/product/1449313876/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1449313876&linkCode=as2&tag=itsaprli-20&linkId=5F6YF3D5RCEZYXUU)
* and other books from [my electronics bookshelf](http://www.bookjetty.com/pratalife/electronics)

Feel free to borrow liberally, and if you spot any issues do let me know. See the individual projects for credits where due.

### Other Bits

* [Custom Fritzing Parts](./FritzingParts) - Most projects have a circuit schematic drawn with the wonderful [Fritzing](http://fritzing.org/home/) application. But often I needed a non-standard part for the diagram. Here they are.
* [PlotNValues](./processing/PlotNValues) - a [Processing](https://www.processing.org/download/) script that reads 1..n values from the serial port and plots on stacked charts. I've often used this as a super-low-rent stand-in for an oscilliscope.

## The Project Index

| Project                                                                       | Category/Description                                              |
|-------------------------------------------------------------------------------|-------------------------------------------------------------------|
| [AD9833/BasicDemoCycle](./playground/AD9833/BasicDemoCycle)                   | **Arduino, Oscillators**        run a basic waveform demo with an AD9833 module |
| [AMFMRadioKit](./Electronics101/AMFMRadioKit)                                 | **RF**                          notes on an AM/FM radio kit build |
| [AM/OpAmpTransmitter](./Electronics101/AM/OpAmpTransmitter)                   | **RF, OpAmp**                   simple AM transmitter with OpAmp carrier/mixer |
| [AMTransmitter/555](./Electronics101/555Timer/AMTransmitter)                  | **RF, 555 Timer**               a simple 555-based AM transmitter |
| [AnalogComparator](./playground/AnalogComparator)                             | **Arduino, Sensor, OpAmp**      test the Atmega328 built-in analog comparator |
| [Arduino Internals](./playground/Internals)                                   | **Arduino**                     report on Arduino Board internals |
| [ArdWinVaders](./playground/OLED/ArdWinVaders)                                | **Arduino, OLED**               an Arduino & OLED version of a classic game |
| [ATmegaBreadboard](./playground/ATmegaBreadboard)                             | **Arduino, ATmel**              running an ATMEGA328P-PU on a breadboard  |
| [ATmegaISPShield](./playground/ATmegaISPShield)                               | **Arduino, ATmel**              a DIY ATmega programming shield for using an Arduino as ISP  |
| [ATmegaViaArduinoISP](./playground/ATmegaViaArduinoISP)                       | **Arduino, ATmel**              Programming an ATMEGA328P-PU on a breadboard with Arduino ISP |
| [ATtinyHardwareInterrupt](./playground/ATtinyHardwareInterrupt)               | **Arduino, ATmel**              test hardware interrupts with an ATtiny85 processor on a breadboard |
| [ATtinyWithArduinoISP](./playground/ATtinyWithArduinoISP)                     | **Arduino, ATmel**              Programming an ATTINY85-20PU on a breadboard with Arduino ISP |
| [ATtinySleep](./playground/ATtinySleep)                                       | **Arduino, ATmel**              test sleep mode with an ATtiny85 processor on a breadboard
| [ATtinyTotalSleep](./playground/ATtinyTotalSleep)                             | **Arduino, ATmel**              test a total power shutdown with an ATtiny85 processor on a breadboard |
| [AsyncLedStripEffects](./LEDArrayDemos/AsyncLedStripEffects)                  | **LED Array, Timing, Arduino**  demo effects on the LED strip driven using timer interrupt |
| [BidirectionalLevelShifter](./Electronics101/BidirectionalLevelShifter)       | **FET**                         test a basic bi-directional 5/3.3V level shifter circuit |
| [BidirectionalLevelShifterModule](./Electronics101/BidirectionalLevelShifterModule)| **FET**                    test a bi-directional 5/3.3V level shifter module |
| [BJTCurrentSink](./Electronics101/BJTCurrentSink)                             | **BJT, Power**                  test a BJT constant current sink circuit |
| [BJTLongTailPair](./Electronics101/BJTLongTailPair)                           | **BJT, OpAmp**                  test the basic BJT "long-tail" differential amplifier circuit |
| [BJTMonostable](./Electronics101/BJTMonostable)                               | **BJT, RC**                     test a 2-transistor monostable multivibrator |
| [BJTSawTooth](./Electronics101/BJTSawTooth)                                   | **BJT, Oscillators**            testing a simple BJT saw-tooth oscillator |
| [BJTZenerModeEffects](./Electronics101/BJTZenerModeEffects)                   | **BJT, Zener, Oscillators**     playing around with some zener-mode sound effects |
| [Blink](./playground/Blink)                                                   | **LED, Arduino**                the simplest blinking LED, with some electrical measurements thrown in |
| [BlinkPrecision](./playground/BlinkPrecision)                                 | **LED, Timing, Arduino**        use a timer to perform a function on a precise schedule |
| [BreatheLamp](./Electronics101/BreatheLamp)                                   | **OpAmp, LED**                  build and test a common LED visual effect circuit |
| [CapacitanceTester](./Electronics101/CapacitanceTester)                       | **LCD, RC, Arduino**            capacitor tester with LCD output |
| [Capacitorial](./Electronics101/Capacitorial)                                 | **RC**                          graphing capacitor discharge with Processing |
| [Comparator741](./Electronics101/Comparator741)                               | **OpAmp**                       demo LM741 OpAmp comparator mode (with PWM-to-analog side-topic) |
| [CounterModule](./playground/CounterModule)                                   | **CMOS, Arduino**               a general-purpose CD4017 counter module |
| [CrystalTester](./Electronics101/CrystalTester)                               | **RF, Oscillators**             a Colpitts Oscillator circuit for testing crystal oscillators with a frequency counter |
| [DarlingtonTouchSwitch](./Electronics101/DarlingtonTouchSwitch)               | **Sensors, BJT**                test a Darlington-pair touch switch |
| [DiodeLogic/AND](./Electronics101/DiodeLogic/AND)                             | **Diode, Logic Gates**          test the basic diode-logic AND gate |
| [DiodeLogic/OR](./Electronics101/DiodeLogic/OR)                               | **Diode, Logic Gates**          test the basic diode-logic OR gate |
| [El Jarabe Tapatío](./playground/JarabeTapatio)                               | **Audio, Arduino**              play The Mexican Hat Dance on a piezo buzzer with LM 386 amplification |
| [ElectretADC](./playground/ElectretADC)                                       | **Audio, Arduino**              convert electret signal to a full range analog input with an LM324 preamp and plot the raw and aplified signals |
| [ElectretTrigger](./playground/ElectretTrigger)                               | **Sensors, Audio, OpAmp, Arduino** uses an electret microphone and LM324 amplifier to trigger action when over audio threshold |
| [ElectronicClockKit](./Electronics101/ElectronicClockKit)                     | **LCD, Kit**                    build and investigate a commercially available "electronic clock" kit |
| [MobileRFDetectorKit](./Electronics101/EMRDetection/MobileRFDetectorKit)      | **RF**                          build and investigate a commercially available "mobile phone signal" detector kit |
| [FunctionGenerator324](./Electronics101/FunctionGenerator324)                 | **OpAmp, Oscillators**          LM324 configured as a low-frequency square, triangle, sine, and cosine function generator |
| [FretBoard](./FretBoard)                                                      | **LED Array, Arduino**          a multi-project build status indicator, that pulls software build status from the net and animates the status of up to 24 projects with an LED array |
| [Gates - RS Flip Flop](./Electronics101/RSFlipFlop)                           | **Logic Gates, BJT**            Set/Reset flip-flop with BJTs |
| [Gates - RS Flip Flop with Arduino](./Electronics101/RSFlipFlopFlipper)       | **Logic Gates, BJT, Arduino**   Set/Reset flip-flop with BJTs, under Arduino control and monitoring |
| [Gates - RS Flip Flop/NOR Latch](./Electronics101/RSFlipFlop_NORLatch)        | **Logic Gates, 74xx TTL**       Set/Reset flip-flop implemented with NOR gates |
| [Girabot](./Girabot)                                                          | **Sensors, OpAmp, Arduino**     EE40LX Electronic Interfaces robot project |
| [GuitarHeadphoneAmp](./Electronics101/AudioAmps/GuitarHeadphoneAmp)           | **OpAmp, Audio**                an LM386 fixed-gain guitar headphone amp |
| [HeartQuotes](./playground/HeartQuotes)                                       | **LCD, Ethernet, Arduino**      press a button to get a quote from the net and display on an LCD |
| [HighFrequencyOpAmpOscillators](./Electronics101/HighFrequencyOpAmpOscillators) |**OpAmp, Oscillators**         how fast can you push an Op-Amp oscillator? |
| [HitTheLights](./playground/HitTheLights)                                     | **LCD, Human Input, Arduino**   simple LED game with LCD output and interrupt-driven button input |
| [InvertingChargePump](./Electronics101/555Timer/InvertingChargePump)          | **555 Timer, Power**            test an inverting charge pump circuit based on a 555 timer |
| [It's Better With Bacon](./playground/BetterWithBacon)                        | **LCD, Arduino**                simple LCD test |
| [JoystickServoControl](./playground/JoystickServoControl)                     | **Human Input, Arduino**        controlling two servos with a joystick |
| [Lcd5110/BareBack](./playground/Lcd5110/BareBack)                             | **LCD, Arduino**                driving a Nokia 5110 LCD Display with an Arduino and the raw command set |
| [Lcd5110/JuliansU8glibDemo](./playground/Lcd5110/JuliansU8glibDemo)           | **LCD, Arduino**                quick test drive of Julian Ilett's 5110 LCD demo with the u8glib library |
| [LedControlDemo](./playground/LED8x8/LedControlDemo)                          | **8x8 LED, Arduino**            test driving and LED matrix with the LedControl library |
| [LDRComparator](./Electronics101/LDRComparator)                               | **Sensors, OpAmp, Arduino**     low-light/proximity Trip Detector demonstration using LM324 and LDR/Wheatstone Bridge sensor |
| [LDRStereoTripDetector](./Electronics101/LDRStereoTripDetector)               | **OpAmp**                       demo LM324 OpAmp as threshold trigger for stereo LDR/Wheatstone Bridge sensor |
| [Led4Digit7Segment](./playground/Led4Digit7Segment)                           | **7-Segment, Arduino**          overview of driving a 4-digit 7-segment display |
| [Led4Digit7Segment/DoubleShift](./playground/Led4Digit7Segment/DoubleShift)   | **7-Segment, Arduino**          driving a 4-Digit 7-Segment display with only 3 pins, using two 74HC595 shift registers and some NPN BJTs |
| [Led4Digit7Segment/DoubleShiftWithFETs](./playground/Led4Digit7Segment/DoubleShiftWithFETs)| **7-Segment, Arduino** driving a 4-Digit 7-Segment display with only 3 pins, using two 74HC595 shift registers and some n-channel FETs |
| [Led4Digit7Segment/SingleShift](./playground/Led4Digit7Segment/SingleShift)   | **7-Segment, Arduino**          driving a 4-digit 7-segment display with a shift register and a few BJTs |
| [LedTemperatureDisplay](./playground/LedTemperatureDisplay)                   | **Sensors, 7-Segment, Arduino** measure ambient temperature and display with a 4-digit 7-segment LED unit |
| [LED chaser](./playground/LedChaser)                                          | **LED, Arduino**                blinks a series of 12 LEDs in a coninuous loop |
| [LEDArrayDemos](./LEDArrayDemos)                                              | **LED Array, Arduino**          Intro and Setup.. I bought some [WS2811-based LED Strips](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) with a specific project in mind. But first, need to get them working... |
| [LevelIndicatorLM3915](./playground/LevelIndicatorLM3915)                     | **LM3915, Arduino**             Driving an LM3915 10-segment display with a single Arduino pin |
| [LightOrNot](./playground/LightOrNot)                                         | **Sensors, Arduino**            uses an LDR to adjust the blink rate of an LED |
| [LittleGem/A386](./Electronics101/AudioAmps/LittleGem)                        | **OpAmp, Audio**                a basic Smokey-inspired LM386 guitar power amp |
| [LEDLamp](./Electronics101/LEDLampAC)                                         | **Power, LED**                  build and analyse a commercial LED lamp kit with capacitive power supply |
| [MaxRawDemo](./playground/LED8x8/MaxRawDemo)                                  | **8x8 LED, Arduino**            drive an 8x8 LED Matrix with a MAX7219 chip an raw SPI commands |
| [MeLEDy](./Electronics101/MeLEDy)                                             | **Audio**                       use an electret microphone to light a series of LEDs in proportion to volume |
| [Monostable](./Electronics101/555Timer/Monostable)                            | **555 Timer**                   basic monostable mode using an Arduino and processing to plot the output |
| [Monostable122](./Electronics101/Monostable122)                               | **74xx TTL**                    simple pulse trigger using 74LS122 monostable with external timing configuration |
| [MonostablePulseExtender](./playground/MonostablePulseExtender)               | **74xx TTL, Arduino**           test the behaviour of a 74LS122 monostable with external timing configuration and plot the results with an Arduino |
| [MotorControlPWM](./playground/MotorControlPWM)                               | **Motors, Arduino**             tests PWM speed control of a DC motor driven by an Arduino |
| [NonInverting324](./Electronics101/NonInverting324)                           | **OpAmp**                       demo LM324 OpAmp non-inverting DC gain mode |
| [NOR7402](./Electronics101/NOR7402)                                           | **74xx TTL, Arduino**           demo the 74LS02 Quad 2-input NOR gate with an Arduino |
| [NORGateOscillator](./Electronics101/NORGateOscillator)                       | **74xx TTL, Oscillators, Arduino** test a low-speed square wave oscillator using NOR gates |
| [OLED/SSD1306BareBack](./playground/OLED/SSD1306BareBack)                     | **OLED, Arduino**               driving a monochrome 128x64 OLED Display with an Arduino and the raw command set |
| [OLED/SSD1306WithAdaFruitLibraries](./playground/OLED/SSD1306WithAdaFruitLibraries) | **OLED, Arduino**         running the AdaFruit example program with a monochrome 128x64 OLED Display |
| [OpAmpTimer](./Electronics101/OpAmpTimer)                                     | **OpAmp, Timer**                testing an OpAmp timer switch |
| [PeakDetector](./Electronics101/PeakDetector)                                 | **OpAmp, RC**                   test an OpAmp-based peak detector circuit |
| [PlotNValues](./playground/PlotNValues)                                       | **Arduino, Processing**         generic script to sample up to 6 analog inputs and stream the data to serial in ASCII format for plotting with Processing |
| [Power317](./Electronics101/Power317)                                         | **Power**                       test/graph an adjustable voltage supply built with the LM317 Adjustable Regulator |
| [Power317CC](./Electronics101/Power317CC)                                     | **Power**                       test a constant current power supply built with the LM317 |
| [Power7805](./Electronics101/Power7805)                                       | **Power**                       test and graph a voltage supply built with an LM7805 5V Regulated Supply |
| [PowerBreadboard5V](./Electronics101/PowerBreadboard5V)                       | **Power**                       custom regulated 5V power supply module for standard breadboard |
| [PowerMB102](./Electronics101/PowerMB102)                                     | **Power**                       demo and test a commercial 3.3/5V MB102 breadboard power supply unit |
| [PowerZener](./Electronics101/PowerZener)                                     | **Power**                       test and graph a power supply regulated with a 1N4733 zener diode |
| [Popcorn](./playground/Popcorn)                                               | **Audio, Arduino**              How to make a piezo buzzer even more annoying? Make it play popcorn! |
| [Pushbutton LED switch](./playground/PushbuttonLED)                           | **LED, Arduino**                Momentary push button switch is used to toggle the LED on and off |
| [Quad Latch](./Electronics101/QuadLatch)                                      | **74xx TTL**                    graph the basic operation of the 74LS75 4-bit bistable latch |
| [QuadNOR](./Electronics101/QuadNOR)                                           | **74xx TTL, Arduino**           demo simple cascading NOR gate logic with the 74LS02 and an Arduino |
| [R2RDAC](./playground/R2RDAC)                                                 | **Arduino**                     a 16-bit R2R digital to analog converter with shift register interface |
| [RangeFinder](./playground/RangeFinder)                                       | **Sensors, Arduino**            proximity/distance measurement with an HC-SR04 untrasonic ranging module |
| [RCOscillator](./Electronics101/RCOscillator)                                 | **BJT, RC, Oscillators**        simple RC/transistor multistable vibrator |
| [RelaxationJouleThief](./Electronics101/RelaxationJouleThief)                 | **Power, RLC, Oscillators**     test a "joule thief" circuit based on a relaxation oscillator |
| [RelayControlTest](./playground/RelayControlTest)                             | **Servo, Arduino**              quick test to drive a motor with a common relay using NPN switching circuit under Arduino control |
| [RelayModuleTest](./playground/RelayModuleTest)                               | **Servo, Arduino**              quick test of a common relay board to switch a motor under Arduino control |
| [ResistorTransistorLogic/AND](./Electronics101/ResistorTransistorLogic/AND)   | **BJT, Logic Gates**            test the basic resistor-transistor logic AND gate  |
| [ResistorTransistorLogic/NAND](./Electronics101/ResistorTransistorLogic/NAND) | **BJT, Logic Gates**            test the basic resistor-transistor logic NAND gate  |
| [ResistorTransistorLogic/NOR](./Electronics101/ResistorTransistorLogic/NOR)   | **BJT, Logic Gates**            test the basic resistor-transistor logic NOR gate  |
| [ResistorTransistorLogic/NOT](./Electronics101/ResistorTransistorLogic/NOT)   | **BJT, Logic Gates**            test the basic resistor-transistor logic NOT gate (Inverter) |
| [ResistorTransistorLogic/OR](./Electronics101/ResistorTransistorLogic/OR)     | **BJT, Logic Gates**            test the basic resistor-transistor logic OR gate |
| [RFDetectorProbe](./Electronics101/EMRDetection/RFDetectorProbe)              | **RF**                          a simple RF detector mounted in a pen |
| [RingCounter](./Electronics101/RingCounter)                                   | **CMOS, 555 Timer**             test the classic CD4017 walking-ring counter |
| [RingCounterController](./playground/RingCounterController)                   | **CMOS, Arduino**               control the classic CD4017 walking-ring counter with an Arduino |
| [RingOscillator](./Electronics101/RingOscillator)                             | **74xx TTL, Oscillators**       test an oscillator built with a 74LS14 Inverter chip |
| [RFSwitch](./Electronics101/RFSwitch)                                         | **RF, OpAmp**                   simple remote control switch with 433Mhz transmitter/receiver and some analog signal processing |
| [RFSwitchASK](./playground/RFSwitchASK)                                       | **RF, ASK, Arduino**            data communications using ASK protocol over 433Mhz RF transmitter and receiver set |
| [RGBCalibrate](./LEDArrayDemos/RGBCalibrate)                                  | **LED Array, Arduino**          quick test to make sure LEDs are correctly addressable and their color can be set correctly |
| [RotaryEncoderMethods](./playground/RotaryEncoderMethods)                     | **Sensor, Arduino**             finding the best method for reading a rotary-encoder |
| [RotaryEncoderModule](./playground/RotaryEncoderModule)                       | **Sensor, 8x8 LED, Arduino**    testing a Rotary Encoder module controlling an LED 8x8 display |
| [RouletteKit](./Electronics101/555Timer/RouletteKit)                          | **555 Timer**                   build and examine the workings of a commercial 555 Roulette kit |
| [Ruby](./Electronics101/AudioAmps/Ruby)                                       | **OpAmp, Audio**                a version of the runoffgroove Ruby LM386 guitar amp |
| [Schmitt Inverter](./Electronics101/SchmittInverter)                          | **74xx TTL**                    graph the basic operation of the 74LS14 Hex Inverter with Schmitt Trigger Inputs |
| [ServoTest](./playground/ServoTest)                                           | **Servo, Arduino**              test the positioning accuracy of a servo motor driven by an Arduino |
| [Shifty](./playground/Shifty)                                                 | **LED, Arduino**                drive 8 LEDs with 3 pins using a 74HC595 shift register |
| [Simple7SegmentDisplay](./playground/Simple7SegmentDisplay)                   | **7-Segment, Arduino**          test a 7-segment common cathode display |
| [SimpleChime](./Electronics101/555Timer/SimpleChime)                          | **555 Timer**                   play a sound for a fixed duration when a button is pressed |
| [SimplePeakDetector](./Electronics101/SimplePeakDetector)                     | **RC**                          test the basic diode-RC peak detector circuit |
| [SimpleSiren](./Electronics101/555Timer/SimpleSiren)                          | **555 Timer**                   classic timer circuit producing a two-tone oscillation |
| [Smokey](./Electronics101/AudioAmps/Smokey)                                   | **Amp, Audio**                  quick build of a Smokey-like LM386 guitar power amp |
| [SolenoidControl](./playground/SolenoidControl)                               | **Solenoid, Arduino**           controlling a mini solenoid with an Arduino |
| [SolenoidDIY](./Electronics101/SolenoidDIY)                                   | **Solenoid, Arduino**           build and test a basic electromechanical solenoid |
| [StereoLightTrigger](./playground/StereoLightTrigger)                         | **Sensors, Arduino**            demo an interrupt-driven method for responding to LDR light threshold triggers |
| [StripTease](./LEDArrayDemos/StripTease)                                      | **LED Array, Arduino**          demo a range of effects on the LED strip |
| [Square Wave - 555](./Electronics101/555Timer/AstableOscillator)              | **555 Timer, Oscillators**      using a 555 timer to generate a square wave and an Arduino and processing to plot the output |
| [Square Wave - LM324](./Electronics101/LM324Oscillator)                       | **OpAmp, Oscillators**          using an LM324 OpAmp to generate a square wave |
| [Square Wave - Schmitt](./Electronics101/SchmittOscillator)                   | **74xx TTL, Oscillators**       using an 74LS14 Hex Inverter with Schmitt Trigger Inputs to generate a square wave |
| [SuperheterodyneReceiverKit](./Electronics101/SuperheterodyneReceiverKit)     | **RF**                          build and analyse a basic commercial radio recevier kit |
| [Switch - NFET](./Electronics101/SwitchNFET)                                  | **MOSFET**                      small-signal n-channel MOSFET switch with turn-off delay |
| [Switch - NJFET](./Electronics101/SwitchNJFET)                                | **JFET, Arduino**               switch an independent power source using an Arduino and n-channel JFET |
| [Switch - NPN](./Electronics101/SwitchNPN)                                    | **BJT**                         small-signal digital switch with NPN BJT |
| [Switch - PFET](./Electronics101/SwitchPFET)                                  | **MOSFET**                      small-signal p-channel MOSFET switch with turn-on delay |
| [Switch - PJFET](./Electronics101/SwitchPJFET)                                | **JFET, Arduino**               switch an independent power source using an Arduino and p-channel JFET |
| [Switch - PNP](./Electronics101/SwitchPNP)                                    | **BJT**                         small-signal digital switch with PNP BJT |
| [TestIR](./playground/TestIR)                                                 | **IR, Arduino**                 test raw IR reception with a TSOP1838-type IR sensor and an Arduino |
| [TinyBlink](./playground/TinyBlink)                                           | **Arduino, ATmel**              a simple blink sketch with an ATTINY85-20PU on a breadboard |
| [ToroidJouleThief](./Electronics101/ToroidJouleThief)                         | **Power, RL, Oscillators**      test a "joule thief" circuit based on a ferrite toroid |
| [TouchSwitch/555](./Electronics101/555Timer/TouchSwitch)                      | **555 Timer**                   test a touch switch circuit based on a 555 timer |
| [TransistorTester](./Electronics101/TransistorTester)                         | **Arduino, BJT**                use an Arduino to test NPN and PNP BJTs |
| [Triangle Wave - 555](./Electronics101/555Timer/TriangleWaveGen)              | **555 Timer, Oscillators**      generate a triangle wave with 555 timer and RC integrator |
| [TTLBufferDriver](./Electronics101/TTLBufferDriver)                           | **OpAmp, TTL**                  using an OpAmp as a final buffer stage for TTL or similar circuits |
| [TwoToneDoorbell](./Electronics101/555Timer/TwoToneDoorbell)                  | **555 Timer, Oscillators**      basic two-tone doorbell using a 555 timer oscillator, with n-channel FET for power conservation |
| [VariableDutyCycle](./Electronics101/555Timer/VariableDutyCycle)              | **555 Timer, Oscillators**      a 555 oscillator circuit that allows easy manual duty cycle adjustment while minimising the change to frequency |
| [Variable LED brightness (PWM)](./playground/VariableLED)                     | **LED, Arduino**                variable resistor is used to control the brightness of an LED with PWM |
| [VoltageDoublerChargePump](./Electronics101/555Timer/VoltageDoublerChargePump)| **555 Timer, Power**            test a voltage-doubling charge pump circuit based on a 555 timer |
| [VolumeControlPowerAmp](./Electronics101/AudioAmps/VolumeControlPowerAmp)     | **OpAmp, Audio**                an LM386 fixed-gain audio power amp with volume control |
| [VoiceLevelIndicatorKit](./Electronics101/VoiceLevelIndicatorKit)             | **LED, Kit**                    build and investigate a commercially available "3-band voice level indicator" kit |
| [X113647Stepper](https://github.com/tardate/X113647Stepper)                   | **Stepper, Arduino**            It's common to find the 28BYJ-48 stepper motor and a X113647 Stepper Motor Driver Board in Arduino starter kits. However documentation is scant and the board is not exactly compatible with the standard Stepper library. See the [X113647Stepper github page](https://github.com/tardate/X113647Stepper) for details of the library, example programs, and custom Fritzing parts for the components. |


# Getting Up and Running

Some projects require additional libraries including FastLED, FlexiTimer2, RadioHead.
A set of such libraries are included as submodules of this repository,
see the [libraries/](./libraries) page for more information on the included libraries and submodule management.

Libraries can be retrieved with git, or you can just install them separately as you would any other library.

If you clone this repo, also update the submodules to have them available for compilation/installation:

    $ git submodule update --init

To pull submodule updates later on:

    $ git submodule foreach git pull

