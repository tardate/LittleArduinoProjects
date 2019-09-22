/*

  RFSwitchASK/Receiver
  Simple ASK RF Receiver with LED indicator

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Radio/LPD433/RFSwitchASK

 */

#define INDICATOR_PIN 6

#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

void setup() {
  Serial.begin(115200); // only used for debugging
  pinMode(INDICATOR_PIN, OUTPUT);
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

void loop()
{
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    // Message with a good checksum received, dump it.
    driver.printBuffer("Got:", buf, buflen);
    buf[buflen] = 0; // because the driver doesn't know it is meant to be a string
    Serial.print("text: ");
    Serial.println((char *) buf);

    if ( strcmp((char *) buf, "on") == 0 ) {
      digitalWrite(INDICATOR_PIN, HIGH);
    } else {
      digitalWrite(INDICATOR_PIN, LOW);
    }

  }
}

