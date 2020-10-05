/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   13/Sept/2020
 *  Type    :   External Interrupts Interface File
 *  Version :   V1.1
 */ 

#ifndef EXTI_INTERFACE_H 
#define EXTI_INTERFACE_H

#define		 FALLING_EDGE		1

#define		 RISING_EDGE		3

#define		 ON_CHANGE			5

#define		 EXTI_LINE0			0
#define		 EXTI_LINE1			1
#define		 EXTI_LINE2			2
#define          EXTI_LINE3			3
#define          EXTI_LINE4			4
#define          EXTI_LINE5			5
#define          EXTI_LINE6			6
#define          EXTI_LINE7			7
#define          EXTI_LINE8			8
#define          EXTI_LINE9			9
#define          EXTI_LINE10		10
#define          EXTI_LINE11		11
#define		 EXTI_LINE12		12
#define		 EXTI_LINE13		13
#define		 EXTI_LINE14		14
#define		 EXTI_LINE15		15

#define NVIC_EXTI0		6
#define NVIC_EXTI1		7
#define NVIC_EXTI2		8
#define NVIC_EXTI3		9
#define NVIC_EXTI4		10
#define NVIC_EXTI9_5	23
#define NVIC_EXTI15_10	40

void EXTI_voidInit(void);
void EXTI_voidEnableEXTI(u8 Copy_u8Line);
void EXTI_voidDisableEXTI(u8 Copy_u8Line);
void EXTI_voidSwTrigger(u8 Copy_u8Line);
void EXTI_voidSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);
void EXTI0_voidSetCallBack(void (*ptr) (void));
void EXTI1_voidSetCallBack(void (*ptr) (void));
void EXTI2_voidSetCallBack(void (*ptr) (void));
void EXTI3_voidSetCallBack(void (*ptr) (void));
void EXTI4_voidSetCallBack(void (*ptr) (void));
void EXTI9_5_voidSetCallBack(void (*ptr) (void));
void EXTI15_10_voidSetCallBack(void (*ptr) (void));

#endif