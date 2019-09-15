/*

  GettingStarted
  Testing with the wifi scan example

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/ESP32/GettingStarted

 */
#include "WiFi.h"

const int DELAY_BETWEEN_SCANS = 5000;
const int DELAY_BETWEEN_SSIDS = 10;

void setup() {
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
}

void loop() {
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int number_of_networks = WiFi.scanNetworks();
    Serial.println("scan done");
    if (number_of_networks == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(number_of_networks);
        Serial.println(" networks found");
        for (int i = 0; i < number_of_networks; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
                Serial.println(" [open]");
            } else {
                Serial.println(" [secure]");
            }
            delay(DELAY_BETWEEN_SSIDS);
        }
    }
    Serial.println();

    delay(DELAY_BETWEEN_SCANS);
}