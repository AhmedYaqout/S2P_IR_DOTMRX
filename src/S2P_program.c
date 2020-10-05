/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   14/Sept/2020
 *  Type    :   S2P Program Executable File
 *  Version :   V1.0
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "S2P_interface.h"
#include "S2P_config.h"
#include "S2P_private.h"

void S2P_voidSendSynchronousOneRegister(u8 Copy_u8DataToSend)
{
	static s8 Local_s8Counter = 0;
	static u8 Local_u8Bit = 0;
	/* Send bit by bit with MSB first */
	for (Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8DataToSend, Local_s8Counter);
		GPIO_voidSetPinValue(S2P_SERIAL_DATA,Local_u8Bit);

		/* Send pulse to shift clock */
		GPIO_voidSetPinValue(S2P_SHIFT_CLOCK,GPIO_HIGH);
		GPIO_voidSetPinValue(S2P_SHIFT_CLOCK,GPIO_LOW);
	}
	/* Send pulse to store clock */
	GPIO_voidSetPinValue(S2P_STORE_CLOCK,GPIO_HIGH);
	GPIO_voidSetPinValue(S2P_STORE_CLOCK,GPIO_LOW);
}

void S2P_voidSendSynchronousTwoRegister(u16 Copy_u16DataToSend)
{
	static s8 Local_s8Counter = 0;
	static u8 Local_u8Bit = 0;
	/* Send bit by bit with MSB first */
	for (Local_s8Counter = 15; Local_s8Counter >= 0; Local_s8Counter--)
	{
		Local_u8Bit = GET_BIT(Copy_u16DataToSend, Local_s8Counter);
		GPIO_voidSetPinValue(S2P_SERIAL_DATA,Local_u8Bit);

		/* Send pulse to shift clock */
		GPIO_voidSetPinValue(S2P_SHIFT_CLOCK,GPIO_HIGH);
		GPIO_voidSetPinValue(S2P_SHIFT_CLOCK,GPIO_LOW);
	}
	/* Send pulse to store clock */
	GPIO_voidSetPinValue(S2P_STORE_CLOCK,GPIO_HIGH);
	GPIO_voidSetPinValue(S2P_STORE_CLOCK,GPIO_LOW);
}
u16 S2P_voidAllocateArrayTwoRegisters ( u16 Copy_u16Data)
{
	static u16 Local_u16Temp=0;
	static u8 k =0;
	static u8 Array[16]={LEDMRX_ROW0,LEDMRX_ROW1,LEDMRX_ROW2,LEDMRX_ROW3,LEDMRX_ROW4,LEDMRX_ROW5,LEDMRX_ROW6,LEDMRX_ROW7,LEDMRX_COLUMN0,LEDMRX_COLUMN1,LEDMRX_COLUMN2,LEDMRX_COLUMN3,LEDMRX_COLUMN4,LEDMRX_COLUMN5,LEDMRX_COLUMN6,LEDMRX_COLUMN7};
	Local_u16Temp=Copy_u16Data;
	Copy_u16Data=0;
	for (k=0;k<16;k++)
	{
		if((GET_BIT(Local_u16Temp,k))==0)
		{
			CLR_BIT(Copy_u16Data,Array[k]);
		}
		else
		{
			SET_BIT(Copy_u16Data,Array[k]);
		}
	}
	return Copy_u16Data;
}
void S2P_LEDMRX_voidDisplay(u8 *Copy_u8Data, u8 Copy_u8FrameRate)
{
	u8 Col = 0;
	u8 Row	= 0;
	s8 i	=	0;
	u8 l	=	0;
	u16 finalArray=0;
	for(l=0;l<Copy_u8FrameRate;l++)
	{
		for(i=0;i<=7; i++)
		{
			finalArray=0;
			Col=0xFF;
			Row	=	*(Copy_u8Data+(i));
			CLR_BIT(Col,i);
			finalArray=(Col<<8)|Row;
			finalArray=S2P_voidAllocateArrayTwoRegisters(finalArray);
			S2P_voidSendSynchronousTwoRegister(finalArray);
			STK_voidSetBusyDelayUs(2500);
		}
	}
}


void S2P_LEDMRX_voidAnimation(u8* Copy_u8DataArray[], u8 Copy_u8FrameRate, u8 Copy_u8CharacterQty)
{
	static u8 u8WorkingArray[8]={0};
	static s8 j=0;

	for (u8 i = 0; i < Copy_u8CharacterQty; i++)
	{
		/*pointer to hold the address of the row*/
		u8* ptr = Copy_u8DataArray[i];

		for (u8 k = 0; k < 8; k++)
		{
			/*Shifting Values*/
			for (j=0;j<=6;j++)
			{
				u8WorkingArray[j]=u8WorkingArray[j+1];
			}

			u8WorkingArray[7]= *ptr;

			S2P_LEDMRX_voidDisplay(u8WorkingArray,Copy_u8FrameRate);

			/*move the pointer to the next element in the letter*/

			ptr++;
		}

		// move the pointer to the next letter
		Copy_u8DataArray[i]++;
	}

}
