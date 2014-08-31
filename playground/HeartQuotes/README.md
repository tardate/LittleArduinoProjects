# Heart Quotes

Press a button to snaffle a random quote from [Heart Quotes](http://www.iheartquotes.com) and print it to a 16x2 LCD.

![The Build](./assets/HeartQuotes_lcd.jpg?raw=true)

## Parts for a breadboard build

* [Arduino Uno R3](http://www.amazon.com/gp/product/B00F6JCV20/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00F6JCV20&linkCode=as2&tag=itsaprli-20&linkId=O34GVKFAZ6FVDC6W) or similar
* [Arduino Ethernet Shield](http://www.amazon.com/gp/product/B00EU7447Y/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B00EU7447Y&linkCode=as2&tag=itsaprli-20&linkId=QJYL7QLWFGQVGUF5)
* Breadboard
* [4 Pin DIP PCB Momentary Push Button Tactile Switch](http://www.amazon.com/gp/product/B008MLKJ3C/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B008MLKJ3C&linkCode=as2&tag=itsaprli-20&linkId=6UORZDXT6S7AZRZ7)
* 16x2 LCD (I used a [QC1602A](./../BetterWithBacon/assets/LCD_QC1602A_datasheet.pdf?raw=true "QC1602A Datasheet"))

![The Breadboard Schematic](./assets/HeartQuotes_bb.jpg?raw=true)

## Notes

This currently just dumps the web response from the HeartQuotes API to the console and LCD panel.

The 220R resistor connecting +5V to the switch is not really required, and is included more as a link on the breadboard.
From [Digital Pins](http://arduino.cc/en/Tutorial/DigitalPins):
"Pins configured [as INPUT] are said to be in a high-impedance state. Input pins make extremely small demands on the circuit that they are sampling, equivalent to a series resistor of 100 megohm in front of the pin."

### Sample console output

    firing up the Ethernet...
    Press the button to get a quote!
    connected
    quote: The days of good English has went.
    disconnecting.


### Sample raw response from iheartquotes.com
This gets parsed down into just the actual "quote" part:

    $ curl -i --raw "http://iheartquotes.com/api/v1/random?max_lines=1&show_permalink=0&show_source=0&format=text"
    HTTP/1.1 200 OK
    Server: nginx
    Date: Sun, 31 Aug 2014 12:44:12 GMT
    Content-Type: text/plain
    Transfer-Encoding: chunked
    Connection: keep-alive
    Etag: "e8b7717bb327ac927a8f9e49744382a5"
    X-Ua-Compatible: IE=Edge,chrome=1
    X-Runtime: 0.083509
    Cache-Control: max-age=0, private, must-revalidate

    3c
    Biz is better.

    http://iheartquotes.com/fortune/show/34841

    0

![Console Output](./assets/HeartQuotes_console.jpg?raw=true)

## Credits and references
* HTTP GET based on the Arduino WebClient example http://arduino.cc/en/Tutorial/WebClient
* LCD output based on the Arduino LiquidCrystal examples http://arduino.cc/en/Tutorial/LiquidCrystal
