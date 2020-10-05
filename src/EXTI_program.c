/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   24/Aug/2020
 *  Type    :   External Interrupts Program Executable File
 *  Version :   V1.0
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#define NULL		(void * )0

static void (* EXTI0_CallBack) (void)   =   NULL;
static void (* EXTI1_CallBack) (void)   =   NULL;
static void (* EXTI2_CallBack) (void)   =   NULL;
static void (* EXTI3_CallBack) (void)   =   NULL;
static void (* EXTI4_CallBack) (void)   =   NULL;
static void (* EXTI9_5_CallBack) (void)   =   NULL;
static void (* EXTI15_10_CallBack) (void)   =   NULL;



void EXTI_voidInit(void)
{
#if		EXTI_LINE == EXTI_LINE0
	SET_BIT(EXTI -> IMR , EXTI_LINE0 );
#elif	EXTI_LINE == EXTI_LINE1
	SET_BIT(EXTI -> IMR , EXTI_LINE1 );
#elif	EXTI_LINE == EXTI_LINE2
	SET_BIT(EXTI -> IMR , EXTI_LINE2 );
#elif	EXTI_LINE == EXTI_LINE3
	SET_BIT(EXTI -> IMR , EXTI_LINE3 );
#elif	EXTI_LINE == EXTI_LINE4
	SET_BIT(EXTI -> IMR , EXTI_LINE4 );
#elif	EXTI_LINE == EXTI_LINE5
	SET_BIT(EXTI -> IMR , EXTI_LINE5 );
#elif	EXTI_LINE == EXTI_LINE6
	SET_BIT(EXTI -> IMR , EXTI_LINE6 );
#elif	EXTI_LINE == EXTI_LINE7
	SET_BIT(EXTI -> IMR , EXTI_LINE7 );
#elif	EXTI_LINE == EXTI_LINE8
	SET_BIT(EXTI -> IMR , EXTI_LINE8 );
#elif	EXTI_LINE == EXTI_LINE9
	SET_BIT(EXTI -> IMR , EXTI_LINE9 );
#else
#error ("Wrong External Interrupt Line !")
#endif

#if EXTI_MODE   ==  RISING_EDGE
	SET_BIT(EXTI -> RTSR    ,   EXTI_LINE);
#elif EXTI_MODE ==  FALLING_EDGE
	SET_BIT(EXTI -> FTSR    ,   EXTI_LINE);
#elif EXTI_MODE ==  ON_CHANGE
	SET_BIT(EXTI -> RTSR    ,   EXTI_LINE);
	SET_BIT(EXTI -> FTSR    ,   EXTI_LINE);
#else
#error "Wrong Mode"
#endif
}

void EXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> IMR, Copy_u8Line);
}

void EXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> IMR, Copy_u8Line);
}

void EXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> IMR, Copy_u8Line);
	SET_BIT(EXTI -> PR, Copy_u8Line);
	SET_BIT(EXTI -> SWIER, Copy_u8Line);
}

void EXTI_voidSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{
	case RISING_EDGE:   SET_BIT(EXTI -> RTSR, EXTI_LINE);     break;
	case FALLING_EDGE:  SET_BIT(EXTI -> FTSR, EXTI_LINE);     break;
	case ON_CHANGE:SET_BIT(EXTI -> RTSR, EXTI_LINE);
	SET_BIT(EXTI -> FTSR, EXTI_LINE);     break;
	default:        break;
	}

	SET_BIT(EXTI -> IMR, Copy_u8Line);
}


void EXTI0_voidSetCallBack(void (*ptr) (void))
{
	EXTI0_CallBack=ptr;
}

void EXTI1_voidSetCallBack(void (*ptr) (void))
{
	EXTI1_CallBack=ptr;
}


void EXTI2_voidSetCallBack(void (*ptr) (void))
{
	EXTI2_CallBack=ptr;
}

void EXTI3_voidSetCallBack(void (*ptr) (void))
{
	EXTI3_CallBack=ptr;
}

void EXTI4_voidSetCallBack(void (*ptr) (void))
{
	EXTI4_CallBack=ptr;
}

void EXTI9_5_voidSetCallBack(void (*ptr) (void))
{
	EXTI9_5_CallBack=ptr;
}

void EXTI15_10_voidSetCallBack(void (*ptr) (void))
{
	EXTI15_10_CallBack=ptr;
}


void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/* Clear Pending Bit */
	SET_BIT(EXTI -> PR, 0);

}

void EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	/* Clear Pending Bit */
	SET_BIT(EXTI -> PR, 1);

}

void EXTI2_IRQHandler(void)
{
	EXTI2_CallBack();
	/* Clear Pending Bit */
	SET_BIT(EXTI -> PR, 2);

}

void EXTI3_IRQHandler(void)
{
	EXTI3_CallBack();
	/* Clear Pending Bit */
	SET_BIT(EXTI -> PR, 3);

}


void EXTI4_IRQHandler(void)
{
	EXTI4_CallBack();
	/* Clear Pending Bit */
	SET_BIT(EXTI -> PR, 4);

}


void EXTI9_5_IRQHandler(void)
{
	EXTI9_5_CallBack();
	/* Clear Pending Bit */
	SET_BIT(EXTI -> PR, 5);
	SET_BIT(EXTI -> PR, 6);
	SET_BIT(EXTI -> PR, 7);
	SET_BIT(EXTI -> PR, 8);
	SET_BIT(EXTI -> PR, 9);

}

void EXTI15_10_IRQHandler(void)
{
	EXTI15_10_CallBack();
	/* Clear Pending Bit */
	SET_BIT(EXTI -> PR, 10);
	SET_BIT(EXTI -> PR, 11);
	SET_BIT(EXTI -> PR, 12);
	SET_BIT(EXTI -> PR, 13);
	SET_BIT(EXTI -> PR, 14);
	SET_BIT(EXTI -> PR, 15);

}
