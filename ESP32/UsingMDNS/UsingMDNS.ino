/*

  UsingMDNS
  Delving into multicast DNS and how it can be used to find and connect to ESP32 devices on the network

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/ESP32/UsingMDNS

 */

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#include "settings.h"

WebServer server(80);

char hostname[] = "esp32-using-mdns";


void handleRoot() {
  IPAddress ip = WiFi.localIP();

  char out[4500];
  snprintf(out, 4500, "<!doctype html><html lang=\"en\">\
<head>\
<meta charset=\"utf-8\">\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\
</head>\
<body>\
<h1>UsingMDNS</h1>\
<p>Hostname: %s.local</p>\
<p>IP address: %d.%d.%d.%d</p>\
</body>\
</html>", hostname, ip[0], ip[1], ip[2], ip[3]);
  server.send(200, "text/html", out);
}


void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}


void setup(void) {
  Serial.begin(115200);

  // Connect to WiFi network
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nConnected to ");
  Serial.print(ssid);
  Serial.print(" SSID with IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(hostname)) {
    Serial.print("mDNS responder started, advertised as ");
    Serial.print(hostname);
    Serial.println(".local");

    // (optional) Register standard HTTP service
    MDNS.addService("http", "tcp", 80);

    // (optional) Register an arbitrary service name
    MDNS.addService("leap", "tcp", 80);

    // (optional) Register arduino details
    MDNS.enableArduino(80, false);

  } else {
    Serial.println("Error setting up MDNS responder!");
  }

  // Start TCP (HTTP) server
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}


void loop(void) {
  server.handleClient();
}
