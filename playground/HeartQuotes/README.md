# Heart Quotes

Press a button to snaffle a random quote from [Heart Quotes](http://www.iheartquotes.com).

![The Build](./assets/HeartQuotes_console.jpg?raw=true)

## Parts for a breadboard build

* [Arduino Uno R3](http://www.amazon.com/gp/product/B00F6JCV20/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00F6JCV20&linkCode=as2&tag=itsaprli-20&linkId=O34GVKFAZ6FVDC6W) or similar
* [Arduino Ethernet Shield](http://www.amazon.com/gp/product/B00EU7447Y/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00EU7447Y&linkCode=as2&tag=itsaprli-20&linkId=QJYL7QLWFGQVGUF5)
* Breadboard
* [4 Pin DIP PCB Momentary Push Button Tactile Switch](http://www.amazon.com/gp/product/B008MLKJ3C/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B008MLKJ3C&linkCode=as2&tag=itsaprli-20&linkId=6UORZDXT6S7AZRZ7)

![The Breadboard Schematic](./assets/HeartQuotes_bb.jpg?raw=true)

## Notes

This currently just dumps the web resonse from the HeartQuotes API to the console. Next steps:
* parse the response
* send it to a more appropriate output (LCD panel?)

The 220R resistor connecting +5V to the switch is not really required, and is included more as a link on the breadboard.
From [Digital Pins](http://arduino.cc/en/Tutorial/DigitalPins):
"Pins configured [as INPUT] are said to be in a high-impedance state. Input pins make extremely small demands on the circuit that they are sampling, equivalent to a series resistor of 100 megohm in front of the pin."

### Example console output

    firing up the Ethernet...
    Press the button to get a quote!
    connected
    HTTP/1.1 200 OK
    Server: nginx
    Date: Sun, 31 Aug 2014 08:53:17 GMT
    Content-Type: text/plain
    Transfer-Encoding: chunked
    Connection: close
    Etag: "5f59f18f4aed49a700f89924b7394229"
    X-Ua-Compatible: IE=Edge,chrome=1
    X-Runtime: 0.070795
    Cache-Control: max-age=0, private, must-revalidate

    a2
    Auribus teneo lupum.
      [I hold a wolf by the ears.]
      [Boy, it *sounds* good.  But what does it *mean*?]

    [codehappy] http://iheartquotes.com/fortune/show/31282

    0


    disconnecting.


## Credits and references
* Based on the Arduino WebClient example http://arduino.cc/en/Tutorial/WebClient
