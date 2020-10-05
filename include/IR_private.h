/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   11/Sept/2020
 *  Type    :   IR MATRIX Private File
 *  Version :   V1.0
 */

#ifndef IR_PRIVATE_H
#define IR_PRIVATE_H


/* Setting up ISR number for NVIC and handler of the isr */
#if   REMOTE_EXTI_LINE == 0
	#define   REMOTE_HANDLER        EXTI0_IRQHandler
	#define   REMOTE_NVIC_NUMBER    EXTI0_IRQ

#elif REMOTE_EXTI_LINE == 1
	#define   REMOTE_HANDLER        EXTI1_IRQHandler
	#define   REMOTE_NVIC_NUMBER    EXTI1_IRQ

#elif REMOTE_EXTI_LINE == 2
	#define   REMOTE_HANDLER        EXTI2_IRQHandler
	#define   REMOTE_NVIC_NUMBER    EXTI2_IRQ

#elif REMOTE_EXTI_LINE == 3
	#define   REMOTE_HANDLER        EXTI3_IRQHandler
	#define   REMOTE_NVIC_NUMBER    EXTI3_IRQ

#elif REMOTE_EXTI_LINE == 4
	#define   REMOTE_HANDLER        EXTI4_IRQHandler
	#define   REMOTE_NVIC_NUMBER    EXTI4_IRQ

#elif (REMOTE_EXTI_LINE  > 4) && (REMOTE_EXTI_LINE  < 10)
	#define   REMOTE_HANDLER        EXTI9_5_IRQHandler
	#define   REMOTE_NVIC_NUMBER    EXTI9_5_IRQ

#elif (REMOTE_EXTI_LINE  > 9) && (REMOTE_EXTI_LINE  < 16)
	#define   REMOTE_HANDLER        EXTI15_10_IRQHandler
	#define   REMOTE_NVIC_NUMBER    EXTI15_10_IRQ

#else
	#error (" Configuration error ")
#endif


void voidTakeAction(void);

#endif
