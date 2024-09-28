#ifndef INC_STM32F411CEU6_I2C_H_
#define INC_STM32F411CEU6_I2C_H_
#include "stm32f411ceu6_generic.h"

// REG OAR1:
#define ADDRMODE 15
#define INTERFACE_ADDR 1

// REG CR1
#define ACK 10
#define NO_STRETCH 7

// REG OAR2
#define ENDUAL 0

typedef struct {
	I2C_REG *I2C;
	uint8_t speedMode; // sm: 100khz, fm: 400khz
	uint8_t addrMode; // 7-bit or 10-bit
	uint8_t addrDualEnable; // If enable, Both OAR1 and OAR2 are recognized in 7-bit addressing mode
	uint8_t stretchClock; // This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until it is reset by software.
	uint8_t generalCall; // Enable or Disable?
	uint8_t ENACK; // Enable ACK
	uint16_t ownAddr; // The address
} I2C_Handle;

void initI2C(I2C_Handle *I2C_Setup);

#endif /* INC_STM32F411CEU6_I2C_H_ */
