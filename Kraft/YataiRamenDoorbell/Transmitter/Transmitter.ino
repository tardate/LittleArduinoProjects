/*

  YataiRamenDoorbell
  Transmitter

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Kraft/YataiRamenDoorbell

 */

const int INDICATOR_PIN = 5;
const int POWERHOLD_PIN = 6;

const int RX_PIN = 3;
const int TX_PIN = 4;

const int RH_BPS = 2000;

const int TX_REPEATS = 4;
const int TX_DELAY = 250;

#include <RH_ASK.h>

RH_ASK driver(RH_BPS, RX_PIN, TX_PIN);

void setup() {
  keepAlive();
  performOperation();
  gotoSleep();
}

void loop() {
  // there is no loop function. This is a one-shot sketch
}

void performOperation() {
  pinMode(INDICATOR_PIN, OUTPUT);
  driver.init();
  for (int i=0; i<TX_REPEATS; ++i) {
    // repeat the message to make sure it gets through
    sendSignal();
    delay(TX_DELAY);
  }
}

void keepAlive() {
  // set the power pin high to keep the processor alive
  pinMode(POWERHOLD_PIN, OUTPUT);
  digitalWrite(POWERHOLD_PIN, HIGH);
}

void gotoSleep() {
  // switch the power-pin to high-impedence input state
  pinMode(POWERHOLD_PIN, INPUT);
  // we should have powered-down by this point.
}

void sendSignal() {
  char *msg = "b";

  digitalWrite(INDICATOR_PIN, HIGH);

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();

  digitalWrite(INDICATOR_PIN, LOW);
}
