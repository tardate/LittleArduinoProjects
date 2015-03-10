/*

  LedGame
  .. a response to http://electronics.stackexchange.com/questions/93269/arduino-uno-r3-plus-digital-pins-overused

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/LedGame

 */

#define LED_PIN_OFFSET 2

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
#define LCD_rs      6
#define LCD_enable  7
#define LCD_d4      9
#define LCD_d5     10
#define LCD_d6     11
#define LCD_d7     12
LiquidCrystal lcd(LCD_rs, LCD_enable, LCD_d4, LCD_d5, LCD_d6, LCD_d7);

int currentLED = LED_PIN_OFFSET;
int delayValue = 200;

void setup() {
  // pinMode(1, INPUT); //Button

  // initialise the LED outputs
  pinMode(LED_PIN_OFFSET, OUTPUT);
  pinMode(LED_PIN_OFFSET + 1, OUTPUT);
  pinMode(LED_PIN_OFFSET + 2, OUTPUT);
  pinMode(LED_PIN_OFFSET + 3, OUTPUT);

  // initialise the LCD output for 16x2 and say hi
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop(){

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);

  /* NYI - what should the buttons do?
  if(digitalRead(1) == 0){
    if(currentLED == 4) {
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
      delay(200);
      digitalWrite(4, HIGH);
      delay(200);
      digitalWrite(4, LOW);
      delay(200);
      delayValue = delayValue - 10;
    } else {
      digitalWrite(currentLED, HIGH);
      delay(200);
      digitalWrite(currentLED, LOW);
      delay(200);
      digitalWrite(currentLED, HIGH);
      delay(200);
      digitalWrite(currentLED, LOW);
      delay(200);
    }
  }
  */

  digitalWrite(currentLED, HIGH);
  delay(delayValue);
  digitalWrite(currentLED, LOW);
  delay(delayValue);

  if(currentLED == LED_PIN_OFFSET + 3) {
    currentLED = LED_PIN_OFFSET;
  } else {
    currentLED++;
  }

}
