# #762 HamClock

Exploring HamClock, the kiosk-style application that displays real time space weather, radio propagation models, operating events and other information particularly useful to the radio amateur. Trying it on macOS, Ubuntu and Raspberry Pi.

![Build](./assets/HamClock_build.jpg?raw=true)

## Notes

I recently learned about [Geochron](https://www.geochron.com/) clocks (analog and digital) on Ham Radio Workbench #230. These are beautiful displays of the current time over a live map of the earth, and support overlays for all manner of interesting details.

They are expensive though! I did find out though (via a tip from Mike Deal N7URH) that there is an open source alternative specifically designed for amateur radio called [HamClock](https://www.clearskyinstitute.com/ham/HamClock/).

HamClock is a kiosk-style application that provides real time space weather, radio propagation models, operating events and other information particularly useful to the radio amateur.

HamClock was introduced in an October 2017 QST article and continues to be maintained and expanded. It supports a range of platforms:

* ESP8266 - the original design, still available but no longer maintained
* Raspberry Pi
* Linux-style systems
* macOS

### macOS

I'm running macOS with an Apple Silicon M1 chip, so it is an obvious place to start. Can we run HamClock? Yes!

Installing XQuartz (for XWindows support) with brew:

    brew install --cask xquartz

Then run the installation steps per the documentation:

    curl -O https://www.clearskyinstitute.com/ham/HamClock/ESPHamClock.zip
    unzip ESPHamClock.zip
    cd ESPHamClock
    make -j 4 hamclock-800x480
    sudo make install

The sources can then be removed:

    cd ..
    rm -fR ESPHamClock
    rm ESPHamClock.zip

To run HamClock, first start XQuartz

    open -a XQuartz

Then within XQuartz, choose "Applications > Terminal", and run the "hamclock" command in the xterm

![macos-run-hamclock](./assets/macos-run-hamclock.png)

After entering call sign, lat lng options etc, HamClock starts and I can start to play with the display options -
see the user guide <https://www.clearskyinstitute.com/ham/HamClock/HamClockKey.pdf>.

![macos-hamclock01](./assets/macos-hamclock01.png)

Nice! Works great.

### Ubuntu

I also routinely use Ubuntu (currently version 24.04). Let's try.

Make sure pre-requisites are installed:

    sudo apt install curl make g++ xorg-dev xdg-utils

Run the installation steps per the documentation (this time a slightly larger 1600x960):

    curl -O https://www.clearskyinstitute.com/ham/HamClock/ESPHamClock.zip
    unzip ESPHamClock.zip
    cd ESPHamClock
    make -j 4 hamclock-1600x960
    sudo make install

The sources can then be removed:

    cd ..
    rm -fR ESPHamClock
    rm ESPHamClock.zip

Run HamClock from the console:

    hamclock

![ubuntu-hamclock01](./assets/ubuntu-hamclock01.jpg)

Nice! Also works great.

### Raspberry Pi

I have an old Raspberry Pi 1 Model B+.
Current documentation recommends an RPi model 4b with 1 GB RAM.
Maybe it is possible to use a Raspberry Pi B+?

I grabbed a copy of the latest [Raspberry Pi OS](https://www.raspberrypi.com/documentation/computers/os.html) and ran the HamClock RPi installation per the docs:

    curl -O https://www.clearskyinstitute.com/ham/HamClock/install-hc-rpi
    chmod u+x install-hc-rpi
    ./install-hc-rpi

The installation took a very long time (I left it for an hour or so), but completed successfully. After installation, start from the command line:

    hamclock

HamClock runs fine, albeit a little sluggishly.

Since it is running on the Pi, I can play with some of the GPIO support.
This requires first visiting setup page 4 and turning on "GPIO".

I am going to test the "Satellite up" indicator per the user guide:

* Output terminal SA_1 indicates satellite visibility from DE.
* Normally low
* cycles high at 1 Hz for 1 minute before rise
* stays high during the pass
* cycles at 2 Hz during the last minute
* stays low again after set.

I wired up an LED indicator per the doc:

![HamClock_schematic](./assets/HamClock_schematic.jpg)

![HamClock_bb](./assets/HamClock_bb.jpg)

I just tested it with a LEDSAT satellite pass near my location (Singapore 1.3521° N, 103.8198° E). Works perfectly as described!

When the satellite rises, the LED blinks at 1Hz for 1 minute before rise, stays on while risen, and blinks at 2 Hz during the last minute it is visible in the sky.

![satellite_up02](./assets/satellite_up02.jpg)

Watching the screen for satellites overhead ...

![satellite_up01](./assets/satellite_up01.jpg)

### Rebuilding for Headless operation

I removed the previous installation:

    rm -fr ESPHamClock
    rm ~/Desktop/hamclock.desktop
    sudo rm /usr/local/bin/hamclock*

Then downloaded the latest sources to build a web-only 1600x960 version:

    $ wget <https://www.clearskyinstitute.com/ham/HamClock/ESPHamClock.zip>
    $ unzip  ESPHamClock.zip
    $ cd ESPHamClock
    $ make help

    The following targets are available (as appropriate for your system)

        hamclock-800x480          X11 GUI desktop version, AKA hamclock
        hamclock-1600x960         X11 GUI desktop version, larger, AKA hamclock-big
        hamclock-2400x1440        X11 GUI desktop version, larger yet
        hamclock-3200x1920        X11 GUI desktop version, huge

        hamclock-web-800x480      web server only (no local display)
        hamclock-web-1600x960     web server only (no local display), larger
        hamclock-web-2400x1440    web server only (no local display), larger yet
        hamclock-web-3200x1920    web server only (no local display), huge

        hamclock-fb0-800x480      RPi stand-alone /dev/fb0, AKA hamclock-fb0-small
        hamclock-fb0-1600x960     RPi stand-alone /dev/fb0, larger, AKA hamclock-fb0
        hamclock-fb0-2400x1440    RPi stand-alone /dev/fb0, larger yet
        hamclock-fb0-3200x1920    RPi stand-alone /dev/fb0, huge

    Optional command line variables which may be set before the desired target:
        FB_DEPTH=16 or 32         - Specify a given frame buffer pixel size (default is 32 on all but fb0)
        WIFI_NEVER=1              - Disable WiFi fields in setup (already the default on all but fb0)

    $ make -j 4 hamclock-web-1600x960
    $ sudo make install

And then startup in the background:

    $ hamclock &
    [1] 1202
    $

I am using the default ports and the Raspberry Pi is on 192.168.10.36, so I can now access hamclock interfaces

* RW live view: <http://192.168.10.36:8081/live.html>
* RO live view: <http://192.168.10.36:8082/live.html>
* REST API e.g. get config: <http://192.168.10.36:8080/get_config.txt>

The web view:

![rpiweb-01a](./assets/rpiweb-01a.png)

To start this automatically on each boot, run `crontab -e` then add the following as the last line:

    @reboot /usr/local/bin/hamclock

## Credits and References

* [HamClock](https://www.clearskyinstitute.com/ham/HamClock/)
* [Geochron](https://www.geochron.com/)
