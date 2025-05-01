/**
  ******************************************************************************
  * @file    stm32u3xx_hal_cortex.h
  * @author  MCD Application Team
  * @brief   Header file of CORTEX HAL module.
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
#ifndef STM32U3xx_HAL_CORTEX_H
#define STM32U3xx_HAL_CORTEX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u3xx_hal_def.h"

/** @addtogroup STM32U3xx_HAL_Driver
  * @{
  */

/** @defgroup CORTEX CORTEX
  * @brief CORTEX HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup CORTEX_Exported_Types CORTEX Exported Types
  * @{
  */

/** @defgroup CORTEX_MPU_Region_Initialization_Structure_definition MPU Region Initialization Structure Definition
  * @brief  MPU Region initialization structure
  * @{
  */
typedef struct
{
  uint8_t  Enable;                /*!< Specifies the status of the region.
                                       This parameter can be a value of @ref CORTEX_MPU_Region_Enable                 */
  uint8_t  Number;                /*!< Specifies the number of the region to protect.
                                       This parameter can be a value of @ref CORTEX_MPU_Region_Number                 */
  uint32_t BaseAddress;           /*!< Specifies the base address of the region to protect.                           */
  uint32_t LimitAddress;          /*!< Specifies the limit address of the region to protect.                          */
  uint8_t  AttributesIndex;       /*!< Specifies the memory attributes index.
                                       This parameter can be a value of @ref CORTEX_MPU_Attributes_Number             */
  uint8_t  AccessPermission;      /*!< Specifies the region access permission type.
                                       This parameter can be a value of @ref CORTEX_MPU_Region_Permission_Attributes  */
  uint8_t  DisableExec;           /*!< Specifies the instruction access status.
                                       This parameter can be a value of @ref CORTEX_MPU_Instruction_Access            */
  uint8_t  IsShareable;           /*!< Specifies the shareability status of the protected region.
                                       This parameter can be a value of @ref CORTEX_MPU_Access_Shareable              */
} MPU_Region_InitTypeDef;
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Attributes_Initialization_Structure_definition \
                                                                   MPU Attributes Initialization Structure Definition
  * @{
  */
typedef struct
{
  uint8_t  Number;                /*!< Specifies the number of the memory attributes to configure.
                                       This parameter can be a value of @ref CORTEX_MPU_Attributes_Number             */

  uint8_t  Attributes;            /*!< Specifies the memory attributes vue.
                                       This parameter must be a number between Min_Data = 0x0 and Max_Data = 0xFFFF   */

} MPU_Attributes_InitTypeDef;
/**
  * @}
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup CORTEX_Exported_Constants CORTEX Exported Constants
  * @{
  */

/** @defgroup CORTEX_Preemption_Priority_Group CORTEX Preemption Priority Group
  * @{
  */
#define NVIC_PRIORITYGROUP_0            7U  /*!< 0 bit  for pre-emption priority,
                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1            6U  /*!< 1 bit  for pre-emption priority,
                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2            5U  /*!< 2 bits for pre-emption priority,
                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3            4U  /*!< 3 bits for pre-emption priority,
                                                 1 bit for subpriority  */
#define NVIC_PRIORITYGROUP_4            3U  /*!< 4 bits for pre-emption priority,
                                                 0 bit for subpriority  */
/**
  * @}
  */

/** @defgroup CORTEX_SysTick_clock_source CORTEX SysTick clock source
  * @{
  */
#define SYSTICK_CLKSOURCE_HCLK_DIV8     0U /*!< AHB clock divided by 8 selected as SysTick clock source */
#define SYSTICK_CLKSOURCE_LSI           1U /*!< LSI clock selected as SysTick clock source */
#define SYSTICK_CLKSOURCE_LSE           2U /*!< LSE clock selected as SysTick clock source */
#define SYSTICK_CLKSOURCE_HCLK          4U /*!< AHB clock selected as SysTick clock source */
/**
  * @}
  */

/** @defgroup CORTEX_MPU_HFNMI_PRIVDEF_Control CORTEX MPU HFNMI and PRIVILEGED Access control
  * @{
  */
#define  MPU_HFNMI_PRIVDEF_NONE          0U
#define  MPU_HARDFAULT_NMI               MPU_CTRL_HFNMIENA_Msk
#define  MPU_PRIVILEGED_DEFAULT          MPU_CTRL_PRIVDEFENA_Msk
#define  MPU_HFNMI_PRIVDEF               (MPU_CTRL_HFNMIENA_Msk | MPU_CTRL_PRIVDEFENA_Msk)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Enable CORTEX MPU Region Enable
  * @{
  */
#define  MPU_REGION_ENABLE               1U
#define  MPU_REGION_DISABLE              0U
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Instruction_Access CORTEX MPU Instruction Access
  * @{
  */
#define  MPU_INSTRUCTION_ACCESS_ENABLE   0U
#define  MPU_INSTRUCTION_ACCESS_DISABLE  1U
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Shareable CORTEX MPU Instruction Access Shareable
  * @{
  */
#define  MPU_ACCESS_NOT_SHAREABLE        0U
#define  MPU_ACCESS_OUTER_SHAREABLE      2U
#define  MPU_ACCESS_INNER_SHAREABLE      3U
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Permission_Attributes CORTEX MPU Region Permission Attributes
  * @{
  */
#define  MPU_REGION_PRIV_RW              0U
#define  MPU_REGION_ALL_RW               1U
#define  MPU_REGION_PRIV_RO              2U
#define  MPU_REGION_ALL_RO               3U
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Number CORTEX MPU Region Number
  * @{
  */
/* STM32U3xx supports 12 secure and 8 non secure MPU regions. */
#define  MPU_REGION_NUMBER0              0U
#define  MPU_REGION_NUMBER1              1U
#define  MPU_REGION_NUMBER2              2U
#define  MPU_REGION_NUMBER3              3U
#define  MPU_REGION_NUMBER4              4U
#define  MPU_REGION_NUMBER5              5U
#define  MPU_REGION_NUMBER6              6U
#define  MPU_REGION_NUMBER7              7U
#if defined (CPU_IN_SECURE_STATE)
#define  MPU_REGION_NUMBER8              8U
#define  MPU_REGION_NUMBER9              9U
#define  MPU_REGION_NUMBER10             10U
#define  MPU_REGION_NUMBER11             11U
#endif /* defined (CPU_IN_SECURE_STATE) */
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Attributes_Number CORTEX MPU Memory Attributes Number
  * @{
  */
#define  MPU_ATTRIBUTES_NUMBER0          0U
#define  MPU_ATTRIBUTES_NUMBER1          1U
#define  MPU_ATTRIBUTES_NUMBER2          2U
#define  MPU_ATTRIBUTES_NUMBER3          3U
#define  MPU_ATTRIBUTES_NUMBER4          4U
#define  MPU_ATTRIBUTES_NUMBER5          5U
#define  MPU_ATTRIBUTES_NUMBER6          6U
#define  MPU_ATTRIBUTES_NUMBER7          7U
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Attributes CORTEX MPU Attributes
  * @{
  */

/* Device memory attributes */
#define  MPU_DEVICE_NGNRNE          0x0U  /* Device, noGather, noReorder, noEarly acknowledge. */
#define  MPU_DEVICE_NGNRE           0x4U  /* Device, noGather, noReorder, Early acknowledge.   */
#define  MPU_DEVICE_NGRE            0x8U  /* Device, noGather, Reorder, Early acknowledge.     */
#define  MPU_DEVICE_GRE             0xCU  /* Device, Gather, Reorder, Early acknowledge.       */

/* Normal Memory attributes */
/* Note that these attributes need to be set for both inner AND outer attributes.
   These defines should be used with the INNER_OUTER macro if they are the same for inner and outer. */
/* - Non-cacheable memory attribute*/
#define  MPU_NOT_CACHEABLE          0x4U  /* Normal memory, non-cacheable. */

/* - Cacheable memory attributes*/
#define  MPU_WRITE_THROUGH          0x0U  /* Normal memory, write-through. */
#define  MPU_WRITE_BACK             0x4U  /* Normal memory, write-back.    */

#define  MPU_TRANSIENT              0x0U  /* Normal memory, transient.     */
#define  MPU_NON_TRANSIENT          0x8U  /* Normal memory, non-transient. */

#define  MPU_NO_ALLOCATE            0x0U  /* Normal memory, no allocate.         */
#define  MPU_W_ALLOCATE             0x1U  /* Normal memory, write allocate.      */
#define  MPU_R_ALLOCATE             0x2U  /* Normal memory, read allocate.       */
#define  MPU_RW_ALLOCATE            0x3U  /* Normal memory, read/write allocate. */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup CORTEX_Exported_Macros CORTEX Exported Macros
  * @{
  */

/** @defgroup CORTEX_MPU_Normal_Memory_Attributes CORTEX MPU Normal Memory Attributes
  * @{
  */
/* __ATTR__ being a combination of MPU Normal memory attributes */
#define OUTER(__ATTR__)        ((__ATTR__) << 4U)
#define INNER_OUTER(__ATTR__)  ((__ATTR__) | ((__ATTR__) << 4U))
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup CORTEX_Exported_Functions CORTEX Exported Functions
  * @{
  */

/** @defgroup CORTEX_Exported_Functions_Group1 Initialization and Configuration functions
  * @brief    Initialization and Configuration functions
  * @{
  */
/* Initialization and Configuration functions *****************************/
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn);
void HAL_NVIC_SystemReset(void);
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb);
/**
  * @}
  */

/** @defgroup CORTEX_Exported_Functions_Group2 Peripheral Control functions
  * @brief   Cortex control functions
  * @{
  */
/* Peripheral Control functions ***********************************************/
uint32_t HAL_NVIC_GetPriorityGrouping(void);
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup,
                          uint32_t *pPreemptPriority, uint32_t *pSubPriority);
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn);
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource);
uint32_t HAL_SYSTICK_GetCLKSourceConfig(void);
void HAL_SYSTICK_IRQHandler(void);
void HAL_SYSTICK_Callback(void);
void HAL_CORTEX_ClearEvent(void);
void HAL_MPU_Enable(uint32_t MPU_Control);
void HAL_MPU_Disable(void);
void HAL_MPU_EnableRegion(uint32_t RegionNumber);
void HAL_MPU_DisableRegion(uint32_t RegionNumber);
void HAL_MPU_ConfigRegion(const MPU_Region_InitTypeDef *pMPU_RegionInit);
void HAL_MPU_ConfigMemoryAttributes(const MPU_Attributes_InitTypeDef *pMPU_AttributesInit);
#if defined (CPU_IN_SECURE_STATE)
void HAL_MPU_Enable_NS(uint32_t MPU_Control);
void HAL_MPU_Disable_NS(void);
void HAL_MPU_EnableRegion_NS(uint32_t RegionNumber);
void HAL_MPU_DisableRegion_NS(uint32_t RegionNumber);
void HAL_MPU_ConfigRegion_NS(const MPU_Region_InitTypeDef *pMPU_RegionInit);
void HAL_MPU_ConfigMemoryAttributes_NS(const MPU_Attributes_InitTypeDef *pMPU_AttributesInit);
#endif /* defined (CPU_IN_SECURE_STATE) */
/**
  * @}
  */

/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup CORTEX_Private_Macros CORTEX Private Macros
  * @{
  */
#define IS_NVIC_PRIORITY_GROUP(__GROUP__)             (((__GROUP__) == NVIC_PRIORITYGROUP_0) || \
                                                       ((__GROUP__) == NVIC_PRIORITYGROUP_1) || \
                                                       ((__GROUP__) == NVIC_PRIORITYGROUP_2) || \
                                                       ((__GROUP__) == NVIC_PRIORITYGROUP_3) || \
                                                       ((__GROUP__) == NVIC_PRIORITYGROUP_4))

#define IS_NVIC_PREEMPTION_PRIORITY(__PRIO__, __PRIOGRP__)   (((__PRIO__) < (1uL << __NVIC_PRIO_BITS)) && \
                                                              ((__PRIO__) < (0x1uL << (0x07u - __PRIOGRP__))))

#define IS_NVIC_SUB_PRIORITY(__PRIO__, __PRIOGRP__) \
  ((__PRIOGRP__ < (0x07u - __NVIC_PRIO_BITS)) ?\
   ((__PRIO__) < (1u)): \
   ((__PRIO__) < (0x1uL << (__PRIOGRP__ - (0x07u - __NVIC_PRIO_BITS)))))

#define IS_NVIC_DEVICE_IRQ(__IRQ__)                   ((__IRQ__) > SysTick_IRQn)

#define IS_NVIC_PRIO_INTERRUPT(__IT__)                (((__IT__) > HardFault_IRQn) &&\
                                                       ((__IT__) != DebugMonitor_IRQn) && ((__IT__) != SVCall_IRQn))

#define IS_SYSTICK_CLK_SOURCE(__SOURCE__)             (((__SOURCE__) == SYSTICK_CLKSOURCE_LSI) || \
                                                       ((__SOURCE__) == SYSTICK_CLKSOURCE_LSE) || \
                                                       ((__SOURCE__) == SYSTICK_CLKSOURCE_HCLK)|| \
                                                       ((__SOURCE__) == SYSTICK_CLKSOURCE_HCLK_DIV8))

#define IS_MPU_REGION_ENABLE(__STATE__)               (((__STATE__) == MPU_REGION_ENABLE) || \
                                                       ((__STATE__) == MPU_REGION_DISABLE))

#define IS_MPU_INSTRUCTION_ACCESS(__STATE__)          (((__STATE__) == MPU_INSTRUCTION_ACCESS_ENABLE) || \
                                                       ((__STATE__) == MPU_INSTRUCTION_ACCESS_DISABLE))

