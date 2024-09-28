#ifndef INC_STM32F411CEU6_GENERIC_H_
#define INC_STM32F411CEU6_GENERIC_H_

#include <stdint.h>
#include <stdio.h>

// ************** BUS ADDRESS ************** //
#define APB1_BASEADDR 0x40000000U
#define APB2_BASEADDR 0x40010000U
#define AHB1_BASEADDR 0x40020000U
#define AHB2_BASEADDR 0x50000000U
// ************** END ************** //

// ************** GPIO ADDRESS ************** //
// EXPLAIN: IN EACH BASEADDR HAS 32BIT REGISTERS WITH DIFFERENT ADDRESS
#define GPIOA_BASEADDR AHB1_BASEADDR
#define GPIOB_BASEADDR (0x40020400)
#define GPIOC_BASEADDR (0x40020800)
#define GPIOD_BASEADDR (0x40020C00)
#define GPIOE_BASEADDR (0x40021000)
#define GPIOH_BASEADDR (0x40021C00)
#define CRC_BASEADRR (0x40023000)
#define RCC_BASEADRR (0x40023800)
// ************** END ************** //

// ************** NVIC BASE ADDRESS ************** //
#define NVIC_BASEADDR 0xE000E100U
#define NVIC_ISER0 (volatile uint32_t *)(NVIC_BASEADDR + 0x100)
#define NVIC_ISER1 (volatile uint32_t *)(NVIC_BASEADDR + 0x104)
#define NVIC_ICER0 (volatile uint32_t *)(NVIC_BASEADDR + 0x180)
#define NVIC_ICER1 (volatile uint32_t *)(NVIC_BASEADDR + 0x184)
// ************** END ************** //

// ************** SYSCONFIG_BASEADDR ************** //
#define SYSCONFIG_BASEADDR (0x40013800)
// ************** END ************** //

// ************** SYSCONFIG_BASEADDR ************** //
#define EXTI_BASEADDR (0x40013C00)
// ************** END ************** //

// ************** FLASH BASEADDR ************** //
#define FLASH_BASEADDR (0x40023C00)
// ************** END ************** //

// ************** I2C ADDRESS ************** //
#define I2C3_BASEADDR 0x40005C00
#define I2C2_BASEADDR 0x40005800
#define I2C1_BASEADDR 0x40005400
// ************** END ************** //

