/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   8/Aug/2020
 *  Type    :   RCC Interface File
 *  Version :   V1.0
 */

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2


/*VERY IMPORTANT NOTE:     The following can only be enabled from APB2 Bus      */
#define RCC_GPIOA   2
#define RCC_GPIOB   3
#define RCC_GPIOC   4
#define RCC_GPIOD   5
#define RCC_GPIOE   6
#define RCC_GPIOF   7
#define RCC_GPIOG   8

#define RCC_AFIO    0
#define RCC_ADC1    9
#define RCC_ADC2    10
#define RCC_TIM1    11
#define RCC_SPI1    12
#define RCC_TIM8    13
#define RCC_USART1  14
#define RCC_ADC3    15
#define RCC_TIM9    19
#define RCC_TIM10   20
#define RCC_TIM11   21

#define RCC_TIM2	0
#define RCC_TIM3	1
#define RCC_TIM4	2
#define RCC_TIM5	3
#define RCC_TIM6	4
#define RCC_TIM7	5
#define RCC_TIM12	6
#define RCC_TIM13	7
#define RCC_TIM14	8


void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidInitSysClock(void);

#endif
