#pragma once

#include <stdint.h>

#define GPIO_CRH_OFFSET 0x4
#define GPIO_ODR_OFFSET 0xC

#define GPIOC_BOUNDARY_ADDRESS 0x40011000
#define GPIOC_CRH (GPIOC_BOUNDARY_ADDRESS + GPIO_CRH_OFFSET)
#define GPIOC_ODR (GPIOC_BOUNDARY_ADDRESS + GPIO_ODR_OFFSET)

#define RCC_BOUNDARY_ADDRESS 0x40021000
#define RCC_APB2ENR (RCC_BOUNDARY_ADDRESS + 0x18)
#define IOPC_EN 4

#define PC13  13

void led_enable(void);
void led_on(void);
void led_off(void);
