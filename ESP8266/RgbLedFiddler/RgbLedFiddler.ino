/*

  RgbLedFiddler
  Using an HTML5 color picker on a web page hosted from an ESP8266 module (ESP12) to fine tune the color settings for an RGB LED.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/ESP8266/RgbLedFiddler

 */

// #define ENABLE_SERIAL_DEBUG

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
#include "settings.h"
#include "index_page.h"

// mDNS - will advertsise this server as (server_host_name).local
char server_host_name[] = "rgb-fiddler";

// TCP server at port 80 will respond to HTTP requests
ESP8266WebServer server(80);


// PWM outputs
const int PWM_RED_PIN = 13;
const int PWM_GREEN_PIN = 12;
const int PWM_BLUE_PIN = 14;
const int PWM_RANGE = 256;

// Current RGB PWM settings

volatile uint16_t rgb_r = 20;
volatile uint16_t rgb_g = 0;
volatile uint16_t rgb_b = 30;

/*
 * Command: server the main page
 */
void handleRoot() {
  server.send(200, "text/html", index_page);
}

String arg_red = "";
String arg_green = "";
String arg_blue = "";

/*
 * Command: server the current status
 */
void handleUpdate() {
  arg_red = server.arg("red");
  if (arg_red.length() != 0) rgb_r = arg_red.toInt();
  arg_green = server.arg("green");
  if (arg_green.length() != 0) rgb_g = arg_green.toInt();
  arg_blue = server.arg("blue");
  if (arg_blue.length() != 0) rgb_b = arg_blue.toInt();

  updateLedSettings();

  String message = "ok; rgb(" + String(rgb_r) + "," + String(rgb_g) + "," + String(rgb_b) + ")";
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", message);
}


/*
 * Command: simple 404
 */
void handleNotFound() {
  String message = "File Not Found\n\n";
  server.send ( 404, "text/plain", message );
}


/*
 * Command: startup wifi and webserver
 */
void wifiStartup() {
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print ( "." );
  }

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.println ( "" );
  Serial.print ( "Connected to " );
  Serial.println ( ssid );
  Serial.print ( "IP address: " );
  Serial.println ( WiFi.localIP() );
  #endif

  if (MDNS.begin(server_host_name)) {
    MDNS.addService("http", "tcp", 80);
  }

  // Start TCP (HTTP) server
  server.on("/", handleRoot);
  server.on("/update", handleUpdate);
  server.onNotFound (handleNotFound);
  server.begin();

  #ifdef ENABLE_SERIAL_DEBUG
  Serial.println ( "HTTP server started" );
  #endif
}


/*
 * Command: update LED RGB settings
 */
void updateLedSettings() {
  analogWrite(PWM_RED_PIN, PWM_RANGE - rgb_r);
  analogWrite(PWM_GREEN_PIN, PWM_RANGE - rgb_g);
  analogWrite(PWM_BLUE_PIN, PWM_RANGE - rgb_b);
}


/*
 * Command: one-time setup
 */
void setup() {
  #ifdef ENABLE_SERIAL_DEBUG
  Serial.begin ( 115200 );
  #endif

  pinMode(PWM_RED_PIN, OUTPUT);
  pinMode(PWM_GREEN_PIN, OUTPUT);
  pinMode(PWM_BLUE_PIN, OUTPUT);

  analogWriteRange(PWM_RANGE);

  wifiStartup();
}


/*
 * Command: main loop
 */
void loop() {
  server.handleClient();
}
