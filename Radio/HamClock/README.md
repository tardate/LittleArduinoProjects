# #762 HamClock

Exploring HamClock, the kiosk-style application that displays real time space weather, radio propagation models, operating events and other information particularly useful to the radio amateur. Trying it on macOS, Ubuntu and Raspberry Pi.

![Build](./assets/HamClock_build.jpg?raw=true)

## Notes

I recently learned about [Geochron](https://www.geochron.com/) clocks (analog and digital) on Ham Radio Workbench #230. These are beautiful displays of the current time over a live map of the earth, and support overlays of all manner of interesting details.

They are expensive though! I did find out though (vai a tip from Mike Deal N7URH) that there is an open source alternative specifically designed for amateur radio called [HamClock](https://www.clearskyinstitute.com/ham/HamClock/).

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

Then within XQuartz, choose "Applications | Terminal", and run the "hamclock" command in the xterm

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

I have an old Raspberry Pi B+.

Current documentation recommends an RPi model 4b with 1 GB RAM.
Maybe it is possible to use a Raspberry Pi B+?

I will try this out and update the notes later. If I can't get it to run with a B+, maybe it is time to get a new Raspberry Pi!

## Credits and References

* [HamClock](https://www.clearskyinstitute.com/ham/HamClock/)
* [Geochron](https://www.geochron.com/)
