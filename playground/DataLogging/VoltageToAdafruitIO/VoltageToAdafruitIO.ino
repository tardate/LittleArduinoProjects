/*

  DataLogging/VoltageToAdafruitIO
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/DataLogging/VoltageToAdafruitIO

 */
#include <SPI.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#include <Ethernet.h>
#include <EthernetClient.h>
#include <Dns.h>
#include <Dhcp.h>

#include "settings.h"

const int VOLTAGE_PIN = A0;
const int SECONDS_PER_SAMPLE = 30;


//Set up the ethernet client
EthernetClient client;


Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);


// MQQT Feed
Adafruit_MQTT_Publish batteryvoltage = Adafruit_MQTT_Publish(&mqtt,  AIO_FEED);


// Function to connect and reconnect as necessary to the MQTT server.
// Ensures the connection to the MQTT server is alive.
// Should be called in the loop function and it will take care of connecting
// and automatically reconnect when disconnected.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
  }
  Serial.println("MQTT Connected!");
}


// function for getting the latest reading scaled to mV
uint32_t readVoltage() {
  return map(analogRead(VOLTAGE_PIN), 0, 1023, 0, 5000);
}


// Publish the latest analog reading
void publishLatestReading() {
  uint32_t milliVolts = readVoltage();

  Serial.print(F("\nSending battery voltage "));
  Serial.print(milliVolts);
  Serial.print("...");
  if (! batteryvoltage.publish(milliVolts)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
}


void setup() {
  Serial.begin(115200);
  Serial.print(F("\nInit the MQTT Client..."));
  Ethernet.begin(mac);
  delay(1000); // give ethernet time to startup
}


void loop() {
  MQTT_connect();

  publishLatestReading();

  // ping the server to keep the mqtt connection alive or cleanly disconnect
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }

  for(int s=0; s<SECONDS_PER_SAMPLE; ++s) {
    delay(1000);
  }
}
