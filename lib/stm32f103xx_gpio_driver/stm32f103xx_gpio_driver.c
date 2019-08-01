/*
 * stm32f103xx_gpio_driver.c
 *
 *  Created on: Jul 29, 2019
 *      Author: Piotr
 */


#include "stm32f103xx_gpio_driver.h"



void GPIO_PeriphClockControl(GPIO_RegDef *pGPIOx,uint8_t EnOrDi){

	

	if(pGPIOx==GPIOA){
		if(EnOrDi==ENABLE){
			GPIOA_PCLK_EN();
		} else{
			GPIOA_PCLK_DI();
		}
	}else if(pGPIOx==GPIOB){
		if(EnOrDi==ENABLE){
			GPIOB_PCLK_EN();
		} else{
			GPIOB_PCLK_DI();
		}
	}else if(pGPIOx==GPIOC){
		if(EnOrDi==ENABLE){
			GPIOA_PCLK_EN();
		} else{
			GPIOC_PCLK_DI();
		}
	}else if(pGPIOx==GPIOD){
		if(EnOrDi==ENABLE){
			GPIOD_PCLK_EN();
		} else{
			GPIOD_PCLK_DI();
		}
	}else if(pGPIOx==GPIOE){
		if(EnOrDi==ENABLE){
			GPIOE_PCLK_EN();
		} else{
			GPIOE_PCLK_DI();
		}
	}

};
