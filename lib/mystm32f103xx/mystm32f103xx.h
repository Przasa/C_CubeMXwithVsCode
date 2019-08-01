/*
 * MyStm32F103xx.h
 *
 *  Created on: Jul 26, 2019
 *      Author: Piotr
 */

#include <stdint.h>
#include <stddef.h>

#ifndef INC_MYSTM32F103XX_H_
#define INC_MYSTM32F103XX_H_

//*********************CUSTOM VALUES********************//
#define __vo volatile

#define ENABLE 			1
#define DISABLE			0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET 	SET
#define GPIO_PIN_RESET 	RESET


//*********************BASE ADRESSES**************************//

//MEMORIES BLOCKS
#define FLASH_BASEADDR			0x80000000U
#define SRAM_BASEADDR			0X20000000U
#define ROM_BASEADDR			0x1FFFF000U
#define OPTION_BYTES_BASEADDR	0x1FFFF800U

//PERIPHERAL BUSES
#define PERIPH_BASEADDR    		0x40000000U
#define AHB_BASEADDR			0x40018000U
#define APB1_BASEADDR			0x40010000U
#define APB2_BASEADDR			PERIPH_BASEADDR

//PERIPHERALS
//AHB
#define SDIO_BASEADDR			0x40018000U
#define DMA1_BASEADDR			0x40020000U
#define DMA2_BASEADDR			0x40020400U
#define RCC_BASEADDR			0x40021000U
#define FLASH_MINTERF_BASEADDR	0x40022000U
#define CRC_BASEADDR			0x40023000U
#define ETHERNET_BASEADDR		0x40028000U
#define USB_OTG_BASEADDR		0x50000000U
#define FSMC_BASEADDR			0xA0000000U

//APB1
#define FFUSB_CANSRAM_BASEADDR	0x40006000U
#define TIM2_BASEADDR			APB2_BASEADDR
#define TIM3_BASEADDR			0x40000400U
#define TIM4_BASEADDR			0x40000800U
#define TIM5_BASEADDR			0x40000C00U
#define TIM6_BASEADDR			0x40001000U
#define TIM7_BASEADDR			0x40001400U
#define TIM12_BASEADDR			0x40001800U
#define TIM13_BASEADDR			0x40001C00U
#define TIM14_BASEADDR			0x40002000U
#define RTC_BASEADDR			0x40002800U
#define WWDG_BASEADDR			0x40002C00U
#define IWDG_BASEADDR			0x40003000U
#define SPI2_I2S_BASEADDR		0x40003800U
#define SPI3_I2S_BASEADDR		0x40003C00U
#define USART2_BASEADDR			0x40004400U
#define USART3_BASEADDR			0x40004800U
#define UART4_BASEADDR			0x40004C00U
#define UART5_BASEADDR			0x40005000U
#define I2C1_BASEADDR			0x40005400U
#define I2C2_BASEADDR			0x40005800U
#define USBDEVICEFS_BASEADDR	0x40005C00U
#define CAN1_BASEADDR			0x40006400U
#define CAN2_BASEADDR			0x40006800U
#define BACKUP_BASEADDR			0x40006C00U
#define POWERCTRL_PWR_BASEADDR	0x40007000U
#define DAC_BASEADDR			0x40007400U

//APB2
#define AFIO_BASEADDR			0x40010000U
#define EXTI_BASEADDR			0x40010400U
#define GPIOA_BASEADDR			0x40010800U
#define GPIOB_BASEADDR			0x40010C00U
#define GPIOC_BASEADDR			0x40011000U
#define GPIOD_BASEADDR			0x40011400U
#define GPIOE_BASEADDR			0x40011800U
#define GPIOF_BASEADDR			0x40011C00U
#define GPIOG_BASEADDR			0x40012000U
#define ADC1_BASEADDR			0x40012400U
#define ADC2_BASEADDR			0x40012800U
#define TIM1_BASEADDR			0x40012C00U
#define SPI1_BASEADDR			0x40013000U
#define TIM8_BASEADDR			0x40013400U
#define USART1_BASEADDR			0x40013800U
#define ADC3_BASEADDR			0x40013C00U
#define TIM9_BASEADDR			0x40014C00U
#define TIM10_BASEADDR			0x40015000U
#define TIM11_BASEADDR			0x40015400U



//******************PERIPHERAL REGISTER DEFINITION STRUCTURES***********///

//Register names and adresses may be different in different MCUs.
//Check the Reference Manual of your MCU.

typedef struct  {
	__vo uint32_t CRL; 	/*offset: 0x00*/
	__vo uint32_t CRH;	/*offset: 0x04*/
	__vo uint32_t IDR;	/*offset: 0x08*/
	__vo uint32_t ODR;	/*offset: 0x0C*/
	__vo uint32_t BSRR;	/*offset: 0x10*/
	__vo uint32_t BRR;	/*offset: 0x14*/
	__vo uint32_t LCKR;	/*offset: 0x18*/
} GPIO_RegDef;

typedef struct  {
	__vo uint32_t CR; 	/*offset: 0x00*/
	__vo uint32_t CFGR;	/*offset: 0x04*/
	__vo uint32_t CIR;	/*offset: 0x08*/
	__vo uint32_t APB2RSTR;	/*offset: 0x0C*/
	__vo uint32_t APB1RSTR;	/*offset: 0x10*/
	__vo uint32_t AHBENR;	/*offset: 0x14*/
	__vo uint32_t APB2ENR;	/*offset: 0x18*/
	__vo uint32_t APB1ENR;	/*offset: 0x1C*/
	__vo uint32_t BDCR;	/*offset: 0x20*/
	__vo uint32_t CSR; /*offset: 0x24*/
} RCC_RegDef;

//******************PERIPHERAL DEFINITIONS (Peripheral base addresses typecasted to xxx_RegDef_t)***********//
#define GPIOA  				((GPIO_RegDef*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef*)GPIOE_BASEADDR)
#define mRCC 				((RCC_RegDef*)RCC_BASEADDR)

//**************ENABLING MACROS********************//
#define GPIOA_PCLK_EN() (mRCC->APB2_BASEADDR |= 1<<2)
#define GPIOB_PCLK_EN() (mRCC->APB2_BASEADDR |= 1<<3)
#define GPIOC_PCLK_EN() (mRCC->APB2_BASEADDR |= 1<<4)
#define GPIOD_PCLK_EN() (mRCC->APB2_BASEADDR |= 1<<5)
#define GPIOE_PCLK_EN() (mRCC->APB2_BASEADDR |= 1<<6)

#define GPIOA_PCLK_DI() (mRCC->APB2_BASEADDR &= ~(1<<2))
#define GPIOB_PCLK_DI() (mRCC->APB2_BASEADDR &= ~(1<<3))
#define GPIOC_PCLK_DI() (mRCC->APB2_BASEADDR &= ~(1<<4))
#define GPIOD_PCLK_DI() (mRCC->APB2_BASEADDR &= ~(1<<5))
#define GPIOE_PCLK_DI() (mRCC->APB2_BASEADDR &= ~(1<<6))





#endif /* INC_MYSTM32F103XX_H_ */
