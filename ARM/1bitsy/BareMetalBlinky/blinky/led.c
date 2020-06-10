#include "led.h"

// offset when [1:0] is bits 17, 16.
#define PA8_2BIT_BP (PA8 * 2)

void led_enable(void) {
  uint32_t *pRCC_AHB1ENR = (uint32_t *)RCC_AHB1ENR;
  uint32_t *pGPIOA_MODER = (uint32_t *)GPIOA_MODER;
  uint32_t *pGPIOA_OTYPER = (uint32_t *)GPIOA_OTYPER;
  uint32_t *pGPIOA_PUPDR = (uint32_t *)GPIOA_PUPDR;

  // RCC_AHB1ENR: Set GPIOAEN I/O port A clock enabled
  *pRCC_AHB1ENR |= ( 1 << GPIOAEN );

  // GPIOx_MODER: Set to 01: General purpose output mode
  *pGPIOA_MODER &= ~( 0b11 << PA8_2BIT_BP );  // clear bits
  *pGPIOA_MODER |= ( 0b01 << PA8_2BIT_BP );   // set the new value

  // GPIOx_OTYPER: Set to 0: Output push-pull
  *pGPIOA_OTYPER &= ~( 0b1 << PA8 );  // clear bits

  // GPIOx_PUPDR: 00: No pull-up, pull-down
  *pGPIOA_PUPDR &= ~( 0b11 << PA8_2BIT_BP );  // clear bits

  led_off();
}

void led_on(void) {
  uint32_t *pGPIOA_ODR = (uint32_t *)GPIOA_ODR;
  *pGPIOA_ODR |= ( 1 << PA8);
}

void led_off(void) {
  uint32_t *pGPIOA_ODR = (uint32_t *)GPIOA_ODR;
  *pGPIOA_ODR  &= ~( 1 << PA8);
}
