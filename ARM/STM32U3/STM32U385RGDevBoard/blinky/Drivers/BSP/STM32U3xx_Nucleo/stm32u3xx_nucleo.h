/**
  ******************************************************************************
  * @file    stm32u3xx_nucleo.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for:
  *          - LEDs and push-button available on STM32U3xx-Nucleo Kit
  *          - COM ports
  *            from STMicroelectronics
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U3XX_NUCLEO_H
#define STM32U3XX_NUCLEO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u3xx_nucleo_conf.h"
#include "stm32u3xx_nucleo_errno.h"

#if (USE_BSP_COM_FEATURE == 1)
#include <stdio.h>
#endif /* USE_BSP_COM_FEATURE */

/** @addtogroup BSP
  * @{
  */

/** @defgroup STM32U3XX_NUCLEO STM32U3XX_NUCLEO
  * @{
  */

/** @defgroup STM32U3XX_NUCLEO_LOW_LEVEL LOW LEVEL
  * @{
  */

/**
  * @brief Define for STM32U3XX_NUCLEO board
  */
#if !defined (USE_STM32U3XX_NUCLEO)
#define USE_STM32U3XX_NUCLEO
#endif /* !defined (USE_STM32U3XX_NUCLEO) */

#if !defined (USE_NUCLEO_64)
#error "Board Pin number not defined!! Add USE_NUCLEO_64 define within stm32u3xx_nucleo_conf.h file"
#endif /* !defined (USE_NUCLEO_64) */

/** @defgroup STM32U3XX_NUCLEO_LOW_LEVEL_Exported_Types LOW LEVEL Exported Types
  * @{
  */

typedef enum
{
  LD2 = 0U,
  LED_GREEN = LD2,
  LEDn
} Led_TypeDef;

typedef enum
{
  B1 = 0U,
  BUTTON_USER = B1,
  BUTTONn
} Button_TypeDef;

typedef enum
{
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

#if (USE_BSP_COM_FEATURE > 0)
typedef enum
{
  COM1 = 0U,
  COMn
} COM_TypeDef;

typedef enum
{
  COM_STOPBITS_1     =   UART_STOPBITS_1,
  COM_STOPBITS_2     =   UART_STOPBITS_2,
} COM_StopBitsTypeDef;

typedef enum
{
  COM_PARITY_NONE     =  UART_PARITY_NONE,
  COM_PARITY_EVEN     =  UART_PARITY_EVEN,
  COM_PARITY_ODD      =  UART_PARITY_ODD,
} COM_ParityTypeDef;

typedef enum
{
  COM_HWCONTROL_NONE    =  UART_HWCONTROL_NONE,
  COM_HWCONTROL_RTS     =  UART_HWCONTROL_RTS,
  COM_HWCONTROL_CTS     =  UART_HWCONTROL_CTS,
  COM_HWCONTROL_RTS_CTS =  UART_HWCONTROL_RTS_CTS,
} COM_HwFlowCtlTypeDef;

typedef enum
{
  COM_WORDLENGTH_7B = UART_WORDLENGTH_7B,
  COM_WORDLENGTH_8B = UART_WORDLENGTH_8B,
  COM_WORDLENGTH_9B = UART_WORDLENGTH_9B,
} COM_WordLengthTypeDef;

typedef struct
{
  uint32_t               BaudRate;
  COM_WordLengthTypeDef  WordLength;
  COM_StopBitsTypeDef    StopBits;
  COM_ParityTypeDef      Parity;
  COM_HwFlowCtlTypeDef   HwFlowCtl;
} COM_InitTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
typedef struct
{
  void (* pMspInitCb)(UART_HandleTypeDef *);
  void (* pMspDeInitCb)(UART_HandleTypeDef *);
} BSP_COM_Cb_t;
#endif /* (USE_HAL_UART_REGISTER_CALLBACKS == 1) */

#define MX_UART_InitTypeDef COM_InitTypeDef

#endif /* USE_BSP_COM_FEATURE */

/**
  * @}
  */

/** @defgroup STM32U3XX_NUCLEO_LOW_LEVEL_Exported_Constants LOW LEVEL Exported Constants
  * @{
  */

/**
  * @brief STM32U3XX NUCLEO BSP Driver version number V1.2.0
  */
#define STM32U3XX_NUCLEO_BSP_VERSION_MAIN   (0x01U) /*!< [31:24] main version */
#define STM32U3XX_NUCLEO_BSP_VERSION_SUB1   (0x00U) /*!< [23:16] sub1 version */
#define STM32U3XX_NUCLEO_BSP_VERSION_SUB2   (0x00U) /*!< [15:8]  sub2 version */
#define STM32U3XX_NUCLEO_BSP_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */
#define STM32U3XX_NUCLEO_BSP_VERSION        ((STM32U3XX_NUCLEO_BSP_VERSION_MAIN << 24)\
                                             |(STM32U3XX_NUCLEO_BSP_VERSION_SUB1 << 16)\
                                             |(STM32U3XX_NUCLEO_BSP_VERSION_SUB2 << 8 )\
                                             |(STM32U3XX_NUCLEO_BSP_VERSION_RC))

