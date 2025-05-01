################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32u385rgtxq.s 

OBJS += \
./Core/Startup/startup_stm32u385rgtxq.o 

S_DEPS += \
./Core/Startup/startup_stm32u385rgtxq.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m33 -g3 -DDEBUG -c -I"/Users/paulgallagher/MyGithub/tardate/LittleArduinoProjects/ARM/STM32U3/STM32U385RGDevBoard/blinky/Drivers/BSP/STM32U3xx_Nucleo" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32u385rgtxq.d ./Core/Startup/startup_stm32u385rgtxq.o

.PHONY: clean-Core-2f-Startup

