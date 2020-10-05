/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   14/Sept/2020
 *  Type    :   S2P Configuration File
 *  Version :   V1.0
 */ 

#ifndef S2P_CONFIG_H
#define S2P_CONFIG_H

/*Options: Look at the RCC options*/
#define S2P_SERIAL_DATA  GPIOA,PIN0
#define	S2P_SHIFT_CLOCK  GPIOA,PIN1
#define	S2P_STORE_CLOCK  GPIOA,PIN2

#define S2P_REGISTER_QTY	2

#define LEDMRX_ROW0        STP_Q0i
#define LEDMRX_ROW1        STP_Q1
#define LEDMRX_ROW2        STP_Q2
#define LEDMRX_ROW3        STP_Q3
#define LEDMRX_ROW4        STP_Q4
#define LEDMRX_ROW5        STP_Q5
#define LEDMRX_ROW6        STP_Q6
#define LEDMRX_ROW7        STP_Q7

#define LEDMRX_COLUMN0     STP_Q0
#define LEDMRX_COLUMN1     STP_Q1i
#define LEDMRX_COLUMN2     STP_Q2i
#define LEDMRX_COLUMN3     STP_Q3i
#define LEDMRX_COLUMN4     STP_Q4i
#define LEDMRX_COLUMN5     STP_Q5i
#define LEDMRX_COLUMN6     STP_Q6i
#define LEDMRX_COLUMN7     STP_Q7i

#endif
