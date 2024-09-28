#include "stm32f411ceu6_I2C.h"

void initI2C(I2C_Handle *I2C_Setup) {

	// ENABLE I2C CLOCK

	// Setup Address
	I2C_Setup->I2C->I2C_OAR1 &= ~(1 << ADDMODE);
	I2C_Setup->I2C->I2C_OAR1 |= (I2C_Setup->addrMode << ADDMODE);

	// Address Dual
	I2C_Setup->I2C->I2C_OAR2 |= (I2C_Setup->addrDualEnable << ENDUAL);

	// OWN ADDRESS
	I2C_Setup->I2C->I2C_OAR1 |= (I2C_Setup->ownAddr << INTERFACE_ADDR);

	// Setup ACK
	I2C_Setup->I2C->I2C_CR1 &= ~(1 << ACK);
	I2C_Setup->I2C->I2C_CR1 |= (I2C_Setup->ENACK << ACK);

	// Setup Stretch Clock
	I2C_Setup->I2C->I2C_CR1 |= (I2C_Setup->stretchClock << NO_STRETCH);

}
