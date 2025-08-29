/*

  FootSwitch
  Simple demonstration of rthe 4-channle foot switch with tri-color LED indicators

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/Electronics101/InputDevices/FootSwitch

 */

// software debounce fudge factor
const int DEBOUNCE_DELAY = 150;

// pins for the shift register control
const int DS_DATA_PIN = 3;
const int ST_CP_LATCH_PIN = 4;
const int SH_CP_CLOCK_PIN = 5;

// switch inputs (active high)
const int SW0_PIN = 6;
const int SW1_PIN = 7;
const int SW2_PIN = 8;
const int SW3_PIN = 9;

/* register_data maps the 16 bits
 bit | LED# | color (active low)
  0  |      |
  1  |      |
  2  | 3    | red
  3  | 3    | green
  4  | 3    | blue
  5  | 2    | red
  6  | 2    | green
  7  | 2    | blue
  8  |      |
  9  |      |
 10  | 1    | red
 11  | 1    | green
 12  | 1    | blue
 13  | 0    | red
 14  | 0    | green
 15  | 0    | blue
*/
uint16_t register_data = 0xFFFF;

// number of bits into register_data that the individual leds are found:
uint16_t led_offset[] = {13, 10, 5, 2};

// track LED states with mnemonics
enum class LedMode : uint8_t {
    red = 0,
    green = 1,
    blue = 2,
    off = 3
};

// current states for the 4 LEDs
LedMode led_mode[] = {
  LedMode::off,
  LedMode::off,
  LedMode::off,
  LedMode::off
};


/*
 * Command: one-time setup
 */
void setup() {
  pinMode(DS_DATA_PIN, OUTPUT);
  pinMode(ST_CP_LATCH_PIN, OUTPUT);
  pinMode(SH_CP_CLOCK_PIN, OUTPUT);
  pinMode(SW0_PIN, INPUT);
  pinMode(SW1_PIN, INPUT);
  pinMode(SW2_PIN, INPUT);
  pinMode(SW3_PIN, INPUT);
  pushLedSettings();
}


/*
 * Command: main loop
 */
void loop() {
  if (switchPressed()) {
    updateRegisterData();
    pushLedSettings();
  }
  delay(DEBOUNCE_DELAY);
}


/*
 * Command: recalculates the correct register data
 */
void updateRegisterData() {
  register_data = 0xFFFF;
  for(int led = 0; led < 4; ++led) {
    if (led_mode[led] != LedMode::off) {
      register_data &= ~bit(led_offset[led] + (uint8_t)led_mode[led]);
    }
  }
}


/*
 * Command: push the led_values to the shift registers
 */
void pushLedSettings() {
  digitalWrite(ST_CP_LATCH_PIN, LOW);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, register_data >> 8);
  shiftOut(DS_DATA_PIN, SH_CP_CLOCK_PIN, MSBFIRST, register_data);
  digitalWrite(ST_CP_LATCH_PIN, HIGH);
}


/*
 * Command: cycle the color for the specified led
 */
void stepLedMode(int led) {
  switch (led_mode[led]) {
  case LedMode::off:
    led_mode[led] = LedMode::red;
    break;
  case LedMode::red:
    led_mode[led] = LedMode::green;
    break;
  case LedMode::green:
    led_mode[led] = LedMode::blue;
    break;
  case LedMode::blue:
    led_mode[led] = LedMode::off;
    break;
  }
}


/*
 * Command: handle button presses
 */
bool switchPressed() {
  bool result = false;
  if(digitalRead(SW0_PIN)) {
    stepLedMode(0);
    result = true;
  }
  if(digitalRead(SW1_PIN)) {
    stepLedMode(1);
    result = true;
  }
  if(digitalRead(SW2_PIN)) {
    stepLedMode(2);
    result = true;
  }
  if(digitalRead(SW3_PIN)) {
    stepLedMode(3);
    result = true;
  }
  return result;
}
