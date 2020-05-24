// startup declarations and function for the STM32F103C8T6
// See: RM0008 10.1.2 Interrupt and exception vectors, Table 63. Vector table for other STM32F10xxx devices

#include <stdint.h>

#define SRAM_START  0x20000000U
#define SRAM_SIZE   (20U * 1024U) // 20KB
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))
#define STACK_START SRAM_END

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;

extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Reset_Handler(void);

// Weak function prototypes for the vector table so that they can easily be redefined
void NMI_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler             (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_LP_CAN_RX0_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_RX1_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_SCE_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void USART3_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_Wakeup_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_BRK_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC3_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void FSMC_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel1_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel2_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel3_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel4_5_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));

// Define the veector table
uint32_t vectors[] __attribute__((section(".isr_vector")))   = {
  STACK_START,
  (uint32_t)Reset_Handler,
  (uint32_t)NMI_Handler,
  (uint32_t)HardFault_Handler,
  (uint32_t)MemManage_Handler,
  (uint32_t)BusFault_Handler,
  (uint32_t)UsageFault_Handler,
  0, // reserved
  0, // reserved
  0, // reserved
  0, // reserved
  (uint32_t)SVC_Handler,
  (uint32_t)DebugMon_Handler,
  0, // reserved
  (uint32_t)PendSV_Handler,
  (uint32_t)SysTick_Handler,
  (uint32_t)WWDG_IRQHandler,
  (uint32_t)PVD_IRQHandler,
  (uint32_t)TAMP_STAMP_IRQHandler,
  (uint32_t)RTC_WKUP_IRQHandler,
  0, // Flash global interrupt
  (uint32_t)RCC_IRQHandler,
  (uint32_t)EXTI0_IRQHandler,
  (uint32_t)EXTI1_IRQHandler,
  (uint32_t)EXTI2_IRQHandler,
  (uint32_t)EXTI3_IRQHandler,
  (uint32_t)EXTI4_IRQHandler,
  (uint32_t)DMA1_Channel1_IRQHandler,
  (uint32_t)DMA1_Channel2_IRQHandler,
  (uint32_t)DMA1_Channel3_IRQHandler,
  (uint32_t)DMA1_Channel4_IRQHandler,
  (uint32_t)DMA1_Channel5_IRQHandler,
  (uint32_t)DMA1_Channel6_IRQHandler,
  (uint32_t)DMA1_Channel7_IRQHandler,
  (uint32_t)ADC_IRQHandler,
  (uint32_t)USB_HP_CAN_TX_IRQHandler,
  (uint32_t)USB_LP_CAN_RX0_IRQHandler,
  (uint32_t)CAN_RX1_IRQHandler,
  (uint32_t)CAN_SCE_IRQHandler,
  (uint32_t)EXTI9_5_IRQHandler,
  (uint32_t)TIM1_BRK_IRQHandler,
  (uint32_t)TIM1_UP_IRQHandler,
  (uint32_t)TIM1_TRG_COM_IRQHandler,
  (uint32_t)TIM1_CC_IRQHandler,
  (uint32_t)TIM2_IRQHandler,
  (uint32_t)TIM3_IRQHandler,
  (uint32_t)TIM4_IRQHandler,
  (uint32_t)I2C1_EV_IRQHandler,
  (uint32_t)I2C1_ER_IRQHandler,
  (uint32_t)I2C2_EV_IRQHandler,
  (uint32_t)I2C2_ER_IRQHandler,
  (uint32_t)SPI1_IRQHandler,
  (uint32_t)SPI2_IRQHandler,
  (uint32_t)USART1_IRQHandler,
  (uint32_t)USART2_IRQHandler,
  (uint32_t)USART3_IRQHandler,
  (uint32_t)EXTI15_10_IRQHandler,
  (uint32_t)RTC_Alarm_IRQHandler,
  (uint32_t)USB_Wakeup_IRQHandler,
  (uint32_t)TIM8_BRK_IRQHandler,
  (uint32_t)TIM8_UP_IRQHandler,
  (uint32_t)TIM8_TRG_COM_IRQHandler,
  (uint32_t)TIM8_CC_IRQHandler,
  (uint32_t)ADC3_IRQHandler,
  (uint32_t)FSMC_IRQHandler,
  (uint32_t)SDIO_IRQHandler,
  (uint32_t)TIM5_IRQHandler,
  (uint32_t)SPI3_IRQHandler,
  (uint32_t)UART4_IRQHandler,
  (uint32_t)UART5_IRQHandler,
  (uint32_t)TIM6_IRQHandler,
  (uint32_t)TIM7_IRQHandler,
  (uint32_t)DMA2_Channel1_IRQHandler,
  (uint32_t)DMA2_Channel2_IRQHandler,
  (uint32_t)DMA2_Channel3_IRQHandler,
  (uint32_t)DMA2_Channel4_5_IRQHandler,
};

// Command: a default "do nothing" handler
void Default_Handler(void) {
  while(1);
}

// Command: reset memory and restart user program
void Reset_Handler(void) {
  // copy .data section to SRAM
  uint8_t *pSramData = (uint8_t *)&_sdata; // sram
  uint8_t *pFlashData = (uint8_t *)&_la_data; //flash
  uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
  for (uint32_t i =0 ; i < data_size ; i++) {
    *pSramData++ = *pFlashData++;
  }

  // init. the .bss section to zero in SRAM
  uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint8_t *pBssData = (uint8_t *)&_sbss;
  for (uint32_t i =0 ; i < bss_size ; i++) {
    *pBssData++ = 0;
  }

  // now invoke main
  main();
}
