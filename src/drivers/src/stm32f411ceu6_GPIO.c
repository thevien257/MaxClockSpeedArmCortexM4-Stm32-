/*
 * stm32f411ceu6_GPIO.c
 *
 *  Created on: Sep 15, 2024
 *      Author: ADMIN
 */

#include "stm32f411ceu6_GPIO.h"

void GPIO_ClockControl(GPIO_REG *pGPIOxReg) {

	if (pGPIOxReg == GPIOA) {
		GPIOA_CLK_EN();
	} else if (pGPIOxReg == GPIOB) {
		GPIOB_CLK_EN();
	} else if (pGPIOxReg == GPIOC) {
		GPIOC_CLK_EN();
	} else if (pGPIOxReg == GPIOD) {
		GPIOD_CLK_EN();
	} else if (pGPIOxReg == GPIOE) {
		GPIOE_CLK_EN();
	} else if (pGPIOxReg == GPIOH) {
		GPIOH_CLK_EN();
	}
}

void initGPIO(GPIO_HANDLE *gpioHandle) {
	// ENABLE CLOCK

	GPIO_ClockControl(gpioHandle->pGPIO);
	// INIT MODE
	// If it is regular mode
	if (gpioHandle->GPIO_MODE < RISING_EDGE) {

		gpioHandle->pGPIO->GPIOx_MODER &= ~(0x3
				<< 2 * gpioHandle->GPIO_PIN_NUMBER);
		gpioHandle->pGPIO->GPIOx_MODER |= (gpioHandle->GPIO_MODE
				<< 2 * gpioHandle->GPIO_PIN_NUMBER);
	} else {
		// If it is INTERRUPT MODE
		initInterrupt(gpioHandle);
	}
	gpioHandle->pGPIO->GPIOx_PUPDR &= ~(0x3 << 2 * gpioHandle->GPIO_PIN_NUMBER);
	gpioHandle->pGPIO->GPIOx_PUPDR |= (gpioHandle->GPIO_SET_PUPD
			<< 2 * gpioHandle->GPIO_PIN_NUMBER);
	if (gpioHandle->GPIO_MODE == OUTPUT) {
		gpioHandle->pGPIO->GPIOx_OTYPER &= ~(1 << gpioHandle->GPIO_PIN_NUMBER);
		gpioHandle->pGPIO->GPIOx_OTYPER |= (gpioHandle->GPIO_OUTPUT_TYPE
				<< gpioHandle->GPIO_PIN_NUMBER);
		gpioHandle->pGPIO->GPIOx_OSPEEDR &= ~(0x3
				<< 2 * gpioHandle->GPIO_PIN_NUMBER);
		gpioHandle->pGPIO->GPIOx_OSPEEDR |= (gpioHandle->GPIO_OUTPUT_SPEED
				<< 2 * gpioHandle->GPIO_PIN_NUMBER);
	}

}

void initInterrupt(GPIO_HANDLE *gpioHandle) {

}

void IRQ_CONFIG(uint8_t IRQ_number, uint8_t status) {
	volatile uint32_t *reg = (IRQ_number < 32) ? NVIC_ISER0 : NVIC_ISER1;
	if (status == DISABLE) {
		reg = (IRQ_number < 32) ? NVIC_ICER0 : NVIC_ICER1;
	}
	*reg |= (1 << (IRQ_number % 32));
}

void IRQ_HANDLING(GPIO_HANDLE *gpioHandle) {
	if (EXTI->EXTI_PR & (1 << gpioHandle->GPIO_PIN_NUMBER)) {
		EXTI->EXTI_PR |= (1 << gpioHandle->GPIO_PIN_NUMBER);
	}
}

//uint8_t GPIO_read(GPIO_REG *pGPIO, uint8_t GPIO_PIN_NUMBER) {
//// Implementation here
//	return ((pGPIO->GPIOx_IDR >> GPIO_PIN_NUMBER) & 0x1);
//}

//void GPIO_write(GPIO_REG *pGPIO, uint8_t GPIO_PIN_NUMBER, uint8_t outVal) {
//// Implementation here
//	pGPIO->GPIOx_ODR = ((pGPIO->GPIOx_ODR & ~(1 << GPIO_PIN_NUMBER))
//			| ((outVal & 1) << GPIO_PIN_NUMBER));
////	if(outVal & 1){
////		pGPIO->GPIOx_ODR  |= (1 << GPIO_PIN_NUMBER);
////	} else{
////		pGPIO->GPIOx_ODR  &= ~(1 << GPIO_PIN_NUMBER);
////	}
//}

void setSpeedClock() {
	// SET SPEED CLOCK TO 100MHZ

	// Clear the latency bits
	FLASH_ACR &= ~FLASH_ACR_LATENCY;
	// Set the latency to 3 wait states
	FLASH_ACR |= FLASH_ACR_LATENCY_3WS;

	FLASH_ACR |= FLASH_ACR_PRFTEN;

	FLASH_ACR |= FLASH_ACR_ICEN;
	FLASH_ACR |= FLASH_ACR_DCEN;

	HSI_EN();
	while (!(RCC->CR & (1 << 1)))
		; // Wait until HSI is ready
	PLL_DISABLE();
	while ((RCC->CR & (1 << 25)))
		; // Wait until PLL is off
	PWR_CR &= VOS_SCALE_NOT_1_MODE;
	PWR_CR |= VOS_SCALE_1_MODE;
	HSI_TO_PLL();
	PLLM();
	PLLN();
	PLLP();
	PLL_EN();
	while (!(RCC->CR & (1 << 25)))
		; // Wait until PLL is ready
	PLL_SYSTEM_CLOCK();

	AHB_PRESCAL();
	APB1_PRESCAL();
	APB2_PRESCAL();
}
