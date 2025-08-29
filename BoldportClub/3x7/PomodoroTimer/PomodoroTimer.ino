/*

  3x7/PomodoroTimer
  A discrete Pomodoro timer using the Boldport 3x7 display and an ATmega328.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/BoldportClub/3x7/PomodoroTimer

 */

#include <avr/sleep.h>
#include <LRThreeDigits.h>

namespace ltd = lr::ThreeDigits;

// Supported application states
enum class AppMode : uint8_t {
    Setup,
    Running,
    Ended,
    Sleep
};

// Most time values work in deci-minutes (0.1 mins), and are named <prefix>_dm
// all other time values are in milliseconds

const uint16_t MS_TO_DM_DIVISOR     = 6000;
const uint16_t ADJUSTMENT_STEP_DM   = 50;
const uint16_t INITIAL_VALUE_DM     = 5 * ADJUSTMENT_STEP_DM; // must be a multiple for calcs to work correctly
const uint16_t DISPLAY_MIN_DM       = 0;
const uint16_t DISPLAY_MAX_DM       = 950;
const uint16_t LOOP_DELAY_MS        = 100;
const uint16_t IDLE_BEFORE_START_MS = 5000;
const uint8_t BTN_UP_PIN            = 2;
const uint8_t BTN_DOWN_PIN          = 3;

AppMode  current_mode;
uint16_t display_dm;
uint16_t started_dm;
unsigned long started_at;

volatile unsigned long last_button_press_at;
volatile boolean pressed_up = false;
volatile boolean pressed_down = false;

/*
 * Set button up flag on interrupt
 */
void handleButtonUp(void) {
  pressed_up = true;
  last_button_press_at = millis();
}

/*
 * Set button down flag on interrupt
 */
void handleButtonDown(void) {
  pressed_down = true;
  last_button_press_at = millis();
}

/*
 * Attach up/down buttons to interrupt handlers
 */
void setpuButtons(void) {
  pinMode(BTN_UP_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_UP_PIN), handleButtonUp, FALLING);
  pinMode(BTN_DOWN_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_DOWN_PIN), handleButtonDown, FALLING);
}

/*
 * Reset to initial state
 */
void resetApplication(void) {
  pressed_up = pressed_down = false;
  last_button_press_at = millis();
  display_dm = INITIAL_VALUE_DM;
  current_mode = AppMode::Setup;
}

/*
 * Put the processor to sleep
 */
void sleepApplication()  {
  current_mode = AppMode::Sleep;
  updateDisplay();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  cli();
  sleep_enable();
  sleep_bod_disable();
  sei();
  sleep_mode();
  sleep_disable();
  resetApplication();
}

/*
 * Start the timer
 */
void startPomodoroTimer(void) {
  current_mode = AppMode::Running;
  started_dm = display_dm;
  started_at = millis();
}

/*
 * Handle timer end
 */
void endPomodoroTimer(void) {
  last_button_press_at = millis();
  display_dm = 0;
  current_mode = AppMode::Ended;
}

/*
 * Calculate time and check if timer has finished the countdown
 */
void recalculateRemainingTime(void) {
  uint16_t elapsed_value = (millis() - started_at)/MS_TO_DM_DIVISOR;
  if(elapsed_value >= started_dm) {
    endPomodoroTimer();
  } else {
    display_dm = started_dm - elapsed_value;
  }
}

/*
 * Check if
 */
void checkForReset(void) {
  if(pressed_up || pressed_down) resetApplication();
}

/*
 * Update the 3x7 display
 */
void updateDisplay() {
  static boolean toggle = false;
  static char buffer[10];

  switch (current_mode) {
  case AppMode::Setup:
    if(toggle) strcpy(buffer, "   ");
    else sprintf(buffer, "%3d", display_dm);
    break;
  case AppMode::Running:
    sprintf(buffer, "%3d", display_dm);
    break;
  case AppMode::Ended:
    if(toggle) strcpy(buffer, " 0 ");
    else strcpy(buffer, "0 0");
    break;
  case AppMode::Sleep:
    strcpy(buffer, "   ");
    break;
  }

  ltd::setDigits(buffer);
  toggle = !toggle;
  delay(LOOP_DELAY_MS);
}

/*
 * Returns true if we should give up waiting for a button press
 */
boolean inputTimeout(void) {
  return  millis() - last_button_press_at > IDLE_BEFORE_START_MS;
}

/*
 * Init the 3x7, buttons and application settings
 */
void setup() {
  ltd::initialize(
    ltd::Frequency::Fast,
    ltd::Orientation::ConnectorOnTop,
    ltd::Pins::From4to13
  );
  setpuButtons();
  resetApplication();
}

/*
 * Evaluate next action, depending on current application mode
 */
void loop() {
  switch (current_mode) {
  case AppMode::Setup:
    if(inputTimeout()) startPomodoroTimer();
    else {
      if(pressed_up) {
        if(display_dm < DISPLAY_MAX_DM) display_dm += ADJUSTMENT_STEP_DM;
        pressed_up = false;
      }
      if(pressed_down) {
        if(display_dm > DISPLAY_MIN_DM) display_dm -= ADJUSTMENT_STEP_DM;
        pressed_down = false;
      }
    }
    break;
  case AppMode::Running:
    recalculateRemainingTime();
    checkForReset();
    break;
  case AppMode::Ended:
    if(inputTimeout()) sleepApplication();
    checkForReset();
    break;
  default:
    break;
  }
  updateDisplay();
}