#define IS_MPU_ACCESS_SHAREABLE(__STATE__)            (((__STATE__) == MPU_ACCESS_OUTER_SHAREABLE) || \
                                                       ((__STATE__) == MPU_ACCESS_INNER_SHAREABLE) || \
                                                       ((__STATE__) == MPU_ACCESS_NOT_SHAREABLE))

#define IS_MPU_REGION_PERMISSION_ATTRIBUTE(__TYPE__)  (((__TYPE__) == MPU_REGION_PRIV_RW) || \
                                                       ((__TYPE__) == MPU_REGION_ALL_RW)  || \
                                                       ((__TYPE__) == MPU_REGION_PRIV_RO)     || \
                                                       ((__TYPE__) == MPU_REGION_ALL_RO))

#if defined (CPU_IN_SECURE_STATE)
#define IS_MPU_REGION_NUMBER(__NUMBER__)              (((__NUMBER__) == MPU_REGION_NUMBER0) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER1) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER2) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER3) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER4) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER5) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER6) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER7) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER8) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER9) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER10)|| \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER11))

#define IS_MPU_NS_REGION_NUMBER(__NUMBER__)            (((__NUMBER__) == MPU_REGION_NUMBER0) || \
                                                        ((__NUMBER__) == MPU_REGION_NUMBER1) || \
                                                        ((__NUMBER__) == MPU_REGION_NUMBER2) || \
                                                        ((__NUMBER__) == MPU_REGION_NUMBER3) || \
                                                        ((__NUMBER__) == MPU_REGION_NUMBER4) || \
                                                        ((__NUMBER__) == MPU_REGION_NUMBER5) || \
                                                        ((__NUMBER__) == MPU_REGION_NUMBER6) || \
                                                        ((__NUMBER__) == MPU_REGION_NUMBER7))
