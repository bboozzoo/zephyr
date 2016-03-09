/*
 * Copyright (c) 2016 Open-RnD Sp. z o.o.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file SoC configuration macros for the STM32F103 family processors.
 *
 * Based on reference manual:
 *   STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx
 *   advanced ARM ® -based 32-bit MCUs
 *
 * Chapter 3.3: Memory Map
 */


#ifndef _STM32F1_SOC_H_
#define _STM32F1_SOC_H_

/* peripherals start address */
#define PERIPH_BASE           0x40000000

/* use naming consistent with STMF10x Peripherals Library */
#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

/* UART */
#define USART1_ADDR           (APB2PERIPH_BASE + 0x3800)
#define USART2_ADDR           (APB1PERIPH_BASE + 0x4400)
#define USART3_ADDR           (APB1PERIPH_BASE + 0x4800)

/* Reset and Clock Control */
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)

#define GPIO_REG_SIZE         0x400
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
/* base address for where GPIO registers start */
#define GPIO_PORTS_BASE       (GPIOA_BASE)

#ifndef _ASMLANGUAGE

#include <device.h>
#include <misc/util.h>
#include <drivers/rand32.h>

/* clock subsystems */
enum {
	/* APB1 */
	STM32F10X_CLOCK_SUBSYS_TIM2   = 1 << 0,
	STM32F10X_CLOCK_SUBSYS_TIM3   = 1 << 1,
	STM32F10X_CLOCK_SUBSYS_TIM4   = 1 << 2,
	STM32F10X_CLOCK_SUBSYS_TIM5   = 1 << 3,
	STM32F10X_CLOCK_SUBSYS_TIM6   = 1 << 4,
	STM32F10X_CLOCK_SUBSYS_TIM7   = 1 << 5,
	STM32F10X_CLOCK_SUBSYS_WWDG   = 1 << 11,
	STM32F10X_CLOCK_SUBSYS_SPI2   = 1 << 14,
	STM32F10X_CLOCK_SUBSYS_SPI3   = 1 << 15,
	STM32F10X_CLOCK_SUBSYS_USART2 = 1 << 17,
	STM32F10X_CLOCK_SUBSYS_USART3 = 1 << 18,
	STM32F10X_CLOCK_SUBSYS_UART4  = 1 << 19,
	STM32F10X_CLOCK_SUBSYS_UART5  = 1 << 20,
	STM32F10X_CLOCK_SUBSYS_I2C1   = 1 << 21,
	STM32F10X_CLOCK_SUBSYS_I2C2   = 1 << 22,
	STM32F10X_CLOCK_SUBSYS_CAN1   = 1 << 25,
	STM32F10X_CLOCK_SUBSYS_CAN2   = 1 << 26,
	STM32F10X_CLOCK_SUBSYS_BKP    = 1 << 27,
	STM32F10X_CLOCK_SUBSYS_PWR    = 1 << 28,
	STM32F10X_CLOCK_SUBSYS_DAC    = 1 << 29,

	STM32F10X_CLOCK_APB2_BASE = 1 << 31,
	/* APB2 */
	STM32F10X_CLOCK_SUBSYS_AFIO   = STM32F10X_CLOCK_APB2_BASE | 1 << 0,
	STM32F10X_CLOCK_SUBSYS_IOPA   = STM32F10X_CLOCK_APB2_BASE | 1 << 2,
	STM32F10X_CLOCK_SUBSYS_IOPB   = STM32F10X_CLOCK_APB2_BASE | 1 << 3,
	STM32F10X_CLOCK_SUBSYS_IOPC   = STM32F10X_CLOCK_APB2_BASE | 1 << 4,
	STM32F10X_CLOCK_SUBSYS_IOPD   = STM32F10X_CLOCK_APB2_BASE | 1 << 5,
	STM32F10X_CLOCK_SUBSYS_IOPE   = STM32F10X_CLOCK_APB2_BASE | 1 << 6,
	STM32F10X_CLOCK_SUBSYS_ADC1   = STM32F10X_CLOCK_APB2_BASE | 1 << 9,
	STM32F10X_CLOCK_SUBSYS_ADC2   = STM32F10X_CLOCK_APB2_BASE | 1 << 10,
	STM32F10X_CLOCK_SUBSYS_TIM1   = STM32F10X_CLOCK_APB2_BASE | 1 << 11,
	STM32F10X_CLOCK_SUBSYS_SPI1   = STM32F10X_CLOCK_APB2_BASE | 1 << 12,
	STM32F10X_CLOCK_SUBSYS_USART1 = STM32F10X_CLOCK_APB2_BASE | 1 << 14,

};

#endif /* !_ASMLANGUAGE */

#endif /* _STM32F1_SOC_H_ */
