/*
 * stm32f103xx_gpio_driver.h
 *
 *  Created on: Jul 29, 2019
 *      Author: Piotr
 */


#ifndef INC_STM32F103XX_GPIO_DRIVER_H_
#define INC_STM32F103XX_GPIO_DRIVER_H_

#include "../mystm32f103xx/mystm32f103xx.h"

/************************STRUCTURES***********************************/
/*
	this is configuration structure for a gpion pin
*/
typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdCtrl;
	uint8_t GPIO_PinOutType;
	uint8_t GPIO_PinALtFunMode;
}GPIO_PinConfig;
/*
	this is a handle structure for a gpio pin
*/
typedef struct{
	GPIO_RegDef pGPIOx;	//holds the base address of the gpio port to which the pin belongs
	GPIO_PinConfig GPIOxPinConfig;	//holds gpio pin conf settings
} GPIO_Handle_t;
/*************************METHODS**************************************/
/*
 *clock enablig
 */
void GPIO_PeriphClockControl(GPIO_RegDef *pGPIOx,uint8_t EnOrDi);
//(de)initializers
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef *pGPIOx);
/*
 * data write/read
 */
uint8_t GPIO_ReadOutputPin(GPIO_RegDef *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadOutputPort(GPIO_RegDef *pGPIOx);
void GPIO_WriteToInputPin(GPIO_RegDef *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WriteToInputPort(GPIO_RegDef *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef *pGPIOx,uint8_t PinNumber);
/*
	IRQ Conf and ISR Handling
 */
void GPIO_IRQConfig(uint8_t IRQHandler, uint8_t IRQPrority,uint8_t EnOrDi);
void GPIO_IRQHandling(uint8_t IRQPinNumber);




#endif /* INC_STM32F103XX_GPIO_DRIVER_H_ */