#else
#define IS_MPU_REGION_NUMBER(__NUMBER__)              (((__NUMBER__) == MPU_REGION_NUMBER0) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER1) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER2) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER3) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER4) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER5) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER6) || \
                                                       ((__NUMBER__) == MPU_REGION_NUMBER7))
#endif /* defined (CPU_IN_SECURE_STATE)*/

#define IS_MPU_ATTRIBUTES_NUMBER(__NUMBER__)          (((__NUMBER__) == MPU_ATTRIBUTES_NUMBER0) || \
                                                       ((__NUMBER__) == MPU_ATTRIBUTES_NUMBER1) || \
                                                       ((__NUMBER__) == MPU_ATTRIBUTES_NUMBER2) || \
                                                       ((__NUMBER__) == MPU_ATTRIBUTES_NUMBER3) || \
                                                       ((__NUMBER__) == MPU_ATTRIBUTES_NUMBER4) || \
                                                       ((__NUMBER__) == MPU_ATTRIBUTES_NUMBER5) || \
                                                       ((__NUMBER__) == MPU_ATTRIBUTES_NUMBER6) || \
                                                       ((__NUMBER__) == MPU_ATTRIBUTES_NUMBER7))

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

#endif /* STM32U3xx_HAL_CORTEX_H */
