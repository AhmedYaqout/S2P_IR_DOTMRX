#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"AFIO_interface.h"
#include"EXTI_interface.h"
#include"NVIC_interface.h"
#include"STK_interface.h"
//#include"GPTIM_interface.h"
//#include"LEDMRX_interface.h"
//#include"S2P_interface.h"
//#include"S2P_config.h"
#include"IR_interface.h"
/*
u8 Football_Frame1[8]={0x00, 0x00, 0xD6, 0x7A, 0xD6, 0x00, 0x00, 0x00};
u8 Football_Frame2[8]={0x00, 0x00, 0xD6, 0x7A, 0x56, 0x60, 0x00, 0x00};
u8 Football_Frame3[8]={0x00, 0x00, 0xD6, 0x7A, 0x56, 0x60, 0x00, 0x00};
u8 Football_Frame4[8]={0x00, 0x00, 0xD6, 0x7A, 0xD6, 0x10, 0x00, 0x00};
u8 Football_Frame5[8]={0x00, 0x00, 0xD6, 0x7A, 0xD6, 0x08, 0x00, 0x00};
u8 Football_Frame6[8]={0x00, 0x00, 0xD6, 0x7A, 0xD6, 0x04, 0x00, 0x00};
u8 Football_Frame7[8]={0x00, 0x00, 0xD6, 0x7A, 0xD6, 0x02, 0x00, 0x00};
u8 Football_Frame8[8]={0x00, 0x00, 0xD6, 0x7A, 0xD6, 0x01, 0x00, 0x00};
u8 * Football[13]={Football_Frame1,Football_Frame2,Football_Frame3,Football_Frame4,Football_Frame5,Football_Frame6,Football_Frame7,Football_Frame8,Football_Frame7,Football_Frame6,Football_Frame5,Football_Frame4,Football_Frame3};

void ir_animate(void)
{
	while(1)
	{
		for(u8 i=0; i<12;i++)
		{
			S2P_LEDMRX_voidDisplay(Football[i],20);
		}
	}
}
u8* u8Word[]={u8LetterA, u8LetterH, u8LetterM,u8LetterA,u8LetterD};

u8 Speed =20;
*/
void u8Play(u8 u8Data)
{
	switch(u8Data)
	{
	//case IR_POWER_BUTTON:
	case 0:
	//S2P_LEDMRX_voidAnimation(u8Word,Speed,5);
		GPIO_voidSetPinValue(GPIOB,PIN0,GPIO_HIGH);

		break;
	//case IR_REMOTE_BACK:
	case 101:
		GPIO_voidSetPinValue(GPIOB,PIN0,GPIO_LOW);

		/*if (Speed>-19){
			Speed+=20;
			S2P_LEDMRX_voidAnimation(u8Word,Speed,5);
		}
		else
		{
			Speed=20;
			S2P_LEDMRX_voidAnimation(u8Word,Speed,5);
		}*/
		break;
	//case IR_REMOTE_FORWARD:
	case 100:
		GPIO_voidSetPinValue(GPIOB,PIN0,GPIO_HIGH);

		/*if (Speed>21){
			Speed-=20;
			S2P_LEDMRX_voidAnimation(u8Word,Speed,5);
		}
		else
		{
			Speed=20;
			S2P_LEDMRX_voidAnimation(u8Word,Speed,5);
		}*/
		break;
	default: break;
	}
}

int main (void)
{
	/*	RCC Initialize*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOA);
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOB);
	RCC_voidEnableClock(RCC_APB2, RCC_AFIO);
	//RCC_voidEnableClock(RCC_APB1,RCC_TIM2);

	/*IO Pins Initialization*/
	GPIO_voidSetPinDirection(GPIOA,PIN4,INPUT_FLOATING); /*A0 Input Floating*/
	//GPIO_voidSetPinDirection(S2P_SERIAL_DATA,OUTPUT_GP_PP_2MHZ);
	//GPIO_voidSetPinDirection(S2P_SHIFT_CLOCK,OUTPUT_GP_PP_2MHZ);
	//GPIO_voidSetPinDirection(S2P_STORE_CLOCK,OUTPUT_GP_PP_2MHZ);
	GPIO_voidSetPinDirection(GPIOB,PIN0,OUTPUT_GP_PP_2MHZ);
	GPIO_voidSetPinDirection(GPIOB,PIN1,OUTPUT_GP_PP_2MHZ);
	GPIO_voidSetPinDirection(GPIOB,PIN7,OUTPUT_GP_PP_2MHZ);

	/*TIM2 and SYSTIC  Init*/
	//TIM2_voidInit();
	STK_voidInit();

	/*Alternative Function setting to enable external interrupt on B1*/
	EXTI_voidEnableEXTI(EXTI_LINE4);
	AFIO_voidSetEXTIConfig(EXTI_LINE4,AFIO_PA);

	/*EXTI initialization*/
	EXTI4_voidSetCallBack(GetFrame);
	EXTI_voidInit();

	/*Set Callback function to animation*/
	IR_voidSetCallBack(u8Play);

	/*Enable EXTI4 from NVIC*/
	NVIC_voidInit();
	NVIC_voidEnableInterrupt(NVIC_EXTI4);



	while(1)
	{
		//S2P_LEDMRX_voidAnimation(u8Word,Speed,5);
	}
	return 0;
}
