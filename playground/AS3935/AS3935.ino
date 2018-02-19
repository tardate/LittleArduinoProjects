/*

  AS3935
  Using the AMS AS3935 Franklin Lightning Sensor with an Arduino over I²C.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/AS3935

 */


#include "AS3935_controller.h"
#include "display_controller.h"

const int LCD_CSN_PIN = 8;
const int LCD_SS_PIN = 9;
const int LCD_RST_PIN = 10;

const uint8_t AS3935_ADDRESS = 3;
const uint8_t AS3935_INT_PIN = 2;

volatile bool lightning_flag = false;

AS3935Controller as3935_controller(AS3935_ADDRESS, AS3935_INT_PIN);
Adafruit_PCD8544 display_driver(LCD_CSN_PIN, LCD_SS_PIN, LCD_RST_PIN);
DisplayController display_controller(&display_driver, &as3935_controller);


/*
 * Command: standard setup - init hardware and print AS3935 settings
 */
void setup() {
  as3935_controller.begin();

  display_controller.begin();
  display_controller.welcome();
  display_controller.showConfig();
  display_controller.waiting();

  enableLightningInterrupt();
}


/*
 * Command: standard loop - handles lightenting event when triggered
 */
void loop() {
  if(lightning_flag) {
    display_controller.lightningWarning();
    lightning_flag = false;
  }
}


/*
 * Command: enable hardware interrupt from MCP23017 INTA
 */
void enableLightningInterrupt() {
  pinMode(AS3935_INT_PIN, INPUT);
  delay(200);
  attachInterrupt(digitalPinToInterrupt(AS3935_INT_PIN), flagLightningInterrupt, RISING);
}


/*
 * Command: INTA interrupt handler
 */
void flagLightningInterrupt() {
  lightning_flag = true;
}
