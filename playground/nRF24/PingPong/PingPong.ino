/*

  nRF24/PingPong
  Two Arduino's entertaining themselves with a "ping pong" game over nRF24L01+ 2.4GHz RF.
  Largely "stolen" from the RF24 library example code from https://github.com/maniacbug/RF24

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/nRF24/PingPong

 */

#define CE_PIN 9
#define CSN_PIN 10
#define ROLE_PIN 8 //  Connect to GND to be the 'pong' receiver, unconnected on the 'ping' transmitter
#define LED_PIN 7

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

// Radio pipe addresses for the 2 nodes to communicate.
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

RF24 radio(CE_PIN, CSN_PIN);

#define ROLE_PING 0
#define ROLE_PONG 1
int role;


void setup() {

  // read the role
  pinMode(ROLE_PIN, INPUT);
  digitalWrite(ROLE_PIN,HIGH);
  delay(20);
  if ( digitalRead(ROLE_PIN) ) role = ROLE_PING;
  else role = ROLE_PONG;

  // init LED control
  pinMode(LED_PIN, OUTPUT);

  // init serial debug
  Serial.begin(9600);
  Serial.println("role:");
  Serial.println(role);

  // Setup and configure rf radio
  radio.begin();

  // optionally, increase the delay between retries & # of retries
  radio.setRetries(15,15);

  // optionally, reduce the payload size; seems to improve reliability
  radio.setPayloadSize(8);

  radio.openWritingPipe(pipes[role]);
  radio.openReadingPipe(1,pipes[role ^ 1]);

  radio.startListening();
}


void loop() {
  if(role==ROLE_PING) ping();
  else pong();
}


void ping() {

  // send a message
  radio.stopListening();
  unsigned long message = 1;
  bool ok = radio.write( &message, sizeof(unsigned long) );
  radio.startListening();

  if(ok) {
    Serial.println("ping ok...");
    flash();

    // read reply (or timeout)
    unsigned long started_waiting_at = millis();
    bool timeout = false;
    while ( ! radio.available() && ! timeout )
      if (millis() - started_waiting_at > 200 )
        timeout = true;

    if ( timeout ) {
      Serial.println("Failed, response timed out.");
    } else {
      unsigned long message_in;
      radio.read( &message_in, sizeof(unsigned long) );

      if(message_in==message) {
        Serial.println("Correct response!");
      } else {
        Serial.println("Got unexpected response:");
        Serial.println(message_in);
      }
    }
  } else {
    Serial.println("ping failed...");
  }

  delay(1000);
}

void pong() {
  if ( radio.available() ) {
    unsigned long message;
    bool done = false;

    while (!done) {
      delay(20);
      done = radio.read( &message, sizeof(unsigned long) );
    }

    flash();

    // pong back the message
    radio.stopListening();
    radio.write( &message, sizeof(unsigned long) );
    radio.startListening();

  }
}

void flash() {
  digitalWrite(LED_PIN,HIGH);
  delay(200);
  digitalWrite(LED_PIN,LOW);
}
