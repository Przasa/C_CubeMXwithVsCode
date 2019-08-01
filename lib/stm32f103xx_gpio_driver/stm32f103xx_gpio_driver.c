/*
 * stm32f103xx_gpio_driver.c
 *
 *  Created on: Jul 29, 2019
 *      Author: Piotr
 */


#include "stm32f103xx_gpio_driver.h"



void mGPIO_PeriphClockControl(mGPIO_RegDef *pGPIOx,uint8_t EnOrDi){

	

	if(pGPIOx==mGPIOA){
		if(EnOrDi==mENABLE){
			mGPIOA_PCLK_EN();
		} else{
			mGPIOA_PCLK_DI();
		}
	}else if(pGPIOx==mGPIOB){
		if(EnOrDi==mENABLE){
			mGPIOB_PCLK_EN();
		} else{
			mGPIOB_PCLK_DI();
		}
	}else if(pGPIOx==mGPIOC){
		if(EnOrDi==mENABLE){
			mGPIOA_PCLK_EN();
		} else{
			mGPIOC_PCLK_DI();
		}
	}else if(pGPIOx==mGPIOD){
		if(EnOrDi==mENABLE){
			mGPIOD_PCLK_EN();
		} else{
			mGPIOD_PCLK_DI();
		}
	}else if(pGPIOx==mGPIOE){
		if(EnOrDi==mENABLE){
			mGPIOE_PCLK_EN();
		} else{
			mGPIOE_PCLK_DI();
		}
	}

};
