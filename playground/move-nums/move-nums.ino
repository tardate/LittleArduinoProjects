/*

  move-nums

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/main/playground/move-nums

 */
#include <stdlib.h>
#include <LedControl.h>
#include <Rotary.h>
#include "DigitDisplay.h"
#include "ButtonMonitor.h"
#include "EncoderState.h"
#include "MatrixDisplay.h"

const uint8_t LED7_CS_PIN = 9;
const uint8_t MATRIX_CS_PIN = 10;
const uint8_t MOSI_PIN = 11;
const uint8_t SCK_PIN = 13;

DigitDisplay n_display = DigitDisplay(MOSI_PIN, SCK_PIN, LED7_CS_PIN, -1, 1, 8);

LedControl lc = LedControl(MOSI_PIN, SCK_PIN, MATRIX_CS_PIN, 1);

const uint8_t ENCODER_INTERRUPT_A = 0;
const uint8_t ENCODER_INTERRUPT_B = 1;
const uint8_t ENCODER_PIN_A = 2;
const uint8_t ENCODER_PIN_B = 3;
const uint8_t ENCODER_PIN_SW = 4;

Rotary encoder = Rotary(ENCODER_PIN_A, ENCODER_PIN_B);
EncoderState encoder_state = EncoderState(1, 8);

ButtonMonitor button_monitor = ButtonMonitor(ENCODER_PIN_SW);

volatile bool flag_encoder_change = false;

MatrixDisplay matrix_display = MatrixDisplay(&lc);

enum Mode : uint8_t {
  ResetState = 0,
  Col1EntryState = 1,
  Col2EntryState = 2,
  Col3EntryState = 3,
  Col4EntryState = 4,
  Col5EntryState = 5,
  Col6EntryState = 6,
  Col7EntryState = 7,
  Col8EntryState = 8,
  DigitEntryState = 9,
  CalculateState = 10,
  WaitForResetState = 11
};

Mode current_state = ResetState;

/*
 * Command: move to next state
 */
void nextState() {
  if (current_state == WaitForResetState) {
    current_state = ResetState;
  } else {
    current_state = static_cast<Mode>(static_cast<uint8_t>(current_state) + 1);
  }
  encoder_state.reset();
}

/*
  Interrupt Service Routine:
  flags if encoder pin A or B has changed
 */
void flagEncoderChanged() {
  flag_encoder_change = true;
}

void encoderPositionUpdate() {
  if (flag_encoder_change) {
    encoder_state.process(encoder.process());
    flag_encoder_change = false;
  } else {
    encoder_state.clear();
  }
}

/*
 * Command: one-time setup
 */
void setup() {
  button_monitor.begin();
  matrix_display.begin();

  attachInterrupt(ENCODER_INTERRUPT_A, flagEncoderChanged, CHANGE);
  attachInterrupt(ENCODER_INTERRUPT_B, flagEncoderChanged, CHANGE);
}

/*
 * Command: main loop
 */
void loop() {
  encoderPositionUpdate();
  bool button_pressed = button_monitor.update();

  switch (current_state) {
    case ResetState:
      matrix_display.reset();
      n_display.reset();
      nextState();
      break;

    case Col1EntryState:
    case Col2EntryState:
    case Col3EntryState:
    case Col4EntryState:
    case Col5EntryState:
    case Col6EntryState:
    case Col7EntryState:
    case Col8EntryState:
      if (button_pressed && matrix_display.column_valid(current_state - 1)) {
        matrix_display.confirm_column(current_state - 1);
        nextState();
      } else if (encoder_state.has_changed) {
        matrix_display.update_column(current_state - 1, encoder_state.position);
      }
      break;

    case DigitEntryState:
      if (button_pressed && n_display.valid()) {
        nextState();
      } else if (encoder_state.has_changed) {
        n_display.set(encoder_state.position);
        n_display.update();
      }
      break;

    case CalculateState:
      matrix_display.moveNums(n_display.value());
      nextState();
      break;

    case WaitForResetState:
      if (button_pressed) nextState();
      break;
  }
}
