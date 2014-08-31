/*
 Get a random quote from http://www.iheartquotes.com/api/v1/random
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
  
 */

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
// See http://www.freetronics.com/pages/setting-arduino-ethernet-mac-address#.U_oa7oC1Z-g
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(174,129,20,208);
char server[] = "www.iheartquotes.com";

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192,168,0,177);

// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

int pushButton = 2;   // digital pin 2 has a pushbutton attached to it
int buttonStatus = 0; // track button status - normally pulled low

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT); // pushbutton's pin an input

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  Serial.println("firing up the Ethernet...");
  delay(1000);

  Serial.println("Press the button to get a quote!");
}

void loop()
{
  int buttonState = digitalRead(pushButton); // read the input pin

  if(buttonState!=buttonStatus) {
    // status has changed
    buttonStatus = buttonState;
    if(buttonStatus==1) getQuote();
  }

  delay(10);
}

void getQuote() {
  if(sendRequest()) {
    while(client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
      }
    }
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
  }
}

boolean sendRequest() {
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println("GET /api/v1/random HTTP/1.1");
    client.println("Host: www.iheartquotes.com");
    client.println("Connection: close");
    client.println();
    return true;
  }
  else {
    Serial.println("connection failed");
    return false;
  }
}
