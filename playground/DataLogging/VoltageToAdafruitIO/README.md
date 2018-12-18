# #440 Logging Voltage Measurements To Adafruit IO

Using Adafruit IO and an Ethernet shield to collect analog measurements to the cloud with MQTT.

![Build](./assets/VoltageToAdafruitIO_build.jpg?raw=true)

[:arrow_forward: return to the LEAP Catalog](https://leap.tardate.com)

## Notes

I wanted a simple way to log the voltage of the rechargeable battery for
[LEAP#439 QX5252 Solar Night Light](../../../Electronics101/LedDrivers/QX5252SolarNightLight),
so I can measure the overnight discharge and daily solar recharge.

It didn't need to be particularly accurate, but I did want it to provide a fairly continuous log at least every 5 minutes or so.
Sounds like a perfect case for some Arduino-powered data logging!

I could just capture some data locally to an SD card, but sending the data to the "cloud" is much more appealing,
as it means I can access and do some analysis at any time without needing to be local to the device.

There are many established and roll-your-own solutions for this problem, but I've chosen to use this
as an opportunity to experiment with [Adafruit IO](https://learn.adafruit.com/welcome-to-adafruit-io).

Adafruit IO is a publically-hosted MQTT service that of course offers a free tier for experimentation,
and as you would expect Adafruit has libraries for Arduino, ESP8266, ESP32 and Python environments.
It also appears to be a pretty faithful implementation of the MQTT specification, so other MQTT libraries should work with it too.

MQTT is a pub-sub framework and can be used for bi-directional data transfer and control, but I'll only be using a fraction of
its capabilities (I just want to do some data collection in the cloud).

Adafruit IO has some basic dashboarding automatically built-in, which is enough to visualise the collected data.
But they do off many integration options for doing something with the data once collected, such as trigger [IFTTT](https://ifttt.com/) workflows.


## About MQTT

[MQTT](https://en.wikipedia.org/wiki/MQTT) (Message Queuing Telemetry Transport) is an ISO standard for pub-sub over TCP/IP,
designed for light-weight clients (like an Arduino) or where bandwidth is limited.
Development of MQTT is coordinated by the community at [mqtt.org](http://mqtt.org/).

MQTT protocol defines a binary control packet structure. There are 15 control packet types (0x0 and 0xF are reserved/forbidden):

| Control Packet | Payload  | Value | Description                                |
|----------------|----------|-------|--------------------------------------------|
| CONNECT        | Required | 0x1   | Client request to connect to Server        |
| CONNACK        | None     | 0x2   | Connect acknowledgment                     |
| PUBLISH        | Optional | 0x3   | Publish message                            |
| PUBACK         | None     | 0x4   | Publish acknowledgment                     |
| PUBREC         | None     | 0x5   | Publish received (assured delivery part 1) |
| PUBREL         | None     | 0x6   | Publish release (assured delivery part 2)  |
| PUBCOMP        | None     | 0x7   | Publish complete (assured delivery part 3) |
| SUBSCRIBE      | Required | 0x8   | Client subscribe request                   |
| SUBACK         | Required | 0x9   | Subscribe acknowledgment                   |
| UNSUBSCRIBE    | Required | 0xA   | Unsubscribe request                        |
| UNSUBACK       | None     | 0xB   | Unsubscribe acknowledgment                 |
| PINGREQ        | None     | 0xC   | PING request                               |
| PINGRESP       | None     | 0xD   | PING response                              |
| DISCONNECT     | None     | 0xE   | Client is disconnecting                    |


## Code

The code is a simple variation of the
[mqtt_ethernet.ino](https://github.com/adafruit/Adafruit_MQTT_Library/blob/master/examples/mqtt_ethernet/mqtt_ethernet.ino)
example from the [Adafruit MQTT Library](https://github.com/adafruit/Adafruit_MQTT_Library). Some variations:

* logs an analog reading from A0
* does not subscribe to any commands
* configuration is extracted in a separate header file that can be excluded from the repository (so keys are kept private)

## Resolution (or lack thereof)

The voltage readings I'm expecting will be in the 1-1.3V range. Direct sampling with a 5V Arduino Uno's analog pin
sacrifices a great deal of resolution - basically I'll have a [4.9mV](https://www.wolframalpha.com/input/?i=5V%2F1024) resolution.

That's not great, and could be improved with some off-board apmplification or higher resolution ADC,
but in this case I prefer to accept the lack of precision for the benefit of not needing any additional circuit components.


## Setting up Adafruit IO

It's pretty simple! Create an Adafruit account and use it for access to the [Adafruit IO](https://io.adafruit.com/) console.
The "View AIO Key" link provides the username and key details needed to configure an MQTT client.

The AIO username, key and feed name are defined in [settings.h](./settings.h).
Since this includes "secret" details, it is not checked into the repository.
Before compiling the source, copy [settings.h.template](./settings.h.template) to settings.h and fill in the required information.


## Adafruit IO Features

The Adafruit IO cloud service has 4 key components (on top of the MQTT infrastructure):

* Feeds - the "data bins" used to collect data/messages
* Dashboards - web tool for building simple interfaces to present data and controls
* Triggers - setup actions that can fire on a schedule or based on feed data values
* Services - a selection of third-party applications with pre-built integrations that can be enabled


### Feeds

With the script running, data will automatically be collected in the nominated feed.
The feed page provides direct access to the raw data (including export features), and also has basic charting to
get a sense of the data:

![aio_feed](./assets/aio_feed.png?raw=true)


### Dashboards

It is also very easy to create a custom dashboard that includes feed data:

![aio_dashboard](./assets/aio_dashboard.png?raw=true)

Dashboards are probably much more interesting with more data feeds and control interfaces!


### Triggers

Simple event-based or scheduled triggers are easy to setup. When fired, triggers can publish a message or call a webhook.
In the paid version they can also send email.

I setup a low-voltage trigger that calls a webhook:

![aio_create_trigger](./assets/aio_create_trigger.png?raw=true)

For testing purposes, I pointed it to a [Request Bin](https://github.com/Runscope/requestbin) instance.
Here's what an incoming event looks like:

![low_voltage_trigger_event](./assets/low_voltage_trigger_event.png?raw=true)

The event is a nice JSON structure, although I haven't been able to find a specification for this yet
(the [Triggers API doc](https://io.adafruit.com/api/docs/#tag/Triggers) appears a little deficient at the moment):

    [
      {
        "id":"0E1P8RT2BX7PBJ1M30XZRRM07A",
        "feed_id":945962,
        "value":"1129",
        "location":null,
        "created_at":"2018-12-18T14:38:50.303Z",
        "updated_at":"2018-12-18T14:38:50Z",
        "expiration":1547735930,
        "lat":null,
        "lon":null,
        "ele":null
      }
    ]


## Construction

Since I purposely avoided any external circuitry, this is about as simple as it gets:
tap the battery voltage to A0 and make sure the DUT has a common ground:

![Breadboard](./assets/VoltageToAdafruitIO_bb.jpg?raw=true)

![Schematic](./assets/VoltageToAdafruitIO_schematic.jpg?raw=true)


## Power Problems

After running some successful tests with the Arduino plugged into my Mac USB,
I switched to an external 12V/2A power supply in order to leave it running.
Within 15 minutes the Ethernet shield had locked up with an error.

After a little investigation, I'm suspecting the problem is the 5V regulator of my (cloned) Arduino is skewing low (4.7V) and perhaps not
delivering reliable current. Something to dig into and solve later...

For now, Ive avoided the problem by simply powering the unit with a regulated 5V supply direct to the 5V pin of the Arduino.
No more lock-ups.


## Conclusions

Adafruit IO is pretty amazing! It is extremely easy to get something simple up and running fast.
It doesn't over-reach in terms of its features (or price!), so I can see this being a great prototyping
platform for relatively straight-forward control and data collection.
But this also means you can probably imagine more ambitious projects that require more than Adafruit IO has to offer.

For my initial problem - log some data about the state of a rechargeable battery over a couple of daya - it was perfect.
Literally took me 10 minutes from signing up at Adafruit to when I had data streaming into a feed.
Doing more research on how it worked and writing these notes took far longer;-)


## Credits and References
* [Adafruit IO](https://learn.adafruit.com/welcome-to-adafruit-io)
* [Adafruit MQTT Library](https://github.com/adafruit/Adafruit_MQTT_Library)
* [MQTT](https://en.wikipedia.org/wiki/MQTT) - wikipedia
* [mqtt.org](http://mqtt.org/)
