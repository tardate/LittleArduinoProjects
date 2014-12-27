/*

  HeartQuotes

  Get a random quote from http://www.iheartquotes.com/api/v1/random

  Circuit:
  * Ethernet shield attached to pins 10, 11, 12, 13

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/HeartQuotes

 */

#include <SPI.h>
#include <Ethernet.h>
#include <LiquidCrystal.h>

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

LiquidCrystal lcd(8, 9, 6, 4, 3, 2);

int pushButton = 7;   // digital pin has a pushbutton attached to it
int buttonStatus = 0; // track button status - normally pulled low

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT); // pushbutton's pin an input

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  Serial.println("firing up the Ethernet...");
  delay(1000);

  Serial.println("Press the button to get a quote!");

  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.print("Press the button to get a quote!");
  lcd.autoscroll();

}

void loop()
{
  int buttonState = digitalRead(pushButton); // read the input pin

  if(buttonState!=buttonStatus) {
    // status has changed
    buttonStatus = buttonState;
    if(buttonStatus==1) getQuote();
  }

  delay(15);
}

void getQuote() {
  if(sendRequest()) {
    String response = String("");
    while(client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c != -1) response += c;
      }
    }

    // this feels very hackety - and it is! It finds the body section of the response, skips a line,
    // then the quote will be the rest of the line - which may end in \r or \n (it seems to vary)
    // ... and if any of that fails, this will probably blow up!
    int bodyBreak = response.indexOf("\r\n\r\n") + 4;
    int quoteStart = response.indexOf("\r\n", bodyBreak) + 2;
    int quoteEndA = response.indexOf("\r", quoteStart);
    int quoteEndB = response.indexOf("\n", quoteStart);
    int quoteEnd = (quoteEndA > quoteEndB) ? quoteEndB : quoteEndA;

    String quote = response.substring(quoteStart,quoteEnd);

    displayQuote(quote);
    client.stop();
  }
}

boolean sendRequest() {
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println("GET /api/v1/random?max_lines=1&max_characters=32&show_permalink=0&show_source=0 HTTP/1.1");
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

void displayQuote(String quote) {
  Serial.print("quote: ");
  Serial.println(quote);
  Serial.println("disconnecting.");
  lcd.clear();

  lcd.setCursor(16,0);
  for (int thisChar = 0; thisChar < quote.length(); thisChar++) {
    lcd.print(quote[thisChar]);
    delay(250);
  }

}
