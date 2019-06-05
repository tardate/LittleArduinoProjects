#include "charge_indicator.h"


ChargeIndicator::ChargeIndicator(int reset_led_pin, int recharge_led_pin, int deduct_led_pin) {
  this->reset_led_pin = reset_led_pin;
  this->recharge_led_pin = recharge_led_pin;
  this->deduct_led_pin = deduct_led_pin;
  end_state_delay = DEFAULT_DELAY;
}


void ChargeIndicator::begin() {
  pinMode(reset_led_pin, OUTPUT);
  pinMode(recharge_led_pin, OUTPUT);
  pinMode(deduct_led_pin, OUTPUT);
  hello();
}


void ChargeIndicator::start_charge() {
  end_state_delay = CHARGE_DELAY;
  digitalWrite(recharge_led_pin, HIGH);
}


void ChargeIndicator::start_reset() {
  end_state_delay = RESET_DELAY;
  digitalWrite(reset_led_pin, HIGH);
}


void ChargeIndicator::start_deduct() {
  end_state_delay = DEDUCT_DELAY;
  digitalWrite(deduct_led_pin, HIGH);
}


void ChargeIndicator::end_state() {
  delay(end_state_delay);
  end_state_delay = DEFAULT_DELAY;
  digitalWrite(reset_led_pin, LOW);
  digitalWrite(recharge_led_pin, LOW);
  digitalWrite(deduct_led_pin, LOW);
}


void ChargeIndicator::hello() {
  int duration = 100;
  flash(reset_led_pin, duration);
  flash(recharge_led_pin, duration);
  flash(deduct_led_pin, duration);
}


void ChargeIndicator::flash(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
}
