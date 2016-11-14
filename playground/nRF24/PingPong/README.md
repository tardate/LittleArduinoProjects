# #187 nRF24/PingPong

Two Arduino's entertaining themselves with a game of "ping pong" over nRF24L01+ 2.4GHz RF.

Here's a quick video of a "game" in action:

[![nRF24/PingPong](http://img.youtube.com/vi/aNJqokwFAGI/0.jpg)](http://www.youtube.com/watch?v=aNJqokwFAGI)


[:arrow_forward: return to the LEAP Catalog](http://leap.tardate.com)

## Notes

This is a quick first test of Arudino 2.4GHz RF communications using nRF24L01+ modules.

I'm using the [maniacbug/RF24](https://github.com/maniacbug/RF24) library and the code is based on examples provided.

The [PingPong.ino](./PingPong.ino) script runs on both the "ping" and "pong" node. A ground link on pin 8 tells that aRduino to play "pong".
Here are the rules of the game:
* "ping" serves: sends a packet and flashes it's LED if successful, and waits for reply
* "pong" receives the message, flashes it's LED and sends the message back
* if/when "ping" gets the reply, it waits a bit and starts again (else logs an error before restarting).

This is not really stressing the communications, but a nice way to prove the basics are working.

NB: I'm using [these nRF24Breakout modules](../../../Electronics101/nRF24Breakout) to make it easy to breadboard the circuit.

### Connections

See the schematic for details. Here's the summary of pin connections to the nRF24L01+ module:

| Line | Arduino |
|------|---------|
| GND  | GND |
| 3V3  | 3V3 |
| CE   |   9 |
| CSN  |  10 |
| SCK  |  13 |
| MOSI |  11 |
| MISO |  12 |

### Power

According to the datasheet:
* 1.9 to 3.6V supply range
* 5V tolerant inputs (5.25V max)
* 60mA maximum power dissipation; 13.5mA RX at 2Mbps air data rate

That's almost perfect for driving with an Arduino Uno, with the exception of the maximum current draw:
* 5V GPIO pins are acceptable
* 3.3V pin is within the voltage supply range
* the [Arduino specifications](https://www.arduino.cc/en/Main/ArduinoBoardUno) state a 50mA limit for 3.3V Pin

But I'm going to chance it for a quick demo, as many others seem to have done quite succesfully.
For a fixed installation, I think I would provide a stiffer external 3.3V supply to avoid overloading the Arduino's onboard regulators.

In practice, I'm seeing no more than 14.8mA drawn by the nRF24L01+ module (send or receive).

## Construction

![Breadboard](./assets/PingPong_bb.jpg?raw=true)

![The Schematic](./assets/PingPong_schematic.jpg?raw=true)

![The Build](./assets/PingPong_build.jpg?raw=true)

## Credits and References
* [nRF24L01+ fritzing part](https://github.com/vdemay/fritzing-parts) - vdemay's GitHub repo
* [nRF24L01+ datasheet](http://www.nordicsemi.com/eng/content/download/2726/34069/file/nRF24L01P_Product_Specification_1_0.pdf)
* [maniacbug RF24](https://github.com/maniacbug/RF24) library
* [nRF24Breakout](../../../Electronics101/nRF24Breakout) - custom breadboard adapters for the nRF24L01+
* [..as mentioned on my blog](http://blog.tardate.com/2016/02/littlearduinoprojects187-nrf24l01-ping.html)
