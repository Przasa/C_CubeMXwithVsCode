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
#define mvo volatile

#define mENABLE 			1
#define mDISABLE			0
#define mSET 				mENABLE
#define mRESET 				mDISABLE
#define mGPIO_PIN_SET 		mSET
#define mGPIO_PIN_RESET 	mRESET


//*********************BASE ADRESSES**************************//

//MEMORIES BLOCKS
#define mFLASH_BASEADDR			0x80000000U
#define mSRAM_BASEADDR			0X20000000U
#define mROM_BASEADDR			0x1FFFF000U
#define mOPTION_BYTES_BASEADDR	0x1FFFF800U

//PERIPHERAL BUSES
#define mPERIPRH_BASEADDR		0x40000000U
#define mAHB_BASEADDR			0x40018000U
#define mAPB1_BASEADDR			0x40010000U
#define mAPB2_BASEADDR			mPERIPRH_BASEADDR

//PERIPHERALS

//AHB
#define mSDIO_BASEADDR			0x40018000U
#define mDMA1_BASEADDR			0x40020000U
#define mDMA2_BASEADDR			0x40020400U
#define mRCC_BASEADDR			0x40021000U
#define mFLASH_MINTERF_BASEADDR	0x40022000U
#define mCRC_BASEADDR			0x40023000U
#define mETHERNET_BASEADDR		0x40028000U
#define mUSB_OTG_BASEADDR		0x50000000U
#define mFSMC_BASEADDR			0xA0000000U

//APB1
#define mFFUSB_CANSRAM_BASEADDR	0x40006000U
#define mTIM2_BASEADDR			mAPB2_BASEADDR
#define mTIM3_BASEADDR			0x40000400U
#define mTIM4_BASEADDR			0x40000800U
#define mTIM5_BASEADDR			0x40000C00U
#define mTIM6_BASEADDR			0x40001000U
#define mTIM7_BASEADDR			0x40001400U
#define mTIM12_BASEADDR			0x40001800U
#define mTIM13_BASEADDR			0x40001C00U
#define mTIM14_BASEADDR			0x40002000U
#define mRTC_BASEADDR			0x40002800U
#define mWWDG_BASEADDR			0x40002C00U
#define mIWDG_BASEADDR			0x40003000U
#define mSPI2_I2S_BASEADDR		0x40003800U
#define mSPI3_I2S_BASEADDR		0x40003C00U
#define mUSART2_BASEADDR			0x40004400U
#define mUSART3_BASEADDR			0x40004800U
#define mUART4_BASEADDR			0x40004C00U
#define mUART5_BASEADDR			0x40005000U
#define mI2C1_BASEADDR			0x40005400U
#define mI2C2_BASEADDR			0x40005800U
#define mUSBDEVICEFS_BASEADDR	0x40005C00U
#define mCAN1_BASEADDR			0x40006400U
#define mCAN2_BASEADDR			0x40006800U
#define mBACKUP_BASEADDR			0x40006C00U
#define mPOWERCTRL_PWR_BASEADDR	0x40007000U
#define mDAC_BASEADDR			0x40007400U

//APB2
#define mAFIO_BASEADDR			0x40010000U
#define mEXTI_BASEADDR			0x40010400U
#define mGPIOA_BASEADDR			0x40010800U
#define mGPIOB_BASEADDR			0x40010C00U
#define mGPIOC_BASEADDR			0x40011000U
#define mGPIOD_BASEADDR			0x40011400U
#define mGPIOE_BASEADDR			0x40011800U
#define mGPIOF_BASEADDR			0x40011C00U
#define mGPIOG_BASEADDR			0x40012000U
#define mADC1_BASEADDR			0x40012400U
#define mADC2_BASEADDR			0x40012800U
#define mTIM1_BASEADDR			0x40012C00U
#define mSPI1_BASEADDR			0x40013000U
#define mTIM8_BASEADDR			0x40013400U
#define mUSART1_BASEADDR			0x40013800U
#define mADC3_BASEADDR			0x40013C00U
#define mTIM9_BASEADDR			0x40014C00U
#define mTIM10_BASEADDR			0x40015000U
#define mTIM11_BASEADDR			0x40015400U



//******************PERIPHERAL REGISTER DEFINITION STRUCTURES***********///

//Register names and adresses may be different in different MCUs.
//Check the Reference Manual of your MCU.

typedef struct  {
	mvo uint32_t CRL; 	/*offset: 0x00*/
	mvo uint32_t CRH;	/*offset: 0x04*/
	mvo uint32_t IDR;	/*offset: 0x08*/
	mvo uint32_t ODR;	/*offset: 0x0C*/
	mvo uint32_t BSRR;	/*offset: 0x10*/
	mvo uint32_t BRR;	/*offset: 0x14*/
	mvo uint32_t LCKR;	/*offset: 0x18*/
} mGPIO_RegDef;

typedef struct  {
	mvo uint32_t CR; 	/*offset: 0x00*/
	mvo uint32_t CFGR;	/*offset: 0x04*/
	mvo uint32_t CIR;	/*offset: 0x08*/
	mvo uint32_t APB2RSTR;	/*offset: 0x0C*/
	mvo uint32_t APB1RSTR;	/*offset: 0x10*/
	mvo uint32_t AHBENR;	/*offset: 0x14*/
	mvo uint32_t APB2ENR;	/*offset: 0x18*/
	mvo uint32_t APB1ENR;	/*offset: 0x1C*/
	mvo uint32_t BDCR;	/*offset: 0x20*/
	mvo uint32_t CSR; /*offset: 0x24*/
} mRCC_RegDef;

//******************PERIPHERAL DEFINITIONS (Peripheral base addresses typecasted to xxx_RegDef_t)***********//
#define mGPIOA  				((mGPIO_RegDef*)mGPIOA_BASEADDR)
#define mGPIOB  				((mGPIO_RegDef*)mGPIOB_BASEADDR)
#define mGPIOC  				((mGPIO_RegDef*)mGPIOC_BASEADDR)
#define mGPIOD  				((mGPIO_RegDef*)mGPIOD_BASEADDR)
#define mGPIOE  				((mGPIO_RegDef*)mGPIOE_BASEADDR)
#define mRCC 				((mRCC_RegDef*)mRCC_BASEADDR)

//**************ENABLING MACROS********************//
#define mGPIOA_PCLK_EN() (mRCC->mAPB2_BASEADDR |= 1<<2)
#define mGPIOB_PCLK_EN() (mRCC->mAPB2_BASEADDR |= 1<<3)
#define mGPIOC_PCLK_EN() (mRCC->mAPB2_BASEADDR |= 1<<4)
#define mGPIOD_PCLK_EN() (mRCC->mAPB2_BASEADDR |= 1<<5)
#define mGPIOE_PCLK_EN() (mRCC->mAPB2_BASEADDR |= 1<<6)

#define mGPIOA_PCLK_DI() (mRCC->mAPB2_BASEADDR &= ~(1<<2))
#define mGPIOB_PCLK_DI() (mRCC->mAPB2_BASEADDR &= ~(1<<3))
#define mGPIOC_PCLK_DI() (mRCC->mAPB2_BASEADDR &= ~(1<<4))
#define mGPIOD_PCLK_DI() (mRCC->mAPB2_BASEADDR &= ~(1<<5))
#define mGPIOE_PCLK_DI() (mRCC->mAPB2_BASEADDR &= ~(1<<6))



#include "../mystm32f103xx/mystm32f103xx.h"


#endif /* INC_MYSTM32F103XX_H_ */
