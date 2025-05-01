################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_cortex.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma_ex.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_exti.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash_ex.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gpio.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gtzc.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_icache.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr_ex.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc_ex.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim.c \
../Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim_ex.c 

OBJS += \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_cortex.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma_ex.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_exti.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash_ex.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gpio.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gtzc.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_icache.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr_ex.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc_ex.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim.o \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim_ex.o 

C_DEPS += \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_cortex.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma_ex.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_exti.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash_ex.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gpio.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gtzc.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_icache.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr_ex.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc_ex.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim.d \
./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32U3xx_HAL_Driver/Src/%.o Drivers/STM32U3xx_HAL_Driver/Src/%.su Drivers/STM32U3xx_HAL_Driver/Src/%.cyclo: ../Drivers/STM32U3xx_HAL_Driver/Src/%.c Drivers/STM32U3xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U385xx -c -I../Core/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U3xx/Include -I../Drivers/CMSIS/Include -I"/Users/paulgallagher/MyGithub/tardate/LittleArduinoProjects/ARM/STM32U3/STM32U385RGDevBoard/blinky/Drivers/BSP/STM32U3xx_Nucleo" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32U3xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32U3xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_cortex.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_cortex.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_cortex.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_cortex.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma_ex.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma_ex.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma_ex.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_dma_ex.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_exti.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_exti.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_exti.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_exti.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash_ex.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash_ex.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash_ex.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_flash_ex.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gpio.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gpio.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gpio.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gpio.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gtzc.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gtzc.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gtzc.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_gtzc.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_icache.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_icache.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_icache.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_icache.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr_ex.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr_ex.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr_ex.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_pwr_ex.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc_ex.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc_ex.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc_ex.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_rcc_ex.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim.su ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim_ex.cyclo ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim_ex.d ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim_ex.o ./Drivers/STM32U3xx_HAL_Driver/Src/stm32u3xx_hal_tim_ex.su

.PHONY: clean-Drivers-2f-STM32U3xx_HAL_Driver-2f-Src

