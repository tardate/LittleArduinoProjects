#include "led.h"

// MODE13[1:0] is bits 21,20.
#define PC13_MODE_BP ((PC13 - 8) * 4)

// CNF13[1:0] is bits 23,22.
#define PC13_CRH_BP (PC13_MODE_BP + 2)

void led_enable(void) {
  uint32_t *pRCC_APB2ENR = (uint32_t *)RCC_APB2ENR;
  uint32_t *pGPIOC_CRH = (uint32_t *)GPIOC_CRH;

  // RCC_APB2ENR: Set IOPC_EN 1: :I/O port C clock enabled
  *pRCC_APB2ENR |= ( 1 << IOPC_EN );

  // CRH: Set to 00: General purpose output push-pull
  *pGPIOC_CRH &= ~( 0b11 << PC13_CRH_BP );  // clear bits

  // MODE: Set to 01: Output mode, max speed 10 MHz.
  *pGPIOC_CRH &= ~( 0b11 << PC13_MODE_BP );  // clear bits
  *pGPIOC_CRH |= ( 0b01 << PC13_MODE_BP );   // set the new value

  led_off();
}

void led_on(void) {
  uint32_t *pGPIOC_ODR = (uint32_t *)GPIOC_ODR;
  *pGPIOC_ODR |= ( 1 << PC13);
}

void led_off(void) {
  uint32_t *pGPIOC_ODR = (uint32_t *)GPIOC_ODR;
  *pGPIOC_ODR  &= ~( 1 << PC13);
}
