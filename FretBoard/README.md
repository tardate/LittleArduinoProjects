# #018 FretBoard

FretBoard is a multi-project build status indicator, using a [WS2811-based LED Strip](https://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html)
to display the status of each project.

Full details of the project are available at [fretboard.tardate.com](https://fretboard.tardate.com)

[![Build](./assets/FretBoard_build.jpg?raw=true)](https://fretboard.tardate.com)

Done:

* parse build status from the net using Ethernet shield
* driving the LED Array with basic build status indication
* added LED effects (glow) using timer driver
* added visual indicator when the build status is refreshed and builds-in-progress
* the physical build - housing this in a suitable case for display
* wrap up the doco



[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

### The Build Status Web Response

We get build status from a web server that supports a simple HTTP 1.0 CSV response.
This is probably a proxy to the actual build server.
See the
[fretboard web](https://github.com/tardate/fretboard_web)
repository for an example of a proxy that can handle Circle CI JSON API and CruiseControl XmlStatusReport response formats.

The response looks like this:

```
$ curl -i -0 --raw http://fretboard.tardate.com/status.csv

HTTP/1.1 200 OK
Connection: close
Content-Type: text/csv;charset=utf-8
Content-Length: 288
X-Content-Type-Options: nosniff
Server: WEBrick/1.3.1 (Ruby/2.0.0/2014-11-13)
Date: Sun, 01 Feb 2015 09:04:18 GMT
Via: 1.1 vegur

dummy_project_1,Sleeping,Success
dummy_project_2,Sleeping,Failure
dummy_project_3,CheckingModifications,Success
dummy_project_4,CheckingModifications,Failure
dummy_project_5,Building,Success
dummy_project_6,Building,Failure
dummy_project_7,Unknown,Success
dummy_project_8,Unknown,Failure
```

Each line of the CSV response includes three elements:

* project name
* build activity (CheckingModifications,Building,Sleeping,Unknown)
* build status (Success,Unknown,Failure)


A couple of features make this easy to deal with:

* HTTP 1.0 means the Arduino doesn't need to deal with chunked-encoding.
* The CSV format is easy to parse either natively from EthernetClient or with the assistance of a library like [TextFinder](https://github.com/tardate/TextFinder)
* project build status are provided in alphabetical order, hence the Arduino doesn't need to worry about ordering of results


### Parsing the Web Request

I'm using [TextFinder](https://github.com/tardate/TextFinder) to parse the web response. Note that the GitHub repository version of TextFinder is an
enhanced version of the original library available form the [Arduino Playground](http://playground.arduino.cc/Code/TextFinder).

Other libraries that could be used are [amcewen/HttpClient](https://github.com/amcewen/HttpClient)
and [interactive-matter/HTTPClient](https://github.com/interactive-matter/HTTPClient).


### Power

The LED strip requires 5V and with all 24 LEDs on, current should max out at 1.44A (0.3W * 24 / 5V).

For testing, I'm powering the LED Array from a 5V 2A adapter and the Arduino from USB.

For the final build, I'll be powering the Arduino from the same 5V adapter powering the LEDs (direct to the 5V pin on the Arduino).
There is lots of advice on how to do this
[e.g. here](http://www.reddit.com/r/arduino/comments/2fcr6c/powering_arduino_with_5v_supply/)
 - along with strong caveats since the 5V pin bypasses the onboard regulator, and it is essential to ensure no other power source is simulatneously provided to the Arduino.
However, the 5V adapter I am using is regulated, and under test it has worked fine to power the Arduino and LED array together.


## Construction

![The Breadboard](./assets/FretBoard_bb.jpg?raw=true)

![The Schematic](./assets/FretBoard_schematic.jpg?raw=true)

![The Build](./assets/FretBoard_build2.jpg?raw=true)

### Parts

Not much to the electronics. Core parts:

* Arduino Uno
* Arduino Ethernet shield
* WS2811-based LED Strip
* 1000µF capacitor for power supply smoothing
* 1kΩ resistor for current-limiting the LED data line

And then connectors etc depending on the physical housing.

### LED Strip Data

[WS2811-based LED Strip](https://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html) ships in a strip of 50 LEDs (cut down to 24 for this project). The basic details:

* Certification: EMC,FCC,LVD,RoHS
* Brand Name: olym-led
* Features: ws2811
* Model Number: ol-rgb-0.3w
* Voltage: 5V
* LED Power: 0.3W
* Waterproof IP Grade: IP68
* Led Lifespan: Over 50000 hours
* Light Color: RGB FULL Color

## References
* [fretboard.tardate.com](https://fretboard.tardate.com) - vanity site for the project
* [The GitHub Stoplight](http://urbanhonking.com/ideasfordozens/2010/05/19/the_github_stoplight/)
* [Monitoring Your Continuous Integration Server with Traffic Lights and an Arduino](http://isotope11.com/blog/monitoring-your-continuous-integration-server-with-traffic-lights-and-an-arduino)
* [Operation Stoplight: Jenkins + Arduino Build Status Notification](https://www.helpshift.com/blog/operation-stoplight-jenkins-arduino-build-status-notification/)
* [adafruit digital-led-strip wiring](https://learn.adafruit.com/digital-led-strip/wiring)
* [Adafruit NeoPixel Überguide](https://learn.adafruit.com/adafruit-neopixel-uberguide)
* [Arduino and WS2812 LEDs](http://www.tweaking4all.com/hardware/arduino/arduino-ws2812-led/)
* [Bit banging step-by-step: Arduino control of WS2811, WS2812, and WS2812B RGB LEDs](https://www.instructables.com/id/Bitbanging-step-by-step-Arduino-control-of-WS2811-/)
* [Digital Addressable Led Strip & Arduino](http://interface.khm.de/index.php/lab-log/digital-addressable-led-strip-arduino/) - code for simple example
* [Driving a WS2811 RGB LED Strip with an Arduino](http://erroraccessdenied.com/node/1707)
* [FastLED Animation Library](http://fastled.io/)
* [FastSPI LED Effects](http://funkboxing.com/wordpress/?p=1366) - some custom code for driving the ws2811
* [thread on connecting datalines to LED array](http://forum.espruino.com/conversations/699/)
* [Use a $1 ATTiny to drive addressable RGB LEDs](https://www.instructables.com/id/Use-a-1-ATTiny-to-drive-addressable-RGB-LEDs/)
* [WS2811 Digital RGB LED](http://wiki.hacdc.org/index.php/WS2811_Digital_RGB_LED) - good data sheet and tips resource - addressable LEDs
* [..as mentioned on my blog](https://blog.tardate.com/2015/02/the-fretboard-multi-project-build.html)
