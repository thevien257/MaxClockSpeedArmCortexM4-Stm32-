################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Example/100mhz.c \
../Example/syscalls.c \
../Example/sysmem.c 

OBJS += \
./Example/100mhz.o \
./Example/syscalls.o \
./Example/sysmem.o 

C_DEPS += \
./Example/100mhz.d \
./Example/syscalls.d \
./Example/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Example/%.o Example/%.su Example/%.cyclo: ../Example/%.c Example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411CEUx -c -I../Inc -I"D:/Work Space STM32/balanceSpoon/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Example

clean-Example:
	-$(RM) ./Example/100mhz.cyclo ./Example/100mhz.d ./Example/100mhz.o ./Example/100mhz.su ./Example/syscalls.cyclo ./Example/syscalls.d ./Example/syscalls.o ./Example/syscalls.su ./Example/sysmem.cyclo ./Example/sysmem.d ./Example/sysmem.o ./Example/sysmem.su

.PHONY: clean-Example