// ************** RCC CLOCK STRUCTURE ************** //
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR; // RESET THE PERIPHERAL TO THE RESET VALUE
	volatile uint32_t AHB2RSTR; // RESET THE PERIPHERAL TO THE RESET VALUE
	uint32_t Reserved1[2];
	volatile uint32_t APB1RSTR; // RESET THE PERIPHERAL TO THE RESET VALUE
	volatile uint32_t APB2RSTR; // RESET THE PERIPHERAL TO THE RESET VALUE
	uint32_t Reserved2[2];
	volatile uint32_t AHB1ENR; // ENABLE CLOCK FOR THE FIRST TIME
	volatile uint32_t AHB2ENR; // ENABLE CLOCK FOR THE FIRST TIME
	uint32_t Reserved3[2];
	volatile uint32_t APB1ENR; // ENABLE CLOCK FOR THE FIRST TIME
	volatile uint32_t APB2ENR; // ENABLE CLOCK FOR THE FIRST TIME
	uint32_t Reserved4[2];
	volatile uint32_t AHB1LPENR; // LOW POWER MODE ENABLE CLOCK
	volatile uint32_t RCC_AHB2LPENR; // LOW POWER MODE ENABLE CLOCK
	uint32_t Reserved5[2];
	volatile uint32_t APB1LPENR; // LOW POWER MODE ENABLE CLOCK
	volatile uint32_t APB2LPENR; // LOW POWER MODE ENABLE CLOCK
	uint32_t Reserved6[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	uint32_t Reserved7[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	uint32_t Reserved8;
	volatile uint32_t DCKCFGR;
} RCC_REG;
// ************** END ************** //

// ************** RCC POINTER DECLARE ************** //
// RCC_BASEADDR is just a number (an address), but to access the memory at that address, the compiler needs to know what type of data is stored there.
// By typecasting it to RCC_REG *, you tell the compiler that the memory at RCC_BASEADDR is organized according to the RCC_REG structure (cast it to the pointer of type struct).
// typecasts that address into a pointer to the RCC_REG struct.
// (RCC_REG *) is the typecast that tells the compiler: “I want to treat this address as if it is the starting address of a structure of type RCC_REG.”
#define RCC ((RCC_REG*)RCC_BASEADRR) // Similar to: RCC_REG* pRCC = (RCC_REG*)RCC_BASEADRR;
// ************** END ************** //

// ************** ENABLE CLOCK ************** //
#define GPIOA_CLK_EN() (RCC->AHB1ENR |= 1<<0)
#define GPIOB_CLK_EN() (RCC->AHB1ENR |= 1<<1)
#define GPIOC_CLK_EN() (RCC->AHB1ENR |= 1<<2)
#define GPIOD_CLK_EN() (RCC->AHB1ENR |= 1<<3)
#define GPIOE_CLK_EN() (RCC->AHB1ENR |= 1<<4)
#define GPIOH_CLK_EN() (RCC->AHB1ENR |= 1<<7)

#define LPOWER_AHB1_DIS() (RCC->AHB1LPENR = 0);
#define LPOWER_APB1_DIS() (RCC->APB1LPENR = 0);
#define LPOWER_APB2_DIS() (RCC->APB2LPENR = 0);

#define AHB1_EN() (RCC->AHB1ENR = 1);
#define APB1_EN() (RCC->APB1ENR = 1);
#define APB2_EN() (RCC->APB2ENR = 1);

#define GPIOA_CLK_DIS() (RCC->AHB1LPENR &= ~(1<<0))
#define GPIOB_CLK_DIS() (RCC->AHB1LPENR &= ~(1<<1))
#define GPIOC_CLK_DIS() (RCC->AHB1LPENR &= ~(1<<2))
#define GPIOD_CLK_DIS() (RCC->AHB1LPENR &= ~(1<<3))
#define GPIOE_CLK_DIS() (RCC->AHB1LPENR &= ~(1<<4))
#define GPIOH_CLK_DIS() (RCC->AHB1LPENR &= ~(1<<7))
// ************** END ************** //

// ************** SET SPEED CLOCK ************** //
#define HSI_EN() (RCC->CR |= (1<<0))
#define PLL_EN() (RCC->CR |= (1 << 24))
#define PLL_DISABLE() (RCC->CR &= ~(1 << 24))
#define HSI_TO_PLL() (RCC->PLLCFGR &= ~(1 << 22))
#define PLLM() (RCC->PLLCFGR |= (16 << 0))
#define PLLN() (RCC->PLLCFGR |= (200 << 6))
#define PLLP() (RCC->PLLCFGR &= ~(0x3 << 16))
#define PLL_SYSTEM_CLOCK() (RCC->CFGR |= (0x2<<0))
#define AHB_PRESCAL() (RCC->CFGR &= ~(15 << 4))
#define APB1_PRESCAL() (RCC->CFGR |= (4 << 10))
#define APB12_PRESCAL() (RCC->CFGR |= (5 << 10))
#define APB2_PRESCAL() (RCC->CFGR &= ~(7 << 13))
#define PWR_CR (*(volatile uint32_t*)0x40007000)
#define VOS_SCALE_1_MODE (0x3 << 14)
#define VOS_SCALE_NOT_1_MODE ~(0x3 << 14)
#define FLASH_ACR          (*(volatile uint32_t*)0x40023C00)
#define FLASH_ACR_LATENCY  (0x7U << 0) // Latency mask
#define FLASH_ACR_LATENCY_3WS (0x2U << 0) // 3 wait states
#define FLASH_ACR_PRFTEN   (0x1U << 8) // Prefetch enable
#define FLASH_ACR_ICEN     (0x1U << 9) // Instruction cache enable
#define FLASH_ACR_DCEN     (0x1U << 10) // Data cache enable
// ************** END ************** //

// ************** STRUCT GPIO ************** //
typedef struct {
	volatile uint32_t GPIOx_MODER;
	volatile uint32_t GPIOx_OTYPER;
	volatile uint32_t GPIOx_OSPEEDR;
	volatile uint32_t GPIOx_PUPDR;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_LCKR;
	volatile uint32_t GPIOx_AFRL;
	volatile uint32_t GPIOx_AFRH;
} GPIO_REG;
// ************** END ************** //

// GPIO POINTER DECLARE
#define GPIOA (GPIO_REG*)GPIOA_BASEADDR
#define GPIOB (GPIO_REG*)GPIOB_BASEADDR
#define GPIOC (GPIO_REG*)GPIOC_BASEADDR
#define GPIOD (GPIO_REG*)GPIOD_BASEADDR
#define GPIOE (GPIO_REG*)GPIOE_BASEADDR
#define GPIOH (GPIO_REG*)GPIOH_BASEADDR
// ************** END ************** //

// ************** SYSCONFIG ENABLE ************** //
#define SYSCONFIG_ENABLE() (RCC->APB2ENR |= 1 << 14)
// ************** END ************** //

// ************** STRUCT SYSCONFIG ************** //
typedef struct {
	volatile uint32_t SYSCFG_MEMRMP;
	volatile uint32_t SYSCFG_PMC;
	volatile uint32_t SYSCFG_EXTICRx[4];
	volatile uint32_t SYSCFG_CMPCR;
} SYS_REG;
// ************** END ************** //

// ************** SYSCONFIG DECLARE ************** //
#define SYSCONFIG ((SYS_REG*)SYSCONFIG_BASEADDR)
// ************** END ************** //

// ************** EXTI_REG ************** //
typedef struct {
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;
} EXTI_REG;
// ************** END ************** //

// ************** SYSCONFIG DECLARE ************** //
#define EXTI ((EXTI_REG*)EXTI_BASEADDR)
// ************** END ************** //

// ************** I2C REGISTER ************** //
typedef struct {
	volatile uint32_t I2C_CR1;
	volatile uint32_t I2C_CR2;
	volatile uint32_t I2C_OAR1;
	volatile uint32_t I2C_OAR2;
	volatile uint32_t I2C_DR;
	volatile uint32_t I2C_SR1;
	volatile uint32_t I2C_SR2;
	volatile uint32_t I2C_CCR;
	volatile uint32_t I2C_TRISE;
	volatile uint32_t I2C_FLTR;
} I2C_REG;
// ************** END ************** //

// I2C POINTER DECLARE
#define I2C1 (I2C_REG *)I2C1_BASEADDR;
#define I2C2 (I2C_REG *)I2C2_BASEADDR;
#define I2C3 (I2C_REG *)I2C3_BASEADDR;

// PORT CHOICE
#define PORT_CHOICE(x) ((x==GPIOA) ? 0:\
					 (x==GPIOB) ? 1:\
					 (x==GPIOC) ? 2:\
				     (x == GPIOD)?3:\
				     (x == GPIOE)?4:\
					 (x == GPIOH)?7: 0)

#include "stm32f411ceu6_GPIO.h"
#endif /* INC_STM32F411CEU6_GENERIC_H_ */