#define STM32U3XX_NUCLEO_BSP_BOARD_NAME  "NUCLEO-U345RE-Q";
#define STM32U3XX_NUCLEO_BSP_BOARD_ID    "MB1841A";

/** @defgroup STM32U3XX_NUCLEO_LOW_LEVEL_LED LOW LEVEL LED
  * @{
  */
#define LED2_PIN                                GPIO_PIN_5
#define LED2_GPIO_PORT                          GPIOA
#define LED2_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOA_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOA_CLK_DISABLE()
/**
  * @}
  */

/** @defgroup STM32U3XX_NUCLEO_LOW_LEVEL_BUTTON LOW LEVEL BUTTON
  * @{
  */
/* Button state */
#define BUTTON_RELEASED                    0U
#define BUTTON_PRESSED                     1U

/**
  * @brief Key push-button
  */
#define BUTTON_USER_PIN                       GPIO_PIN_13
#define BUTTON_USER_GPIO_PORT                 GPIOC
#define BUTTON_USER_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOC_CLK_ENABLE()
#define BUTTON_USER_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOC_CLK_DISABLE()
#define BUTTON_USER_EXTI_IRQn                 EXTI13_IRQn
#define BUTTON_USER_EXTI_LINE                 EXTI_LINE_13

/**
  * @}
  */

/** @defgroup STM32U3XX_NUCLEO_LOW_LEVEL_COM LOW LEVEL COM
  * @{
  */
/**
  * @brief Definition for COM port1, connected to UART1
  */
#if (USE_BSP_COM_FEATURE > 0)
#define COM1_UART                     USART1
#define COM1_CLK_ENABLE()             __HAL_RCC_USART1_CLK_ENABLE()
#define COM1_CLK_DISABLE()            __HAL_RCC_USART1_CLK_DISABLE()

#define COM1_TX_PIN                   GPIO_PIN_9
#define COM1_TX_GPIO_PORT             GPIOA
#define COM1_TX_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define COM1_TX_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()
#define COM1_TX_AF                    GPIO_AF7_USART1

#define COM1_RX_PIN                   GPIO_PIN_10
#define COM1_RX_GPIO_PORT             GPIOA
#define COM1_RX_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define COM1_RX_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()
#define COM1_RX_AF                    GPIO_AF7_USART1
#define COM_POLL_TIMEOUT             1000
#endif /* USE_BSP_COM_FEATURE */

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup STM32U3XX_NUCLEO_LOW_LEVEL_Exported_Variables
  * @{
  */
extern EXTI_HandleTypeDef hpb_exti[];
#if (USE_BSP_COM_FEATURE > 0)
extern UART_HandleTypeDef hcom_uart[];
extern USART_TypeDef *COM_USART[];
#endif /* USE_BSP_COM_FEATURE */

/**
  * @}
  */

/** @defgroup STM32U3XX_NUCLEO_LOW_LEVEL_Exported_FunctionsPrototypes LOW LEVEL Exported Functions Prototypes
  * @{
  */
int32_t  BSP_GetVersion(void);
const uint8_t *BSP_GetBoardName(void);
const uint8_t *BSP_GetBoardID(void);
int32_t  BSP_LED_Init(Led_TypeDef Led);
int32_t  BSP_LED_DeInit(Led_TypeDef Led);
int32_t  BSP_LED_On(Led_TypeDef Led);
int32_t  BSP_LED_Off(Led_TypeDef Led);
int32_t  BSP_LED_Toggle(Led_TypeDef Led);
int32_t  BSP_LED_GetState(Led_TypeDef Led);
int32_t  BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode);
int32_t  BSP_PB_DeInit(Button_TypeDef Button);
int32_t  BSP_PB_GetState(Button_TypeDef Button);
void     BSP_PB_IRQHandler(Button_TypeDef Button);
void     BSP_PB_Callback(Button_TypeDef Button);

#if (USE_BSP_COM_FEATURE > 0)
int32_t  BSP_COM_Init(COM_TypeDef COM, COM_InitTypeDef *COM_Init);
int32_t  BSP_COM_DeInit(COM_TypeDef COM);
#if (USE_COM_LOG > 0)
int32_t  BSP_COM_SelectLogPort(COM_TypeDef COM);
#endif /* USE_COM_LOG */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
int32_t BSP_COM_RegisterDefaultMspCallbacks(COM_TypeDef COM);
int32_t BSP_COM_RegisterMspCallbacks(COM_TypeDef COM, BSP_COM_Cb_t *Callback);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
HAL_StatusTypeDef MX_USART1_Init(UART_HandleTypeDef *huart, MX_UART_InitTypeDef *COM_Init);
#endif /* USE_BSP_COM_FEATURE */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32U3XX_NUCLEO_H */
