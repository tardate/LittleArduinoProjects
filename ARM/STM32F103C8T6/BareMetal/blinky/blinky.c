#include "delay.h"
#include "led.h"

void setup() {
  led_enable();
}

void loop() {
  led_on();
  delay(500);
  led_off();
  delay(500);

  led_on();
  delay(250);
  led_off();
  delay(250);

  led_on();
  delay(125);
  led_off();
  delay(125);
}

int main(void) {
  setup();
  for(;;) {
    loop();
  }
}
