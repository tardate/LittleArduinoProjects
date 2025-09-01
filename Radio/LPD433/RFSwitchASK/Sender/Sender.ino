/*

  RFSwitchASK/Sender
  Simple ASK RF Transmitter with LED indicator

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Radio/LPD433/RFSwitchASK

 */

#define CYCLE_TIME 1000
#define INDICATOR_PIN 6

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
  Serial.begin(115200);
  pinMode(INDICATOR_PIN, OUTPUT);
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

boolean current_state = false;

void loop()
{
  current_state = !current_state;
  if(current_state) sendOn();
  else sendOff();
  delay(CYCLE_TIME);
}

void sendOn() {
  char *msg = "on";
  digitalWrite(INDICATOR_PIN, HIGH);
  sendMessage(msg);
}

void sendOff() {
  char *msg = "off";
  digitalWrite(INDICATOR_PIN, LOW);
  sendMessage(msg);
}

void sendMessage(char *msg) {
  Serial.print("sending: ");
  Serial.println(msg);

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
}
