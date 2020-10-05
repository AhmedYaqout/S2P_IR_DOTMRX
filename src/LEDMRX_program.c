/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   09/Sept/2020
 *  Type    :   LED MATRIX Program Executable File
 *  Version :   V2.0
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"



void HLEDMRX_voidInit(void)
{
	GPIO_voidSetPinDirection(LEDMRX_ROW0_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW1_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW2_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW3_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW4_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW5_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW6_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW7_PIN, 0b0010);

	GPIO_voidSetPinDirection(LEDMRX_COLUMN0_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN1_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN2_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN3_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN4_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN5_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN6_PIN, 0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN7_PIN, 0b0010);
}

void HLEDMRX_voidDisplay(u8 *Copy_u8Data, u8 Copy_u8FrameRate)
{
	static s8 k=0;
	for(k=Copy_u8FrameRate;k>0;k--)
	{
		/* Column 0 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[0]);
		GPIO_voidSetPinValue(LEDMRX_COLUMN0_PIN, GPIO_LOW);
		SYSTICK_voidSetBusyDelayMs(3); /* 2.5MSEC */

		/* Column 1 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[1]);
		GPIO_voidSetPinValue(LEDMRX_COLUMN1_PIN, GPIO_LOW);
		SYSTICK_voidSetBusyDelayMs(3); /* 2.5MSEC */

		/* Column 2 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[2]);
		GPIO_voidSetPinValue(LEDMRX_COLUMN2_PIN, GPIO_LOW);
		SYSTICK_voidSetBusyDelayMs(3); /* 2.5MSEC */

		/* Column 3 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[3]);
		GPIO_voidSetPinValue(LEDMRX_COLUMN3_PIN, GPIO_LOW);
		SYSTICK_voidSetBusyDelayMs(3); /* 2.5MSEC */

		/* Column 4 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[4]);
		GPIO_voidSetPinValue(LEDMRX_COLUMN4_PIN, GPIO_LOW);
		SYSTICK_voidSetBusyDelayMs(3); /* 2.5MSEC */

		/* Column 5 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[5]);
		GPIO_voidSetPinValue(LEDMRX_COLUMN5_PIN, GPIO_LOW);
		SYSTICK_voidSetBusyDelayMs(3); /* 2.5MSEC */

		/* Column 6 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[6]);
		GPIO_voidSetPinValue(LEDMRX_COLUMN6_PIN, GPIO_LOW);
		SYSTICK_voidSetBusyDelayMs(3); /* 2.5MSEC */

		/* Column 7 */
		DisableAllColumns();
		SetRowValues(Copy_u8Data[7]);
		GPIO_voidSetPinValue(LEDMRX_COLUMN7_PIN, GPIO_LOW);
		SYSTICK_voidSetBusyDelayMs(3); /* 2.5MSEC */

	}
}

void DisableAllColumns(void)
{
	GPIO_voidSetPinValue(LEDMRX_COLUMN0_PIN, GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN1_PIN, GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN2_PIN, GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN3_PIN, GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN4_PIN, GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN5_PIN, GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN6_PIN, GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN7_PIN, GPIO_HIGH);
}

void SetRowValues(u8 Copy_u8Data)
{
	static u8 Local_u8BIT;

	/* Enable Column 0 */
	Local_u8BIT = GET_BIT(Copy_u8Data, 0);
	GPIO_voidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);

	/* Enable Column 1 */
	Local_u8BIT = GET_BIT(Copy_u8Data, 1);
	GPIO_voidSetPinValue(LEDMRX_ROW1_PIN, Local_u8BIT);

	/* Enable Column 2 */
	Local_u8BIT = GET_BIT(Copy_u8Data, 2);
	GPIO_voidSetPinValue(LEDMRX_ROW2_PIN, Local_u8BIT);

	/* Enable Column 3 */
	Local_u8BIT = GET_BIT(Copy_u8Data, 3);
	GPIO_voidSetPinValue(LEDMRX_ROW3_PIN, Local_u8BIT);

	/* Enable Column 4 */
	Local_u8BIT = GET_BIT(Copy_u8Data, 4);
	GPIO_voidSetPinValue(LEDMRX_ROW4_PIN, Local_u8BIT);

	/* Enable Column 5 */
	Local_u8BIT = GET_BIT(Copy_u8Data, 5);
	GPIO_voidSetPinValue(LEDMRX_ROW5_PIN, Local_u8BIT);

	/* Enable Column 6 */
	Local_u8BIT = GET_BIT(Copy_u8Data, 6);
	GPIO_voidSetPinValue(LEDMRX_ROW6_PIN, Local_u8BIT);

	/* Enable Column 7 */
	Local_u8BIT = GET_BIT(Copy_u8Data, 7);
	GPIO_voidSetPinValue(LEDMRX_ROW7_PIN, Local_u8BIT);
}

void HLEDMRX_voidAnimation(u8** Copy_u8DataArray, u8 Copy_u8FrameRate, u8 Copy_u8CharacterQty)
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

			HLEDMRX_voidDisplay(u8WorkingArray,Copy_u8FrameRate);

		/*move the pointer to the next element in the letter*/

			ptr++;
		}

		// move the pointer to the next letter
		Copy_u8DataArray[i]++;
	}

}
