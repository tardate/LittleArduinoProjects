# #390 MilliVoltmeterDIY Custom PCB and Enclosure

Custom PCB and enclosure for the ATmega328-based millivolt meter based on a design by Scullcom Hobby Electronics. Uses an LTC2400 ADC and LT1019 voltage reference

![Build](./assets/CustomBoardAndEnclosure_build.jpg?raw=true)

## Notes

This is a continuation of [LEAP#372 MilliVoltmeterDIY](../), a circuit based on the Scullcom Hobby Electronics #44 - Millivolt Meter MK2 project.

Previously, I reached the point of modifying the design somewhat, revising the code and having a breadboard prototype working just fine.
Since it is such a handy piece of kit, I decided to go the whole hog: make a PCB and mount it in a case.

Update: I've added battery by-pass and reverse polarity protection - see the last section of this document.

## PCB Design

I'm going to drop an ATmega328P-AU TQFP on the board, rather than use an Arduino module. So let's get some pin mapping stright first:

| Arduino Pin | Connection                     | ATmega pin |
|-------------|--------------------------------|------------|
| D2          | DB7 serial LCD                 | 32, PD2    |
| D3          | DB6 serial LCD                 | 1, PD3     |
| D4          | DB5 serial LCD                 | 2, PD4     |
| D5          | DB4 serial LCD                 | 9, PD5     |
| D6          | E serial LCD enable            | 10, PD6    |
| D7          | RS serial LCD                  | 11, PD7    |
| D8          | BTN_2_FUNCTION function button | 12, PB0    |
| D9          | BTN_PRECISION precision button | 13, PB1    |
| D10         | CS - ADC SPI select            | 14, PB2    |
| D10         | MOSI - ICSP header             | 15, PB3    |
| D12         | MISO - ADC SPI SDA, ICSP       | 16, PB4    |
| D13         | SCK - ADC SPI clock, ICSP      | 17, PB5    |
| A0          | BTN_CAL calibration button     | 23, PC0    |
| A1          | VBATT_SENSE battery sensor     | 24, PC1    |
| A4          | SDA optional I²C screen        | 27, PC4    |
| A5          | SCL optional I²C screen        | 28, PC5    |
| RESET       | ICSP header                    | 29, PC6    |
|             | VCC                            | 4, 6       |
|             | GND                            | 3, 5, 21   |
|             | AVCC                           | 18         |
|             | XTAL                           | 7, PB6     |
|             | XTAL                           | 8, PB7     |

I decided to provision pin connections for either serial or I²C LCD displays.

After finding that KiCad didn't have footprints for half the components I wanted to use in the standard library,
I decided to try EasyEDA for PCB production:

* the component library is very complete (I didn't need to create any custom components)
* but the PCB designer is not quite as advanced as KiCad. Workable though.

The [EasyEDA project is available here](https://easyeda.com/tardate/MilliVoltmeterDIY-8553e43370c2483c926e832323425b5b),
and I sent the board off to [OSHpark](https://oshpark.com/).
The OSHPark project [is available here](https://oshpark.com/shared_projects/c6PGdeFn).


[![CustomBoardAndEnclosure_schematic](./assets/CustomBoardAndEnclosure_schematic.png?raw=true)](https://easyeda.com/tardate/MilliVoltmeterDIY-8553e43370c2483c926e832323425b5b)

![pcb_render_front](./assets/pcb_render_front.png?raw=true)

![pcb_render_rear](./assets/pcb_render_rear.png?raw=true)

The boards have arrived! All traces and pads check-out perfectly.

![pcb_blanks](./assets/pcb_blanks.jpg?raw=true)

Mostly hot-air for surface-mount components, but through-hole for:

* connectors - I decided to use simple male header pins in this build (instead of soldering wires direct to the board)
* ICSP header and shroud
* trim pot

![pcb_populated](./assets/pcb_populated.jpg?raw=true)

Dang! This is when I realise I forgot the 50Hz/60Hz noise rejection jumper.


## Enclosure and Hardware

I'm using a 140mm x 110mm x 42mm black plastic project enclosure.
As a bonus it comes with 4 screw-on rubber feet.

I picked this up while browsing in [Sim Lim Tower (Singapore)](https://goo.gl/maps/pSonsE9L4J72).
There is no manufacturer identification, but I suspect it may be the [Future Kit FB16](https://www.futurekit.com/product/25667/fb16).


### Control Buttons

I'm using some 7mm normally closed momentary push-buttons
[similar to these from an aliexpress seller](https://www.aliexpress.com/item/PBS-110-No-Lock-Switch-Self-resetting-Push-Button-Switch-Normally-Closed-Reset-Switch/32557823070.html)

![hw_pb_switch](./assets/hw_pb_switch.png?raw=true)

### Input Jacks

I decided to use a nice dual banana binding post for the positive and negative test lead connector,
like this [example from a seller on aliexpress](https://www.aliexpress.com/item/High-Quality-Speaker-Amplifier-Dual-Binding-Post-Banana-Plug-Socket-Connectors-5pcs/32738527737.html)

I have [Multimeter Dual Test Hook Clip to Male Banana Plug Cable](https://www.aliexpress.com/item/IMC-Hot-Multimeter-Dual-Test-Hook-Clip-to-Male-Banana-Plug-Cable-4ft-4-in-1/32438306723.html?spm=a2g0s.9042311.0.0.27424c4dIxrIt4) that matches perfectly.

I'm maybe having second thoughts about this. If I'd used for example some
[4mm Banana Female Jack Socket Panel Mount](https://www.aliexpress.com/item/10Pcs-4mm-Banana-Female-Jack-Socket-Panel-Mount-Binding-Post-Connector/32684201221.html?spm=a2g0s.9042311.0.0.27424c4dIxrIt4) then I could use most of my multimeter test leads with the unit.

![hw_input_jacks](./assets/hw_input_jacks.png?raw=true)

### DC Socket

On the rear panel I have a
[5.5x2.1mm DC Power Socket Connector Round Panel Mounting](https://www.aliexpress.com/item/20pcs-Lot-5-5x2-1mm-DC-Power-Socket-Connector-Round-Panel-Mounting-Black-Plastic-Free-Shipping/1560577280.html) to take external 9V DC supply (centre positive),
and a [SPST 2PIN ON/OFF G130 Rocker Switch 3A/250V](https://www.aliexpress.com/item/10pcs-lot-10-15mm-SPST-2PIN-ON-OFF-G130-Boat-Rocker-Switch-3A-250V-Car-Dash/32680215196.html). There is no reverse polarity protection in the circuit yet, so maybe I should just throw a diode in series.
There's a perfect spot for it: connecting the power to the switch.

![hw_power_connectors](./assets/hw_power_connectors.png?raw=true)


### Calibration Test Point

I fashioned a loop of copper wire, soldered to a 1x3 piece of protoboard on the rear.
It is positioned just next to the positive input jack.



## Code and Programming

The unit is programmed with the [MilliVoltmeterDIY.ino](../MilliVoltmeterDIY.ino) sketch and associated libraries.

Only one modification was required. As I'm using normally-closed pushbutttons, the button state logic is declared as active-high:

    #define BUTTON_LOGIC_ACTIVE_STATE          (HIGH)

I used an Arduino as ISP to:

* burn bootloader
* upload the code

See [LEAP#068 ATmegaViaArduinoISP](../../../playground/ATmegaViaArduinoISP) for notes on programming with Arduino ISP.

## Assembly

There's lots of room in this enclosure, so it all goes in very well. Immediately I see a few things
that could be better if I'd planned the construction properly when designing the board. If I were to do it again:

* I should reverse the LCD serial connectors, so they don't need to cross when connecting to the LCD
* the push-button connectors would be better positioned on the other side of the board
* mounting holes I made in the PCB should have been larger! The screws provided with the enclosure are a size too big... so I just hot-glued the board in place.


![assembly_top](./assets/assembly_top.jpg?raw=true)

![assembly_inner_front](./assets/assembly_inner_front.jpg?raw=true)

![assembly_inner_rear](./assets/assembly_inner_rear.jpg?raw=true)

## Done and Tested

Calibrating with the 2.5V reference voltage:

* connect the positive input to the 2.5V calibration test point and press the `C`alibrate button.
The calibration factor is stored in EEPROM and reloaded on startup.

![CustomBoardAndEnclosure_calibration](./assets/CustomBoardAndEnclosure_calibration.jpg?raw=true)

The function button cycles between 3 display modes on the second line:

* bar graph
* hold value
* raw ADC value

The precision button cycles through the number of significant digits to display.

Rear view:

![CustomBoardAndEnclosure_rear](./assets/CustomBoardAndEnclosure_rear.jpg?raw=true)

With a simple voltage-divider test load:

![CustomBoardAndEnclosure_build](./assets/CustomBoardAndEnclosure_build.jpg?raw=true)


## Battery By-pass and Reverse Polarity Mod

After the initial build, there were two enhancements I wanted to make:

* more flexible power supply: internal battery for portable use. The power socket has bypass connector, so this is easy to add.
* reverse polarity protection, to avoid issues with centre-positive/centre-negative connectors

I've just added these, having got hold of some
[9V battery holders](https://www.aliexpress.com/item/5pcs-9V-Battery-Case-Holder-Cover-Box-Replacement-for-Active-Guitar-Bass-Pickup/32846434285.html)
designed for panel mounting...

![Battery_mod](./assets/Battery_mod.jpg?raw=true)

The battery is wired up with the negative connection to the bypass connector on the panel jack.
I added a 1N5819 rectifier diode in series to the power switch for reverse-polarity protection.

All installed:

![Battery_mod_installed](./assets/Battery_mod_installed.jpg?raw=true)

Rear panel now has power switch, external power supply jack, and 9V battery holder:

![Battery_mod_CustomBoardAndEnclosure_rear](./assets/Battery_mod_CustomBoardAndEnclosure_rear.jpg?raw=true)


## Conclusion

All told, this turned out pretty well, though there are a couple of things I would change if I were to do it again:

* some changes to the PCB as mentioned above:
    * flip the LCD serial connectors, so they don't need to cross when connecting to the LCD
    * the push-button connectors would be better positioned on the other side of the board
    * larger (M3) mounting holes
* I think I'd switch from binding posts to shrouded banana sockets for the input jacks (compatible with most multimeter leads)
* perhaps a mains AC supply adapter built-into the unit


## Credits and References

* [Scullcom Hobby Electronics #44 - Millivolt Meter MK2](https://www.youtube.com/watch?v=CiTPUmqE3Yg) - YouTube
* [Millivolt Meter MK2](http://www.scullcom.uk/millivolt-meter-mk2/) - more info on on www.scullcom.uk
* [LEAP#372 MilliVoltmeterDIY](../) - precursor: details my adaptation of the design and breadboard testing
* schematic and PCB design [available here in EasyEDA](https://easyeda.com/tardate/MilliVoltmeterDIY-8553e43370c2483c926e832323425b5b)
* [PCB project available here from OSHPark](https://oshpark.com/shared_projects/c6PGdeFn)
* [Atmel ATmega328P Product Info](http://www.atmel.com/devices/ATMEGA328P.aspx)
* [9V Battery Case Holder Cover Box Replacement for Active Guitar Bass Pickup](https://www.aliexpress.com/item/5pcs-9V-Battery-Case-Holder-Cover-Box-Replacement-for-Active-Guitar-Bass-Pickup/32846434285.html)
* [1N5819 datasheet](https://www.futurlec.com/Diodes/1N5819.shtml)
* [..as mentioned on my blog](https://blog.tardate.com/2018/05/leap391-packaging-the-mv-meter.html)
