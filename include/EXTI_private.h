/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   24/Aug/2020
 *  Type    :   External Interrupts Private File
 *  Version :   V1.0
 */ 

#ifndef EXTI_PRIVATE_H 
#define EXTI_PRIVATE_H

typedef struct 
{
    volatile u32   IMR;     /* Interrupt Mask Register */
    volatile u32   EMR;     /* Event Mask Register */
    volatile u32   RTSR;    /* Rising Trigger Set Register */
    volatile u32   FTSR;    /* Falling Trigger Set Register */
    volatile u32   SWIER;   /* Software Interrupt Event Register */
    volatile u32   PR;      /* Pending Register */

} EXTI_t;


/* Declares a pointer to structure */
#define EXTI    ((volatile EXTI_t *)0x40010400)


#endif