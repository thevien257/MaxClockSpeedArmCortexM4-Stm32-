/*
 * 100mhz.c
 *
 *  Created on: Sep 19, 2024
 *      Author: ADMIN
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f411ceu6_generic.h"
void delay() {
	for (volatile int i = 0; i < 100000; i++) {

	}
}

int main(void) {
	/* Loop forever */
	setSpeedClock();

	GPIO_HANDLE gpioB;
	gpioB.pGPIO = GPIOB;
	gpioB.GPIO_PIN_NUMBER = 12;
	gpioB.GPIO_MODE = OUTPUT;
	gpioB.GPIO_OUTPUT_TYPE = PUSHPULL;
	gpioB.GPIO_OUTPUT_SPEED = HIGH_SPEED;
	initGPIO(&gpioB);

	GPIO_HANDLE gpioC;
	gpioC.pGPIO = GPIOC;
	gpioC.GPIO_PIN_NUMBER = 14;
	gpioC.GPIO_MODE = OUTPUT;
	gpioC.GPIO_OUTPUT_TYPE = PUSHPULL;
	gpioC.GPIO_OUTPUT_SPEED = HIGH_SPEED;
	initGPIO(&gpioC);
	while (1) {
		GPIO_write(GPIOB, 12, LOW);
		GPIO_write(GPIOB, 12, HIGH);
		GPIO_write(GPIOC, 14, LOW);
		GPIO_write(GPIOC, 14, HIGH);
		GPIO_write(GPIOC, 14, HIGH);
		GPIO_write(GPIOC, 14, LOW);
		GPIO_write(GPIOB, 12, HIGH);
		GPIO_write(GPIOB, 12, LOW);
		GPIO_write(GPIOC, 14, HIGH);
		GPIO_write(GPIOC, 14, LOW);
		GPIO_write(GPIOB, 12, HIGH);
		GPIO_write(GPIOB, 12, LOW);
	}

}
