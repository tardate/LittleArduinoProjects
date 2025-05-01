################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32u3xx_hal_msp.c \
../Core/Src/stm32u3xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32u3xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/stm32u3xx_hal_msp.o \
./Core/Src/stm32u3xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32u3xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32u3xx_hal_msp.d \
./Core/Src/stm32u3xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32u3xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U385xx -c -I../Core/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U3xx/Include -I../Drivers/CMSIS/Include -I"/Users/paulgallagher/MyGithub/tardate/LittleArduinoProjects/ARM/STM32U3/STM32U385RGDevBoard/blinky/Drivers/BSP/STM32U3xx_Nucleo" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32u3xx_hal_msp.cyclo ./Core/Src/stm32u3xx_hal_msp.d ./Core/Src/stm32u3xx_hal_msp.o ./Core/Src/stm32u3xx_hal_msp.su ./Core/Src/stm32u3xx_it.cyclo ./Core/Src/stm32u3xx_it.d ./Core/Src/stm32u3xx_it.o ./Core/Src/stm32u3xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32u3xx.cyclo ./Core/Src/system_stm32u3xx.d ./Core/Src/system_stm32u3xx.o ./Core/Src/system_stm32u3xx.su

.PHONY: clean-Core-2f-Src

