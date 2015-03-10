/*

  HitTheLights
  A simple LED game with LCD output
  .. started as a response to http://electronics.stackexchange.com/questions/93269/arduino-uno-r3-plus-digital-pins-overused

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/HitTheLights

 */

#define BUTTON_PIN 2
#define BUTTON_INTERRUPT 0
#define LED_PIN_OFFSET 3
#define LED_COUNT 4

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
#define LCD_rs      7
#define LCD_enable  8
#define LCD_d4      9
#define LCD_d5     10
#define LCD_d6     11
#define LCD_d7     12
LiquidCrystal lcd(LCD_rs, LCD_enable, LCD_d4, LCD_d5, LCD_d6, LCD_d7);

volatile int currentLED = LED_PIN_OFFSET;
volatile int currentState = 0;
volatile int nextTarget = LED_COUNT;   // the ordinal index of the next LED that needs a hit. Game over when down to 0
int highScore = 0;
int startTime;

int onTimeDelay = 500;
int pauseTimeDelay = 200;

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  // initialise the LED outputs
  for(int p = LED_PIN_OFFSET; p < LED_PIN_OFFSET + LED_COUNT; p++) {
    pinMode(p, OUTPUT);
  }

  // initialise the LCD output for 16x2 and say hi
  lcd.begin(16, 2);
  resetGame();

  attachInterrupt(BUTTON_INTERRUPT, buttonPress, RISING);
}

void resetGame() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hit the Lights!");
  startTime = millis();
  nextTarget = LED_COUNT;
  currentState = 0;
}

void updateProgress() {
  lcd.setCursor(0, 1);
  lcd.print((millis() - startTime)/1000);
  lcd.print("s");
  if(highScore > 0) {
    lcd.print(" HS:");
    lcd.print(highScore/1000);
  }
}

void buttonPress() {
  if(currentState==1 && currentLED == LED_PIN_OFFSET + nextTarget - 1) { // score!
    nextTarget--;
  }
}

void win() {
  int score = millis() - startTime;
  lcd.setCursor(0, 1);
  if(highScore == 0 || score<highScore) {
    highScore = score;
    lcd.print("High Score! ");
  } else {
    lcd.print("Score: ");
  }
  lcd.print(score/1000);
  lcd.print("s");
  delay(5000);
  resetGame();
}


void loop(){

  for(currentLED = LED_PIN_OFFSET; currentLED < LED_PIN_OFFSET + nextTarget; currentLED++) {
    updateProgress();
    delay(pauseTimeDelay);
    currentState = 1;
    digitalWrite(currentLED, HIGH);
    delay(onTimeDelay);
    digitalWrite(currentLED, LOW);
    currentState = 0;
  }
  if(nextTarget==0) win();

}
