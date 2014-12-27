# FretBoard

FretBoard is a multi-project build status indicator, using
a [WS2811-based LED Strip](http://www.aliexpress.com/item/IP68-12mm-WS2811-as-WS2801-led-pixel-module-IP68-waterproof-DC5V-full-color-RGB-50pcs-a/1932649085.html)
to display the status of each project.

This is a work-in-progress. Done:

* parse build status from the net using Ethernet shield
* driving the LED Array with basic build status indication
* added LED effects (glow) using timer driver
* added visual indicator when the build status is refreshed

Still To Do:

* add specific effects for builds-in-progress
* the physical build - housing this in a suitable case for display
* wrap up the doco


Here's a quick video of the first demo of the LED array hooked up to an Arduino collecting live build status from the net; next step is the physical housing:

[![AsyncLedStripEffects - using a timer interrupt to run effects on an LED array](http://img.youtube.com/vi/XJ0cd0ktjQg/0.jpg)](http://www.youtube.com/watch?v=XJ0cd0ktjQg)


## Notes

### The Build Status Web Repsonse

I'm getting build status from a web server that supports a simple HTTP 1.0 CSV response format:

    $ curl -i -0 --raw "http://my.ci-server.net/statuses/builds.csv"

    HTTP/1.1 200 OK
    Content-Type: text/csv; charset=utf-8
    Connection: close
    Status: 200
    X-Powered-By: Phusion Passenger (mod_rails/mod_rack) 3.0.19
    X-UA-Compatible: IE=Edge,chrome=1
    ETag: "3a99c061fc2b854ce9880af33079c98f"
    Cache-Control: max-age=0, private, must-revalidate
    X-Request-Id: d94d735690a2827101f7e14488a5eca8
    X-Runtime: 2.554357
    Date: Thu, 25 Dec 2014 06:05:51 GMT
    X-Rack-Cache: miss
    Server: nginx/1.2.6 + Phusion Passenger 3.0.19

    project a,Sleeping,Success
    project b,Sleeping,Building
    project c,Sleeping,Failure
    project d,CheckingModifications,Success
    project e,CheckingModifications,Failure

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


## Construction

### Schematic

![The Schematic](../LEDArrayDemos/assets/LedArray_schematic.jpg?raw=true)

### Raw Build prior to Physical Housing

![The Build](./assets/FretBoard_build_unassembled.jpg?raw=true)

