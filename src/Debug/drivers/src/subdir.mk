################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/stm32f411ceu6_GPIO.c \
../drivers/src/stm32f411ceu6_generic.c 

OBJS += \
./drivers/src/stm32f411ceu6_GPIO.o \
./drivers/src/stm32f411ceu6_generic.o 

C_DEPS += \
./drivers/src/stm32f411ceu6_GPIO.d \
./drivers/src/stm32f411ceu6_generic.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411CEUx -c -I../Inc -I"D:/Work Space STM32/balanceSpoon/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/stm32f411ceu6_GPIO.cyclo ./drivers/src/stm32f411ceu6_GPIO.d ./drivers/src/stm32f411ceu6_GPIO.o ./drivers/src/stm32f411ceu6_GPIO.su ./drivers/src/stm32f411ceu6_generic.cyclo ./drivers/src/stm32f411ceu6_generic.d ./drivers/src/stm32f411ceu6_generic.o ./drivers/src/stm32f411ceu6_generic.su

.PHONY: clean-drivers-2f-src

