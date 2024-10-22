# #497 Publishing Internals

Publishing live ESP32 system internals to the web - an exploration of ESP32 features and web serving options, including JSON serialization.

![PublishingInternals_demo](./assets/PublishingInternals_demo.gif?raw=true)

## Notes

The ESP32 is powerful enough to do some decent web serving. This project explores:

* implementing a web server on the ESP32
* generating JSON web responses
* collecting ESP32 system internals, including:
    * temperature
    * hall-effect sensor
    * CPU and bus speeds
    * .. and other tidbits I can glean from references and sources...

The code is written to be built with the Arduino IDE + ESP32 board support.

### Reading the Chip Temperature

The undocumented `uint8_t temprature_sens_read()` function is discplosed in
[esp32-hal-misc.c#L40](https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/esp32-hal-misc.c#L40)
It returns the get chip temperature in Farenheit. The `float temperatureRead()` function returns celsius.

### Reading the Hall Effect Sensor

The [`hallRead()`](https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/esp32-hal-adc.h#L98) function
returns the magnetic field strength using the on-board hall-effect sensor.

### Getting Operating Frequencies

[esp32-hal-cpu.h#L40](https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/esp32-hal-cpu.h#L40)

* `getCpuFrequencyMhz()` returns the CPU frequency in MHz. This gets the actual CPU speed, whereas the avr function `clockCyclesPerMicrosecond()` returns the frequency that the code has been compiled for (based on the F_CPU #define)
* `getXtalFrequencyMhz()` returns the crystal frequency in MHz
* `getApbFrequency()` returns the advanced peripheral bus (APB) frequency in Hz

While the crystal frequency should be static, the CPU and bus speeds can vary due to the power management algorithm being applied.
See [Power Management](https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/system/power_management.html) docs.

### Rendering JSON

The `/stats.json` endpoint returns a JSON collection of current stats.
Instead of a manual (and error-prone) process of building the JSON representation,
the example uses the [ArduinoJson](https://www.arduinolibraries.info/libraries/arduino-json) library.
It makes JSON generation trivial.

I'm using the `StaticJsonDocument` class that pre-allocates storage on the stack. Creating attributes and serializing the result is trivial, e.g.:

    char buffer[200];
    StaticJsonDocument<200> statsDocument;
    statsDocument["uptime"] = millis();
    serializeJson(statsDocument, buffer);

### Developing the Web Page

I didn't skimp on the web page: it uses a number of Javascript libraries, but all loaded from external CDNs.
The ESP32 just serves the basic HTML page, and the stats JSON endpoint.

The [page_design.html](./page_design.html) file was used during development. I load it in Firefox,
and it has a hard-coded reference to the IP that the ESP32 is sitting on. In this way, I could
fine-tune the web page before building it into the code that is written to the ESP32 itself.

The page uses some assets and libraries that are side-loaded i.e. not served directly from the ESP32:

* [Bootstrap](https://getbootstrap.com/) - for some simple layout and format help
* [Google Charts](https://developers.google.com/chart/)

### Building and Running the Example

Copy `settings.h.template` to `settings.h` and fill in the WiFi access credentials before compiling.
After uploading the program to the ESP32, connect to the serial console to find out what IP address it obtained..

![demo_getting_ip](./assets/demo_getting_ip.png?raw=true)

Go to the IP address with a browser. the status page should load, and start updating statistics every second or so.
To verify it is really working, bring a magnet close to the ESP32 to see changes the hall effect sensor.

![demo_screenshot](./assets/demo_screenshot.png?raw=true)

## Construction

There is no "circuit" to construct so far - simply plugging the ESP32 into the USB port!

![Build](./assets/PublishingInternals_build.jpg?raw=true)

## Credits and References

* [LEAP#496 ESP32 Getting Started](../GettingStarted) - background on programming the ESP32 with the Arduino IDE
* [ESP32 ArduinoJson v6: Serializing JSON](https://techtutorialsx.com/2019/05/02/esp32-arduinojson-v6-serializing-json/)
* [Bootstrap](https://getbootstrap.com/) - for some simple layout and format help
* [Google Charts](https://developers.google.com/chart/)
