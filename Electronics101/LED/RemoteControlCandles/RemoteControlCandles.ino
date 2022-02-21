/*

  LED/RemoteControlCandles
  __subtitle__

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/Electronics101/LED/RemoteControlCandles

 */


#define IR_SEND_PIN 8
#define NO_LED_FEEDBACK_CODE

#include <IRremote.hpp>

#define CANDLE_ON 0x0
#define CANDLE_OFF 0x2
#define CANDLE_MODE_CANDLE 0xC
#define CANDLE_MODE_LIGHT 0xE
#define CANDLE_DIM_DOWN 0x10
#define CANDLE_DIM_UP 0x12
#define CANDLE_TIMER_2H 0x4
#define CANDLE_TIMER_4H 0x6
#define CANDLE_TIMER_6H 0x8
#define CANDLE_TIMER_8H 0xA

/*
 * Command: one-time setup
 */
void setup() {

  IrSender.begin();
  IrSender.enableIROut(38);
}


/*
 * Command: main loop
 */
void loop() {

  IrSender.sendNEC(0x0, CANDLE_ON, 2);
  delay(1000);

  IrSender.sendNEC(0x0, CANDLE_MODE_CANDLE, 1);
  delay(5000);

  IrSender.sendNEC(0x0, CANDLE_MODE_LIGHT, 1);
  delay(1000);

  IrSender.sendNEC(0x0, CANDLE_DIM_DOWN, 1);
  delay(2000);
  IrSender.sendNEC(0x0, CANDLE_DIM_DOWN, 1);
  delay(2000);
  IrSender.sendNEC(0x0, CANDLE_DIM_DOWN, 1);
  delay(2000);

  IrSender.sendNEC(0x0, CANDLE_OFF, 2);
  delay(2000);
}

