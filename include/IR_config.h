/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   02/Sept/2020
 *  Type    :   IR Configuration File
 *  Version :   V1.0
 */ 

#ifndef IR_CONFIG_H
#define IR_CONFIG_H

/*
	Options :
		0 : 15
*/
//#define   REMOTE_EXTI_LINE     PIN1
#define EXTI_LINE	EXTI_LINE4
/*
	Options :
		PORTA
		PORTB
		PORTC
*/
#define EXTI_MODE FALLING_EDGE

#define   REMOTE_EXTI_PORT     GPIOA

#endif
