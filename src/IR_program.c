/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   11/Sept/2020
 *  Type    :   IR Program Executable File
 *  Version :   V1.0
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"

#include"GPIO_interface.h"
#include"AFIO_interface.h"
#include"NVIC_interface.h"
//#include"GPTIM_interface.h"
#include"STK_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

volatile u8 u8StartFlag=0;
volatile u32 u32FrameData[50]={0};
volatile u8 u8EdgeCounter	=	0;
volatile u8 u8Data	=	0;
volatile u8 u8Address	=	0;

static void (* IR_CallBack) (u8)   =   NULL;

void IR_voidSetCallBack(void (*ptr) (u8))
{
	IR_CallBack=ptr;
}


void voidTakeAction(void)
{
	u8 i=0;
	u8Data=0;
	u8Address=0;
	/* Check proper start condition*/
	if((u32FrameData[0]>=10000) && (u32FrameData[0] <= 14000) )
	{
		/* store address value */
		for (i=0; i<8;i++)
		{
			if (u32FrameData[1+i]	>= 2000 && u32FrameData[1+i] <= 2300)
			{
				SET_BIT(u8Address,i);
			}
			else
			{
				CLR_BIT(u8Address,i);
			}
		}
		/*Store data according to elapsed time between one falling edge to next one*/
		for (i=0; i<8;i++)
		{
			if (u32FrameData[17+i]	>= 2000 && u32FrameData[17+i] <= 2300)
			{
				SET_BIT(u8Data,i);
			}
			else
			{
				CLR_BIT(u8Data,i);
			}
		}
		//TIM2_voidStopInterval();
		STK_voidStopTimer();
		IR_CallBack(u8Data);
	}
	else
	{
		/*Invalid Frame*/
	}
	u8StartFlag	=	0;
	u32FrameData[0]=0;
	u8EdgeCounter=0;
}

void GetFrame(void)
{
	if(u8StartFlag==0)
	{
		/* Start Timer */
		//TIM2_voidSetIntervalSingle(1000000,voidTakeAction);
		STK_voidStartTimer();
		u8StartFlag=1;
	}
	else
	{
		//u32FrameData[u8EdgeCounter]=TIM2_u16GetElapsedTime();
		u32FrameData[u8EdgeCounter]=STK_u32GetElapsedTime();
		//TIM2_voidSetIntervalSingle(1000000,voidTakeAction);
		STK_voidStartTimer();
		u8EdgeCounter++;
	}

	if(u8EdgeCounter>=33)
	{
		voidTakeAction();
	}
	asm("NOP");
}
