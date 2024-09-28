#ifndef INC_STM32F411CEU6_GPIO_H_
#define INC_STM32F411CEU6_GPIO_H_

#include "stm32f411ceu6_generic.h"

// *** INTERRUPT NUMBER VECTOR TABLE *** //
#define IRQ_EXTI16_NUMBER 1
#define IRQ_EXTI21_NUMBER 2
#define IRQ_EXTI22_NUMBER 3
#define IRQ_EXTI0_NUMBER 6
#define IRQ_EXTI1_NUMBER 7
#define IRQ_EXTI2_NUMBER 8
#define IRQ_EXTI3_NUMBER 9
#define IRQ_EXTI4_NUMBER 10
#define IRQ_EXTI9_5_NUMBER 23
#define IRQ_EXTI15_10_NUMBER 40
#define IRQ_EXTI17_NUMBER 41
#define IRQ_EXTI18_NUMBER 42
// *** END  *** //

// Status //
#define ENABLE 1
#define DISABLE 0
// END //

#define ERROR 12

//*** MODE ***//
#define INPUT 00
#define OUTPUT 01
#define ALTERNATE 10
#define ANALOG 11
//*** END ***//

// *** INTERRUPT MODE *** //
#define RISING_EDGE 4
#define FALLING_EDGE 5
//*** END ***//

//*** VAL ***//
#define LOW 0
#define HIGH 1
//*** END ***//

// *** SPEED ***//
#define LOW_SPEED 6
#define MEDIUM 7
#define FAST 8
#define HIGH_SPEED 3
//*** END ***//

// *** OUTPUT TYPE ***//
#define PUSHPULL 0
#define OPDRAIN 1
// *** END ***//

// *** PUPD ***//
#define NO_PUPD 00
#define PUL_UP 01
#define PULL_DOWN 10
#define RESERVED 11

typedef struct {
	GPIO_REG *pGPIO;
	uint8_t GPIO_PIN_NUMBER; // selectPinNumber
	uint8_t GPIO_MODE; // INPUT or OUTPUT
	uint8_t GPIO_OUTPUT_TYPE; // PUSH-PULL or OPEN-DRAIN
	uint8_t GPIO_OUTPUT_SPEED; // The higher speed is, the more straight up Time Rise and Time Fall is
	uint8_t GPIO_SET_PUPD; // PULL-UP or PULL-DOWN
	uint8_t GPIO_SET_ALTERNATE; // Alternate FUNCTION
} GPIO_HANDLE; // GPIO_PORT

// GPIO
void initGPIO(GPIO_HANDLE *gpioHandle);
//uint8_t GPIO_read(GPIO_REG *pGPIO, uint8_t GPIO_PIN_NUMBER);
//static inline uint8_t __attribute__((always_inline)) GPIO_read(GPIO_REG *pGPIO,
//		uint8_t GPIO_PIN_NUMBER) {
//// Implementation here
//	return ((pGPIO->GPIOx_IDR >> GPIO_PIN_NUMBER) & 0x1);
//}
//static inline void __attribute__((always_inline)) GPIO_write(GPIO_REG *pGPIO,
//		uint8_t GPIO_PIN_NUMBER, uint8_t outVal) {
//	pGPIO->GPIOx_ODR = ((pGPIO->GPIOx_ODR & ~(1 << GPIO_PIN_NUMBER))
//			| ((outVal & 1) << GPIO_PIN_NUMBER));
//}

// Place GPIO functions in SRAM for faster access
static inline uint8_t __attribute__((always_inline, section(".ramfunc"))) GPIO_read(
		GPIO_REG *pGPIO, uint8_t GPIO_PIN_NUMBER) {
	return ((pGPIO->GPIOx_IDR >> GPIO_PIN_NUMBER) & 0x1);
}

static inline void __attribute__((always_inline, section(".ramfunc"))) GPIO_write(
		GPIO_REG *pGPIO, uint8_t GPIO_PIN_NUMBER, uint8_t outVal) {
//	pGPIO->GPIOx_ODR = ((pGPIO->GPIOx_ODR & ~(1 << GPIO_PIN_NUMBER))
//			| ((outVal & 1) << GPIO_PIN_NUMBER));
	pGPIO->GPIOx_BSRR =
			(outVal & 1) ?
					(1 << GPIO_PIN_NUMBER) : (1 << (GPIO_PIN_NUMBER + 16));
}

void GPIO_ClockControl(GPIO_REG *pGPIO);

// INTERRUPT
void initInterrupt(GPIO_HANDLE *gpioHandle);
void IRQ_CONFIG(uint8_t IRQ_number, uint8_t status);
void IRQ_HANDLING(GPIO_HANDLE *gpioHandle);
void setSpeedClock();

#endif /* INC_STM32F411CEU6_GPIO_H_ */
