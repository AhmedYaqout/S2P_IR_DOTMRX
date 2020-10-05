/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   24/Aug/2020
 *  Type    :   External Interrupts Configuration File
 *  Version :   V1.0
 */ 

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H


/*
* Defines the line of the External Interrupt
*   Options:
*           EXTI_LINE0
*           EXTI_LINE1
*           .
*           .
*           .
*           EXTI_LINE15
*/
#ifndef EXTI_LINE
#define EXTI_LINE   EXTI_LINE4
#endif
/*
* Defines the mode of the External Interrupt
*   Options:
*           RISING_EDGE
*           FALLING_EDGE
*           ON_CHANGE
*/
#ifndef EXTI_MODE
#define EXTI_MODE   FALLING_EDGE
#endif

#endif
