/*

  PublishingInternals
  Publishing live ESP32 system internals to the web

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/ESP32/PublishingInternals

 */

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#include <ArduinoJson.h>

#include "peripheral_interfaces.h"
#include "settings.h"

WebServer server(80);

const int INDICATOR_LED = 2;

void setup_write_indicator() {
  pinMode(INDICATOR_LED, OUTPUT);
  write_indicator(LOW);
}

void write_indicator(uint8_t status) {
  digitalWrite(INDICATOR_LED, status);
}

void handleRoot() {
  write_indicator(HIGH);

  char out[4500];
  snprintf(out, 4500, "<!doctype html><html lang=\"en\">\
<head>\
<meta charset=\"utf-8\">\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\
<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">\
</head>\
<body>\
<div class=\"container-fluid mt-3\">\
<div class=\"row\">\
<div class=\"col-3\">\
<div class=\"card\">\
<img src=\"https://leap.tardate.com/esp32/gettingstarted/assets/GettingStarted_build.jpg?raw=true\" class=\"card-img-top\">\
<div class=\"card-body\">\
<h5 class=\"card-title\">ESP32 Internals</h5>\
<p class=\"card-text\">Compiled on " __DATE__ " at " __TIME__ " with Arduino IDE %d</p>\
<p class=\"card-text\">Uptime: <span id=\"uptime\" class=\"badge badge-success\">00:00:00</span></p>\
<div id=\"freq_chart\"></div>\
</div>\
</div>\
</div>\
<div class=\"col-9\">\
<h2>Chip Temperature</h2><div id=\"temp_chart\"></div><h2>Sensors</h2><div id=\"sensor_chart\"></div>\
</div>\
</div>\
</div>\
<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js\"></script>\
<script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js\"></script>\
<script src=\"https://www.gstatic.com/charts/loader.js\"></script>\
<script type=\"text/javascript\">\
$( document ).ready(function() {\
google.charts.load('current', {'packages':['corechart', 'gauge']});\
google.charts.setOnLoadCallback(drawChart);\
function drawChart() {\
  var sample = 0;\
  var freq_data = google.visualization.arrayToDataTable([['Label','Value'],['CPU',0],['XTAL',0],['APB',0]]);\
  var freq_options = {redFrom: 200,redTo: 250,yellowFrom: 160, yellowTo: 200,greenFrom: 0, greenTo: 50,max: 250,minorTicks: 5};\
  var freq_chart = new google.visualization.Gauge(document.getElementById('freq_chart'));\
  freq_chart.draw(freq_data, freq_options);\
  var temp_data = google.visualization.arrayToDataTable([['Time','Chip Temp'],[0,0]]);\
  var temp_options = {curveType: 'function',legend: { position: 'none' },vAxis: { title: '°F', minValue: 0 },hAxis: { minValue: 0, textPosition: 'none' }};\
  var temp_chart = new google.visualization.LineChart(document.getElementById('temp_chart'));\
  temp_chart.draw(temp_data, temp_options);\
  var sensor_data = google.visualization.arrayToDataTable([['Sensor', 'Reading'],['Hall Effect', 0]]);\
  var sensor_options = {legend: { position: 'none' },hAxis: { minValue: 0, maxValue: 40 }};\
  var sensor_chart = new google.visualization.BarChart(document.getElementById('sensor_chart'));\
  sensor_chart.draw(sensor_data, sensor_options);\
  var sampler = function() {\
    $.ajax({\
      url: '/stats.json',\
      success: function( data ) {\
        sample = sample + 1;\
        $('#uptime').html( new Date(data.uptime).toISOString().substr(11, 8) );\
        freq_data.setValue(0, 1, data.cpu_mhz);\
        freq_data.setValue(1, 1, data.xtal_mhz);\
        freq_data.setValue(2, 1, data.apb_hz / 1000000 );\
        freq_chart.draw(freq_data, freq_options);\
        temp_data.addRow([sample, data.chip_temp]);\
        temp_chart.draw(temp_data, temp_options);\
        sensor_data.setValue(0, 1, data.hall_sensor);\
        sensor_chart.draw(sensor_data, sensor_options);\
        setTimeout(sampler, 1000);\
      }\
    });\
  };\
  sampler();\
};\
});\
</script>\
</body>\
</html>", ARDUINO);
  server.send(200, "text/html", out);

  write_indicator(LOW);
}

void handleStats() {
  digitalWrite(INDICATOR_LED, HIGH);

  char buffer[200];
  StaticJsonDocument<200> statsDocument;

  statsDocument["uptime"] = millis();
  statsDocument["chip_temp"] = temprature_sens_read();
  statsDocument["hall_sensor"] = hallRead();
  statsDocument["cpu_mhz"] = getCpuFrequencyMhz(); // clockCyclesPerMicrosecond();
  statsDocument["xtal_mhz"] = getXtalFrequencyMhz();
  statsDocument["apb_hz"] = getApbFrequency();

  serializeJson(statsDocument, buffer);
  server.send(200, "application/json", buffer);

  write_indicator(LOW);
}

void handleNotFound() {
  digitalWrite(INDICATOR_LED, HIGH);

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

  write_indicator(LOW);
}

void setup(void) {
  setup_write_indicator();

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/stats.json", handleStats);
  server.onNotFound(handleNotFound);

  server.enableCORS(); // allow cross-origin requests to the /stats.json endpoint (for testing purposes)

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
}
